//=============================================================================================================================
//
// EasyAR Sense 4.8.0.11837-e0e3282d9
// Copyright (c) 2015-2026 VisionStar Information Technology (Shanghai) Co., Ltd. All Rights Reserved.
// EasyAR is the registered trademark or trademark of VisionStar Information Technology (Shanghai) Co., Ltd in China
// and other countries for the augmented reality technology developed by VisionStar Information Technology (Shanghai) Co., Ltd.
//
//=============================================================================================================================

#ifndef __EASYAR_ARCOREDEVICELIST_H__
#define __EASYAR_ARCOREDEVICELIST_H__

#include "easyar/types.h"

#ifdef __cplusplus
extern "C" {
#endif

void easyar_ARCoreDeviceListDownloader__ctor(/* OUT */ easyar_ARCoreDeviceListDownloader * * Return);
void easyar_ARCoreDeviceListDownloader_download(easyar_ARCoreDeviceListDownloader * This, easyar_OptionalOfInt timeoutMilliseconds, easyar_CallbackScheduler * callbackScheduler, easyar_FunctorOfVoidFromARCoreDeviceListDownloadStatusAndOptionalOfString onCompleted);
void easyar_ARCoreDeviceListDownloader__dtor(easyar_ARCoreDeviceListDownloader * This);
void easyar_ARCoreDeviceListDownloader__retain(const easyar_ARCoreDeviceListDownloader * This, /* OUT */ easyar_ARCoreDeviceListDownloader * * Return);
const char * easyar_ARCoreDeviceListDownloader__typeName(const easyar_ARCoreDeviceListDownloader * This);

#ifdef __cplusplus
}
#endif

#endif
