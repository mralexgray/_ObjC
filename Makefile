# MKF_PATH := $(abspath $(lastword $(MAKEFILE_LIST)))
# PROJ = `xcodebuild -showBuildSettings | grep -m 1 "PROJECT_NAME" | grep -oEi  "\/.*"`

     PROJ = _ObjC
	 TOOL = $(PROJ)_Tool
 TEMPLATE = $(PROJ)/$(PROJ)_Template.h
    PLIST = $(PROJ)/$(PROJ).plist
ifdef BUILT_PRODUCTS_DIR
TOOL_PATH = $(BUILT_PRODUCTS_DIR)/$(TOOL)
DSTHEADER = $(BUILT_PRODUCTS_DIR)/$(PROJ).h $(PROJ).h
else
TOOL_PATH = build/Release/$(TOOL)
DSTHEADER = $(PROJ).h
endif

all: run-tool

clean:
	rm -f $(DSTHEADER) $(HEADER)
	say done cleaning

build-tool:
ifndef BUILT_PRODUCTS_DIR
	say building tool
	xcodebuild
endif
	
run-tool: build-tool $(TEMPLATE) $(PLIST)
	say running tool
	
# genheader:
# 	$(BUILT_PRODUCTS_DIR)/_ObjC_Tool -plist $(INPLIST) -header  -o $(DSTHEADER):$(HEADER)
#
# build: genheader
# 	say "running"
#
# sexy:

	
	
# docs: _ObjC.h
# 	headerdoc2html -p _ObjC.h -o docs
# APP = $(xcodebuild -target _ObjC_Tool -showBuildSettings | grep -m 1 "CODESIGNING_FOLDER_PATH" | grep -oEi  "\/.*")
# build; xcodebuild -scheme _ObjC_Tool
#	rm -r docs
# xcrun xcodebuild clean
