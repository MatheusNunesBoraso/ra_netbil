//=============================================================================================================================
//
// EasyAR Sense 4.8.0.11837-e0e3282d9
// Copyright (c) 2015-2026 VisionStar Information Technology (Shanghai) Co., Ltd. All Rights Reserved.
// EasyAR is the registered trademark or trademark of VisionStar Information Technology (Shanghai) Co., Ltd in China
// and other countries for the augmented reality technology developed by VisionStar Information Technology (Shanghai) Co., Ltd.
//
//=============================================================================================================================

#ifndef __EASYAR_MEGATRACKER_H__
#define __EASYAR_MEGATRACKER_H__

#include "easyar/types.h"

#ifdef __cplusplus
extern "C" {
#endif

/// <summary>
/// The appId of service.
/// </summary>
void easyar_MegaTrackerBlockInstance_appId(const easyar_MegaTrackerBlockInstance * This, /* OUT */ easyar_String * * Return);
/// <summary>
/// The ID of the block.
/// </summary>
void easyar_MegaTrackerBlockInstance_blockId(const easyar_MegaTrackerBlockInstance * This, /* OUT */ easyar_String * * Return);
/// <summary>
/// The name of the block.
/// </summary>
void easyar_MegaTrackerBlockInstance_name(const easyar_MegaTrackerBlockInstance * This, /* OUT */ easyar_String * * Return);
/// <summary>
/// The map block pose in the camera coordinates.
/// </summary>
easyar_Matrix44F easyar_MegaTrackerBlockInstance_pose(const easyar_MegaTrackerBlockInstance * This);
void easyar_MegaTrackerBlockInstance__dtor(easyar_MegaTrackerBlockInstance * This);
void easyar_MegaTrackerBlockInstance__retain(const easyar_MegaTrackerBlockInstance * This, /* OUT */ easyar_MegaTrackerBlockInstance * * Return);
const char * easyar_MegaTrackerBlockInstance__typeName(const easyar_MegaTrackerBlockInstance * This);

/// <summary>
/// Current localized block instances. An existing instance will be preserved until another block is localized, or when MegaTracker is stopped or paused.
/// </summary>
void easyar_MegaTrackerResult_instances(const easyar_MegaTrackerResult * This, /* OUT */ easyar_ListOfMegaTrackerBlockInstance * * Return);
void easyar_MegaTrackerResult__dtor(easyar_MegaTrackerResult * This);
void easyar_MegaTrackerResult__retain(const easyar_MegaTrackerResult * This, /* OUT */ easyar_MegaTrackerResult * * Return);
const char * easyar_MegaTrackerResult__typeName(const easyar_MegaTrackerResult * This);
void easyar_castMegaTrackerResultToFrameFilterResult(const easyar_MegaTrackerResult * This, /* OUT */ easyar_FrameFilterResult * * Return);
void easyar_tryCastFrameFilterResultToMegaTrackerResult(const easyar_FrameFilterResult * This, /* OUT */ easyar_MegaTrackerResult * * Return);

/// <summary>
/// The input frame on request.
/// </summary>
void easyar_MegaTrackerLocalizationResponse_inputFrame(const easyar_MegaTrackerLocalizationResponse * This, /* OUT */ easyar_InputFrame * * Return);
/// <summary>
/// The accelerometer reading on request.
/// </summary>
easyar_OptionalOfAccelerometerResult easyar_MegaTrackerLocalizationResponse_acceleration(const easyar_MegaTrackerLocalizationResponse * This);
/// <summary>
/// The location reading on request.
/// </summary>
easyar_OptionalOfLocationResult easyar_MegaTrackerLocalizationResponse_location(const easyar_MegaTrackerLocalizationResponse * This);
/// <summary>
/// Localization status.
/// </summary>
easyar_MegaTrackerLocalizationStatus easyar_MegaTrackerLocalizationResponse_status(const easyar_MegaTrackerLocalizationResponse * This);
/// <summary>
/// The spot version ID.
/// </summary>
void easyar_MegaTrackerLocalizationResponse_spotVersionId(const easyar_MegaTrackerLocalizationResponse * This, /* OUT */ easyar_OptionalOfString * Return);
/// <summary>
/// Current localized block instances. An existing instance will be preserved until another block is localized, or when MegaTracker is stopped or paused.
/// </summary>
void easyar_MegaTrackerLocalizationResponse_instances(const easyar_MegaTrackerLocalizationResponse * This, /* OUT */ easyar_ListOfMegaTrackerBlockInstance * * Return);
/// <summary>
/// The appId of service.
/// </summary>
void easyar_MegaTrackerLocalizationResponse_appId(const easyar_MegaTrackerLocalizationResponse * This, /* OUT */ easyar_String * * Return);
/// <summary>
/// The duration in seconds for server response.
/// </summary>
easyar_OptionalOfDouble easyar_MegaTrackerLocalizationResponse_serverResponseDuration(const easyar_MegaTrackerLocalizationResponse * This);
/// <summary>
/// The duration in seconds for server internal calculation.
/// </summary>
easyar_OptionalOfDouble easyar_MegaTrackerLocalizationResponse_serverCalculationDuration(const easyar_MegaTrackerLocalizationResponse * This);
/// <summary>
/// Error message. It is filled when status is UnknownError.
/// </summary>
void easyar_MegaTrackerLocalizationResponse_errorMessage(const easyar_MegaTrackerLocalizationResponse * This, /* OUT */ easyar_OptionalOfString * Return);
void easyar_MegaTrackerLocalizationResponse_extraInfo(const easyar_MegaTrackerLocalizationResponse * This, /* OUT */ easyar_String * * Return);
void easyar_MegaTrackerLocalizationResponse__dtor(easyar_MegaTrackerLocalizationResponse * This);
void easyar_MegaTrackerLocalizationResponse__retain(const easyar_MegaTrackerLocalizationResponse * This, /* OUT */ easyar_MegaTrackerLocalizationResponse * * Return);
const char * easyar_MegaTrackerLocalizationResponse__typeName(const easyar_MegaTrackerLocalizationResponse * This);

/// <summary>
/// Check whether SparseSpatialMap is is available, always return true.
/// </summary>
bool easyar_MegaTracker_isAvailable(void);
/// <summary>
/// Input port for input frame. For MegaTracker to work, the inputFrame must include camera parameters, timestamp and spatial information. See also `InputFrameSink`_ .
/// </summary>
void easyar_MegaTracker_inputFrameSink(easyar_MegaTracker * This, /* OUT */ easyar_InputFrameSink * * Return);
/// <summary>
/// Input port for accelerometer result. See also `AccelerometerResultSink`_ .
/// </summary>
void easyar_MegaTracker_accelerometerResultSink(easyar_MegaTracker * This, /* OUT */ easyar_AccelerometerResultSink * * Return);
/// <summary>
/// Optional. Input port for location result. See also `LocationResultSink`_ .
/// </summary>
void easyar_MegaTracker_locationResultSink(easyar_MegaTracker * This, /* OUT */ easyar_LocationResultSink * * Return);
/// <summary>
/// Optional. Input port for proximity location result. See also `ProximityLocationResultSink`_ .
/// </summary>
void easyar_MegaTracker_proximityLocationResultSink(easyar_MegaTracker * This, /* OUT */ easyar_ProximityLocationResultSink * * Return);
/// <summary>
/// Camera buffers occupied in this component.
/// </summary>
int easyar_MegaTracker_bufferRequirement(easyar_MegaTracker * This);
/// <summary>
/// Output port for output frame. See also `OutputFrameSource`_ .
/// </summary>
void easyar_MegaTracker_outputFrameSource(easyar_MegaTracker * This, /* OUT */ easyar_OutputFrameSource * * Return);
/// <summary>
/// Creates an instance.
/// </summary>
void easyar_MegaTracker_create(easyar_String * server, easyar_String * apiKey, easyar_String * apiSecret, easyar_String * appId, /* OUT */ easyar_MegaTracker * * Return);
/// <summary>
/// Creates an instance with API Token.
/// </summary>
void easyar_MegaTracker_createWithToken(easyar_String * server, easyar_String * apiToken, easyar_String * appId, /* OUT */ easyar_MegaTracker * * Return);
/// <summary>
/// Updates API Token.
/// </summary>
void easyar_MegaTracker_updateToken(easyar_MegaTracker * This, easyar_String * apiToken);
/// <summary>
/// Sets MEGA API Type. The default is Block.
/// </summary>
void easyar_MegaTracker_setMegaApiType(easyar_MegaTracker * This, easyar_MegaApiType type);
/// <summary>
/// Sets the spot version ID. Only available with `MegaApiType`_.Landmark .
/// </summary>
void easyar_MegaTracker_setSpotVersionId(easyar_MegaTracker * This, easyar_OptionalOfString spotVersionId);
/// <summary>
/// Switches remote end point.
/// </summary>
void easyar_MegaTracker_switchEndPoint(easyar_MegaTracker * This, easyar_String * server, easyar_String * apiKey, easyar_String * apiSecret, easyar_String * appId);
/// <summary>
/// Switches remote end point with API Token.
/// </summary>
void easyar_MegaTracker_switchEndPointWithToken(easyar_MegaTracker * This, easyar_String * server, easyar_String * apiToken, easyar_String * appId);
/// <summary>
/// Binds to a specific block prior. An automatic unbind will be performed during reset or end point switching.
/// </summary>
void easyar_MegaTracker_bindBlockPrior(easyar_MegaTracker * This, easyar_BlockPriorResult * blockPrior);
/// <summary>
/// Release bind to any block.
/// </summary>
void easyar_MegaTracker_unbindBlockPrior(easyar_MegaTracker * This);
/// <summary>
/// Sets request time parameters. timeoutMilliseconds is connection timeout. requestIntervalMilliseconds is the expected request interval, and the default value is 1000 and the minimum value is 300, with a longer value results a larger overall error.
/// </summary>
void easyar_MegaTracker_setRequestTimeParameters(easyar_MegaTracker * This, easyar_OptionalOfInt timeoutMilliseconds, int requestIntervalMilliseconds);
/// <summary>
/// Sets whether to enable localzation. If disabled, localization result from server response will not be in the output. Defaults to true.
/// </summary>
void easyar_MegaTracker_setEnableLocalization(easyar_MegaTracker * This, bool enableLocalization);
/// <summary>
/// Sets whether to enable stateless localzation. If enabled, previous result will not be used in localization. Defaults to false.
/// </summary>
void easyar_MegaTracker_setEnableStatelessLocalization(easyar_MegaTracker * This, bool enableStatelessLocalization);
/// <summary>
/// Sets result async mode. Set true If results are to be outputted via outputFrameSource, false if results are to be fetched via getSyncResult. enableAsync defaults to true. Sync mode is only available with a XR license.
/// </summary>
bool easyar_MegaTracker_setResultAsyncMode(easyar_MegaTracker * This, bool enableAsync);
void easyar_MegaTracker_setRequestMessage(easyar_MegaTracker * This, easyar_String * message);
/// <summary>
/// Sets localization callback. On every localization, the callback will be triggered.
/// </summary>
void easyar_MegaTracker_setLocalizationCallback(easyar_MegaTracker * This, easyar_CallbackScheduler * callbackScheduler, easyar_OptionalOfFunctorOfVoidFromMegaTrackerLocalizationResponse callback);
/// <summary>
/// Sets the override value for camera position from map block. When set, MegaTracker will output override value instead of the position in input frame. This option can be utilized to improve output pose precision when there is known map info but limited sensor capability.
/// </summary>
void easyar_MegaTracker_setCameraPositionOverride(easyar_MegaTracker * This, easyar_OptionalOfFloat x, easyar_OptionalOfFloat y, easyar_OptionalOfFloat z);
/// <summary>
/// Start MegaTracker.
/// </summary>
bool easyar_MegaTracker_start(easyar_MegaTracker * This);
/// <summary>
/// Stop MegaTracker. Call start() to resume running.
/// </summary>
void easyar_MegaTracker_stop(easyar_MegaTracker * This);
/// <summary>
/// Reset MegaTracker and clear all internal states.
/// </summary>
void easyar_MegaTracker_reset(easyar_MegaTracker * This);
/// <summary>
/// Close MegaTracker. MegaTracker can no longer be used.
/// </summary>
void easyar_MegaTracker_close(easyar_MegaTracker * This);
/// <summary>
/// Get synchronized result. If MegaTracker is paused, or the result async mode is not set to false through setResultAsyncMode, the return value is empty.
/// </summary>
void easyar_MegaTracker_getSyncResult(easyar_MegaTracker * This, easyar_MotionInputData * motionInputData, /* OUT */ easyar_OptionalOfMegaTrackerResult * Return);
void easyar_MegaTracker__dtor(easyar_MegaTracker * This);
void easyar_MegaTracker__retain(const easyar_MegaTracker * This, /* OUT */ easyar_MegaTracker * * Return);
const char * easyar_MegaTracker__typeName(const easyar_MegaTracker * This);

void easyar_ListOfMegaTrackerBlockInstance__ctor(easyar_MegaTrackerBlockInstance * const * begin, easyar_MegaTrackerBlockInstance * const * end, /* OUT */ easyar_ListOfMegaTrackerBlockInstance * * Return);
void easyar_ListOfMegaTrackerBlockInstance__dtor(easyar_ListOfMegaTrackerBlockInstance * This);
void easyar_ListOfMegaTrackerBlockInstance_copy(const easyar_ListOfMegaTrackerBlockInstance * This, /* OUT */ easyar_ListOfMegaTrackerBlockInstance * * Return);
int easyar_ListOfMegaTrackerBlockInstance_size(const easyar_ListOfMegaTrackerBlockInstance * This);
easyar_MegaTrackerBlockInstance * easyar_ListOfMegaTrackerBlockInstance_at(const easyar_ListOfMegaTrackerBlockInstance * This, int index);

#ifdef __cplusplus
}
#endif

#endif
