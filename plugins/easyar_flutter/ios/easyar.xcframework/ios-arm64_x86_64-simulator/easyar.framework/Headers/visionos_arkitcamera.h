//=============================================================================================================================
//
// EasyAR Sense 4.8.0.11837-e0e3282d9
// Copyright (c) 2015-2026 VisionStar Information Technology (Shanghai) Co., Ltd. All Rights Reserved.
// EasyAR is the registered trademark or trademark of VisionStar Information Technology (Shanghai) Co., Ltd in China
// and other countries for the augmented reality technology developed by VisionStar Information Technology (Shanghai) Co., Ltd.
//
//=============================================================================================================================

#ifndef __EASYAR_VISIONOS_ARKITCAMERA_H__
#define __EASYAR_VISIONOS_ARKITCAMERA_H__

#include "easyar/types.h"

#ifdef __cplusplus
extern "C" {
#endif

void easyar_VisionOSARKitCameraDevice__ctor(/* OUT */ easyar_VisionOSARKitCameraDevice * * Return);
bool easyar_VisionOSARKitCameraDevice_isAvailable(void);
/// <summary>
/// `InputFrame`_ buffer capacity. The default is 8.
/// </summary>
int easyar_VisionOSARKitCameraDevice_bufferCapacity(const easyar_VisionOSARKitCameraDevice * This);
/// <summary>
/// Sets `InputFrame`_ buffer capacity.
/// </summary>
void easyar_VisionOSARKitCameraDevice_setBufferCapacity(easyar_VisionOSARKitCameraDevice * This, int capacity);
/// <summary>
/// Requests necessary permissions from VisionOS including [World Sensing] and [Camera Access]
/// </summary>
void easyar_VisionOSARKitCameraDevice_requestPermissions(easyar_VisionOSARKitCameraDevice * This, easyar_CallbackScheduler * callbackScheduler, easyar_OptionalOfFunctorOfVoidFromPermissionStatusAndString permissionCallback);
/// <summary>
/// `InputFrame`_ output port.
/// </summary>
void easyar_VisionOSARKitCameraDevice_inputFrameSource(easyar_VisionOSARKitCameraDevice * This, /* OUT */ easyar_InputFrameSource * * Return);
/// <summary>
/// Get synchoronous motion input data.
/// </summary>
void easyar_VisionOSARKitCameraDevice_getMotionInputData(easyar_VisionOSARKitCameraDevice * This, /* OUT */ easyar_OptionalOfMotionInputData * Return);
/// <summary>
/// Starts video stream capture.
/// </summary>
bool easyar_VisionOSARKitCameraDevice_start(easyar_VisionOSARKitCameraDevice * This);
/// <summary>
/// Stops video stream capture.
/// </summary>
void easyar_VisionOSARKitCameraDevice_stop(easyar_VisionOSARKitCameraDevice * This);
/// <summary>
/// Close. The component shall not be used after calling close.
/// </summary>
void easyar_VisionOSARKitCameraDevice_close(easyar_VisionOSARKitCameraDevice * This);
/// <summary>
/// Gets the current preview size.
/// </summary>
easyar_Vec2I easyar_VisionOSARKitCameraDevice_size(const easyar_VisionOSARKitCameraDevice * This);
/// <summary>
/// Camera type.
/// </summary>
easyar_CameraDeviceType easyar_VisionOSARKitCameraDevice_type(const easyar_VisionOSARKitCameraDevice * This);
/// <summary>
/// Angles rotation required to rotate clockwise and display camera image on device with natural orientation.
/// </summary>
int easyar_VisionOSARKitCameraDevice_cameraOrientation(const easyar_VisionOSARKitCameraDevice * This);
/// <summary>
/// Gets lower bound of current frame rate range.
/// </summary>
double easyar_VisionOSARKitCameraDevice_frameRateRangeLower(const easyar_VisionOSARKitCameraDevice * This);
/// <summary>
/// Gets upper bound of current frame rate range.
/// </summary>
double easyar_VisionOSARKitCameraDevice_frameRateRangeUpper(const easyar_VisionOSARKitCameraDevice * This);
void easyar_VisionOSARKitCameraDevice__dtor(easyar_VisionOSARKitCameraDevice * This);
void easyar_VisionOSARKitCameraDevice__retain(const easyar_VisionOSARKitCameraDevice * This, /* OUT */ easyar_VisionOSARKitCameraDevice * * Return);
const char * easyar_VisionOSARKitCameraDevice__typeName(const easyar_VisionOSARKitCameraDevice * This);

#ifdef __cplusplus
}
#endif

#endif
