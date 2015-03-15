#!/bin/zsh

logger WELCOME

PROJ_FOLDER_="$(cd -P -- $(dirname -- $(command -v -- $0)) && pwd -P)"
PROJ_NAMEIS_="$(basename $PROJ_FOLDER_)"
PROJ_DOMAIN_="com.mrgray.$PROJ_NAMEIS_"
INSTALLABLE_="$PROJ_FOLDER_/$PROJ_NAMEIS_.h"

notify () {
  type -p terminal-notifier > /dev/null && terminal-notifier -title "$PROJ_NAMEIS_" -message "$@" && logger "$@"  
}

update () {

  ln -sF "$INSTALLABLE_" /usr/local/include && echo "\nLinked $PROJ_NAMEIS_.h to /usr/local/include\n"

  for PLATFORM_ in 'iphonesimulator' 'iphoneos' 'macosx'; do ((C++))

    SDKPATH_="$(xcrun --show-sdk-path -sdk $PLATFORM_ 2> /dev/null)/usr/include"  # --no-cache
    DESTLOC_="${SDKPATH_}/${PROJ_NAMEIS_}.h"                                           # install path

    [[ ! -w "$SDKPATH_" ]] && notify "$PLATFORM_ SDK missing! Abort!" && exit 99   # guarantee destination exists
    [[ ! -f "$DESTLOC_" ]] && echo "Fresh install for $PLATFORM_"   || {

      diff -w -B -I'^\/\*\!' -I'^\/\/' -I'^\s*\*\/&' "$DESTLOC_" "$INSTALLABLE_" \
        && printf "%-20s exists and is the SAME!\n" $PLATFORM_ && continue \
        || { echo "$PLATFORM_ dirty! Cleaning" && rm "$DESTLOC_" }
    }
    cp "$INSTALLABLE_" "$SDKPATH_" || echo "Copy FAILED!" && ((REBUILD_++))
    echo "\033[48;5;$C;5mInstalled $PROJ_NAMEIS_ into ${SDKPATH_##*SDKs} folder.\033[m"

  done

  XCODE_WAS_="$(/usr/bin/defaults read $PROJ_DOMAIN_ xcode 2>/dev/null)"
  XCODE_NOW_="$('xcode-select' -p)"

  [[ "${XCODE_WAS_}" != "${XCODE_NOW_}" ]] && echo "New Xcode! Scheduling rebuild." && ((REBUILD_++))

  [[ -z $REBUILD_ ]] && notify "Nothing to rebuild, bye bye!" && exit 0

  DRVD_DATA_="$(defaults read com.apple.dt.Xcode IDECustomDerivedDataLocation)"
  MOD_CACHE_="$DRVD_DATA_/ModuleCache"

  [[ -d "$MOD_CACHE_" ]] && echo "Rebuilding Module Cache" \
                         && rm -r "$MOD_CACHE_"  \
                         && notify "Install OK + ModuleCache cleaned!" \
                         || { notify "Clean of Module Cache Failed!" && exit 2 }

  [[ $? -eq 0 ]] && [[ "$XCODE_WAS_" == "$XCODE_NOW_" ]] || /usr/bin/defaults write "$PROJ_DOMAIN_" xcode "$XCODE_NOW_" 2> /dev/null
}

THIS_SCRIPT_="$(basename $0)"

watchdog () {

  PLIST_LCTL_="$PROJ_NAMEIS_.watchdog"
  PLIST_PATH_="$HOME/Library/LaunchAgents/$PLIST_LCTL_.plist"
  launchctl unload "$PLIST_PATH_" 2> /dev/null
  
  plutil -convert xml1 -o "$PLIST_PATH_" - <<-EOF 
{
                "RunAtLoad" : false,
                  "Enabled" : true,
                    "Label" : "$PLIST_LCTL_",
                  "Program" : "$PROJ_FOLDER_/$THIS_SCRIPT_",
         "ProgramArguments" : [ "update" ],
  "WatchPaths" : [ "$HOME/Library/Preferences/com.apple.dt.Xcode.plist","$INSTALLABLE_" ],
  "StandardErrorPath" : "/tmp/_ObjC.watchdog.stderr",
   "StandardOutPath" : "/tmp/_ObjC.watchdog.stdout"
}
EOF
  launchctl load "$PLIST_PATH_"
}

regex() {

}

[[ -z "$1" ]]                          && watchdog  && exit
[[ "$1" == "update" ]] && say updating && update    && exit
                                          regex


