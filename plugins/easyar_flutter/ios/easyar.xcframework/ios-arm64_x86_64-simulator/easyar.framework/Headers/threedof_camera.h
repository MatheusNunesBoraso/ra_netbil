//=============================================================================================================================
//
// EasyAR Sense 4.8.0.11837-e0e3282d9
// Copyright (c) 2015-2026 VisionStar Information Technology (Shanghai) Co., Ltd. All Rights Reserved.
// EasyAR is the registered trademark or trademark of VisionStar Information Technology (Shanghai) Co., Ltd in China
// and other countries for the augmented reality technology developed by VisionStar Information Technology (Shanghai) Co., Ltd.
//
//=============================================================================================================================

#ifndef __EASYAR_THREEDOF_CAMERA_H__
#define __EASYAR_THREEDOF_CAMERA_H__

#include "easyar/types.h"

#ifdef __cplusplus
extern "C" {
#endif

/// <summary>
/// Default create method.
/// </summary>
void easyar_ThreeDofCameraDevice__ctor(/* OUT */ easyar_ThreeDofCameraDevice * * Return);
/// <summary>
/// Checks if the component is available. It returns true only on Android or IOS when the gyroscope is available.
/// </summary>
bool easyar_ThreeDofCameraDevice_isAvailable(void);
/// <summary>
/// `InputFrame`_ buffer capacity. The default is 8.
/// </summary>
int easyar_ThreeDofCameraDevice_bufferCapacity(const easyar_ThreeDofCameraDevice * This);
/// <summary>
/// Sets `InputFrame`_ buffer capacity.
/// </summary>
void easyar_ThreeDofCameraDevice_setBufferCapacity(easyar_ThreeDofCameraDevice * This, int capacity);
/// <summary>
/// `InputFrame`_ output port.
/// </summary>
void easyar_ThreeDofCameraDevice_inputFrameSource(easyar_ThreeDofCameraDevice * This, /* OUT */ easyar_InputFrameSource * * Return);
/// <summary>
/// Sets focus mode to focusMode. Call before start.
/// </summary>
void easyar_ThreeDofCameraDevice_setFocusMode(easyar_ThreeDofCameraDevice * This, easyar_ThreeDofCameraDeviceFocusMode focusMode);
/// <summary>
/// Camera type. Call after a successful open.
/// </summary>
easyar_CameraDeviceType easyar_ThreeDofCameraDevice_type(const easyar_ThreeDofCameraDevice * This);
/// <summary>
/// Angles rotation required to rotate clockwise and display camera image on device with natural orientation. Call after a successful open.
/// </summary>
int easyar_ThreeDofCameraDevice_cameraOrientation(const easyar_ThreeDofCameraDevice * This);
/// <summary>
/// Gets the current preview size. Call after a successful open.
/// </summary>
easyar_Vec2I easyar_ThreeDofCameraDevice_size(const easyar_ThreeDofCameraDevice * This);
/// <summary>
/// Gets the number of supported preview sizes. Call after a successful open.
/// </summary>
int easyar_ThreeDofCameraDevice_supportedSizeCount(const easyar_ThreeDofCameraDevice * This);
/// <summary>
/// Gets the index-th supported preview size. It returns {0, 0} if index is out of range. Call after a successful open.
/// </summary>
easyar_Vec2I easyar_ThreeDofCameraDevice_supportedSize(const easyar_ThreeDofCameraDevice * This, int index);
/// <summary>
/// Sets the preview size. The available nearest value will be selected. Call size to get the actual size. Call after a successful open. frameRateRange may change after calling setSize.
/// </summary>
bool easyar_ThreeDofCameraDevice_setSize(easyar_ThreeDofCameraDevice * This, easyar_Vec2I size);
/// <summary>
/// Opens back camera of device. If the opening fails will return false.
/// </summary>
bool easyar_ThreeDofCameraDevice_open(easyar_ThreeDofCameraDevice * This);
/// <summary>
/// Starts video stream capture.
/// </summary>
bool easyar_ThreeDofCameraDevice_start(easyar_ThreeDofCameraDevice * This);
/// <summary>
/// Stops video stream capture.
/// </summary>
void easyar_ThreeDofCameraDevice_stop(easyar_ThreeDofCameraDevice * This);
/// <summary>
/// Close. The component shall not be used after calling close.
/// </summary>
void easyar_ThreeDofCameraDevice_close(easyar_ThreeDofCameraDevice * This);
/// <summary>
/// Gets lower bound of current frame rate range. Call after a successful open.
/// </summary>
double easyar_ThreeDofCameraDevice_frameRateRangeLower(const easyar_ThreeDofCameraDevice * This);
/// <summary>
/// Gets upper bound of current frame rate range. Call after a successful open.
/// </summary>
double easyar_ThreeDofCameraDevice_frameRateRangeUpper(const easyar_ThreeDofCameraDevice * This);
void easyar_ThreeDofCameraDevice__dtor(easyar_ThreeDofCameraDevice * This);
void easyar_ThreeDofCameraDevice__retain(const easyar_ThreeDofCameraDevice * This, /* OUT */ easyar_ThreeDofCameraDevice * * Return);
const char * easyar_ThreeDofCameraDevice__typeName(const easyar_ThreeDofCameraDevice * This);

#ifdef __cplusplus
}
#endif

#endif
