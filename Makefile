# ifndef CONFIGURATION
#   CONFIGURATION ?= Debug
#   IGNORE := $(shell bash -c "Universal/xcodebuildenv >! /tmp/xccodeenv")
#   include /tmp/xccodeenv
# endif
ifndef CONFIGURATION
IGNORE := $(shell ./Universal/xcodebuildenv > /tmp/xcodebuildenv)
include /tmp/xcodebuildenv
endif

DRVDTA = $(SYMROOT)/../..

TESTS := $(PROJECT_NAME)_Tests.m
TOOL   = $(PROJECT_NAME)_Tool
XCB    = /usr/local/bin/xctool -project $(PROJECT_FILE_PATH)
# XCB    = /usr/local/bin/xctool -project ../$(PROJECT_NAME).xcodeproj

PLIST  = $(SRCROOT)/$(PROJECT_NAME)/$(PROJECT_NAME).plist
TEMPL  = $(SRCROOT)/$(PROJECT_NAME)/$(PROJECT_NAME)_Template.h
TESTS  = -tests $(SRCROOT)/$(PROJECT_NAME)/$(PROJECT_NAME)_Tests.m
INPUT  = -plist  $(PLIST) -header $(TEMPL)

LOCAL  = $(SRCROOT)/$(PROJECT_NAME).h
SHARE  = $(dir $(TARGET_BUILD_DIR))/$(PROJECT_NAME).h
OUTPUT = -output $(LOCAL) $(SHARE)


build: sayit build-tool generate

sayit:
	$(shell say action is $(ACTION))

build-tool:
	# $(shell echo "$(XCB) -scheme $(TOOL) -sdk macosx10.10 -derivedDataPath $(DRVDTA)")
	$(XCB) -scheme $(TOOL) -sdk macosx10.10 -derivedDataPath $(DRVDTA)

generate:
#	open $(DD)
	$(SYMROOT)/$(CONFIGURATION)/$(TOOL) \
		$(INPUT) \
		$(TESTS) \
		$(OUTPUT)

#	$(SYMROOT)/$(CONFIGURATION)/$(TOOL) \
#		$(INPUT) \
#		$(TESTS) \
#		$(OUTPUT)

clean:
	# $(shell say cleaning $(OUTPUT))
	for arch in $(SUPPORTED_PLATFORMS); do \
		echo "arch is $$arch" \
	done

		# rm -f $(BUILT_PRODUCTS_DIR)/$(CONFIGURATION)-$$arch/$(PROJECT_NAME).h ; \



#for arch in $(SUPPORTED_PLATFORMS); do \
#	say $$arch ; \
#	$(XCB) -scheme $(PROJECT_NAME) SUPPORTED_PLATFORMS=$$arch -derivedDataPath $(SYMROOT) ; \
# done
# $(BUILT_PRODUCTS_DIR)

