import os, sys, re, ctypes

class Patch:
    def __init__(self, offset, length, content):
        self.offset = offset
        self.length = length
        self.content = content

PATCH_DIR = "patches"
PATCH_EXTENSION = ".slpatch"

PATCH_CONFIG_DIR = os.path.join(PATCH_DIR, "configs")
PATCH_CONFIG_EXTENSION = ".config"

NSO_HEADER_LEN = 0x100

buildVersion = None
patchConfig = {
    "build_id" : {},
    "nso_load_addr" : {}
}
patchList = {}

mapFile = None

def initConfig():
    configPath = os.path.join(PATCH_CONFIG_DIR, buildVersion + PATCH_CONFIG_EXTENSION)
    with open(configPath) as configFile:
        curConfigName = None
        for line in configFile:
            configNameLineMatch = re.match(r'\[(.+)\]', line)
            if configNameLineMatch:
                curConfigName = configNameLineMatch.group(1)
                continue

            if '=' in line:
                configNSO, configValue = line.split('=', 1)
                patchConfig[curConfigName][configNSO] = configValue

def getSymAddrFromMap(regexStr, symStr):
    mapFilePath = os.path.join("build" + buildVersion, "starlight" + buildVersion + ".map")
    with open(mapFilePath, 'r') as f:
        mapFile = f.read()

    def getFoundPosAddr(start):
        regexMatch = re.search(regexStr, mapFile[start:])
        if not regexMatch:
            return -1, -1

        foundLinePos = mapFile.rfind('\n', 0, regexMatch.span()[0] + start) + 1
        foundLineEndPos = mapFile.find('\n', regexMatch.span()[1] + start)
        foundLine = mapFile[foundLinePos:foundLineEndPos].strip()
        foundAddr = int(foundLine[:foundLine.find(" ")], 16)
        
        return foundLineEndPos, foundAddr

    foundPos, firstFoundAddr = getFoundPosAddr(0)
    if foundPos == -1:
        raise "symbol not found"

    # check uniqueness
    while True:
        foundPos, moreFoundAddr = getFoundPosAddr(foundPos)
        if foundPos == -1:
            break

        if moreFoundAddr != firstFoundAddr:
            print("genPatch.py error:", symStr, "is ambiguous!")
            sys.exit(-1)

    # map stores signed address relative to starlight as unsigned?
    return int(patchConfig["nso_load_addr"]["subsdk0"], 16) + ctypes.c_long(firstFoundAddr).value

def resolveAddress(target, symbolStr):
    resolvedAddr = 0

    plusSplit = symbolStr.split('+', 1)
    if len(plusSplit) > 1:
        symbolStr = plusSplit[0]
        resolvedAddr += int(plusSplit[1], 16)

    # if symbol is one of the targets
    if symbolStr in patchConfig["nso_load_addr"]:
        resolvedAddr += int(patchConfig["nso_load_addr"][symbolStr], 16)
        return resolvedAddr

    targetSplit = symbolStr.split('!', 1)
    if len(targetSplit) > 1:
        target = targetSplit[0]
        symbolStr = targetSplit[1]
    else:
        # if symbol is in starlight
        funcStr = symbolStr + r'\('
        try:
            addrInStarlight = getSymAddrFromMap(funcStr, symbolStr)
            resolvedAddr +=  + addrInStarlight
            return resolvedAddr
        except:
            pass

    resolvedAddr += int(patchConfig["nso_load_addr"][target], 16)

    # if symbolStr is already address
    try:
        resolvedAddr += int(symbolStr, 16)
        return resolvedAddr
    except ValueError:
        pass

    regexStr = r'\w*'.join(re.findall(r'\w+', symbolStr))
    try:
        resolvedAddr += getSymAddrFromMap(regexStr, symbolStr)
    except:
        print("genPatch.py error: cannot resolve", symbolStr)
        sys.exit(-1)

    return resolvedAddr

def addPatchFromFile(patchFilePath):
    PATCH_VERSION_ALL = "all"
    patchVars = {
        "version" : None,
        "target" : "main"
    }

    with open(patchFilePath) as patchFile:
        fileLinesIter = iter(patchFile)
        for line in fileLinesIter:
            line = line.split('/', 1)[0]

            patchVarLineMatch = re.match(r'\[(.+)\]', line)
            if patchVarLineMatch:
                patchVarMatches = re.findall(r'(\w+)=(\w+)', patchVarLineMatch.group(1))
                for match in patchVarMatches:
                    patchVars[match[0]] = match[1]
                continue

            addressSplit = line.split(' ', 1)
            isMultiPatch = addressSplit[0].endswith(':')
            if len(addressSplit) < 2 and not isMultiPatch:
                continue
            
            patchAddress = resolveAddress(patchVars["target"],
                addressSplit[0] if not isMultiPatch else addressSplit[0][:-1])
            print(addressSplit[0], "resovled to", hex(patchAddress))

            # UNFINISHED


if len(sys.argv) < 2:
    print('Usage: ' + sys.argv[0] + ' [version]')
    sys.exit(-1)

buildVersion = sys.argv[1]
initConfig()

for file in os.listdir(PATCH_DIR):
    if file.endswith(PATCH_EXTENSION):
        addPatchFromFile(os.path.join(PATCH_DIR, file))

# UNFINISHED
