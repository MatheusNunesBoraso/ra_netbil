//=============================================================================================================================
//
// EasyAR Sense 4.8.0.11837-e0e3282d9
// Copyright (c) 2015-2026 VisionStar Information Technology (Shanghai) Co., Ltd. All Rights Reserved.
// EasyAR is the registered trademark or trademark of VisionStar Information Technology (Shanghai) Co., Ltd in China
// and other countries for the augmented reality technology developed by VisionStar Information Technology (Shanghai) Co., Ltd.
//
//=============================================================================================================================

#ifndef __EASYAR_ENGINE_H__
#define __EASYAR_ENGINE_H__

#include "easyar/types.h"

#ifdef __cplusplus
extern "C" {
#endif

/// <summary>
/// Gets the version schema hash, which can be used to ensure type declarations consistent with runtime library.
/// </summary>
int easyar_Engine_schemaHash(void);
bool easyar_Engine_initialize(easyar_String * licenseKey);
/// <summary>
/// Handles the app onPause, pauses internal tasks.
/// </summary>
void easyar_Engine_onPause(void);
/// <summary>
/// Handles the app onResume, resumes internal tasks.
/// </summary>
void easyar_Engine_onResume(void);
/// <summary>
/// Gets license validation state.
/// </summary>
easyar_ValidationState easyar_Engine_validationState(void);
/// <summary>
/// Gets error message on initialization failure.
/// </summary>
void easyar_Engine_errorMessage(/* OUT */ easyar_String * * Return);
/// <summary>
/// Gets the version number of EasyARSense.
/// </summary>
void easyar_Engine_versionString(/* OUT */ easyar_String * * Return);
/// <summary>
/// Gets the product name of EasyARSense. (Including variant, operating system and CPU architecture.)
/// </summary>
void easyar_Engine_name(/* OUT */ easyar_String * * Return);
/// <summary>
/// Gets the release variant of EasyARSense.
/// </summary>
void easyar_Engine_variant(/* OUT */ easyar_String * * Return);
/// <summary>
/// Checks whether the license key matches the provided release variant, package name(or bundle id) and operating system.
/// </summary>
bool easyar_Engine_isLicenseKeyMatched(easyar_String * licenseKey, easyar_String * packageName, easyar_String * variant, easyar_EngineOperatingSystem operatingSystem);
/// <summary>
/// Enable eyewear support.
/// </summary>
void easyar_Engine_enableEyewearSupport(void);

#ifdef __cplusplus
}
#endif

#endif
