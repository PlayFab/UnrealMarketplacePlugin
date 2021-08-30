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
    UEnum* enumPtr = FindObject<UEnum>(ANY_PACKAGE, *enumTypeName, true);
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
#if ENGINE_MINOR_VERSION < 16
    output = (EnumType)enumPtr->FindEnumIndex(FName(*fullInput));
#else
    output = (EnumType)enumPtr->GetIndexByName(FName(*fullInput));
#endif
    return true;
}

template<typename EnumType>
static FORCEINLINE bool GetEnumValueToString(const FString& enumTypeName, const EnumType& input, FString& output)
{
    const UEnum* enumPtr = FindObject<UEnum>(ANY_PACKAGE, *enumTypeName, true);
    if (!enumPtr)
    {
        output = FString("0");
        return false;
    }

#if ENGINE_MINOR_VERSION < 16
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
    pfenum_Email UMETA(DisplayName = "Email"),
};

/** Conditionals */

UENUM(BlueprintType)
enum class EConditionals : uint8
{
    pfenum_Any UMETA(DisplayName = "Any"),
    pfenum_True UMETA(DisplayName = "True"),
    pfenum_False UMETA(DisplayName = "False"),
};

/** ContinentCode */

UENUM(BlueprintType)
enum class EContinentCode : uint8
{
    pfenum_AF UMETA(DisplayName = "AF"),
    pfenum_AN UMETA(DisplayName = "AN"),
    pfenum_AS UMETA(DisplayName = "AS"),
    pfenum_EU UMETA(DisplayName = "EU"),
    pfenum_NA UMETA(DisplayName = "NA"),
    pfenum_OC UMETA(DisplayName = "OC"),
    pfenum_SA UMETA(DisplayName = "SA"),
};

/** CountryCode */

UENUM(BlueprintType)
enum class ECountryCode : uint8
{
    pfenum_AF UMETA(DisplayName = "AF"),
    pfenum_AX UMETA(DisplayName = "AX"),
    pfenum_AL UMETA(DisplayName = "AL"),
    pfenum_DZ UMETA(DisplayName = "DZ"),
    pfenum_AS UMETA(DisplayName = "AS"),
    pfenum_AD UMETA(DisplayName = "AD"),
    pfenum_AO UMETA(DisplayName = "AO"),
    pfenum_AI UMETA(DisplayName = "AI"),
    pfenum_AQ UMETA(DisplayName = "AQ"),
    pfenum_AG UMETA(DisplayName = "AG"),
    pfenum_AR UMETA(DisplayName = "AR"),
    pfenum_AM UMETA(DisplayName = "AM"),
    pfenum_AW UMETA(DisplayName = "AW"),
    pfenum_AU UMETA(DisplayName = "AU"),
    pfenum_AT UMETA(DisplayName = "AT"),
    pfenum_AZ UMETA(DisplayName = "AZ"),
    pfenum_BS UMETA(DisplayName = "BS"),
    pfenum_BH UMETA(DisplayName = "BH"),
    pfenum_BD UMETA(DisplayName = "BD"),
    pfenum_BB UMETA(DisplayName = "BB"),
    pfenum_BY UMETA(DisplayName = "BY"),
    pfenum_BE UMETA(DisplayName = "BE"),
    pfenum_BZ UMETA(DisplayName = "BZ"),
    pfenum_BJ UMETA(DisplayName = "BJ"),
    pfenum_BM UMETA(DisplayName = "BM"),
    pfenum_BT UMETA(DisplayName = "BT"),
    pfenum_BO UMETA(DisplayName = "BO"),
    pfenum_BQ UMETA(DisplayName = "BQ"),
    pfenum_BA UMETA(DisplayName = "BA"),
    pfenum_BW UMETA(DisplayName = "BW"),
    pfenum_BV UMETA(DisplayName = "BV"),
    pfenum_BR UMETA(DisplayName = "BR"),
    pfenum_IO UMETA(DisplayName = "IO"),
    pfenum_BN UMETA(DisplayName = "BN"),
    pfenum_BG UMETA(DisplayName = "BG"),
    pfenum_BF UMETA(DisplayName = "BF"),
    pfenum_BI UMETA(DisplayName = "BI"),
    pfenum_KH UMETA(DisplayName = "KH"),
    pfenum_CM UMETA(DisplayName = "CM"),
    pfenum_CA UMETA(DisplayName = "CA"),
    pfenum_CV UMETA(DisplayName = "CV"),
    pfenum_KY UMETA(DisplayName = "KY"),
    pfenum_CF UMETA(DisplayName = "CF"),
    pfenum_TD UMETA(DisplayName = "TD"),
    pfenum_CL UMETA(DisplayName = "CL"),
    pfenum_CN UMETA(DisplayName = "CN"),
    pfenum_CX UMETA(DisplayName = "CX"),
    pfenum_CC UMETA(DisplayName = "CC"),
    pfenum_CO UMETA(DisplayName = "CO"),
    pfenum_KM UMETA(DisplayName = "KM"),
    pfenum_CG UMETA(DisplayName = "CG"),
    pfenum_CD UMETA(DisplayName = "CD"),
    pfenum_CK UMETA(DisplayName = "CK"),
    pfenum_CR UMETA(DisplayName = "CR"),
    pfenum_CI UMETA(DisplayName = "CI"),
    pfenum_HR UMETA(DisplayName = "HR"),
    pfenum_CU UMETA(DisplayName = "CU"),
    pfenum_CW UMETA(DisplayName = "CW"),
    pfenum_CY UMETA(DisplayName = "CY"),
    pfenum_CZ UMETA(DisplayName = "CZ"),
    pfenum_DK UMETA(DisplayName = "DK"),
    pfenum_DJ UMETA(DisplayName = "DJ"),
    pfenum_DM UMETA(DisplayName = "DM"),
    pfenum_DO UMETA(DisplayName = "DO"),
    pfenum_EC UMETA(DisplayName = "EC"),
    pfenum_EG UMETA(DisplayName = "EG"),
    pfenum_SV UMETA(DisplayName = "SV"),
    pfenum_GQ UMETA(DisplayName = "GQ"),
    pfenum_ER UMETA(DisplayName = "ER"),
    pfenum_EE UMETA(DisplayName = "EE"),
    pfenum_ET UMETA(DisplayName = "ET"),
    pfenum_FK UMETA(DisplayName = "FK"),
    pfenum_FO UMETA(DisplayName = "FO"),
    pfenum_FJ UMETA(DisplayName = "FJ"),
    pfenum_FI UMETA(DisplayName = "FI"),
    pfenum_FR UMETA(DisplayName = "FR"),
    pfenum_GF UMETA(DisplayName = "GF"),
    pfenum_PF UMETA(DisplayName = "PF"),
    pfenum_TF UMETA(DisplayName = "TF"),
    pfenum_GA UMETA(DisplayName = "GA"),
    pfenum_GM UMETA(DisplayName = "GM"),
    pfenum_GE UMETA(DisplayName = "GE"),
    pfenum_DE UMETA(DisplayName = "DE"),
    pfenum_GH UMETA(DisplayName = "GH"),
    pfenum_GI UMETA(DisplayName = "GI"),
    pfenum_GR UMETA(DisplayName = "GR"),
    pfenum_GL UMETA(DisplayName = "GL"),
    pfenum_GD UMETA(DisplayName = "GD"),
    pfenum_GP UMETA(DisplayName = "GP"),
    pfenum_GU UMETA(DisplayName = "GU"),
    pfenum_GT UMETA(DisplayName = "GT"),
    pfenum_GG UMETA(DisplayName = "GG"),
    pfenum_GN UMETA(DisplayName = "GN"),
    pfenum_GW UMETA(DisplayName = "GW"),
    pfenum_GY UMETA(DisplayName = "GY"),
    pfenum_HT UMETA(DisplayName = "HT"),
    pfenum_HM UMETA(DisplayName = "HM"),
    pfenum_VA UMETA(DisplayName = "VA"),
    pfenum_HN UMETA(DisplayName = "HN"),
    pfenum_HK UMETA(DisplayName = "HK"),
    pfenum_HU UMETA(DisplayName = "HU"),
    pfenum_IS UMETA(DisplayName = "IS"),
    pfenum_IN UMETA(DisplayName = "IN"),
    pfenum_ID UMETA(DisplayName = "ID"),
    pfenum_IR UMETA(DisplayName = "IR"),
    pfenum_IQ UMETA(DisplayName = "IQ"),
    pfenum_IE UMETA(DisplayName = "IE"),
    pfenum_IM UMETA(DisplayName = "IM"),
    pfenum_IL UMETA(DisplayName = "IL"),
    pfenum_IT UMETA(DisplayName = "IT"),
    pfenum_JM UMETA(DisplayName = "JM"),
    pfenum_JP UMETA(DisplayName = "JP"),
    pfenum_JE UMETA(DisplayName = "JE"),
    pfenum_JO UMETA(DisplayName = "JO"),
    pfenum_KZ UMETA(DisplayName = "KZ"),
    pfenum_KE UMETA(DisplayName = "KE"),
    pfenum_KI UMETA(DisplayName = "KI"),
    pfenum_KP UMETA(DisplayName = "KP"),
    pfenum_KR UMETA(DisplayName = "KR"),
    pfenum_KW UMETA(DisplayName = "KW"),
    pfenum_KG UMETA(DisplayName = "KG"),
    pfenum_LA UMETA(DisplayName = "LA"),
    pfenum_LV UMETA(DisplayName = "LV"),
    pfenum_LB UMETA(DisplayName = "LB"),
    pfenum_LS UMETA(DisplayName = "LS"),
    pfenum_LR UMETA(DisplayName = "LR"),
    pfenum_LY UMETA(DisplayName = "LY"),
    pfenum_LI UMETA(DisplayName = "LI"),
    pfenum_LT UMETA(DisplayName = "LT"),
    pfenum_LU UMETA(DisplayName = "LU"),
    pfenum_MO UMETA(DisplayName = "MO"),
    pfenum_MK UMETA(DisplayName = "MK"),
    pfenum_MG UMETA(DisplayName = "MG"),
    pfenum_MW UMETA(DisplayName = "MW"),
    pfenum_MY UMETA(DisplayName = "MY"),
    pfenum_MV UMETA(DisplayName = "MV"),
    pfenum_ML UMETA(DisplayName = "ML"),
    pfenum_MT UMETA(DisplayName = "MT"),
    pfenum_MH UMETA(DisplayName = "MH"),
    pfenum_MQ UMETA(DisplayName = "MQ"),
    pfenum_MR UMETA(DisplayName = "MR"),
    pfenum_MU UMETA(DisplayName = "MU"),
    pfenum_YT UMETA(DisplayName = "YT"),
    pfenum_MX UMETA(DisplayName = "MX"),
    pfenum_FM UMETA(DisplayName = "FM"),
    pfenum_MD UMETA(DisplayName = "MD"),
    pfenum_MC UMETA(DisplayName = "MC"),
    pfenum_MN UMETA(DisplayName = "MN"),
    pfenum_ME UMETA(DisplayName = "ME"),
    pfenum_MS UMETA(DisplayName = "MS"),
    pfenum_MA UMETA(DisplayName = "MA"),
    pfenum_MZ UMETA(DisplayName = "MZ"),
    pfenum_MM UMETA(DisplayName = "MM"),
    pfenum_NA UMETA(DisplayName = "NA"),
    pfenum_NR UMETA(DisplayName = "NR"),
    pfenum_NP UMETA(DisplayName = "NP"),
    pfenum_NL UMETA(DisplayName = "NL"),
    pfenum_NC UMETA(DisplayName = "NC"),
    pfenum_NZ UMETA(DisplayName = "NZ"),
    pfenum_NI UMETA(DisplayName = "NI"),
    pfenum_NE UMETA(DisplayName = "NE"),
    pfenum_NG UMETA(DisplayName = "NG"),
    pfenum_NU UMETA(DisplayName = "NU"),
    pfenum_NF UMETA(DisplayName = "NF"),
    pfenum_MP UMETA(DisplayName = "MP"),
    pfenum_NO UMETA(DisplayName = "NO"),
    pfenum_OM UMETA(DisplayName = "OM"),
    pfenum_PK UMETA(DisplayName = "PK"),
    pfenum_PW UMETA(DisplayName = "PW"),
    pfenum_PS UMETA(DisplayName = "PS"),
    pfenum_PA UMETA(DisplayName = "PA"),
    pfenum_PG UMETA(DisplayName = "PG"),
    pfenum_PY UMETA(DisplayName = "PY"),
    pfenum_PE UMETA(DisplayName = "PE"),
    pfenum_PH UMETA(DisplayName = "PH"),
    pfenum_PN UMETA(DisplayName = "PN"),
    pfenum_PL UMETA(DisplayName = "PL"),
    pfenum_PT UMETA(DisplayName = "PT"),
    pfenum_PR UMETA(DisplayName = "PR"),
    pfenum_QA UMETA(DisplayName = "QA"),
    pfenum_RE UMETA(DisplayName = "RE"),
    pfenum_RO UMETA(DisplayName = "RO"),
    pfenum_RU UMETA(DisplayName = "RU"),
    pfenum_RW UMETA(DisplayName = "RW"),
    pfenum_BL UMETA(DisplayName = "BL"),
    pfenum_SH UMETA(DisplayName = "SH"),
    pfenum_KN UMETA(DisplayName = "KN"),
    pfenum_LC UMETA(DisplayName = "LC"),
    pfenum_MF UMETA(DisplayName = "MF"),
    pfenum_PM UMETA(DisplayName = "PM"),
    pfenum_VC UMETA(DisplayName = "VC"),
    pfenum_WS UMETA(DisplayName = "WS"),
    pfenum_SM UMETA(DisplayName = "SM"),
    pfenum_ST UMETA(DisplayName = "ST"),
    pfenum_SA UMETA(DisplayName = "SA"),
    pfenum_SN UMETA(DisplayName = "SN"),
    pfenum_RS UMETA(DisplayName = "RS"),
    pfenum_SC UMETA(DisplayName = "SC"),
    pfenum_SL UMETA(DisplayName = "SL"),
    pfenum_SG UMETA(DisplayName = "SG"),
    pfenum_SX UMETA(DisplayName = "SX"),
    pfenum_SK UMETA(DisplayName = "SK"),
    pfenum_SI UMETA(DisplayName = "SI"),
    pfenum_SB UMETA(DisplayName = "SB"),
    pfenum_SO UMETA(DisplayName = "SO"),
    pfenum_ZA UMETA(DisplayName = "ZA"),
    pfenum_GS UMETA(DisplayName = "GS"),
    pfenum_SS UMETA(DisplayName = "SS"),
    pfenum_ES UMETA(DisplayName = "ES"),
    pfenum_LK UMETA(DisplayName = "LK"),
    pfenum_SD UMETA(DisplayName = "SD"),
    pfenum_SR UMETA(DisplayName = "SR"),
    pfenum_SJ UMETA(DisplayName = "SJ"),
    pfenum_SZ UMETA(DisplayName = "SZ"),
    pfenum_SE UMETA(DisplayName = "SE"),
    pfenum_CH UMETA(DisplayName = "CH"),
    pfenum_SY UMETA(DisplayName = "SY"),
    pfenum_TW UMETA(DisplayName = "TW"),
    pfenum_TJ UMETA(DisplayName = "TJ"),
    pfenum_TZ UMETA(DisplayName = "TZ"),
    pfenum_TH UMETA(DisplayName = "TH"),
    pfenum_TL UMETA(DisplayName = "TL"),
    pfenum_TG UMETA(DisplayName = "TG"),
    pfenum_TK UMETA(DisplayName = "TK"),
    pfenum_TO UMETA(DisplayName = "TO"),
    pfenum_TT UMETA(DisplayName = "TT"),
    pfenum_TN UMETA(DisplayName = "TN"),
    pfenum_TR UMETA(DisplayName = "TR"),
    pfenum_TM UMETA(DisplayName = "TM"),
    pfenum_TC UMETA(DisplayName = "TC"),
    pfenum_TV UMETA(DisplayName = "TV"),
    pfenum_UG UMETA(DisplayName = "UG"),
    pfenum_UA UMETA(DisplayName = "UA"),
    pfenum_AE UMETA(DisplayName = "AE"),
    pfenum_GB UMETA(DisplayName = "GB"),
    pfenum_US UMETA(DisplayName = "US"),
    pfenum_UM UMETA(DisplayName = "UM"),
    pfenum_UY UMETA(DisplayName = "UY"),
    pfenum_UZ UMETA(DisplayName = "UZ"),
    pfenum_VU UMETA(DisplayName = "VU"),
    pfenum_VE UMETA(DisplayName = "VE"),
    pfenum_VN UMETA(DisplayName = "VN"),
    pfenum_VG UMETA(DisplayName = "VG"),
    pfenum_VI UMETA(DisplayName = "VI"),
    pfenum_WF UMETA(DisplayName = "WF"),
    pfenum_EH UMETA(DisplayName = "EH"),
    pfenum_YE UMETA(DisplayName = "YE"),
    pfenum_ZM UMETA(DisplayName = "ZM"),
    pfenum_ZW UMETA(DisplayName = "ZW"),
};

/** Currency */

UENUM(BlueprintType)
enum class ECurrency : uint8
{
    pfenum_AED UMETA(DisplayName = "AED"),
    pfenum_AFN UMETA(DisplayName = "AFN"),
    pfenum_ALL UMETA(DisplayName = "ALL"),
    pfenum_AMD UMETA(DisplayName = "AMD"),
    pfenum_ANG UMETA(DisplayName = "ANG"),
    pfenum_AOA UMETA(DisplayName = "AOA"),
    pfenum_ARS UMETA(DisplayName = "ARS"),
    pfenum_AUD UMETA(DisplayName = "AUD"),
    pfenum_AWG UMETA(DisplayName = "AWG"),
    pfenum_AZN UMETA(DisplayName = "AZN"),
    pfenum_BAM UMETA(DisplayName = "BAM"),
    pfenum_BBD UMETA(DisplayName = "BBD"),
    pfenum_BDT UMETA(DisplayName = "BDT"),
    pfenum_BGN UMETA(DisplayName = "BGN"),
    pfenum_BHD UMETA(DisplayName = "BHD"),
    pfenum_BIF UMETA(DisplayName = "BIF"),
    pfenum_BMD UMETA(DisplayName = "BMD"),
    pfenum_BND UMETA(DisplayName = "BND"),
    pfenum_BOB UMETA(DisplayName = "BOB"),
    pfenum_BRL UMETA(DisplayName = "BRL"),
    pfenum_BSD UMETA(DisplayName = "BSD"),
    pfenum_BTN UMETA(DisplayName = "BTN"),
    pfenum_BWP UMETA(DisplayName = "BWP"),
    pfenum_BYR UMETA(DisplayName = "BYR"),
    pfenum_BZD UMETA(DisplayName = "BZD"),
    pfenum_CAD UMETA(DisplayName = "CAD"),
    pfenum_CDF UMETA(DisplayName = "CDF"),
    pfenum_CHF UMETA(DisplayName = "CHF"),
    pfenum_CLP UMETA(DisplayName = "CLP"),
    pfenum_CNY UMETA(DisplayName = "CNY"),
    pfenum_COP UMETA(DisplayName = "COP"),
    pfenum_CRC UMETA(DisplayName = "CRC"),
    pfenum_CUC UMETA(DisplayName = "CUC"),
    pfenum_CUP UMETA(DisplayName = "CUP"),
    pfenum_CVE UMETA(DisplayName = "CVE"),
    pfenum_CZK UMETA(DisplayName = "CZK"),
    pfenum_DJF UMETA(DisplayName = "DJF"),
    pfenum_DKK UMETA(DisplayName = "DKK"),
    pfenum_DOP UMETA(DisplayName = "DOP"),
    pfenum_DZD UMETA(DisplayName = "DZD"),
    pfenum_EGP UMETA(DisplayName = "EGP"),
    pfenum_ERN UMETA(DisplayName = "ERN"),
    pfenum_ETB UMETA(DisplayName = "ETB"),
    pfenum_EUR UMETA(DisplayName = "EUR"),
    pfenum_FJD UMETA(DisplayName = "FJD"),
    pfenum_FKP UMETA(DisplayName = "FKP"),
    pfenum_GBP UMETA(DisplayName = "GBP"),
    pfenum_GEL UMETA(DisplayName = "GEL"),
    pfenum_GGP UMETA(DisplayName = "GGP"),
    pfenum_GHS UMETA(DisplayName = "GHS"),
    pfenum_GIP UMETA(DisplayName = "GIP"),
    pfenum_GMD UMETA(DisplayName = "GMD"),
    pfenum_GNF UMETA(DisplayName = "GNF"),
    pfenum_GTQ UMETA(DisplayName = "GTQ"),
    pfenum_GYD UMETA(DisplayName = "GYD"),
    pfenum_HKD UMETA(DisplayName = "HKD"),
    pfenum_HNL UMETA(DisplayName = "HNL"),
    pfenum_HRK UMETA(DisplayName = "HRK"),
    pfenum_HTG UMETA(DisplayName = "HTG"),
    pfenum_HUF UMETA(DisplayName = "HUF"),
    pfenum_IDR UMETA(DisplayName = "IDR"),
    pfenum_ILS UMETA(DisplayName = "ILS"),
    pfenum_IMP UMETA(DisplayName = "IMP"),
    pfenum_INR UMETA(DisplayName = "INR"),
    pfenum_IQD UMETA(DisplayName = "IQD"),
    pfenum_IRR UMETA(DisplayName = "IRR"),
    pfenum_ISK UMETA(DisplayName = "ISK"),
    pfenum_JEP UMETA(DisplayName = "JEP"),
    pfenum_JMD UMETA(DisplayName = "JMD"),
    pfenum_JOD UMETA(DisplayName = "JOD"),
    pfenum_JPY UMETA(DisplayName = "JPY"),
    pfenum_KES UMETA(DisplayName = "KES"),
    pfenum_KGS UMETA(DisplayName = "KGS"),
    pfenum_KHR UMETA(DisplayName = "KHR"),
    pfenum_KMF UMETA(DisplayName = "KMF"),
    pfenum_KPW UMETA(DisplayName = "KPW"),
    pfenum_KRW UMETA(DisplayName = "KRW"),
    pfenum_KWD UMETA(DisplayName = "KWD"),
    pfenum_KYD UMETA(DisplayName = "KYD"),
    pfenum_KZT UMETA(DisplayName = "KZT"),
    pfenum_LAK UMETA(DisplayName = "LAK"),
    pfenum_LBP UMETA(DisplayName = "LBP"),
    pfenum_LKR UMETA(DisplayName = "LKR"),
    pfenum_LRD UMETA(DisplayName = "LRD"),
    pfenum_LSL UMETA(DisplayName = "LSL"),
    pfenum_LYD UMETA(DisplayName = "LYD"),
    pfenum_MAD UMETA(DisplayName = "MAD"),
    pfenum_MDL UMETA(DisplayName = "MDL"),
    pfenum_MGA UMETA(DisplayName = "MGA"),
    pfenum_MKD UMETA(DisplayName = "MKD"),
    pfenum_MMK UMETA(DisplayName = "MMK"),
    pfenum_MNT UMETA(DisplayName = "MNT"),
    pfenum_MOP UMETA(DisplayName = "MOP"),
    pfenum_MRO UMETA(DisplayName = "MRO"),
    pfenum_MUR UMETA(DisplayName = "MUR"),
    pfenum_MVR UMETA(DisplayName = "MVR"),
    pfenum_MWK UMETA(DisplayName = "MWK"),
    pfenum_MXN UMETA(DisplayName = "MXN"),
    pfenum_MYR UMETA(DisplayName = "MYR"),
    pfenum_MZN UMETA(DisplayName = "MZN"),
    pfenum_NAD UMETA(DisplayName = "NAD"),
    pfenum_NGN UMETA(DisplayName = "NGN"),
    pfenum_NIO UMETA(DisplayName = "NIO"),
    pfenum_NOK UMETA(DisplayName = "NOK"),
    pfenum_NPR UMETA(DisplayName = "NPR"),
    pfenum_NZD UMETA(DisplayName = "NZD"),
    pfenum_OMR UMETA(DisplayName = "OMR"),
    pfenum_PAB UMETA(DisplayName = "PAB"),
    pfenum_PEN UMETA(DisplayName = "PEN"),
    pfenum_PGK UMETA(DisplayName = "PGK"),
    pfenum_PHP UMETA(DisplayName = "PHP"),
    pfenum_PKR UMETA(DisplayName = "PKR"),
    pfenum_PLN UMETA(DisplayName = "PLN"),
    pfenum_PYG UMETA(DisplayName = "PYG"),
    pfenum_QAR UMETA(DisplayName = "QAR"),
    pfenum_RON UMETA(DisplayName = "RON"),
    pfenum_RSD UMETA(DisplayName = "RSD"),
    pfenum_RUB UMETA(DisplayName = "RUB"),
    pfenum_RWF UMETA(DisplayName = "RWF"),
    pfenum_SAR UMETA(DisplayName = "SAR"),
    pfenum_SBD UMETA(DisplayName = "SBD"),
    pfenum_SCR UMETA(DisplayName = "SCR"),
    pfenum_SDG UMETA(DisplayName = "SDG"),
    pfenum_SEK UMETA(DisplayName = "SEK"),
    pfenum_SGD UMETA(DisplayName = "SGD"),
    pfenum_SHP UMETA(DisplayName = "SHP"),
    pfenum_SLL UMETA(DisplayName = "SLL"),
    pfenum_SOS UMETA(DisplayName = "SOS"),
    pfenum_SPL UMETA(DisplayName = "SPL"),
    pfenum_SRD UMETA(DisplayName = "SRD"),
    pfenum_STD UMETA(DisplayName = "STD"),
    pfenum_SVC UMETA(DisplayName = "SVC"),
    pfenum_SYP UMETA(DisplayName = "SYP"),
    pfenum_SZL UMETA(DisplayName = "SZL"),
    pfenum_THB UMETA(DisplayName = "THB"),
    pfenum_TJS UMETA(DisplayName = "TJS"),
    pfenum_TMT UMETA(DisplayName = "TMT"),
    pfenum_TND UMETA(DisplayName = "TND"),
    pfenum_TOP UMETA(DisplayName = "TOP"),
    pfenum_TRY UMETA(DisplayName = "TRY"),
    pfenum_TTD UMETA(DisplayName = "TTD"),
    pfenum_TVD UMETA(DisplayName = "TVD"),
    pfenum_TWD UMETA(DisplayName = "TWD"),
    pfenum_TZS UMETA(DisplayName = "TZS"),
    pfenum_UAH UMETA(DisplayName = "UAH"),
    pfenum_UGX UMETA(DisplayName = "UGX"),
    pfenum_USD UMETA(DisplayName = "USD"),
    pfenum_UYU UMETA(DisplayName = "UYU"),
    pfenum_UZS UMETA(DisplayName = "UZS"),
    pfenum_VEF UMETA(DisplayName = "VEF"),
    pfenum_VND UMETA(DisplayName = "VND"),
    pfenum_VUV UMETA(DisplayName = "VUV"),
    pfenum_WST UMETA(DisplayName = "WST"),
    pfenum_XAF UMETA(DisplayName = "XAF"),
    pfenum_XCD UMETA(DisplayName = "XCD"),
    pfenum_XDR UMETA(DisplayName = "XDR"),
    pfenum_XOF UMETA(DisplayName = "XOF"),
    pfenum_XPF UMETA(DisplayName = "XPF"),
    pfenum_YER UMETA(DisplayName = "YER"),
    pfenum_ZAR UMETA(DisplayName = "ZAR"),
    pfenum_ZMW UMETA(DisplayName = "ZMW"),
    pfenum_ZWD UMETA(DisplayName = "ZWD"),
};

/** EffectType */

UENUM(BlueprintType)
enum class EEffectType : uint8
{
    pfenum_Allow UMETA(DisplayName = "Allow"),
    pfenum_Deny UMETA(DisplayName = "Deny"),
};

/** EmailVerificationStatus */

UENUM(BlueprintType)
enum class EEmailVerificationStatus : uint8
{
    pfenum_Unverified UMETA(DisplayName = "Unverified"),
    pfenum_Pending UMETA(DisplayName = "Pending"),
    pfenum_Confirmed UMETA(DisplayName = "Confirmed"),
};

/** GameBuildStatus */

UENUM(BlueprintType)
enum class EGameBuildStatus : uint8
{
    pfenum_Available UMETA(DisplayName = "Available"),
    pfenum_Validating UMETA(DisplayName = "Validating"),
    pfenum_InvalidBuildPackage UMETA(DisplayName = "InvalidBuildPackage"),
    pfenum_Processing UMETA(DisplayName = "Processing"),
    pfenum_FailedToProcess UMETA(DisplayName = "FailedToProcess"),
};

/** LoginIdentityProvider */

UENUM(BlueprintType)
enum class ELoginIdentityProvider : uint8
{
    pfenum_Unknown UMETA(DisplayName = "Unknown"),
    pfenum_PlayFab UMETA(DisplayName = "PlayFab"),
    pfenum_Custom UMETA(DisplayName = "Custom"),
    pfenum_GameCenter UMETA(DisplayName = "GameCenter"),
    pfenum_GooglePlay UMETA(DisplayName = "GooglePlay"),
    pfenum_Steam UMETA(DisplayName = "Steam"),
    pfenum_XBoxLive UMETA(DisplayName = "XBoxLive"),
    pfenum_PSN UMETA(DisplayName = "PSN"),
    pfenum_Kongregate UMETA(DisplayName = "Kongregate"),
    pfenum_Facebook UMETA(DisplayName = "Facebook"),
    pfenum_IOSDevice UMETA(DisplayName = "IOSDevice"),
    pfenum_AndroidDevice UMETA(DisplayName = "AndroidDevice"),
    pfenum_Twitch UMETA(DisplayName = "Twitch"),
    pfenum_WindowsHello UMETA(DisplayName = "WindowsHello"),
    pfenum_GameServer UMETA(DisplayName = "GameServer"),
    pfenum_CustomServer UMETA(DisplayName = "CustomServer"),
    pfenum_NintendoSwitch UMETA(DisplayName = "NintendoSwitch"),
    pfenum_FacebookInstantGames UMETA(DisplayName = "FacebookInstantGames"),
    pfenum_OpenIdConnect UMETA(DisplayName = "OpenIdConnect"),
    pfenum_Apple UMETA(DisplayName = "Apple"),
    pfenum_NintendoSwitchAccount UMETA(DisplayName = "NintendoSwitchAccount"),
};

/** PushNotificationPlatform */

UENUM(BlueprintType)
enum class EPushNotificationPlatform : uint8
{
    pfenum_ApplePushNotificationService UMETA(DisplayName = "ApplePushNotificationService"),
    pfenum_GoogleCloudMessaging UMETA(DisplayName = "GoogleCloudMessaging"),
};

/** PushSetupPlatform */

UENUM(BlueprintType)
enum class EPushSetupPlatform : uint8
{
    pfenum_GCM UMETA(DisplayName = "GCM"),
    pfenum_APNS UMETA(DisplayName = "APNS"),
    pfenum_APNS_SANDBOX UMETA(DisplayName = "APNS_SANDBOX"),
};

/** Region */

UENUM(BlueprintType)
enum class ERegion : uint8
{
    pfenum_USCentral UMETA(DisplayName = "USCentral"),
    pfenum_USEast UMETA(DisplayName = "USEast"),
    pfenum_EUWest UMETA(DisplayName = "EUWest"),
    pfenum_Singapore UMETA(DisplayName = "Singapore"),
    pfenum_Japan UMETA(DisplayName = "Japan"),
    pfenum_Brazil UMETA(DisplayName = "Brazil"),
    pfenum_Australia UMETA(DisplayName = "Australia"),
};

/** ResolutionOutcome */

UENUM(BlueprintType)
enum class EResolutionOutcome : uint8
{
    pfenum_Revoke UMETA(DisplayName = "Revoke"),
    pfenum_Reinstate UMETA(DisplayName = "Reinstate"),
    pfenum_Manual UMETA(DisplayName = "Manual"),
};

/** ResultTableNodeType */

UENUM(BlueprintType)
enum class EResultTableNodeType : uint8
{
    pfenum_ItemId UMETA(DisplayName = "ItemId"),
    pfenum_TableId UMETA(DisplayName = "TableId"),
};

/** ScheduledTaskType */

UENUM(BlueprintType)
enum class EScheduledTaskType : uint8
{
    pfenum_CloudScript UMETA(DisplayName = "CloudScript"),
    pfenum_ActionsOnPlayerSegment UMETA(DisplayName = "ActionsOnPlayerSegment"),
    pfenum_CloudScriptAzureFunctions UMETA(DisplayName = "CloudScriptAzureFunctions"),
    pfenum_InsightsScheduledScaling UMETA(DisplayName = "InsightsScheduledScaling"),
};

/** SegmentCountryCode */

UENUM(BlueprintType)
enum class ESegmentCountryCode : uint8
{
    pfenum_AF UMETA(DisplayName = "AF"),
    pfenum_AX UMETA(DisplayName = "AX"),
    pfenum_AL UMETA(DisplayName = "AL"),
    pfenum_DZ UMETA(DisplayName = "DZ"),
    pfenum_AS UMETA(DisplayName = "AS"),
    pfenum_AD UMETA(DisplayName = "AD"),
    pfenum_AO UMETA(DisplayName = "AO"),
    pfenum_AI UMETA(DisplayName = "AI"),
    pfenum_AQ UMETA(DisplayName = "AQ"),
    pfenum_AG UMETA(DisplayName = "AG"),
    pfenum_AR UMETA(DisplayName = "AR"),
    pfenum_AM UMETA(DisplayName = "AM"),
    pfenum_AW UMETA(DisplayName = "AW"),
    pfenum_AU UMETA(DisplayName = "AU"),
    pfenum_AT UMETA(DisplayName = "AT"),
    pfenum_AZ UMETA(DisplayName = "AZ"),
    pfenum_BS UMETA(DisplayName = "BS"),
    pfenum_BH UMETA(DisplayName = "BH"),
    pfenum_BD UMETA(DisplayName = "BD"),
    pfenum_BB UMETA(DisplayName = "BB"),
    pfenum_BY UMETA(DisplayName = "BY"),
    pfenum_BE UMETA(DisplayName = "BE"),
    pfenum_BZ UMETA(DisplayName = "BZ"),
    pfenum_BJ UMETA(DisplayName = "BJ"),
    pfenum_BM UMETA(DisplayName = "BM"),
    pfenum_BT UMETA(DisplayName = "BT"),
    pfenum_BO UMETA(DisplayName = "BO"),
    pfenum_BQ UMETA(DisplayName = "BQ"),
    pfenum_BA UMETA(DisplayName = "BA"),
    pfenum_BW UMETA(DisplayName = "BW"),
    pfenum_BV UMETA(DisplayName = "BV"),
    pfenum_BR UMETA(DisplayName = "BR"),
    pfenum_IO UMETA(DisplayName = "IO"),
    pfenum_BN UMETA(DisplayName = "BN"),
    pfenum_BG UMETA(DisplayName = "BG"),
    pfenum_BF UMETA(DisplayName = "BF"),
    pfenum_BI UMETA(DisplayName = "BI"),
    pfenum_KH UMETA(DisplayName = "KH"),
    pfenum_CM UMETA(DisplayName = "CM"),
    pfenum_CA UMETA(DisplayName = "CA"),
    pfenum_CV UMETA(DisplayName = "CV"),
    pfenum_KY UMETA(DisplayName = "KY"),
    pfenum_CF UMETA(DisplayName = "CF"),
    pfenum_TD UMETA(DisplayName = "TD"),
    pfenum_CL UMETA(DisplayName = "CL"),
    pfenum_CN UMETA(DisplayName = "CN"),
    pfenum_CX UMETA(DisplayName = "CX"),
    pfenum_CC UMETA(DisplayName = "CC"),
    pfenum_CO UMETA(DisplayName = "CO"),
    pfenum_KM UMETA(DisplayName = "KM"),
    pfenum_CG UMETA(DisplayName = "CG"),
    pfenum_CD UMETA(DisplayName = "CD"),
    pfenum_CK UMETA(DisplayName = "CK"),
    pfenum_CR UMETA(DisplayName = "CR"),
    pfenum_CI UMETA(DisplayName = "CI"),
    pfenum_HR UMETA(DisplayName = "HR"),
    pfenum_CU UMETA(DisplayName = "CU"),
    pfenum_CW UMETA(DisplayName = "CW"),
    pfenum_CY UMETA(DisplayName = "CY"),
    pfenum_CZ UMETA(DisplayName = "CZ"),
    pfenum_DK UMETA(DisplayName = "DK"),
    pfenum_DJ UMETA(DisplayName = "DJ"),
    pfenum_DM UMETA(DisplayName = "DM"),
    pfenum_DO UMETA(DisplayName = "DO"),
    pfenum_EC UMETA(DisplayName = "EC"),
    pfenum_EG UMETA(DisplayName = "EG"),
    pfenum_SV UMETA(DisplayName = "SV"),
    pfenum_GQ UMETA(DisplayName = "GQ"),
    pfenum_ER UMETA(DisplayName = "ER"),
    pfenum_EE UMETA(DisplayName = "EE"),
    pfenum_ET UMETA(DisplayName = "ET"),
    pfenum_FK UMETA(DisplayName = "FK"),
    pfenum_FO UMETA(DisplayName = "FO"),
    pfenum_FJ UMETA(DisplayName = "FJ"),
    pfenum_FI UMETA(DisplayName = "FI"),
    pfenum_FR UMETA(DisplayName = "FR"),
    pfenum_GF UMETA(DisplayName = "GF"),
    pfenum_PF UMETA(DisplayName = "PF"),
    pfenum_TF UMETA(DisplayName = "TF"),
    pfenum_GA UMETA(DisplayName = "GA"),
    pfenum_GM UMETA(DisplayName = "GM"),
    pfenum_GE UMETA(DisplayName = "GE"),
    pfenum_DE UMETA(DisplayName = "DE"),
    pfenum_GH UMETA(DisplayName = "GH"),
    pfenum_GI UMETA(DisplayName = "GI"),
    pfenum_GR UMETA(DisplayName = "GR"),
    pfenum_GL UMETA(DisplayName = "GL"),
    pfenum_GD UMETA(DisplayName = "GD"),
    pfenum_GP UMETA(DisplayName = "GP"),
    pfenum_GU UMETA(DisplayName = "GU"),
    pfenum_GT UMETA(DisplayName = "GT"),
    pfenum_GG UMETA(DisplayName = "GG"),
    pfenum_GN UMETA(DisplayName = "GN"),
    pfenum_GW UMETA(DisplayName = "GW"),
    pfenum_GY UMETA(DisplayName = "GY"),
    pfenum_HT UMETA(DisplayName = "HT"),
    pfenum_HM UMETA(DisplayName = "HM"),
    pfenum_VA UMETA(DisplayName = "VA"),
    pfenum_HN UMETA(DisplayName = "HN"),
    pfenum_HK UMETA(DisplayName = "HK"),
    pfenum_HU UMETA(DisplayName = "HU"),
    pfenum_IS UMETA(DisplayName = "IS"),
    pfenum_IN UMETA(DisplayName = "IN"),
    pfenum_ID UMETA(DisplayName = "ID"),
    pfenum_IR UMETA(DisplayName = "IR"),
    pfenum_IQ UMETA(DisplayName = "IQ"),
    pfenum_IE UMETA(DisplayName = "IE"),
    pfenum_IM UMETA(DisplayName = "IM"),
    pfenum_IL UMETA(DisplayName = "IL"),
    pfenum_IT UMETA(DisplayName = "IT"),
    pfenum_JM UMETA(DisplayName = "JM"),
    pfenum_JP UMETA(DisplayName = "JP"),
    pfenum_JE UMETA(DisplayName = "JE"),
    pfenum_JO UMETA(DisplayName = "JO"),
    pfenum_KZ UMETA(DisplayName = "KZ"),
    pfenum_KE UMETA(DisplayName = "KE"),
    pfenum_KI UMETA(DisplayName = "KI"),
    pfenum_KP UMETA(DisplayName = "KP"),
    pfenum_KR UMETA(DisplayName = "KR"),
    pfenum_KW UMETA(DisplayName = "KW"),
    pfenum_KG UMETA(DisplayName = "KG"),
    pfenum_LA UMETA(DisplayName = "LA"),
    pfenum_LV UMETA(DisplayName = "LV"),
    pfenum_LB UMETA(DisplayName = "LB"),
    pfenum_LS UMETA(DisplayName = "LS"),
    pfenum_LR UMETA(DisplayName = "LR"),
    pfenum_LY UMETA(DisplayName = "LY"),
    pfenum_LI UMETA(DisplayName = "LI"),
    pfenum_LT UMETA(DisplayName = "LT"),
    pfenum_LU UMETA(DisplayName = "LU"),
    pfenum_MO UMETA(DisplayName = "MO"),
    pfenum_MK UMETA(DisplayName = "MK"),
    pfenum_MG UMETA(DisplayName = "MG"),
    pfenum_MW UMETA(DisplayName = "MW"),
    pfenum_MY UMETA(DisplayName = "MY"),
    pfenum_MV UMETA(DisplayName = "MV"),
    pfenum_ML UMETA(DisplayName = "ML"),
    pfenum_MT UMETA(DisplayName = "MT"),
    pfenum_MH UMETA(DisplayName = "MH"),
    pfenum_MQ UMETA(DisplayName = "MQ"),
    pfenum_MR UMETA(DisplayName = "MR"),
    pfenum_MU UMETA(DisplayName = "MU"),
    pfenum_YT UMETA(DisplayName = "YT"),
    pfenum_MX UMETA(DisplayName = "MX"),
    pfenum_FM UMETA(DisplayName = "FM"),
    pfenum_MD UMETA(DisplayName = "MD"),
    pfenum_MC UMETA(DisplayName = "MC"),
    pfenum_MN UMETA(DisplayName = "MN"),
    pfenum_ME UMETA(DisplayName = "ME"),
    pfenum_MS UMETA(DisplayName = "MS"),
    pfenum_MA UMETA(DisplayName = "MA"),
    pfenum_MZ UMETA(DisplayName = "MZ"),
    pfenum_MM UMETA(DisplayName = "MM"),
    pfenum_NA UMETA(DisplayName = "NA"),
    pfenum_NR UMETA(DisplayName = "NR"),
    pfenum_NP UMETA(DisplayName = "NP"),
    pfenum_NL UMETA(DisplayName = "NL"),
    pfenum_NC UMETA(DisplayName = "NC"),
    pfenum_NZ UMETA(DisplayName = "NZ"),
    pfenum_NI UMETA(DisplayName = "NI"),
    pfenum_NE UMETA(DisplayName = "NE"),
    pfenum_NG UMETA(DisplayName = "NG"),
    pfenum_NU UMETA(DisplayName = "NU"),
    pfenum_NF UMETA(DisplayName = "NF"),
    pfenum_MP UMETA(DisplayName = "MP"),
    pfenum_NO UMETA(DisplayName = "NO"),
    pfenum_OM UMETA(DisplayName = "OM"),
    pfenum_PK UMETA(DisplayName = "PK"),
    pfenum_PW UMETA(DisplayName = "PW"),
    pfenum_PS UMETA(DisplayName = "PS"),
    pfenum_PA UMETA(DisplayName = "PA"),
    pfenum_PG UMETA(DisplayName = "PG"),
    pfenum_PY UMETA(DisplayName = "PY"),
    pfenum_PE UMETA(DisplayName = "PE"),
    pfenum_PH UMETA(DisplayName = "PH"),
    pfenum_PN UMETA(DisplayName = "PN"),
    pfenum_PL UMETA(DisplayName = "PL"),
    pfenum_PT UMETA(DisplayName = "PT"),
    pfenum_PR UMETA(DisplayName = "PR"),
    pfenum_QA UMETA(DisplayName = "QA"),
    pfenum_RE UMETA(DisplayName = "RE"),
    pfenum_RO UMETA(DisplayName = "RO"),
    pfenum_RU UMETA(DisplayName = "RU"),
    pfenum_RW UMETA(DisplayName = "RW"),
    pfenum_BL UMETA(DisplayName = "BL"),
    pfenum_SH UMETA(DisplayName = "SH"),
    pfenum_KN UMETA(DisplayName = "KN"),
    pfenum_LC UMETA(DisplayName = "LC"),
    pfenum_MF UMETA(DisplayName = "MF"),
    pfenum_PM UMETA(DisplayName = "PM"),
    pfenum_VC UMETA(DisplayName = "VC"),
    pfenum_WS UMETA(DisplayName = "WS"),
    pfenum_SM UMETA(DisplayName = "SM"),
    pfenum_ST UMETA(DisplayName = "ST"),
    pfenum_SA UMETA(DisplayName = "SA"),
    pfenum_SN UMETA(DisplayName = "SN"),
    pfenum_RS UMETA(DisplayName = "RS"),
    pfenum_SC UMETA(DisplayName = "SC"),
    pfenum_SL UMETA(DisplayName = "SL"),
    pfenum_SG UMETA(DisplayName = "SG"),
    pfenum_SX UMETA(DisplayName = "SX"),
    pfenum_SK UMETA(DisplayName = "SK"),
    pfenum_SI UMETA(DisplayName = "SI"),
    pfenum_SB UMETA(DisplayName = "SB"),
    pfenum_SO UMETA(DisplayName = "SO"),
    pfenum_ZA UMETA(DisplayName = "ZA"),
    pfenum_GS UMETA(DisplayName = "GS"),
    pfenum_SS UMETA(DisplayName = "SS"),
    pfenum_ES UMETA(DisplayName = "ES"),
    pfenum_LK UMETA(DisplayName = "LK"),
    pfenum_SD UMETA(DisplayName = "SD"),
    pfenum_SR UMETA(DisplayName = "SR"),
    pfenum_SJ UMETA(DisplayName = "SJ"),
    pfenum_SZ UMETA(DisplayName = "SZ"),
    pfenum_SE UMETA(DisplayName = "SE"),
    pfenum_CH UMETA(DisplayName = "CH"),
    pfenum_SY UMETA(DisplayName = "SY"),
    pfenum_TW UMETA(DisplayName = "TW"),
    pfenum_TJ UMETA(DisplayName = "TJ"),
    pfenum_TZ UMETA(DisplayName = "TZ"),
    pfenum_TH UMETA(DisplayName = "TH"),
    pfenum_TL UMETA(DisplayName = "TL"),
    pfenum_TG UMETA(DisplayName = "TG"),
    pfenum_TK UMETA(DisplayName = "TK"),
    pfenum_TO UMETA(DisplayName = "TO"),
    pfenum_TT UMETA(DisplayName = "TT"),
    pfenum_TN UMETA(DisplayName = "TN"),
    pfenum_TR UMETA(DisplayName = "TR"),
    pfenum_TM UMETA(DisplayName = "TM"),
    pfenum_TC UMETA(DisplayName = "TC"),
    pfenum_TV UMETA(DisplayName = "TV"),
    pfenum_UG UMETA(DisplayName = "UG"),
    pfenum_UA UMETA(DisplayName = "UA"),
    pfenum_AE UMETA(DisplayName = "AE"),
    pfenum_GB UMETA(DisplayName = "GB"),
    pfenum_US UMETA(DisplayName = "US"),
    pfenum_UM UMETA(DisplayName = "UM"),
    pfenum_UY UMETA(DisplayName = "UY"),
    pfenum_UZ UMETA(DisplayName = "UZ"),
    pfenum_VU UMETA(DisplayName = "VU"),
    pfenum_VE UMETA(DisplayName = "VE"),
    pfenum_VN UMETA(DisplayName = "VN"),
    pfenum_VG UMETA(DisplayName = "VG"),
    pfenum_VI UMETA(DisplayName = "VI"),
    pfenum_WF UMETA(DisplayName = "WF"),
    pfenum_EH UMETA(DisplayName = "EH"),
    pfenum_YE UMETA(DisplayName = "YE"),
    pfenum_ZM UMETA(DisplayName = "ZM"),
    pfenum_ZW UMETA(DisplayName = "ZW"),
};

/** SegmentCurrency */

UENUM(BlueprintType)
enum class ESegmentCurrency : uint8
{
    pfenum_AED UMETA(DisplayName = "AED"),
    pfenum_AFN UMETA(DisplayName = "AFN"),
    pfenum_ALL UMETA(DisplayName = "ALL"),
    pfenum_AMD UMETA(DisplayName = "AMD"),
    pfenum_ANG UMETA(DisplayName = "ANG"),
    pfenum_AOA UMETA(DisplayName = "AOA"),
    pfenum_ARS UMETA(DisplayName = "ARS"),
    pfenum_AUD UMETA(DisplayName = "AUD"),
    pfenum_AWG UMETA(DisplayName = "AWG"),
    pfenum_AZN UMETA(DisplayName = "AZN"),
    pfenum_BAM UMETA(DisplayName = "BAM"),
    pfenum_BBD UMETA(DisplayName = "BBD"),
    pfenum_BDT UMETA(DisplayName = "BDT"),
    pfenum_BGN UMETA(DisplayName = "BGN"),
    pfenum_BHD UMETA(DisplayName = "BHD"),
    pfenum_BIF UMETA(DisplayName = "BIF"),
    pfenum_BMD UMETA(DisplayName = "BMD"),
    pfenum_BND UMETA(DisplayName = "BND"),
    pfenum_BOB UMETA(DisplayName = "BOB"),
    pfenum_BRL UMETA(DisplayName = "BRL"),
    pfenum_BSD UMETA(DisplayName = "BSD"),
    pfenum_BTN UMETA(DisplayName = "BTN"),
    pfenum_BWP UMETA(DisplayName = "BWP"),
    pfenum_BYR UMETA(DisplayName = "BYR"),
    pfenum_BZD UMETA(DisplayName = "BZD"),
    pfenum_CAD UMETA(DisplayName = "CAD"),
    pfenum_CDF UMETA(DisplayName = "CDF"),
    pfenum_CHF UMETA(DisplayName = "CHF"),
    pfenum_CLP UMETA(DisplayName = "CLP"),
    pfenum_CNY UMETA(DisplayName = "CNY"),
    pfenum_COP UMETA(DisplayName = "COP"),
    pfenum_CRC UMETA(DisplayName = "CRC"),
    pfenum_CUC UMETA(DisplayName = "CUC"),
    pfenum_CUP UMETA(DisplayName = "CUP"),
    pfenum_CVE UMETA(DisplayName = "CVE"),
    pfenum_CZK UMETA(DisplayName = "CZK"),
    pfenum_DJF UMETA(DisplayName = "DJF"),
    pfenum_DKK UMETA(DisplayName = "DKK"),
    pfenum_DOP UMETA(DisplayName = "DOP"),
    pfenum_DZD UMETA(DisplayName = "DZD"),
    pfenum_EGP UMETA(DisplayName = "EGP"),
    pfenum_ERN UMETA(DisplayName = "ERN"),
    pfenum_ETB UMETA(DisplayName = "ETB"),
    pfenum_EUR UMETA(DisplayName = "EUR"),
    pfenum_FJD UMETA(DisplayName = "FJD"),
    pfenum_FKP UMETA(DisplayName = "FKP"),
    pfenum_GBP UMETA(DisplayName = "GBP"),
    pfenum_GEL UMETA(DisplayName = "GEL"),
    pfenum_GGP UMETA(DisplayName = "GGP"),
    pfenum_GHS UMETA(DisplayName = "GHS"),
    pfenum_GIP UMETA(DisplayName = "GIP"),
    pfenum_GMD UMETA(DisplayName = "GMD"),
    pfenum_GNF UMETA(DisplayName = "GNF"),
    pfenum_GTQ UMETA(DisplayName = "GTQ"),
    pfenum_GYD UMETA(DisplayName = "GYD"),
    pfenum_HKD UMETA(DisplayName = "HKD"),
    pfenum_HNL UMETA(DisplayName = "HNL"),
    pfenum_HRK UMETA(DisplayName = "HRK"),
    pfenum_HTG UMETA(DisplayName = "HTG"),
    pfenum_HUF UMETA(DisplayName = "HUF"),
    pfenum_IDR UMETA(DisplayName = "IDR"),
    pfenum_ILS UMETA(DisplayName = "ILS"),
    pfenum_IMP UMETA(DisplayName = "IMP"),
    pfenum_INR UMETA(DisplayName = "INR"),
    pfenum_IQD UMETA(DisplayName = "IQD"),
    pfenum_IRR UMETA(DisplayName = "IRR"),
    pfenum_ISK UMETA(DisplayName = "ISK"),
    pfenum_JEP UMETA(DisplayName = "JEP"),
    pfenum_JMD UMETA(DisplayName = "JMD"),
    pfenum_JOD UMETA(DisplayName = "JOD"),
    pfenum_JPY UMETA(DisplayName = "JPY"),
    pfenum_KES UMETA(DisplayName = "KES"),
    pfenum_KGS UMETA(DisplayName = "KGS"),
    pfenum_KHR UMETA(DisplayName = "KHR"),
    pfenum_KMF UMETA(DisplayName = "KMF"),
    pfenum_KPW UMETA(DisplayName = "KPW"),
    pfenum_KRW UMETA(DisplayName = "KRW"),
    pfenum_KWD UMETA(DisplayName = "KWD"),
    pfenum_KYD UMETA(DisplayName = "KYD"),
    pfenum_KZT UMETA(DisplayName = "KZT"),
    pfenum_LAK UMETA(DisplayName = "LAK"),
    pfenum_LBP UMETA(DisplayName = "LBP"),
    pfenum_LKR UMETA(DisplayName = "LKR"),
    pfenum_LRD UMETA(DisplayName = "LRD"),
    pfenum_LSL UMETA(DisplayName = "LSL"),
    pfenum_LYD UMETA(DisplayName = "LYD"),
    pfenum_MAD UMETA(DisplayName = "MAD"),
    pfenum_MDL UMETA(DisplayName = "MDL"),
    pfenum_MGA UMETA(DisplayName = "MGA"),
    pfenum_MKD UMETA(DisplayName = "MKD"),
    pfenum_MMK UMETA(DisplayName = "MMK"),
    pfenum_MNT UMETA(DisplayName = "MNT"),
    pfenum_MOP UMETA(DisplayName = "MOP"),
    pfenum_MRO UMETA(DisplayName = "MRO"),
    pfenum_MUR UMETA(DisplayName = "MUR"),
    pfenum_MVR UMETA(DisplayName = "MVR"),
    pfenum_MWK UMETA(DisplayName = "MWK"),
    pfenum_MXN UMETA(DisplayName = "MXN"),
    pfenum_MYR UMETA(DisplayName = "MYR"),
    pfenum_MZN UMETA(DisplayName = "MZN"),
    pfenum_NAD UMETA(DisplayName = "NAD"),
    pfenum_NGN UMETA(DisplayName = "NGN"),
    pfenum_NIO UMETA(DisplayName = "NIO"),
    pfenum_NOK UMETA(DisplayName = "NOK"),
    pfenum_NPR UMETA(DisplayName = "NPR"),
    pfenum_NZD UMETA(DisplayName = "NZD"),
    pfenum_OMR UMETA(DisplayName = "OMR"),
    pfenum_PAB UMETA(DisplayName = "PAB"),
    pfenum_PEN UMETA(DisplayName = "PEN"),
    pfenum_PGK UMETA(DisplayName = "PGK"),
    pfenum_PHP UMETA(DisplayName = "PHP"),
    pfenum_PKR UMETA(DisplayName = "PKR"),
    pfenum_PLN UMETA(DisplayName = "PLN"),
    pfenum_PYG UMETA(DisplayName = "PYG"),
    pfenum_QAR UMETA(DisplayName = "QAR"),
    pfenum_RON UMETA(DisplayName = "RON"),
    pfenum_RSD UMETA(DisplayName = "RSD"),
    pfenum_RUB UMETA(DisplayName = "RUB"),
    pfenum_RWF UMETA(DisplayName = "RWF"),
    pfenum_SAR UMETA(DisplayName = "SAR"),
    pfenum_SBD UMETA(DisplayName = "SBD"),
    pfenum_SCR UMETA(DisplayName = "SCR"),
    pfenum_SDG UMETA(DisplayName = "SDG"),
    pfenum_SEK UMETA(DisplayName = "SEK"),
    pfenum_SGD UMETA(DisplayName = "SGD"),
    pfenum_SHP UMETA(DisplayName = "SHP"),
    pfenum_SLL UMETA(DisplayName = "SLL"),
    pfenum_SOS UMETA(DisplayName = "SOS"),
    pfenum_SPL UMETA(DisplayName = "SPL"),
    pfenum_SRD UMETA(DisplayName = "SRD"),
    pfenum_STD UMETA(DisplayName = "STD"),
    pfenum_SVC UMETA(DisplayName = "SVC"),
    pfenum_SYP UMETA(DisplayName = "SYP"),
    pfenum_SZL UMETA(DisplayName = "SZL"),
    pfenum_THB UMETA(DisplayName = "THB"),
    pfenum_TJS UMETA(DisplayName = "TJS"),
    pfenum_TMT UMETA(DisplayName = "TMT"),
    pfenum_TND UMETA(DisplayName = "TND"),
    pfenum_TOP UMETA(DisplayName = "TOP"),
    pfenum_TRY UMETA(DisplayName = "TRY"),
    pfenum_TTD UMETA(DisplayName = "TTD"),
    pfenum_TVD UMETA(DisplayName = "TVD"),
    pfenum_TWD UMETA(DisplayName = "TWD"),
    pfenum_TZS UMETA(DisplayName = "TZS"),
    pfenum_UAH UMETA(DisplayName = "UAH"),
    pfenum_UGX UMETA(DisplayName = "UGX"),
    pfenum_USD UMETA(DisplayName = "USD"),
    pfenum_UYU UMETA(DisplayName = "UYU"),
    pfenum_UZS UMETA(DisplayName = "UZS"),
    pfenum_VEF UMETA(DisplayName = "VEF"),
    pfenum_VND UMETA(DisplayName = "VND"),
    pfenum_VUV UMETA(DisplayName = "VUV"),
    pfenum_WST UMETA(DisplayName = "WST"),
    pfenum_XAF UMETA(DisplayName = "XAF"),
    pfenum_XCD UMETA(DisplayName = "XCD"),
    pfenum_XDR UMETA(DisplayName = "XDR"),
    pfenum_XOF UMETA(DisplayName = "XOF"),
    pfenum_XPF UMETA(DisplayName = "XPF"),
    pfenum_YER UMETA(DisplayName = "YER"),
    pfenum_ZAR UMETA(DisplayName = "ZAR"),
    pfenum_ZMW UMETA(DisplayName = "ZMW"),
    pfenum_ZWD UMETA(DisplayName = "ZWD"),
};

/** SegmentFilterComparison */

UENUM(BlueprintType)
enum class ESegmentFilterComparison : uint8
{
    pfenum_GreaterThan UMETA(DisplayName = "GreaterThan"),
    pfenum_LessThan UMETA(DisplayName = "LessThan"),
    pfenum_EqualTo UMETA(DisplayName = "EqualTo"),
    pfenum_NotEqualTo UMETA(DisplayName = "NotEqualTo"),
    pfenum_GreaterThanOrEqual UMETA(DisplayName = "GreaterThanOrEqual"),
    pfenum_LessThanOrEqual UMETA(DisplayName = "LessThanOrEqual"),
    pfenum_Exists UMETA(DisplayName = "Exists"),
    pfenum_Contains UMETA(DisplayName = "Contains"),
    pfenum_NotContains UMETA(DisplayName = "NotContains"),
};

/** SegmentLoginIdentityProvider */

UENUM(BlueprintType)
enum class ESegmentLoginIdentityProvider : uint8
{
    pfenum_Unknown UMETA(DisplayName = "Unknown"),
    pfenum_PlayFab UMETA(DisplayName = "PlayFab"),
    pfenum_Custom UMETA(DisplayName = "Custom"),
    pfenum_GameCenter UMETA(DisplayName = "GameCenter"),
    pfenum_GooglePlay UMETA(DisplayName = "GooglePlay"),
    pfenum_Steam UMETA(DisplayName = "Steam"),
    pfenum_XBoxLive UMETA(DisplayName = "XBoxLive"),
    pfenum_PSN UMETA(DisplayName = "PSN"),
    pfenum_Kongregate UMETA(DisplayName = "Kongregate"),
    pfenum_Facebook UMETA(DisplayName = "Facebook"),
    pfenum_IOSDevice UMETA(DisplayName = "IOSDevice"),
    pfenum_AndroidDevice UMETA(DisplayName = "AndroidDevice"),
    pfenum_Twitch UMETA(DisplayName = "Twitch"),
    pfenum_WindowsHello UMETA(DisplayName = "WindowsHello"),
    pfenum_GameServer UMETA(DisplayName = "GameServer"),
    pfenum_CustomServer UMETA(DisplayName = "CustomServer"),
    pfenum_NintendoSwitch UMETA(DisplayName = "NintendoSwitch"),
    pfenum_FacebookInstantGames UMETA(DisplayName = "FacebookInstantGames"),
    pfenum_OpenIdConnect UMETA(DisplayName = "OpenIdConnect"),
    pfenum_Apple UMETA(DisplayName = "Apple"),
    pfenum_NintendoSwitchAccount UMETA(DisplayName = "NintendoSwitchAccount"),
};

/** SegmentPushNotificationDevicePlatform */

UENUM(BlueprintType)
enum class ESegmentPushNotificationDevicePlatform : uint8
{
    pfenum_ApplePushNotificationService UMETA(DisplayName = "ApplePushNotificationService"),
    pfenum_GoogleCloudMessaging UMETA(DisplayName = "GoogleCloudMessaging"),
};

/** SourceType */

UENUM(BlueprintType)
enum class EPfSourceType : uint8
{
    pfenum_Admin UMETA(DisplayName = "Admin"),
    pfenum_BackEnd UMETA(DisplayName = "BackEnd"),
    pfenum_GameClient UMETA(DisplayName = "GameClient"),
    pfenum_GameServer UMETA(DisplayName = "GameServer"),
    pfenum_Partner UMETA(DisplayName = "Partner"),
    pfenum_Custom UMETA(DisplayName = "Custom"),
    pfenum_API UMETA(DisplayName = "API"),
};

/** StatisticAggregationMethod */

UENUM(BlueprintType)
enum class EStatisticAggregationMethod : uint8
{
    pfenum_Last UMETA(DisplayName = "Last"),
    pfenum_Min UMETA(DisplayName = "Min"),
    pfenum_Max UMETA(DisplayName = "Max"),
    pfenum_Sum UMETA(DisplayName = "Sum"),
};

/** StatisticResetIntervalOption */

UENUM(BlueprintType)
enum class EStatisticResetIntervalOption : uint8
{
    pfenum_Never UMETA(DisplayName = "Never"),
    pfenum_Hour UMETA(DisplayName = "Hour"),
    pfenum_Day UMETA(DisplayName = "Day"),
    pfenum_Week UMETA(DisplayName = "Week"),
    pfenum_Month UMETA(DisplayName = "Month"),
};

/** StatisticVersionArchivalStatus */

UENUM(BlueprintType)
enum class EStatisticVersionArchivalStatus : uint8
{
    pfenum_NotScheduled UMETA(DisplayName = "NotScheduled"),
    pfenum_Scheduled UMETA(DisplayName = "Scheduled"),
    pfenum_Queued UMETA(DisplayName = "Queued"),
    pfenum_InProgress UMETA(DisplayName = "InProgress"),
    pfenum_Complete UMETA(DisplayName = "Complete"),
};

/** StatisticVersionStatus */

UENUM(BlueprintType)
enum class EStatisticVersionStatus : uint8
{
    pfenum_Active UMETA(DisplayName = "Active"),
    pfenum_SnapshotPending UMETA(DisplayName = "SnapshotPending"),
    pfenum_Snapshot UMETA(DisplayName = "Snapshot"),
    pfenum_ArchivalPending UMETA(DisplayName = "ArchivalPending"),
    pfenum_Archived UMETA(DisplayName = "Archived"),
};

/** SubscriptionProviderStatus */

UENUM(BlueprintType)
enum class ESubscriptionProviderStatus : uint8
{
    pfenum_NoError UMETA(DisplayName = "NoError"),
    pfenum_Cancelled UMETA(DisplayName = "Cancelled"),
    pfenum_UnknownError UMETA(DisplayName = "UnknownError"),
    pfenum_BillingError UMETA(DisplayName = "BillingError"),
    pfenum_ProductUnavailable UMETA(DisplayName = "ProductUnavailable"),
    pfenum_CustomerDidNotAcceptPriceChange UMETA(DisplayName = "CustomerDidNotAcceptPriceChange"),
    pfenum_FreeTrial UMETA(DisplayName = "FreeTrial"),
    pfenum_PaymentPending UMETA(DisplayName = "PaymentPending"),
};

/** TaskInstanceStatus */

UENUM(BlueprintType)
enum class ETaskInstanceStatus : uint8
{
    pfenum_Succeeded UMETA(DisplayName = "Succeeded"),
    pfenum_Starting UMETA(DisplayName = "Starting"),
    pfenum_InProgress UMETA(DisplayName = "InProgress"),
    pfenum_Failed UMETA(DisplayName = "Failed"),
    pfenum_Aborted UMETA(DisplayName = "Aborted"),
    pfenum_Stalled UMETA(DisplayName = "Stalled"),
};

/** TitleActivationStatus */

UENUM(BlueprintType)
enum class ETitleActivationStatus : uint8
{
    pfenum_None UMETA(DisplayName = "None"),
    pfenum_ActivatedTitleKey UMETA(DisplayName = "ActivatedTitleKey"),
    pfenum_PendingSteam UMETA(DisplayName = "PendingSteam"),
    pfenum_ActivatedSteam UMETA(DisplayName = "ActivatedSteam"),
    pfenum_RevokedSteam UMETA(DisplayName = "RevokedSteam"),
};

/** UserDataPermission */

UENUM(BlueprintType)
enum class EUserDataPermission : uint8
{
    pfenum_Private UMETA(DisplayName = "Private"),
    pfenum_Public UMETA(DisplayName = "Public"),
};

/** UserOrigination */

UENUM(BlueprintType)
enum class EUserOrigination : uint8
{
    pfenum_Organic UMETA(DisplayName = "Organic"),
    pfenum_Steam UMETA(DisplayName = "Steam"),
    pfenum_Google UMETA(DisplayName = "Google"),
    pfenum_Amazon UMETA(DisplayName = "Amazon"),
    pfenum_Facebook UMETA(DisplayName = "Facebook"),
    pfenum_Kongregate UMETA(DisplayName = "Kongregate"),
    pfenum_GamersFirst UMETA(DisplayName = "GamersFirst"),
    pfenum_Unknown UMETA(DisplayName = "Unknown"),
    pfenum_IOS UMETA(DisplayName = "IOS"),
    pfenum_LoadTest UMETA(DisplayName = "LoadTest"),
    pfenum_Android UMETA(DisplayName = "Android"),
    pfenum_PSN UMETA(DisplayName = "PSN"),
    pfenum_GameCenter UMETA(DisplayName = "GameCenter"),
    pfenum_CustomId UMETA(DisplayName = "CustomId"),
    pfenum_XboxLive UMETA(DisplayName = "XboxLive"),
    pfenum_Parse UMETA(DisplayName = "Parse"),
    pfenum_Twitch UMETA(DisplayName = "Twitch"),
    pfenum_ServerCustomId UMETA(DisplayName = "ServerCustomId"),
    pfenum_NintendoSwitchDeviceId UMETA(DisplayName = "NintendoSwitchDeviceId"),
    pfenum_FacebookInstantGamesId UMETA(DisplayName = "FacebookInstantGamesId"),
    pfenum_OpenIdConnect UMETA(DisplayName = "OpenIdConnect"),
    pfenum_Apple UMETA(DisplayName = "Apple"),
    pfenum_NintendoSwitchAccount UMETA(DisplayName = "NintendoSwitchAccount"),
};

/** AdActivity */

UENUM(BlueprintType)
enum class EAdActivity : uint8
{
    pfenum_Opened UMETA(DisplayName = "Opened"),
    pfenum_Closed UMETA(DisplayName = "Closed"),
    pfenum_Start UMETA(DisplayName = "Start"),
    pfenum_End UMETA(DisplayName = "End"),
};

/** CloudScriptRevisionOption */

UENUM(BlueprintType)
enum class ECloudScriptRevisionOption : uint8
{
    pfenum_Live UMETA(DisplayName = "Live"),
    pfenum_Latest UMETA(DisplayName = "Latest"),
    pfenum_Specific UMETA(DisplayName = "Specific"),
};

/** GameInstanceState */

UENUM(BlueprintType)
enum class EGameInstanceState : uint8
{
    pfenum_Open UMETA(DisplayName = "Open"),
    pfenum_Closed UMETA(DisplayName = "Closed"),
};

/** MatchmakeStatus */

UENUM(BlueprintType)
enum class EMatchmakeStatus : uint8
{
    pfenum_Complete UMETA(DisplayName = "Complete"),
    pfenum_Waiting UMETA(DisplayName = "Waiting"),
    pfenum_GameNotFound UMETA(DisplayName = "GameNotFound"),
    pfenum_NoAvailableSlots UMETA(DisplayName = "NoAvailableSlots"),
    pfenum_SessionClosed UMETA(DisplayName = "SessionClosed"),
};

/** TradeStatus */

UENUM(BlueprintType)
enum class ETradeStatus : uint8
{
    pfenum_Invalid UMETA(DisplayName = "Invalid"),
    pfenum_Opening UMETA(DisplayName = "Opening"),
    pfenum_Open UMETA(DisplayName = "Open"),
    pfenum_Accepting UMETA(DisplayName = "Accepting"),
    pfenum_Accepted UMETA(DisplayName = "Accepted"),
    pfenum_Filled UMETA(DisplayName = "Filled"),
    pfenum_Cancelled UMETA(DisplayName = "Cancelled"),
};

/** TransactionStatus */

UENUM(BlueprintType)
enum class ETransactionStatus : uint8
{
    pfenum_CreateCart UMETA(DisplayName = "CreateCart"),
    pfenum_Init UMETA(DisplayName = "Init"),
    pfenum_Approved UMETA(DisplayName = "Approved"),
    pfenum_Succeeded UMETA(DisplayName = "Succeeded"),
    pfenum_FailedByProvider UMETA(DisplayName = "FailedByProvider"),
    pfenum_DisputePending UMETA(DisplayName = "DisputePending"),
    pfenum_RefundPending UMETA(DisplayName = "RefundPending"),
    pfenum_Refunded UMETA(DisplayName = "Refunded"),
    pfenum_RefundFailed UMETA(DisplayName = "RefundFailed"),
    pfenum_ChargedBack UMETA(DisplayName = "ChargedBack"),
    pfenum_FailedByUber UMETA(DisplayName = "FailedByUber"),
    pfenum_FailedByPlayFab UMETA(DisplayName = "FailedByPlayFab"),
    pfenum_Revoked UMETA(DisplayName = "Revoked"),
    pfenum_TradePending UMETA(DisplayName = "TradePending"),
    pfenum_Traded UMETA(DisplayName = "Traded"),
    pfenum_Upgraded UMETA(DisplayName = "Upgraded"),
    pfenum_StackPending UMETA(DisplayName = "StackPending"),
    pfenum_Stacked UMETA(DisplayName = "Stacked"),
    pfenum_Other UMETA(DisplayName = "Other"),
    pfenum_Failed UMETA(DisplayName = "Failed"),
};

/** PlayerConnectionState */

UENUM(BlueprintType)
enum class EPlayerConnectionState : uint8
{
    pfenum_Unassigned UMETA(DisplayName = "Unassigned"),
    pfenum_Connecting UMETA(DisplayName = "Connecting"),
    pfenum_Participating UMETA(DisplayName = "Participating"),
    pfenum_Participated UMETA(DisplayName = "Participated"),
};

/** IdentifiedDeviceType */

UENUM(BlueprintType)
enum class EIdentifiedDeviceType : uint8
{
    pfenum_Unknown UMETA(DisplayName = "Unknown"),
    pfenum_XboxOne UMETA(DisplayName = "XboxOne"),
    pfenum_Scarlett UMETA(DisplayName = "Scarlett"),
};

/** TriggerType */

UENUM(BlueprintType)
enum class EPfTriggerType : uint8
{
    pfenum_HTTP UMETA(DisplayName = "HTTP"),
    pfenum_Queue UMETA(DisplayName = "Queue"),
};

/** OperationTypes */

UENUM(BlueprintType)
enum class EOperationTypes : uint8
{
    pfenum_Created UMETA(DisplayName = "Created"),
    pfenum_Updated UMETA(DisplayName = "Updated"),
    pfenum_Deleted UMETA(DisplayName = "Deleted"),
    pfenum_None UMETA(DisplayName = "None"),
};

/** AnalysisTaskState */

UENUM(BlueprintType)
enum class EAnalysisTaskState : uint8
{
    pfenum_Waiting UMETA(DisplayName = "Waiting"),
    pfenum_ReadyForSubmission UMETA(DisplayName = "ReadyForSubmission"),
    pfenum_SubmittingToPipeline UMETA(DisplayName = "SubmittingToPipeline"),
    pfenum_Running UMETA(DisplayName = "Running"),
    pfenum_Completed UMETA(DisplayName = "Completed"),
    pfenum_Failed UMETA(DisplayName = "Failed"),
    pfenum_Canceled UMETA(DisplayName = "Canceled"),
};

/** ExperimentState */

UENUM(BlueprintType)
enum class EExperimentState : uint8
{
    pfenum_New UMETA(DisplayName = "New"),
    pfenum_Started UMETA(DisplayName = "Started"),
    pfenum_Stopped UMETA(DisplayName = "Stopped"),
    pfenum_Deleted UMETA(DisplayName = "Deleted"),
};

/** ExperimentType */

UENUM(BlueprintType)
enum class EExperimentType : uint8
{
    pfenum_Active UMETA(DisplayName = "Active"),
    pfenum_Snapshot UMETA(DisplayName = "Snapshot"),
};

/** AzureRegion */

UENUM(BlueprintType)
enum class EAzureRegion : uint8
{
    pfenum_AustraliaEast UMETA(DisplayName = "AustraliaEast"),
    pfenum_AustraliaSoutheast UMETA(DisplayName = "AustraliaSoutheast"),
    pfenum_BrazilSouth UMETA(DisplayName = "BrazilSouth"),
    pfenum_CentralUs UMETA(DisplayName = "CentralUs"),
    pfenum_EastAsia UMETA(DisplayName = "EastAsia"),
    pfenum_EastUs UMETA(DisplayName = "EastUs"),
    pfenum_EastUs2 UMETA(DisplayName = "EastUs2"),
    pfenum_JapanEast UMETA(DisplayName = "JapanEast"),
    pfenum_JapanWest UMETA(DisplayName = "JapanWest"),
    pfenum_NorthCentralUs UMETA(DisplayName = "NorthCentralUs"),
    pfenum_NorthEurope UMETA(DisplayName = "NorthEurope"),
    pfenum_SouthCentralUs UMETA(DisplayName = "SouthCentralUs"),
    pfenum_SoutheastAsia UMETA(DisplayName = "SoutheastAsia"),
    pfenum_WestEurope UMETA(DisplayName = "WestEurope"),
    pfenum_WestUs UMETA(DisplayName = "WestUs"),
    pfenum_SouthAfricaNorth UMETA(DisplayName = "SouthAfricaNorth"),
    pfenum_WestCentralUs UMETA(DisplayName = "WestCentralUs"),
    pfenum_KoreaCentral UMETA(DisplayName = "KoreaCentral"),
    pfenum_FranceCentral UMETA(DisplayName = "FranceCentral"),
    pfenum_WestUs2 UMETA(DisplayName = "WestUs2"),
    pfenum_CentralIndia UMETA(DisplayName = "CentralIndia"),
    pfenum_UaeNorth UMETA(DisplayName = "UaeNorth"),
    pfenum_UkSouth UMETA(DisplayName = "UkSouth"),
};

/** AzureVmFamily */

UENUM(BlueprintType)
enum class EAzureVmFamily : uint8
{
    pfenum_A UMETA(DisplayName = "A"),
    pfenum_Av2 UMETA(DisplayName = "Av2"),
    pfenum_Dv2 UMETA(DisplayName = "Dv2"),
    pfenum_Dv3 UMETA(DisplayName = "Dv3"),
    pfenum_F UMETA(DisplayName = "F"),
    pfenum_Fsv2 UMETA(DisplayName = "Fsv2"),
    pfenum_Dasv4 UMETA(DisplayName = "Dasv4"),
    pfenum_Dav4 UMETA(DisplayName = "Dav4"),
    pfenum_Eav4 UMETA(DisplayName = "Eav4"),
    pfenum_Easv4 UMETA(DisplayName = "Easv4"),
    pfenum_Ev4 UMETA(DisplayName = "Ev4"),
    pfenum_Esv4 UMETA(DisplayName = "Esv4"),
    pfenum_Dsv3 UMETA(DisplayName = "Dsv3"),
    pfenum_Dsv2 UMETA(DisplayName = "Dsv2"),
    pfenum_NCasT4_v3 UMETA(DisplayName = "NCasT4_v3"),
    pfenum_Ddv4 UMETA(DisplayName = "Ddv4"),
    pfenum_Ddsv4 UMETA(DisplayName = "Ddsv4"),
    pfenum_HBv3 UMETA(DisplayName = "HBv3"),
};

/** AzureVmSize */

UENUM(BlueprintType)
enum class EAzureVmSize : uint8
{
    pfenum_Standard_A1 UMETA(DisplayName = "Standard_A1"),
    pfenum_Standard_A2 UMETA(DisplayName = "Standard_A2"),
    pfenum_Standard_A3 UMETA(DisplayName = "Standard_A3"),
    pfenum_Standard_A4 UMETA(DisplayName = "Standard_A4"),
    pfenum_Standard_A1_v2 UMETA(DisplayName = "Standard_A1_v2"),
    pfenum_Standard_A2_v2 UMETA(DisplayName = "Standard_A2_v2"),
    pfenum_Standard_A4_v2 UMETA(DisplayName = "Standard_A4_v2"),
    pfenum_Standard_A8_v2 UMETA(DisplayName = "Standard_A8_v2"),
    pfenum_Standard_D1_v2 UMETA(DisplayName = "Standard_D1_v2"),
    pfenum_Standard_D2_v2 UMETA(DisplayName = "Standard_D2_v2"),
    pfenum_Standard_D3_v2 UMETA(DisplayName = "Standard_D3_v2"),
    pfenum_Standard_D4_v2 UMETA(DisplayName = "Standard_D4_v2"),
    pfenum_Standard_D5_v2 UMETA(DisplayName = "Standard_D5_v2"),
    pfenum_Standard_D2_v3 UMETA(DisplayName = "Standard_D2_v3"),
    pfenum_Standard_D4_v3 UMETA(DisplayName = "Standard_D4_v3"),
    pfenum_Standard_D8_v3 UMETA(DisplayName = "Standard_D8_v3"),
    pfenum_Standard_D16_v3 UMETA(DisplayName = "Standard_D16_v3"),
    pfenum_Standard_F1 UMETA(DisplayName = "Standard_F1"),
    pfenum_Standard_F2 UMETA(DisplayName = "Standard_F2"),
    pfenum_Standard_F4 UMETA(DisplayName = "Standard_F4"),
    pfenum_Standard_F8 UMETA(DisplayName = "Standard_F8"),
    pfenum_Standard_F16 UMETA(DisplayName = "Standard_F16"),
    pfenum_Standard_F2s_v2 UMETA(DisplayName = "Standard_F2s_v2"),
    pfenum_Standard_F4s_v2 UMETA(DisplayName = "Standard_F4s_v2"),
    pfenum_Standard_F8s_v2 UMETA(DisplayName = "Standard_F8s_v2"),
    pfenum_Standard_F16s_v2 UMETA(DisplayName = "Standard_F16s_v2"),
    pfenum_Standard_D2as_v4 UMETA(DisplayName = "Standard_D2as_v4"),
    pfenum_Standard_D4as_v4 UMETA(DisplayName = "Standard_D4as_v4"),
    pfenum_Standard_D8as_v4 UMETA(DisplayName = "Standard_D8as_v4"),
    pfenum_Standard_D16as_v4 UMETA(DisplayName = "Standard_D16as_v4"),
    pfenum_Standard_D2a_v4 UMETA(DisplayName = "Standard_D2a_v4"),
    pfenum_Standard_D4a_v4 UMETA(DisplayName = "Standard_D4a_v4"),
    pfenum_Standard_D8a_v4 UMETA(DisplayName = "Standard_D8a_v4"),
    pfenum_Standard_D16a_v4 UMETA(DisplayName = "Standard_D16a_v4"),
    pfenum_Standard_E2a_v4 UMETA(DisplayName = "Standard_E2a_v4"),
    pfenum_Standard_E4a_v4 UMETA(DisplayName = "Standard_E4a_v4"),
    pfenum_Standard_E8a_v4 UMETA(DisplayName = "Standard_E8a_v4"),
    pfenum_Standard_E16a_v4 UMETA(DisplayName = "Standard_E16a_v4"),
    pfenum_Standard_E2as_v4 UMETA(DisplayName = "Standard_E2as_v4"),
    pfenum_Standard_E4as_v4 UMETA(DisplayName = "Standard_E4as_v4"),
    pfenum_Standard_E8as_v4 UMETA(DisplayName = "Standard_E8as_v4"),
    pfenum_Standard_E16as_v4 UMETA(DisplayName = "Standard_E16as_v4"),
    pfenum_Standard_D2s_v3 UMETA(DisplayName = "Standard_D2s_v3"),
    pfenum_Standard_D4s_v3 UMETA(DisplayName = "Standard_D4s_v3"),
    pfenum_Standard_D8s_v3 UMETA(DisplayName = "Standard_D8s_v3"),
    pfenum_Standard_D16s_v3 UMETA(DisplayName = "Standard_D16s_v3"),
    pfenum_Standard_DS1_v2 UMETA(DisplayName = "Standard_DS1_v2"),
    pfenum_Standard_DS2_v2 UMETA(DisplayName = "Standard_DS2_v2"),
    pfenum_Standard_DS3_v2 UMETA(DisplayName = "Standard_DS3_v2"),
    pfenum_Standard_DS4_v2 UMETA(DisplayName = "Standard_DS4_v2"),
    pfenum_Standard_DS5_v2 UMETA(DisplayName = "Standard_DS5_v2"),
    pfenum_Standard_NC4as_T4_v3 UMETA(DisplayName = "Standard_NC4as_T4_v3"),
    pfenum_Standard_D2d_v4 UMETA(DisplayName = "Standard_D2d_v4"),
    pfenum_Standard_D4d_v4 UMETA(DisplayName = "Standard_D4d_v4"),
    pfenum_Standard_D8d_v4 UMETA(DisplayName = "Standard_D8d_v4"),
    pfenum_Standard_D16d_v4 UMETA(DisplayName = "Standard_D16d_v4"),
    pfenum_Standard_D2ds_v4 UMETA(DisplayName = "Standard_D2ds_v4"),
    pfenum_Standard_D4ds_v4 UMETA(DisplayName = "Standard_D4ds_v4"),
    pfenum_Standard_D8ds_v4 UMETA(DisplayName = "Standard_D8ds_v4"),
    pfenum_Standard_D16ds_v4 UMETA(DisplayName = "Standard_D16ds_v4"),
    pfenum_Standard_HB120_16rs_v3 UMETA(DisplayName = "Standard_HB120_16rs_v3"),
    pfenum_Standard_HB120_32rs_v3 UMETA(DisplayName = "Standard_HB120_32rs_v3"),
    pfenum_Standard_HB120_64rs_v3 UMETA(DisplayName = "Standard_HB120_64rs_v3"),
    pfenum_Standard_HB120_96rs_v3 UMETA(DisplayName = "Standard_HB120_96rs_v3"),
    pfenum_Standard_HB120rs_v3 UMETA(DisplayName = "Standard_HB120rs_v3"),
};

/** CancellationReason */

UENUM(BlueprintType)
enum class ECancellationReason : uint8
{
    pfenum_Requested UMETA(DisplayName = "Requested"),
    pfenum_Internal UMETA(DisplayName = "Internal"),
    pfenum_Timeout UMETA(DisplayName = "Timeout"),
};

/** ContainerFlavor */

UENUM(BlueprintType)
enum class EContainerFlavor : uint8
{
    pfenum_ManagedWindowsServerCore UMETA(DisplayName = "ManagedWindowsServerCore"),
    pfenum_CustomLinux UMETA(DisplayName = "CustomLinux"),
    pfenum_ManagedWindowsServerCorePreview UMETA(DisplayName = "ManagedWindowsServerCorePreview"),
    pfenum_Invalid UMETA(DisplayName = "Invalid"),
};

/** OsPlatform */

UENUM(BlueprintType)
enum class EOsPlatform : uint8
{
    pfenum_Windows UMETA(DisplayName = "Windows"),
    pfenum_Linux UMETA(DisplayName = "Linux"),
};

/** ProtocolType */

UENUM(BlueprintType)
enum class EProtocolType : uint8
{
    pfenum_TCP UMETA(DisplayName = "TCP"),
    pfenum_UDP UMETA(DisplayName = "UDP"),
};

/** ServerType */

UENUM(BlueprintType)
enum class EServerType : uint8
{
    pfenum_Container UMETA(DisplayName = "Container"),
    pfenum_Process UMETA(DisplayName = "Process"),
};

/** TitleMultiplayerServerEnabledStatus */

UENUM(BlueprintType)
enum class ETitleMultiplayerServerEnabledStatus : uint8
{
    pfenum_Initializing UMETA(DisplayName = "Initializing"),
    pfenum_Enabled UMETA(DisplayName = "Enabled"),
    pfenum_Disabled UMETA(DisplayName = "Disabled"),
};

