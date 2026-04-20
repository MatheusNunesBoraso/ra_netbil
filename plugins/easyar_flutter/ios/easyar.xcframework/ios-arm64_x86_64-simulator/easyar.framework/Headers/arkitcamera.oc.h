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
/// ARKitCameraDevice implements a camera device based on ARKit, which outputs `InputFrame`_ (including image, camera parameters, timestamp, 6DOF location, and tracking status).
/// After creation, start/stop can be invoked to start or stop data collection.
/// When the component is not needed anymore, call close function to close it. It shall not be used after calling close.
/// ARKitCameraDevice outputs `InputFrame`_ from inputFrameSource. inputFrameSource shall be connected to `InputFrameSink`_ for use.
/// bufferCapacity is the capacity of `InputFrame`_ buffer. If the count of `InputFrame`_ which has been output from the device and have not been released is more than this number, the device will not output new `InputFrame`_ , until previous `InputFrame`_ have been released. This may cause screen stuck.
/// </summary>
@interface easyar_ARKitCameraDevice : easyar_RefBase

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

+ (easyar_ARKitCameraDevice *) create;
/// <summary>
/// Checks if the component is available. It returns true only on iOS 11 or later when ARKit is supported by hardware.
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
/// Sets focus mode to focusMode. Call before start. Valid since iOS 11.3.
/// </summary>
- (void)setFocusMode:(easyar_ARKitCameraDeviceFocusMode)focusMode;
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
/// Camera type.
/// </summary>
- (easyar_CameraDeviceType)type;
/// <summary>
/// Angles rotation required to rotate clockwise and display camera image on device with natural orientation.
/// </summary>
- (int)cameraOrientation;
/// <summary>
/// Gets the current preview size.
/// </summary>
- (easyar_Vec2I *)size;
/// <summary>
/// Gets the current frame rate.
/// </summary>
- (double)frameRate;
/// <summary>
/// Gets the number of supported preview sizes.
/// </summary>
- (int)supportedSizeCount;
/// <summary>
/// Gets the index-th supported preview size. It returns {0, 0} if index is out of range.
/// </summary>
- (easyar_Vec2I *)supportedSize:(int)index;
/// <summary>
/// Sets the preview size. The available nearest value will be selected. Call size to get the actual size. frameRateRange may change after calling setSize.
/// </summary>
- (bool)setSize:(easyar_Vec2I *)size;
/// <summary>
/// Gets the number of supported frame rates.
/// </summary>
- (int)supportedFrameRateCount;
/// <summary>
/// Gets the index-th supported frame rates
/// </summary>
- (double)supportedFrameRate:(int)index;
/// <summary>
/// Sets frame rate.
/// </summary>
- (bool)setFrameRate:(double)frameRate;

@end
