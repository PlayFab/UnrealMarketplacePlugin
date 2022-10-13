var path = require("path");

// Making resharper less noisy - These are defined in Generate.js
if (typeof (generateApiSummaryLines) === "undefined") generateApiSummaryLines = function () { };
if (typeof (getCompiledTemplate) === "undefined") getCompiledTemplate = function () { };
if (typeof (templatizeTree) === "undefined") templatizeTree = function () { };

var maxEnumSize = 255;

exports.makeCppCombinedAPI = function (apis, copyright, sourceDir, baseApiOutputDir, ueTargetVersion, sdkVersion, buildIdentifier) {
    var locals = {
        apis: apis,
        buildIdentifier: buildIdentifier,
        copyright: copyright,
        errorList: apis[0].errorList,
        errors: apis[0].errors,
        friendlyName: "PlayFab Cpp Module",
        sdkVersion: sdkVersion
    };

    var subFolders = ["PlayFabPlugin"]; // Raw plugin folder
    for (var i = 0; i < subFolders.length; i++) {
        var apiOutputDir = path.resolve(baseApiOutputDir, subFolders[i]);
        var outputCodeDir = path.resolve(apiOutputDir, "PlayFab/Source/PlayFabCpp");

        console.log("Generating UE4 C++ Module from " + sourceDir + " to " + apiOutputDir);

        for (var a = 0; a < apis.length; a++)
            makeApi(apis[a], copyright, sourceDir, outputCodeDir, "Core/");
        generateModels(apis, copyright, sourceDir, outputCodeDir, "All", "Core/");
    }
}

function makeApi(api, copyright, sourceDir, apiOutputDir, subdir) {
    var apiLocals = {
        api: api,
        copyright: copyright,
        generateApiSummary: generateApiSummary,
        getAuthParams: getAuthParams,
        getRequestActions: getRequestActions,
        getCustomApiLogic: getCustomApiLogic,
        getResultActions: getResultActions,
        hasClientOptions: getAuthMechanisms([api]).includes("SessionTicket"),
        hasRequest: hasRequest
    };

    var apiHeaderTemplate = getCompiledTemplate(path.resolve(sourceDir, "template/templates/PlayFabCpp/core/PlayFab_API.h.ejs"));
    writeFile(path.resolve(apiOutputDir, "Public/" + subdir + "PlayFab" + api.name + "API.h"), apiHeaderTemplate(apiLocals));

    var instanceApiHeaderTemplate = getCompiledTemplate(path.resolve(sourceDir, "template/templates/PlayFabCpp/core/PlayFab_InstanceAPI.h.ejs"));
    writeFile(path.resolve(apiOutputDir, "Public/" + subdir + "PlayFab" + api.name + "InstanceAPI.h"), instanceApiHeaderTemplate(apiLocals));

    var apiBodyTemplate = getCompiledTemplate(path.resolve(sourceDir, "template/templates/PlayFabCpp/core/PlayFab_API.cpp.ejs"));
    writeFile(path.resolve(apiOutputDir, "Private/" + subdir + "PlayFab" + api.name + "API.cpp"), apiBodyTemplate(apiLocals));

    var instanceApiBodyTemplate = getCompiledTemplate(path.resolve(sourceDir, "template/templates/PlayFabCpp/core/PlayFab_InstanceAPI.cpp.ejs"));
    writeFile(path.resolve(apiOutputDir, "Private/" + subdir + "PlayFab" + api.name + "InstanceAPI.cpp"), instanceApiBodyTemplate(apiLocals));
}

function generateModels(apis, copyright, sourceDir, apiOutputDir, libraryName, subdir) {
    for (var a = 0; a < apis.length; a++) {
        var api = apis[a];

        // Order datatypes based on dependency graph
        var orderedTypes = [];
        var addedSet = {};
        for (var i in api.datatypes)
            addTypeAndDependencies(api.datatypes[i], api.datatypes, orderedTypes, addedSet);

        var modelLocals = {
            api: api,
            copyright: copyright,
            datatypes: orderedTypes,
            generateApiSummary: generateApiSummary,
            getBaseType: getBaseType,
            getPropertyCopyValue: getPropertyCopyValue,
            getPropertyDef: getPropertyDef,
            getPropertyDefaultValue: getPropertyDefaultValue,
            getPropertyDeserializer: getPropertyDeserializer,
            getPropertySerializer: getPropertySerializer,
            getPropertySafeName: getPropertySafeName,
            libraryName: libraryName
        };

        var modelHeaderTemplate = getCompiledTemplate(path.resolve(sourceDir, "template/templates/PlayFabCpp/core/PlayFab_DataModels.h.ejs"));
        writeFile(path.resolve(apiOutputDir, "Public/" + subdir + "/PlayFab" + api.name + "DataModels.h"), modelHeaderTemplate(modelLocals));

        var modelBodyTemplate = getCompiledTemplate(path.resolve(sourceDir, "template/templates/PlayFabCpp/core/PlayFab_DataModels.cpp.ejs"));
        writeFile(path.resolve(apiOutputDir, "Private/" + subdir + "PlayFab" + api.name + "DataModels.cpp"), modelBodyTemplate(modelLocals));
    }
}

function generateApiSummary(tabbing, apiElement, summaryParam, extraLines) {
    if (!extraLines)
        extraLines = [];
    if (apiElement.hasOwnProperty("requestDetails"))
        extraLines.push(apiElement.requestDetails);

    var lines = generateApiSummaryLines(apiElement, summaryParam, extraLines);
    if (apiElement.optional) {
        if (lines.count === 0)
            lines.unshift("[optional]");
        else
            lines[0] = "[optional] " + lines[0];
    }

    var output;
    if (lines.length === 1 && lines[0])
        output = tabbing + "// " + lines[0] + "\n";
    else if (lines.length > 0)
        output = tabbing + "/**\n" + tabbing + " * " + lines.join("\n" + tabbing + " * ") + "\n" + tabbing + " */\n";
    else
        output = "";
    return output;
}

function hasRequest(apiCall, api) {
    var requestType = api.datatypes[apiCall.request];
    return requestType.properties.length > 0;
}

function getPropertyDef(tabbing, api, datatype, property) {
    var safePropName = getPropertySafeName(property);

    if (property.collection === "array")
        return tabbing + "TArray<" + getPropertyCppType(api, datatype, property, false) + "> " + safePropName + ";\n";
    else if (property.collection === "map")
        return tabbing + "TMap<FString, " + getPropertyCppType(api, datatype, property, false) + "> " + safePropName + ";\n";
    else
        return tabbing + getPropertyCppType(api, datatype, property, true) + " " + safePropName + ";\n\n";
}

// PFWORKBIN-445 & PFWORKBIN-302 - variable names can't be the same as the variable type when compiling for android
function getPropertySafeName(property) {
    return (property.actualtype === property.name) ? "pf" + property.name : property.name;
}

function getPropertyCppType(api, datatype, property, needOptional) {
    var isOptional = property.optional && needOptional;

    if (property.actualtype === "String")
        return "FString";
    else if (property.isenum && api.datatypes[property.actualtype].enumvalues.length > maxEnumSize)
        return "FString";
    else if (property.actualtype === "Boolean")
        return isOptional ? "Boxed<bool>" : "bool";
    else if (property.actualtype === "int16")
        return isOptional ? "Boxed<int16>" : "int16";
    else if (property.actualtype === "uint16")
        return isOptional ? "Boxed<uint16>" : "uint16";
    else if (property.actualtype === "int32")
        return isOptional ? "Boxed<int32>" : "int32";
    else if (property.actualtype === "uint32")
        return isOptional ? "Boxed<uint32>" : "uint32";
    else if (property.actualtype === "int64")
        return isOptional ? "Boxed<int64>" : "int64";
    else if (property.actualtype === "uint64")
        return isOptional ? "Boxed<uint64>" : "uint64";
    else if (property.actualtype === "float")
        return isOptional ? "Boxed<float>" : "float";
    else if (property.actualtype === "double")
        return isOptional ? "Boxed<double>" : "double";
    else if (property.actualtype === "DateTime")
        return isOptional ? "Boxed<FDateTime>" : "FDateTime";
    else if (property.isclass)
        return isOptional ? "TSharedPtr<F" + property.actualtype + ">" : "F" + property.actualtype; // sub object
    else if (property.isenum)
        return isOptional ? ("Boxed<" + property.actualtype + ">") : property.actualtype; // enum
    else if (property.actualtype === "object")
        return "FJsonKeeper";
    throw "getPropertyCppType: Unknown property type: " + property.actualtype + " for " + property.name + " in " + datatype.name;
}

function getPropertyDefaultValue(api, datatype, property) {
    var isOptional = property.optional;
    if (property.collection)
        return "";

    if (property.actualtype === "String")
        return "";
    else if (property.isenum && api.datatypes[property.actualtype].enumvalues.length > maxEnumSize)
        return "";
    else if (property.actualtype === "Boolean")
        return isOptional ? "" : "false";
    else if (property.actualtype === "int16")
        return isOptional ? "" : "0";
    else if (property.actualtype === "uint16")
        return isOptional ? "" : "0";
    else if (property.actualtype === "int32")
        return isOptional ? "" : "0";
    else if (property.actualtype === "uint32")
        return isOptional ? "" : "0";
    else if (property.actualtype === "int64")
        return isOptional ? "" : "0";
    else if (property.actualtype === "uint64")
        return isOptional ? "" : "0";
    else if (property.actualtype === "float")
        return isOptional ? "" : "0";
    else if (property.actualtype === "double")
        return isOptional ? "" : "0";
    else if (property.actualtype === "DateTime")
        return isOptional ? "" : "0";
    else if (property.isclass)
        return isOptional ? "nullptr" : ""; // sub object
    else if (property.isenum)
        return ""; // isOptional ? "" : ""; // enum
    else if (property.actualtype === "object")
        return "";
    throw "getPropertyDefaultValue: Unknown property type: " + property.actualtype + " for " + property.name + " in " + datatype.name;
}

function getPropertyCopyValue(property) {
    var safePropName = getPropertySafeName(property);

    if (property.isclass && property.optional && !property.collection)
        return "src." + safePropName + ".IsValid() ? MakeShareable(new F" + property.actualtype + "(*src." + safePropName + ")) : nullptr";
    return "src." + safePropName;
}

function getPropertySerializer(tabbing, api, datatype, property) {
    if (property.collection === "array")
        return getArrayPropertySerializer(tabbing, api, datatype, property);
    else if (property.collection === "map")
        return getMapPropertySerializer(tabbing, api, datatype, property);

    var writer = null;
    var tester = null;
    var safePropName = getPropertySafeName(property);

    function setTemps(intWriter, intTester) {
        writer = intWriter;
        tester = intTester;
    }

    if (property.actualtype === "String")
        setTemps("writer->WriteValue(" + safePropName + ");", safePropName + ".IsEmpty() == false");
    else if (property.isenum && api.datatypes[property.actualtype].enumvalues.length > maxEnumSize)
        setTemps("writer->WriteValue(" + safePropName + ");", safePropName + ".IsEmpty() == false");
    else if (property.actualtype === "Boolean")
        setTemps("writer->WriteValue(" + safePropName + ");", safePropName + ".notNull()");
    else if (property.actualtype === "int16")
        setTemps("writer->WriteValue(" + safePropName + ");", safePropName + ".notNull()");
    else if (property.actualtype === "uint16")
        setTemps("writer->WriteValue(" + safePropName + ");", safePropName + ".notNull()");
    else if (property.actualtype === "int32")
        setTemps("writer->WriteValue(" + safePropName + ");", safePropName + ".notNull()");
    else if (property.actualtype === "uint32")
        setTemps("writer->WriteValue(static_cast<int64>(" + safePropName + "));", safePropName + ".notNull()");
    else if (property.actualtype === "int64")
        setTemps("writer->WriteValue(" + safePropName + ");", safePropName + ".notNull()");
    else if (property.actualtype === "uint64")
        setTemps("writer->WriteValue(static_cast<int64>(" + safePropName + "));", safePropName + ".notNull()");
    else if (property.actualtype === "float")
        setTemps("writer->WriteValue(" + safePropName + ");", safePropName + ".notNull()");
    else if (property.actualtype === "double")
        setTemps("writer->WriteValue(" + safePropName + ");", safePropName + ".notNull()");
    else if (property.actualtype === "DateTime")
        setTemps("writeDatetime(" + safePropName + ", writer);", safePropName + ".notNull()");
    else if (property.isclass && property.optional)
        setTemps(safePropName + "->writeJSON(writer);", safePropName + ".IsValid()");
    else if (property.isclass)
        setTemps(safePropName + ".writeJSON(writer);", safePropName + ".IsValid()");
    else if (property.isenum)
        setTemps("write" + property.actualtype + "EnumJSON(" + safePropName + ", writer);", safePropName + ".notNull()");
    else if (property.actualtype === "object")
        setTemps(safePropName + ".writeJSON(writer);", safePropName + ".notNull()");
    else
        throw "getPropertySerializer: Unknown property type: " + property.actualtype + " for " + property.name + " in " + datatype.name;

    if (property.optional) {
        return tabbing + "if (" + tester + ")\n" + tabbing + "{\n" + tabbing + tabbing + "writer->WriteIdentifierPrefix(TEXT(\"" + property.name + "\"));\n" + tabbing + tabbing + writer + "\n" + tabbing + "}";
    }
    else {
        // this property is REQUIRED
        if (property.actualtype === "String") {
            return tabbing + "if (!" + tester + ")\n" + tabbing + "{\n" + tabbing + tabbing + "UE_LOG(LogTemp, Error, TEXT(\"This field is required: " + datatype.name + "::" + property.name + ", PlayFab calls may not work if it remains empty.\"));\n" + tabbing + "}\n" + tabbing + "else\n" + tabbing + "{\n" + tabbing + tabbing + "writer->WriteIdentifierPrefix(TEXT(\"" + property.name + "\"));\n" + tabbing + tabbing + writer + "\n" + tabbing + "}";
        }
        else {
            return tabbing + "writer->WriteIdentifierPrefix(TEXT(\"" + property.name + "\"));\n" + tabbing + writer;
        }
    }
}

function getArrayPropertySerializer(tabbing, api, datatype, property) {
    var isOptional = property.optional;
    var cppType = getPropertyCppType(api, datatype, property, false);

    var writer = "writer->WriteValue(item);";
    if (property.actualtype === "uint64")
        writer = "writer->WriteValue(static_cast<int64>(item));";
    else if (property.actualtype === "DateTime")
        writer = "writeDatetime(item, writer);";
    else if (property.isclass)
        writer = "item.writeJSON(writer);";
    else if (property.isenum && api.datatypes[property.actualtype].enumvalues.length <= maxEnumSize)
        writer = "write" + property.actualtype + "EnumJSON(item, writer);";
    else if (property.actualtype === "object")
        writer = "item.writeJSON(writer);";

    var collectionTabbing = isOptional ? "    " + tabbing : tabbing;
    var collectionWriter = collectionTabbing + "writer->WriteArrayStart(TEXT(\"" + property.name + "\"));\n"
        + collectionTabbing + "for (const " + cppType + "& item : " + property.name + ")\n"
        + collectionTabbing + "    " + writer + "\n"
        + collectionTabbing + "writer->WriteArrayEnd();\n";

    if (isOptional)
        return tabbing + "if (" + property.name + ".Num() != 0)\n"
            + tabbing + "{\n"
            + collectionWriter
            + tabbing + "}\n";
    return collectionWriter;
}

function getMapPropertySerializer(tabbing, api, datatype, property) {
    var isOptional = property.optional;
    var cppType = getPropertyCppType(api, datatype, property, false);

    var writer = "writer->WriteValue((*It).Value);";
    if (property.actualtype === "uint32")
        writer = "writer->WriteValue(static_cast<int64>((*It).Value));";
    else if (property.actualtype === "DateTime")
        writer = "writeDatetime((*It).Value, writer);";
    else if (property.isclass)
        writer = "(*It).Value.writeJSON(writer);";
    else if (property.isenum && api.datatypes[property.actualtype].enumvalues.length > maxEnumSize)
        ; // Explicit do nothing, use the default string writer above
    else if (property.isenum)
        writer = "write" + property.actualtype + "EnumJSON((*It).Value, writer);";
    else if (property.actualtype === "object")
        writer = "(*It).Value.writeJSON(writer);";

    var collectionTabbing = isOptional ? "    " + tabbing : tabbing;
    var collectionWriter = collectionTabbing + "writer->WriteObjectStart(TEXT(\"" + property.name + "\"));\n"
        + collectionTabbing + "for (TMap<FString, " + cppType + ">::TConstIterator It(" + property.name + "); It; ++It)\n"
        + collectionTabbing + "{\n"
        + collectionTabbing + "    writer->WriteIdentifierPrefix((*It).Key);\n"
        + collectionTabbing + "    " + writer + "\n"
        + collectionTabbing + "}\n"
        + collectionTabbing + "writer->WriteObjectEnd();\n";

    if (isOptional)
        return tabbing + "if (" + property.name + ".Num() != 0)\n"
            + tabbing + "{\n"
            + collectionWriter
            + tabbing + "}";
    return tabbing + collectionWriter;
}

// custom deserializer for readDatetime
function getDateTimeDeserializer(tabbing, property) {
    var safePropName = getPropertySafeName(property);
    var propNameValue = property.name + "Value";

    var result = tabbing + "const TSharedPtr<FJsonValue> " + propNameValue + " = obj->TryGetField(TEXT(\"" + property.name + "\"));\n"
        + tabbing + "if (" + propNameValue + ".IsValid())\n"
        + tabbing + "    " + safePropName + " = readDatetime(" + propNameValue + ");\n";
    return result;
}

function getPropertyDeserializer(tabbing, api, datatype, property) {
    var safePropName = getPropertySafeName(property);

    if (property.collection === "array")
        return getArrayPropertyDeserializer(tabbing, api, datatype, property);
    else if (property.collection === "map")
        return getMapPropertyDeserializer(tabbing, api, datatype, property);

    var getter = null;
    var temporary = "";
    var propNameVal = property.name + "Value";
    function setTemps(intTemporary, intGetter) {
        temporary = intTemporary;
        getter = intGetter;
    }

    if (property.actualtype === "String")
        setTemps("FString TmpValue;", "TryGetString(TmpValue)");
    else if (property.isenum && api.datatypes[property.actualtype].enumvalues.length > maxEnumSize)
        setTemps("FString TmpValue;", "TryGetString(TmpValue)");
    else if (property.actualtype === "Boolean")
        setTemps("bool TmpValue;", "TryGetBool(TmpValue)");
    else if (property.actualtype === "int16")
        setTemps("int32 TmpValue;", "TryGetNumber(TmpValue)");
    else if (property.actualtype === "uint16")
        setTemps("uint32 TmpValue;", "TryGetNumber(TmpValue)");
    else if (property.actualtype === "int32")
        setTemps("int32 TmpValue;", "TryGetNumber(TmpValue)");
    else if (property.actualtype === "uint32")
        setTemps("uint32 TmpValue;", "TryGetNumber(TmpValue)");
    else if (property.actualtype === "int64")
        setTemps("int64 TmpValue;", "TryGetNumber(TmpValue)");
    else if (property.actualtype === "uint64")
        setTemps("int64 TmpValue;", "TryGetNumber(TmpValue)");
    else if (property.actualtype === "float")
        setTemps("double TmpValue;", "TryGetNumber(TmpValue)");
    else if (property.actualtype === "double")
        setTemps("double TmpValue;", "TryGetNumber(TmpValue)");
    else if (property.actualtype === "DateTime")
        return getDateTimeDeserializer(tabbing, property);
    else if (property.isclass && property.optional)
        getter = "MakeShareable(new F" + property.actualtype + "(" + propNameVal + "->AsObject()));";
    else if (property.isclass)
        getter = "F" + property.actualtype + "(" + propNameVal + "->AsObject());";
    else if (property.isenum)
        return tabbing + safePropName + " = read" + property.actualtype + "FromValue(obj->TryGetField(TEXT(\"" + property.name + "\")));";
    else if (property.actualtype === "object")
        getter = "FJsonKeeper(" + propNameVal + ");"; // implement custom call for this
    else
        throw "getPropertyDeserializer: Unknown property type: " + property.actualtype + " for " + property.name + " in " + datatype.name;

    var output = tabbing + "const TSharedPtr<FJsonValue> " + propNameVal + " = obj->TryGetField(TEXT(\"" + property.name + "\"));\n"
        + tabbing + "if (" + propNameVal + ".IsValid() && !" + propNameVal + "->IsNull())\n"
        + tabbing + "{\n";
    if (property.isclass || property.actualtype === "object")
        output += tabbing + "    " + safePropName + " = " + getter + "\n";
    else if (temporary)
        output += tabbing + "    " + temporary + "\n"
            + tabbing + "    if (" + propNameVal + "->" + getter + ") { " + safePropName + " = TmpValue; }\n";
    else // if (!temporary)
        output += + tabbing + "    if (" + propNameVal + "->" + getter + ") { " + safePropName + " = TmpValue; }\n";
    output += tabbing + "}";

    return output;
}

// specialization for array of strings
function getArrayStringPropertyDeserializer(tabbing, datatype, property) {
    var isOptional = property.optional;
    var optionalOption = "";

    if (isOptional === false)
        optionalOption = "HasSucceeded &= ";

    if (property.actualtype === "String")
        return tabbing + optionalOption + "obj->TryGetStringArrayField(TEXT(\"" + property.name + "\"), " + property.name + ");";
    throw "getArrayStringPropertyDeserializer: Unknown property type: " + property.actualtype + " for " + property.name + " in " + datatype.name;
}

function getArrayPropertyDeserializer(tabbing, api, datatype, property) {
    var getter = null; // represent the getter call function
    var temporary = ""; // represents a potential intermediate state used for some variables

    function setTemps(intGetter, intTemporary) {
        getter = intGetter;
        if (intTemporary)
            temporary = intTemporary;
    }

    if (property.actualtype === "String")
        return getArrayStringPropertyDeserializer(tabbing, datatype, property);
    else if (property.isenum && api.datatypes[property.actualtype].enumvalues.length > maxEnumSize)
        return getArrayStringPropertyDeserializer(tabbing, datatype, property);
    else if (property.actualtype === "Boolean")
        setTemps("CurrentItem->AsBool()");
    else if (property.actualtype === "int16")
        setTemps("TmpValue", "int32 TmpValue;\n" + tabbing + "CurrentItem->TryGetNumber(TmpValue);\n");
    else if (property.actualtype === "uint16")
        setTemps("TmpValue", "uint32 TmpValue;\n" + tabbing + "CurrentItem->TryGetNumber(TmpValue);\n");
    else if (property.actualtype === "int32")
        setTemps("TmpValue", "int32 TmpValue;\n" + tabbing + "CurrentItem->TryGetNumber(TmpValue);\n");
    else if (property.actualtype === "uint32")
        setTemps("TmpValue", "uint32 TmpValue;\n" + tabbing + "CurrentItem->TryGetNumber(TmpValue);\n");
    else if (property.actualtype === "int64")
        setTemps("TmpValue", "int64 TmpValue;\n" + tabbing + "CurrentItem->TryGetNumber(TmpValue);\n");
    else if (property.actualtype === "uint64")
        setTemps("TmpValue", "int64 TmpValue;\n" + tabbing + "CurrentItem->TryGetNumber(TmpValue);\n");
    else if (property.actualtype === "float")
        setTemps("(float)TmpValue", "double TmpValue;\n" + tabbing + "CurrentItem->TryGetNumber(TmpValue);\n");
    else if (property.actualtype === "double")
        setTemps("TmpValue", "double TmpValue;\n" + tabbing + "CurrentItem->TryGetNumber(TmpValue);\n");
    else if (property.actualtype === "DateTime")
        setTemps("readDatetime(CurrentItem)");
    else if (property.isclass)
        setTemps("F" + property.actualtype + "(CurrentItem->AsObject())");
    else if (property.isenum)
        setTemps("read" + property.actualtype + "FromValue(CurrentItem)");
    else if (property.actualtype === "object")
        setTemps("FJsonKeeper(CurrentItem)");
    else
        throw "getArrayPropertyDeserializer: Unknown property type: " + property.actualtype + " for " + property.name + " in " + datatype.name;

    var propertyArrayName = property.name + "Array";

    if (temporary)
        return tabbing + "const TArray<TSharedPtr<FJsonValue>>&" + propertyArrayName + " = FPlayFabJsonHelpers::ReadArray(obj, TEXT(\"" + property.name + "\"));\n"
            + tabbing + "for (int32 Idx = 0; Idx < " + propertyArrayName + ".Num(); Idx++)\n"
            + tabbing + "{\n"
            + tabbing + "    TSharedPtr<FJsonValue> CurrentItem = " + propertyArrayName + "[Idx];\n"
            + tabbing + "    " + temporary + "\n"
            + tabbing + "    " + property.name + ".Add(" + getter + ");\n"
            + tabbing + "}\n";
    // else if (!temporary)
    return tabbing + "const TArray<TSharedPtr<FJsonValue>>&" + propertyArrayName + " = FPlayFabJsonHelpers::ReadArray(obj, TEXT(\"" + property.name + "\"));\n"
        + tabbing + "for (int32 Idx = 0; Idx < " + propertyArrayName + ".Num(); Idx++)\n"
        + tabbing + "{\n"
        + tabbing + "    TSharedPtr<FJsonValue> CurrentItem = " + propertyArrayName + "[Idx];\n"
        + tabbing + "    " + property.name + ".Add(" + getter + ");\n"
        + tabbing + "}\n";
}

function getMapPropertyDeserializer(tabbing, api, datatype, property) {
    var getter = null;
    var temporary = "";

    function setTemps(get, temp) {
        getter = get;
        if (temp)
            temporary = temp;
    }

    if (property.actualtype === "String")
        setTemps("It.Value()->AsString()");
    else if (property.isenum && api.datatypes[property.actualtype].enumvalues.length > maxEnumSize)
        setTemps("It.Value()->AsString()");
    else if (property.actualtype === "Boolean")
        setTemps("It.Value()->AsBool()");
    else if (property.actualtype === "int16")
        setTemps("TmpValue", "int32 TmpValue; It.Value()->TryGetNumber(TmpValue);");
    else if (property.actualtype === "uint16")
        setTemps("TmpValue", "uint32 TmpValue; It.Value()->TryGetNumber(TmpValue);");
    else if (property.actualtype === "int32")
        setTemps("TmpValue", "int32 TmpValue; It.Value()->TryGetNumber(TmpValue);");
    else if (property.actualtype === "uint32")
        setTemps("TmpValue", "uint32 TmpValue; It.Value()->TryGetNumber(TmpValue);");
    else if (property.actualtype === "int64")
        setTemps("TmpValue", "int64 TmpValue; It.Value()->TryGetNumber(TmpValue);");
    else if (property.actualtype === "uint64")
        setTemps("TmpValue", "int64 TmpValue; It.Value()->TryGetNumber(TmpValue);");
    else if (property.actualtype === "float")
        setTemps("(float)TmpValue", "double TmpValue; It.Value()->TryGetNumber(TmpValue);");
    else if (property.actualtype === "double")
        setTemps("TmpValue", "double TmpValue; It.Value()->TryGetNumber(TmpValue);");
    else if (property.actualtype === "DateTime")
        setTemps("readDatetime(It.Value())");
    else if (property.isclass)
        setTemps("F" + property.actualtype + "(It.Value()->AsObject())");
    else if (property.isenum)
        setTemps("read" + property.actualtype + "FromValue(It.Value())");
    else if (property.actualtype === "object")
        setTemps("FJsonKeeper(It.Value())");
    else
        throw "getMapPropertyDeserializer: Unknown property type: " + property.actualtype + " for " + property.name + " in " + datatype.name;

    var propertyObjectName = property.name + "Object";

    if (temporary)
        return tabbing + "const TSharedPtr<FJsonObject>* " + propertyObjectName + ";\n"
            + tabbing + "if (obj->TryGetObjectField(TEXT(\"" + property.name + "\"), " + propertyObjectName + "))\n"
            + tabbing + "{\n"
            + tabbing + "    for (TMap<FString, TSharedPtr<FJsonValue>>::TConstIterator It((*" + propertyObjectName + ")->Values); It; ++It)\n"
            + tabbing + "    {\n"
            + tabbing + "        " + temporary + "\n"
            + tabbing + "        " + property.name + ".Add(It.Key(), " + getter + ");\n"
            + tabbing + "    }\n"
            + tabbing + "}";
    // else if (!temporary)
    return tabbing + "const TSharedPtr<FJsonObject>* " + propertyObjectName + ";\n"
        + tabbing + "if (obj->TryGetObjectField(TEXT(\"" + property.name + "\"), " + propertyObjectName + "))\n"
        + tabbing + "{\n"
        + tabbing + "    for (TMap<FString, TSharedPtr<FJsonValue>>::TConstIterator It((*" + propertyObjectName + ")->Values); It; ++It)\n"
        + tabbing + "    {\n"
        + tabbing + "        " + property.name + ".Add(It.Key(), " + getter + ");\n"
        + tabbing + "    }\n"
        + tabbing + "}";
}

function addTypeAndDependencies(datatype, datatypes, orderedTypes, addedSet) {
    if (datatype.isenum && datatype.enumvalues.length > maxEnumSize)
        return; // Enums are basically strings under the hood, and Unreal doesn't support that many enum values, so just fall back on Strings

    if (addedSet[datatype.name])
        return;

    if (datatype.properties) {
        for (var p = 0; p < datatype.properties.length; p++) {
            var property = datatype.properties[p];
            if (property.isclass || property.isenum)
                addTypeAndDependencies(datatypes[property.actualtype], datatypes, orderedTypes, addedSet);
        }
    }

    orderedTypes.push(datatype);
    addedSet[datatype.name] = datatype;
}

function getContextContainer(isInstanceApi, getOrCreate) {
    if (isInstanceApi) {
        return "GetOrCreateAuthenticationContext()->";
    } else {
        return "PlayFabSettings::";
    }
}

function getAuthParams(apiCall, isInstanceApi) {
    if (apiCall.url === "/Authentication/GetEntityToken")
        return "authKey, authValue";
    else if (isInstanceApi && apiCall.auth === "EntityToken")
        return "TEXT(\"X-EntityToken\"), context->GetEntityToken()";
    else if (!isInstanceApi && apiCall.auth === "EntityToken")
        return "TEXT(\"X-EntityToken\"), entityToken";
    else if (isInstanceApi && apiCall.auth === "SecretKey")
        return "TEXT(\"X-SecretKey\"), context->GetDeveloperSecretKey()";
    else if (!isInstanceApi && apiCall.auth === "SecretKey")
        return "TEXT(\"X-SecretKey\"), devSecretKey";
    else if (isInstanceApi && apiCall.auth === "SessionTicket")
        return "TEXT(\"X-Authorization\"), context->GetClientSessionTicket()";
    else if (!isInstanceApi && apiCall.auth === "SessionTicket")
        return "TEXT(\"X-Authorization\"), clientTicket";
    return "TEXT(\"\"), TEXT(\"\")";
}

function getBaseType(datatype) {
    if (datatype.isRequest === true)
        return "FPlayFabCppRequestCommon";
    if (datatype.isResult === true) {
        if (datatype.className.toLowerCase().endsWith("loginresult"))
            return "FPlayFabLoginResultCommon";
        return "FPlayFabCppResultCommon";
    }
    return "FPlayFabCppBaseModel";
}

function getRequestActions(tabbing, apiCall, isInstanceApi) {
    if (apiCall.result === "LoginResult" || apiCall.request === "RegisterPlayFabUserRequest") {
        return tabbing + "if (GetDefault<UPlayFabRuntimeSettings>()->TitleId.Len() > 0)\n"
            + tabbing + "    request.TitleId = GetDefault<UPlayFabRuntimeSettings>()->TitleId;\n";
    } else if (apiCall.url === "/Authentication/GetEntityToken") {
        return tabbing + "FString authKey; FString authValue;\n"
            + tabbing + "FString clientTicket = request.AuthenticationContext.IsValid() ? request.AuthenticationContext->GetClientSessionTicket() : PlayFabSettings::GetClientSessionTicket();\n"
            + tabbing + "FString devSecretKey = GetDefault<UPlayFabRuntimeSettings>()->DeveloperSecretKey;\n"
            + tabbing + "FString entityToken = request.AuthenticationContext.IsValid() ? request.AuthenticationContext->GetEntityToken() : PlayFabSettings::GetEntityToken();\n"
            + "\n"
            + tabbing + "if (entityToken.Len() > 0) {\n"
            + tabbing + "    authKey = TEXT(\"X-EntityToken\"); authValue = entityToken;\n"
            + tabbing + "} else if (clientTicket.Len() > 0) {\n"
            + tabbing + "    authKey = TEXT(\"X-Authorization\"); authValue = clientTicket;\n"
            + tabbing + "} else if (GetDefault<UPlayFabRuntimeSettings>()->DeveloperSecretKey.Len() > 0) {\n"
            + tabbing + "    authKey = TEXT(\"X-SecretKey\"); authValue = devSecretKey;\n"
            + tabbing + "}\n";
    } else if (isInstanceApi && apiCall.auth === "EntityToken") {
        return tabbing + "if (context->GetEntityToken().Len() == 0) {\n"
            + tabbing + "    UE_LOG(LogPlayFabCpp, Error, TEXT(\"You must call GetEntityToken API Method before calling this function.\"));\n"
            + tabbing + "}\n";
    } else if (!isInstanceApi && apiCall.auth === "EntityToken") {
        return tabbing + "FString entityToken = request.AuthenticationContext.IsValid() ? request.AuthenticationContext->GetEntityToken() : PlayFabSettings::GetEntityToken();\n"
            + tabbing + "if (entityToken.Len() == 0) {\n"
            + tabbing + "    UE_LOG(LogPlayFabCpp, Error, TEXT(\"You must call GetEntityToken API Method before calling this function.\"));\n"
            + tabbing + "}\n";
    } else if (isInstanceApi && apiCall.auth === "SecretKey") {
        return tabbing + "if(context->GetDeveloperSecretKey().Len() == 0) {\n"
            + tabbing + "    UE_LOG(LogPlayFabCpp, Error, TEXT(\"You must first set your PlayFab developerSecretKey to use this function (Unreal Settings Menu, or in C++ code)\"));\n"
            + tabbing + "}\n";
    } else if (!isInstanceApi && apiCall.auth === "SecretKey") {
        return tabbing + "FString devSecretKey = request.AuthenticationContext.IsValid() ? request.AuthenticationContext->GetDeveloperSecretKey() : GetDefault<UPlayFabRuntimeSettings>()->DeveloperSecretKey;\n"
            + tabbing + "if (devSecretKey.Len() == 0) {\n"
            + tabbing + "    UE_LOG(LogPlayFabCpp, Error, TEXT(\"You must first set your PlayFab developerSecretKey to use this function (Unreal Settings Menu, or in C++ code)\"));\n"
            + tabbing + "}\n";
    } else if (isInstanceApi && apiCall.auth === "SessionTicket") {
        return tabbing + "if (context->GetClientSessionTicket().Len() == 0) {\n"
            + tabbing + "    UE_LOG(LogPlayFabCpp, Error, TEXT(\"You must log in before calling this function\"));\n"
            + tabbing + "    return false;\n"
            + tabbing + "}\n";
    } else if (!isInstanceApi && apiCall.auth === "SessionTicket") {
        return tabbing + "FString clientTicket = request.AuthenticationContext.IsValid() ? request.AuthenticationContext->GetClientSessionTicket() : PlayFabSettings::GetClientSessionTicket();\n"
            + tabbing + "if(clientTicket.Len() == 0) {\n"
            + tabbing + "    UE_LOG(LogPlayFabCpp, Error, TEXT(\"You must log in before calling this function\"));\n"
            + tabbing + "    return false;\n"
            + tabbing + "}\n";
    }
    return "";
}

function getCustomApiLogic(tabbing, api, apiCall, isInstanceApi) {
    if (apiCall.url === "/CloudScript/ExecuteFunction")
        return tabbing + "FString localApiServer = PlayFabSettings::GetLocalApiServer();\n"
            + tabbing + "if (!localApiServer.IsEmpty())\n"
            + tabbing + "{\n"
            + tabbing + "    FString endpoint = TEXT(\"" + apiCall.url + "\");\n"
            + tabbing + "    endpoint.RemoveFromStart(TEXT(\"/\"));\n"
            + tabbing + "    auto HttpRequest = PlayFabRequestHandler::SendFullUrlRequest(localApiServer + endpoint, request.toJSONString(), " + getAuthParams(apiCall, isInstanceApi) + ");\n"
            + tabbing + "    HttpRequest->OnProcessRequestComplete().BindRaw(this, &UPlayFab" + api.name + (isInstanceApi ? "Instance" : "") + "API::On" + apiCall.name + "Result, SuccessDelegate, ErrorDelegate);\n"
            + tabbing + "    return HttpRequest->ProcessRequest();\n"
            + tabbing + "}\n"
}

function getResultActions(tabbing, apiCall, isInstanceApi) {
    if (apiCall.url === "/Authentication/GetEntityToken")
        return tabbing + "if (outResult.EntityToken.Len() > 0)\n"
            + tabbing + "    " + getContextContainer(isInstanceApi, true) + "SetEntityToken(outResult.EntityToken);\n";
    if (apiCall.url === "/GameServerIdentity/AuthenticateGameServerWithCustomId")
        return tabbing + "if (outResult.EntityToken != nullptr && outResult.EntityToken->EntityToken.Len() > 0)\n"
            + tabbing + "    " + getContextContainer(isInstanceApi, true) + "SetEntityToken(outResult.EntityToken->EntityToken);\n";
    else if (apiCall.result === "LoginResult") {
        return tabbing + "outResult.AuthenticationContext = MakeSharedUObject<UPlayFabAuthenticationContext>();\n"
            + tabbing + "if (outResult.SessionTicket.Len() > 0) {\n"
            + tabbing + "    " + getContextContainer(isInstanceApi, false) + "SetClientSessionTicket(outResult.SessionTicket);\n"
            + tabbing + "    outResult.AuthenticationContext->SetClientSessionTicket(outResult.SessionTicket);\n"
            + tabbing + "}\n"
            + tabbing + "if (outResult.EntityToken.IsValid()) {\n"
            + tabbing + "    " + getContextContainer(isInstanceApi, false) + "SetEntityToken(outResult.EntityToken->EntityToken);\n"
            + tabbing + "    outResult.AuthenticationContext->SetEntityToken(outResult.EntityToken->EntityToken);\n"
            + tabbing + "}\n"
            + tabbing + "if (outResult.PlayFabId.Len() > 0) {\n"
            + (isInstanceApi ? tabbing + "    this->authContext->SetPlayFabId(outResult.PlayFabId);\n" : "")
            + tabbing + "    outResult.AuthenticationContext->SetPlayFabId(outResult.PlayFabId);\n"
            + tabbing + "}\n"
            + tabbing + "\n\n";
    }
    else if (apiCall.result === "RegisterPlayFabUserResult")
        return tabbing + "if (outResult.SessionTicket.Len() > 0)\n"
            + tabbing + "    " + getContextContainer(isInstanceApi, true) + "SetClientSessionTicket(outResult.SessionTicket);\n"
            + tabbing + "\n\n";
    return "";
}
