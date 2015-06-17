
TESTS := $(PROJECT_NAME)_Tests.m
TOOL   = $(PROJECT_NAME)_Tool
XCB    = /usr/local/bin/xctool -project ../$(PROJECT_NAME).xcodeproj

PLIST  = $(SRCROOT)/$(PROJECT_NAME)/$(PROJECT_NAME).plist
TEMPL  = $(SRCROOT)/$(PROJECT_NAME)/$(PROJECT_NAME)_Template.h
TESTS  = -tests $(SRCROOT)/$(PROJECT_NAME)/$(PROJECT_NAME)_Tests.m
INPUT  = -plist  $(PLIST) -header $(TEMPL)

LOCAL  = $(SRCROOT)/$(PROJECT_NAME).h
SHARE  = $(dir $(TARGET_BUILD_DIR))/$(PROJECT_NAME).h
OUTPUT = -output $(LOCAL) $(SHARE)

all: build-tool generate

build-tool:
	$(XCB) -scheme $(TOOL) -sdk macosx -derivedDataPath $(SYMROOT)/../..

generate:
	$(SYMROOT)/$(CONFIGURATION)/$(TOOL) \
		$(INPUT) \
		$(TESTS) \
		$(OUTPUT)

clean:
	for arch in $(SUPPORTED_PLATFORMS); do \
		rm -f $(BUILT_PRODUCTS_DIR)/$(CONFIGURATION)-$$arch/$(PROJECT_NAME).h ; \
	done



#for arch in $(SUPPORTED_PLATFORMS); do \
#	say $$arch ; \
#	$(XCB) -scheme $(PROJECT_NAME) SUPPORTED_PLATFORMS=$$arch -derivedDataPath $(SYMROOT) ; \
# done
# $(BUILT_PRODUCTS_DIR)
