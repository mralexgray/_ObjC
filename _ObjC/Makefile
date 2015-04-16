
					 PROJ = _ObjC
					 TOOL = $(PROJ)_Tool
			 TEMPLATE = $(PROJ)_Template.h
					PLIST = $(PROJ).plist
		 
				 ifndef   BUILT_PRODUCTS_DIR

						 DD:= $(shell xcodebuild -showBuildSettings 2> /dev/null | grep BUILD_ROOT | sed 's:.* = ::g'| sed 's:/Build.*::g')
	CONFIGURATION = Debug
	     TOOLPATH = $(shell xcodebuild -target $(TOOL) -showBuildSettings | grep CODESIGNING_FOLDER_PATH | sed 's:.* = ::g')
      DSTHEADER = $(BUILT_PRODUCTS_DIR)/$(PROJ).h

									else

			 TOOLPATH = $(BUILT_PRODUCTS_DIR)/$(TOOL)
      DSTHEADER = $(PROJ).h
						 DD = $(BUILD_ROOT)

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
	$(TOOLPATH) -p $(PLIST) -t $(TEMPLATE) -o $(DSTHEADER)

