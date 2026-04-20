//=============================================================================================================================
//
// EasyAR Sense 4.8.0.11837-e0e3282d9
// Copyright (c) 2015-2026 VisionStar Information Technology (Shanghai) Co., Ltd. All Rights Reserved.
// EasyAR is the registered trademark or trademark of VisionStar Information Technology (Shanghai) Co., Ltd in China
// and other countries for the augmented reality technology developed by VisionStar Information Technology (Shanghai) Co., Ltd.
//
//=============================================================================================================================

#ifndef __EASYAR_XREALCAMERA_H__
#define __EASYAR_XREALCAMERA_H__

#include "easyar/types.h"

#ifdef __cplusplus
extern "C" {
#endif

void easyar_XREALCameraDevice__ctor(/* OUT */ easyar_XREALCameraDevice * * Return);
/// <summary>
/// Checks if the component is available. It returns true only when XREAL eyewear is connected on the device supported.
/// </summary>
bool easyar_XREALCameraDevice_isAvailable(void);
/// <summary>
/// Checks if the eyewear is supported. Has value only after XREAL finishes initialization on devices where isAvailable is ture.
/// </summary>
easyar_OptionalOfBool easyar_XREALCameraDevice_isDeviceSupported(void);
/// <summary>
/// `InputFrame`_ buffer capacity. The default is 8.
/// </summary>
int easyar_XREALCameraDevice_bufferCapacity(const easyar_XREALCameraDevice * This);
/// <summary>
/// Sets `InputFrame`_ buffer capacity.
/// </summary>
void easyar_XREALCameraDevice_setBufferCapacity(easyar_XREALCameraDevice * This, int capacity);
/// <summary>
/// `InputFrame`_ output port.
/// </summary>
void easyar_XREALCameraDevice_inputFrameSource(const easyar_XREALCameraDevice * This, /* OUT */ easyar_InputFrameSource * * Return);
/// <summary>
/// Get synchoronous motion input data. Call after isDeviceSupported return true.
/// </summary>
void easyar_XREALCameraDevice_getMotionInputData(const easyar_XREALCameraDevice * This, /* OUT */ easyar_OptionalOfMotionInputData * Return);
/// <summary>
/// Received frame count from camera. It should continously increase after start, otherwise the device connection may not be stable or XREAL service/SDK not working correctly, and you need to get help from XREAL directly.
/// </summary>
int easyar_XREALCameraDevice_receivedFrameCount(const easyar_XREALCameraDevice * This);
/// <summary>
/// Opens camera. Call after isDeviceSupported return true. XREAL license must be validated through XREAL official method on Air2 Ultra and some other devices before open.
/// </summary>
bool easyar_XREALCameraDevice_open(easyar_XREALCameraDevice * This);
/// <summary>
/// Starts video stream capture.
/// </summary>
bool easyar_XREALCameraDevice_start(easyar_XREALCameraDevice * This);
/// <summary>
/// Stops video stream capture.
/// </summary>
void easyar_XREALCameraDevice_stop(easyar_XREALCameraDevice * This);
/// <summary>
/// Close. The component shall not be used after calling close.
/// </summary>
void easyar_XREALCameraDevice_close(easyar_XREALCameraDevice * This);
/// <summary>
/// Camera type. Call after a successful open.
/// </summary>
easyar_CameraDeviceType easyar_XREALCameraDevice_type(const easyar_XREALCameraDevice * This);
/// <summary>
/// Angles rotation required to rotate clockwise and display camera image on device with natural orientation. Call after a successful open.
/// </summary>
int easyar_XREALCameraDevice_cameraOrientation(const easyar_XREALCameraDevice * This);
/// <summary>
/// Gets the current preview size. Call after a successful open.
/// </summary>
easyar_Vec2I easyar_XREALCameraDevice_size(const easyar_XREALCameraDevice * This);
/// <summary>
/// Gets the current frame rate. Call after a successful open.
/// </summary>
double easyar_XREALCameraDevice_frameRate(const easyar_XREALCameraDevice * This);
void easyar_XREALCameraDevice__dtor(easyar_XREALCameraDevice * This);
void easyar_XREALCameraDevice__retain(const easyar_XREALCameraDevice * This, /* OUT */ easyar_XREALCameraDevice * * Return);
const char * easyar_XREALCameraDevice__typeName(const easyar_XREALCameraDevice * This);

#ifdef __cplusplus
}
#endif

#endif
