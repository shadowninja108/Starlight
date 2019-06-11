from ftplib import FTP
import os

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

def ensuredirectory(connection,root, path):
    print(f'Ensuring {os.path.join(root, path)} exists...')
    if path not in listdirs(connection, root):
        connection.mkd(f'{root}/{path}')


consoleIP = "10.4.1.79"
consolePort = 5000

curDir = os.curdir

ftp = FTP()
print('Connecting to console...')
ftp.connect(consoleIP, consolePort)
print('Connected!')

patchDirectories = []

root, dirs, _ = next(os.walk(f'{curDir}/..'))
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
