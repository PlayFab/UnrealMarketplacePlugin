# Party Errors
// BEGIN GENERATED SECTION: DO NOT EDIT

## Common errors
Number | Description
------ | ------
0x0001 | Encountered unknown error.
0x0002 | Failed to allocate memory.
0x0003 | API not implemented.
0x0004 | Invalid argument specified.
0x0005 | Failed to create new thread.
0x0006 | Failed to find specified resource.
0x0007 | The operation is pending.
0x0008 | Unmapped platform error.
0x0009 | Unmapped messaging error.
0x000A | The buffer passed is too small.
0x000B | A component is in an invalid state to perform the requested operation.
0x000C | A thread created in a suspended state could not be started.
0x0018 | The specified PlayFab Entity ID is invalid.
0x0020 | The PlayFab token is too large.
0x0022 | The specified PlayFab Entity ID has not been provided to the Party library.
0x0023 | The PlayFab entity token is malformed or otherwise invalid.
0x0024 | The user is not authorized to execute the operation.
0x0026 | At least one data buffer with at least one byte must be provided.
0x0029 | A specified argument was valid but support is unimplemented.
0x002C | An error was encountered while validating the PlayFab entity token.
0x002D | The provided network configuration struct was invalid.
0x002E | The provided invitation failed to specify an identifier.
0x002F | The provided invitation specified too many Entity IDs.
0x0030 | The provided invitation's identifier was too long.
0x0031 | The provided invitation's revocability was invalid.
0x0032 | Another invitation with the provided identifier already exists in the network.
0x0036 | This operation is already in progress.
0x0053 | A request to a PlayFab service timed out.
0x0054 | An internal error was encountered while processing a service request.
0x005B | A platform operation provided a generic failure code.
0x005C | The PlayFab entity token has expired.
0x005D | The http request was throttled by the service.

## Client errors
Number | Description
------ | ------
0x1000 | The Party library must be initialized.
0x1001 | A user is already associated with the specified chat control.
0x1002 | The operation was called with an invalid handle.
0x1003 | Cannot create local user; local user limit reached.
0x1004 | Cannot create local user; local user already exists.
0x1005 | Only one PartyManager instance may exist at a time.
0x1006 | Cannot connect to network; network already connected.
0x1007 | Internet connectivity error encountered.
0x1008 | Operation could not be performed because object is being destroyed.
0x1009 | Cannot create another chat control; chat control limit reached.
0x100C | The thread affinity mask requested a processor that is not selected for the process affinity mask.
0x100E | Information about the endpoint is not yet available because the endpoint is still being created.
0x1010 | The request to create a network failed because there are no servers were available.
0x1011 | Failed to access the audio device.
0x1012 | Audio operation failed because it was provided an unsupported audio format.
0x1013 | The device handle must reference a local device.
0x1014 | The chat control handle must reference a local chat control.
0x1015 | The endpoint handle must reference a local endpoint.
0x1016 | The specified audio output is pending initialization.
0x1017 | The specified audio output was recognized but disabled.
0x1018 | The specified audio output was recognized but not present.
0x1019 | The specified audio output was recognized but currently unplugged.
0x101A | The allocation service is unavailable.
0x101B | Too many data buffers provided for sending a message.
0x1022 | The client could not find the specified endpoint ID.
0x1023 | The specified endpoint ID was invalid or out of range.
0x1025 | Cannot create an endpoint because the limit specified by the network configuration has been reached.
0x102C | The endpoint list is not yet available.
0x102F | Using a local target chat control is unsupported.
0x1031 | Too many target endpoints specified for sending a message.
0x1034 | The network handle provided does not own the provided endpoint handle.
0x103E | The client failed to resolve the network's IP address and port strings.
0x103F | The multiplayer server response specified an unexpected Azure region.
0x1040 | Attempted to create an endpoint or connect a chat control with an unauthenticated local user.
0x1042 | The serialized network descriptor is not supported by this version of the Party library.
0x1043 | The network identifier is invalid.
0x1044 | The region name is invalid.
0x1045 | The network descriptor's opaque connection information is invalid.
0x1046 | The size of the serialized network descriptor string is too small to be deserialized into valid data.
0x1049 | The chat control is already in the specified network.
0x104A | The chat control is not in the specified network.
0x104B | The opaque connection information is not supported by this version of the Party library.
0x104C | The hostname contained in the network descriptor's opaque connection information was invalid.
0x104D | The port contained in the network descriptor's opaque connection information was invalid.
0x104E | The network configuration is not available yet.
0x104F | The audio render volume was out of the allowable range [0.0, 1.0].
0x1051 | Attempted to perform an invitation operation on behalf of an unauthenticated local user.
0x1058 | The provided target chat control list contained at least one duplicate chat control.
0x1059 | The provided target endpoint list contained at least one duplicate endpoint.
0x105A | A platform error resulted in failure to determine the preferred UI language.
0x105B | XAudio 2.7 debug version not installed on system (install the DirectX SDK Developer Runtime).
0x105C | XAudio 2.7 not installed on system (install the DirectX End-user Runtimes (June 2010)).
0x105E | Authentication was attempted for a user that is already authenticated.
0x1062 | The text-to-speech synthesis request was rejected by the service for being too large.
0x1063 | The text-to-speech synthesis request was throttled.
0x1064 | The text-to-speech synthesis request was unauthorized.
0x1065 | The text-to-speech synthesis request was canceled.
0x1066 | The provided text-to-speech synthesis string was longer than the max text-to-speech synthesis string length.
0x1069 | Parsing the transcription phrase text failed.
0x106A | The region list could not be determined.
0x106B | This version of the Party library is not compatible with the PlayFab service.
0x106C | The hostname returned by the allocation request was invalid.
0x106D | The send message queuing priority was not within the allowed range.
0x1071 | The ping to the quality of service beacon timed out.
0x1072 | No supported regions were found.
0x1073 | The request provided to the PlayFab service was malformed.
0x1074 | The title is not authorized to perform the operation.
0x1075 | Tried to send to a local target; loopback is not yet supported.
0x1079 | The specified text to speech profile was invalid.
0x107A | Attempted to synthesize text without setting a text to speech profile.
0x107B | The provided gender was not recognized.
0x107C | The remote transcription operation failed.
0x107D | An invalid transcription error type was received.
0x107E | The specified text to speech profile identifier was too long.
0x107F | The specified text to speech profile name was too long.
0x1080 | The specified language code was too long.
0x1081 | The PlayFab service has throttled requests for this user.
0x1083 | Parsing the transcription hypothesis text failed.
0x1084 | The requested statistic list contained at least one duplicate statistic type.
0x1085 | The requested statistic list contained an unrecognized or unsupported statistic type.
0x1086 | This title is not enabled for PlayFab Party use. Check the PlayFab game manager portal.
0x1087 | The request to populate text-to-speech profiles was canceled.
0x1089 | The service provided an invalid translation response.
0x108A | The network's configuration will not allow any more unique users.
0x108B | The network's configuration will not allow any more users on this device.
0x108C | The network's configuration will not allow this user to authenticate on any more devices.
0x108D | The network's configuration will not allow this device to connect because the maximum number of devices are already connected.
0x108E | The operation failed because it depended on a user authentication that also failed.
0x108F | An invalid translation result type was received.
0x1090 | Endpoints cannot be created without a successfully authenticated user or an authentication in progress.
0x1092 | The request to populate text-to-speech profiles encountered an unhandled service error.
0x1094 | A translation request returned an unexpected response.
0x1098 | The specified audio device is already in use.
0x1099 | The network descriptor is malformed because the checksum doesn't match the expected value.
0x109A | The serialized network descriptor is malformed because the checksum doesn't match the expected value.
0x109B | The network descriptor is a placeholder that cannot be used on this device at this time.
0x109C | The serialized network descriptor is not in an expected format.
0x109E | The create invitation operation was canceled.
0x109F | The revoke invitation operation was canceled.
0x10A2 | The operation could not be completed because the invitation does not exist.
0x10A4 | A quality of service beacon server region name was invalid.
0x10A5 | A quality of service beacon server hostname was invalid.
0x10A6 | The service returned more quality of service beacon server regions than are supported.
0x10AA | The network operation cannot complete because creating the network failed.
0x10AB | Access to the specified audio output is restricted.
0x10AC | The audio device couldn't be initialized because the app doesn't have microphone focus.
0x10AD | No audio device was initialized because the app doesn't have microphone focus.
0x10AE | No audio devices could be found for the specified user.
0x10AF | A user was recognized, but no associated audio device was found.
0x10BA | The translation operation was canceled due to chat control destruction.
0x10BC | The service failed to validate the provided text-to-speech profile.
0x10BD | The service could not allocate a network because the requested version was invalid.
0x10C7 | This device was disconnected from the Party network because it had no authenticated users for an extended period of time.
0x10C8 | The audio device selection context was invalid.
0x10C9 | The chat text string must not be empty.
0x10CB | XAudio 2.8 and 2.9 not found. These are built in to Windows 8 and Windows 10, respectively.
0x10CD | The requested operation cannot be performed because the network is already being destroyed.
0x10CE | The audio device is already in use by a different application and could not be initialized.
0x10CF | The audio device was removed during initialization.
0x10D0 | The Party module could not be found or loaded.
0x10D1 | The specified PartyOption is unsupported.
0x10D2 | The specified object type is not supported for this PartyOption.
0x10D4 | The memory allocate callback and memory free callback must both be null or both be non-null.
0x10D5 | SetMemoryCallbacks has already been called and may not be called again for the lifetime of this process.
0x10D7 | The Cognitive Services token has expired but hasn't refreshed yet.
0x10D8 | The audio stream doesn't have enough space to handle the buffer.
0x10DA | The source text did not contain any characters that could be synthesized.
0x10DC | User denied access to the audio device.

## Platform-specific errors
Number | Description
------ | ------
0x3000 | The thread affinity mask did not specify any processors that are valid for XAudio2 to affinitize its threads to.
0x3001 | Unmapped XAudio2 error.
0x3002 | Audio operation failed because Windows audio service is not running.
0x3003 | An unspecified platform error occurred when trying to read an environment variable.
0x3004 | Could not locate the audio device interface path.
0x3005 | Device selection type not supported on this platform.
0x3006 | Could not initialize the Android audio device.
0x3009 | The Android audio render device is not ready.
0x300B | Could not find iOS audio unit.
0x300C | Could not set format to iOS audio unit.
0x300E | Could not initialize iOS audio unit.
0x300F | The thread affinity mask did not specify any processors that are valid for Android to affinitize its threads to.
0x3010 | Failed to set the thread affinity.
0x3011 | No platform user was specified.
0x3014 | The Microsoft gaming runtime DLL was not found.
0x3015 | The Microsoft gaming runtime DLL does not support this version of the GDK.
0x3016 | Operation failed because the Microsoft gaming runtime requires an application window to be in the foreground.
0x3017 | The Microsoft gaming runtime is in a suspended state.
0x3018 | Cannot add this user because the max number of users was already added to the Microsoft gaming runtime.
0x3019 | Microsoft gaming runtime operation failed because the user is signed out.
0x301A | The Microsoft gaming runtime needs UI to resolve an issue with a user.
0x301B | Deferral not available in the Microsoft gaming runtime.
0x301C | A user matching the id was not found in the Microsoft gaming runtime.
0x301D | There is no current default user for the Microsoft gaming runtime.
0x301E | The Microsoft gaming runtime failed to resolve a required user privilege.
0x301F | The Microsoft gaming XNetworking feature is unavailable.
0x3020 | The network stack must be initialized before calling PartyManager::Initialize(); use the Microsoft Game Core XNetworkingGetConnectivityHint API to determine when the network stack is initialized.
0x3021 | Callers must pass a port value of 0 when the PartyLocalUdpSocketBindAddressOptions::ExcludeGameCorePreferredUdpMultiplayerPort option is set.
0x3022 | It is invalid to pass PartyLocalUdpSocketBindAddressOptions::ExcludeGameCorePreferredUdpMultiplayerPort in all versions of PlayFab Party except for the Microsoft Game Core version.
// END GENERATED SECTION
