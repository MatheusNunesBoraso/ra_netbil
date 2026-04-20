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
/// XREALCameraDevice implements a camera device based on XREAL Enterprise Native SDK Plugin, which outputs `InputFrame`_ (image, camera parameters, timestamp, 6DOF location, and tracking status cannot be accessed).
/// After creation, start/stop can be invoked to start or stop data collection. Start must not be called before isDeviceSupported returns true.
/// When the component is not needed anymore, call close function to close it. It shall not be used after calling close.
/// XREALCameraDevice outputs `InputFrame`_ from inputFrameSource. inputFrameSource shall be connected to `InputFrameSink`_ for use.
/// bufferCapacity is the capacity of `InputFrame`_ buffer. If the count of `InputFrame`_ which has been output from the device and have not been released is more than this number, the device will not output new `InputFrame`_ , until previous `InputFrame`_ have been released. This may cause screen stuck.
/// </summary>
@interface easyar_XREALCameraDevice : easyar_RefBase

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

+ (easyar_XREALCameraDevice *) create;
/// <summary>
/// Checks if the component is available. It returns true only when XREAL eyewear is connected on the device supported.
/// </summary>
+ (bool)isAvailable;
/// <summary>
/// Checks if the eyewear is supported. Has value only after XREAL finishes initialization on devices where isAvailable is ture.
/// </summary>
+ (NSNumber *)isDeviceSupported;
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
/// Get synchoronous motion input data. Call after isDeviceSupported return true.
/// </summary>
- (easyar_MotionInputData *)getMotionInputData;
/// <summary>
/// Received frame count from camera. It should continously increase after start, otherwise the device connection may not be stable or XREAL service/SDK not working correctly, and you need to get help from XREAL directly.
/// </summary>
- (int)receivedFrameCount;
/// <summary>
/// Opens camera. Call after isDeviceSupported return true. XREAL license must be validated through XREAL official method on Air2 Ultra and some other devices before open.
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
/// Gets the current frame rate. Call after a successful open.
/// </summary>
- (double)frameRate;

@end
