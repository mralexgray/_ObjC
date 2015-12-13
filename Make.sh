#!/usr/bin/env zsh

IN0="${SRCROOT}/${PROJECT_NAME}/${PROJECT_NAME}.plist"
IN1="$(SRCROOT)/$(PROJECT_NAME)/$(PROJECT_NAME)_Tests.m"
IN2="$(SRCROOT)/$(PROJECT_NAME)/$(PROJECT_NAME)_Template.h"

OUT0="/usr/local/include/$(PROJECT_NAME).h"

############

OUTFILES=( "${SCRIPT_OUTPUT_FILE_0}" )

 PLIST="${SCRIPT_INPUT_FILE_0}"
HEADER="${SCRIPT_INPUT_FILE_1}"
 TESTS="${SCRIPT_INPUT_FILE_2}"

TOOL="${BUILT_PRODUCTS_DIR/-iphone*/}/${PROJECT_NAME}_Tool"

LINK_TO=( "${SRCROOT}/${PROJECT_NAME}.h" )

for x in macosx iphoneos; do
    LINK_TO+="$(xcrun --show-sdk-path --sdk $x)/usr/include/${PRODUCT_NAME}.h"
done

# build the tool.

xcodebuild -scheme          "${PROJECT_NAME}_Tool"    \
           -configuration   "${CONFIGURATION}"        \
           -derivedDataPath "${SYMROOT}/../.."        \
            CODE_SIGN_IDENTITY=""                     \
            CODE_SIGNING_REQUIRED=NO


"$TOOL" -plist "$PLIST" -header "$HEADER" -tests "$TESTS" -output $OUTFILES

RES=$?

[[ $RES != 0 ]] && say purging failures from exit $RES && rm -f $OUTFILES

for z in $LINK_TO; do ln -sF "${SCRIPT_OUTPUT_FILE_0}" "$z" done

[[ $EFFECTIVE_PLATFORM_NAME =~ iphone ]] && scp "${OUTFILES[2]}" ip6:/usr/local/include

#env |sort | pbcopy

exit $RES

#FILES=$(printf "{SCRIPT_OUTPUT_FILE_%s}\n" {0..2})
#for x in $FILES
#do
#    OUTFILES+="${!x}"
#done

#if false; then WD="$(realpath $(pwd))/"; fi
# $(TARGET_BUILD_DIR)/../$(PROJECT_NAME).h
# /Applications/Xcode-beta.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.11.sdk

# ${SCRIPT_OUTPUT_FILE_1}

#    sudo chmod +a "$(whoami) allow chown,read,write,append,execute,list,search,add_file,add_subdirectory,file_inherit,directory_inherit"
# XCODE="$(xcode-select -p)"

