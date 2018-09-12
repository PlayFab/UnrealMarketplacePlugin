//////////////////////////////////////////////////////
// Copyright (C) Microsoft. 2018. All rights reserved.
//////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////////////////////
// This files holds the code for the play fab base model.
//////////////////////////////////////////////////////////////////////////////////////////////

#include "PlayFabBaseModel.h"
#include "PlayFabJsonObject.h"
#include "PlayFabPrivate.h"

const int ERROR_DETAILS_INIT_BUFFER_SIZE = 10000;

void FPlayFabError::decodeError(UPlayFabJsonObject* responseData)
{
    // Check if we have an error
    if (!responseData->HasField("code") || int(responseData->GetNumberField("code")) != 200) // We have an error
    {
        hasError = true;
        ErrorCode = int(responseData->GetNumberField("errorCode"));
        ErrorName = responseData->GetStringField("error");
        ErrorMessage = responseData->GetStringField("errorMessage");
        if (responseData->HasField("errorDetails"))
        {
            ErrorDetails.Empty(ERROR_DETAILS_INIT_BUFFER_SIZE);
            auto detailsObj = responseData->GetObjectField("errorDetails");
            int count = 0;
            for (auto detailParamPair = detailsObj->GetRootObject()->Values.CreateConstIterator(); detailParamPair; ++detailParamPair)
            {
                auto errorArray = detailParamPair->Value->AsArray();
                for (auto paramMsg = errorArray.CreateConstIterator(); paramMsg; ++paramMsg)
                {
                    if (count != 0)
                        ErrorDetails += "\n";
                    ErrorDetails += detailParamPair->Key;
                    ErrorDetails += ": ";
                    ErrorDetails += paramMsg->Get()->AsString();
                    count++;
                }
            }
        }
        else
        {
            ErrorDetails.Empty(0);
        }
    }
    else { hasError = false; }
}
