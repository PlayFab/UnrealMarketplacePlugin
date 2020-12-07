# Unreal 201207 Upgrade Guide

TitleId, DevSecretKey, and ProductionEnvironmentUrl were stored in multiple places inconsistently, not universally synchronized, and sometimes you could set a value with no effect to the rest of the code. We have resolved this such that there's only one location for these values and everything shares that location. Most pass-through accessors for old locations have been removed. This guide describes removed accessors, and the replacement code to access those accessors in the new locations.

## Upgrade instructions

In all cases, if you are setting TitleId, DevSecretKey, or ProductionEnvironmentURL, all of these values can also be defined in the "PlayFab/Settings/setPlayFabSettings" Blueprint, and in the Editor via "Edit -> Project Settings -> Plugins -> PlayFab". If you want to continue setting them via C++ code, check the "Replace" sections below for a code snippet matching yours and exchange it with the indicated replacement.

* Replace:
    * IPlayFab::Get().getGameTitleId()
    * PlayFabSettings::GetTitleId()
* With:
    * GetDefault<UPlayFabRuntimeSettings>()->TitleId

* Replace:
    * IPlayFab::Get().getDeveloperSecretKey()
    * PlayFabSettings::GetDeveloperSecretKey()
* With:
    * GetDefault<UPlayFabRuntimeSettings>()->DeveloperSecretKey

* Replace:
    * IPlayFab::Get().getDeveloperSecretKey()
    * PlayFabSettings::GetProductionEnvironmentURL()
* With:
    * GetDefault<UPlayFabRuntimeSettings>()->DeveloperSecretKey

* Replace:
    * apiInstance.SetTitleId(newValue)
    * PlayFab_API::SetTitleId(newValue)
* With:
    * GetMutableDefault<UPlayFabRuntimeSettings>()->TitleId = newValue

* Replace:
    * apiInstance.SetDevSecretKey(newValue)
    * PlayFab_API::SetDevSecretKey(newValue)
* With:
    * GetMutableDefault<UPlayFabRuntimeSettings>()->DeveloperSecretKey = newValue

## Detailed Changes

* PlayFabRuntimeSettings.ProductionEnvironmentUrl replaces all other identical and synonomous variables meant to hold the PlayFab web-server URL.
    * Removed some options about developmentUrl vs productionUrl
    * Renamed PlayFabApiSettings.BaseServiceHost methods to ProductionEnvironmentURL
    * Removed many duplicate variables and pass-through methods linked to duplicate variables
    * Fixed all locations where this URL was not synchronized properly which resulted in inconsistent connectivity behavior
    * Added the option to define only the web-server domain, or the full web address (previously only accepted just the domain)
* PlayFabRuntimeSettings.TitleId and PlayFabRuntimeSettings.DeveloperSecretKey replace other TitleId and DevSecretKey variables in other loctions
    * It was hard, but not impossible to de-synchronize these values, so they only exist in PlayFabRuntimeSettings now
    * Most other locations have been removed, and the remaining locations are synced to PlayFabRuntimeSettings at instance creation
* Removed the unusable verticalName fields and methods
    * This feature was removed from the web-server, and never meant for typical customer use.
    * ProductionEnvironmentUrl usability is expanded enough to cover the rare instances where verticalName was intended/useful
