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
/// Motion input data.
/// It includes timestamp, transform matrix against world coordinate system, and tracking status.
/// </summary>
@interface easyar_MotionInputData : easyar_RefBase

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

/// <summary>
/// Creates with 6DOF transform of both rotation and position. rotation is quaternion, ordered as wxyz.
/// </summary>
+ (easyar_MotionInputData *)tryCreateSixDof:(double)timestamp position:(easyar_Vec3F *)position rotation:(easyar_Vec4F *)rotation tracking_status:(easyar_MotionTrackingStatus)tracking_status;
/// <summary>
/// Creates with 5DOF transform of both rotation and 2D position. rotation is quaternion, ordered as wxyz.
/// </summary>
+ (easyar_MotionInputData *)tryCreateFiveDofRotXZ:(double)timestamp position:(easyar_Vec3F *)position rotation:(easyar_Vec4F *)rotation;
/// <summary>
/// Creates with 3DOF transform of rotation only. rotation is quaternion, ordered as wxyz.
/// </summary>
+ (easyar_MotionInputData *)tryCreateThreeDofRotOnly:(double)timestamp rotation:(easyar_Vec4F *)rotation;
/// <summary>
/// Timestamp. In seconds.
/// </summary>
- (double)timestamp;
/// <summary>
/// Transform type.
/// </summary>
- (easyar_CameraTransformType)transformType;
/// <summary>
/// Transform matrix against world coordinate system.
/// </summary>
- (easyar_Matrix44F *)transform;
/// <summary>
/// Gets device motion tracking status: `MotionTrackingStatus`_ . Only for 6DOF.
/// </summary>
- (easyar_MotionTrackingStatus)trackingStatus;

@end

/// <summary>
/// Input frame.
/// It includes image, camera parameters, timestamp, camera transform matrix against world coordinate system, and tracking status,
/// among which, camera parameters, timestamp, camera transform matrix and tracking status are all optional, but specific algorithms may have special requirements on the input.
/// </summary>
@interface easyar_InputFrame : easyar_RefBase

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

/// <summary>
/// Index, an automatic incremental value, which is different for every input frame.
/// </summary>
- (int)index;
/// <summary>
/// Gets image.
/// </summary>
- (easyar_Image *)image;
/// <summary>
/// Checks if there are camera parameters.
/// </summary>
- (bool)hasCameraParameters;
/// <summary>
/// Gets camera parameters.
/// </summary>
- (easyar_CameraParameters *)cameraParameters;
/// <summary>
/// Checks if there is temporal information (timestamp).
/// </summary>
- (bool)hasTemporalInformation;
/// <summary>
/// Timestamp. In seconds.
/// </summary>
- (double)timestamp;
/// <summary>
/// Checks if there is spatial information (cameraTransform and trackingStatus).
/// </summary>
- (bool)hasSpatialInformation;
/// <summary>
/// Camera transform matrix against world coordinate system. Camera coordinate system and world coordinate system are all right-handed. For the camera coordinate system, the origin is the optical center, x-right, y-up, and z in the direction of light going into camera. (The right and up, is right and up in the camera image, which can be different from these in the natural orientation of the device.) The data arrangement is row-major, not like OpenGL&#39;s column-major.
/// </summary>
- (easyar_Matrix44F *)cameraTransform;
/// <summary>
/// Camera transform type.
/// </summary>
- (easyar_CameraTransformType)cameraTransformType;
/// <summary>
/// Gets device motion tracking status: `MotionTrackingStatus`_ .
/// </summary>
- (easyar_MotionTrackingStatus)trackingStatus;
/// <summary>
/// Motion input data.
/// </summary>
- (easyar_MotionInputData *)motion;
/// <summary>
/// Creates an instance.
/// </summary>
+ (easyar_InputFrame *)tryCreate:(easyar_Image *)image cameraParameters:(easyar_CameraParameters *)cameraParameters timestamp:(double)timestamp cameraTransform:(easyar_Matrix44F *)cameraTransform cameraTransformType:(easyar_CameraTransformType)cameraTransformType trackingStatus:(easyar_MotionTrackingStatus)trackingStatus;
/// <summary>
/// Creates an instance with image, camera parameters, and timestamp.
/// </summary>
+ (easyar_InputFrame *)createWithImageAndCameraParametersAndTemporal:(easyar_Image *)image cameraParameters:(easyar_CameraParameters *)cameraParameters timestamp:(double)timestamp;
/// <summary>
/// Creates an instance with image and camera parameters. Nothing but `CloudRecognizer`_ can work with input created by this method.
/// </summary>
+ (easyar_InputFrame *)createWithImageAndCameraParameters:(easyar_Image *)image cameraParameters:(easyar_CameraParameters *)cameraParameters;
/// <summary>
/// Creates an instance with image. Nothing but `CloudRecognizer`_ can work with input created by this method.
/// </summary>
+ (easyar_InputFrame *)createWithImage:(easyar_Image *)image;

@end

/// <summary>
/// FrameFilterResult is the base class for result classes of all synchronous algorithm components.
/// </summary>
@interface easyar_FrameFilterResult : easyar_RefBase

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

@end

/// <summary>
/// Output frame.
/// It includes input frame and results of synchronous components.
/// </summary>
@interface easyar_OutputFrame : easyar_RefBase

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

+ (easyar_OutputFrame *) create:(easyar_InputFrame *)inputFrame results:(NSArray<easyar_FrameFilterResult *> *)results;
/// <summary>
/// Index, an automatic incremental value, which is different for every output frame.
/// </summary>
- (int)index;
/// <summary>
/// Corresponding input frame.
/// </summary>
- (easyar_InputFrame *)inputFrame;
/// <summary>
/// Results of synchronous components.
/// </summary>
- (NSArray<easyar_FrameFilterResult *> *)results;

@end

/// <summary>
/// Feedback frame.
/// It includes an input frame and a historic output frame for use in feedback synchronous components such as `ImageTracker`_ .
/// </summary>
@interface easyar_FeedbackFrame : easyar_RefBase

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

+ (easyar_FeedbackFrame *) create:(easyar_InputFrame *)inputFrame previousOutputFrame:(easyar_OutputFrame *)previousOutputFrame;
/// <summary>
/// Input frame.
/// </summary>
- (easyar_InputFrame *)inputFrame;
/// <summary>
/// Historic output frame.
/// </summary>
- (easyar_OutputFrame *)previousOutputFrame;

@end
