//=============================================================================================================================
//
// EasyAR Sense 4.8.0.11837-e0e3282d9
// Copyright (c) 2015-2026 VisionStar Information Technology (Shanghai) Co., Ltd. All Rights Reserved.
// EasyAR is the registered trademark or trademark of VisionStar Information Technology (Shanghai) Co., Ltd in China
// and other countries for the augmented reality technology developed by VisionStar Information Technology (Shanghai) Co., Ltd.
//
//=============================================================================================================================

#ifndef __EASYAR_INS_H__
#define __EASYAR_INS_H__

#include "easyar/types.h"

#ifdef __cplusplus
extern "C" {
#endif

/// <summary>
/// Default create method.
/// </summary>
void easyar_InertialCameraDevice__ctor(/* OUT */ easyar_InertialCameraDevice * * Return);
/// <summary>
/// Checks if the component is available. It returns true only on Android 7.0 (API Level 24+) when accelerometer, gyroscope and attitude sensor are all available.
/// </summary>
bool easyar_InertialCameraDevice_isAvailable(void);
/// <summary>
/// `InputFrame`_ buffer capacity. The default is 8.
/// </summary>
int easyar_InertialCameraDevice_bufferCapacity(const easyar_InertialCameraDevice * This);
/// <summary>
/// Sets `InputFrame`_ buffer capacity.
/// </summary>
void easyar_InertialCameraDevice_setBufferCapacity(easyar_InertialCameraDevice * This, int capacity);
/// <summary>
/// `InputFrame`_ output port.
/// </summary>
void easyar_InertialCameraDevice_inputFrameSource(easyar_InertialCameraDevice * This, /* OUT */ easyar_InputFrameSource * * Return);
/// <summary>
/// Sets focus mode to focusMode. Call before start.
/// </summary>
void easyar_InertialCameraDevice_setFocusMode(easyar_InertialCameraDevice * This, easyar_InertialCameraDeviceFocusMode focusMode);
/// <summary>
/// Camera type. Call after a successful open.
/// </summary>
easyar_CameraDeviceType easyar_InertialCameraDevice_type(const easyar_InertialCameraDevice * This);
/// <summary>
/// Angles rotation required to rotate clockwise and display camera image on device with natural orientation. Call after a successful open.
/// </summary>
int easyar_InertialCameraDevice_cameraOrientation(const easyar_InertialCameraDevice * This);
/// <summary>
/// Gets the current preview size. Call after a successful open.
/// </summary>
easyar_Vec2I easyar_InertialCameraDevice_size(const easyar_InertialCameraDevice * This);
/// <summary>
/// Gets the number of supported preview sizes. Call after a successful open.
/// </summary>
int easyar_InertialCameraDevice_supportedSizeCount(const easyar_InertialCameraDevice * This);
/// <summary>
/// Gets the index-th supported preview size. It returns {0, 0} if index is out of range. Call after a successful open.
/// </summary>
easyar_Vec2I easyar_InertialCameraDevice_supportedSize(const easyar_InertialCameraDevice * This, int index);
/// <summary>
/// Sets the preview size. The available nearest value will be selected. Call size to get the actual size. Call after a successful open. frameRateRange may change after calling setSize.
/// </summary>
bool easyar_InertialCameraDevice_setSize(easyar_InertialCameraDevice * This, easyar_Vec2I size);
/// <summary>
/// Opens back camera of device. If the opening fails will return false.
/// </summary>
bool easyar_InertialCameraDevice_open(easyar_InertialCameraDevice * This);
/// <summary>
/// Starts video stream capture.
/// </summary>
bool easyar_InertialCameraDevice_start(easyar_InertialCameraDevice * This);
/// <summary>
/// Stops video stream capture.
/// </summary>
void easyar_InertialCameraDevice_stop(easyar_InertialCameraDevice * This);
/// <summary>
/// Resets states.
/// </summary>
void easyar_InertialCameraDevice_reset(easyar_InertialCameraDevice * This);
/// <summary>
/// Close. The component shall not be used after calling close.
/// </summary>
void easyar_InertialCameraDevice_close(easyar_InertialCameraDevice * This);
/// <summary>
/// Gets lower bound of current frame rate range. Call after a successful open.
/// </summary>
double easyar_InertialCameraDevice_frameRateRangeLower(const easyar_InertialCameraDevice * This);
/// <summary>
/// Gets upper bound of current frame rate range. Call after a successful open.
/// </summary>
double easyar_InertialCameraDevice_frameRateRangeUpper(const easyar_InertialCameraDevice * This);
void easyar_InertialCameraDevice__dtor(easyar_InertialCameraDevice * This);
void easyar_InertialCameraDevice__retain(const easyar_InertialCameraDevice * This, /* OUT */ easyar_InertialCameraDevice * * Return);
const char * easyar_InertialCameraDevice__typeName(const easyar_InertialCameraDevice * This);

#ifdef __cplusplus
}
#endif

#endif
