var path = require("path");

// Making resharper less noisy - These are defined in Generate.js
if (typeof (generateApiSummaryLines) === "undefined") generateApiSummaryLines = function () { };
if (typeof (getCompiledTemplate) === "undefined") getCompiledTemplate = function () { };

exports.makeBpCombinedAPI = function (apis, copyright, sourceDir, apiOutputDir, ueTargetVersion, sdkVersion, buildIdentifier) {
    apiOutputDir = path.join(apiOutputDir, "PlayFabPlugin");
    makeApiIntermal(apis, copyright, sourceDir, apiOutputDir, "All", ueTargetVersion, sdkVersion, buildIdentifier);
}

function makeApiIntermal(apis, copyright, sourceDir, apiOutputDir, libName, ueTargetVersion, sdkVersion, buildIdentifier) {
    console.log("Generating Unreal Engine Blueprints module to " + apiOutputDir);

    var authMechanisms = getAuthMechanisms(apis);
    var locals = {
        apis: apis,
        copyright: copyright,
        buildIdentifier: buildIdentifier,

        generateApiSummary: generateApiSummary,
        getDataTypeSafeName: getDataTypeSafeName,
        hasClientOptions: authMechanisms.includes("SessionTicket"),
        hasServerOptions: authMechanisms.includes("SecretKey"),
        libName: libName,
        sdkVersion: sdkVersion
    };

    // Make the variable api files
    for (var a = 0; a < apis.length; a++)
        makeApiFiles(apis[a], copyright, apiOutputDir, sourceDir, libName, ueTargetVersion);
}

// Create Models, .h and .cpp files
function makeApiFiles(api, copyright, apiOutputDir, sourceDir, libName, ueTargetVersion) {
    var apiLocals = {
        api: api,
        copyright: copyright,
        getAuthBools: getAuthBools,
        getBaseType: getBaseType,
        getPropertyCppType: getPropertyCppType,
        generateApiSummary: generateApiSummary,
        getPropertySerialization: getPropertySerialization,
        getPropertyDeserialization: getPropertyDeserialization,
        getDataTypeSafeName: getDataTypeSafeName,
        getCustomApiAssignmentLogic: getCustomApiAssignmentLogic,
        getCustomApiActivationUrlLogic: getCustomApiActivationUrlLogic,
        hasClientOptions: getAuthMechanisms([api]).includes("SessionTicket"),
        httpRequestDatatype: ueTargetVersion.minor >= 26 ? "TSharedRef<IHttpRequest, ESPMode::ThreadSafe>" : "TSharedRef<IHttpRequest>",
        libName: libName,
        sdkVersion: sdkGlobals.sdkVersion
    };

    var templateName = api.name == "Events" ? "PlayFab_Events_API" : "PlayFab_API";
    var apiHeaderTemplate = getCompiledTemplate(path.resolve(sourceDir, "template/templates/PlayFab/" + templateName + ".h.ejs"));
    writeFile(path.resolve(apiOutputDir, "PlayFab/Source/PlayFab/Classes/PlayFab" + api.name + "API.h"), apiHeaderTemplate(apiLocals));
    var apiCppTemplate = getCompiledTemplate(path.resolve(sourceDir, "template/templates/PlayFab/" + templateName + ".cpp.ejs"));
    writeFile(path.resolve(apiOutputDir, "PlayFab/Source/PlayFab/Private/PlayFab" + api.name + "API.cpp"), apiCppTemplate(apiLocals));

    var apiPlayFabModelTemplate = getCompiledTemplate(path.resolve(sourceDir, "template/templates/PlayFab/PlayFab_Models.h.ejs"));
    writeFile(path.resolve(apiOutputDir, "PlayFab/Source/PlayFab/Classes/PlayFab" + api.name + "Models.h"), apiPlayFabModelTemplate(apiLocals));
    var apiPlayFabModelCppTemplate = getCompiledTemplate(path.resolve(sourceDir, "template/templates/PlayFab/PlayFab_Models.cpp.ejs"));
    writeFile(path.resolve(apiOutputDir, "PlayFab/Source/PlayFab/Private/PlayFab" + api.name + "Models.cpp"), apiPlayFabModelCppTemplate(apiLocals));

    var apiPlayFabModelDecoderHTemplate = getCompiledTemplate(path.resolve(sourceDir, "template/templates/PlayFab/PlayFab_ModelDecoder.h.ejs"));
    writeFile(path.resolve(apiOutputDir, "PlayFab/Source/PlayFab/Classes/PlayFab" + api.name + "ModelDecoder.h"), apiPlayFabModelDecoderHTemplate(apiLocals));
    var apiPlayFabModelDecoderCppTemplate = getCompiledTemplate(path.resolve(sourceDir, "template/templates/PlayFab/PlayFab_ModelDecoder.cpp.ejs"));
    writeFile(path.resolve(apiOutputDir, "PlayFab/Source/PlayFab/Private/PlayFab" + api.name + "ModelDecoder.cpp"), apiPlayFabModelDecoderCppTemplate(apiLocals));
}

// Any playfab datatype names that conflict with Unreal datatype names need to be prefixed with "Pf-"
function getDataTypeSafeName(apiElement, attrName) {
    var pfTypeName = apiElement[attrName];
    if (pfTypeName === "SourceType") // In Unreal, the Enum ESourceType exists in the Android builder and conflicts with our ESourceType enum
        return "PfSourceType";
    if (pfTypeName === "TriggerType") // In Unreal, the Enum ETriggerType exists in the Enhanced Input plugin and conflicts with our ETriggerType enum
        return "PfTriggerType"
    return pfTypeName;
}
exports.getDataTypeSafeName = getDataTypeSafeName;

function getPropertySafeName(property) {
    // Turns out we didn't need this at the time it was added, but it's a good pattern
    return property.name;
}

function getBaseType(datatype) {
    if (datatype.isRequest === true)
        return "FPlayFabRequestCommon";
    if (datatype.isResult === true) {
        if (datatype.className.toLowerCase().endsWith("loginresult"))
            return "FPlayFabLoginResultCommon";
        return "FPlayFabResultCommon";
    }
    throw new Error(`No valid base type because a proper FPlayFabBaseModel doesn't exist yet for the Blueprint API, and ${datatype.className} is neither request nor result.`);
}

function getPropertyCppType(property, datatype) {
    var propSafeName = getPropertySafeName(property);
    var isCollection = property.hasOwnProperty("collection");
    var isArray = isCollection && property.collection === "array";

    switch (property.jsontype) {
        case "String":
            if (isCollection && isArray) {
                return "FString " + propSafeName + ";";
            } else if (isCollection) {
                return "UPlayFabJsonObject* " + propSafeName + " = nullptr;";
            } else if (property.isenum) {
                return "E" + getDataTypeSafeName(property, "actualtype") + " " + propSafeName + " = StaticCast<E" + getDataTypeSafeName(property, "actualtype") + ">(0);";
            } else {
                return "FString " + propSafeName + ";";
            }
        case "Boolean":
            if (isCollection && isArray) {
                return "TArray<bool> " + propSafeName + ";";
            } else if (isCollection) {
                return "UPlayFabJsonObject* " + propSafeName + " = nullptr;";
            } else {
                return "bool " + propSafeName + " = false;";
            }
        case "Number":
            if (isCollection && isArray) {
                return "TArray<int32> " + propSafeName + ";";
            } else if (isCollection) {
                return "UPlayFabJsonObject* " + propSafeName + " = nullptr;";
            } else {
                return "int32 " + propSafeName + " = 0;";
            }
        case "Object":
            if (isCollection && isArray) {
                return "TArray<UPlayFabJsonObject*> " + propSafeName + ";";
            } else if (isCollection) {
                return "UPlayFabJsonObject* " + propSafeName + " = nullptr;";
            } else {
                return "UPlayFabJsonObject* " + propSafeName + " = nullptr;";
            }
    }

    throw "Unknown property type: " + property.actualtype + " for " + property.name + " in " + datatype.name;
}

function getPropertySerialization(tabbing, property, datatype) {
    var propSafeName = getPropertySafeName(property);
    var isCollection = property.hasOwnProperty("collection");
    var isArray = isCollection && property.collection === "array";

    switch (property.jsontype) {
        case "String":
            if (propSafeName === "ParamsEncoded") {
                return tabbing + "if (request.ParamsEncoded != \"\") OutRestJsonObj->SetStringField(TEXT(\"" + property.name + "\"), request." + propSafeName + ");\n";
            }
            if (property.name === "TitleId") {
                return tabbing + "OutRestJsonObj->SetStringField(TEXT(\"" + property.name + "\"), GetDefault<UPlayFabRuntimeSettings>()->TitleId);\n";
            }
            if (isCollection && isArray) {
                return tabbing + "// Check to see if string is empty\n"
                    + tabbing + "if (request." + propSafeName + ".IsEmpty() || request." + propSafeName + " == \"\") {\n"
                    + tabbing + "    OutRestJsonObj->SetFieldNull(TEXT(\"" + property.name + "\"));\n"
                    + tabbing + "} else {\n"
                    + tabbing + "    TArray<FString> " + propSafeName + "Array;\n"
                    + tabbing + "    FString(request." + propSafeName + ").ParseIntoArray(" + propSafeName + "Array, TEXT(\",\"), false);\n"
                    + tabbing + "    OutRestJsonObj->SetStringArrayField(TEXT(\"" + property.name + "\"), " + propSafeName + "Array);\n"
                    + tabbing + "}\n";
            } else if (isCollection) {
                return tabbing + "if (request." + propSafeName + " != nullptr) OutRestJsonObj->SetObjectField(TEXT(\"" + property.name + "\"), request." + propSafeName + ");\n";
            } else if (property.isenum) {
                return tabbing + "FString temp_" + propSafeName + ";\n"
                    + tabbing + "if (GetEnumValueToString<E" + getDataTypeSafeName(property, "actualtype") + ">(TEXT(\"E" + getDataTypeSafeName(property, "actualtype") + "\"), request." + propSafeName + ", temp_" + propSafeName + "))\n"
                    + tabbing + "    OutRestJsonObj->SetStringField(TEXT(\"" + property.name + "\"), temp_" + propSafeName + ");\n";
            } else {
                return tabbing + "if (request." + propSafeName + ".IsEmpty() || request." + propSafeName + " == \"\") {\n"
                    + tabbing + "    OutRestJsonObj->SetFieldNull(TEXT(\"" + property.name + "\"));\n"
                    + tabbing + "} else {\n"
                    + tabbing + "    OutRestJsonObj->SetStringField(TEXT(\"" + property.name + "\"), request." + propSafeName + ");\n"
                    + tabbing + "}\n";
            }
        case "Number":
            if (isCollection && isArray) {
                return tabbing + "// Copy int array to float\n"
                    + tabbing + "TArray<float> tempArray;\n"
                    + tabbing + "for (int32 i = 0; i < request." + propSafeName + ".Num(); ++i) {\n"
                    + tabbing + "    tempArray.Add(float(request." + propSafeName + "[i]));\n"
                    + tabbing + "}\n"
                    + tabbing + "if (tempArray.Num() == 0) {\n"
                    + tabbing + "    OutRestJsonObj->SetFieldNull(TEXT(\"" + property.name + "\"));\n"
                    + tabbing + "} else {\n"
                    + tabbing + "    OutRestJsonObj->SetNumberArrayField(TEXT(\"" + property.name + "\"), tempArray);\n"
                    + tabbing + "}\n";
            } else if (isCollection) {
                return tabbing + "if (request." + propSafeName + " != nullptr) OutRestJsonObj->SetObjectField(TEXT(\"" + property.name + "\"), request." + propSafeName + ");\n";
            } else {
                return tabbing + "OutRestJsonObj->SetNumberField(TEXT(\"" + property.name + "\"), request." + propSafeName + ");\n";
            }
        case "Object":
            if (isCollection && isArray) {
                return tabbing + "if (request." + propSafeName + ".Num() == 0) {\n"
                    + tabbing + "    OutRestJsonObj->SetFieldNull(TEXT(\"" + property.name + "\"));\n"
                    + tabbing + "} else {\n"
                    + tabbing + "    OutRestJsonObj->SetObjectArrayField(TEXT(\"" + property.name + "\"), request." + propSafeName + ");\n"
                    + tabbing + "}\n";
            } else if (isCollection) {
                return tabbing + "if (request." + propSafeName + " != nullptr) OutRestJsonObj->SetObjectField(TEXT(\"" + property.name + "\"), request." + propSafeName + ");\n";
            } else {
                return tabbing + "if (request." + propSafeName + " != nullptr) OutRestJsonObj->SetObjectField(TEXT(\"" + property.name + "\"), request." + propSafeName + ");\n";
            }
        case "Boolean":
            if (isCollection && isArray) {
                return tabbing + "if (request." + propSafeName + ".Num() == 0) {\n"
                    + tabbing + "    OutRestJsonObj->SetFieldNull(TEXT(\"" + property.name + "\"));\n"
                    + tabbing + "} else {\n"
                    + tabbing + "    OutRestJsonObj->SetBoolArrayField(TEXT(\"" + property.name + "\"), request." + propSafeName + ");\n"
                    + tabbing + "}\n";
            } else if (isCollection) {
                return tabbing + "if (request." + propSafeName + " != nullptr) OutRestJsonObj->SetObjectField(TEXT(\"" + property.name + "\"), request." + propSafeName + ");\n";
            } else {
                return tabbing + "OutRestJsonObj->SetBoolField(TEXT(\"" + property.name + "\"), request." + propSafeName + ");\n";
            }
    }
    throw "Cannot parse property: " + datatype.name + "." + property.name;
}

function getPropertyDeserialization(tabbing, property, datatype) {
    var propSafeName = getPropertySafeName(property);
    var isCollection = property.hasOwnProperty("collection");
    var isArray = isCollection && property.collection === "array";
    var isMap = isCollection && property.collection === "map";

    switch (property.jsontype) {
        case "String":
            if (isCollection && isArray) {
                return tabbing + "tempStruct." + propSafeName + " = !(dataObj->HasField(\"" + property.name + "\")) ? TEXT(\"\") : FString::Join(dataObj->GetStringArrayField(\"" + property.name + "\"), TEXT(\",\"));";
            } else if (isCollection && isMap) {
                return tabbing + "tempStruct." + propSafeName + " = !(dataObj->HasField(\"" + property.name + "\")) ? nullptr : dataObj->GetObjectField(\"" + property.name + "\");";
            } else if (property.isenum) {
                return tabbing + "GetEnumValueFromString<E" + getDataTypeSafeName(property, "actualtype") + ">(TEXT(\"E" + getDataTypeSafeName(property, "actualtype") + "\"), dataObj->GetStringField(\"" + property.name + "\"), tempStruct." + propSafeName + ");";
            } else {
                return tabbing + "tempStruct." + propSafeName + " = !(dataObj->HasField(\"" + property.name + "\")) ? TEXT(\"\") : dataObj->GetStringField(\"" + property.name + "\");";
            }
        case "Boolean":
            if (isCollection && isArray) {
                return tabbing + "tempStruct." + propSafeName + " = !(dataObj->HasField(\"" + property.name + "\")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetBoolArrayField(\"" + property.name + "\");";
            } else if (isCollection) {
                return tabbing + "tempStruct." + propSafeName + " = !(dataObj->HasField(\"" + property.name + "\")) ? nullptr : dataObj->GetObjectField(\"" + property.name + "\");";
            } else {
                return tabbing + "tempStruct." + propSafeName + " = !(dataObj->HasField(\"" + property.name + "\")) ? false : dataObj->GetBoolField(\"" + property.name + "\");";
            }
        case "Number":
            if (isCollection && isArray) {
                return tabbing + "// Copy int array to float"
                    + tabbing + "TArray<int32> tempArray;"
                    + tabbing + "for (int32 i = 0; i < dataObj->GetNumberArrayField(\"" + property.name + "\"); ++i) {"
                    + tabbing + "    tempArray.Add(int(dataObj->GetNumberArrayField(\"" + property.name + "\")[i]));"
                    + tabbing + "}"
                    + tabbing + "tempStruct." + propSafeName + " = tempArray;";
            } else if (isCollection) {
                return tabbing + "tempStruct." + propSafeName + " = !(dataObj->HasField(\"" + property.name + "\")) ? nullptr : dataObj->GetObjectField(\"" + property.name + "\");";
            } else {
                return tabbing + "tempStruct." + propSafeName + " = !(dataObj->HasField(\"" + property.name + "\")) ? 0 : int(dataObj->GetNumberField(\"" + property.name + "\"));";
            }
        case "Object":
            if (isCollection && isArray) {
                return tabbing + "tempStruct." + propSafeName + " = !(dataObj->HasField(\"" + property.name + "\")) ? TArray<UPlayFabJsonObject*>() : dataObj->GetObjectArrayField(\"" + property.name + "\");";
            } else if (isCollection) {
                return tabbing + "tempStruct." + propSafeName + " = !(dataObj->HasField(\"" + property.name + "\")) ? nullptr : dataObj->GetObjectField(\"" + property.name + "\");";
            } else {
                return tabbing + "tempStruct." + propSafeName + " = !(dataObj->HasField(\"" + property.name + "\")) ? nullptr : dataObj->GetObjectField(\"" + property.name + "\");";
            }
    }
    throw "Cannot parse property: " + datatype.name + "." + property.name;
}

function generateApiSummary(tabbing, apiElement, summaryParam, extraLines) {
    var lines = generateApiSummaryLines(apiElement, summaryParam, extraLines);

    var output;
    if (lines.length === 1 && lines[0]) {
        output = tabbing + "/** " + lines[0] + " */\n";
    } else if (lines.length > 0) {
        output = tabbing + "/**\n" + tabbing + " * " + lines.join("\n" + tabbing + " * ") + "\n" + tabbing + " */\n";
    } else {
        output = "";
    }
    return output;
}
exports.generateApiSummary = generateApiSummary;

function getAuthBools(tabbing, apiCall) {
    var output = "";
    if (apiCall.auth === "EntityToken" || apiCall.url === "/Authentication/GetEntityToken")
        output += tabbing + "manager->useEntityToken = true;\n";
    if (apiCall.auth === "SecretKey" || apiCall.url === "/Authentication/GetEntityToken")
        output += tabbing + "manager->useSecretKey = true;\n";
    if (apiCall.auth === "SessionTicket" || apiCall.url === "/Authentication/GetEntityToken")
        output += tabbing + "manager->useSessionTicket = true;\n";

    if (apiCall.result === "LoginResult" || apiCall.result === "RegisterPlayFabUserResult")
        output += tabbing + "manager->returnsSessionTicket = true;\n";
    if (apiCall.url === "/Authentication/GetEntityToken" || apiCall.url === "/GameServerIdentity/AuthenticateGameServerWithCustomId")
        output += tabbing + "manager->returnsEntityToken = true;\n";

    return output;
}

function getCustomApiAssignmentLogic(tabbing, api, apiCall) {
    if (api.name === "CloudScript" && apiCall.name === "ExecuteFunction")
    {
        return tabbing + "// Check for local debugging\n"
            + tabbing + "FString localApiServer = PlayFabCommon::PlayFabCommonUtils::GetLocalSettingsFileProperty(TEXT(\"LocalApiServer\"));\n"
            + tabbing + "if (!localApiServer.IsEmpty())\n"
            + tabbing + "{\n"
            + tabbing + "    FString endpoint = TEXT(\"" + apiCall.url + "\");\n"
            + tabbing + "    endpoint.RemoveFromStart(TEXT(\"/\"));\n"
            + tabbing + "    FString url = localApiServer + endpoint;\n"
            + tabbing + "    manager->PlayFabRequestFullURL = url;\n"
            + tabbing + "}\n"
    }
}

function getCustomApiActivationUrlLogic(api) {
    if (api.name === "CloudScript")
    {
        return "RequestUrl = this->PlayFabRequestFullURL.IsEmpty() ? pfSettings->GeneratePfUrl(PlayFabRequestURL) : this->PlayFabRequestFullURL;\n"
    }
    else 
    {
        return "RequestUrl = pfSettings->GeneratePfUrl(PlayFabRequestURL);\n"
    }
}
