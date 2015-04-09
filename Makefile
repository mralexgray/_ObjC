
       PROJ = _ObjC
       TOOL = $(PROJ)_Tool
   TEMPLATE = $(PROJ)_Template.h
      PLIST = $(PROJ).plist
        DD := $(shell xcodebuild -showBuildSettings 2> /dev/null | grep BUILD_ROOT | sed 's:.* = ::g'| sed 's:/Build.*::g')
	 TOOLPATH = $(shell xcodebuild -target $(TOOL) -showBuildSettings | grep CODESIGNING_FOLDER_PATH | sed 's:.* = ::g')
		 
ifndef CONFIGURATION
	CONFIGURATION = Debug
endif
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

build-tool: $(PROJ)_Tool.m
	echo "derived data is $(DD)"
	xcodebuild -scheme $(TOOL) -configuration $(CONFIGURATION) -derivedDataPath $(DD) 2> /dev/null

test: run-tool
	xcodebuild -scheme $(PROJ) test 2> /dev/null
	
show: run-tool
	open -R $(DSTHEADER)
		
run-tool: build-tool $(TEMPLATE) $(PLIST)
	 $(TOOLPATH) -plist $(PLIST) -template $(TEMPLATE)  -o $(DSTHEADER)

