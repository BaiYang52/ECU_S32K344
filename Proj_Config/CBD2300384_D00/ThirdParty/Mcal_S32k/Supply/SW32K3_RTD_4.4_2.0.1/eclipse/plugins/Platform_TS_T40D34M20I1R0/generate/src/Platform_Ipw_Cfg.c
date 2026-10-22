/*==================================================================================================
*   Project              : RTD AUTOSAR 4.4
*   Platform             : CORTEXM
*   Peripheral           : 
*   Dependencies         : none
*
*   Autosar Version      : 4.4.0
*   Autosar Revision     : ASR_REL_4_4_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 2.0.1
*   Build Version        : S32K3_RTD_2_0_1_D2207_ASR_REL_4_4_REV_0000_20220707
*
*   (c) Copyright 2020 - 2022 NXP Semiconductors
*   All Rights Reserved.
*
*   NXP Confidential. This software is owned or controlled by NXP and may only be
*   used strictly in accordance with the applicable license terms. By expressly
*   accepting such terms or by downloading, installing, activating and/or otherwise
*   using the software, you are agreeing that you have read, and that you agree to
*   comply with and are bound by, such license terms. If you do not agree to be
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
==================================================================================================*/

#ifdef __cplusplus
extern "C" {
#endif

/*==================================================================================================
                                         INCLUDE FILES
==================================================================================================*/
#include "Platform_Ipw_Cfg.h"
#include "IntCtrl_Ip.h"

#define PLATFORM_IPW_CFG_VENDOR_ID_C                     43
#define PLATFORM_IPW_CFG_AR_RELEASE_MAJOR_VERSION_C      4
#define PLATFORM_IPW_CFG_AR_RELEASE_MINOR_VERSION_C      4
#define PLATFORM_IPW_CFG_AR_RELEASE_REVISION_VERSION_C   0
#define PLATFORM_IPW_CFG_SW_MAJOR_VERSION_C              2
#define PLATFORM_IPW_CFG_SW_MINOR_VERSION_C              0
#define PLATFORM_IPW_CFG_SW_PATCH_VERSION_C              1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Platform_Ipw_TypesDef header file are of the same vendor */
#if (PLATFORM_IPW_CFG_VENDOR_ID_C != PLATFORM_IPW_CFG_VENDOR_ID)
    #error "Platform_Ipw_Cfg.c and Platform_Ipw_TypesDef.h have different vendor ids"
#endif
/* Check if current file and Platform_Ipw_TypesDef header file are of the same Autosar version */
#if ((PLATFORM_IPW_CFG_AR_RELEASE_MAJOR_VERSION_C    != PLATFORM_IPW_TYPESDEF_AR_RELEASE_MAJOR_VERSION) || \
     (PLATFORM_IPW_CFG_AR_RELEASE_MINOR_VERSION_C    != PLATFORM_IPW_TYPESDEF_AR_RELEASE_MINOR_VERSION) || \
     (PLATFORM_IPW_CFG_AR_RELEASE_REVISION_VERSION_C != PLATFORM_IPW_TYPESDEF_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Platform_Ipw_Cfg.c and Platform_Ipw_TypesDef.h are different"
#endif
/* Check if current file and Platform_Ipw_TypesDef header file are of the same Software version */
#if ((PLATFORM_IPW_CFG_SW_MAJOR_VERSION_C != PLATFORM_IPW_TYPESDEF_SW_MAJOR_VERSION) || \
     (PLATFORM_IPW_CFG_SW_MINOR_VERSION_C != PLATFORM_IPW_TYPESDEF_SW_MINOR_VERSION) || \
     (PLATFORM_IPW_CFG_SW_PATCH_VERSION_C != PLATFORM_IPW_TYPESDEF_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Platform_Ipw_Cfg.c and Platform_Ipw_TypesDef.h are different"
#endif


/* Check if current file and IntCtrl_Ip header file are of the same vendor */
#if (PLATFORM_IPW_CFG_VENDOR_ID != PLATFORM_INTCTRL_IP_VENDOR_ID)
    #error "Platform_Ipw_Cfg.c and IntCtrl_Ip.h have different vendor ids"
#endif
/* Check if current file and IntCtrl_Ip header file are of the same Autosar version */
#if ((PLATFORM_IPW_CFG_AR_MAJOR_VERSION    != PLATFORM_IPW_TYPESDEF_AR_RELEASE_MAJOR_VERSION) || \
     (PLATFORM_IPW_CFG_AR_MINOR_VERSION    != PLATFORM_IPW_TYPESDEF_AR_RELEASE_MINOR_VERSION) || \
     (PLATFORM_IPW_CFG_AR_REVISION_VERSION != PLATFORM_IPW_TYPESDEF_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Platform_Ipw_Cfg.c and IntCtrl_Ip.h are different"
#endif
/* Check if current file and IntCtrl_Ip header file are of the same Software version */
#if ((PLATFORM_IPW_CFG_SW_MAJOR_VERSION != PLATFORM_IPW_TYPESDEF_SW_MAJOR_VERSION) || \
     (PLATFORM_IPW_CFG_SW_MINOR_VERSION != PLATFORM_IPW_TYPESDEF_SW_MINOR_VERSION) || \
     (PLATFORM_IPW_CFG_SW_PATCH_VERSION != PLATFORM_IPW_TYPESDEF_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Platform_Ipw_Cfg.c and IntCtrl_Ip.h are different"
#endif






[!NOCODE!]
[!VAR "McmAvailable" = "0"!]
[!IF "GeneralConfiguration/PlatformMcmConfigurable"!]
    [!IF "count(McmConfig/*) > 0"!]
        [!VAR "McmAvailable" = "1"!]
    [!ENDIF!]
[!ENDIF!]
[!VAR "IntCtrlAvailable" = "0"!]
[!IF "count(IntCtrlConfig/*) > 0"!]
    [!VAR "IntCtrlAvailable" = "1"!]
[!ENDIF!]
[!ENDNOCODE!]


[!IF "GeneralConfiguration/PlatformIntmConfigurable"!]#include "Intm_Ip.h"[!ENDIF!]
[!IF "$McmAvailable = 1"!]#include "System_Ip.h"[!ENDIF!]

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/

/* TBD */


/*==================================================================================================
                                       GLOBAL VARIABLES
==================================================================================================*/
#define PLATFORM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Platform_MemMap.h"
[!NOCODE!]


[!IF "./GeneralConfiguration/PlatformMulticoreSupport = 'true'"!]


/* Variable storing number of maximum partitions using in configuration */
[!VAR "numPartition" = "0"!]

[!LOOP "as:modconf('Os')[1]/OsApplication/*"!]
    [!SELECT "node:ref(./OsApplicationCoreRef)"!]
        [!IF "$numPartition < node:value(./EcucCoreId)"!]
            [!VAR "numPartition" = "node:value(./EcucCoreId)"!]
        [!ENDIF!]
    [!ENDSELECT!]
[!ENDLOOP!]

[!VAR "numPartition" = "$numPartition + 1 "!]

[!FOR "CurrentCoreId" = "0" TO "$numPartition - 1"!]
    [!VAR "CoreIdConfigured" = "0"!]
    [!LOOP "GeneralConfiguration/PlatformEcucPartitionRef/*"!]
        [!VAR "CurrentPartitionRefName" = "node:value(.)"!]
        [!VAR "CurrentPartitionShortName" = "substring-after($CurrentPartitionRefName, '/')"!]
        [!VAR "CurrentPartitionShortName" = "substring-after($CurrentPartitionShortName, '/')"!]
        [!VAR "CurrentPartitionShortName" = "substring-after($CurrentPartitionShortName, '/')"!]
        [!VAR "CurrentPartitionShortName" = "substring-after($CurrentPartitionShortName, '/')"!]
        [!LOOP "as:modconf('Os')[1]/OsApplication/*"!]
            [!IF "$CurrentPartitionRefName = node:value(./OsAppEcucPartitionRef)"!]
                [!SELECT "node:ref(./OsApplicationCoreRef)"!]
                    [!IF "$CurrentCoreId = node:value(./EcucCoreId)"!]                    
                        [!VAR "CoreIdConfigured" = "1"!]
                        [!VAR "PartitionShortName" = "$CurrentPartitionShortName"!]
                        [!VAR "PartitionRefName" = "$CurrentPartitionRefName"!]
                    [!ENDIF!]
                [!ENDSELECT!]
            [!ENDIF!]
        [!ENDLOOP!]
    [!ENDLOOP!]
[!IF "$CoreIdConfigured = 1"!]
[!CODE!]
/*================================== Partition [!"$PartitionShortName"!] ==================================*/
[!ENDCODE!]
[!VAR "McmConfigAvailable" = "0"!]
[!IF "$McmAvailable = 1"!] /* System settings */
    [!VAR "McmConfigAvailable" = "0"!]
    [!LOOP "McmConfig/*"!]
        [!IF "./PlatformMcmEcucPartitionRef = $PartitionRefName "!]
            [!VAR "McmConfigAvailable" = "1"!]
            [!CODE!]
#if (PLATFORM_SYS_CFG == STD_ON)
/* List of configurations for CM7 system interrupts */
[!IF "count(./SystemIsrConfig/*) > 0"!][!//
static const Platform_SystemIrqConfigType aSysIrqCfg[!"$PartitionShortName"!][] = {[!LOOP "SystemIsrConfig/*"!]
    { [!"SystemIsrName"!], (boolean)[!IF "SystemIsrEnabled"!]TRUE[!ELSE!]FALSE[!ENDIF!] },[!ENDLOOP!]
};
[!ENDIF!][!//
/* system configurations for [!"$PartitionShortName"!]*/
static const Platform_SystemConfigType SystemConfig[!"$PartitionShortName"!] = 
{
[!IF "count(./SystemIsrConfig/*) > 0"!][!//
    aSysIrqCfg[!"$PartitionShortName"!], 
[!ELSE!][!//
    NULL_PTR,
[!ENDIF!][!//
    [!"num:dectoint(count(./SystemIsrConfig/*))"!]U, 
    (boolean)[!IF "SystemAhbSlavePrio = 'Round_robin'"!]FALSE[!ELSE!]TRUE[!ENDIF!]
};
#endif
            [!ENDCODE!]
        [!ENDIF!]
    [!ENDLOOP!]
[!ENDIF!]

[!VAR "NvicConfigAvailable" = "0"!]
[!LOOP "IntCtrlConfig/*"!]
    [!IF "./PlatformNvicEcucPartitionRef = $PartitionRefName "!]
        [!VAR "NvicConfigAvailable" = "1"!]
    [!ENDIF!]
[!ENDLOOP!]

[!IF "GeneralConfiguration/PlatformIntmConfigurable"!]

[!VAR "IntmChannelConfigAvailable" = "0"!]
[!VAR "IntmChannelcount" = "0"!]
[!LOOP "IntmConfig/IntmChannel/*"!]
    [!IF "./PlatformIntmChannelEcucPartitionRef = $PartitionRefName "!]
        [!VAR "IntmChannelConfigAvailable" = "1"!]
        [!VAR "IntmChannelcount" = "$IntmChannelcount + 1"!]
    [!ENDIF!]
[!ENDLOOP!]
[!IF "$IntmChannelConfigAvailable = 1"!]
[!VAR "NumPlatformChannels" = "num:i(count(IntmConfig/IntmChannel/*))"!]
[!CODE!]/*[!CR!][!ENDCODE!]
[!CODE!]*   @brief Translation LUT for Logical channel number to Partition Configuration indexed location[!CR!][!ENDCODE!]
[!CODE!]*/[!CR!][!ENDCODE!]
[!CODE!]static const uint8 Platform_ChIndexMap_[!"$PartitionShortName"!][[!"$NumPlatformChannels"!]U] = [!CR!]{[!CR!][!ENDCODE!]
            [!VAR "Index" = "0"!]
            [!FOR "Idx" = "0" TO "$NumPlatformChannels - 1"!]
                    [!LOOP "IntmConfig/IntmChannel/*"!]
                        [!IF "num:i($Idx)=num:i(PlatformIntmChannelId)"!]
                            [!VAR "Found" = "'false'"!]
                            [!IF "./PlatformIntmChannelEcucPartitionRef = $PartitionRefName "!]
                                [!VAR "Found" = "'true'"!]
                            [!ENDIF!]                            
                            [!IF "$Found='false'"!]
[!CODE!][!WS "4"!]255U[!IF "$Idx < $NumPlatformChannels - 1"!],[!ENDIF!]    /* No channel */[!CR!][!ENDCODE!]
                            [!ELSEIF "$Found='true'"!]
[!CODE!][!WS "4"!][!"num:i($Index)"!]U[!IF "$Idx < $NumPlatformChannels - 1"!],[!ENDIF!]    /* [!"node:name(.)"!] has an index of [!"num:i($Index)"!] */[!CR!][!ENDCODE!]
                                [!VAR "Index" = "$Index + 1"!]
                            [!ENDIF!]
                        [!ENDIF!]
                    [!ENDLOOP!]
            [!ENDFOR!]
[!CODE!]};[!ENDCODE!]
[!ENDIF!]

[!VAR "IntmGenericConfigAvailable" = "0"!]
[!IF "./IntmConfig/IntmGenericSettings/PlatformIntmGenericEcucPartitionRef = $PartitionRefName "!]
    [!VAR "IntmGenericConfigAvailable" = "1"!]
[!ENDIF!]
[!IF "$IntmChannelConfigAvailable = 1"!]
[!CODE!]
/* channel interrupt monitor configurations for [!"$PartitionShortName"!]*/
static const Platform_IntmChannelConfigType aIntmChannelConfig[!"$PartitionShortName"!][] = 
{
[!ENDCODE!]
[!LOOP "IntmConfig/IntmChannel/*"!]
    [!IF "./PlatformIntmChannelEcucPartitionRef = $PartitionRefName "!] 
[!CODE!]    {INTM_IP_MONITOR[!"substring-after(InterruptMonitor, 'IntMonitor')"!], [!"MonitoredIrq"!], [!"AcceptedLatency"!] }, 
[!ENDCODE!]
    [!ENDIF!]
[!ENDLOOP!]
[!CODE!]
};
[!ENDCODE!]
[!ENDIF!][!//IntmChannelConfigAvailable
[!IF "$IntmGenericConfigAvailable = 1 "!]
[!CODE!]
/* generic interrupt monitor configurations for [!"$PartitionShortName"!]*/
static const Platform_IntmGenericConfigType pIntmGenericConfig[!"$PartitionShortName"!] =
{
    (boolean)[!IF "IntmConfig/IntmGenericSettings/IntmEnable = 'true'"!]TRUE [!ELSE!] FALSE [!ENDIF!]
};
[!ENDCODE!]
[!ENDIF!]
[!CODE!]
/* interrupt monitor configurations for [!"$PartitionShortName"!]*/
static const Platform_IntmConfigType IntmConfig[!"$PartitionShortName"!] = 
{
    (uint8)[!"num:i($IntmChannelcount)"!]U ,
    [!IF "$IntmChannelConfigAvailable = 1"!]aIntmChannelConfig[!"$PartitionShortName"!] [!ELSE!] NULL_PTR [!ENDIF!] ,
    [!IF "$IntmGenericConfigAvailable = 1"!]&pIntmGenericConfig[!"$PartitionShortName"!] [!ELSE!] NULL_PTR [!ENDIF!] ,
    [!IF "$IntmChannelConfigAvailable = 1"!]&Platform_ChIndexMap_[!"$PartitionShortName"!] [!ELSE!] NULL_PTR [!ENDIF!]
};
[!ENDCODE!]
[!ENDIF!][!//GeneralConfiguration/PlatformIntmConfigurable


[!CODE!]
/* Definition of the configuration structure for Platform IPW */
const Platform_Ipw_ConfigType ipwConfig[!"$PartitionShortName"!] = {
    [!IF "$NvicConfigAvailable = 1"!]&intCtrlConfig[!"$PartitionShortName"!][!ELSE!]NULL_PTR [!ENDIF!] , /* Interrupt controller configuration */
    [!IF "$McmConfigAvailable = 1"!]&SystemConfig[!"$PartitionShortName"!][!ELSE!]NULL_PTR [!ENDIF!] , /* System settings */
    [!IF "GeneralConfiguration/PlatformIntmConfigurable"!]&IntmConfig[!"$PartitionShortName"!] [!ELSE!] NULL_PTR [!ENDIF!]  /* Interrupt monitor settings */
};
[!IF "(GeneralConfiguration/PlatformMscmConfigurable = true()) and (MscmConfig/PlatformGenericInterruptEcucPartitionRef = $PartitionRefName)"!]
/* Definition of the configuration structure for non core Platform IPW */
const Platform_Ipw_NonCoreConfigType ipwNonCoreConfig[!"$PartitionShortName"!] = {
    &intRouteConfig[!"$PartitionShortName"!]
};
[!ELSE!][!//PlatformMscmConfigurable
/* Definition of the configuration structure for non core Platform IPW */
const Platform_Ipw_NonCoreConfigType ipwNonCoreConfig[!"$PartitionShortName"!] = {
    NULL_PTR
};
[!ENDIF!][!//PlatformMscmConfigurable
/*================================== End Partition [!"$PartitionShortName"!] ==============================*/

[!ENDCODE!]

[!ENDIF!]
[!ENDFOR!]

[!ELSE!][!//multicore
    [!IF "$McmAvailable = 1"!] /* System settings */
    [!SELECT "McmConfig/*[1]"!]
        [!CODE!]
#if (PLATFORM_SYS_CFG == STD_ON)
/* List of configurations for CM7 system interrupts */
[!IF "count(./SystemIsrConfig/*) > 0"!][!//
static const Platform_SystemIrqConfigType aSysIrqCfg[] = {[!LOOP "SystemIsrConfig/*"!]
    { [!"SystemIsrName"!], (boolean)[!IF "SystemIsrEnabled"!]TRUE[!ELSE!]FALSE[!ENDIF!] },[!ENDLOOP!]
};
[!ENDIF!][!//
/* system configurations */
static const Platform_SystemConfigType SystemConfig = 
{ 
[!IF "count(./SystemIsrConfig/*) > 0"!][!//
    aSysIrqCfg,
[!ELSE!][!//
    NULL_PTR,
[!ENDIF!][!//
    [!"num:dectoint(count(./SystemIsrConfig/*))"!]U, 
    (boolean)[!IF "SystemAhbSlavePrio = 'Round_robin'"!]FALSE [!ELSE!] TRUE [!ENDIF!]
};
#endif
        [!ENDCODE!]
    [!ENDSELECT!][!//SELECT "McmConfig/*[1]"
    [!ENDIF!][!// McmAvailable
[!IF "GeneralConfiguration/PlatformIntmConfigurable"!]
[!CODE!]
#if (PLATFORM_INT_MONITOR == STD_ON)
[!NOCODE!]
[!VAR "NumPlatformChannels" = "num:i(count(IntmConfig/IntmChannel/*))"!]
[!IF "$NumPlatformChannels > 0 "!]
[!CODE!]/*[!CR!][!ENDCODE!]
[!CODE!]*   @brief Translation LUT for Logical channel number to Partition Configuration indexed location[!CR!][!ENDCODE!]
[!CODE!]*/[!CR!][!ENDCODE!]
[!CODE!]static const uint8 Platform_ChIndexMap[[!"$NumPlatformChannels"!]U] = [!CR!]{[!CR!][!ENDCODE!]
            [!VAR "Index" = "0"!]
            [!FOR "Idx" = "0" TO "$NumPlatformChannels - 1"!]                
[!CODE!][!WS "4"!][!"num:i($Idx)"!]U[!IF "$Idx < $NumPlatformChannels - 1"!],[!ENDIF!]  [!CR!][!ENDCODE!]
            [!ENDFOR!]
[!CODE!]};[!ENDCODE!]
[!ENDIF!]
[!ENDNOCODE!]
    [!IF "node:exists(IntmConfig/IntmGenericSettings)"!]
static const Platform_IntmGenericConfigType pIntmGenericConfig =
{
    (boolean)[!IF "IntmConfig/IntmGenericSettings/IntmEnable = 'true'"!]TRUE [!ELSE!] FALSE [!ENDIF!]
};
    [!ENDIF!]
    [!IF "count(IntmConfig/IntmChannel/*) > 0 "!]
/* List of configurations for channel interrupt monitors */
static const Platform_IntmChannelConfigType aIntmChannelConfig[] = { [!LOOP "IntmConfig/IntmChannel/*"!]
    { INTM_IP_MONITOR[!"substring-after(InterruptMonitor, 'IntMonitor')"!], [!"MonitoredIrq"!], [!"AcceptedLatency"!] }, [!ENDLOOP!]
};
    [!ENDIF!]
    
static const Platform_IntmConfigType IntmConfig =
{
    (uint8)[!"num:i(count(IntmConfig/IntmChannel/*))"!]U ,
    [!IF "count(IntmConfig/IntmChannel/*) > 0 "!]aIntmChannelConfig [!ELSE!] NULL_PTR [!ENDIF!],
    [!IF "node:exists(IntmConfig/IntmGenericSettings)"!]&pIntmGenericConfig [!ELSE!] NULL_PTR [!ENDIF!],
    [!IF "count(IntmConfig/IntmChannel/*) > 0 "!]&Platform_ChIndexMap [!ELSE!] NULL_PTR [!ENDIF!]
};
#endif
[!ENDCODE!]
[!ENDIF!][!//PlatformIntmConfigurable
    
[!CODE!]
/* Definition of the configuration structure for Platform IPW */
const Platform_Ipw_ConfigType ipwConfig = {
    [!IF "$IntCtrlAvailable = 1"!]&intCtrlConfig [!ELSE!] NULL_PTR [!ENDIF!] , /* Interrupt controller configuration */
    [!IF "$McmAvailable = 1"!]&SystemConfig [!ELSE!] NULL_PTR [!ENDIF!] ,/* System settings */
    [!IF "GeneralConfiguration/PlatformIntmConfigurable"!]&IntmConfig [!ELSE!] NULL_PTR [!ENDIF!]  /* Interrupt monitor settings */
};
[!ENDCODE!]
    
[!IF "GeneralConfiguration/PlatformMscmConfigurable"!]
    [!CODE!]
/* Definition of the configuration structure for non core Platform IPW */
const Platform_Ipw_NonCoreConfigType ipwNonCoreConfig = {
    &intRouteConfig
};
    [!ENDCODE!]
[!ENDIF!][!//PlatformMscmConfigurable
[!ENDIF!][!//multicore
[!ENDNOCODE!]
#define PLATFORM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Platform_MemMap.h"

#ifdef __cplusplus
}
#endif
