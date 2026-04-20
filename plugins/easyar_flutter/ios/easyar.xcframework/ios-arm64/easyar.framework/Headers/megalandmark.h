//=============================================================================================================================
//
// EasyAR Sense 4.8.0.11837-e0e3282d9
// Copyright (c) 2015-2026 VisionStar Information Technology (Shanghai) Co., Ltd. All Rights Reserved.
// EasyAR is the registered trademark or trademark of VisionStar Information Technology (Shanghai) Co., Ltd in China
// and other countries for the augmented reality technology developed by VisionStar Information Technology (Shanghai) Co., Ltd.
//
//=============================================================================================================================

#ifndef __EASYAR_MEGALANDMARK_H__
#define __EASYAR_MEGALANDMARK_H__

#include "easyar/types.h"

#ifdef __cplusplus
extern "C" {
#endif

/// <summary>
/// Request status.
/// </summary>
easyar_MegaLandmarkFilterStatus easyar_MegaLandmarkFilterResult_status(const easyar_MegaLandmarkFilterResult * This);
/// <summary>
/// The spot version ID.
/// </summary>
void easyar_MegaLandmarkFilterResult_spotVersionId(const easyar_MegaLandmarkFilterResult * This, /* OUT */ easyar_OptionalOfString * Return);
/// <summary>
/// Detailed exception message.
/// </summary>
void easyar_MegaLandmarkFilterResult_exceptionInfo(const easyar_MegaLandmarkFilterResult * This, /* OUT */ easyar_String * * Return);
void easyar_MegaLandmarkFilterResult__dtor(easyar_MegaLandmarkFilterResult * This);
void easyar_MegaLandmarkFilterResult__retain(const easyar_MegaLandmarkFilterResult * This, /* OUT */ easyar_MegaLandmarkFilterResult * * Return);
const char * easyar_MegaLandmarkFilterResult__typeName(const easyar_MegaLandmarkFilterResult * This);

/// <summary>
/// Returns true.
/// </summary>
bool easyar_MegaLandmarkFilter_isAvailable(void);
/// <summary>
/// Creates an instance and connects to the server.
/// </summary>
void easyar_MegaLandmarkFilter_create(easyar_String * server, easyar_String * apiKey, easyar_String * apiSecret, easyar_String * appId, /* OUT */ easyar_MegaLandmarkFilter * * Return);
/// <summary>
/// Creates an instance with API Token.
/// </summary>
void easyar_MegaLandmarkFilter_createWithToken(easyar_String * server, easyar_String * apiToken, easyar_String * appId, /* OUT */ easyar_MegaLandmarkFilter * * Return);
/// <summary>
/// Updates API Token.
/// </summary>
void easyar_MegaLandmarkFilter_updateToken(easyar_MegaLandmarkFilter * This, easyar_String * apiToken);
/// <summary>
/// Location filtering.
/// Send GPS information to get SpotVersionId.
/// </summary>
void easyar_MegaLandmarkFilter_filterByLocation(easyar_MegaLandmarkFilter * This, easyar_LocationResult gps, easyar_OptionalOfInt timeoutMilliseconds, easyar_CallbackScheduler * callbackScheduler, easyar_FunctorOfVoidFromMegaLandmarkFilterResult callback);
/// <summary>
/// Filtering by SpotId.
/// Returns SpotVersionId.
/// </summary>
void easyar_MegaLandmarkFilter_filterBySpotId(easyar_MegaLandmarkFilter * This, easyar_String * spotId, easyar_OptionalOfInt timeoutMilliseconds, easyar_CallbackScheduler * callbackScheduler, easyar_FunctorOfVoidFromMegaLandmarkFilterResult callback);
/// <summary>
/// Closes connection. The component shall not be used after calling close.
/// </summary>
void easyar_MegaLandmarkFilter_close(easyar_MegaLandmarkFilter * This);
void easyar_MegaLandmarkFilter__dtor(easyar_MegaLandmarkFilter * This);
void easyar_MegaLandmarkFilter__retain(const easyar_MegaLandmarkFilter * This, /* OUT */ easyar_MegaLandmarkFilter * * Return);
const char * easyar_MegaLandmarkFilter__typeName(const easyar_MegaLandmarkFilter * This);

#ifdef __cplusplus
}
#endif

#endif
