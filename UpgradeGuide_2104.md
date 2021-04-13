# Unreal 2104 Upgrade Guide

We have ran into a generic naming conflict with the enum ETriggerType. We are updating our enum to EPfTriggerType.

## Upgrade instructions

If you are using ETriggerType, see the new name in "PlayFabPlugin/Source/PlayFab/Classes/PlayFabEnums.h". If you used this enum via C++ code:

* Replace:
    * ETriggerType
* With:
    * EPfTriggerType
