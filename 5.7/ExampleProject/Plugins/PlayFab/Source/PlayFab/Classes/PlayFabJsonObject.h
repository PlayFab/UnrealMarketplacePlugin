//////////////////////////////////////////////////////
// Copyright (C) Microsoft. 2018. All rights reserved.
//////////////////////////////////////////////////////


////////////////////////////////////////////////////////////
// JSon Objects
// These are used as a wrapper for the internal json objects.
// Originally wriiten by Vladimir Alyamkin.
// Updated by Joshua Lyons to include null values
////////////////////////////////////////////////////////////

#pragma once

#include "CoreMinimal.h"
#include "Dom/JsonObject.h"
#include "Policies/CondensedJsonPrintPolicy.h"
#include "PlayFabJsonObject.generated.h"

class UPlayFabJsonValue;

/**
 * Blueprintable FJsonObject wrapper
 */
UCLASS(BlueprintType, Blueprintable)
class PLAYFAB_API UPlayFabJsonObject : public UObject
{
    GENERATED_UCLASS_BODY()

    /** Create new Json object */
    UFUNCTION(BlueprintPure, meta = (DisplayName = "Construct Json Object", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"), Category = "PlayFab | Json")
        static UPlayFabJsonObject* ConstructJsonObject(UObject* WorldContextObject);

    /** Reset all internal data */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Json")
        void Reset();

    /** Get the root Json object */
    TSharedPtr<FJsonObject>& GetRootObject();

    /** Set the root Json object */
    void SetRootObject(TSharedPtr<FJsonObject>& JsonObject);


    //////////////////////////////////////////////////////////////////////////
    // Serialization

    /** Serialize Json to string */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Json")
        FString EncodeJson() const;

    /** Construct Json object from string */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Json")
        bool DecodeJson(const FString& JsonString);


    //////////////////////////////////////////////////////////////////////////
    // FJsonObject API

    /** Returns a list of field names that exist in the object */
    UFUNCTION(BlueprintPure, Category = "PlayFab | Json")
        TArray<FString> GetFieldNames();

    /** Checks to see if the FieldName exists in the object */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Json")
        bool HasField(const FString& FieldName) const;

    /** Remove field named FieldName */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Json")
        void RemoveField(const FString& FieldName);

    /** Get the field named FieldName as a JsonValue */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Json")
        UPlayFabJsonValue* GetField(const FString& FieldName) const;

    /** Add a field named FieldName with a Value */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Json")
        void SetField(const FString& FieldName, UPlayFabJsonValue* JsonValue);

    /** Add a field named FieldName with a null value */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Json")
        void SetFieldNull(const FString& FieldName);

    /** Get the field named FieldName as a Json Array */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Json")
        TArray<UPlayFabJsonValue*> GetArrayField(const FString& FieldName);

    /** Set an ObjectField named FieldName and value of Json Array */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Json")
        void SetArrayField(const FString& FieldName, const TArray<UPlayFabJsonValue*>& InArray);

    /** Adds all of the fields from one json object to this one */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Json")
        void MergeJsonObject(UPlayFabJsonObject* InJsonObject, bool Overwrite);


    //////////////////////////////////////////////////////////////////////////
    // FJsonObject API Helpers (easy to use with simple Json objects)

    /** Get the field named FieldName as a number. Ensures that the field is present and is of type Json number.
     * Attn.!! float used instead of double to make the function blueprintable! */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Json")
        float GetNumberField(const FString& FieldName) const;

    /** Add a field named FieldName with Number as value
     * Attn.!! float used instead of double to make the function blueprintable! */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Json")
        void SetNumberField(const FString& FieldName, float Number);

    /** Get the field named FieldName as a string. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Json")
        FString GetStringField(const FString& FieldName) const;

    /** Add a field named FieldName with value of StringValue */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Json")
        void SetStringField(const FString& FieldName, const FString& StringValue);

    /** Get the field named FieldName as a boolean. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Json")
        bool GetBoolField(const FString& FieldName) const;

    /** Set a boolean field named FieldName and value of InValue */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Json")
        void SetBoolField(const FString& FieldName, bool InValue);

    /** Get the field named FieldName as a Json object. */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Json")
        UPlayFabJsonObject* GetObjectField(const FString& FieldName) const;

    /** Set an ObjectField named FieldName and value of JsonObject */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Json")
        void SetObjectField(const FString& FieldName, UPlayFabJsonObject* JsonObject);


    //////////////////////////////////////////////////////////////////////////
    // Array fields helpers (uniform arrays)

    /** Get the field named FieldName as a Number Array. Use it only if you're sure that array is uniform!
     * Attn.!! float used instead of double to make the function blueprintable! */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Json")
        TArray<float> GetNumberArrayField(const FString& FieldName);

    /** Set an ObjectField named FieldName and value of Number Array
     * Attn.!! float used instead of double to make the function blueprintable! */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Json")
        void SetNumberArrayField(const FString& FieldName, const TArray<float>& NumberArray);

    /** Get the field named FieldName as a String Array. Use it only if you're sure that array is uniform! */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Json")
        TArray<FString> GetStringArrayField(const FString& FieldName);

    /** Set an ObjectField named FieldName and value of String Array */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Json")
        void SetStringArrayField(const FString& FieldName, const TArray<FString>& StringArray);

    /** Get the field named FieldName as a Bool Array. Use it only if you're sure that array is uniform! */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Json")
        TArray<bool> GetBoolArrayField(const FString& FieldName);

    /** Set an ObjectField named FieldName and value of Bool Array */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Json")
        void SetBoolArrayField(const FString& FieldName, const TArray<bool>& BoolArray);

    /** Get the field named FieldName as an Object Array. Use it only if you're sure that array is uniform! */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Json")
        TArray<UPlayFabJsonObject*> GetObjectArrayField(const FString& FieldName);

    /** Set an ObjectField named FieldName and value of Ob Array */
    UFUNCTION(BlueprintCallable, Category = "PlayFab | Json")
        void SetObjectArrayField(const FString& FieldName, const TArray<UPlayFabJsonObject*>& ObjectArray);


    //////////////////////////////////////////////////////////////////////////
    // Data

private:
    /** Internal JSON data */
    TSharedPtr<FJsonObject> JsonObj;

};
