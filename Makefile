
       PROJ = _ObjC
       TOOL = $(PROJ)_Tool
   TEMPLATE = $(PROJ)/$(PROJ)_Template.h
      PLIST = $(PROJ)/$(PROJ).plist
         DD = $(shell xcodebuild -showBuildSettings 2> /dev/null | grep BUILD_ROOT | sed 's:.* = ::g')

ifdef BUILT_PRODUCTS_DIR
  DSTHEADER = $(BUILT_PRODUCTS_DIR)/$(PROJ).h
else
  DSTHEADER = $(PROJ).h
endif

all: run-tool

clean:
	rm -f $(PROJ).h 
	rm -f $(DSTHEADER)
	rm -f **/*/.DS_Store

build-tool: $(PROJ)/$(PROJ)_Tool.m
	xcodebuild -scheme $(TOOL) -derivedDataPath $(DD)

test: run-tool
	xcodebuild -scheme $(PROJ) test
	
show: run-tool
	open -R $(DSTHEADER)
		
run-tool: build-tool $(TEMPLATE) $(PLIST)
	$(DD)/Release/$(TOOL) -plist $(PLIST) -template $(TEMPLATE)  -o $(DSTHEADER)

















	# -o /tmp/output
	
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
# ifndef BUILT_PRODUCTS_DIR
# 	say building tool
# 	xcodebuild
# endif
# TOOL_PATH = build/Release/$(TOOL)
# DSTHEADER = $(PROJ).h
# MKF_PATH := $(abspath $(lastword $(MAKEFILE_LIST)))
# PROJ = `xcodebuild -showBuildSettings | grep -m 1 "PROJECT_NAME" | grep -oEi  "\/.*"`
