//=============================================================================================================================
//
// EasyAR Sense 4.8.0.11837-e0e3282d9
// Copyright (c) 2015-2026 VisionStar Information Technology (Shanghai) Co., Ltd. All Rights Reserved.
// EasyAR is the registered trademark or trademark of VisionStar Information Technology (Shanghai) Co., Ltd in China
// and other countries for the augmented reality technology developed by VisionStar Information Technology (Shanghai) Co., Ltd.
//
//=============================================================================================================================

#ifndef __EASYAR_GYROSCOPE_H__
#define __EASYAR_GYROSCOPE_H__

#include "easyar/types.h"

#ifdef __cplusplus
extern "C" {
#endif

void easyar_Gyroscope__ctor(/* OUT */ easyar_Gyroscope * * Return);
/// <summary>
/// Checks if the component is available. It returns true only on Android or iOS with supported hardware. On other operating systems, it is not supported.
/// </summary>
bool easyar_Gyroscope_isAvailable(easyar_Gyroscope * This);
/// <summary>
/// Output port.
/// </summary>
void easyar_Gyroscope_output(easyar_Gyroscope * This, /* OUT */ easyar_GyroscopeResultSource * * Return);
/// <summary>
/// Opens the device. Sampling period is defined by implementation. If failed, it will return false.
/// </summary>
bool easyar_Gyroscope_open(easyar_Gyroscope * This);
/// <summary>
/// Opens the device with a specific sampling period. Sampling period is limited by hardware and may not reach the specified value. If failed, it will return false.
/// </summary>
bool easyar_Gyroscope_openWithSamplingPeriod(easyar_Gyroscope * This, int samplingPeriodMilliseconds);
/// <summary>
/// Closes. It shall not be used after calling close.
/// </summary>
void easyar_Gyroscope_close(easyar_Gyroscope * This);
/// <summary>
/// Gets the most recent result. If there is no result, it returns empty.
/// </summary>
easyar_OptionalOfGyroscopeResult easyar_Gyroscope_getCurrentResult(easyar_Gyroscope * This);
void easyar_Gyroscope__dtor(easyar_Gyroscope * This);
void easyar_Gyroscope__retain(const easyar_Gyroscope * This, /* OUT */ easyar_Gyroscope * * Return);
const char * easyar_Gyroscope__typeName(const easyar_Gyroscope * This);

#ifdef __cplusplus
}
#endif

#endif
