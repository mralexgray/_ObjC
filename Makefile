
     PROJ = $(PROJECT_NAME)
  TMPLATE = "$(SRCROOT)/$(PROJ)/$(PROJ)_Template.h"
    PLIST = "$(SRCROOT)/$(PROJ)/$(PROJ).plist"
DSTHEADER = "$(BUILT_PRODUCTS_DIR)/$(PROJ).h"


all: sexy

clean:
	rm -f $(DSTHEADER) $(HEADER)
	say done cleaning

genheader:
	$(BUILT_PRODUCTS_DIR)/_ObjC_Tool -plist $(INPLIST) -header  -o $(DSTHEADER):$(HEADER)
	
build: genheader
	say "running"

sexy:
  echo $(PROJ)
	
	
# docs: _ObjC.h
# 	headerdoc2html -p _ObjC.h -o docs
# APP = $(xcodebuild -target _ObjC_Tool -showBuildSettings | grep -m 1 "CODESIGNING_FOLDER_PATH" | grep -oEi  "\/.*")
# build; xcodebuild -scheme _ObjC_Tool
#	rm -r docs
# xcrun xcodebuild clean
