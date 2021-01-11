//////////////////////////////////////////////////////
// Copyright (C) Microsoft. 2018. All rights reserved.
//////////////////////////////////////////////////////


#pragma once

#include "CoreMinimal.h"
#include "Dom/JsonObject.h"
#include "Dom/JsonValue.h"
#include "Serialization/JsonWriter.h"
#include "Serialization/JsonReader.h"
#include "PlayFabCommon/Public/PlayFabAuthenticationContext.h"
#include <Policies/CondensedJsonPrintPolicy.h>

namespace PlayFab
{
    typedef TSharedRef< TJsonWriter<TCHAR, TCondensedJsonPrintPolicy<TCHAR> > > JsonWriter;
    typedef TSharedRef< TJsonReader<TCHAR> > JsonReader;

    template <typename BoxedType>
    class PLAYFABCPP_API Boxed
    {
    public:
        BoxedType mValue;

        Boxed() : mValue(), mIsSet(false) {}
        Boxed(BoxedType value) : mValue(value), mIsSet(true) {}

        Boxed& operator=(BoxedType value) { mValue = value; mIsSet = true; return *this; }
        operator BoxedType() { return mValue; }
        operator BoxedType() const { return mValue; }

        void setNull() { mIsSet = false; }
        bool notNull() { return mIsSet; }
        bool notNull() const { return mIsSet; }
        bool isNull() { return !mIsSet; }
        bool isNull() const { return !mIsSet; }
    private:
        bool mIsSet;
    };

    struct PLAYFABCPP_API FPlayFabCppBaseModel
    {
        virtual ~FPlayFabCppBaseModel() {}
        virtual void writeJSON(JsonWriter& Json) const = 0;
        virtual bool readFromValue(const TSharedPtr<FJsonObject>& obj) = 0;
        virtual bool readFromValue(const TSharedPtr<FJsonValue>& value) { return false; };

        FString toJSONString() const;
    };

    struct PLAYFABCPP_API FPlayFabCppRequestCommon : FPlayFabCppBaseModel
    {
        TSharedPtr<UPlayFabAuthenticationContext> AuthenticationContext; // an optional authentication context (can used in multi-user scenarios)
    };

    struct PLAYFABCPP_API FPlayFabCppResultCommon : FPlayFabCppBaseModel
    {
    };

    struct PLAYFABCPP_API FPlayFabLoginResultCommon : FPlayFabCppResultCommon
    {
        TSharedPtr<UPlayFabAuthenticationContext> AuthenticationContext; // an optional authentication context (can used in multi-user scenarios)
    };

    struct PLAYFABCPP_API FJsonKeeper : public FPlayFabCppBaseModel
    {
    private:
        TSharedRef<class FJsonValue> JsonValue; // Reference so that any time this struct is avaiable, the JsonValue is aswell, even if a FJsonValueNull

    public:
        FJsonKeeper() : JsonValue(MakeShareable(new FJsonValueNull())) {}
        FJsonKeeper(const TSharedPtr<class FJsonValue>& val) : JsonValue(val.ToSharedRef()) {}
        FJsonKeeper(const TSharedPtr<class FJsonObject>& val) : JsonValue(MakeShareable(new FJsonValueObject(val))) {}
        FJsonKeeper(const FString& val) : JsonValue(MakeShareable(new FJsonValueString(val))) {}
        FJsonKeeper(const bool& val) : JsonValue(MakeShareable(new FJsonValueBoolean(val))) {}
        FJsonKeeper(const int8& val) : JsonValue(MakeShareable(new FJsonValueNumber(val))) {}
        FJsonKeeper(const int16& val) : JsonValue(MakeShareable(new FJsonValueNumber(val))) {}
        FJsonKeeper(const int32& val) : JsonValue(MakeShareable(new FJsonValueNumber(val))) {}
        FJsonKeeper(const int64& val) : JsonValue(MakeShareable(new FJsonValueNumber(val))) {}
        FJsonKeeper(const uint8& val) : JsonValue(MakeShareable(new FJsonValueNumber(val))) {}
        FJsonKeeper(const uint16& val) : JsonValue(MakeShareable(new FJsonValueNumber(val))) {}
        FJsonKeeper(const uint32& val) : JsonValue(MakeShareable(new FJsonValueNumber(val))) {}
        FJsonKeeper(const uint64& val) : JsonValue(MakeShareable(new FJsonValueNumber(val))) {}
        FJsonKeeper(const float& val) : JsonValue(MakeShareable(new FJsonValueNumber(val))) {}
        FJsonKeeper(const double& val) : JsonValue(MakeShareable(new FJsonValueNumber(val))) {}

        bool notNull() const { return !isNull(); }
        bool isNull() const { return JsonValue->IsNull(); }

        FJsonKeeper& operator=(const TSharedPtr<class FJsonValue>& val) { JsonValue = val.ToSharedRef(); return *this; }
        FJsonKeeper& operator=(const TSharedPtr<class FJsonObject>& val) { JsonValue = MakeShareable(new FJsonValueObject(val)); return *this; }
        FJsonKeeper& operator=(const FString& val) { JsonValue = MakeShareable(new FJsonValueString(val)); return *this; }
        FJsonKeeper& operator=(const bool& val) { JsonValue = MakeShareable(new FJsonValueBoolean(val)); return *this; }
        FJsonKeeper& operator=(const int8& val) { JsonValue = MakeShareable(new FJsonValueNumber(val)); return *this; }
        FJsonKeeper& operator=(const int16& val) { JsonValue = MakeShareable(new FJsonValueNumber(val)); return *this; }
        FJsonKeeper& operator=(const int32& val) { JsonValue = MakeShareable(new FJsonValueNumber(val)); return *this; }
        FJsonKeeper& operator=(const int64& val) { JsonValue = MakeShareable(new FJsonValueNumber(val)); return *this; }
        FJsonKeeper& operator=(const uint8& val) { JsonValue = MakeShareable(new FJsonValueNumber(val)); return *this; }
        FJsonKeeper& operator=(const uint16& val) { JsonValue = MakeShareable(new FJsonValueNumber(val)); return *this; }
        FJsonKeeper& operator=(const uint32& val) { JsonValue = MakeShareable(new FJsonValueNumber(val)); return *this; }
        FJsonKeeper& operator=(const uint64& val) { JsonValue = MakeShareable(new FJsonValueNumber(val)); return *this; }
        FJsonKeeper& operator=(const float& val) { JsonValue = MakeShareable(new FJsonValueNumber(val)); return *this; }
        FJsonKeeper& operator=(const double& val) { JsonValue = MakeShareable(new FJsonValueNumber(val)); return *this; }

        ~FJsonKeeper() {}
        void writeJSON(JsonWriter& writer) const override;
        bool readFromValue(const TSharedPtr<class FJsonObject>& obj) override;
        bool readFromValue(const TSharedPtr<class FJsonValue>& value) override;

        TSharedPtr<class FJsonValue> GetJsonValue() const { return JsonValue; };
    };

    void writeDatetime(FDateTime datetime, JsonWriter& writer);
    FDateTime readDatetime(const TSharedPtr<FJsonValue>& value);
}
