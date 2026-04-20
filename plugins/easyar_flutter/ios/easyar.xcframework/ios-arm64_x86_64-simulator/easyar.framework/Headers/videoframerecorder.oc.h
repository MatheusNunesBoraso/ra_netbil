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
/// Input frame recorder.
/// There is an input frame input port and an input frame output port. It can be used to record input frames into an EIF MKV file.
/// All members of this class is thread-safe.
/// </summary>
@interface easyar_VideoInputFrameRecorder : easyar_RefBase

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

/// <summary>
/// Checks if the component is available. It returns true only on MacOS, iOS and Android.
/// </summary>
+ (bool)isAvailable;
/// <summary>
/// Input port.
/// </summary>
- (easyar_InputFrameSink *)input;
/// <summary>
/// Optional. Input port for accelerometer result. See also `AccelerometerResultSink`_ .
/// </summary>
- (easyar_AccelerometerResultSink *)accelerometerResultSink;
/// <summary>
/// Optional. Input port for gyroscope result. See also `GyroscopeResultSink`_ .
/// </summary>
- (easyar_GyroscopeResultSink *)gyroscopeResultSink;
/// <summary>
/// Optional. Input port for attitude sensor. See also `AttitudeSensorResultSink`_ .
/// </summary>
- (easyar_AttitudeSensorResultSink *)attitudeSensorResultSink;
/// <summary>
/// Optional. Input port for magnetometer. See also `MagnetometerResultSink`_ .
/// </summary>
- (easyar_MagnetometerResultSink *)magnetometerResultSink;
/// <summary>
/// Optional. Input port for location result. See also `LocationResultSink`_ .
/// </summary>
- (easyar_LocationResultSink *)locationResultSink;
/// <summary>
/// Optional. Input port for proximity location result. See also `ProximityLocationResultSink`_ .
/// </summary>
- (easyar_ProximityLocationResultSink *)proximityLocationResultSink;
/// <summary>
/// Camera buffers occupied in this component.
/// </summary>
- (int)bufferRequirement;
/// <summary>
/// Output port.
/// </summary>
- (easyar_InputFrameSource *)output;
/// <summary>
/// Creates an instance.
/// </summary>
+ (easyar_VideoInputFrameRecorder *)create;
/// <summary>
/// Starts frame recording. The definitions of cameraDeviceType, cameraOrientation and cameraOrientation are the same as in `CameraParameters`_ . initialScreenRotation is the initial screen rotation when recording data, and it will be used in rendering for playback.
/// </summary>
- (bool)start:(NSString *)filePath cameraDeviceType:(easyar_CameraDeviceType)cameraDeviceType cameraOrientation:(int)cameraOrientation initialScreenRotation:(int)initialScreenRotation codec:(easyar_VideoInputFrameRecorderVideoCodec)codec width:(int)width height:(int)height frameRate:(double)frameRate metadata:(NSString *)metadata;
/// <summary>
/// Stops frame recording. It will only stop recording and will not affect connection.
/// </summary>
- (void)stop;
/// <summary>
/// Sets callback for automatic completion of recording.
/// </summary>
- (void)setAutomaticCompletionCallback:(easyar_CallbackScheduler *)callbackScheduler automaticCompletionCallback:(void (^)(easyar_VideoInputFrameRecorderCompletionReason))automaticCompletionCallback;

@end

/// <summary>
/// Input frame player.
/// There is an input frame output port. It can be used to get input frame from an EIF MKV file.
/// All members of this class is thread-safe.
/// </summary>
@interface easyar_VideoInputFramePlayer : easyar_RefBase

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

/// <summary>
/// Checks if the component is available. It returns true only on Windows.
/// </summary>
+ (bool)isAvailable;
/// <summary>
/// Output port.
/// </summary>
- (easyar_InputFrameSource *)output;
/// <summary>
/// Output port for accelerometer result. See also `AccelerometerResultSource`_ .
/// </summary>
- (easyar_AccelerometerResultSource *)accelerometerResultSource;
/// <summary>
/// Output port for gyroscope result. See also `GyroscopeResultSource`_ .
/// </summary>
- (easyar_GyroscopeResultSource *)gyroscopeResultSource;
/// <summary>
/// Output port for attitude sensor. See also `AttitudeSensorResultSource`_ .
/// </summary>
- (easyar_AttitudeSensorResultSource *)attitudeSensorResultSource;
/// <summary>
/// Output port for magnetometer. See also `MagnetometerResultSource`_ .
/// </summary>
- (easyar_MagnetometerResultSource *)magnetometerResultSource;
/// <summary>
/// Output port for location result. See also `LocationResultSource`_ .
/// </summary>
- (easyar_LocationResultSource *)locationResultSource;
/// <summary>
/// Output port for proximity location result. See also `ProximityLocationResultSource`_ .
/// </summary>
- (easyar_ProximityLocationResultSource *)proximityLocationResultSource;
/// <summary>
/// Creates an instance.
/// </summary>
+ (easyar_VideoInputFramePlayer *)create;
/// <summary>
/// Starts frame play.
/// </summary>
- (bool)start:(NSString *)filePath;
/// <summary>
/// Stops frame play.
/// </summary>
- (void)stop;
/// <summary>
/// Pauses frame play.
/// </summary>
- (void)pause;
/// <summary>
/// Resumes frame play.
/// </summary>
- (bool)resume;
/// <summary>
/// Total expected playback time span. The unit is second. If recording halts improperly, it may be missing.
/// </summary>
- (NSNumber *)totalTime;
/// <summary>
/// Current playback time point. The unit is second. The initial value is 0.
/// </summary>
- (double)currentTime;
/// <summary>
/// Whether the current playback time point can be relocated. If recording halts improperly, index data to set playback time point may be missing.
/// </summary>
- (bool)isSeekable;
/// <summary>
/// Sets current playback time point. The unit is second. If index data is missing, it returns false.
/// </summary>
- (bool)seek:(double)time;
/// <summary>
/// Current playback speed. The initial value is 1.
/// </summary>
- (double)speed;
/// <summary>
/// Sets current playback speed.
/// </summary>
- (void)setSpeed:(double)_value;
/// <summary>
/// The initial screen rotation when recording data.
/// </summary>
- (int)initalScreenRotation;
/// <summary>
/// The metadata when recording data.
/// </summary>
- (NSString *)metadata;
/// <summary>
/// Whether the playback is completed.
/// </summary>
- (bool)isCompleted;

@end
