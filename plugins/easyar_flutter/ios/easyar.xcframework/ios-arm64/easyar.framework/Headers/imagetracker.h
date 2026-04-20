//=============================================================================================================================
//
// EasyAR Sense 4.8.0.11837-e0e3282d9
// Copyright (c) 2015-2026 VisionStar Information Technology (Shanghai) Co., Ltd. All Rights Reserved.
// EasyAR is the registered trademark or trademark of VisionStar Information Technology (Shanghai) Co., Ltd in China
// and other countries for the augmented reality technology developed by VisionStar Information Technology (Shanghai) Co., Ltd.
//
//=============================================================================================================================

#ifndef __EASYAR_IMAGETRACKER_H__
#define __EASYAR_IMAGETRACKER_H__

#include "easyar/types.h"

#ifdef __cplusplus
extern "C" {
#endif

void easyar_ImageTrackerConfig__ctor(/* OUT */ easyar_ImageTrackerConfig * * Return);
/// <summary>
/// Mode for ImageTracker. It defaults to PreferQuality.
/// </summary>
easyar_ImageTrackerMode easyar_ImageTrackerConfig_trackerMode(easyar_ImageTrackerConfig * This);
void easyar_ImageTrackerConfig_setTrackerMode(easyar_ImageTrackerConfig * This, easyar_ImageTrackerMode _value);
void easyar_ImageTrackerConfig__dtor(easyar_ImageTrackerConfig * This);
void easyar_ImageTrackerConfig__retain(const easyar_ImageTrackerConfig * This, /* OUT */ easyar_ImageTrackerConfig * * Return);
const char * easyar_ImageTrackerConfig__typeName(const easyar_ImageTrackerConfig * This);

/// <summary>
/// Returns the list of `TargetInstance`_ contained in the result.
/// </summary>
void easyar_ImageTrackerResult_targetInstances(const easyar_ImageTrackerResult * This, /* OUT */ easyar_ListOfTargetInstance * * Return);
/// <summary>
/// Sets the list of `TargetInstance`_ contained in the result.
/// </summary>
void easyar_ImageTrackerResult_setTargetInstances(easyar_ImageTrackerResult * This, easyar_ListOfTargetInstance * instances);
void easyar_ImageTrackerResult__dtor(easyar_ImageTrackerResult * This);
void easyar_ImageTrackerResult__retain(const easyar_ImageTrackerResult * This, /* OUT */ easyar_ImageTrackerResult * * Return);
const char * easyar_ImageTrackerResult__typeName(const easyar_ImageTrackerResult * This);
void easyar_castImageTrackerResultToFrameFilterResult(const easyar_ImageTrackerResult * This, /* OUT */ easyar_FrameFilterResult * * Return);
void easyar_tryCastFrameFilterResultToImageTrackerResult(const easyar_FrameFilterResult * This, /* OUT */ easyar_ImageTrackerResult * * Return);
void easyar_castImageTrackerResultToTargetTrackerResult(const easyar_ImageTrackerResult * This, /* OUT */ easyar_TargetTrackerResult * * Return);
void easyar_tryCastTargetTrackerResultToImageTrackerResult(const easyar_TargetTrackerResult * This, /* OUT */ easyar_ImageTrackerResult * * Return);

/// <summary>
/// Returns true.
/// </summary>
bool easyar_ImageTracker_isAvailable(void);
/// <summary>
/// `FeedbackFrame`_ input port. The InputFrame member of FeedbackFrame must have raw image, timestamp, and camera parameters. Both pinhole and fisheye camera are supported.
/// </summary>
void easyar_ImageTracker_feedbackFrameSink(easyar_ImageTracker * This, /* OUT */ easyar_FeedbackFrameSink * * Return);
/// <summary>
/// Camera buffers occupied in this component.
/// </summary>
int easyar_ImageTracker_bufferRequirement(easyar_ImageTracker * This);
/// <summary>
/// `OutputFrame`_ output port.
/// </summary>
void easyar_ImageTracker_outputFrameSource(easyar_ImageTracker * This, /* OUT */ easyar_OutputFrameSource * * Return);
/// <summary>
/// Creates an instance. The default track mode is `ImageTrackerMode`_.PreferQuality .
/// </summary>
void easyar_ImageTracker_create(/* OUT */ easyar_ImageTracker * * Return);
/// <summary>
/// Creates an instance with a specified track mode. On lower-end phones, `ImageTrackerMode`_.PreferPerformance can be used to keep a better performance with a little quality loss.
/// </summary>
void easyar_ImageTracker_createWithMode(easyar_ImageTrackerMode trackMode, /* OUT */ easyar_ImageTracker * * Return);
/// <summary>
/// Creates an instance with a specified config.
/// </summary>
void easyar_ImageTracker_createWithConfig(easyar_ImageTrackerConfig * config, /* OUT */ easyar_ImageTracker * * Return);
/// <summary>
/// Sets result post-processing.
/// enablePersistentTargetInstance defaults to false. When it is enabled and `InputFrame`_ contains spatial information, targetInstances in `ImageTrackerResult`_ will contain all recognized instances (with not tracking target instances).
/// enableMotionFusion defaults to false. When it is enabled and `InputFrame`_ contains temporal information and spatial information, pose of targetInstances in `ImageTrackerResult`_ will utilize RealTimeCoordinateTransform .
/// </summary>
void easyar_ImageTracker_setResultPostProcessing(easyar_ImageTracker * This, bool enablePersistentTargetInstance, bool enableMotionFusion);
/// <summary>
/// Sets result async mode. Set true If results are to be outputted via outputFrameSource, false if results are to be fetched via getSyncResult. enableAsync defaults to true. Sync mode is only available with input frames including spatial information and with a XR license.
/// </summary>
bool easyar_ImageTracker_setResultAsyncMode(easyar_ImageTracker * This, bool enableAsync);
/// <summary>
/// Starts the track algorithm.
/// </summary>
bool easyar_ImageTracker_start(easyar_ImageTracker * This);
/// <summary>
/// Stops the track algorithm. Call start to start the track again.
/// </summary>
void easyar_ImageTracker_stop(easyar_ImageTracker * This);
/// <summary>
/// Close. The component shall not be used after calling close.
/// </summary>
void easyar_ImageTracker_close(easyar_ImageTracker * This);
/// <summary>
/// Load a `Target`_ into the tracker. A Target can only be tracked by tracker after a successful load.
/// This method is an asynchronous method. A load operation may take some time to finish and detection of a new/lost target may take more time during the load. The track time after detection will not be affected. If you want to know the load result, you have to handle the callback data. The callback will be called from the thread specified by `CallbackScheduler`_ . It will not block the track thread or any other operations except other load/unload.
/// </summary>
void easyar_ImageTracker_loadTarget(easyar_ImageTracker * This, easyar_Target * target, easyar_CallbackScheduler * callbackScheduler, easyar_FunctorOfVoidFromTargetAndBool callback);
/// <summary>
/// Unload a `Target`_ from the tracker.
/// This method is an asynchronous method. An unload operation may take some time to finish and detection of a new/lost target may take more time during the unload. If you want to know the unload result, you have to handle the callback data. The callback will be called from the thread specified by `CallbackScheduler`_ . It will not block the track thread or any other operations except other load/unload.
/// </summary>
void easyar_ImageTracker_unloadTarget(easyar_ImageTracker * This, easyar_Target * target, easyar_CallbackScheduler * callbackScheduler, easyar_FunctorOfVoidFromTargetAndBool callback);
/// <summary>
/// Returns current loaded targets in the tracker. If an asynchronous load/unload is in progress, the returned value will not reflect the result until all load/unload finish.
/// </summary>
void easyar_ImageTracker_targets(const easyar_ImageTracker * This, /* OUT */ easyar_ListOfTarget * * Return);
/// <summary>
/// Sets the max number of targets which will be the simultaneously tracked by the tracker. The default value is 1.
/// </summary>
bool easyar_ImageTracker_setSimultaneousNum(easyar_ImageTracker * This, int num);
/// <summary>
/// Gets the max number of targets which will be the simultaneously tracked by the tracker. The default value is 1.
/// </summary>
int easyar_ImageTracker_simultaneousNum(const easyar_ImageTracker * This);
/// <summary>
/// Get synchronized result. If ImageTracker is paused, or the result async mode is not set to false through setResultAsyncMode, the return value is empty.
/// </summary>
void easyar_ImageTracker_getSyncResult(easyar_ImageTracker * This, easyar_MotionInputData * motionInputData, /* OUT */ easyar_OptionalOfImageTrackerResult * Return);
void easyar_ImageTracker__dtor(easyar_ImageTracker * This);
void easyar_ImageTracker__retain(const easyar_ImageTracker * This, /* OUT */ easyar_ImageTracker * * Return);
const char * easyar_ImageTracker__typeName(const easyar_ImageTracker * This);

void easyar_ListOfTargetInstance__ctor(easyar_TargetInstance * const * begin, easyar_TargetInstance * const * end, /* OUT */ easyar_ListOfTargetInstance * * Return);
void easyar_ListOfTargetInstance__dtor(easyar_ListOfTargetInstance * This);
void easyar_ListOfTargetInstance_copy(const easyar_ListOfTargetInstance * This, /* OUT */ easyar_ListOfTargetInstance * * Return);
int easyar_ListOfTargetInstance_size(const easyar_ListOfTargetInstance * This);
easyar_TargetInstance * easyar_ListOfTargetInstance_at(const easyar_ListOfTargetInstance * This, int index);

void easyar_ListOfTarget__ctor(easyar_Target * const * begin, easyar_Target * const * end, /* OUT */ easyar_ListOfTarget * * Return);
void easyar_ListOfTarget__dtor(easyar_ListOfTarget * This);
void easyar_ListOfTarget_copy(const easyar_ListOfTarget * This, /* OUT */ easyar_ListOfTarget * * Return);
int easyar_ListOfTarget_size(const easyar_ListOfTarget * This);
easyar_Target * easyar_ListOfTarget_at(const easyar_ListOfTarget * This, int index);

#ifdef __cplusplus
}
#endif

#endif
