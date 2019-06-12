from ftplib import FTP
import os
import sys

titleIdLookup = {
    "JP": '01003C700009C000',
    "US": '01003BC0000A0000',
    "EU": '0100F8F0000A2000',
    'EveJP': '0100D070040F8000',
    'EveUS': '01003870040FA000',
    'EveEU': '010086F0040FC000',
    'TrialUS': '01006BB00D45A000',
    'ShowDL': '010000A00218E000'
}


def listdirs(connection,_path):
    file_list, dirs, nondirs = [], [], []
    try:
        connection.cwd(_path)
    except:
        return []

    connection.retrlines('LIST', lambda x: file_list.append(x.split()))
    for info in file_list:
        ls_type, name = info[0], info[-1]
        if ls_type.startswith('d'):
            dirs.append(name)
        else:
            nondirs.append(name)
    return dirs


def ensuredirectory(connection,root,path):
    print(f'Ensuring {os.path.join(root, path)} exists...')
    if path not in listdirs(connection, root):
        connection.mkd(f'{root}/{path}')


consoleIP = sys.argv[1]
if '.' not in consoleIP:
    print(sys.argv[0], "ERROR: Please specify with `IP=[Your console's IP]`")
    sys.exit(-1)

consolePort = 5000

if len(sys.argv) < 3:
    romType = 'US'
else:
    romType = sys.argv[2]

if len(sys.argv) < 4:
    version = '310'
else:
    version = sys.argv[3]

curDir = os.curdir

ftp = FTP()
print(f'Connecting to {consoleIP}... ', end='')
ftp.connect(consoleIP, consolePort)
print('Connected!')

patchDirectories = []

root, dirs, _ = next(os.walk(curDir))
for dir in dirs:
    if dir.startswith("starlight_patch_"):
        patchDirectories.append((os.path.join(root, dir), dir))

ensuredirectory(ftp, '', 'atmosphere')
ensuredirectory(ftp, '/atmosphere', 'exefs_patches')

for patchDir in patchDirectories:
    dirPath = patchDir[0]
    dirName = patchDir[1]
    ensuredirectory(ftp, '/atmosphere/exefs_patches', patchDir[1])
    _, _, files = next(os.walk(dirPath))
    for file in files:
        fullPath = os.path.join(dirPath, file)
        if os.path.exists(fullPath):
            sdPath = f'/atmosphere/exefs_patches/{dirName}/{file}'
            print(f'Sending {sdPath}')
            ftp.storbinary(f'STOR {sdPath}', open(fullPath, 'rb'))

ensuredirectory(ftp, '/atmosphere', 'titles')
ensuredirectory(ftp, '/atmosphere/titles', titleIdLookup[romType])
ensuredirectory(ftp, f'/atmosphere/titles/{titleIdLookup[romType]}', 'exefs')

if os.path.isfile(f'Starlight{version}.nso'):
    sdPath = f'/atmosphere/titles/{titleIdLookup[romType]}/exefs/subsdk0'
    print(f'Sending {sdPath}')
    ftp.storbinary(f'STOR {sdPath}', open(f'Starlight{version}.nso', 'rb'))
