import sys

subsdk0Offset = {
	"310" : 0x48DF000
}

if len(sys.argv) < 3:
	print("Usage: %s [from addr] [to func name] (s2 vers, like '310')" % sys.argv[0])
	sys.exit()

from_addr = int(sys.argv[1], 0)
dest_func = sys.argv[2] + "("

vers = "310"
if len(sys.argv) > 3:
	vers = sys.argv[3]

mapFilePath = "build" + vers + "/starlight310.map"
with open(mapFilePath, 'r') as f:
	mapFile = f.read()

foundPos = mapFile.find(dest_func) - 34
foundLine = mapFile[foundPos:mapFile.find("\n", foundPos)]

print("Found:")
print(foundLine)

func_addr = int(foundLine[:foundLine.find(" ")], 0)
jump_offset = subsdk0Offset[vers] + func_addr - from_addr
print("Jump needed: " + hex(jump_offset))
