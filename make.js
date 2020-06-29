var path = require("path");
var cppMakeJsPath = require("./template/makeCpp.js");
var bpMakeJsPath = require("./template/makebp.js");

// Making resharper less noisy - These are defined in Generate.js
if (typeof (generateApiSummaryLines) === "undefined") generateApiSummaryLines = function () { };
if (typeof (getCompiledTemplate) === "undefined") getCompiledTemplate = function () { };
if (typeof (templatizeTree) === "undefined") templatizeTree = function () { };

var copyright =
`//////////////////////////////////////////////////////
// Copyright (C) Microsoft. 2018. All rights reserved.
//////////////////////////////////////////////////////
`;

class TargetVersion {
    constructor(inMajor, inMinor, inPatch) {
        this.major = inMajor;
        this.minor = inMinor;
        this.patch = inPatch;
    }
    get targetVersionShort() {
        return `${this.major}.${this.minor}`;
    }

    get targetVersionLong() {
        return `${this.major}.${this.minor}.${this.patch}`;
    }
}

// The list of current supported UE versions - Intended to be the latest 3 supported by Epic
// Although we can target later updates to the versions,
// we should set the hotfix version to 0 so that any further updates will not need a prompt when opening with PlayFab
const ueTargetVersions = [
    new TargetVersion(4, 23, 0),
    new TargetVersion(4, 24, 0),
    new TargetVersion(4, 25, 0)
];
exports.ueTargetVersions = ueTargetVersions;

exports.makeCombinedAPI = function (apis, sourceDir, baseApiOutputDir) {

    var ueWhitelistPlatforms = '[ "Win64", "Win32", "Mac", "IOS", "Android", "PS4", "XboxOne", "Switch" ]';

    for (var v = 0; v < ueTargetVersions.length; v++) {
        var ueTargetVersion = ueTargetVersions[v];
        var apiOutputDir = path.resolve(baseApiOutputDir, ueTargetVersion.targetVersionShort); // Break multiple versions into separate top level folders

        console.log("\nGenerating Unreal Plugin from:\n  - " + sourceDir + "\nto:\n  - " + apiOutputDir);

        // Create the Source folder in the plugin with all the modules
        bpMakeJsPath.makeBpCombinedAPI(apis, copyright, sourceDir, apiOutputDir, ueTargetVersion.targetVersionShort, sdkGlobals.sdkVersion, sdkGlobals.buildIdentifier);
        cppMakeJsPath.makeCppCombinedAPI(apis, copyright, sourceDir, apiOutputDir, ueTargetVersion.targetVersionShort, sdkGlobals.sdkVersion, sdkGlobals.buildIdentifier);

        var authMechanisms = getAuthMechanisms(apis);
        var locals = {
            apis: apis,
            buildIdentifier: sdkGlobals.buildIdentifier,
            copyright: copyright,
            enumTypes: collectEnumsFromApis(apis),
            errorList: apis[0].errorList,
            errors: apis[0].errors,
            generateBpApiSummary: bpMakeJsPath.generateApiSummary,
            getDataTypeSafeName: bpMakeJsPath.getDataTypeSafeName,
            getDefaultVerticalName: getDefaultVerticalName,
            hasClientOptions: authMechanisms.includes("SessionTicket"),
            hasServerOptions: authMechanisms.includes("SecretKey"),
            sdkVersion: sdkGlobals.sdkVersion,
            ueTargetVersionMinor: ueTargetVersion.minor, // This is actually used
            ueTargetVersion: ueTargetVersion.targetVersionShort,
            ueTargetVersionLong: ueTargetVersion.targetVersionLong,
            ueWhitelistPlatforms: ueWhitelistPlatforms,
            addTest: false
        };

        // Copy the resources, content and the .uplugin file
        templatizeTree(locals, path.resolve(sourceDir, "template/source"), path.resolve(apiOutputDir, "PlayFabPlugin"));

        // Create the Example project folder
        templatizeTree(locals, path.resolve(sourceDir, "template/examplesource"), apiOutputDir);

        locals.addTest = true;

        // Copy the PlayFabPlugin folder just created into the ExampleProject
        // TODO: It causes very confusing problems to copy from an output subdir to another output subdir. Let's fix this
        templatizeTree(locals, path.resolve(apiOutputDir, "PlayFabPlugin"), path.resolve(apiOutputDir, "ExampleProject/Plugins"));
        templatizeTree(locals, path.resolve(sourceDir, "template/source"), path.resolve(apiOutputDir, "ExampleProject/Plugins"));
    }
}

// BP Module: Pull all the enums out of all the apis, and collect them into a single collection of just the enum types and filter duplicates
function collectEnumsFromApis(apis) {
    var enumTypes = {};
    for (var a = 0; a < apis.length; a++)
        for (var d in apis[a].datatypes)
            if (apis[a].datatypes[d].isenum && apis[a].datatypes[d].enumvalues.length <= 255)
                enumTypes[d] = apis[a].datatypes[d];
    return enumTypes;
}

function getDefaultVerticalName() {
    if (exports.verticalName) {
        return exports.verticalName;
    }
    return "";
}
