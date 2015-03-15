#!/usr/bin/env zsh

PROJ_FOLDER_="$( cd -P -- $(dirname -- $(command -v -- $0)) && pwd -P )"
PROJ_NAMEIS_="$(basename $PROJ_FOLDER_)"
PROJ_DOMAIN_="com.mrgray.$PROJ_NAMEIS_"
INSTALLABLE_="$PROJ_FOLDER_/$PROJ_NAMEIS_.h"

notify () { N_=$(which terminal-notifier); [[ "$N_" ]] && "$N_" -title "$PROJ_NAMEIS_" -message "$@" && echo "$@"  }

ln -sF "$INSTALLABLE_" /usr/local/include && echo "Linked $PROJ_NAMEIS_.h to /usr/local/include"

for PLATFORM_ in 'iphonesimulator' 'iphoneos' 'macosx'; { ((C++))

  SDKPATH_="$(xcrun --show-sdk-path -sdk $PLATFORM_  2> /dev/null)/usr/include"  # --no-cache
  DESTLOC_="$SDKPATH_/$PROJ_NAMEIS_.h"                                           # install path

  [[ ! -w "$SDKPATH_" ]] && notify "$PLATFORM_ SDK missing! Abort!" && exit 99      # guarantee destination exists
  [[ ! -f "$DESTLOC_" ]] && echo "Fresh install for $PLATFORM_"   || {

    diff -w -B -I'^\/\*\!' -I'^\/\/' -I'^\s*\*\/&' "$DESTLOC_" "$INSTALLABLE_" \
      && printf "%-20s exists and is the SAME!\n" $PLATFORM_ && continue \
      || { echo "$PLATFORM_ dirty! Cleaning" && rm "$DESTLOC_" }
  }
  cp "$INSTALLABLE_" "$SDKPATH_" || echo "Copy FAILED!" && ((REBUILD_++))
  echo "\033[48;5;$C;5mInstalled $PROJ_NAMEIS_ into ${SDKPATH_##*SDKs} folder.\033[m"
}

XCODE_WAS_="$(/usr/bin/defaults read $PROJ_DOMAIN_ xcode 2> /dev/null)"
XCODE_NOW_="$(xcode-select -p)"

[[ "$XCODE_WAS_" != "$XCODE_NOW_" ]] && echo "New Xcode!  Scheduling rebuild." && ((REBUILD_++))

[[ -z $REBUILD_ ]] && notify "Nothing to rebuild, bye bye!" && exit 0

DRVD_DATA_="$(defaults read com.apple.dt.Xcode IDECustomDerivedDataLocation)"
MOD_CACHE_="$DRVD_DATA_/ModuleCache"

[[ -d "$MOD_CACHE_" ]] && echo "Rebuilding Module Cache" \
                       && rm -r "$MOD_CACHE_"  && notify "Install OK + ModuleCache cleaned!" \
                       || { notify "Clean of Module Cache Failed!" && exit 2 }

[[ $? -ne 0 ]] && [[ "$XCODE_WAS_" == "$XCODE_NOW_" ]] \
               || /usr/bin/defaults write "$PROJ_DOMAIN_" xcode "$XCODE_NOW_" 2> /dev/null






#defaults write "$PROJ_DOMAIN_" hash "$NEW_HASH_" 2> /dev/null
#     NEW_HASH_="$(md5 -q $INSTALLABLE_)"
#     OLD_HASH_="$(defaults read $PROJ_DOMAIN_ hash 2> /dev/null)"
#
# setDefaults () { defaults write "$PROJ_DOMAIN_" hash "$NEW_HASH_"; defaults write "$PROJ_DOMAIN_" xcode "$XCODE_NOW_" }
#
#echo "pref_key:$PROJ_DOMAIN_\nold hash: $OLD_HASH_\nnew_hash: $NEW_HASH_\n  xc_def: $XCODE_WAS_\n  xc_now: $XCODE_NOW_"
#
#[[ "$OLD_HASH_" == "$NEW_HASH_" ]] && echo "hashes are same. aborting. OK!" # && exit 0

#DRVD_DATA_="$(defaults read com.apple.dt.Xcode IDECustomDerivedDataLocation)"
#MOD_CACHE_="$DRVD_DATA_/ModuleCache"
#
#[[ -d "$MOD_CACHE_" ]] && rm -r "$MOD_CACHE_" && echo "\033[48;5;$CmCleared cache at $MOD_CACHE_!" || echo "Could clear cache"

# open --reveal "$DDATA"

#[[ ( $# ) ]] && say $# || {
#
#  putf "running optional"
#  DDATA="$(defaults read com.apple.dt.Xcode IDECustomDerivedDataLocation)"
#
#}
#/*/../bin/ls > /dev/null
#
#NEED_REBUILD=                                        # delete module cache?
#INSTALL_FILE="$(pwd)/$0"                             # THIS
#
#for x in 'iphonesimulator' 'iphoneos' 'macosx'; { ((C++))
#
#  SDKPATH="$(xcrun --show-sdk-path -sdk $x --no-cache 2> /dev/null)/usr/include"
#  DESTLOC="$SDKPATH/$(basename $0)"
#  [[ -z "$SDKPATH" ]] && exit 99
#  [[ -a "$DESTLOC" ]] && ! diff "$INSTALL" "$DESTLOC" && say "Skipping $x" && continue
#  [[ -a "$DESTLOC" ]] && rm "$DESTLOC"
#  cp "$INSTALL" "$SDKPATH" && REBUILD=1
#  echo "\033[38;5;$C;5mInstalled $(basename $0) into ${SDKPATH##*SDKs} folder.\033m"
#}
#
#[[ $REBUILD ]] && echo rebuilding || echo NOT rebuilding
#
#exit
#
#*/
# :-$(md5 -q "$PROJ_HEADER")}

