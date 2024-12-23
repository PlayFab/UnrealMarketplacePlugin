//////////////////////////////////////////////////////
// Copyright (C) Microsoft. 2018. All rights reserved.
//////////////////////////////////////////////////////


////////////////////////////////////////////////////////////
// JSon Objects
// These are used as a wrapper for the internal json objects.
// Originally wriiten by Vladimir Alyamkin.
// Updated by Joshua Lyons to include null values
////////////////////////////////////////////////////////////

#include "PlayFabJsonObject.h"
#include "PlayFabJsonValue.h"
#include "PlayFabPrivate.h"

typedef TJsonWriterFactory< TCHAR, TCondensedJsonPrintPolicy<TCHAR> > FCondensedJsonStringWriterFactory;
typedef TJsonWriter< TCHAR, TCondensedJsonPrintPolicy<TCHAR> > FCondensedJsonStringWriter;

UPlayFabJsonObject::UPlayFabJsonObject(const class FObjectInitializer& PCIP)
    : Super(PCIP)
{
    Reset();
}

UPlayFabJsonObject* UPlayFabJsonObject::ConstructJsonObject(UObject* WorldContextObject)
{
    return NewObject<UPlayFabJsonObject>();
}

void UPlayFabJsonObject::Reset()
{
    if (JsonObj.IsValid())
    {
        JsonObj.Reset();
    }

    JsonObj = MakeShareable(new FJsonObject());
}

TSharedPtr<FJsonObject>& UPlayFabJsonObject::GetRootObject()
{
    return JsonObj;
}

void UPlayFabJsonObject::SetRootObject(TSharedPtr<FJsonObject>& JsonObject)
{
    JsonObj = JsonObject;
}


//////////////////////////////////////////////////////////////////////////
// Serialization

FString UPlayFabJsonObject::EncodeJson() const
{
    if (!JsonObj.IsValid())
    {
        return TEXT("");
    }

    FString OutputString;
    TSharedRef< FCondensedJsonStringWriter > Writer = FCondensedJsonStringWriterFactory::Create(&OutputString);
    FJsonSerializer::Serialize(JsonObj.ToSharedRef(), Writer);

    return OutputString;
}

bool UPlayFabJsonObject::DecodeJson(const FString& JsonString)
{
    TSharedRef< TJsonReader<> > Reader = TJsonReaderFactory<>::Create(*JsonString);
    if (FJsonSerializer::Deserialize(Reader, JsonObj) && JsonObj.IsValid())
    {
        return true;
    }

    // If we've failed to deserialize the string, we should clear our internal data
    Reset();

    UE_LOG(LogPlayFab, Error, TEXT("Json decoding failed for: %s"), *JsonString);

    return false;
}


//////////////////////////////////////////////////////////////////////////
// FJsonObject API

TArray<FString> UPlayFabJsonObject::GetFieldNames()
{
    TArray<FString> Result;

    if (!JsonObj.IsValid())
    {
        return Result;
    }

    JsonObj->Values.GetKeys(Result);

    return Result;
}

bool UPlayFabJsonObject::HasField(const FString& FieldName) const
{
    if (!JsonObj.IsValid())
    {
        return false;
    }

    return JsonObj->HasField(FieldName);
}

void UPlayFabJsonObject::RemoveField(const FString& FieldName)
{
    if (!JsonObj.IsValid())
    {
        return;
    }

    JsonObj->RemoveField(FieldName);
}

UPlayFabJsonValue* UPlayFabJsonObject::GetField(const FString& FieldName) const
{
    if (!JsonObj.IsValid())
    {
        return nullptr;
    }

    TSharedPtr<FJsonValue> NewVal = JsonObj->TryGetField(FieldName);

    UPlayFabJsonValue* NewValue = NewObject<UPlayFabJsonValue>();
    NewValue->SetRootValue(NewVal);

    return NewValue;
}

void UPlayFabJsonObject::SetField(const FString& FieldName, UPlayFabJsonValue* JsonValue)
{
    if (!JsonObj.IsValid())
    {
        return;
    }

    JsonObj->SetField(FieldName, JsonValue->GetRootValue());
}

void UPlayFabJsonObject::SetFieldNull(const FString& FieldName)
{
    if (!JsonObj.IsValid())
    {
        return;
    }

    TSharedPtr<FJsonValue> myNull = MakeShareable(new FJsonValueNull());

    JsonObj->SetField(FieldName, myNull);
}

//////////////////////////////////////////////////////////////////////////
// FJsonObject API Helpers (easy to use with simple Json objects)

float UPlayFabJsonObject::GetNumberField(const FString& FieldName) const
{
    if (!JsonObj.IsValid())
    {
        return 0.0f;
    }

    return JsonObj->GetNumberField(FieldName);
}

void UPlayFabJsonObject::SetNumberField(const FString& FieldName, float Number)
{
    if (!JsonObj.IsValid())
    {
        return;
    }

    JsonObj->SetNumberField(FieldName, Number);
}

FString UPlayFabJsonObject::GetStringField(const FString& FieldName) const
{
    if (!JsonObj.IsValid())
    {
        return TEXT("");
    }

    return JsonObj->GetStringField(FieldName);
}

void UPlayFabJsonObject::SetStringField(const FString& FieldName, const FString& StringValue)
{
    if (!JsonObj.IsValid())
    {
        return;
    }

    JsonObj->SetStringField(FieldName, StringValue);
}

bool UPlayFabJsonObject::GetBoolField(const FString& FieldName) const
{
    if (!JsonObj.IsValid())
    {
        return false;
    }

    return JsonObj->GetBoolField(FieldName);
}

void UPlayFabJsonObject::SetBoolField(const FString& FieldName, bool InValue)
{
    if (!JsonObj.IsValid())
    {
        return;
    }

    JsonObj->SetBoolField(FieldName, InValue);
}

TArray<UPlayFabJsonValue*> UPlayFabJsonObject::GetArrayField(const FString& FieldName)
{
    TArray<UPlayFabJsonValue*> OutArray;
    if (!JsonObj.IsValid())
    {
        return OutArray;
    }

    TArray< TSharedPtr<FJsonValue> > ValArray = JsonObj->GetArrayField(FieldName);
    for (auto Value : ValArray)
    {
        UPlayFabJsonValue* NewValue = NewObject<UPlayFabJsonValue>();
        NewValue->SetRootValue(Value);

        OutArray.Add(NewValue);
    }

    return OutArray;
}

void UPlayFabJsonObject::SetArrayField(const FString& FieldName, const TArray<UPlayFabJsonValue*>& InArray)
{
    if (!JsonObj.IsValid())
    {
        return;
    }

    TArray< TSharedPtr<FJsonValue> > ValArray;

    // Process input array and COPY original values
    for (auto InVal : InArray)
    {
        TSharedPtr<FJsonValue> JsonVal = InVal->GetRootValue();

        switch (InVal->GetType())
        {
        case EPFJson::None:
            break;

        case EPFJson::Null:
            ValArray.Add(MakeShareable(new FJsonValueNull()));
            break;

        case EPFJson::String:
            ValArray.Add(MakeShareable(new FJsonValueString(JsonVal->AsString())));
            break;

        case EPFJson::Number:
            ValArray.Add(MakeShareable(new FJsonValueNumber(JsonVal->AsNumber())));
            break;

        case EPFJson::Boolean:
            ValArray.Add(MakeShareable(new FJsonValueBoolean(JsonVal->AsBool())));
            break;

        case EPFJson::Array:
            ValArray.Add(MakeShareable(new FJsonValueArray(JsonVal->AsArray())));
            break;

        case EPFJson::Object:
            ValArray.Add(MakeShareable(new FJsonValueObject(JsonVal->AsObject())));
            break;

        default:
            break;
        }
    }

    JsonObj->SetArrayField(FieldName, ValArray);
}

void UPlayFabJsonObject::MergeJsonObject(UPlayFabJsonObject* InJsonObject, bool Overwrite)
{
    TArray<FString> Keys = InJsonObject->GetFieldNames();

    for (auto Key : Keys)
    {
        if (Overwrite == false && HasField(Key))
        {
            continue;
        }

        SetField(Key, InJsonObject->GetField(Key));
    }
}

UPlayFabJsonObject* UPlayFabJsonObject::GetObjectField(const FString& FieldName) const
{
    if (!JsonObj.IsValid())
    {
        return nullptr;
    }

    TSharedPtr<FJsonObject> JsonObjField = JsonObj->GetObjectField(FieldName);

    UPlayFabJsonObject* OutRestJsonObj = NewObject<UPlayFabJsonObject>();
    OutRestJsonObj->SetRootObject(JsonObjField);

    return OutRestJsonObj;
}

void UPlayFabJsonObject::SetObjectField(const FString& FieldName, UPlayFabJsonObject* JsonObject)
{
    if (!JsonObj.IsValid())
    {
        return;
    }

    JsonObj->SetObjectField(FieldName, JsonObject->GetRootObject());
}


//////////////////////////////////////////////////////////////////////////
// Array fields helpers (uniform arrays)

TArray<float> UPlayFabJsonObject::GetNumberArrayField(const FString& FieldName)
{
    TArray<float> NumberArray;

    if (!JsonObj.IsValid())
    {
        return NumberArray;
    }

    TArray<TSharedPtr<FJsonValue> > JsonArrayValues = JsonObj->GetArrayField(FieldName);
    for (TArray<TSharedPtr<FJsonValue> >::TConstIterator It(JsonArrayValues); It; ++It)
    {
        NumberArray.Add((*It)->AsNumber());
    }

    return NumberArray;
}

void UPlayFabJsonObject::SetNumberArrayField(const FString& FieldName, const TArray<float>& NumberArray)
{
    if (!JsonObj.IsValid())
    {
        return;
    }

    TArray< TSharedPtr<FJsonValue> > EntriesArray;

    for (auto Number : NumberArray)
    {
        EntriesArray.Add(MakeShareable(new FJsonValueNumber(Number)));
    }

    JsonObj->SetArrayField(FieldName, EntriesArray);
}

TArray<FString> UPlayFabJsonObject::GetStringArrayField(const FString& FieldName)
{
    TArray<FString> StringArray;

    if (!JsonObj.IsValid())
    {
        return StringArray;
    }

    TArray<TSharedPtr<FJsonValue> > JsonArrayValues = JsonObj->GetArrayField(FieldName);
    for (TArray<TSharedPtr<FJsonValue> >::TConstIterator It(JsonArrayValues); It; ++It)
    {
        StringArray.Add((*It)->AsString());
    }

    return StringArray;
}

void UPlayFabJsonObject::SetStringArrayField(const FString& FieldName, const TArray<FString>& StringArray)
{
    if (!JsonObj.IsValid())
    {
        return;
    }

    TArray< TSharedPtr<FJsonValue> > EntriesArray;

    for (auto String : StringArray)
    {
        EntriesArray.Add(MakeShareable(new FJsonValueString(String)));
    }

    JsonObj->SetArrayField(FieldName, EntriesArray);
}

TArray<bool> UPlayFabJsonObject::GetBoolArrayField(const FString& FieldName)
{
    TArray<bool> BoolArray;

    if (!JsonObj.IsValid())
    {
        return BoolArray;
    }

    TArray<TSharedPtr<FJsonValue> > JsonArrayValues = JsonObj->GetArrayField(FieldName);
    for (TArray<TSharedPtr<FJsonValue> >::TConstIterator It(JsonArrayValues); It; ++It)
    {
        BoolArray.Add((*It)->AsBool());
    }

    return BoolArray;
}

void UPlayFabJsonObject::SetBoolArrayField(const FString& FieldName, const TArray<bool>& BoolArray)
{
    if (!JsonObj.IsValid())
    {
        return;
    }

    TArray< TSharedPtr<FJsonValue> > EntriesArray;

    for (auto Boolean : BoolArray)
    {
        EntriesArray.Add(MakeShareable(new FJsonValueBoolean(Boolean)));
    }

    JsonObj->SetArrayField(FieldName, EntriesArray);
}

TArray<UPlayFabJsonObject*> UPlayFabJsonObject::GetObjectArrayField(const FString& FieldName)
{
    TArray<UPlayFabJsonObject*> OutArray;

    if (!JsonObj.IsValid())
    {
        return OutArray;
    }

    TArray< TSharedPtr<FJsonValue> > ValArray = JsonObj->GetArrayField(FieldName);
    for (auto Value : ValArray)
    {
        TSharedPtr<FJsonObject> NewObj = Value->AsObject();

        UPlayFabJsonObject* NewJson = NewObject<UPlayFabJsonObject>();
        NewJson->SetRootObject(NewObj);

        OutArray.Add(NewJson);
    }

    return OutArray;
}

void UPlayFabJsonObject::SetObjectArrayField(const FString& FieldName, const TArray<UPlayFabJsonObject*>& ObjectArray)
{
    if (!JsonObj.IsValid())
    {
        return;
    }

    TArray< TSharedPtr<FJsonValue> > EntriesArray;

    for (auto Value : ObjectArray)
    {
        EntriesArray.Add(MakeShareable(new FJsonValueObject(Value->GetRootObject())));
    }

    JsonObj->SetArrayField(FieldName, EntriesArray);
}
