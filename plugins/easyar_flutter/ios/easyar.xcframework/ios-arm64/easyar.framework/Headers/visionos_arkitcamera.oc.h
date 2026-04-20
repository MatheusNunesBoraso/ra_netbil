//=============================================================================================================================
//
// EasyAR Sense 4.8.0.11837-e0e3282d9
// Copyright (c) 2015-2026 VisionStar Information Technology (Shanghai) Co., Ltd. All Rights Reserved.
// EasyAR is the registered trademark or trademark of VisionStar Information Technology (Shanghai) Co., Ltd in China
// and other countries for the augmented reality technology developed by VisionStar Information Technology (Shanghai) Co., Ltd.
//
//=============================================================================================================================

#import "easyar/types.oc.h"

/// <summary>
/// VisionOSARKitCameraDevice implements a camera device based on VisionOS ARKit, which outputs `InputFrame`_ (including image, camera parameters, timestamp, 6DOF location, and tracking status).
/// After creation, start/stop can be invoked to start or stop data collection.
/// When the component is not needed anymore, call close function to close it. It shall not be used after calling close.
/// VisionOSARKitCameraDevice outputs `InputFrame`_ from inputFrameSource. inputFrameSource shall be connected to `InputFrameSink`_ for use.
/// bufferCapacity is the capacity of `InputFrame`_ buffer. If the count of `InputFrame`_ which has been output from the device and have not been released is more than this number, the device will not output new `InputFrame`_ , until previous `InputFrame`_ have been released. This may cause screen stuck.
/// </summary>
@interface easyar_VisionOSARKitCameraDevice : easyar_RefBase

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

+ (easyar_VisionOSARKitCameraDevice *) create;
+ (bool)isAvailable;
/// <summary>
/// `InputFrame`_ buffer capacity. The default is 8.
/// </summary>
- (int)bufferCapacity;
/// <summary>
/// Sets `InputFrame`_ buffer capacity.
/// </summary>
- (void)setBufferCapacity:(int)capacity;
/// <summary>
/// Requests necessary permissions from VisionOS including [World Sensing] and [Camera Access]
/// </summary>
- (void)requestPermissions:(easyar_CallbackScheduler *)callbackScheduler permissionCallback:(void (^)(easyar_PermissionStatus status, NSString * value))permissionCallback;
/// <summary>
/// `InputFrame`_ output port.
/// </summary>
- (easyar_InputFrameSource *)inputFrameSource;
/// <summary>
/// Get synchoronous motion input data.
/// </summary>
- (easyar_MotionInputData *)getMotionInputData;
/// <summary>
/// Starts video stream capture.
/// </summary>
- (bool)start;
/// <summary>
/// Stops video stream capture.
/// </summary>
- (void)stop;
/// <summary>
/// Close. The component shall not be used after calling close.
/// </summary>
- (void)close;
/// <summary>
/// Gets the current preview size.
/// </summary>
- (easyar_Vec2I *)size;
/// <summary>
/// Camera type.
/// </summary>
- (easyar_CameraDeviceType)type;
/// <summary>
/// Angles rotation required to rotate clockwise and display camera image on device with natural orientation.
/// </summary>
- (int)cameraOrientation;
/// <summary>
/// Gets lower bound of current frame rate range.
/// </summary>
- (double)frameRateRangeLower;
/// <summary>
/// Gets upper bound of current frame rate range.
/// </summary>
- (double)frameRateRangeUpper;

@end
