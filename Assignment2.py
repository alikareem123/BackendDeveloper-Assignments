import os
import re

def updateFile(filePath, buildNumber, matchMaker):

    os.chmod(filePath, 0o755) # here used a correct file permission.

    with open(filePath, 'r') as inputter, open(filePath + '1', 'w') as outPutter:
        for i in inputter:

            i = re.sub(matchMaker, buildNumber, i)

            outPutter.write(i)
    os.remove(filePath)

    os.rename(filePath + '1', filePath)

def updateConstruction(buildNumber):

    correctedPath = os.path.join(os.environ["SourcePath"], "develop", "global", "src", "SConstruct")

    matchMaker = r"point=\d+"

    updateFile(correctedPath, buildNumber, matchMaker)

def updateTheVersion(buildNumber):

    versionP = os.path.join(os.environ["SourcePath"], "develop", "global", "src", "VERSION")

    matchMaker = r"ADLMSDK_VERSION_POINT=\d+"

    updateFile(versionP, buildNumber, matchMaker)

def main():

    buildNumber = os.environ.get("BuildNum")

    if buildNumber:

        updateConstruction(buildNumber)

        updateTheVersion(buildNumber)
    else:
        print("Error: Build number is not provided!!!.")

if __name__ == "__main__":
    main()
