//=============================================================================================================================
//
// EasyAR Sense 4.8.0.11837-e0e3282d9
// Copyright (c) 2015-2026 VisionStar Information Technology (Shanghai) Co., Ltd. All Rights Reserved.
// EasyAR is the registered trademark or trademark of VisionStar Information Technology (Shanghai) Co., Ltd in China
// and other countries for the augmented reality technology developed by VisionStar Information Technology (Shanghai) Co., Ltd.
//
//=============================================================================================================================

#ifndef __EASYAR_FRAME_H__
#define __EASYAR_FRAME_H__

#include "easyar/types.h"

#ifdef __cplusplus
extern "C" {
#endif

/// <summary>
/// Creates with 6DOF transform of both rotation and position. rotation is quaternion, ordered as wxyz.
/// </summary>
void easyar_MotionInputData_tryCreateSixDof(double timestamp, easyar_Vec3F position, easyar_Vec4F rotation, easyar_MotionTrackingStatus tracking_status, /* OUT */ easyar_OptionalOfMotionInputData * Return);
/// <summary>
/// Creates with 5DOF transform of both rotation and 2D position. rotation is quaternion, ordered as wxyz.
/// </summary>
void easyar_MotionInputData_tryCreateFiveDofRotXZ(double timestamp, easyar_Vec3F position, easyar_Vec4F rotation, /* OUT */ easyar_OptionalOfMotionInputData * Return);
/// <summary>
/// Creates with 3DOF transform of rotation only. rotation is quaternion, ordered as wxyz.
/// </summary>
void easyar_MotionInputData_tryCreateThreeDofRotOnly(double timestamp, easyar_Vec4F rotation, /* OUT */ easyar_OptionalOfMotionInputData * Return);
/// <summary>
/// Timestamp. In seconds.
/// </summary>
double easyar_MotionInputData_timestamp(const easyar_MotionInputData * This);
/// <summary>
/// Transform type.
/// </summary>
easyar_CameraTransformType easyar_MotionInputData_transformType(const easyar_MotionInputData * This);
/// <summary>
/// Transform matrix against world coordinate system.
/// </summary>
easyar_Matrix44F easyar_MotionInputData_transform(const easyar_MotionInputData * This);
/// <summary>
/// Gets device motion tracking status: `MotionTrackingStatus`_ . Only for 6DOF.
/// </summary>
easyar_MotionTrackingStatus easyar_MotionInputData_trackingStatus(const easyar_MotionInputData * This);
void easyar_MotionInputData__dtor(easyar_MotionInputData * This);
void easyar_MotionInputData__retain(const easyar_MotionInputData * This, /* OUT */ easyar_MotionInputData * * Return);
const char * easyar_MotionInputData__typeName(const easyar_MotionInputData * This);

/// <summary>
/// Index, an automatic incremental value, which is different for every input frame.
/// </summary>
int easyar_InputFrame_index(const easyar_InputFrame * This);
/// <summary>
/// Gets image.
/// </summary>
void easyar_InputFrame_image(const easyar_InputFrame * This, /* OUT */ easyar_Image * * Return);
/// <summary>
/// Checks if there are camera parameters.
/// </summary>
bool easyar_InputFrame_hasCameraParameters(const easyar_InputFrame * This);
/// <summary>
/// Gets camera parameters.
/// </summary>
void easyar_InputFrame_cameraParameters(const easyar_InputFrame * This, /* OUT */ easyar_CameraParameters * * Return);
/// <summary>
/// Checks if there is temporal information (timestamp).
/// </summary>
bool easyar_InputFrame_hasTemporalInformation(const easyar_InputFrame * This);
/// <summary>
/// Timestamp. In seconds.
/// </summary>
double easyar_InputFrame_timestamp(const easyar_InputFrame * This);
/// <summary>
/// Checks if there is spatial information (cameraTransform and trackingStatus).
/// </summary>
bool easyar_InputFrame_hasSpatialInformation(const easyar_InputFrame * This);
/// <summary>
/// Camera transform matrix against world coordinate system. Camera coordinate system and world coordinate system are all right-handed. For the camera coordinate system, the origin is the optical center, x-right, y-up, and z in the direction of light going into camera. (The right and up, is right and up in the camera image, which can be different from these in the natural orientation of the device.) The data arrangement is row-major, not like OpenGL&#39;s column-major.
/// </summary>
easyar_Matrix44F easyar_InputFrame_cameraTransform(const easyar_InputFrame * This);
/// <summary>
/// Camera transform type.
/// </summary>
easyar_CameraTransformType easyar_InputFrame_cameraTransformType(const easyar_InputFrame * This);
/// <summary>
/// Gets device motion tracking status: `MotionTrackingStatus`_ .
/// </summary>
easyar_MotionTrackingStatus easyar_InputFrame_trackingStatus(const easyar_InputFrame * This);
/// <summary>
/// Motion input data.
/// </summary>
void easyar_InputFrame_motion(const easyar_InputFrame * This, /* OUT */ easyar_OptionalOfMotionInputData * Return);
/// <summary>
/// Creates an instance.
/// </summary>
void easyar_InputFrame_tryCreate(easyar_Image * image, easyar_CameraParameters * cameraParameters, double timestamp, easyar_Matrix44F cameraTransform, easyar_CameraTransformType cameraTransformType, easyar_MotionTrackingStatus trackingStatus, /* OUT */ easyar_OptionalOfInputFrame * Return);
/// <summary>
/// Creates an instance with image, camera parameters, and timestamp.
/// </summary>
void easyar_InputFrame_createWithImageAndCameraParametersAndTemporal(easyar_Image * image, easyar_CameraParameters * cameraParameters, double timestamp, /* OUT */ easyar_InputFrame * * Return);
/// <summary>
/// Creates an instance with image and camera parameters. Nothing but `CloudRecognizer`_ can work with input created by this method.
/// </summary>
void easyar_InputFrame_createWithImageAndCameraParameters(easyar_Image * image, easyar_CameraParameters * cameraParameters, /* OUT */ easyar_InputFrame * * Return);
/// <summary>
/// Creates an instance with image. Nothing but `CloudRecognizer`_ can work with input created by this method.
/// </summary>
void easyar_InputFrame_createWithImage(easyar_Image * image, /* OUT */ easyar_InputFrame * * Return);
void easyar_InputFrame__dtor(easyar_InputFrame * This);
void easyar_InputFrame__retain(const easyar_InputFrame * This, /* OUT */ easyar_InputFrame * * Return);
const char * easyar_InputFrame__typeName(const easyar_InputFrame * This);

void easyar_FrameFilterResult__dtor(easyar_FrameFilterResult * This);
void easyar_FrameFilterResult__retain(const easyar_FrameFilterResult * This, /* OUT */ easyar_FrameFilterResult * * Return);
const char * easyar_FrameFilterResult__typeName(const easyar_FrameFilterResult * This);

void easyar_OutputFrame__ctor(easyar_InputFrame * inputFrame, easyar_ListOfOptionalOfFrameFilterResult * results, /* OUT */ easyar_OutputFrame * * Return);
/// <summary>
/// Index, an automatic incremental value, which is different for every output frame.
/// </summary>
int easyar_OutputFrame_index(const easyar_OutputFrame * This);
/// <summary>
/// Corresponding input frame.
/// </summary>
void easyar_OutputFrame_inputFrame(const easyar_OutputFrame * This, /* OUT */ easyar_InputFrame * * Return);
/// <summary>
/// Results of synchronous components.
/// </summary>
void easyar_OutputFrame_results(const easyar_OutputFrame * This, /* OUT */ easyar_ListOfOptionalOfFrameFilterResult * * Return);
void easyar_OutputFrame__dtor(easyar_OutputFrame * This);
void easyar_OutputFrame__retain(const easyar_OutputFrame * This, /* OUT */ easyar_OutputFrame * * Return);
const char * easyar_OutputFrame__typeName(const easyar_OutputFrame * This);

void easyar_FeedbackFrame__ctor(easyar_InputFrame * inputFrame, easyar_OptionalOfOutputFrame previousOutputFrame, /* OUT */ easyar_FeedbackFrame * * Return);
/// <summary>
/// Input frame.
/// </summary>
void easyar_FeedbackFrame_inputFrame(const easyar_FeedbackFrame * This, /* OUT */ easyar_InputFrame * * Return);
/// <summary>
/// Historic output frame.
/// </summary>
void easyar_FeedbackFrame_previousOutputFrame(const easyar_FeedbackFrame * This, /* OUT */ easyar_OptionalOfOutputFrame * Return);
void easyar_FeedbackFrame__dtor(easyar_FeedbackFrame * This);
void easyar_FeedbackFrame__retain(const easyar_FeedbackFrame * This, /* OUT */ easyar_FeedbackFrame * * Return);
const char * easyar_FeedbackFrame__typeName(const easyar_FeedbackFrame * This);

void easyar_ListOfOptionalOfFrameFilterResult__ctor(easyar_OptionalOfFrameFilterResult const * begin, easyar_OptionalOfFrameFilterResult const * end, /* OUT */ easyar_ListOfOptionalOfFrameFilterResult * * Return);
void easyar_ListOfOptionalOfFrameFilterResult__dtor(easyar_ListOfOptionalOfFrameFilterResult * This);
void easyar_ListOfOptionalOfFrameFilterResult_copy(const easyar_ListOfOptionalOfFrameFilterResult * This, /* OUT */ easyar_ListOfOptionalOfFrameFilterResult * * Return);
int easyar_ListOfOptionalOfFrameFilterResult_size(const easyar_ListOfOptionalOfFrameFilterResult * This);
easyar_OptionalOfFrameFilterResult easyar_ListOfOptionalOfFrameFilterResult_at(const easyar_ListOfOptionalOfFrameFilterResult * This, int index);

#ifdef __cplusplus
}
#endif

#endif
