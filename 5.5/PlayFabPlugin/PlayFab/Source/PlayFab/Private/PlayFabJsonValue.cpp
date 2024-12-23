//////////////////////////////////////////////////////
// Copyright (C) Microsoft. 2018. All rights reserved.
//////////////////////////////////////////////////////


////////////////////////////////////////////////////////////
// JSon Values
// These are used as a wrapper for the internal json values.
// Originally wriiten by Vladimir Alyamkin.
////////////////////////////////////////////////////////////

#include "PlayFabJsonValue.h"
#include "PlayFabJsonObject.h"
#include "PlayFabPrivate.h"
#include "CoreMinimal.h"


UPlayFabJsonValue::UPlayFabJsonValue(const class FObjectInitializer& PCIP)
    : Super(PCIP)
{

}

UPlayFabJsonValue* UPlayFabJsonValue::ConstructJsonValueNumber(UObject* WorldContextObject, float Number)
{
    TSharedPtr<FJsonValue> NewVal = MakeShareable(new FJsonValueNumber(Number));

    UPlayFabJsonValue* NewValue = NewObject<UPlayFabJsonValue>();
    NewValue->SetRootValue(NewVal);

    return NewValue;
}

UPlayFabJsonValue* UPlayFabJsonValue::ConstructJsonValueString(UObject* WorldContextObject, const FString& StringValue)
{
    TSharedPtr<FJsonValue> NewVal = MakeShareable(new FJsonValueString(StringValue));

    UPlayFabJsonValue* NewValue = NewObject<UPlayFabJsonValue>();
    NewValue->SetRootValue(NewVal);

    return NewValue;
}

UPlayFabJsonValue* UPlayFabJsonValue::ConstructJsonValueBool(UObject* WorldContextObject, bool InValue)
{
    TSharedPtr<FJsonValue> NewVal = MakeShareable(new FJsonValueBoolean(InValue));

    UPlayFabJsonValue* NewValue = NewObject<UPlayFabJsonValue>();
    NewValue->SetRootValue(NewVal);

    return NewValue;
}

UPlayFabJsonValue* UPlayFabJsonValue::ConstructJsonValueArray(UObject* WorldContextObject, const TArray<UPlayFabJsonValue*>& InArray)
{
    // Prepare data array to create new value
    TArray< TSharedPtr<FJsonValue> > ValueArray;
    for (auto InVal : InArray)
    {
        ValueArray.Add(InVal->GetRootValue());
    }

    TSharedPtr<FJsonValue> NewVal = MakeShareable(new FJsonValueArray(ValueArray));

    UPlayFabJsonValue* NewValue = NewObject<UPlayFabJsonValue>();
    NewValue->SetRootValue(NewVal);

    return NewValue;
}

UPlayFabJsonValue* UPlayFabJsonValue::ConstructJsonValueObject(UObject* WorldContextObject, UPlayFabJsonObject *JsonObject)
{
    TSharedPtr<FJsonValue> NewVal = MakeShareable(new FJsonValueObject(JsonObject->GetRootObject()));

    UPlayFabJsonValue* NewValue = NewObject<UPlayFabJsonValue>();
    NewValue->SetRootValue(NewVal);

    return NewValue;
}

UPlayFabJsonValue* ConstructJsonValue(UObject* WorldContextObject, const TSharedPtr<FJsonValue>& InValue)
{
    TSharedPtr<FJsonValue> NewVal = InValue;

    UPlayFabJsonValue* NewValue = NewObject<UPlayFabJsonValue>();
    NewValue->SetRootValue(NewVal);

    return NewValue;
}

TSharedPtr<FJsonValue>& UPlayFabJsonValue::GetRootValue()
{
    return JsonVal;
}

void UPlayFabJsonValue::SetRootValue(TSharedPtr<FJsonValue>& JsonValue)
{
    JsonVal = JsonValue;
}


//////////////////////////////////////////////////////////////////////////
// FJsonValue API

EPFJson::Type UPlayFabJsonValue::GetType() const
{
    if (!JsonVal.IsValid())
    {
        return EPFJson::None;
    }

    switch (JsonVal->Type)
    {
    case EJson::None:
        return EPFJson::None;

    case EJson::Null:
        return EPFJson::Null;

    case EJson::String:
        return EPFJson::String;

    case EJson::Number:
        return EPFJson::Number;

    case EJson::Boolean:
        return EPFJson::Boolean;

    case EJson::Array:
        return EPFJson::Array;

    case EJson::Object:
        return EPFJson::Object;

    default:
        return EPFJson::None;
    }
}

FString UPlayFabJsonValue::GetTypeString() const
{
    if (!JsonVal.IsValid())
    {
        return "None";
    }

    switch (JsonVal->Type)
    {
    case EJson::None:
        return TEXT("None");

    case EJson::Null:
        return TEXT("Null");

    case EJson::String:
        return TEXT("String");

    case EJson::Number:
        return TEXT("Number");

    case EJson::Boolean:
        return TEXT("Boolean");

    case EJson::Array:
        return TEXT("Array");

    case EJson::Object:
        return TEXT("Object");

    default:
        return TEXT("None");
    }
}

bool UPlayFabJsonValue::IsNull() const
{
    if (!JsonVal.IsValid())
    {
        return true;
    }

    return JsonVal->IsNull();
}

float UPlayFabJsonValue::AsNumber() const
{
    if (!JsonVal.IsValid())
    {
        ErrorMessage(TEXT("Number"));
        return 0.f;
    }

    return JsonVal->AsNumber();
}

FString UPlayFabJsonValue::AsString() const
{
    if (!JsonVal.IsValid())
    {
        ErrorMessage(TEXT("String"));
        return FString();
    }

    return JsonVal->AsString();
}

bool UPlayFabJsonValue::AsBool() const
{
    if (!JsonVal.IsValid())
    {
        ErrorMessage(TEXT("Boolean"));
        return false;
    }

    return JsonVal->AsBool();
}

TArray<UPlayFabJsonValue*> UPlayFabJsonValue::AsArray() const
{
    TArray<UPlayFabJsonValue*> OutArray;

    if (!JsonVal.IsValid())
    {
        ErrorMessage(TEXT("Array"));
        return OutArray;
    }

    TArray< TSharedPtr<FJsonValue> > ValArray = JsonVal->AsArray();
    for (auto Value : ValArray)
    {
        UPlayFabJsonValue* NewValue = NewObject<UPlayFabJsonValue>();
        NewValue->SetRootValue(Value);

        OutArray.Add(NewValue);
    }

    return OutArray;
}

UPlayFabJsonObject* UPlayFabJsonValue::AsObject()
{
    if (!JsonVal.IsValid())
    {
        ErrorMessage(TEXT("Object"));
        return nullptr;
    }

    TSharedPtr<FJsonObject> NewObj = JsonVal->AsObject();

    UPlayFabJsonObject* JsonObj = NewObject<UPlayFabJsonObject>();
    JsonObj->SetRootObject(NewObj);

    return JsonObj;
}


//////////////////////////////////////////////////////////////////////////
// Helpers

void UPlayFabJsonValue::ErrorMessage(const FString& InType) const
{
    UE_LOG(LogPlayFab, Error, TEXT("Json Value of type '%s' used as a '%s'."), *GetTypeString(), *InType);
}
