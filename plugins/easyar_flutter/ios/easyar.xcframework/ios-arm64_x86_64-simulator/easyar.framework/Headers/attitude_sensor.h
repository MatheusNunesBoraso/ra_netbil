//=============================================================================================================================
//
// EasyAR Sense 4.8.0.11837-e0e3282d9
// Copyright (c) 2015-2026 VisionStar Information Technology (Shanghai) Co., Ltd. All Rights Reserved.
// EasyAR is the registered trademark or trademark of VisionStar Information Technology (Shanghai) Co., Ltd in China
// and other countries for the augmented reality technology developed by VisionStar Information Technology (Shanghai) Co., Ltd.
//
//=============================================================================================================================

#ifndef __EASYAR_ATTITUDE_SENSOR_H__
#define __EASYAR_ATTITUDE_SENSOR_H__

#include "easyar/types.h"

#ifdef __cplusplus
extern "C" {
#endif

void easyar_AttitudeSensor__ctor(/* OUT */ easyar_AttitudeSensor * * Return);
/// <summary>
/// Checks if the component is available. It returns true only on Android or iOS with supported hardware. On other operating systems, it is not supported.
/// </summary>
bool easyar_AttitudeSensor_isAvailable(easyar_AttitudeSensor * This);
/// <summary>
/// Output port.
/// </summary>
void easyar_AttitudeSensor_output(easyar_AttitudeSensor * This, /* OUT */ easyar_AttitudeSensorResultSource * * Return);
/// <summary>
/// Opens the device. Sampling period is defined by implementation. If failed, it will return false.
/// </summary>
bool easyar_AttitudeSensor_open(easyar_AttitudeSensor * This);
/// <summary>
/// Opens the device with a specific sampling period. Sampling period is limited by hardware and may not reach the specified value. If failed, it will return false.
/// </summary>
bool easyar_AttitudeSensor_openWithSamplingPeriod(easyar_AttitudeSensor * This, int samplingPeriodMilliseconds);
/// <summary>
/// Closes. It shall not be used after calling close.
/// </summary>
void easyar_AttitudeSensor_close(easyar_AttitudeSensor * This);
/// <summary>
/// Gets the most recent result. If there is no result, it returns empty.
/// </summary>
easyar_OptionalOfAttitudeSensorResult easyar_AttitudeSensor_getCurrentResult(easyar_AttitudeSensor * This);
void easyar_AttitudeSensor__dtor(easyar_AttitudeSensor * This);
void easyar_AttitudeSensor__retain(const easyar_AttitudeSensor * This, /* OUT */ easyar_AttitudeSensor * * Return);
const char * easyar_AttitudeSensor__typeName(const easyar_AttitudeSensor * This);

#ifdef __cplusplus
}
#endif

#endif
