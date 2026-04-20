//=============================================================================================================================
//
// EasyAR Sense 4.8.0.11837-e0e3282d9
// Copyright (c) 2015-2026 VisionStar Information Technology (Shanghai) Co., Ltd. All Rights Reserved.
// EasyAR is the registered trademark or trademark of VisionStar Information Technology (Shanghai) Co., Ltd in China
// and other countries for the augmented reality technology developed by VisionStar Information Technology (Shanghai) Co., Ltd.
//
//=============================================================================================================================

#ifndef __EASYAR_CLOUDLOCALIZE_H__
#define __EASYAR_CLOUDLOCALIZE_H__

#include "easyar/types.h"

#ifdef __cplusplus
extern "C" {
#endif

/// <summary>
/// The ID of the block.
/// </summary>
void easyar_CloudLocalizerBlockInstance_blockId(const easyar_CloudLocalizerBlockInstance * This, /* OUT */ easyar_String * * Return);
/// <summary>
/// The name of the block.
/// </summary>
void easyar_CloudLocalizerBlockInstance_name(const easyar_CloudLocalizerBlockInstance * This, /* OUT */ easyar_String * * Return);
/// <summary>
/// The map pose in the camera coordinates.
/// </summary>
easyar_Matrix44F easyar_CloudLocalizerBlockInstance_pose(const easyar_CloudLocalizerBlockInstance * This);
void easyar_CloudLocalizerBlockInstance__dtor(easyar_CloudLocalizerBlockInstance * This);
void easyar_CloudLocalizerBlockInstance__retain(const easyar_CloudLocalizerBlockInstance * This, /* OUT */ easyar_CloudLocalizerBlockInstance * * Return);
const char * easyar_CloudLocalizerBlockInstance__typeName(const easyar_CloudLocalizerBlockInstance * This);

/// <summary>
/// Localization status.
/// </summary>
easyar_CloudLocalizerStatus easyar_CloudLocalizerResult_localizeStatus(const easyar_CloudLocalizerResult * This);
/// <summary>
/// The spot version ID. Only available with `MegaApiType`_.Landmark .
/// </summary>
void easyar_CloudLocalizerResult_spotVersionId(const easyar_CloudLocalizerResult * This, /* OUT */ easyar_OptionalOfString * Return);
/// <summary>
/// Current localized block instances.
/// </summary>
void easyar_CloudLocalizerResult_blockInstances(const easyar_CloudLocalizerResult * This, /* OUT */ easyar_ListOfCloudLocalizerBlockInstance * * Return);
/// <summary>
/// Extra informations of the localization.
/// </summary>
void easyar_CloudLocalizerResult_extraInfo(const easyar_CloudLocalizerResult * This, /* OUT */ easyar_String * * Return);
/// <summary>
/// Detailed exception message.
/// </summary>
void easyar_CloudLocalizerResult_exceptionInfo(const easyar_CloudLocalizerResult * This, /* OUT */ easyar_String * * Return);
/// <summary>
/// The duration in seconds for server response.
/// </summary>
easyar_OptionalOfDouble easyar_CloudLocalizerResult_serverResponseDuration(const easyar_CloudLocalizerResult * This);
/// <summary>
/// The duration in seconds for server internal calculation.
/// </summary>
easyar_OptionalOfDouble easyar_CloudLocalizerResult_serverCalculationDuration(const easyar_CloudLocalizerResult * This);
void easyar_CloudLocalizerResult__dtor(easyar_CloudLocalizerResult * This);
void easyar_CloudLocalizerResult__retain(const easyar_CloudLocalizerResult * This, /* OUT */ easyar_CloudLocalizerResult * * Return);
const char * easyar_CloudLocalizerResult__typeName(const easyar_CloudLocalizerResult * This);

void easyar_DeviceAuxiliaryInfo_create(/* OUT */ easyar_DeviceAuxiliaryInfo * * Return);
void easyar_DeviceAuxiliaryInfo_setAcceleration(easyar_DeviceAuxiliaryInfo * This, easyar_AccelerometerResult acce);
void easyar_DeviceAuxiliaryInfo_setGPSLocation(easyar_DeviceAuxiliaryInfo * This, easyar_LocationResult gps);
void easyar_DeviceAuxiliaryInfo_setProximityLocation(easyar_DeviceAuxiliaryInfo * This, easyar_ProximityLocationResult proximity);
void easyar_DeviceAuxiliaryInfo_setBlockPrior(easyar_DeviceAuxiliaryInfo * This, easyar_BlockPriorResult * blockPrior);
void easyar_DeviceAuxiliaryInfo_setECompass(easyar_DeviceAuxiliaryInfo * This, double northHeading, double headingAccuracy);
void easyar_DeviceAuxiliaryInfo__dtor(easyar_DeviceAuxiliaryInfo * This);
void easyar_DeviceAuxiliaryInfo__retain(const easyar_DeviceAuxiliaryInfo * This, /* OUT */ easyar_DeviceAuxiliaryInfo * * Return);
const char * easyar_DeviceAuxiliaryInfo__typeName(const easyar_DeviceAuxiliaryInfo * This);

/// <summary>
/// Returns true.
/// </summary>
bool easyar_CloudLocalizer_isAvailable(void);
/// <summary>
/// Creates an instance and connects to the server.
/// </summary>
void easyar_CloudLocalizer_create(easyar_String * server, easyar_String * apiKey, easyar_String * apiSecret, easyar_String * appId, /* OUT */ easyar_CloudLocalizer * * Return);
/// <summary>
/// Creates an instance with API Token and connects to the server.
/// </summary>
void easyar_CloudLocalizer_createWithToken(easyar_String * server, easyar_String * apiToken, easyar_String * appId, /* OUT */ easyar_CloudLocalizer * * Return);
/// <summary>
/// Updates API Token.
/// </summary>
void easyar_CloudLocalizer_updateToken(easyar_CloudLocalizer * This, easyar_String * apiToken);
/// <summary>
/// Sets MEGA API Type. The default is Block.
/// </summary>
void easyar_CloudLocalizer_setMegaApiType(easyar_CloudLocalizer * This, easyar_MegaApiType type);
/// <summary>
/// Send localization request.
/// Send `InputFrame`_ to resolve a cloud localization. `InputFrame`_ should have at least image data and camera parameters.
/// message input is a json string.
/// </summary>
void easyar_CloudLocalizer_resolve(easyar_CloudLocalizer * This, easyar_InputFrame * inputFrame, easyar_String * message, easyar_DeviceAuxiliaryInfo * deviceAuxInfo, easyar_OptionalOfInt timeoutMilliseconds, easyar_CallbackScheduler * callbackScheduler, easyar_FunctorOfVoidFromCloudLocalizerResult callback);
/// <summary>
/// Send localization request.
/// Send `InputFrame`_ to resolve a cloud localization. `InputFrame`_ should have at least image data and camera parameters.
/// message input is a json string.
/// </summary>
void easyar_CloudLocalizer_resolveLandmark(easyar_CloudLocalizer * This, easyar_InputFrame * inputFrame, easyar_String * message, easyar_DeviceAuxiliaryInfo * deviceAuxInfo, easyar_String * spotVersionId, easyar_OptionalOfInt timeoutMilliseconds, easyar_CallbackScheduler * callbackScheduler, easyar_FunctorOfVoidFromCloudLocalizerResult callback);
/// <summary>
/// Stops the localization and closes connection. The component shall not be used after calling close.
/// </summary>
void easyar_CloudLocalizer_close(easyar_CloudLocalizer * This);
void easyar_CloudLocalizer__dtor(easyar_CloudLocalizer * This);
void easyar_CloudLocalizer__retain(const easyar_CloudLocalizer * This, /* OUT */ easyar_CloudLocalizer * * Return);
const char * easyar_CloudLocalizer__typeName(const easyar_CloudLocalizer * This);

void easyar_ListOfCloudLocalizerBlockInstance__ctor(easyar_CloudLocalizerBlockInstance * const * begin, easyar_CloudLocalizerBlockInstance * const * end, /* OUT */ easyar_ListOfCloudLocalizerBlockInstance * * Return);
void easyar_ListOfCloudLocalizerBlockInstance__dtor(easyar_ListOfCloudLocalizerBlockInstance * This);
void easyar_ListOfCloudLocalizerBlockInstance_copy(const easyar_ListOfCloudLocalizerBlockInstance * This, /* OUT */ easyar_ListOfCloudLocalizerBlockInstance * * Return);
int easyar_ListOfCloudLocalizerBlockInstance_size(const easyar_ListOfCloudLocalizerBlockInstance * This);
easyar_CloudLocalizerBlockInstance * easyar_ListOfCloudLocalizerBlockInstance_at(const easyar_ListOfCloudLocalizerBlockInstance * This, int index);

#ifdef __cplusplus
}
#endif

#endif
