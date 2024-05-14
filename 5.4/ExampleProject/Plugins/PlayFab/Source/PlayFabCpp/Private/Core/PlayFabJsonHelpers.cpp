//////////////////////////////////////////////////////
// Copyright (C) Microsoft. 2018. All rights reserved.
//////////////////////////////////////////////////////


#include "PlayFabJsonHelpers.h"
#include "Dom/JsonObject.h"

using namespace PlayFab;

static TArray< TSharedPtr<FJsonValue> > EmptyArray;

const TArray< TSharedPtr<FJsonValue> >& FPlayFabJsonHelpers::ReadArray(TSharedPtr<class FJsonObject> Item, const FString& Key)
{
    if (Item->HasTypedField<EJson::Array>(Key))
    {
        return Item->GetArrayField(Key);
    }
    return EmptyArray;
}


// void FPlayFabJsonHelpers::WriteValue(JsonWriter& writer, const FString& Identifier, const bool Value)
// {
//     writer->WriteValue(Identifier, Value);
// }
// 
// void FPlayFabJsonHelpers::WriteValue(JsonWriter& writer, const FString& Identifier, const double Value)
// {
//     writer->WriteValue(Identifier, Value);
// }
// 
// void FPlayFabJsonHelpers::WriteValue(JsonWriter& writer, const FString& Identifier, const int32 Value)
// {
//     writer->WriteValue(Identifier, Value);
// }
// 
// void FPlayFabJsonHelpers::WriteValue(JsonWriter& writer, const FString& Identifier, const uint32 Value)
// {
//     writer->WriteValue(Identifier, static_cast<int64>(Value));
// }
// 
// void FPlayFabJsonHelpers::WriteValue(JsonWriter& writer, const FString& Identifier, const int64 Value)
// {
//     writer->WriteValue(Identifier, Value);
// }
// 
// void FPlayFabJsonHelpers::WriteValue(JsonWriter& writer, const FString& Identifier, const uint64 Value)
// {
//     writer->WriteValue(Identifier, Value);
// }
// 
// void FPlayFabJsonHelpers::WriteValue(JsonWriter& writer, const FString& Identifier, const FString& Value)
// {
//     writer->WriteValue(Identifier, Value);
// }
// 
// void FPlayFabJsonHelpers::WriteValue(JsonWriter& writer, const FString& Identifier, const TCHAR* Value)
// {
//     writer->WriteValue(Identifier, Value);
// }

// void FPlayFabJsonHelpers::WriteValue(JsonWriter& writer, const FString& Identifier, const time_t Value)
// {
// 
// }

bool FPlayFabJsonHelpers::ReadValue(const TSharedPtr<FJsonObject>& obj, const FString& FieldName, double& OutNumber)
{
    return obj->TryGetNumberField(FieldName, OutNumber);
}

bool FPlayFabJsonHelpers::ReadValue(const TSharedPtr<FJsonObject>& obj, const FString& FieldName, int32& OutNumber)
{
    return obj->TryGetNumberField(FieldName, OutNumber);
}

bool FPlayFabJsonHelpers::ReadValue(const TSharedPtr<FJsonObject>& obj, const FString& FieldName, uint32& OutNumber)
{
    return obj->TryGetNumberField(FieldName, OutNumber);
}

// bool FPlayFabJsonHelpers::ReadValue(const TSharedPtr<FJsonObject>& obj, const FString& FieldName, OptionalBool& OutNumber)
// {
//     bool tmp;
//     if (obj->TryGetBoolField(FieldName, tmp))
//     {
//         OutNumber = tmp;
//     }
//     return true;
// }
// 
// bool FPlayFabJsonHelpers::ReadValue(const TSharedPtr<FJsonObject>& obj, const FString& FieldName, OptionalUint16& OutNumber)
// {
//     return false;
// }
// 
// bool FPlayFabJsonHelpers::ReadValue(const TSharedPtr<FJsonObject>& obj, const FString& FieldName, OptionalInt16& OutNumber)
// {
//     return false;
// }
// 
// bool FPlayFabJsonHelpers::ReadValue(const TSharedPtr<FJsonObject>& obj, const FString& FieldName, OptionalUint32& OutNumber)
// {
//     return false;
// }
// 
// bool FPlayFabJsonHelpers::ReadValue(const TSharedPtr<FJsonObject>& obj, const FString& FieldName, OptionalInt32& OutNumber)
// {
//     return false;
// }
// 
// bool FPlayFabJsonHelpers::ReadValue(const TSharedPtr<FJsonObject>& obj, const FString& FieldName, OptionalUint64& OutNumber)
// {
//     return false;
// }
// 
// bool FPlayFabJsonHelpers::ReadValue(const TSharedPtr<FJsonObject>& obj, const FString& FieldName, OptionalInt64& OutNumber)
// {
//     return false;
// }
// 
// bool FPlayFabJsonHelpers::ReadValue(const TSharedPtr<FJsonObject>& obj, const FString& FieldName, OptionalFloat& OutNumber)
// {
//     return false;
// }
// 
// bool FPlayFabJsonHelpers::ReadValue(const TSharedPtr<FJsonObject>& obj, const FString& FieldName, OptionalDouble& OutNumber)
// {
//     return false;
// }
// 
// bool FPlayFabJsonHelpers::ReadValue(const TSharedPtr<FJsonObject>& obj, const FString& FieldName, OptionalTime& OutNumber)
// {
//     return false;
// }



