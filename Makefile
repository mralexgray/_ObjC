
     PROJ = _ObjC
   HEADER = "$(SRCROOT)/$(PROJ).h"
DSTHEADER =  "$(BUILT_PRODUCTS_DIR)/$(PROJ).h"
  INPLIST = "$(SRCROOT)/$(PROJ)/$(PROJ).plist"

# APP = $(xcodebuild -target _ObjC_Tool -showBuildSettings | grep -m 1 "CODESIGNING_FOLDER_PATH" | grep -oEi  "\/.*")

all: build
	
# build; xcodebuild -scheme _ObjC_Tool

clean:
	rm -f $(DSTHEADER) $(HEADER)
	say done cleaning
#	rm -r docs
	# xcrun xcodebuild clean

dsthead:
	$(BUILT_PRODUCTS_DIR)/_ObjC_Tool $(INPLIST) -o $(DSTHEADER):$(HEADER)
	
build: dsthead
	say "running"
	
	
	# docs: _ObjC.h
	# 	headerdoc2html -p _ObjC.h -o docs
	