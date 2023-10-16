//////////////////////////////////////////////////////
// Copyright (C) Microsoft. 2018. All rights reserved.
//////////////////////////////////////////////////////


#pragma once

#include "UObject/Package.h"
#include "CoreMinimal.h"
#include <Runtime/Launch/Resources/Version.h>
#include "PlayFabJsonObject.h"
#include "PlayFabEnums.generated.h"

// PlayFab enums start with "pfenum_" in order to avoid code-name conflicts - For JSON, remove that prefix, and send only the expected portion (the display name is not fetchable when compiled)
  static const FString prefix = TEXT("pfenum_");

template <typename EnumType>
static FORCEINLINE bool GetEnumValueFromString(const FString& enumTypeName, const FString& input, EnumType& output)
{
#if ENGINE_MAJOR_VERSION == 5  && ENGINE_MINOR_VERSION >= 1
    UEnum* enumPtr = FindFirstObject<UEnum>(*enumTypeName, EFindFirstObjectOptions::ExactClass);
#else
    UEnum* enumPtr = FindObject<UEnum>(ANY_PACKAGE, *enumTypeName, true);
#endif
    if (!enumPtr)
    {
        output = EnumType(0);
        return false;
    }

    FString fullInput;
    if (!input.StartsWith(*prefix))
        fullInput = prefix + input;
    else
        fullInput = input;
#if ENGINE_MAJOR_VERSION == 4 && ENGINE_MINOR_VERSION < 16
    output = (EnumType)enumPtr->FindEnumIndex(FName(*fullInput));
#else
    output = (EnumType)enumPtr->GetIndexByName(FName(*fullInput));
#endif
    return true;
}

template<typename EnumType>
static FORCEINLINE bool GetEnumValueToString(const FString& enumTypeName, const EnumType& input, FString& output)
{
#if ENGINE_MAJOR_VERSION == 5 && ENGINE_MINOR_VERSION >= 1
    const UEnum* enumPtr = FindFirstObject<UEnum>(*enumTypeName, EFindFirstObjectOptions::ExactClass);
#else
    const UEnum* enumPtr = FindObject<UEnum>(ANY_PACKAGE, *enumTypeName, true);
#endif
    if (!enumPtr)
    {
        output = FString("0");
        return false;
    }

#if ENGINE_MAJOR_VERSION == 4 && ENGINE_MINOR_VERSION < 16
    output = enumPtr->GetEnumName((int32)input);
#else
    output = enumPtr->GetNameStringByIndex((int32)input);
#endif
    if (output.StartsWith(*prefix))
        output.RemoveAt(0, 7, false);
    return true;
}


/** AuthTokenType */

UENUM(BlueprintType)
enum class EAuthTokenType : uint8
{
    pfenum_Email = 0 UMETA(DisplayName = "Email"),
};

/** ChurnRiskLevel */

UENUM(BlueprintType)
enum class EChurnRiskLevel : uint8
{
    pfenum_NoData = 0 UMETA(DisplayName = "NoData"),
    pfenum_LowRisk = 1 UMETA(DisplayName = "LowRisk"),
    pfenum_MediumRisk = 2 UMETA(DisplayName = "MediumRisk"),
    pfenum_HighRisk = 3 UMETA(DisplayName = "HighRisk"),
};

/** Conditionals */

UENUM(BlueprintType)
enum class EConditionals : uint8
{
    pfenum_Any = 0 UMETA(DisplayName = "Any"),
    pfenum_True = 1 UMETA(DisplayName = "True"),
    pfenum_False = 2 UMETA(DisplayName = "False"),
};

/** ContinentCode */

UENUM(BlueprintType)
enum class EContinentCode : uint8
{
    pfenum_AF = 0 UMETA(DisplayName = "AF"),
    pfenum_AN = 1 UMETA(DisplayName = "AN"),
    pfenum_AS = 2 UMETA(DisplayName = "AS"),
    pfenum_EU = 3 UMETA(DisplayName = "EU"),
    pfenum_NA = 4 UMETA(DisplayName = "NA"),
    pfenum_OC = 5 UMETA(DisplayName = "OC"),
    pfenum_SA = 6 UMETA(DisplayName = "SA"),
    pfenum_Unknown = 7 UMETA(DisplayName = "Unknown"),
};

/** CountryCode */

UENUM(BlueprintType)
enum class ECountryCode : uint8
{
    pfenum_AF = 0 UMETA(DisplayName = "AF"),
    pfenum_AX = 1 UMETA(DisplayName = "AX"),
    pfenum_AL = 2 UMETA(DisplayName = "AL"),
    pfenum_DZ = 3 UMETA(DisplayName = "DZ"),
    pfenum_AS = 4 UMETA(DisplayName = "AS"),
    pfenum_AD = 5 UMETA(DisplayName = "AD"),
    pfenum_AO = 6 UMETA(DisplayName = "AO"),
    pfenum_AI = 7 UMETA(DisplayName = "AI"),
    pfenum_AQ = 8 UMETA(DisplayName = "AQ"),
    pfenum_AG = 9 UMETA(DisplayName = "AG"),
    pfenum_AR = 10 UMETA(DisplayName = "AR"),
    pfenum_AM = 11 UMETA(DisplayName = "AM"),
    pfenum_AW = 12 UMETA(DisplayName = "AW"),
    pfenum_AU = 13 UMETA(DisplayName = "AU"),
    pfenum_AT = 14 UMETA(DisplayName = "AT"),
    pfenum_AZ = 15 UMETA(DisplayName = "AZ"),
    pfenum_BS = 16 UMETA(DisplayName = "BS"),
    pfenum_BH = 17 UMETA(DisplayName = "BH"),
    pfenum_BD = 18 UMETA(DisplayName = "BD"),
    pfenum_BB = 19 UMETA(DisplayName = "BB"),
    pfenum_BY = 20 UMETA(DisplayName = "BY"),
    pfenum_BE = 21 UMETA(DisplayName = "BE"),
    pfenum_BZ = 22 UMETA(DisplayName = "BZ"),
    pfenum_BJ = 23 UMETA(DisplayName = "BJ"),
    pfenum_BM = 24 UMETA(DisplayName = "BM"),
    pfenum_BT = 25 UMETA(DisplayName = "BT"),
    pfenum_BO = 26 UMETA(DisplayName = "BO"),
    pfenum_BQ = 27 UMETA(DisplayName = "BQ"),
    pfenum_BA = 28 UMETA(DisplayName = "BA"),
    pfenum_BW = 29 UMETA(DisplayName = "BW"),
    pfenum_BV = 30 UMETA(DisplayName = "BV"),
    pfenum_BR = 31 UMETA(DisplayName = "BR"),
    pfenum_IO = 32 UMETA(DisplayName = "IO"),
    pfenum_BN = 33 UMETA(DisplayName = "BN"),
    pfenum_BG = 34 UMETA(DisplayName = "BG"),
    pfenum_BF = 35 UMETA(DisplayName = "BF"),
    pfenum_BI = 36 UMETA(DisplayName = "BI"),
    pfenum_KH = 37 UMETA(DisplayName = "KH"),
    pfenum_CM = 38 UMETA(DisplayName = "CM"),
    pfenum_CA = 39 UMETA(DisplayName = "CA"),
    pfenum_CV = 40 UMETA(DisplayName = "CV"),
    pfenum_KY = 41 UMETA(DisplayName = "KY"),
    pfenum_CF = 42 UMETA(DisplayName = "CF"),
    pfenum_TD = 43 UMETA(DisplayName = "TD"),
    pfenum_CL = 44 UMETA(DisplayName = "CL"),
    pfenum_CN = 45 UMETA(DisplayName = "CN"),
    pfenum_CX = 46 UMETA(DisplayName = "CX"),
    pfenum_CC = 47 UMETA(DisplayName = "CC"),
    pfenum_CO = 48 UMETA(DisplayName = "CO"),
    pfenum_KM = 49 UMETA(DisplayName = "KM"),
    pfenum_CG = 50 UMETA(DisplayName = "CG"),
    pfenum_CD = 51 UMETA(DisplayName = "CD"),
    pfenum_CK = 52 UMETA(DisplayName = "CK"),
    pfenum_CR = 53 UMETA(DisplayName = "CR"),
    pfenum_CI = 54 UMETA(DisplayName = "CI"),
    pfenum_HR = 55 UMETA(DisplayName = "HR"),
    pfenum_CU = 56 UMETA(DisplayName = "CU"),
    pfenum_CW = 57 UMETA(DisplayName = "CW"),
    pfenum_CY = 58 UMETA(DisplayName = "CY"),
    pfenum_CZ = 59 UMETA(DisplayName = "CZ"),
    pfenum_DK = 60 UMETA(DisplayName = "DK"),
    pfenum_DJ = 61 UMETA(DisplayName = "DJ"),
    pfenum_DM = 62 UMETA(DisplayName = "DM"),
    pfenum_DO = 63 UMETA(DisplayName = "DO"),
    pfenum_EC = 64 UMETA(DisplayName = "EC"),
    pfenum_EG = 65 UMETA(DisplayName = "EG"),
    pfenum_SV = 66 UMETA(DisplayName = "SV"),
    pfenum_GQ = 67 UMETA(DisplayName = "GQ"),
    pfenum_ER = 68 UMETA(DisplayName = "ER"),
    pfenum_EE = 69 UMETA(DisplayName = "EE"),
    pfenum_ET = 70 UMETA(DisplayName = "ET"),
    pfenum_FK = 71 UMETA(DisplayName = "FK"),
    pfenum_FO = 72 UMETA(DisplayName = "FO"),
    pfenum_FJ = 73 UMETA(DisplayName = "FJ"),
    pfenum_FI = 74 UMETA(DisplayName = "FI"),
    pfenum_FR = 75 UMETA(DisplayName = "FR"),
    pfenum_GF = 76 UMETA(DisplayName = "GF"),
    pfenum_PF = 77 UMETA(DisplayName = "PF"),
    pfenum_TF = 78 UMETA(DisplayName = "TF"),
    pfenum_GA = 79 UMETA(DisplayName = "GA"),
    pfenum_GM = 80 UMETA(DisplayName = "GM"),
    pfenum_GE = 81 UMETA(DisplayName = "GE"),
    pfenum_DE = 82 UMETA(DisplayName = "DE"),
    pfenum_GH = 83 UMETA(DisplayName = "GH"),
    pfenum_GI = 84 UMETA(DisplayName = "GI"),
    pfenum_GR = 85 UMETA(DisplayName = "GR"),
    pfenum_GL = 86 UMETA(DisplayName = "GL"),
    pfenum_GD = 87 UMETA(DisplayName = "GD"),
    pfenum_GP = 88 UMETA(DisplayName = "GP"),
    pfenum_GU = 89 UMETA(DisplayName = "GU"),
    pfenum_GT = 90 UMETA(DisplayName = "GT"),
    pfenum_GG = 91 UMETA(DisplayName = "GG"),
    pfenum_GN = 92 UMETA(DisplayName = "GN"),
    pfenum_GW = 93 UMETA(DisplayName = "GW"),
    pfenum_GY = 94 UMETA(DisplayName = "GY"),
    pfenum_HT = 95 UMETA(DisplayName = "HT"),
    pfenum_HM = 96 UMETA(DisplayName = "HM"),
    pfenum_VA = 97 UMETA(DisplayName = "VA"),
    pfenum_HN = 98 UMETA(DisplayName = "HN"),
    pfenum_HK = 99 UMETA(DisplayName = "HK"),
    pfenum_HU = 100 UMETA(DisplayName = "HU"),
    pfenum_IS = 101 UMETA(DisplayName = "IS"),
    pfenum_IN = 102 UMETA(DisplayName = "IN"),
    pfenum_ID = 103 UMETA(DisplayName = "ID"),
    pfenum_IR = 104 UMETA(DisplayName = "IR"),
    pfenum_IQ = 105 UMETA(DisplayName = "IQ"),
    pfenum_IE = 106 UMETA(DisplayName = "IE"),
    pfenum_IM = 107 UMETA(DisplayName = "IM"),
    pfenum_IL = 108 UMETA(DisplayName = "IL"),
    pfenum_IT = 109 UMETA(DisplayName = "IT"),
    pfenum_JM = 110 UMETA(DisplayName = "JM"),
    pfenum_JP = 111 UMETA(DisplayName = "JP"),
    pfenum_JE = 112 UMETA(DisplayName = "JE"),
    pfenum_JO = 113 UMETA(DisplayName = "JO"),
    pfenum_KZ = 114 UMETA(DisplayName = "KZ"),
    pfenum_KE = 115 UMETA(DisplayName = "KE"),
    pfenum_KI = 116 UMETA(DisplayName = "KI"),
    pfenum_KP = 117 UMETA(DisplayName = "KP"),
    pfenum_KR = 118 UMETA(DisplayName = "KR"),
    pfenum_KW = 119 UMETA(DisplayName = "KW"),
    pfenum_KG = 120 UMETA(DisplayName = "KG"),
    pfenum_LA = 121 UMETA(DisplayName = "LA"),
    pfenum_LV = 122 UMETA(DisplayName = "LV"),
    pfenum_LB = 123 UMETA(DisplayName = "LB"),
    pfenum_LS = 124 UMETA(DisplayName = "LS"),
    pfenum_LR = 125 UMETA(DisplayName = "LR"),
    pfenum_LY = 126 UMETA(DisplayName = "LY"),
    pfenum_LI = 127 UMETA(DisplayName = "LI"),
    pfenum_LT = 128 UMETA(DisplayName = "LT"),
    pfenum_LU = 129 UMETA(DisplayName = "LU"),
    pfenum_MO = 130 UMETA(DisplayName = "MO"),
    pfenum_MK = 131 UMETA(DisplayName = "MK"),
    pfenum_MG = 132 UMETA(DisplayName = "MG"),
    pfenum_MW = 133 UMETA(DisplayName = "MW"),
    pfenum_MY = 134 UMETA(DisplayName = "MY"),
    pfenum_MV = 135 UMETA(DisplayName = "MV"),
    pfenum_ML = 136 UMETA(DisplayName = "ML"),
    pfenum_MT = 137 UMETA(DisplayName = "MT"),
    pfenum_MH = 138 UMETA(DisplayName = "MH"),
    pfenum_MQ = 139 UMETA(DisplayName = "MQ"),
    pfenum_MR = 140 UMETA(DisplayName = "MR"),
    pfenum_MU = 141 UMETA(DisplayName = "MU"),
    pfenum_YT = 142 UMETA(DisplayName = "YT"),
    pfenum_MX = 143 UMETA(DisplayName = "MX"),
    pfenum_FM = 144 UMETA(DisplayName = "FM"),
    pfenum_MD = 145 UMETA(DisplayName = "MD"),
    pfenum_MC = 146 UMETA(DisplayName = "MC"),
    pfenum_MN = 147 UMETA(DisplayName = "MN"),
    pfenum_ME = 148 UMETA(DisplayName = "ME"),
    pfenum_MS = 149 UMETA(DisplayName = "MS"),
    pfenum_MA = 150 UMETA(DisplayName = "MA"),
    pfenum_MZ = 151 UMETA(DisplayName = "MZ"),
    pfenum_MM = 152 UMETA(DisplayName = "MM"),
    pfenum_NA = 153 UMETA(DisplayName = "NA"),
    pfenum_NR = 154 UMETA(DisplayName = "NR"),
    pfenum_NP = 155 UMETA(DisplayName = "NP"),
    pfenum_NL = 156 UMETA(DisplayName = "NL"),
    pfenum_NC = 157 UMETA(DisplayName = "NC"),
    pfenum_NZ = 158 UMETA(DisplayName = "NZ"),
    pfenum_NI = 159 UMETA(DisplayName = "NI"),
    pfenum_NE = 160 UMETA(DisplayName = "NE"),
    pfenum_NG = 161 UMETA(DisplayName = "NG"),
    pfenum_NU = 162 UMETA(DisplayName = "NU"),
    pfenum_NF = 163 UMETA(DisplayName = "NF"),
    pfenum_MP = 164 UMETA(DisplayName = "MP"),
    pfenum_NO = 165 UMETA(DisplayName = "NO"),
    pfenum_OM = 166 UMETA(DisplayName = "OM"),
    pfenum_PK = 167 UMETA(DisplayName = "PK"),
    pfenum_PW = 168 UMETA(DisplayName = "PW"),
    pfenum_PS = 169 UMETA(DisplayName = "PS"),
    pfenum_PA = 170 UMETA(DisplayName = "PA"),
    pfenum_PG = 171 UMETA(DisplayName = "PG"),
    pfenum_PY = 172 UMETA(DisplayName = "PY"),
    pfenum_PE = 173 UMETA(DisplayName = "PE"),
    pfenum_PH = 174 UMETA(DisplayName = "PH"),
    pfenum_PN = 175 UMETA(DisplayName = "PN"),
    pfenum_PL = 176 UMETA(DisplayName = "PL"),
    pfenum_PT = 177 UMETA(DisplayName = "PT"),
    pfenum_PR = 178 UMETA(DisplayName = "PR"),
    pfenum_QA = 179 UMETA(DisplayName = "QA"),
    pfenum_RE = 180 UMETA(DisplayName = "RE"),
    pfenum_RO = 181 UMETA(DisplayName = "RO"),
    pfenum_RU = 182 UMETA(DisplayName = "RU"),
    pfenum_RW = 183 UMETA(DisplayName = "RW"),
    pfenum_BL = 184 UMETA(DisplayName = "BL"),
    pfenum_SH = 185 UMETA(DisplayName = "SH"),
    pfenum_KN = 186 UMETA(DisplayName = "KN"),
    pfenum_LC = 187 UMETA(DisplayName = "LC"),
    pfenum_MF = 188 UMETA(DisplayName = "MF"),
    pfenum_PM = 189 UMETA(DisplayName = "PM"),
    pfenum_VC = 190 UMETA(DisplayName = "VC"),
    pfenum_WS = 191 UMETA(DisplayName = "WS"),
    pfenum_SM = 192 UMETA(DisplayName = "SM"),
    pfenum_ST = 193 UMETA(DisplayName = "ST"),
    pfenum_SA = 194 UMETA(DisplayName = "SA"),
    pfenum_SN = 195 UMETA(DisplayName = "SN"),
    pfenum_RS = 196 UMETA(DisplayName = "RS"),
    pfenum_SC = 197 UMETA(DisplayName = "SC"),
    pfenum_SL = 198 UMETA(DisplayName = "SL"),
    pfenum_SG = 199 UMETA(DisplayName = "SG"),
    pfenum_SX = 200 UMETA(DisplayName = "SX"),
    pfenum_SK = 201 UMETA(DisplayName = "SK"),
    pfenum_SI = 202 UMETA(DisplayName = "SI"),
    pfenum_SB = 203 UMETA(DisplayName = "SB"),
    pfenum_SO = 204 UMETA(DisplayName = "SO"),
    pfenum_ZA = 205 UMETA(DisplayName = "ZA"),
    pfenum_GS = 206 UMETA(DisplayName = "GS"),
    pfenum_SS = 207 UMETA(DisplayName = "SS"),
    pfenum_ES = 208 UMETA(DisplayName = "ES"),
    pfenum_LK = 209 UMETA(DisplayName = "LK"),
    pfenum_SD = 210 UMETA(DisplayName = "SD"),
    pfenum_SR = 211 UMETA(DisplayName = "SR"),
    pfenum_SJ = 212 UMETA(DisplayName = "SJ"),
    pfenum_SZ = 213 UMETA(DisplayName = "SZ"),
    pfenum_SE = 214 UMETA(DisplayName = "SE"),
    pfenum_CH = 215 UMETA(DisplayName = "CH"),
    pfenum_SY = 216 UMETA(DisplayName = "SY"),
    pfenum_TW = 217 UMETA(DisplayName = "TW"),
    pfenum_TJ = 218 UMETA(DisplayName = "TJ"),
    pfenum_TZ = 219 UMETA(DisplayName = "TZ"),
    pfenum_TH = 220 UMETA(DisplayName = "TH"),
    pfenum_TL = 221 UMETA(DisplayName = "TL"),
    pfenum_TG = 222 UMETA(DisplayName = "TG"),
    pfenum_TK = 223 UMETA(DisplayName = "TK"),
    pfenum_TO = 224 UMETA(DisplayName = "TO"),
    pfenum_TT = 225 UMETA(DisplayName = "TT"),
    pfenum_TN = 226 UMETA(DisplayName = "TN"),
    pfenum_TR = 227 UMETA(DisplayName = "TR"),
    pfenum_TM = 228 UMETA(DisplayName = "TM"),
    pfenum_TC = 229 UMETA(DisplayName = "TC"),
    pfenum_TV = 230 UMETA(DisplayName = "TV"),
    pfenum_UG = 231 UMETA(DisplayName = "UG"),
    pfenum_UA = 232 UMETA(DisplayName = "UA"),
    pfenum_AE = 233 UMETA(DisplayName = "AE"),
    pfenum_GB = 234 UMETA(DisplayName = "GB"),
    pfenum_US = 235 UMETA(DisplayName = "US"),
    pfenum_UM = 236 UMETA(DisplayName = "UM"),
    pfenum_UY = 237 UMETA(DisplayName = "UY"),
    pfenum_UZ = 238 UMETA(DisplayName = "UZ"),
    pfenum_VU = 239 UMETA(DisplayName = "VU"),
    pfenum_VE = 240 UMETA(DisplayName = "VE"),
    pfenum_VN = 241 UMETA(DisplayName = "VN"),
    pfenum_VG = 242 UMETA(DisplayName = "VG"),
    pfenum_VI = 243 UMETA(DisplayName = "VI"),
    pfenum_WF = 244 UMETA(DisplayName = "WF"),
    pfenum_EH = 245 UMETA(DisplayName = "EH"),
    pfenum_YE = 246 UMETA(DisplayName = "YE"),
    pfenum_ZM = 247 UMETA(DisplayName = "ZM"),
    pfenum_ZW = 248 UMETA(DisplayName = "ZW"),
    pfenum_Unknown = 249 UMETA(DisplayName = "Unknown"),
};

/** Currency */

UENUM(BlueprintType)
enum class ECurrency : uint8
{
    pfenum_AED = 0 UMETA(DisplayName = "AED"),
    pfenum_AFN = 1 UMETA(DisplayName = "AFN"),
    pfenum_ALL = 2 UMETA(DisplayName = "ALL"),
    pfenum_AMD = 3 UMETA(DisplayName = "AMD"),
    pfenum_ANG = 4 UMETA(DisplayName = "ANG"),
    pfenum_AOA = 5 UMETA(DisplayName = "AOA"),
    pfenum_ARS = 6 UMETA(DisplayName = "ARS"),
    pfenum_AUD = 7 UMETA(DisplayName = "AUD"),
    pfenum_AWG = 8 UMETA(DisplayName = "AWG"),
    pfenum_AZN = 9 UMETA(DisplayName = "AZN"),
    pfenum_BAM = 10 UMETA(DisplayName = "BAM"),
    pfenum_BBD = 11 UMETA(DisplayName = "BBD"),
    pfenum_BDT = 12 UMETA(DisplayName = "BDT"),
    pfenum_BGN = 13 UMETA(DisplayName = "BGN"),
    pfenum_BHD = 14 UMETA(DisplayName = "BHD"),
    pfenum_BIF = 15 UMETA(DisplayName = "BIF"),
    pfenum_BMD = 16 UMETA(DisplayName = "BMD"),
    pfenum_BND = 17 UMETA(DisplayName = "BND"),
    pfenum_BOB = 18 UMETA(DisplayName = "BOB"),
    pfenum_BRL = 19 UMETA(DisplayName = "BRL"),
    pfenum_BSD = 20 UMETA(DisplayName = "BSD"),
    pfenum_BTN = 21 UMETA(DisplayName = "BTN"),
    pfenum_BWP = 22 UMETA(DisplayName = "BWP"),
    pfenum_BYR = 23 UMETA(DisplayName = "BYR"),
    pfenum_BZD = 24 UMETA(DisplayName = "BZD"),
    pfenum_CAD = 25 UMETA(DisplayName = "CAD"),
    pfenum_CDF = 26 UMETA(DisplayName = "CDF"),
    pfenum_CHF = 27 UMETA(DisplayName = "CHF"),
    pfenum_CLP = 28 UMETA(DisplayName = "CLP"),
    pfenum_CNY = 29 UMETA(DisplayName = "CNY"),
    pfenum_COP = 30 UMETA(DisplayName = "COP"),
    pfenum_CRC = 31 UMETA(DisplayName = "CRC"),
    pfenum_CUC = 32 UMETA(DisplayName = "CUC"),
    pfenum_CUP = 33 UMETA(DisplayName = "CUP"),
    pfenum_CVE = 34 UMETA(DisplayName = "CVE"),
    pfenum_CZK = 35 UMETA(DisplayName = "CZK"),
    pfenum_DJF = 36 UMETA(DisplayName = "DJF"),
    pfenum_DKK = 37 UMETA(DisplayName = "DKK"),
    pfenum_DOP = 38 UMETA(DisplayName = "DOP"),
    pfenum_DZD = 39 UMETA(DisplayName = "DZD"),
    pfenum_EGP = 40 UMETA(DisplayName = "EGP"),
    pfenum_ERN = 41 UMETA(DisplayName = "ERN"),
    pfenum_ETB = 42 UMETA(DisplayName = "ETB"),
    pfenum_EUR = 43 UMETA(DisplayName = "EUR"),
    pfenum_FJD = 44 UMETA(DisplayName = "FJD"),
    pfenum_FKP = 45 UMETA(DisplayName = "FKP"),
    pfenum_GBP = 46 UMETA(DisplayName = "GBP"),
    pfenum_GEL = 47 UMETA(DisplayName = "GEL"),
    pfenum_GGP = 48 UMETA(DisplayName = "GGP"),
    pfenum_GHS = 49 UMETA(DisplayName = "GHS"),
    pfenum_GIP = 50 UMETA(DisplayName = "GIP"),
    pfenum_GMD = 51 UMETA(DisplayName = "GMD"),
    pfenum_GNF = 52 UMETA(DisplayName = "GNF"),
    pfenum_GTQ = 53 UMETA(DisplayName = "GTQ"),
    pfenum_GYD = 54 UMETA(DisplayName = "GYD"),
    pfenum_HKD = 55 UMETA(DisplayName = "HKD"),
    pfenum_HNL = 56 UMETA(DisplayName = "HNL"),
    pfenum_HRK = 57 UMETA(DisplayName = "HRK"),
    pfenum_HTG = 58 UMETA(DisplayName = "HTG"),
    pfenum_HUF = 59 UMETA(DisplayName = "HUF"),
    pfenum_IDR = 60 UMETA(DisplayName = "IDR"),
    pfenum_ILS = 61 UMETA(DisplayName = "ILS"),
    pfenum_IMP = 62 UMETA(DisplayName = "IMP"),
    pfenum_INR = 63 UMETA(DisplayName = "INR"),
    pfenum_IQD = 64 UMETA(DisplayName = "IQD"),
    pfenum_IRR = 65 UMETA(DisplayName = "IRR"),
    pfenum_ISK = 66 UMETA(DisplayName = "ISK"),
    pfenum_JEP = 67 UMETA(DisplayName = "JEP"),
    pfenum_JMD = 68 UMETA(DisplayName = "JMD"),
    pfenum_JOD = 69 UMETA(DisplayName = "JOD"),
    pfenum_JPY = 70 UMETA(DisplayName = "JPY"),
    pfenum_KES = 71 UMETA(DisplayName = "KES"),
    pfenum_KGS = 72 UMETA(DisplayName = "KGS"),
    pfenum_KHR = 73 UMETA(DisplayName = "KHR"),
    pfenum_KMF = 74 UMETA(DisplayName = "KMF"),
    pfenum_KPW = 75 UMETA(DisplayName = "KPW"),
    pfenum_KRW = 76 UMETA(DisplayName = "KRW"),
    pfenum_KWD = 77 UMETA(DisplayName = "KWD"),
    pfenum_KYD = 78 UMETA(DisplayName = "KYD"),
    pfenum_KZT = 79 UMETA(DisplayName = "KZT"),
    pfenum_LAK = 80 UMETA(DisplayName = "LAK"),
    pfenum_LBP = 81 UMETA(DisplayName = "LBP"),
    pfenum_LKR = 82 UMETA(DisplayName = "LKR"),
    pfenum_LRD = 83 UMETA(DisplayName = "LRD"),
    pfenum_LSL = 84 UMETA(DisplayName = "LSL"),
    pfenum_LYD = 85 UMETA(DisplayName = "LYD"),
    pfenum_MAD = 86 UMETA(DisplayName = "MAD"),
    pfenum_MDL = 87 UMETA(DisplayName = "MDL"),
    pfenum_MGA = 88 UMETA(DisplayName = "MGA"),
    pfenum_MKD = 89 UMETA(DisplayName = "MKD"),
    pfenum_MMK = 90 UMETA(DisplayName = "MMK"),
    pfenum_MNT = 91 UMETA(DisplayName = "MNT"),
    pfenum_MOP = 92 UMETA(DisplayName = "MOP"),
    pfenum_MRO = 93 UMETA(DisplayName = "MRO"),
    pfenum_MUR = 94 UMETA(DisplayName = "MUR"),
    pfenum_MVR = 95 UMETA(DisplayName = "MVR"),
    pfenum_MWK = 96 UMETA(DisplayName = "MWK"),
    pfenum_MXN = 97 UMETA(DisplayName = "MXN"),
    pfenum_MYR = 98 UMETA(DisplayName = "MYR"),
    pfenum_MZN = 99 UMETA(DisplayName = "MZN"),
    pfenum_NAD = 100 UMETA(DisplayName = "NAD"),
    pfenum_NGN = 101 UMETA(DisplayName = "NGN"),
    pfenum_NIO = 102 UMETA(DisplayName = "NIO"),
    pfenum_NOK = 103 UMETA(DisplayName = "NOK"),
    pfenum_NPR = 104 UMETA(DisplayName = "NPR"),
    pfenum_NZD = 105 UMETA(DisplayName = "NZD"),
    pfenum_OMR = 106 UMETA(DisplayName = "OMR"),
    pfenum_PAB = 107 UMETA(DisplayName = "PAB"),
    pfenum_PEN = 108 UMETA(DisplayName = "PEN"),
    pfenum_PGK = 109 UMETA(DisplayName = "PGK"),
    pfenum_PHP = 110 UMETA(DisplayName = "PHP"),
    pfenum_PKR = 111 UMETA(DisplayName = "PKR"),
    pfenum_PLN = 112 UMETA(DisplayName = "PLN"),
    pfenum_PYG = 113 UMETA(DisplayName = "PYG"),
    pfenum_QAR = 114 UMETA(DisplayName = "QAR"),
    pfenum_RON = 115 UMETA(DisplayName = "RON"),
    pfenum_RSD = 116 UMETA(DisplayName = "RSD"),
    pfenum_RUB = 117 UMETA(DisplayName = "RUB"),
    pfenum_RWF = 118 UMETA(DisplayName = "RWF"),
    pfenum_SAR = 119 UMETA(DisplayName = "SAR"),
    pfenum_SBD = 120 UMETA(DisplayName = "SBD"),
    pfenum_SCR = 121 UMETA(DisplayName = "SCR"),
    pfenum_SDG = 122 UMETA(DisplayName = "SDG"),
    pfenum_SEK = 123 UMETA(DisplayName = "SEK"),
    pfenum_SGD = 124 UMETA(DisplayName = "SGD"),
    pfenum_SHP = 125 UMETA(DisplayName = "SHP"),
    pfenum_SLL = 126 UMETA(DisplayName = "SLL"),
    pfenum_SOS = 127 UMETA(DisplayName = "SOS"),
    pfenum_SPL = 128 UMETA(DisplayName = "SPL"),
    pfenum_SRD = 129 UMETA(DisplayName = "SRD"),
    pfenum_STD = 130 UMETA(DisplayName = "STD"),
    pfenum_SVC = 131 UMETA(DisplayName = "SVC"),
    pfenum_SYP = 132 UMETA(DisplayName = "SYP"),
    pfenum_SZL = 133 UMETA(DisplayName = "SZL"),
    pfenum_THB = 134 UMETA(DisplayName = "THB"),
    pfenum_TJS = 135 UMETA(DisplayName = "TJS"),
    pfenum_TMT = 136 UMETA(DisplayName = "TMT"),
    pfenum_TND = 137 UMETA(DisplayName = "TND"),
    pfenum_TOP = 138 UMETA(DisplayName = "TOP"),
    pfenum_TRY = 139 UMETA(DisplayName = "TRY"),
    pfenum_TTD = 140 UMETA(DisplayName = "TTD"),
    pfenum_TVD = 141 UMETA(DisplayName = "TVD"),
    pfenum_TWD = 142 UMETA(DisplayName = "TWD"),
    pfenum_TZS = 143 UMETA(DisplayName = "TZS"),
    pfenum_UAH = 144 UMETA(DisplayName = "UAH"),
    pfenum_UGX = 145 UMETA(DisplayName = "UGX"),
    pfenum_USD = 146 UMETA(DisplayName = "USD"),
    pfenum_UYU = 147 UMETA(DisplayName = "UYU"),
    pfenum_UZS = 148 UMETA(DisplayName = "UZS"),
    pfenum_VEF = 149 UMETA(DisplayName = "VEF"),
    pfenum_VND = 150 UMETA(DisplayName = "VND"),
    pfenum_VUV = 151 UMETA(DisplayName = "VUV"),
    pfenum_WST = 152 UMETA(DisplayName = "WST"),
    pfenum_XAF = 153 UMETA(DisplayName = "XAF"),
    pfenum_XCD = 154 UMETA(DisplayName = "XCD"),
    pfenum_XDR = 155 UMETA(DisplayName = "XDR"),
    pfenum_XOF = 156 UMETA(DisplayName = "XOF"),
    pfenum_XPF = 157 UMETA(DisplayName = "XPF"),
    pfenum_YER = 158 UMETA(DisplayName = "YER"),
    pfenum_ZAR = 159 UMETA(DisplayName = "ZAR"),
    pfenum_ZMW = 160 UMETA(DisplayName = "ZMW"),
    pfenum_ZWD = 161 UMETA(DisplayName = "ZWD"),
};

/** EffectType */

UENUM(BlueprintType)
enum class EEffectType : uint8
{
    pfenum_Allow = 0 UMETA(DisplayName = "Allow"),
    pfenum_Deny = 1 UMETA(DisplayName = "Deny"),
};

/** EmailVerificationStatus */

UENUM(BlueprintType)
enum class EEmailVerificationStatus : uint8
{
    pfenum_Unverified = 0 UMETA(DisplayName = "Unverified"),
    pfenum_Pending = 1 UMETA(DisplayName = "Pending"),
    pfenum_Confirmed = 2 UMETA(DisplayName = "Confirmed"),
};

/** LoginIdentityProvider */

UENUM(BlueprintType)
enum class ELoginIdentityProvider : uint8
{
    pfenum_Unknown = 0 UMETA(DisplayName = "Unknown"),
    pfenum_PlayFab = 1 UMETA(DisplayName = "PlayFab"),
    pfenum_Custom = 2 UMETA(DisplayName = "Custom"),
    pfenum_GameCenter = 3 UMETA(DisplayName = "GameCenter"),
    pfenum_GooglePlay = 4 UMETA(DisplayName = "GooglePlay"),
    pfenum_Steam = 5 UMETA(DisplayName = "Steam"),
    pfenum_XBoxLive = 6 UMETA(DisplayName = "XBoxLive"),
    pfenum_PSN = 7 UMETA(DisplayName = "PSN"),
    pfenum_Kongregate = 8 UMETA(DisplayName = "Kongregate"),
    pfenum_Facebook = 9 UMETA(DisplayName = "Facebook"),
    pfenum_IOSDevice = 10 UMETA(DisplayName = "IOSDevice"),
    pfenum_AndroidDevice = 11 UMETA(DisplayName = "AndroidDevice"),
    pfenum_Twitch = 12 UMETA(DisplayName = "Twitch"),
    pfenum_WindowsHello = 13 UMETA(DisplayName = "WindowsHello"),
    pfenum_GameServer = 14 UMETA(DisplayName = "GameServer"),
    pfenum_CustomServer = 15 UMETA(DisplayName = "CustomServer"),
    pfenum_NintendoSwitch = 16 UMETA(DisplayName = "NintendoSwitch"),
    pfenum_FacebookInstantGames = 17 UMETA(DisplayName = "FacebookInstantGames"),
    pfenum_OpenIdConnect = 18 UMETA(DisplayName = "OpenIdConnect"),
    pfenum_Apple = 19 UMETA(DisplayName = "Apple"),
    pfenum_NintendoSwitchAccount = 20 UMETA(DisplayName = "NintendoSwitchAccount"),
    pfenum_GooglePlayGames = 21 UMETA(DisplayName = "GooglePlayGames"),
};

/** PushNotificationPlatform */

UENUM(BlueprintType)
enum class EPushNotificationPlatform : uint8
{
    pfenum_ApplePushNotificationService = 0 UMETA(DisplayName = "ApplePushNotificationService"),
    pfenum_GoogleCloudMessaging = 1 UMETA(DisplayName = "GoogleCloudMessaging"),
};

/** PushSetupPlatform */

UENUM(BlueprintType)
enum class EPushSetupPlatform : uint8
{
    pfenum_GCM = 0 UMETA(DisplayName = "GCM"),
    pfenum_APNS = 1 UMETA(DisplayName = "APNS"),
    pfenum_APNS_SANDBOX = 2 UMETA(DisplayName = "APNS_SANDBOX"),
};

/** ResolutionOutcome */

UENUM(BlueprintType)
enum class EResolutionOutcome : uint8
{
    pfenum_Revoke = 0 UMETA(DisplayName = "Revoke"),
    pfenum_Reinstate = 1 UMETA(DisplayName = "Reinstate"),
    pfenum_Manual = 2 UMETA(DisplayName = "Manual"),
};

/** ResultTableNodeType */

UENUM(BlueprintType)
enum class EResultTableNodeType : uint8
{
    pfenum_ItemId = 0 UMETA(DisplayName = "ItemId"),
    pfenum_TableId = 1 UMETA(DisplayName = "TableId"),
};

/** ScheduledTaskType */

UENUM(BlueprintType)
enum class EScheduledTaskType : uint8
{
    pfenum_CloudScript = 0 UMETA(DisplayName = "CloudScript"),
    pfenum_ActionsOnPlayerSegment = 1 UMETA(DisplayName = "ActionsOnPlayerSegment"),
    pfenum_CloudScriptAzureFunctions = 2 UMETA(DisplayName = "CloudScriptAzureFunctions"),
    pfenum_InsightsScheduledScaling = 3 UMETA(DisplayName = "InsightsScheduledScaling"),
};

/** SegmentCountryCode */

UENUM(BlueprintType)
enum class ESegmentCountryCode : uint8
{
    pfenum_AF = 0 UMETA(DisplayName = "AF"),
    pfenum_AX = 1 UMETA(DisplayName = "AX"),
    pfenum_AL = 2 UMETA(DisplayName = "AL"),
    pfenum_DZ = 3 UMETA(DisplayName = "DZ"),
    pfenum_AS = 4 UMETA(DisplayName = "AS"),
    pfenum_AD = 5 UMETA(DisplayName = "AD"),
    pfenum_AO = 6 UMETA(DisplayName = "AO"),
    pfenum_AI = 7 UMETA(DisplayName = "AI"),
    pfenum_AQ = 8 UMETA(DisplayName = "AQ"),
    pfenum_AG = 9 UMETA(DisplayName = "AG"),
    pfenum_AR = 10 UMETA(DisplayName = "AR"),
    pfenum_AM = 11 UMETA(DisplayName = "AM"),
    pfenum_AW = 12 UMETA(DisplayName = "AW"),
    pfenum_AU = 13 UMETA(DisplayName = "AU"),
    pfenum_AT = 14 UMETA(DisplayName = "AT"),
    pfenum_AZ = 15 UMETA(DisplayName = "AZ"),
    pfenum_BS = 16 UMETA(DisplayName = "BS"),
    pfenum_BH = 17 UMETA(DisplayName = "BH"),
    pfenum_BD = 18 UMETA(DisplayName = "BD"),
    pfenum_BB = 19 UMETA(DisplayName = "BB"),
    pfenum_BY = 20 UMETA(DisplayName = "BY"),
    pfenum_BE = 21 UMETA(DisplayName = "BE"),
    pfenum_BZ = 22 UMETA(DisplayName = "BZ"),
    pfenum_BJ = 23 UMETA(DisplayName = "BJ"),
    pfenum_BM = 24 UMETA(DisplayName = "BM"),
    pfenum_BT = 25 UMETA(DisplayName = "BT"),
    pfenum_BO = 26 UMETA(DisplayName = "BO"),
    pfenum_BQ = 27 UMETA(DisplayName = "BQ"),
    pfenum_BA = 28 UMETA(DisplayName = "BA"),
    pfenum_BW = 29 UMETA(DisplayName = "BW"),
    pfenum_BV = 30 UMETA(DisplayName = "BV"),
    pfenum_BR = 31 UMETA(DisplayName = "BR"),
    pfenum_IO = 32 UMETA(DisplayName = "IO"),
    pfenum_BN = 33 UMETA(DisplayName = "BN"),
    pfenum_BG = 34 UMETA(DisplayName = "BG"),
    pfenum_BF = 35 UMETA(DisplayName = "BF"),
    pfenum_BI = 36 UMETA(DisplayName = "BI"),
    pfenum_KH = 37 UMETA(DisplayName = "KH"),
    pfenum_CM = 38 UMETA(DisplayName = "CM"),
    pfenum_CA = 39 UMETA(DisplayName = "CA"),
    pfenum_CV = 40 UMETA(DisplayName = "CV"),
    pfenum_KY = 41 UMETA(DisplayName = "KY"),
    pfenum_CF = 42 UMETA(DisplayName = "CF"),
    pfenum_TD = 43 UMETA(DisplayName = "TD"),
    pfenum_CL = 44 UMETA(DisplayName = "CL"),
    pfenum_CN = 45 UMETA(DisplayName = "CN"),
    pfenum_CX = 46 UMETA(DisplayName = "CX"),
    pfenum_CC = 47 UMETA(DisplayName = "CC"),
    pfenum_CO = 48 UMETA(DisplayName = "CO"),
    pfenum_KM = 49 UMETA(DisplayName = "KM"),
    pfenum_CG = 50 UMETA(DisplayName = "CG"),
    pfenum_CD = 51 UMETA(DisplayName = "CD"),
    pfenum_CK = 52 UMETA(DisplayName = "CK"),
    pfenum_CR = 53 UMETA(DisplayName = "CR"),
    pfenum_CI = 54 UMETA(DisplayName = "CI"),
    pfenum_HR = 55 UMETA(DisplayName = "HR"),
    pfenum_CU = 56 UMETA(DisplayName = "CU"),
    pfenum_CW = 57 UMETA(DisplayName = "CW"),
    pfenum_CY = 58 UMETA(DisplayName = "CY"),
    pfenum_CZ = 59 UMETA(DisplayName = "CZ"),
    pfenum_DK = 60 UMETA(DisplayName = "DK"),
    pfenum_DJ = 61 UMETA(DisplayName = "DJ"),
    pfenum_DM = 62 UMETA(DisplayName = "DM"),
    pfenum_DO = 63 UMETA(DisplayName = "DO"),
    pfenum_EC = 64 UMETA(DisplayName = "EC"),
    pfenum_EG = 65 UMETA(DisplayName = "EG"),
    pfenum_SV = 66 UMETA(DisplayName = "SV"),
    pfenum_GQ = 67 UMETA(DisplayName = "GQ"),
    pfenum_ER = 68 UMETA(DisplayName = "ER"),
    pfenum_EE = 69 UMETA(DisplayName = "EE"),
    pfenum_ET = 70 UMETA(DisplayName = "ET"),
    pfenum_FK = 71 UMETA(DisplayName = "FK"),
    pfenum_FO = 72 UMETA(DisplayName = "FO"),
    pfenum_FJ = 73 UMETA(DisplayName = "FJ"),
    pfenum_FI = 74 UMETA(DisplayName = "FI"),
    pfenum_FR = 75 UMETA(DisplayName = "FR"),
    pfenum_GF = 76 UMETA(DisplayName = "GF"),
    pfenum_PF = 77 UMETA(DisplayName = "PF"),
    pfenum_TF = 78 UMETA(DisplayName = "TF"),
    pfenum_GA = 79 UMETA(DisplayName = "GA"),
    pfenum_GM = 80 UMETA(DisplayName = "GM"),
    pfenum_GE = 81 UMETA(DisplayName = "GE"),
    pfenum_DE = 82 UMETA(DisplayName = "DE"),
    pfenum_GH = 83 UMETA(DisplayName = "GH"),
    pfenum_GI = 84 UMETA(DisplayName = "GI"),
    pfenum_GR = 85 UMETA(DisplayName = "GR"),
    pfenum_GL = 86 UMETA(DisplayName = "GL"),
    pfenum_GD = 87 UMETA(DisplayName = "GD"),
    pfenum_GP = 88 UMETA(DisplayName = "GP"),
    pfenum_GU = 89 UMETA(DisplayName = "GU"),
    pfenum_GT = 90 UMETA(DisplayName = "GT"),
    pfenum_GG = 91 UMETA(DisplayName = "GG"),
    pfenum_GN = 92 UMETA(DisplayName = "GN"),
    pfenum_GW = 93 UMETA(DisplayName = "GW"),
    pfenum_GY = 94 UMETA(DisplayName = "GY"),
    pfenum_HT = 95 UMETA(DisplayName = "HT"),
    pfenum_HM = 96 UMETA(DisplayName = "HM"),
    pfenum_VA = 97 UMETA(DisplayName = "VA"),
    pfenum_HN = 98 UMETA(DisplayName = "HN"),
    pfenum_HK = 99 UMETA(DisplayName = "HK"),
    pfenum_HU = 100 UMETA(DisplayName = "HU"),
    pfenum_IS = 101 UMETA(DisplayName = "IS"),
    pfenum_IN = 102 UMETA(DisplayName = "IN"),
    pfenum_ID = 103 UMETA(DisplayName = "ID"),
    pfenum_IR = 104 UMETA(DisplayName = "IR"),
    pfenum_IQ = 105 UMETA(DisplayName = "IQ"),
    pfenum_IE = 106 UMETA(DisplayName = "IE"),
    pfenum_IM = 107 UMETA(DisplayName = "IM"),
    pfenum_IL = 108 UMETA(DisplayName = "IL"),
    pfenum_IT = 109 UMETA(DisplayName = "IT"),
    pfenum_JM = 110 UMETA(DisplayName = "JM"),
    pfenum_JP = 111 UMETA(DisplayName = "JP"),
    pfenum_JE = 112 UMETA(DisplayName = "JE"),
    pfenum_JO = 113 UMETA(DisplayName = "JO"),
    pfenum_KZ = 114 UMETA(DisplayName = "KZ"),
    pfenum_KE = 115 UMETA(DisplayName = "KE"),
    pfenum_KI = 116 UMETA(DisplayName = "KI"),
    pfenum_KP = 117 UMETA(DisplayName = "KP"),
    pfenum_KR = 118 UMETA(DisplayName = "KR"),
    pfenum_KW = 119 UMETA(DisplayName = "KW"),
    pfenum_KG = 120 UMETA(DisplayName = "KG"),
    pfenum_LA = 121 UMETA(DisplayName = "LA"),
    pfenum_LV = 122 UMETA(DisplayName = "LV"),
    pfenum_LB = 123 UMETA(DisplayName = "LB"),
    pfenum_LS = 124 UMETA(DisplayName = "LS"),
    pfenum_LR = 125 UMETA(DisplayName = "LR"),
    pfenum_LY = 126 UMETA(DisplayName = "LY"),
    pfenum_LI = 127 UMETA(DisplayName = "LI"),
    pfenum_LT = 128 UMETA(DisplayName = "LT"),
    pfenum_LU = 129 UMETA(DisplayName = "LU"),
    pfenum_MO = 130 UMETA(DisplayName = "MO"),
    pfenum_MK = 131 UMETA(DisplayName = "MK"),
    pfenum_MG = 132 UMETA(DisplayName = "MG"),
    pfenum_MW = 133 UMETA(DisplayName = "MW"),
    pfenum_MY = 134 UMETA(DisplayName = "MY"),
    pfenum_MV = 135 UMETA(DisplayName = "MV"),
    pfenum_ML = 136 UMETA(DisplayName = "ML"),
    pfenum_MT = 137 UMETA(DisplayName = "MT"),
    pfenum_MH = 138 UMETA(DisplayName = "MH"),
    pfenum_MQ = 139 UMETA(DisplayName = "MQ"),
    pfenum_MR = 140 UMETA(DisplayName = "MR"),
    pfenum_MU = 141 UMETA(DisplayName = "MU"),
    pfenum_YT = 142 UMETA(DisplayName = "YT"),
    pfenum_MX = 143 UMETA(DisplayName = "MX"),
    pfenum_FM = 144 UMETA(DisplayName = "FM"),
    pfenum_MD = 145 UMETA(DisplayName = "MD"),
    pfenum_MC = 146 UMETA(DisplayName = "MC"),
    pfenum_MN = 147 UMETA(DisplayName = "MN"),
    pfenum_ME = 148 UMETA(DisplayName = "ME"),
    pfenum_MS = 149 UMETA(DisplayName = "MS"),
    pfenum_MA = 150 UMETA(DisplayName = "MA"),
    pfenum_MZ = 151 UMETA(DisplayName = "MZ"),
    pfenum_MM = 152 UMETA(DisplayName = "MM"),
    pfenum_NA = 153 UMETA(DisplayName = "NA"),
    pfenum_NR = 154 UMETA(DisplayName = "NR"),
    pfenum_NP = 155 UMETA(DisplayName = "NP"),
    pfenum_NL = 156 UMETA(DisplayName = "NL"),
    pfenum_NC = 157 UMETA(DisplayName = "NC"),
    pfenum_NZ = 158 UMETA(DisplayName = "NZ"),
    pfenum_NI = 159 UMETA(DisplayName = "NI"),
    pfenum_NE = 160 UMETA(DisplayName = "NE"),
    pfenum_NG = 161 UMETA(DisplayName = "NG"),
    pfenum_NU = 162 UMETA(DisplayName = "NU"),
    pfenum_NF = 163 UMETA(DisplayName = "NF"),
    pfenum_MP = 164 UMETA(DisplayName = "MP"),
    pfenum_NO = 165 UMETA(DisplayName = "NO"),
    pfenum_OM = 166 UMETA(DisplayName = "OM"),
    pfenum_PK = 167 UMETA(DisplayName = "PK"),
    pfenum_PW = 168 UMETA(DisplayName = "PW"),
    pfenum_PS = 169 UMETA(DisplayName = "PS"),
    pfenum_PA = 170 UMETA(DisplayName = "PA"),
    pfenum_PG = 171 UMETA(DisplayName = "PG"),
    pfenum_PY = 172 UMETA(DisplayName = "PY"),
    pfenum_PE = 173 UMETA(DisplayName = "PE"),
    pfenum_PH = 174 UMETA(DisplayName = "PH"),
    pfenum_PN = 175 UMETA(DisplayName = "PN"),
    pfenum_PL = 176 UMETA(DisplayName = "PL"),
    pfenum_PT = 177 UMETA(DisplayName = "PT"),
    pfenum_PR = 178 UMETA(DisplayName = "PR"),
    pfenum_QA = 179 UMETA(DisplayName = "QA"),
    pfenum_RE = 180 UMETA(DisplayName = "RE"),
    pfenum_RO = 181 UMETA(DisplayName = "RO"),
    pfenum_RU = 182 UMETA(DisplayName = "RU"),
    pfenum_RW = 183 UMETA(DisplayName = "RW"),
    pfenum_BL = 184 UMETA(DisplayName = "BL"),
    pfenum_SH = 185 UMETA(DisplayName = "SH"),
    pfenum_KN = 186 UMETA(DisplayName = "KN"),
    pfenum_LC = 187 UMETA(DisplayName = "LC"),
    pfenum_MF = 188 UMETA(DisplayName = "MF"),
    pfenum_PM = 189 UMETA(DisplayName = "PM"),
    pfenum_VC = 190 UMETA(DisplayName = "VC"),
    pfenum_WS = 191 UMETA(DisplayName = "WS"),
    pfenum_SM = 192 UMETA(DisplayName = "SM"),
    pfenum_ST = 193 UMETA(DisplayName = "ST"),
    pfenum_SA = 194 UMETA(DisplayName = "SA"),
    pfenum_SN = 195 UMETA(DisplayName = "SN"),
    pfenum_RS = 196 UMETA(DisplayName = "RS"),
    pfenum_SC = 197 UMETA(DisplayName = "SC"),
    pfenum_SL = 198 UMETA(DisplayName = "SL"),
    pfenum_SG = 199 UMETA(DisplayName = "SG"),
    pfenum_SX = 200 UMETA(DisplayName = "SX"),
    pfenum_SK = 201 UMETA(DisplayName = "SK"),
    pfenum_SI = 202 UMETA(DisplayName = "SI"),
    pfenum_SB = 203 UMETA(DisplayName = "SB"),
    pfenum_SO = 204 UMETA(DisplayName = "SO"),
    pfenum_ZA = 205 UMETA(DisplayName = "ZA"),
    pfenum_GS = 206 UMETA(DisplayName = "GS"),
    pfenum_SS = 207 UMETA(DisplayName = "SS"),
    pfenum_ES = 208 UMETA(DisplayName = "ES"),
    pfenum_LK = 209 UMETA(DisplayName = "LK"),
    pfenum_SD = 210 UMETA(DisplayName = "SD"),
    pfenum_SR = 211 UMETA(DisplayName = "SR"),
    pfenum_SJ = 212 UMETA(DisplayName = "SJ"),
    pfenum_SZ = 213 UMETA(DisplayName = "SZ"),
    pfenum_SE = 214 UMETA(DisplayName = "SE"),
    pfenum_CH = 215 UMETA(DisplayName = "CH"),
    pfenum_SY = 216 UMETA(DisplayName = "SY"),
    pfenum_TW = 217 UMETA(DisplayName = "TW"),
    pfenum_TJ = 218 UMETA(DisplayName = "TJ"),
    pfenum_TZ = 219 UMETA(DisplayName = "TZ"),
    pfenum_TH = 220 UMETA(DisplayName = "TH"),
    pfenum_TL = 221 UMETA(DisplayName = "TL"),
    pfenum_TG = 222 UMETA(DisplayName = "TG"),
    pfenum_TK = 223 UMETA(DisplayName = "TK"),
    pfenum_TO = 224 UMETA(DisplayName = "TO"),
    pfenum_TT = 225 UMETA(DisplayName = "TT"),
    pfenum_TN = 226 UMETA(DisplayName = "TN"),
    pfenum_TR = 227 UMETA(DisplayName = "TR"),
    pfenum_TM = 228 UMETA(DisplayName = "TM"),
    pfenum_TC = 229 UMETA(DisplayName = "TC"),
    pfenum_TV = 230 UMETA(DisplayName = "TV"),
    pfenum_UG = 231 UMETA(DisplayName = "UG"),
    pfenum_UA = 232 UMETA(DisplayName = "UA"),
    pfenum_AE = 233 UMETA(DisplayName = "AE"),
    pfenum_GB = 234 UMETA(DisplayName = "GB"),
    pfenum_US = 235 UMETA(DisplayName = "US"),
    pfenum_UM = 236 UMETA(DisplayName = "UM"),
    pfenum_UY = 237 UMETA(DisplayName = "UY"),
    pfenum_UZ = 238 UMETA(DisplayName = "UZ"),
    pfenum_VU = 239 UMETA(DisplayName = "VU"),
    pfenum_VE = 240 UMETA(DisplayName = "VE"),
    pfenum_VN = 241 UMETA(DisplayName = "VN"),
    pfenum_VG = 242 UMETA(DisplayName = "VG"),
    pfenum_VI = 243 UMETA(DisplayName = "VI"),
    pfenum_WF = 244 UMETA(DisplayName = "WF"),
    pfenum_EH = 245 UMETA(DisplayName = "EH"),
    pfenum_YE = 246 UMETA(DisplayName = "YE"),
    pfenum_ZM = 247 UMETA(DisplayName = "ZM"),
    pfenum_ZW = 248 UMETA(DisplayName = "ZW"),
};

/** SegmentCurrency */

UENUM(BlueprintType)
enum class ESegmentCurrency : uint8
{
    pfenum_AED = 0 UMETA(DisplayName = "AED"),
    pfenum_AFN = 1 UMETA(DisplayName = "AFN"),
    pfenum_ALL = 2 UMETA(DisplayName = "ALL"),
    pfenum_AMD = 3 UMETA(DisplayName = "AMD"),
    pfenum_ANG = 4 UMETA(DisplayName = "ANG"),
    pfenum_AOA = 5 UMETA(DisplayName = "AOA"),
    pfenum_ARS = 6 UMETA(DisplayName = "ARS"),
    pfenum_AUD = 7 UMETA(DisplayName = "AUD"),
    pfenum_AWG = 8 UMETA(DisplayName = "AWG"),
    pfenum_AZN = 9 UMETA(DisplayName = "AZN"),
    pfenum_BAM = 10 UMETA(DisplayName = "BAM"),
    pfenum_BBD = 11 UMETA(DisplayName = "BBD"),
    pfenum_BDT = 12 UMETA(DisplayName = "BDT"),
    pfenum_BGN = 13 UMETA(DisplayName = "BGN"),
    pfenum_BHD = 14 UMETA(DisplayName = "BHD"),
    pfenum_BIF = 15 UMETA(DisplayName = "BIF"),
    pfenum_BMD = 16 UMETA(DisplayName = "BMD"),
    pfenum_BND = 17 UMETA(DisplayName = "BND"),
    pfenum_BOB = 18 UMETA(DisplayName = "BOB"),
    pfenum_BRL = 19 UMETA(DisplayName = "BRL"),
    pfenum_BSD = 20 UMETA(DisplayName = "BSD"),
    pfenum_BTN = 21 UMETA(DisplayName = "BTN"),
    pfenum_BWP = 22 UMETA(DisplayName = "BWP"),
    pfenum_BYR = 23 UMETA(DisplayName = "BYR"),
    pfenum_BZD = 24 UMETA(DisplayName = "BZD"),
    pfenum_CAD = 25 UMETA(DisplayName = "CAD"),
    pfenum_CDF = 26 UMETA(DisplayName = "CDF"),
    pfenum_CHF = 27 UMETA(DisplayName = "CHF"),
    pfenum_CLP = 28 UMETA(DisplayName = "CLP"),
    pfenum_CNY = 29 UMETA(DisplayName = "CNY"),
    pfenum_COP = 30 UMETA(DisplayName = "COP"),
    pfenum_CRC = 31 UMETA(DisplayName = "CRC"),
    pfenum_CUC = 32 UMETA(DisplayName = "CUC"),
    pfenum_CUP = 33 UMETA(DisplayName = "CUP"),
    pfenum_CVE = 34 UMETA(DisplayName = "CVE"),
    pfenum_CZK = 35 UMETA(DisplayName = "CZK"),
    pfenum_DJF = 36 UMETA(DisplayName = "DJF"),
    pfenum_DKK = 37 UMETA(DisplayName = "DKK"),
    pfenum_DOP = 38 UMETA(DisplayName = "DOP"),
    pfenum_DZD = 39 UMETA(DisplayName = "DZD"),
    pfenum_EGP = 40 UMETA(DisplayName = "EGP"),
    pfenum_ERN = 41 UMETA(DisplayName = "ERN"),
    pfenum_ETB = 42 UMETA(DisplayName = "ETB"),
    pfenum_EUR = 43 UMETA(DisplayName = "EUR"),
    pfenum_FJD = 44 UMETA(DisplayName = "FJD"),
    pfenum_FKP = 45 UMETA(DisplayName = "FKP"),
    pfenum_GBP = 46 UMETA(DisplayName = "GBP"),
    pfenum_GEL = 47 UMETA(DisplayName = "GEL"),
    pfenum_GGP = 48 UMETA(DisplayName = "GGP"),
    pfenum_GHS = 49 UMETA(DisplayName = "GHS"),
    pfenum_GIP = 50 UMETA(DisplayName = "GIP"),
    pfenum_GMD = 51 UMETA(DisplayName = "GMD"),
    pfenum_GNF = 52 UMETA(DisplayName = "GNF"),
    pfenum_GTQ = 53 UMETA(DisplayName = "GTQ"),
    pfenum_GYD = 54 UMETA(DisplayName = "GYD"),
    pfenum_HKD = 55 UMETA(DisplayName = "HKD"),
    pfenum_HNL = 56 UMETA(DisplayName = "HNL"),
    pfenum_HRK = 57 UMETA(DisplayName = "HRK"),
    pfenum_HTG = 58 UMETA(DisplayName = "HTG"),
    pfenum_HUF = 59 UMETA(DisplayName = "HUF"),
    pfenum_IDR = 60 UMETA(DisplayName = "IDR"),
    pfenum_ILS = 61 UMETA(DisplayName = "ILS"),
    pfenum_IMP = 62 UMETA(DisplayName = "IMP"),
    pfenum_INR = 63 UMETA(DisplayName = "INR"),
    pfenum_IQD = 64 UMETA(DisplayName = "IQD"),
    pfenum_IRR = 65 UMETA(DisplayName = "IRR"),
    pfenum_ISK = 66 UMETA(DisplayName = "ISK"),
    pfenum_JEP = 67 UMETA(DisplayName = "JEP"),
    pfenum_JMD = 68 UMETA(DisplayName = "JMD"),
    pfenum_JOD = 69 UMETA(DisplayName = "JOD"),
    pfenum_JPY = 70 UMETA(DisplayName = "JPY"),
    pfenum_KES = 71 UMETA(DisplayName = "KES"),
    pfenum_KGS = 72 UMETA(DisplayName = "KGS"),
    pfenum_KHR = 73 UMETA(DisplayName = "KHR"),
    pfenum_KMF = 74 UMETA(DisplayName = "KMF"),
    pfenum_KPW = 75 UMETA(DisplayName = "KPW"),
    pfenum_KRW = 76 UMETA(DisplayName = "KRW"),
    pfenum_KWD = 77 UMETA(DisplayName = "KWD"),
    pfenum_KYD = 78 UMETA(DisplayName = "KYD"),
    pfenum_KZT = 79 UMETA(DisplayName = "KZT"),
    pfenum_LAK = 80 UMETA(DisplayName = "LAK"),
    pfenum_LBP = 81 UMETA(DisplayName = "LBP"),
    pfenum_LKR = 82 UMETA(DisplayName = "LKR"),
    pfenum_LRD = 83 UMETA(DisplayName = "LRD"),
    pfenum_LSL = 84 UMETA(DisplayName = "LSL"),
    pfenum_LYD = 85 UMETA(DisplayName = "LYD"),
    pfenum_MAD = 86 UMETA(DisplayName = "MAD"),
    pfenum_MDL = 87 UMETA(DisplayName = "MDL"),
    pfenum_MGA = 88 UMETA(DisplayName = "MGA"),
    pfenum_MKD = 89 UMETA(DisplayName = "MKD"),
    pfenum_MMK = 90 UMETA(DisplayName = "MMK"),
    pfenum_MNT = 91 UMETA(DisplayName = "MNT"),
    pfenum_MOP = 92 UMETA(DisplayName = "MOP"),
    pfenum_MRO = 93 UMETA(DisplayName = "MRO"),
    pfenum_MUR = 94 UMETA(DisplayName = "MUR"),
    pfenum_MVR = 95 UMETA(DisplayName = "MVR"),
    pfenum_MWK = 96 UMETA(DisplayName = "MWK"),
    pfenum_MXN = 97 UMETA(DisplayName = "MXN"),
    pfenum_MYR = 98 UMETA(DisplayName = "MYR"),
    pfenum_MZN = 99 UMETA(DisplayName = "MZN"),
    pfenum_NAD = 100 UMETA(DisplayName = "NAD"),
    pfenum_NGN = 101 UMETA(DisplayName = "NGN"),
    pfenum_NIO = 102 UMETA(DisplayName = "NIO"),
    pfenum_NOK = 103 UMETA(DisplayName = "NOK"),
    pfenum_NPR = 104 UMETA(DisplayName = "NPR"),
    pfenum_NZD = 105 UMETA(DisplayName = "NZD"),
    pfenum_OMR = 106 UMETA(DisplayName = "OMR"),
    pfenum_PAB = 107 UMETA(DisplayName = "PAB"),
    pfenum_PEN = 108 UMETA(DisplayName = "PEN"),
    pfenum_PGK = 109 UMETA(DisplayName = "PGK"),
    pfenum_PHP = 110 UMETA(DisplayName = "PHP"),
    pfenum_PKR = 111 UMETA(DisplayName = "PKR"),
    pfenum_PLN = 112 UMETA(DisplayName = "PLN"),
    pfenum_PYG = 113 UMETA(DisplayName = "PYG"),
    pfenum_QAR = 114 UMETA(DisplayName = "QAR"),
    pfenum_RON = 115 UMETA(DisplayName = "RON"),
    pfenum_RSD = 116 UMETA(DisplayName = "RSD"),
    pfenum_RUB = 117 UMETA(DisplayName = "RUB"),
    pfenum_RWF = 118 UMETA(DisplayName = "RWF"),
    pfenum_SAR = 119 UMETA(DisplayName = "SAR"),
    pfenum_SBD = 120 UMETA(DisplayName = "SBD"),
    pfenum_SCR = 121 UMETA(DisplayName = "SCR"),
    pfenum_SDG = 122 UMETA(DisplayName = "SDG"),
    pfenum_SEK = 123 UMETA(DisplayName = "SEK"),
    pfenum_SGD = 124 UMETA(DisplayName = "SGD"),
    pfenum_SHP = 125 UMETA(DisplayName = "SHP"),
    pfenum_SLL = 126 UMETA(DisplayName = "SLL"),
    pfenum_SOS = 127 UMETA(DisplayName = "SOS"),
    pfenum_SPL = 128 UMETA(DisplayName = "SPL"),
    pfenum_SRD = 129 UMETA(DisplayName = "SRD"),
    pfenum_STD = 130 UMETA(DisplayName = "STD"),
    pfenum_SVC = 131 UMETA(DisplayName = "SVC"),
    pfenum_SYP = 132 UMETA(DisplayName = "SYP"),
    pfenum_SZL = 133 UMETA(DisplayName = "SZL"),
    pfenum_THB = 134 UMETA(DisplayName = "THB"),
    pfenum_TJS = 135 UMETA(DisplayName = "TJS"),
    pfenum_TMT = 136 UMETA(DisplayName = "TMT"),
    pfenum_TND = 137 UMETA(DisplayName = "TND"),
    pfenum_TOP = 138 UMETA(DisplayName = "TOP"),
    pfenum_TRY = 139 UMETA(DisplayName = "TRY"),
    pfenum_TTD = 140 UMETA(DisplayName = "TTD"),
    pfenum_TVD = 141 UMETA(DisplayName = "TVD"),
    pfenum_TWD = 142 UMETA(DisplayName = "TWD"),
    pfenum_TZS = 143 UMETA(DisplayName = "TZS"),
    pfenum_UAH = 144 UMETA(DisplayName = "UAH"),
    pfenum_UGX = 145 UMETA(DisplayName = "UGX"),
    pfenum_USD = 146 UMETA(DisplayName = "USD"),
    pfenum_UYU = 147 UMETA(DisplayName = "UYU"),
    pfenum_UZS = 148 UMETA(DisplayName = "UZS"),
    pfenum_VEF = 149 UMETA(DisplayName = "VEF"),
    pfenum_VND = 150 UMETA(DisplayName = "VND"),
    pfenum_VUV = 151 UMETA(DisplayName = "VUV"),
    pfenum_WST = 152 UMETA(DisplayName = "WST"),
    pfenum_XAF = 153 UMETA(DisplayName = "XAF"),
    pfenum_XCD = 154 UMETA(DisplayName = "XCD"),
    pfenum_XDR = 155 UMETA(DisplayName = "XDR"),
    pfenum_XOF = 156 UMETA(DisplayName = "XOF"),
    pfenum_XPF = 157 UMETA(DisplayName = "XPF"),
    pfenum_YER = 158 UMETA(DisplayName = "YER"),
    pfenum_ZAR = 159 UMETA(DisplayName = "ZAR"),
    pfenum_ZMW = 160 UMETA(DisplayName = "ZMW"),
    pfenum_ZWD = 161 UMETA(DisplayName = "ZWD"),
};

/** SegmentFilterComparison */

UENUM(BlueprintType)
enum class ESegmentFilterComparison : uint8
{
    pfenum_GreaterThan = 0 UMETA(DisplayName = "GreaterThan"),
    pfenum_LessThan = 1 UMETA(DisplayName = "LessThan"),
    pfenum_EqualTo = 2 UMETA(DisplayName = "EqualTo"),
    pfenum_NotEqualTo = 3 UMETA(DisplayName = "NotEqualTo"),
    pfenum_GreaterThanOrEqual = 4 UMETA(DisplayName = "GreaterThanOrEqual"),
    pfenum_LessThanOrEqual = 5 UMETA(DisplayName = "LessThanOrEqual"),
    pfenum_Exists = 6 UMETA(DisplayName = "Exists"),
    pfenum_Contains = 7 UMETA(DisplayName = "Contains"),
    pfenum_NotContains = 8 UMETA(DisplayName = "NotContains"),
};

/** SegmentLoginIdentityProvider */

UENUM(BlueprintType)
enum class ESegmentLoginIdentityProvider : uint8
{
    pfenum_Unknown = 0 UMETA(DisplayName = "Unknown"),
    pfenum_PlayFab = 1 UMETA(DisplayName = "PlayFab"),
    pfenum_Custom = 2 UMETA(DisplayName = "Custom"),
    pfenum_GameCenter = 3 UMETA(DisplayName = "GameCenter"),
    pfenum_GooglePlay = 4 UMETA(DisplayName = "GooglePlay"),
    pfenum_Steam = 5 UMETA(DisplayName = "Steam"),
    pfenum_XBoxLive = 6 UMETA(DisplayName = "XBoxLive"),
    pfenum_PSN = 7 UMETA(DisplayName = "PSN"),
    pfenum_Kongregate = 8 UMETA(DisplayName = "Kongregate"),
    pfenum_Facebook = 9 UMETA(DisplayName = "Facebook"),
    pfenum_IOSDevice = 10 UMETA(DisplayName = "IOSDevice"),
    pfenum_AndroidDevice = 11 UMETA(DisplayName = "AndroidDevice"),
    pfenum_Twitch = 12 UMETA(DisplayName = "Twitch"),
    pfenum_WindowsHello = 13 UMETA(DisplayName = "WindowsHello"),
    pfenum_GameServer = 14 UMETA(DisplayName = "GameServer"),
    pfenum_CustomServer = 15 UMETA(DisplayName = "CustomServer"),
    pfenum_NintendoSwitch = 16 UMETA(DisplayName = "NintendoSwitch"),
    pfenum_FacebookInstantGames = 17 UMETA(DisplayName = "FacebookInstantGames"),
    pfenum_OpenIdConnect = 18 UMETA(DisplayName = "OpenIdConnect"),
    pfenum_Apple = 19 UMETA(DisplayName = "Apple"),
    pfenum_NintendoSwitchAccount = 20 UMETA(DisplayName = "NintendoSwitchAccount"),
    pfenum_GooglePlayGames = 21 UMETA(DisplayName = "GooglePlayGames"),
};

/** SegmentPushNotificationDevicePlatform */

UENUM(BlueprintType)
enum class ESegmentPushNotificationDevicePlatform : uint8
{
    pfenum_ApplePushNotificationService = 0 UMETA(DisplayName = "ApplePushNotificationService"),
    pfenum_GoogleCloudMessaging = 1 UMETA(DisplayName = "GoogleCloudMessaging"),
};

/** SourceType */

UENUM(BlueprintType)
enum class EPfSourceType : uint8
{
    pfenum_Admin = 0 UMETA(DisplayName = "Admin"),
    pfenum_BackEnd = 1 UMETA(DisplayName = "BackEnd"),
    pfenum_GameClient = 2 UMETA(DisplayName = "GameClient"),
    pfenum_GameServer = 3 UMETA(DisplayName = "GameServer"),
    pfenum_Partner = 4 UMETA(DisplayName = "Partner"),
    pfenum_Custom = 5 UMETA(DisplayName = "Custom"),
    pfenum_API = 6 UMETA(DisplayName = "API"),
};

/** StatisticAggregationMethod */

UENUM(BlueprintType)
enum class EStatisticAggregationMethod : uint8
{
    pfenum_Last = 0 UMETA(DisplayName = "Last"),
    pfenum_Min = 1 UMETA(DisplayName = "Min"),
    pfenum_Max = 2 UMETA(DisplayName = "Max"),
    pfenum_Sum = 3 UMETA(DisplayName = "Sum"),
};

/** StatisticResetIntervalOption */

UENUM(BlueprintType)
enum class EStatisticResetIntervalOption : uint8
{
    pfenum_Never = 0 UMETA(DisplayName = "Never"),
    pfenum_Hour = 1 UMETA(DisplayName = "Hour"),
    pfenum_Day = 2 UMETA(DisplayName = "Day"),
    pfenum_Week = 3 UMETA(DisplayName = "Week"),
    pfenum_Month = 4 UMETA(DisplayName = "Month"),
};

/** StatisticVersionArchivalStatus */

UENUM(BlueprintType)
enum class EStatisticVersionArchivalStatus : uint8
{
    pfenum_NotScheduled = 0 UMETA(DisplayName = "NotScheduled"),
    pfenum_Scheduled = 1 UMETA(DisplayName = "Scheduled"),
    pfenum_Queued = 2 UMETA(DisplayName = "Queued"),
    pfenum_InProgress = 3 UMETA(DisplayName = "InProgress"),
    pfenum_Complete = 4 UMETA(DisplayName = "Complete"),
};

/** StatisticVersionStatus */

UENUM(BlueprintType)
enum class EStatisticVersionStatus : uint8
{
    pfenum_Active = 0 UMETA(DisplayName = "Active"),
    pfenum_SnapshotPending = 1 UMETA(DisplayName = "SnapshotPending"),
    pfenum_Snapshot = 2 UMETA(DisplayName = "Snapshot"),
    pfenum_ArchivalPending = 3 UMETA(DisplayName = "ArchivalPending"),
    pfenum_Archived = 4 UMETA(DisplayName = "Archived"),
};

/** SubscriptionProviderStatus */

UENUM(BlueprintType)
enum class ESubscriptionProviderStatus : uint8
{
    pfenum_NoError = 0 UMETA(DisplayName = "NoError"),
    pfenum_Cancelled = 1 UMETA(DisplayName = "Cancelled"),
    pfenum_UnknownError = 2 UMETA(DisplayName = "UnknownError"),
    pfenum_BillingError = 3 UMETA(DisplayName = "BillingError"),
    pfenum_ProductUnavailable = 4 UMETA(DisplayName = "ProductUnavailable"),
    pfenum_CustomerDidNotAcceptPriceChange = 5 UMETA(DisplayName = "CustomerDidNotAcceptPriceChange"),
    pfenum_FreeTrial = 6 UMETA(DisplayName = "FreeTrial"),
    pfenum_PaymentPending = 7 UMETA(DisplayName = "PaymentPending"),
};

/** TaskInstanceStatus */

UENUM(BlueprintType)
enum class ETaskInstanceStatus : uint8
{
    pfenum_Succeeded = 0 UMETA(DisplayName = "Succeeded"),
    pfenum_Starting = 1 UMETA(DisplayName = "Starting"),
    pfenum_InProgress = 2 UMETA(DisplayName = "InProgress"),
    pfenum_Failed = 3 UMETA(DisplayName = "Failed"),
    pfenum_Aborted = 4 UMETA(DisplayName = "Aborted"),
    pfenum_Stalled = 5 UMETA(DisplayName = "Stalled"),
};

/** TitleActivationStatus */

UENUM(BlueprintType)
enum class ETitleActivationStatus : uint8
{
    pfenum_None = 0 UMETA(DisplayName = "None"),
    pfenum_ActivatedTitleKey = 1 UMETA(DisplayName = "ActivatedTitleKey"),
    pfenum_PendingSteam = 2 UMETA(DisplayName = "PendingSteam"),
    pfenum_ActivatedSteam = 3 UMETA(DisplayName = "ActivatedSteam"),
    pfenum_RevokedSteam = 4 UMETA(DisplayName = "RevokedSteam"),
};

/** UserDataPermission */

UENUM(BlueprintType)
enum class EUserDataPermission : uint8
{
    pfenum_Private = 0 UMETA(DisplayName = "Private"),
    pfenum_Public = 1 UMETA(DisplayName = "Public"),
};

/** UserOrigination */

UENUM(BlueprintType)
enum class EUserOrigination : uint8
{
    pfenum_Organic = 0 UMETA(DisplayName = "Organic"),
    pfenum_Steam = 1 UMETA(DisplayName = "Steam"),
    pfenum_Google = 2 UMETA(DisplayName = "Google"),
    pfenum_Amazon = 3 UMETA(DisplayName = "Amazon"),
    pfenum_Facebook = 4 UMETA(DisplayName = "Facebook"),
    pfenum_Kongregate = 5 UMETA(DisplayName = "Kongregate"),
    pfenum_GamersFirst = 6 UMETA(DisplayName = "GamersFirst"),
    pfenum_Unknown = 7 UMETA(DisplayName = "Unknown"),
    pfenum_IOS = 8 UMETA(DisplayName = "IOS"),
    pfenum_LoadTest = 9 UMETA(DisplayName = "LoadTest"),
    pfenum_Android = 10 UMETA(DisplayName = "Android"),
    pfenum_PSN = 11 UMETA(DisplayName = "PSN"),
    pfenum_GameCenter = 12 UMETA(DisplayName = "GameCenter"),
    pfenum_CustomId = 13 UMETA(DisplayName = "CustomId"),
    pfenum_XboxLive = 14 UMETA(DisplayName = "XboxLive"),
    pfenum_Parse = 15 UMETA(DisplayName = "Parse"),
    pfenum_Twitch = 16 UMETA(DisplayName = "Twitch"),
    pfenum_ServerCustomId = 17 UMETA(DisplayName = "ServerCustomId"),
    pfenum_NintendoSwitchDeviceId = 18 UMETA(DisplayName = "NintendoSwitchDeviceId"),
    pfenum_FacebookInstantGamesId = 19 UMETA(DisplayName = "FacebookInstantGamesId"),
    pfenum_OpenIdConnect = 20 UMETA(DisplayName = "OpenIdConnect"),
    pfenum_Apple = 21 UMETA(DisplayName = "Apple"),
    pfenum_NintendoSwitchAccount = 22 UMETA(DisplayName = "NintendoSwitchAccount"),
    pfenum_GooglePlayGames = 23 UMETA(DisplayName = "GooglePlayGames"),
};

/** AdActivity */

UENUM(BlueprintType)
enum class EAdActivity : uint8
{
    pfenum_Opened = 0 UMETA(DisplayName = "Opened"),
    pfenum_Closed = 1 UMETA(DisplayName = "Closed"),
    pfenum_Start = 2 UMETA(DisplayName = "Start"),
    pfenum_End = 3 UMETA(DisplayName = "End"),
};

/** CloudScriptRevisionOption */

UENUM(BlueprintType)
enum class ECloudScriptRevisionOption : uint8
{
    pfenum_Live = 0 UMETA(DisplayName = "Live"),
    pfenum_Latest = 1 UMETA(DisplayName = "Latest"),
    pfenum_Specific = 2 UMETA(DisplayName = "Specific"),
};

/** ExternalFriendSources */

UENUM(BlueprintType)
enum class EExternalFriendSources : uint8
{
    pfenum_None = 0 UMETA(DisplayName = "None"),
    pfenum_Steam = 1 UMETA(DisplayName = "Steam"),
    pfenum_Facebook = 2 UMETA(DisplayName = "Facebook"),
    pfenum_Xbox = 3 UMETA(DisplayName = "Xbox"),
    pfenum_Psn = 4 UMETA(DisplayName = "Psn"),
    pfenum_All = 5 UMETA(DisplayName = "All"),
};

/** TradeStatus */

UENUM(BlueprintType)
enum class ETradeStatus : uint8
{
    pfenum_Invalid = 0 UMETA(DisplayName = "Invalid"),
    pfenum_Opening = 1 UMETA(DisplayName = "Opening"),
    pfenum_Open = 2 UMETA(DisplayName = "Open"),
    pfenum_Accepting = 3 UMETA(DisplayName = "Accepting"),
    pfenum_Accepted = 4 UMETA(DisplayName = "Accepted"),
    pfenum_Filled = 5 UMETA(DisplayName = "Filled"),
    pfenum_Cancelled = 6 UMETA(DisplayName = "Cancelled"),
};

/** TransactionStatus */

UENUM(BlueprintType)
enum class ETransactionStatus : uint8
{
    pfenum_CreateCart = 0 UMETA(DisplayName = "CreateCart"),
    pfenum_Init = 1 UMETA(DisplayName = "Init"),
    pfenum_Approved = 2 UMETA(DisplayName = "Approved"),
    pfenum_Succeeded = 3 UMETA(DisplayName = "Succeeded"),
    pfenum_FailedByProvider = 4 UMETA(DisplayName = "FailedByProvider"),
    pfenum_DisputePending = 5 UMETA(DisplayName = "DisputePending"),
    pfenum_RefundPending = 6 UMETA(DisplayName = "RefundPending"),
    pfenum_Refunded = 7 UMETA(DisplayName = "Refunded"),
    pfenum_RefundFailed = 8 UMETA(DisplayName = "RefundFailed"),
    pfenum_ChargedBack = 9 UMETA(DisplayName = "ChargedBack"),
    pfenum_FailedByUber = 10 UMETA(DisplayName = "FailedByUber"),
    pfenum_FailedByPlayFab = 11 UMETA(DisplayName = "FailedByPlayFab"),
    pfenum_Revoked = 12 UMETA(DisplayName = "Revoked"),
    pfenum_TradePending = 13 UMETA(DisplayName = "TradePending"),
    pfenum_Traded = 14 UMETA(DisplayName = "Traded"),
    pfenum_Upgraded = 15 UMETA(DisplayName = "Upgraded"),
    pfenum_StackPending = 16 UMETA(DisplayName = "StackPending"),
    pfenum_Stacked = 17 UMETA(DisplayName = "Stacked"),
    pfenum_Other = 18 UMETA(DisplayName = "Other"),
    pfenum_Failed = 19 UMETA(DisplayName = "Failed"),
};

/** IdentifiedDeviceType */

UENUM(BlueprintType)
enum class EIdentifiedDeviceType : uint8
{
    pfenum_Unknown = 0 UMETA(DisplayName = "Unknown"),
    pfenum_XboxOne = 1 UMETA(DisplayName = "XboxOne"),
    pfenum_Scarlett = 2 UMETA(DisplayName = "Scarlett"),
};

/** TriggerType */

UENUM(BlueprintType)
enum class EPfTriggerType : uint8
{
    pfenum_HTTP = 0 UMETA(DisplayName = "HTTP"),
    pfenum_Queue = 1 UMETA(DisplayName = "Queue"),
};

/** OperationTypes */

UENUM(BlueprintType)
enum class EOperationTypes : uint8
{
    pfenum_Created = 0 UMETA(DisplayName = "Created"),
    pfenum_Updated = 1 UMETA(DisplayName = "Updated"),
    pfenum_Deleted = 2 UMETA(DisplayName = "Deleted"),
    pfenum_None = 3 UMETA(DisplayName = "None"),
};

/** ConcernCategory */

UENUM(BlueprintType)
enum class EConcernCategory : uint8
{
    pfenum_None = 0 UMETA(DisplayName = "None"),
    pfenum_OffensiveContent = 1 UMETA(DisplayName = "OffensiveContent"),
    pfenum_ChildExploitation = 2 UMETA(DisplayName = "ChildExploitation"),
    pfenum_MalwareOrVirus = 3 UMETA(DisplayName = "MalwareOrVirus"),
    pfenum_PrivacyConcerns = 4 UMETA(DisplayName = "PrivacyConcerns"),
    pfenum_MisleadingApp = 5 UMETA(DisplayName = "MisleadingApp"),
    pfenum_PoorPerformance = 6 UMETA(DisplayName = "PoorPerformance"),
    pfenum_ReviewResponse = 7 UMETA(DisplayName = "ReviewResponse"),
    pfenum_SpamAdvertising = 8 UMETA(DisplayName = "SpamAdvertising"),
    pfenum_Profanity = 9 UMETA(DisplayName = "Profanity"),
};

/** DisplayPropertyType */

UENUM(BlueprintType)
enum class EDisplayPropertyType : uint8
{
    pfenum_None = 0 UMETA(DisplayName = "None"),
    pfenum_QueryDateTime = 1 UMETA(DisplayName = "QueryDateTime"),
    pfenum_QueryDouble = 2 UMETA(DisplayName = "QueryDouble"),
    pfenum_QueryString = 3 UMETA(DisplayName = "QueryString"),
    pfenum_SearchString = 4 UMETA(DisplayName = "SearchString"),
};

/** HelpfulnessVote */

UENUM(BlueprintType)
enum class EHelpfulnessVote : uint8
{
    pfenum_None = 0 UMETA(DisplayName = "None"),
    pfenum_UnHelpful = 1 UMETA(DisplayName = "UnHelpful"),
    pfenum_Helpful = 2 UMETA(DisplayName = "Helpful"),
};

/** ModerationStatus */

UENUM(BlueprintType)
enum class EModerationStatus : uint8
{
    pfenum_Unknown = 0 UMETA(DisplayName = "Unknown"),
    pfenum_AwaitingModeration = 1 UMETA(DisplayName = "AwaitingModeration"),
    pfenum_Approved = 2 UMETA(DisplayName = "Approved"),
    pfenum_Rejected = 3 UMETA(DisplayName = "Rejected"),
};

/** PublishResult */

UENUM(BlueprintType)
enum class EPublishResult : uint8
{
    pfenum_Unknown = 0 UMETA(DisplayName = "Unknown"),
    pfenum_Pending = 1 UMETA(DisplayName = "Pending"),
    pfenum_Succeeded = 2 UMETA(DisplayName = "Succeeded"),
    pfenum_Failed = 3 UMETA(DisplayName = "Failed"),
    pfenum_Canceled = 4 UMETA(DisplayName = "Canceled"),
};

/** AnalysisTaskState */

UENUM(BlueprintType)
enum class EAnalysisTaskState : uint8
{
    pfenum_Waiting = 0 UMETA(DisplayName = "Waiting"),
    pfenum_ReadyForSubmission = 1 UMETA(DisplayName = "ReadyForSubmission"),
    pfenum_SubmittingToPipeline = 2 UMETA(DisplayName = "SubmittingToPipeline"),
    pfenum_Running = 3 UMETA(DisplayName = "Running"),
    pfenum_Completed = 4 UMETA(DisplayName = "Completed"),
    pfenum_Failed = 5 UMETA(DisplayName = "Failed"),
    pfenum_Canceled = 6 UMETA(DisplayName = "Canceled"),
};

/** ExperimentState */

UENUM(BlueprintType)
enum class EExperimentState : uint8
{
    pfenum_New = 0 UMETA(DisplayName = "New"),
    pfenum_Started = 1 UMETA(DisplayName = "Started"),
    pfenum_Stopped = 2 UMETA(DisplayName = "Stopped"),
    pfenum_Deleted = 3 UMETA(DisplayName = "Deleted"),
};

/** ExperimentType */

UENUM(BlueprintType)
enum class EExperimentType : uint8
{
    pfenum_Active = 0 UMETA(DisplayName = "Active"),
    pfenum_Snapshot = 1 UMETA(DisplayName = "Snapshot"),
};

/** AccessPolicy */

UENUM(BlueprintType)
enum class EAccessPolicy : uint8
{
    pfenum_Public = 0 UMETA(DisplayName = "Public"),
    pfenum_Friends = 1 UMETA(DisplayName = "Friends"),
    pfenum_Private = 2 UMETA(DisplayName = "Private"),
};

/** AzureRegion */

UENUM(BlueprintType)
enum class EAzureRegion : uint8
{
    pfenum_AustraliaEast = 0 UMETA(DisplayName = "AustraliaEast"),
    pfenum_AustraliaSoutheast = 1 UMETA(DisplayName = "AustraliaSoutheast"),
    pfenum_BrazilSouth = 2 UMETA(DisplayName = "BrazilSouth"),
    pfenum_CentralUs = 3 UMETA(DisplayName = "CentralUs"),
    pfenum_EastAsia = 4 UMETA(DisplayName = "EastAsia"),
    pfenum_EastUs = 5 UMETA(DisplayName = "EastUs"),
    pfenum_EastUs2 = 6 UMETA(DisplayName = "EastUs2"),
    pfenum_JapanEast = 7 UMETA(DisplayName = "JapanEast"),
    pfenum_JapanWest = 8 UMETA(DisplayName = "JapanWest"),
    pfenum_NorthCentralUs = 9 UMETA(DisplayName = "NorthCentralUs"),
    pfenum_NorthEurope = 10 UMETA(DisplayName = "NorthEurope"),
    pfenum_SouthCentralUs = 11 UMETA(DisplayName = "SouthCentralUs"),
    pfenum_SoutheastAsia = 12 UMETA(DisplayName = "SoutheastAsia"),
    pfenum_WestEurope = 13 UMETA(DisplayName = "WestEurope"),
    pfenum_WestUs = 14 UMETA(DisplayName = "WestUs"),
    pfenum_SouthAfricaNorth = 15 UMETA(DisplayName = "SouthAfricaNorth"),
    pfenum_WestCentralUs = 16 UMETA(DisplayName = "WestCentralUs"),
    pfenum_KoreaCentral = 17 UMETA(DisplayName = "KoreaCentral"),
    pfenum_FranceCentral = 18 UMETA(DisplayName = "FranceCentral"),
    pfenum_WestUs2 = 19 UMETA(DisplayName = "WestUs2"),
    pfenum_CentralIndia = 20 UMETA(DisplayName = "CentralIndia"),
    pfenum_UaeNorth = 21 UMETA(DisplayName = "UaeNorth"),
    pfenum_UkSouth = 22 UMETA(DisplayName = "UkSouth"),
    pfenum_SwedenCentral = 23 UMETA(DisplayName = "SwedenCentral"),
};

/** AzureVmFamily */

UENUM(BlueprintType)
enum class EAzureVmFamily : uint8
{
    pfenum_A = 0 UMETA(DisplayName = "A"),
    pfenum_Av2 = 1 UMETA(DisplayName = "Av2"),
    pfenum_Dv2 = 2 UMETA(DisplayName = "Dv2"),
    pfenum_Dv3 = 3 UMETA(DisplayName = "Dv3"),
    pfenum_F = 4 UMETA(DisplayName = "F"),
    pfenum_Fsv2 = 5 UMETA(DisplayName = "Fsv2"),
    pfenum_Dasv4 = 6 UMETA(DisplayName = "Dasv4"),
    pfenum_Dav4 = 7 UMETA(DisplayName = "Dav4"),
    pfenum_Dadsv5 = 8 UMETA(DisplayName = "Dadsv5"),
    pfenum_Eav4 = 9 UMETA(DisplayName = "Eav4"),
    pfenum_Easv4 = 10 UMETA(DisplayName = "Easv4"),
    pfenum_Ev4 = 11 UMETA(DisplayName = "Ev4"),
    pfenum_Esv4 = 12 UMETA(DisplayName = "Esv4"),
    pfenum_Dsv3 = 13 UMETA(DisplayName = "Dsv3"),
    pfenum_Dsv2 = 14 UMETA(DisplayName = "Dsv2"),
    pfenum_NCasT4_v3 = 15 UMETA(DisplayName = "NCasT4_v3"),
    pfenum_Ddv4 = 16 UMETA(DisplayName = "Ddv4"),
    pfenum_Ddsv4 = 17 UMETA(DisplayName = "Ddsv4"),
    pfenum_HBv3 = 18 UMETA(DisplayName = "HBv3"),
};

/** AzureVmSize */

UENUM(BlueprintType)
enum class EAzureVmSize : uint8
{
    pfenum_Standard_A1 = 0 UMETA(DisplayName = "Standard_A1"),
    pfenum_Standard_A2 = 1 UMETA(DisplayName = "Standard_A2"),
    pfenum_Standard_A3 = 2 UMETA(DisplayName = "Standard_A3"),
    pfenum_Standard_A4 = 3 UMETA(DisplayName = "Standard_A4"),
    pfenum_Standard_A1_v2 = 4 UMETA(DisplayName = "Standard_A1_v2"),
    pfenum_Standard_A2_v2 = 5 UMETA(DisplayName = "Standard_A2_v2"),
    pfenum_Standard_A4_v2 = 6 UMETA(DisplayName = "Standard_A4_v2"),
    pfenum_Standard_A8_v2 = 7 UMETA(DisplayName = "Standard_A8_v2"),
    pfenum_Standard_D1_v2 = 8 UMETA(DisplayName = "Standard_D1_v2"),
    pfenum_Standard_D2_v2 = 9 UMETA(DisplayName = "Standard_D2_v2"),
    pfenum_Standard_D3_v2 = 10 UMETA(DisplayName = "Standard_D3_v2"),
    pfenum_Standard_D4_v2 = 11 UMETA(DisplayName = "Standard_D4_v2"),
    pfenum_Standard_D5_v2 = 12 UMETA(DisplayName = "Standard_D5_v2"),
    pfenum_Standard_D2_v3 = 13 UMETA(DisplayName = "Standard_D2_v3"),
    pfenum_Standard_D4_v3 = 14 UMETA(DisplayName = "Standard_D4_v3"),
    pfenum_Standard_D8_v3 = 15 UMETA(DisplayName = "Standard_D8_v3"),
    pfenum_Standard_D16_v3 = 16 UMETA(DisplayName = "Standard_D16_v3"),
    pfenum_Standard_F1 = 17 UMETA(DisplayName = "Standard_F1"),
    pfenum_Standard_F2 = 18 UMETA(DisplayName = "Standard_F2"),
    pfenum_Standard_F4 = 19 UMETA(DisplayName = "Standard_F4"),
    pfenum_Standard_F8 = 20 UMETA(DisplayName = "Standard_F8"),
    pfenum_Standard_F16 = 21 UMETA(DisplayName = "Standard_F16"),
    pfenum_Standard_F2s_v2 = 22 UMETA(DisplayName = "Standard_F2s_v2"),
    pfenum_Standard_F4s_v2 = 23 UMETA(DisplayName = "Standard_F4s_v2"),
    pfenum_Standard_F8s_v2 = 24 UMETA(DisplayName = "Standard_F8s_v2"),
    pfenum_Standard_F16s_v2 = 25 UMETA(DisplayName = "Standard_F16s_v2"),
    pfenum_Standard_D2as_v4 = 26 UMETA(DisplayName = "Standard_D2as_v4"),
    pfenum_Standard_D4as_v4 = 27 UMETA(DisplayName = "Standard_D4as_v4"),
    pfenum_Standard_D8as_v4 = 28 UMETA(DisplayName = "Standard_D8as_v4"),
    pfenum_Standard_D16as_v4 = 29 UMETA(DisplayName = "Standard_D16as_v4"),
    pfenum_Standard_D2a_v4 = 30 UMETA(DisplayName = "Standard_D2a_v4"),
    pfenum_Standard_D4a_v4 = 31 UMETA(DisplayName = "Standard_D4a_v4"),
    pfenum_Standard_D8a_v4 = 32 UMETA(DisplayName = "Standard_D8a_v4"),
    pfenum_Standard_D16a_v4 = 33 UMETA(DisplayName = "Standard_D16a_v4"),
    pfenum_Standard_D2ads_v5 = 34 UMETA(DisplayName = "Standard_D2ads_v5"),
    pfenum_Standard_D4ads_v5 = 35 UMETA(DisplayName = "Standard_D4ads_v5"),
    pfenum_Standard_D8ads_v5 = 36 UMETA(DisplayName = "Standard_D8ads_v5"),
    pfenum_Standard_D16ads_v5 = 37 UMETA(DisplayName = "Standard_D16ads_v5"),
    pfenum_Standard_E2a_v4 = 38 UMETA(DisplayName = "Standard_E2a_v4"),
    pfenum_Standard_E4a_v4 = 39 UMETA(DisplayName = "Standard_E4a_v4"),
    pfenum_Standard_E8a_v4 = 40 UMETA(DisplayName = "Standard_E8a_v4"),
    pfenum_Standard_E16a_v4 = 41 UMETA(DisplayName = "Standard_E16a_v4"),
    pfenum_Standard_E2as_v4 = 42 UMETA(DisplayName = "Standard_E2as_v4"),
    pfenum_Standard_E4as_v4 = 43 UMETA(DisplayName = "Standard_E4as_v4"),
    pfenum_Standard_E8as_v4 = 44 UMETA(DisplayName = "Standard_E8as_v4"),
    pfenum_Standard_E16as_v4 = 45 UMETA(DisplayName = "Standard_E16as_v4"),
    pfenum_Standard_D2s_v3 = 46 UMETA(DisplayName = "Standard_D2s_v3"),
    pfenum_Standard_D4s_v3 = 47 UMETA(DisplayName = "Standard_D4s_v3"),
    pfenum_Standard_D8s_v3 = 48 UMETA(DisplayName = "Standard_D8s_v3"),
    pfenum_Standard_D16s_v3 = 49 UMETA(DisplayName = "Standard_D16s_v3"),
    pfenum_Standard_DS1_v2 = 50 UMETA(DisplayName = "Standard_DS1_v2"),
    pfenum_Standard_DS2_v2 = 51 UMETA(DisplayName = "Standard_DS2_v2"),
    pfenum_Standard_DS3_v2 = 52 UMETA(DisplayName = "Standard_DS3_v2"),
    pfenum_Standard_DS4_v2 = 53 UMETA(DisplayName = "Standard_DS4_v2"),
    pfenum_Standard_DS5_v2 = 54 UMETA(DisplayName = "Standard_DS5_v2"),
    pfenum_Standard_NC4as_T4_v3 = 55 UMETA(DisplayName = "Standard_NC4as_T4_v3"),
    pfenum_Standard_D2d_v4 = 56 UMETA(DisplayName = "Standard_D2d_v4"),
    pfenum_Standard_D4d_v4 = 57 UMETA(DisplayName = "Standard_D4d_v4"),
    pfenum_Standard_D8d_v4 = 58 UMETA(DisplayName = "Standard_D8d_v4"),
    pfenum_Standard_D16d_v4 = 59 UMETA(DisplayName = "Standard_D16d_v4"),
    pfenum_Standard_D2ds_v4 = 60 UMETA(DisplayName = "Standard_D2ds_v4"),
    pfenum_Standard_D4ds_v4 = 61 UMETA(DisplayName = "Standard_D4ds_v4"),
    pfenum_Standard_D8ds_v4 = 62 UMETA(DisplayName = "Standard_D8ds_v4"),
    pfenum_Standard_D16ds_v4 = 63 UMETA(DisplayName = "Standard_D16ds_v4"),
    pfenum_Standard_HB120_16rs_v3 = 64 UMETA(DisplayName = "Standard_HB120_16rs_v3"),
    pfenum_Standard_HB120_32rs_v3 = 65 UMETA(DisplayName = "Standard_HB120_32rs_v3"),
    pfenum_Standard_HB120_64rs_v3 = 66 UMETA(DisplayName = "Standard_HB120_64rs_v3"),
    pfenum_Standard_HB120_96rs_v3 = 67 UMETA(DisplayName = "Standard_HB120_96rs_v3"),
    pfenum_Standard_HB120rs_v3 = 68 UMETA(DisplayName = "Standard_HB120rs_v3"),
};

/** CancellationReason */

UENUM(BlueprintType)
enum class ECancellationReason : uint8
{
    pfenum_Requested = 0 UMETA(DisplayName = "Requested"),
    pfenum_Internal = 1 UMETA(DisplayName = "Internal"),
    pfenum_Timeout = 2 UMETA(DisplayName = "Timeout"),
};

/** ContainerFlavor */

UENUM(BlueprintType)
enum class EContainerFlavor : uint8
{
    pfenum_ManagedWindowsServerCore = 0 UMETA(DisplayName = "ManagedWindowsServerCore"),
    pfenum_CustomLinux = 1 UMETA(DisplayName = "CustomLinux"),
    pfenum_ManagedWindowsServerCorePreview = 2 UMETA(DisplayName = "ManagedWindowsServerCorePreview"),
    pfenum_Invalid = 3 UMETA(DisplayName = "Invalid"),
};

/** DirectPeerConnectivityOptions */

UENUM(BlueprintType)
enum class EDirectPeerConnectivityOptions : uint8
{
    pfenum_None = 0 UMETA(DisplayName = "None"),
    pfenum_SamePlatformType = 1 UMETA(DisplayName = "SamePlatformType"),
    pfenum_DifferentPlatformType = 2 UMETA(DisplayName = "DifferentPlatformType"),
    pfenum_AnyPlatformType = 3 UMETA(DisplayName = "AnyPlatformType"),
    pfenum_SameEntityLoginProvider = 4 UMETA(DisplayName = "SameEntityLoginProvider"),
    pfenum_DifferentEntityLoginProvider = 5 UMETA(DisplayName = "DifferentEntityLoginProvider"),
    pfenum_AnyEntityLoginProvider = 6 UMETA(DisplayName = "AnyEntityLoginProvider"),
    pfenum_AnyPlatformTypeAndEntityLoginProvider = 7 UMETA(DisplayName = "AnyPlatformTypeAndEntityLoginProvider"),
};

/** MembershipLock */

UENUM(BlueprintType)
enum class EMembershipLock : uint8
{
    pfenum_Unlocked = 0 UMETA(DisplayName = "Unlocked"),
    pfenum_Locked = 1 UMETA(DisplayName = "Locked"),
};

/** OsPlatform */

UENUM(BlueprintType)
enum class EOsPlatform : uint8
{
    pfenum_Windows = 0 UMETA(DisplayName = "Windows"),
    pfenum_Linux = 1 UMETA(DisplayName = "Linux"),
};

/** OwnerMigrationPolicy */

UENUM(BlueprintType)
enum class EOwnerMigrationPolicy : uint8
{
    pfenum_None = 0 UMETA(DisplayName = "None"),
    pfenum_Automatic = 1 UMETA(DisplayName = "Automatic"),
    pfenum_Manual = 2 UMETA(DisplayName = "Manual"),
    pfenum_Server = 3 UMETA(DisplayName = "Server"),
};

/** PartyInvitationRevocability */

UENUM(BlueprintType)
enum class EPartyInvitationRevocability : uint8
{
    pfenum_Creator = 0 UMETA(DisplayName = "Creator"),
    pfenum_Anyone = 1 UMETA(DisplayName = "Anyone"),
};

/** ProtocolType */

UENUM(BlueprintType)
enum class EProtocolType : uint8
{
    pfenum_TCP = 0 UMETA(DisplayName = "TCP"),
    pfenum_UDP = 1 UMETA(DisplayName = "UDP"),
};

/** RoutingType */

UENUM(BlueprintType)
enum class ERoutingType : uint8
{
    pfenum_Microsoft = 0 UMETA(DisplayName = "Microsoft"),
    pfenum_Internet = 1 UMETA(DisplayName = "Internet"),
};

/** ServerType */

UENUM(BlueprintType)
enum class EServerType : uint8
{
    pfenum_Container = 0 UMETA(DisplayName = "Container"),
    pfenum_Process = 1 UMETA(DisplayName = "Process"),
};

/** SubscriptionType */

UENUM(BlueprintType)
enum class ESubscriptionType : uint8
{
    pfenum_LobbyChange = 0 UMETA(DisplayName = "LobbyChange"),
    pfenum_LobbyInvite = 1 UMETA(DisplayName = "LobbyInvite"),
};

/** TitleMultiplayerServerEnabledStatus */

UENUM(BlueprintType)
enum class ETitleMultiplayerServerEnabledStatus : uint8
{
    pfenum_Initializing = 0 UMETA(DisplayName = "Initializing"),
    pfenum_Enabled = 1 UMETA(DisplayName = "Enabled"),
    pfenum_Disabled = 2 UMETA(DisplayName = "Disabled"),
};

