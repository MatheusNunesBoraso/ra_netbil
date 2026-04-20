//=============================================================================================================================
//
// EasyAR Sense 4.8.0.11837-e0e3282d9
// Copyright (c) 2015-2026 VisionStar Information Technology (Shanghai) Co., Ltd. All Rights Reserved.
// EasyAR is the registered trademark or trademark of VisionStar Information Technology (Shanghai) Co., Ltd in China
// and other countries for the augmented reality technology developed by VisionStar Information Technology (Shanghai) Co., Ltd.
//
//=============================================================================================================================

#ifndef __EASYAR_MOTIONTRACKER_H__
#define __EASYAR_MOTIONTRACKER_H__

#include "easyar/types.h"

#ifdef __cplusplus
extern "C" {
#endif

/// <summary>
/// Create MotionTrackerCameraDevice object.
/// </summary>
void easyar_MotionTrackerCameraDevice__ctor(/* OUT */ easyar_MotionTrackerCameraDevice * * Return);
/// <summary>
/// Check if the devices supports motion tracking. It returns True if the device supports Motion Tracking, otherwise it returns False.
/// </summary>
bool easyar_MotionTrackerCameraDevice_isAvailable(void);
/// <summary>
/// Get the quality of Motion Tracking on the device. You can decide whether to start Motion Tracking.
/// </summary>
easyar_MotionTrackerCameraDeviceQualityLevel easyar_MotionTrackerCameraDevice_getQualityLevel(void);
/// <summary>
/// Sets current frame rate. Call before start. If this function is not called, the default is 30 fps.
/// </summary>
bool easyar_MotionTrackerCameraDevice_setFrameRateType(easyar_MotionTrackerCameraDevice * This, easyar_MotionTrackerCameraDeviceFPS fps);
/// <summary>
/// Sets focus mode. Call before start. If this function is not called, the default is Continousauto.
/// </summary>
bool easyar_MotionTrackerCameraDevice_setFocusMode(easyar_MotionTrackerCameraDevice * This, easyar_MotionTrackerCameraDeviceFocusMode focusMode);
/// <summary>
/// Sets frame resolution. Call before start. If this function is not called, the default is 1280 x 960 or 1280 x 720.
/// </summary>
bool easyar_MotionTrackerCameraDevice_setFrameResolutionType(easyar_MotionTrackerCameraDevice * This, easyar_MotionTrackerCameraDeviceResolution resolution);
/// <summary>
/// Sets tracking mode. Call before start. If this function is not called, the default is Anchor.
/// </summary>
bool easyar_MotionTrackerCameraDevice_setTrackingMode(easyar_MotionTrackerCameraDevice * This, easyar_MotionTrackerCameraDeviceTrackingMode trackingMode);
/// <summary>
/// Set `InputFrame`_ buffer capacity.
/// bufferCapacity is the capacity of `InputFrame`_ buffer. If the count of `InputFrame`_ which has been output from the device and have not been released is higher than this number, the device will not output new `InputFrame`_ until previous `InputFrame`_ has been released. This may cause screen stuck.
/// </summary>
void easyar_MotionTrackerCameraDevice_setBufferCapacity(easyar_MotionTrackerCameraDevice * This, int capacity);
/// <summary>
/// Get `InputFrame`_ buffer capacity. The default is 8.
/// </summary>
int easyar_MotionTrackerCameraDevice_bufferCapacity(const easyar_MotionTrackerCameraDevice * This);
/// <summary>
/// `InputFrame`_ output port.
/// </summary>
void easyar_MotionTrackerCameraDevice_inputFrameSource(easyar_MotionTrackerCameraDevice * This, /* OUT */ easyar_InputFrameSource * * Return);
/// <summary>
/// Start motion tracking or resume motion tracking after pause.
/// Notice: Calling start after pausing will trigger device relocalization. Tracking will resume when the relocalization process succeeds.
/// </summary>
bool easyar_MotionTrackerCameraDevice_start(easyar_MotionTrackerCameraDevice * This);
/// <summary>
/// Pause motion tracking. Call `start` to trigger relocation, resume motion tracking if the relocation succeeds.
/// </summary>
void easyar_MotionTrackerCameraDevice_stop(easyar_MotionTrackerCameraDevice * This);
/// <summary>
/// Close motion tracking. The component shall not be used after calling close.
/// </summary>
void easyar_MotionTrackerCameraDevice_close(easyar_MotionTrackerCameraDevice * This);
/// <summary>
/// Camera type. Call after a successful start.
/// </summary>
easyar_CameraDeviceType easyar_MotionTrackerCameraDevice_type(const easyar_MotionTrackerCameraDevice * This);
/// <summary>
/// Angles rotation required to rotate clockwise and display camera image on device with natural orientation. Call after a successful start.
/// </summary>
int easyar_MotionTrackerCameraDevice_cameraOrientation(const easyar_MotionTrackerCameraDevice * This);
/// <summary>
/// Gets the current preview size. Call after a successful start.
/// </summary>
easyar_Vec2I easyar_MotionTrackerCameraDevice_size(const easyar_MotionTrackerCameraDevice * This);
/// <summary>
/// Gets lower bound of current frame rate range. Call after a successful open.
/// </summary>
double easyar_MotionTrackerCameraDevice_frameRateRangeLower(const easyar_MotionTrackerCameraDevice * This);
/// <summary>
/// Gets upper bound of current frame rate range. Call after a successful open.
/// </summary>
double easyar_MotionTrackerCameraDevice_frameRateRangeUpper(const easyar_MotionTrackerCameraDevice * This);
/// <summary>
/// Perform hit test against the point cloud and return the nearest 3D point. The 3D point is represented by three consecutive values, representing X, Y, Z position coordinates in the world coordinate space.
/// For the camera image coordinate system ([0, 1]^2), x-right, y-down, and origin is at left-top corner. `CameraParameters.imageCoordinatesFromScreenCoordinates`_ can be used to convert points from screen coordinate system to camera image coordinate system.
/// </summary>
void easyar_MotionTrackerCameraDevice_hitTestAgainstPointCloud(easyar_MotionTrackerCameraDevice * This, easyar_Vec2F cameraImagePoint, /* OUT */ easyar_ListOfVec3F * * Return);
/// <summary>
/// Performs ray cast from the user&#39;s device in the direction of given screen point.
/// Intersections with horizontal plane is detected in real time in the current field of view,and return the 3D point nearest to ray on horizontal plane.
/// For the camera image coordinate system ([0, 1]^2), x-right, y-down, and origin is at left-top corner. `CameraParameters.imageCoordinatesFromScreenCoordinates`_ can be used to convert points from screen coordinate system to camera image coordinate system.
/// The output point cloud coordinate on Horizontal plane is in the world coordinate system. The 3D point is represented by three consecutive values, representing X, Y, Z position coordinates in the world coordinate space.
/// </summary>
void easyar_MotionTrackerCameraDevice_hitTestAgainstHorizontalPlane(easyar_MotionTrackerCameraDevice * This, easyar_Vec2F cameraImagePoint, /* OUT */ easyar_ListOfVec3F * * Return);
/// <summary>
/// Returns the vector of point cloud coordinate. Each 3D point is represented by three consecutive values, representing X, Y, Z position coordinates in the world coordinate space.
/// </summary>
void easyar_MotionTrackerCameraDevice_getLocalPointsCloud(easyar_MotionTrackerCameraDevice * This, /* OUT */ easyar_ListOfVec3F * * Return);
void easyar_MotionTrackerCameraDevice__dtor(easyar_MotionTrackerCameraDevice * This);
void easyar_MotionTrackerCameraDevice__retain(const easyar_MotionTrackerCameraDevice * This, /* OUT */ easyar_MotionTrackerCameraDevice * * Return);
const char * easyar_MotionTrackerCameraDevice__typeName(const easyar_MotionTrackerCameraDevice * This);

void easyar_ListOfVec3F__ctor(easyar_Vec3F const * begin, easyar_Vec3F const * end, /* OUT */ easyar_ListOfVec3F * * Return);
void easyar_ListOfVec3F__dtor(easyar_ListOfVec3F * This);
void easyar_ListOfVec3F_copy(const easyar_ListOfVec3F * This, /* OUT */ easyar_ListOfVec3F * * Return);
int easyar_ListOfVec3F_size(const easyar_ListOfVec3F * This);
easyar_Vec3F easyar_ListOfVec3F_at(const easyar_ListOfVec3F * This, int index);

#ifdef __cplusplus
}
#endif

#endif
