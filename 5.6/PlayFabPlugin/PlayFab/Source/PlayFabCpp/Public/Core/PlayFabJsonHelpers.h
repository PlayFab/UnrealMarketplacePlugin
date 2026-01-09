//////////////////////////////////////////////////////
// Copyright (C) Microsoft. 2018. All rights reserved.
//////////////////////////////////////////////////////


#pragma once

#include "CoreMinimal.h"

class FJsonObject;
class FJsonValue;

namespace PlayFab
{
    class FPlayFabJsonHelpers
    {
    public:

        // Returns the array named Key or nullptr if it is missing or the wrong type
        static const TArray< TSharedPtr<class FJsonValue> >& ReadArray(TSharedPtr<class FJsonObject> Item, const FString& Key);
//
//         static void WriteValue(JsonWriter& writer, const FString& Identifier, const bool Value);
//         static void WriteValue(JsonWriter& writer, const FString& Identifier, const double Value);
//         static void WriteValue(JsonWriter& writer, const FString& Identifier, const int32 Value);
//         static void WriteValue(JsonWriter& writer, const FString& Identifier, const uint32 Value);
//         static void WriteValue(JsonWriter& writer, const FString& Identifier, const int64 Value);
//         static void WriteValue(JsonWriter& writer, const FString& Identifier, const uint64 Value);
//         static void WriteValue(JsonWriter& writer, const FString& Identifier, const FString& Value);
//         static void WriteValue(JsonWriter& writer, const FString& Identifier, const TCHAR* Value);
//        static void WriteValue(JsonWriter& writer, const FString& Identifier, const time_t Value);

        static bool ReadValue(const TSharedPtr<class FJsonObject>& obj, const FString& FieldName, double& OutNumber);
        static bool ReadValue(const TSharedPtr<class FJsonObject>& obj, const FString& FieldName, int32& OutNumber);
        static bool ReadValue(const TSharedPtr<class FJsonObject>& obj, const FString& FieldName, uint32& OutNumber);

        // why?
//         static bool ReadValue(const TSharedPtr<class FJsonObject>& obj, const FString& FieldName, OptionalBool& OutNumber);
//         static bool ReadValue(const TSharedPtr<class FJsonObject>& obj, const FString& FieldName, OptionalUint16& OutNumber);
//         static bool ReadValue(const TSharedPtr<class FJsonObject>& obj, const FString& FieldName, OptionalInt16& OutNumber);
//         static bool ReadValue(const TSharedPtr<class FJsonObject>& obj, const FString& FieldName, OptionalUint32& OutNumber);
//         static bool ReadValue(const TSharedPtr<class FJsonObject>& obj, const FString& FieldName, OptionalInt32& OutNumber);
//         static bool ReadValue(const TSharedPtr<class FJsonObject>& obj, const FString& FieldName, OptionalUint64& OutNumber);
//         static bool ReadValue(const TSharedPtr<class FJsonObject>& obj, const FString& FieldName, OptionalInt64& OutNumber);
//         static bool ReadValue(const TSharedPtr<class FJsonObject>& obj, const FString& FieldName, OptionalFloat& OutNumber);
//         static bool ReadValue(const TSharedPtr<class FJsonObject>& obj, const FString& FieldName, OptionalDouble& OutNumber);
//         static bool ReadValue(const TSharedPtr<class FJsonObject>& obj, const FString& FieldName, OptionalTime& OutNumber);

    private:
        FPlayFabJsonHelpers() {}
    };
}
