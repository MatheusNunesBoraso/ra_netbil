//=============================================================================================================================
//
// EasyAR Sense 4.8.0.11837-e0e3282d9
// Copyright (c) 2015-2026 VisionStar Information Technology (Shanghai) Co., Ltd. All Rights Reserved.
// EasyAR is the registered trademark or trademark of VisionStar Information Technology (Shanghai) Co., Ltd in China
// and other countries for the augmented reality technology developed by VisionStar Information Technology (Shanghai) Co., Ltd.
//
//=============================================================================================================================

#ifndef __EASYAR_MAGNETOMETER_H__
#define __EASYAR_MAGNETOMETER_H__

#include "easyar/types.h"

#ifdef __cplusplus
extern "C" {
#endif

void easyar_Magnetometer__ctor(/* OUT */ easyar_Magnetometer * * Return);
/// <summary>
/// Checks if the component is available. It returns true only on Android or iOS with supported hardware. On other operating systems, it is not supported.
/// </summary>
bool easyar_Magnetometer_isAvailable(easyar_Magnetometer * This);
/// <summary>
/// Output port.
/// </summary>
void easyar_Magnetometer_output(easyar_Magnetometer * This, /* OUT */ easyar_MagnetometerResultSource * * Return);
/// <summary>
/// Opens the device. Sampling period is defined by implementation. If failed, it will return false.
/// </summary>
bool easyar_Magnetometer_open(easyar_Magnetometer * This);
/// <summary>
/// Opens the device with a specific sampling period. Sampling period is limited by hardware and may not reach the specified value. If failed, it will return false.
/// </summary>
bool easyar_Magnetometer_openWithSamplingPeriod(easyar_Magnetometer * This, int samplingPeriodMilliseconds);
/// <summary>
/// Closes. It shall not be used after calling close.
/// </summary>
void easyar_Magnetometer_close(easyar_Magnetometer * This);
/// <summary>
/// Gets the most recent result. If there is no result, it returns empty.
/// </summary>
easyar_OptionalOfMagnetometerResult easyar_Magnetometer_getCurrentResult(easyar_Magnetometer * This);
void easyar_Magnetometer__dtor(easyar_Magnetometer * This);
void easyar_Magnetometer__retain(const easyar_Magnetometer * This, /* OUT */ easyar_Magnetometer * * Return);
const char * easyar_Magnetometer__typeName(const easyar_Magnetometer * This);

#ifdef __cplusplus
}
#endif

#endif
