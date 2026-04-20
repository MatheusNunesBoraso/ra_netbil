//=============================================================================================================================
//
// EasyAR Sense 4.8.0.11837-e0e3282d9
// Copyright (c) 2015-2026 VisionStar Information Technology (Shanghai) Co., Ltd. All Rights Reserved.
// EasyAR is the registered trademark or trademark of VisionStar Information Technology (Shanghai) Co., Ltd in China
// and other countries for the augmented reality technology developed by VisionStar Information Technology (Shanghai) Co., Ltd.
//
//=============================================================================================================================

#ifndef __EASYAR_VIDEOFRAMERECORDER_H__
#define __EASYAR_VIDEOFRAMERECORDER_H__

#include "easyar/types.h"

#ifdef __cplusplus
extern "C" {
#endif

/// <summary>
/// Checks if the component is available. It returns true only on MacOS, iOS and Android.
/// </summary>
bool easyar_VideoInputFrameRecorder_isAvailable(void);
/// <summary>
/// Input port.
/// </summary>
void easyar_VideoInputFrameRecorder_input(easyar_VideoInputFrameRecorder * This, /* OUT */ easyar_InputFrameSink * * Return);
/// <summary>
/// Optional. Input port for accelerometer result. See also `AccelerometerResultSink`_ .
/// </summary>
void easyar_VideoInputFrameRecorder_accelerometerResultSink(easyar_VideoInputFrameRecorder * This, /* OUT */ easyar_AccelerometerResultSink * * Return);
/// <summary>
/// Optional. Input port for gyroscope result. See also `GyroscopeResultSink`_ .
/// </summary>
void easyar_VideoInputFrameRecorder_gyroscopeResultSink(easyar_VideoInputFrameRecorder * This, /* OUT */ easyar_GyroscopeResultSink * * Return);
/// <summary>
/// Optional. Input port for attitude sensor. See also `AttitudeSensorResultSink`_ .
/// </summary>
void easyar_VideoInputFrameRecorder_attitudeSensorResultSink(easyar_VideoInputFrameRecorder * This, /* OUT */ easyar_AttitudeSensorResultSink * * Return);
/// <summary>
/// Optional. Input port for magnetometer. See also `MagnetometerResultSink`_ .
/// </summary>
void easyar_VideoInputFrameRecorder_magnetometerResultSink(easyar_VideoInputFrameRecorder * This, /* OUT */ easyar_MagnetometerResultSink * * Return);
/// <summary>
/// Optional. Input port for location result. See also `LocationResultSink`_ .
/// </summary>
void easyar_VideoInputFrameRecorder_locationResultSink(easyar_VideoInputFrameRecorder * This, /* OUT */ easyar_LocationResultSink * * Return);
/// <summary>
/// Optional. Input port for proximity location result. See also `ProximityLocationResultSink`_ .
/// </summary>
void easyar_VideoInputFrameRecorder_proximityLocationResultSink(easyar_VideoInputFrameRecorder * This, /* OUT */ easyar_ProximityLocationResultSink * * Return);
/// <summary>
/// Camera buffers occupied in this component.
/// </summary>
int easyar_VideoInputFrameRecorder_bufferRequirement(easyar_VideoInputFrameRecorder * This);
/// <summary>
/// Output port.
/// </summary>
void easyar_VideoInputFrameRecorder_output(easyar_VideoInputFrameRecorder * This, /* OUT */ easyar_InputFrameSource * * Return);
/// <summary>
/// Creates an instance.
/// </summary>
void easyar_VideoInputFrameRecorder_create(/* OUT */ easyar_VideoInputFrameRecorder * * Return);
/// <summary>
/// Starts frame recording. The definitions of cameraDeviceType, cameraOrientation and cameraOrientation are the same as in `CameraParameters`_ . initialScreenRotation is the initial screen rotation when recording data, and it will be used in rendering for playback.
/// </summary>
bool easyar_VideoInputFrameRecorder_start(easyar_VideoInputFrameRecorder * This, easyar_String * filePath, easyar_CameraDeviceType cameraDeviceType, int cameraOrientation, int initialScreenRotation, easyar_VideoInputFrameRecorderVideoCodec codec, int width, int height, double frameRate, easyar_String * metadata);
/// <summary>
/// Stops frame recording. It will only stop recording and will not affect connection.
/// </summary>
void easyar_VideoInputFrameRecorder_stop(easyar_VideoInputFrameRecorder * This);
/// <summary>
/// Sets callback for automatic completion of recording.
/// </summary>
void easyar_VideoInputFrameRecorder_setAutomaticCompletionCallback(easyar_VideoInputFrameRecorder * This, easyar_CallbackScheduler * callbackScheduler, easyar_OptionalOfFunctorOfVoidFromVideoInputFrameRecorderCompletionReason automaticCompletionCallback);
void easyar_VideoInputFrameRecorder__dtor(easyar_VideoInputFrameRecorder * This);
void easyar_VideoInputFrameRecorder__retain(const easyar_VideoInputFrameRecorder * This, /* OUT */ easyar_VideoInputFrameRecorder * * Return);
const char * easyar_VideoInputFrameRecorder__typeName(const easyar_VideoInputFrameRecorder * This);

/// <summary>
/// Checks if the component is available. It returns true only on Windows.
/// </summary>
bool easyar_VideoInputFramePlayer_isAvailable(void);
/// <summary>
/// Output port.
/// </summary>
void easyar_VideoInputFramePlayer_output(easyar_VideoInputFramePlayer * This, /* OUT */ easyar_InputFrameSource * * Return);
/// <summary>
/// Output port for accelerometer result. See also `AccelerometerResultSource`_ .
/// </summary>
void easyar_VideoInputFramePlayer_accelerometerResultSource(easyar_VideoInputFramePlayer * This, /* OUT */ easyar_AccelerometerResultSource * * Return);
/// <summary>
/// Output port for gyroscope result. See also `GyroscopeResultSource`_ .
/// </summary>
void easyar_VideoInputFramePlayer_gyroscopeResultSource(easyar_VideoInputFramePlayer * This, /* OUT */ easyar_GyroscopeResultSource * * Return);
/// <summary>
/// Output port for attitude sensor. See also `AttitudeSensorResultSource`_ .
/// </summary>
void easyar_VideoInputFramePlayer_attitudeSensorResultSource(easyar_VideoInputFramePlayer * This, /* OUT */ easyar_AttitudeSensorResultSource * * Return);
/// <summary>
/// Output port for magnetometer. See also `MagnetometerResultSource`_ .
/// </summary>
void easyar_VideoInputFramePlayer_magnetometerResultSource(easyar_VideoInputFramePlayer * This, /* OUT */ easyar_MagnetometerResultSource * * Return);
/// <summary>
/// Output port for location result. See also `LocationResultSource`_ .
/// </summary>
void easyar_VideoInputFramePlayer_locationResultSource(easyar_VideoInputFramePlayer * This, /* OUT */ easyar_LocationResultSource * * Return);
/// <summary>
/// Output port for proximity location result. See also `ProximityLocationResultSource`_ .
/// </summary>
void easyar_VideoInputFramePlayer_proximityLocationResultSource(easyar_VideoInputFramePlayer * This, /* OUT */ easyar_ProximityLocationResultSource * * Return);
/// <summary>
/// Creates an instance.
/// </summary>
void easyar_VideoInputFramePlayer_create(/* OUT */ easyar_VideoInputFramePlayer * * Return);
/// <summary>
/// Starts frame play.
/// </summary>
bool easyar_VideoInputFramePlayer_start(easyar_VideoInputFramePlayer * This, easyar_String * filePath);
/// <summary>
/// Stops frame play.
/// </summary>
void easyar_VideoInputFramePlayer_stop(easyar_VideoInputFramePlayer * This);
/// <summary>
/// Pauses frame play.
/// </summary>
void easyar_VideoInputFramePlayer_pause(easyar_VideoInputFramePlayer * This);
/// <summary>
/// Resumes frame play.
/// </summary>
bool easyar_VideoInputFramePlayer_resume(easyar_VideoInputFramePlayer * This);
/// <summary>
/// Total expected playback time span. The unit is second. If recording halts improperly, it may be missing.
/// </summary>
easyar_OptionalOfDouble easyar_VideoInputFramePlayer_totalTime(easyar_VideoInputFramePlayer * This);
/// <summary>
/// Current playback time point. The unit is second. The initial value is 0.
/// </summary>
double easyar_VideoInputFramePlayer_currentTime(easyar_VideoInputFramePlayer * This);
/// <summary>
/// Whether the current playback time point can be relocated. If recording halts improperly, index data to set playback time point may be missing.
/// </summary>
bool easyar_VideoInputFramePlayer_isSeekable(const easyar_VideoInputFramePlayer * This);
/// <summary>
/// Sets current playback time point. The unit is second. If index data is missing, it returns false.
/// </summary>
bool easyar_VideoInputFramePlayer_seek(easyar_VideoInputFramePlayer * This, double time);
/// <summary>
/// Current playback speed. The initial value is 1.
/// </summary>
double easyar_VideoInputFramePlayer_speed(const easyar_VideoInputFramePlayer * This);
/// <summary>
/// Sets current playback speed.
/// </summary>
void easyar_VideoInputFramePlayer_setSpeed(easyar_VideoInputFramePlayer * This, double _value);
/// <summary>
/// The initial screen rotation when recording data.
/// </summary>
int easyar_VideoInputFramePlayer_initalScreenRotation(easyar_VideoInputFramePlayer * This);
/// <summary>
/// The metadata when recording data.
/// </summary>
void easyar_VideoInputFramePlayer_metadata(easyar_VideoInputFramePlayer * This, /* OUT */ easyar_String * * Return);
/// <summary>
/// Whether the playback is completed.
/// </summary>
bool easyar_VideoInputFramePlayer_isCompleted(easyar_VideoInputFramePlayer * This);
void easyar_VideoInputFramePlayer__dtor(easyar_VideoInputFramePlayer * This);
void easyar_VideoInputFramePlayer__retain(const easyar_VideoInputFramePlayer * This, /* OUT */ easyar_VideoInputFramePlayer * * Return);
const char * easyar_VideoInputFramePlayer__typeName(const easyar_VideoInputFramePlayer * This);

#ifdef __cplusplus
}
#endif

#endif
