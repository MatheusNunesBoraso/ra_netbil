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
/// ThreeDofCameraDevice implements a three dof camera device, which outputs `InputFrame`_ which `CameraTransformType`_ is ThreeDofRotOnly (including image, camera parameters, timestamp, camera transform matrix and tracking status).
/// After creation, start/stop can be invoked to start or stop video stream capture.
/// When the component is not needed anymore, call close function to close it. It shall not be used after calling close.
/// ThreeDofCameraDevice outputs `InputFrame`_ from inputFrameSource. inputFrameSource shall be connected to `InputFrameSink`_ for use.
/// bufferCapacity is the capacity of `InputFrame`_ buffer. If the count of `InputFrame`_ which has been output from the device and have not been released is more than this number, the device will not output new `InputFrame`_ , until previous `InputFrame`_ have been released. This may cause screen stuck.
/// </summary>
@interface easyar_ThreeDofCameraDevice : easyar_RefBase

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

/// <summary>
/// Default create method.
/// </summary>
+ (easyar_ThreeDofCameraDevice *) create;
/// <summary>
/// Checks if the component is available. It returns true only on Android or IOS when the gyroscope is available.
/// </summary>
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
/// `InputFrame`_ output port.
/// </summary>
- (easyar_InputFrameSource *)inputFrameSource;
/// <summary>
/// Sets focus mode to focusMode. Call before start.
/// </summary>
- (void)setFocusMode:(easyar_ThreeDofCameraDeviceFocusMode)focusMode;
/// <summary>
/// Camera type. Call after a successful open.
/// </summary>
- (easyar_CameraDeviceType)type;
/// <summary>
/// Angles rotation required to rotate clockwise and display camera image on device with natural orientation. Call after a successful open.
/// </summary>
- (int)cameraOrientation;
/// <summary>
/// Gets the current preview size. Call after a successful open.
/// </summary>
- (easyar_Vec2I *)size;
/// <summary>
/// Gets the number of supported preview sizes. Call after a successful open.
/// </summary>
- (int)supportedSizeCount;
/// <summary>
/// Gets the index-th supported preview size. It returns {0, 0} if index is out of range. Call after a successful open.
/// </summary>
- (easyar_Vec2I *)supportedSize:(int)index;
/// <summary>
/// Sets the preview size. The available nearest value will be selected. Call size to get the actual size. Call after a successful open. frameRateRange may change after calling setSize.
/// </summary>
- (bool)setSize:(easyar_Vec2I *)size;
/// <summary>
/// Opens back camera of device. If the opening fails will return false.
/// </summary>
- (bool)open;
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
/// Gets lower bound of current frame rate range. Call after a successful open.
/// </summary>
- (double)frameRateRangeLower;
/// <summary>
/// Gets upper bound of current frame rate range. Call after a successful open.
/// </summary>
- (double)frameRateRangeUpper;

@end
