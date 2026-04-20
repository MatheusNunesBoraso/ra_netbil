//=============================================================================================================================
//
// EasyAR Sense 4.8.0.11837-e0e3282d9
// Copyright (c) 2015-2026 VisionStar Information Technology (Shanghai) Co., Ltd. All Rights Reserved.
// EasyAR is the registered trademark or trademark of VisionStar Information Technology (Shanghai) Co., Ltd in China
// and other countries for the augmented reality technology developed by VisionStar Information Technology (Shanghai) Co., Ltd.
//
//=============================================================================================================================

#pragma once

#include "easyar/types.h"
#include <cstddef>
#include <optional>
#include <memory>
#include <string>
#include <array>
#include <vector>
#include <functional>
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
#   include <stdexcept>
#   if defined(_EASYAR_EXCEPTION_MODE_NORTTI_)
#       include <type_traits>
#   endif
#else
#   include <cstdlib>
#endif

#if defined(_EASYAR_DECLARATION_ONLY_) || defined(_EASYAR_IMPLEMENTATION_ONLY_)
#   define _INLINE_SPECIFIER_
#else
#   define _INLINE_SPECIFIER_ inline
#endif

#ifndef _EASYAR_IMPLEMENTATION_ONLY_

namespace easyar {

class ObjectTargetParameters;

class ObjectTarget;

class ObjectTrackerResult;

class ObjectTracker;

enum class ARCoreDeviceListDownloadStatus
{
    /// <summary>
    /// Download successful.
    /// </summary>
    Successful = 0,
    /// <summary>
    /// Data is already latest.
    /// </summary>
    NotModified = 1,
    /// <summary>
    /// Connection error
    /// </summary>
    ConnectionError = 2,
    /// <summary>
    /// Unexpected error
    /// </summary>
    UnexpectedError = 3,
};

class ARCoreDeviceListDownloader;

enum class CalibrationDownloadStatus
{
    /// <summary>
    /// Download successful.
    /// </summary>
    Successful = 0,
    /// <summary>
    /// Data is already latest.
    /// </summary>
    NotModified = 1,
    /// <summary>
    /// Connection error
    /// </summary>
    ConnectionError = 2,
    /// <summary>
    /// Unexpected error
    /// </summary>
    UnexpectedError = 3,
};

class CalibrationDownloader;

/// <summary>
/// MEGA API Type.
/// </summary>
enum class MegaApiType
{
    /// <summary>
    /// Mega Block (CLS).
    /// </summary>
    Block = 0,
    /// <summary>
    /// Mega Landmark.
    /// </summary>
    Landmark = 1,
};

/// <summary>
/// CloudLocalizer status.
/// </summary>
enum class CloudLocalizerStatus
{
    /// <summary>
    /// Unknown error
    /// </summary>
    UnknownError = 0,
    /// <summary>
    /// A block is localized.
    /// </summary>
    Found = 1,
    /// <summary>
    /// No blocks are localized.
    /// </summary>
    NotFound = 2,
    /// <summary>
    /// Request time out (more than 1 minute)
    /// </summary>
    RequestTimeout = 3,
    /// <summary>
    /// Request time interval is too low
    /// </summary>
    RequestIntervalTooLow = 4,
    /// <summary>
    /// QPS limit exceeded
    /// </summary>
    QpsLimitExceeded = 5,
    /// <summary>
    /// Service is waking up
    /// </summary>
    WakingUp = 6,
    /// <summary>
    /// SpotVersionId is missing. It is possible that the value is not set.
    /// </summary>
    MissingSpotVersionId = 7,
    /// <summary>
    /// API Token expired.
    /// </summary>
    ApiTokenExpired = 8,
};

class CloudLocalizerBlockInstance;

class CloudLocalizerResult;

class DeviceAuxiliaryInfo;

class CloudLocalizer;

enum class MegaLandmarkFilterStatus
{
    /// <summary>
    /// Unknown error
    /// </summary>
    UnknownError = 0,
    /// <summary>
    /// Localized.
    /// </summary>
    Found = 1,
    /// <summary>
    /// Not localized.
    /// </summary>
    NotFound = 2,
    /// <summary>
    /// Request time out (more than 1 minute)
    /// </summary>
    RequestTimeout = 3,
    /// <summary>
    /// Request time interval is too low
    /// </summary>
    RequestIntervalTooLow = 4,
    /// <summary>
    /// QPS limit exceeded
    /// </summary>
    QpsLimitExceeded = 5,
    /// <summary>
    /// Service is waking up
    /// </summary>
    WakingUp = 6,
    /// <summary>
    /// API Token expired.
    /// </summary>
    ApiTokenExpired = 8,
};

class MegaLandmarkFilterResult;

class MegaLandmarkFilter;

class MegaTrackerBlockInstance;

class MegaTrackerResult;

enum class MegaTrackerLocalizationStatus
{
    /// <summary>
    /// Unknown error
    /// </summary>
    UnknownError = 0,
    /// <summary>
    /// A block is localized.
    /// </summary>
    Found = 1,
    /// <summary>
    /// No blocks are localized.
    /// </summary>
    NotFound = 2,
    /// <summary>
    /// Request time out (more than 1 minute)
    /// </summary>
    RequestTimeout = 3,
    /// <summary>
    /// Request time interval is too low
    /// </summary>
    RequestIntervalTooLow = 4,
    /// <summary>
    /// QPS limit exceeded
    /// </summary>
    QpsLimitExceeded = 5,
    /// <summary>
    /// Service is waking up
    /// </summary>
    WakingUp = 6,
    /// <summary>
    /// SpotVersionId is missing. It is possible that the value is not set.
    /// </summary>
    MissingSpotVersionId = 7,
    /// <summary>
    /// API Token expired.
    /// </summary>
    ApiTokenExpired = 8,
};

class MegaTrackerLocalizationResponse;

class MegaTracker;

enum class CloudRecognizationStatus
{
    /// <summary>
    /// Unknown error
    /// </summary>
    UnknownError = 0,
    /// <summary>
    /// A target is recognized.
    /// </summary>
    FoundTarget = 1,
    /// <summary>
    /// No target is recognized.
    /// </summary>
    TargetNotFound = 2,
    /// <summary>
    /// Reached the access limit
    /// </summary>
    ReachedAccessLimit = 3,
    /// <summary>
    /// Request interval too low
    /// </summary>
    RequestIntervalTooLow = 4,
    /// <summary>
    /// API Token expired.
    /// </summary>
    ApiTokenExpired = 5,
};

class CloudRecognizationResult;

class CloudRecognizer;

class Buffer;

class BufferDictionary;

class BufferPool;

/// <summary>
/// PixelFormat represents the format of image pixel data. All formats follow the pixel direction from left to right and from top to bottom.
/// </summary>
enum class PixelFormat
{
    /// <summary>
    /// Unknown
    /// </summary>
    Unknown = 0,
    /// <summary>
    /// 256 shades grayscale
    /// </summary>
    Gray = 1,
    /// <summary>
    /// YUV_NV21
    /// </summary>
    YUV_NV21 = 2,
    /// <summary>
    /// YUV_NV12
    /// </summary>
    YUV_NV12 = 3,
    /// <summary>
    /// YUV_I420
    /// </summary>
    YUV_I420 = 4,
    /// <summary>
    /// YUV_YV12
    /// </summary>
    YUV_YV12 = 5,
    /// <summary>
    /// RGB888
    /// </summary>
    RGB888 = 6,
    /// <summary>
    /// BGR888
    /// </summary>
    BGR888 = 7,
    /// <summary>
    /// RGBA8888
    /// </summary>
    RGBA8888 = 8,
    /// <summary>
    /// BGRA8888
    /// </summary>
    BGRA8888 = 9,
};

class Image;

struct Matrix44F;

struct Matrix33F;

struct AccelerometerResult;

struct GyroscopeResult;

struct AttitudeSensorResult;

struct MagnetometerResult;

struct LocationResult;

struct ProximityLocationResult;

/// <summary>
/// working mode in which way the system will utilize the block maps prior.
/// </summary>
enum class BlockPriorMode
{
    Soft = 0,
    Hard = 1,
};

class BlockPriorResult;

struct Vec3D;

struct Vec4F;

struct Vec3F;

struct Vec2F;

struct Vec4I;

struct Vec2I;

class DenseSpatialMap;

struct BlockInfo;

class SceneMesh;

class Accelerometer;

enum class ARCoreCameraDeviceFocusMode
{
    /// <summary>
    /// Auto focus mode
    /// </summary>
    Auto = 0,
    /// <summary>
    /// Fixed focus mode
    /// </summary>
    Fixed = 1,
};

class ARCoreCameraDevice;

enum class ARKitCameraDeviceFocusMode
{
    /// <summary>
    /// Auto focus mode
    /// </summary>
    Auto = 0,
    /// <summary>
    /// Fixed focus mode
    /// </summary>
    Fixed = 1,
};

class ARKitCameraDevice;

class AttitudeSensor;

enum class CameraDeviceFocusMode
{
    /// <summary>
    /// Normal auto focus mode. You should call autoFocus to start the focus in this mode.
    /// </summary>
    Normal = 0,
    /// <summary>
    /// Continuous auto focus mode
    /// </summary>
    Continousauto = 2,
    /// <summary>
    /// Infinity focus mode
    /// </summary>
    Infinity = 3,
    /// <summary>
    /// Macro (close-up) focus mode. You should call autoFocus to start the focus in this mode.
    /// </summary>
    Macro = 4,
    /// <summary>
    /// Medium distance focus mode
    /// </summary>
    Medium = 5,
};

enum class AndroidCameraApiType
{
    /// <summary>
    /// Android Camera1
    /// </summary>
    Camera1 = 0,
    /// <summary>
    /// Android Camera2
    /// </summary>
    Camera2 = 1,
};

enum class CameraDevicePresetProfile
{
    /// <summary>
    /// The same as AVCaptureSessionPresetPhoto.
    /// </summary>
    Photo = 0,
    /// <summary>
    /// The same as AVCaptureSessionPresetHigh.
    /// </summary>
    High = 1,
    /// <summary>
    /// The same as AVCaptureSessionPresetMedium.
    /// </summary>
    Medium = 2,
    /// <summary>
    /// The same as AVCaptureSessionPresetLow.
    /// </summary>
    Low = 3,
};

enum class CameraState
{
    /// <summary>
    /// Unknown
    /// </summary>
    Unknown = 0x00000000,
    /// <summary>
    /// Disconnected
    /// </summary>
    Disconnected = 0x00000001,
    /// <summary>
    /// Preempted by another application.
    /// </summary>
    Preempted = 0x00000002,
};

class CameraDevice;

enum class CameraDevicePreference
{
    /// <summary>
    /// Optimized for `ImageTracker`_ , `ObjectTracker`_ and `CloudRecognizer`_ .
    /// </summary>
    PreferObjectSensing = 0,
    /// <summary>
    /// Optimized for `SurfaceTracker`_ .
    /// </summary>
    PreferSurfaceTracking = 1,
    /// <summary>
    /// Optimized for Motion Tracking . But to use Motion Tracking, it is preferred to use `MotionTrackerCameraDevice`_ .
    /// </summary>
    PreferMotionTracking = 2,
};

class CameraDeviceSelector;

class Gyroscope;

class Magnetometer;

enum class ThreeDofCameraDeviceFocusMode
{
    /// <summary>
    /// Auto focus mode
    /// </summary>
    Auto = 0,
    /// <summary>
    /// Fixed focus mode
    /// </summary>
    Fixed = 1,
};

class ThreeDofCameraDevice;

class VisionOSARKitCameraDevice;

class XREALCameraDevice;

class SurfaceTrackerResult;

class SurfaceTracker;

class EventDumpRecorder;

enum class MotionTrackerCameraDeviceQualityLevel
{
    /// <summary>
    /// The device does not support motion tracking. It has failed in calibration or is to be calibrated.
    /// </summary>
    NotSupported = 0,
    /// <summary>
    /// The device has not passed all our verification. Real time scale is unstable. It can be used in AR showcase or other desktop-scale applications.
    /// </summary>
    Bad = 1,
    /// <summary>
    /// The device has not passed all our verification. Real time scale is almost accurate. It can be used in AR showcase, AR games, AR navigation or other room-scale applications.
    /// </summary>
    Limited = 2,
    /// <summary>
    /// The device has passed all our verification. Real time scale is accurate. It can be used in AR showcase, AR games, AR navigation, 3D reconstruction or other building-scale applications.
    /// </summary>
    Good = 3,
};

enum class MotionTrackerCameraDeviceFPS
{
    /// <summary>
    /// Frame rate is 30 fps, the actual fps will vary with device capabilities. It is the default setting.
    /// </summary>
    Camera_FPS_30 = 0,
    /// <summary>
    /// Frame rate is 60 fps or 30 fps, the actual fps will vary with device capabilities.
    /// </summary>
    Camera_FPS_60 = 1,
};

enum class MotionTrackerCameraDeviceFocusMode
{
    /// <summary>
    /// Continuous auto focus mode, high image definition and good tracking performance. The actual focus mode will vary with device capabilities. It is the default setting.
    /// </summary>
    Continousauto = 0,
    /// <summary>
    /// Focus is fixed on Medium distance, medium image definition and better tracking performance. The actual focus mode will vary with device capabilities.
    /// </summary>
    Medium = 1,
};

enum class MotionTrackerCameraDeviceResolution
{
    /// <summary>
    /// Resolution is typically 1280 x 960 or 1280 x 720, the actual resolution will vary with device capabilities. It is the default setting.
    /// </summary>
    Resolution_1280 = 0,
    /// <summary>
    /// Resolution is typically 640 x 480 or 640 x 360, the actual resolution will vary with device capabilities.
    /// </summary>
    Resolution_640 = 1,
};

enum class MotionTrackerCameraDeviceTrackingMode
{
    /// <summary>
    /// Tracking and hitTestAgainstPointCloud is supported, but plane detection, relocation and anchor are not. It has low CPU and memory usage.
    /// </summary>
    VIO = 0,
    /// <summary>
    /// SLAM(Simultaneous tracking and mapping) supports relocation, plane detection and hitTestAgainstPointCloud. CPU and memory usage are higher. Real time pose correction of anchor is not supported.
    /// </summary>
    SLAM = 1,
    /// <summary>
    /// Anchor is SLAM(Simultaneous tracking and mapping) with real time pose correction. CPU and memory usage are highest. Anchor supports relocation, plane detection, hitTestAgainstPointCloud and pose correction. Anchor is automatically saved when hitTestAgainstPointCloud is called.
    /// </summary>
    Anchor = 2,
    /// <summary>
    /// LargeScale is SLAM(Simultaneous tracking and mapping) with real time pose correction in large scenes.Tracking is more stable at a large depth of field. LargeScale supports relocation, plane detection, hitTestAgainstPointCloud and pose correction. Anchor is automatically saved when hitTestAgainstPointCloud is called.
    /// </summary>
    LargeScale = 3,
};

class MotionTrackerCameraDevice;

class InputFrameRecorder;

class InputFramePlayer;

enum class VideoInputFrameRecorderVideoCodec
{
    H264 = 0,
};

enum class VideoInputFrameRecorderCompletionReason
{
    DiskFull = 0,
};

class VideoInputFrameRecorder;

class VideoInputFramePlayer;

class ImageHelper;

enum class InertialCameraDeviceFocusMode
{
    /// <summary>
    /// Auto focus mode
    /// </summary>
    Auto = 0,
    /// <summary>
    /// Fixed focus mode
    /// </summary>
    Fixed = 1,
};

class InertialCameraDevice;

class CallbackScheduler;

class DelayedCallbackScheduler;

class ImmediateCallbackScheduler;

class JniUtility;

enum class LogLevel
{
    /// <summary>
    /// Error
    /// </summary>
    Error = 0,
    /// <summary>
    /// Warning
    /// </summary>
    Warning = 1,
    /// <summary>
    /// Information
    /// </summary>
    Info = 2,
};

class Log;

class Storage;

class ImageTargetParameters;

class ImageTarget;

enum class ImageTrackerMode
{
    /// <summary>
    /// Quality is preferred.
    /// </summary>
    PreferQuality = 0,
    /// <summary>
    /// Performance is preferred.
    /// </summary>
    PreferPerformance = 1,
};

class ImageTrackerConfig;

class ImageTrackerResult;

class ImageTracker;

class Recorder;

enum class RecordProfile
{
    /// <summary>
    /// 1080P, low quality
    /// </summary>
    Quality_1080P_Low = 0x00000001,
    /// <summary>
    /// 1080P, middle quality
    /// </summary>
    Quality_1080P_Middle = 0x00000002,
    /// <summary>
    /// 1080P, high quality
    /// </summary>
    Quality_1080P_High = 0x00000004,
    /// <summary>
    /// 720P, low quality
    /// </summary>
    Quality_720P_Low = 0x00000008,
    /// <summary>
    /// 720P, middle quality
    /// </summary>
    Quality_720P_Middle = 0x00000010,
    /// <summary>
    /// 720P, high quality
    /// </summary>
    Quality_720P_High = 0x00000020,
    /// <summary>
    /// 480P, low quality
    /// </summary>
    Quality_480P_Low = 0x00000040,
    /// <summary>
    /// 480P, middle quality
    /// </summary>
    Quality_480P_Middle = 0x00000080,
    /// <summary>
    /// 480P, high quality
    /// </summary>
    Quality_480P_High = 0x00000100,
    /// <summary>
    /// default resolution and quality, same as `Quality_720P_Middle`
    /// </summary>
    Quality_Default = 0x00000010,
};

enum class RecordVideoSize
{
    /// <summary>
    /// 1080P
    /// </summary>
    Vid1080p = 0x00000002,
    /// <summary>
    /// 720P
    /// </summary>
    Vid720p = 0x00000010,
    /// <summary>
    /// 480P
    /// </summary>
    Vid480p = 0x00000080,
};

enum class RecordZoomMode
{
    /// <summary>
    /// If output aspect ratio does not fit input, content will be clipped to fit output aspect ratio.
    /// </summary>
    NoZoomAndClip = 0x00000000,
    /// <summary>
    /// If output aspect ratio does not fit input, content will not be clipped and there will be black borders in one dimension.
    /// </summary>
    ZoomInWithAllContent = 0x00000001,
};

enum class RecordVideoOrientation
{
    /// <summary>
    /// video recorded is landscape
    /// </summary>
    Landscape = 0x00000000,
    /// <summary>
    /// video recorded is portrait
    /// </summary>
    Portrait = 0x00000001,
};

enum class RecordStatus
{
    /// <summary>
    /// recording start
    /// </summary>
    OnStarted = 0x00000002,
    /// <summary>
    /// recording stopped
    /// </summary>
    OnStopped = 0x00000004,
    /// <summary>
    /// start fail
    /// </summary>
    FailedToStart = 0x00000202,
    /// <summary>
    /// file write succeed
    /// </summary>
    FileSucceeded = 0x00000400,
    /// <summary>
    /// file write fail
    /// </summary>
    FileFailed = 0x00000401,
    /// <summary>
    /// runtime info with description
    /// </summary>
    LogInfo = 0x00000800,
    /// <summary>
    /// runtime error with description
    /// </summary>
    LogError = 0x00001000,
};

class RecorderConfiguration;

class SparseSpatialMapResult;

enum class PlaneType
{
    /// <summary>
    /// Horizontal plane
    /// </summary>
    Horizontal = 0,
    /// <summary>
    /// Vertical plane
    /// </summary>
    Vertical = 1,
};

class PlaneData;

enum class LocalizationMode
{
    /// <summary>
    /// Attempt to perform localization in current SparseSpatialMap until success.
    /// </summary>
    UntilSuccess = 0,
    /// <summary>
    /// Perform localization only once
    /// </summary>
    Once = 1,
    /// <summary>
    /// Keep performing localization and adjust result on success
    /// </summary>
    KeepUpdate = 2,
    /// <summary>
    /// Keep performing localization and adjust localization result only when localization returns different map ID from previous results
    /// </summary>
    ContinousLocalize = 3,
};

class SparseSpatialMapConfig;

class SparseSpatialMap;

class SparseSpatialMapManager;

enum class EngineOperatingSystem
{
    Windows = 0,
    Linux = 1,
    MacOS = 2,
    iOS = 3,
    Android = 4,
    WinRT = 5,
    VisionOS = 6,
};

enum class ValidationState
{
    Successful = 0,
    Pending = 1,
    Failed = 2,
};

class Engine;

enum class VideoStatus
{
    /// <summary>
    /// Status to indicate something wrong happen in video open or play.
    /// </summary>
    Error = -1,
    /// <summary>
    /// Status to show video finished open and is ready for play.
    /// </summary>
    Ready = 0,
    /// <summary>
    /// Status to indicate video finished play and reached the end.
    /// </summary>
    Completed = 1,
};

enum class VideoType
{
    /// <summary>
    /// Normal video.
    /// </summary>
    Normal = 0,
    /// <summary>
    /// Transparent video, left half is the RGB channel and right half is alpha channel.
    /// </summary>
    TransparentSideBySide = 1,
    /// <summary>
    /// Transparent video, top half is the RGB channel and bottom half is alpha channel.
    /// </summary>
    TransparentTopAndBottom = 2,
};

class VideoPlayer;

/// <summary>
/// Camera device type.
/// </summary>
enum class CameraDeviceType
{
    /// <summary>
    /// Unknown location
    /// </summary>
    Unknown = 0,
    /// <summary>
    /// Rear camera
    /// </summary>
    Back = 1,
    /// <summary>
    /// Front camera
    /// </summary>
    Front = 2,
};

/// <summary>
/// Camera optics model type.
/// </summary>
enum class CameraModelType
{
    /// <summary>
    /// Pinhole camera model
    /// Parameter list is expected in the following order:
    /// fx, fy, cx, cy
    /// </summary>
    Pinhole = 0,
    /// <summary>
    /// OpenCV camera model
    /// Parameter list is expected in the following order:
    /// fx, fy, cx, cy, k1, k2, p1, p2 or
    /// fx, fy, cx, cy, k1, k2, p1, p2, k3 or
    /// fx, fy, cx, cy, k1, k2, p1, p2, k3, k4, k5, k6
    /// </summary>
    OpenCV = 1,
    /// <summary>
    /// OpenCV Fisheye camera model
    /// Parameter list is expected in the following order:
    /// fx, fy, cx, cy, k1 or
    /// fx, fy, cx, cy, k1, k2, k3, k4
    /// </summary>
    OpenCV_Fisheye = 2,
};

/// <summary>
/// Camera transform type.
/// </summary>
enum class CameraTransformType
{
    /// <summary>
    /// 0DOF
    /// camera transform without rotation or translation
    /// </summary>
    ZeroDof = 0,
    /// <summary>
    /// ThreeDofRotOnly
    /// camera transform with 3DOF rotation only
    /// </summary>
    ThreeDofRotOnly = 1,
    /// <summary>
    /// 6DOF
    /// camera transform with fully 6DOF of both rotation and translation
    /// </summary>
    SixDof = 2,
    /// <summary>
    /// 5DOF
    /// camera transform with rotation and 2D translation (without translation in the gravity direction)
    /// </summary>
    FiveDofRotXZ = 3,
};

/// <summary>
/// MotionTrackingStatus describes the quality of device motion tracking.
/// </summary>
enum class MotionTrackingStatus
{
    /// <summary>
    /// Result is not available and should not to be used to render virtual objects or do 3D reconstruction. This value occurs temporarily after initializing, tracking lost or relocalizing.
    /// </summary>
    NotTracking = 0,
    /// <summary>
    /// Tracking is available, but the quality of the result is not good enough. This value occurs temporarily due to weak texture or excessive movement. The result can be used to render virtual objects, but should generally not be used to do 3D reconstruction.
    /// </summary>
    Limited = 1,
    /// <summary>
    /// Tracking with a good quality. The result can be used to render virtual objects or do 3D reconstruction.
    /// </summary>
    Tracking = 2,
};

class CameraParameters;

class SignalSink;

class SignalSource;

class AccelerometerResultSink;

class AccelerometerResultSource;

class GyroscopeResultSink;

class GyroscopeResultSource;

class AttitudeSensorResultSink;

class AttitudeSensorResultSource;

class MagnetometerResultSink;

class MagnetometerResultSource;

class LocationResultSink;

class LocationResultSource;

class ProximityLocationResultSink;

class ProximityLocationResultSource;

class InputFrameSink;

class InputFrameSource;

class OutputFrameSink;

class OutputFrameSource;

class FeedbackFrameSink;

class FeedbackFrameSource;

class InputFrameFork;

class OutputFrameFork;

class OutputFrameJoin;

class FeedbackFrameFork;

class InputFrameThrottler;

class OutputFrameBuffer;

class InputFrameToOutputFrameAdapter;

class InputFrameToFeedbackFrameAdapter;

class MotionInputData;

class InputFrame;

class FrameFilterResult;

class OutputFrame;

class FeedbackFrame;

enum class PermissionStatus
{
    /// <summary>
    /// Permission granted
    /// </summary>
    Granted = 0x00000000,
    /// <summary>
    /// Permission denied
    /// </summary>
    Denied = 0x00000001,
    /// <summary>
    /// A error happened while requesting permission.
    /// </summary>
    Error = 0x00000002,
};

class PoseUtility;

/// <summary>
/// StorageType represents where the images, jsons, videos or other files are located.
/// StorageType specifies the root path, in all interfaces, you can use relative path relative to the root path.
/// </summary>
enum class StorageType
{
    /// <summary>
    /// The app path.
    /// Android: the application&#39;s `persistent data directory &lt;https://developer.android.google.cn/reference/android/content/pm/ApplicationInfo.html#dataDir&gt;`__
    /// iOS: the application&#39;s sandbox directory
    /// Windows: Windows: the application&#39;s executable directory
    /// Mac: the application’s executable directory (if app is a bundle, this path is inside the bundle)
    /// </summary>
    App = 0,
    /// <summary>
    /// The assets path.
    /// Android: assets directory (inside apk)
    /// iOS: the application&#39;s executable directory
    /// Windows: EasyAR.dll directory
    /// Mac: libEasyAR.dylib directory
    /// **Note:** *this path is different if you are using Unity3D. It will point to the StreamingAssets folder.*
    /// </summary>
    Assets = 1,
    /// <summary>
    /// The absolute path (json/image path or video path) or url (video only).
    /// </summary>
    Absolute = 2,
};

class Target;

enum class TargetStatus
{
    /// <summary>
    /// The target is not being tracking.
    /// </summary>
    NotTracking = 0,
    /// <summary>
    /// The target is being tracking.
    /// </summary>
    Tracking = 1,
};

class TargetInstance;

class TargetTrackerResult;

class TextureId;

/// <summary>
/// ObjectTargetParameters represents the parameters to create a `ObjectTarget`_ .
/// </summary>
class ObjectTargetParameters
{
protected:
    std::shared_ptr<easyar_ObjectTargetParameters> cdata_;
    void init_cdata(std::shared_ptr<easyar_ObjectTargetParameters> cdata);
    ObjectTargetParameters & operator=(const ObjectTargetParameters & data) = delete;
public:
    ObjectTargetParameters(std::shared_ptr<easyar_ObjectTargetParameters> cdata);
    virtual ~ObjectTargetParameters();

    std::shared_ptr<easyar_ObjectTargetParameters> get_cdata();
    static std::shared_ptr<ObjectTargetParameters> from_cdata(std::shared_ptr<easyar_ObjectTargetParameters> cdata);

    ObjectTargetParameters();
    /// <summary>
    /// Gets `Buffer`_ dictionary.
    /// </summary>
    std::shared_ptr<BufferDictionary> bufferDictionary();
    /// <summary>
    /// Sets `Buffer`_ dictionary. obj, mtl and jpg/png files shall be loaded into the dictionay, and be able to be located by relative or absolute paths.
    /// </summary>
    void setBufferDictionary(std::shared_ptr<BufferDictionary> bufferDictionary);
    /// <summary>
    /// Gets obj file path.
    /// </summary>
    std::string objPath();
    /// <summary>
    /// Sets obj file path.
    /// </summary>
    void setObjPath(std::string objPath);
    /// <summary>
    /// Gets target name. It can be used to distinguish targets.
    /// </summary>
    std::string name();
    /// <summary>
    /// Sets target name.
    /// </summary>
    void setName(std::string name);
    /// <summary>
    /// Gets the target uid. You can set this uid in the json config as a method to distinguish from targets.
    /// </summary>
    std::string uid();
    /// <summary>
    /// Sets target uid.
    /// </summary>
    void setUid(std::string uid);
    /// <summary>
    /// Gets meta data.
    /// </summary>
    std::string meta();
    /// <summary>
    /// Sets meta data。
    /// </summary>
    void setMeta(std::string meta);
    /// <summary>
    /// Gets the scale of model. The value is the physical scale divided by model coordinate system scale. The default value is 1. (Supposing the unit of model coordinate system is 1 meter.)
    /// </summary>
    float scale();
    /// <summary>
    /// Sets the scale of model. The value is the physical scale divided by model coordinate system scale. The default value is 1. (Supposing the unit of model coordinate system is 1 meter.)
    /// It is needed to set the model scale in rendering engine separately.
    /// </summary>
    void setScale(float size);
};

/// <summary>
/// Target is the base class for all targets that can be tracked by `ImageTracker`_ or other algorithms inside EasyAR.
/// </summary>
class Target
{
protected:
    std::shared_ptr<easyar_Target> cdata_;
    void init_cdata(std::shared_ptr<easyar_Target> cdata);
    Target & operator=(const Target & data) = delete;
public:
    Target(std::shared_ptr<easyar_Target> cdata);
    virtual ~Target();

    std::shared_ptr<easyar_Target> get_cdata();
    static std::shared_ptr<Target> from_cdata(std::shared_ptr<easyar_Target> cdata);

    /// <summary>
    /// Returns the target id. A target id is a integer number generated at runtime. This id is non-zero and increasing globally.
    /// </summary>
    int runtimeID();
    /// <summary>
    /// Returns the target uid. A target uid is useful in cloud based algorithms. If no cloud is used, you can set this uid in the json config as a alternative method to distinguish from targets.
    /// </summary>
    std::string uid();
    /// <summary>
    /// Returns the target name. Name is used to distinguish targets in a json file.
    /// </summary>
    std::string name();
    /// <summary>
    /// Set name. It will erase previously set data or data from cloud.
    /// </summary>
    void setName(std::string name);
    /// <summary>
    /// Returns the meta data set by setMetaData. Or, in a cloud returned target, returns the meta data set in the cloud server.
    /// </summary>
    std::string meta();
    /// <summary>
    /// Set meta data. It will erase previously set data or data from cloud.
    /// </summary>
    void setMeta(std::string data);
};

/// <summary>
/// ObjectTarget represents 3d object targets that can be tracked by `ObjectTracker`_ .
/// The size of ObjectTarget is determined by the `obj` file. You can change it by changing the object `scale`, which is default to 1.
/// A ObjectTarget can be tracked by `ObjectTracker`_ after a successful load into the `ObjectTracker`_ using `ObjectTracker.loadTarget`_ .
/// </summary>
class ObjectTarget : public Target
{
protected:
    std::shared_ptr<easyar_ObjectTarget> cdata_;
    void init_cdata(std::shared_ptr<easyar_ObjectTarget> cdata);
    ObjectTarget & operator=(const ObjectTarget & data) = delete;
public:
    ObjectTarget(std::shared_ptr<easyar_ObjectTarget> cdata);
    virtual ~ObjectTarget();

    std::shared_ptr<easyar_ObjectTarget> get_cdata();
    static std::shared_ptr<ObjectTarget> from_cdata(std::shared_ptr<easyar_ObjectTarget> cdata);

    ObjectTarget();
    /// <summary>
    /// Creates a target from parameters.
    /// </summary>
    static std::optional<std::shared_ptr<ObjectTarget>> createFromParameters(std::shared_ptr<ObjectTargetParameters> parameters);
    /// <summary>
    /// Creats a target from obj, mtl and jpg/png files.
    /// </summary>
    static std::optional<std::shared_ptr<ObjectTarget>> createFromObjectFile(std::string path, StorageType storageType, std::string name, std::string uid, std::string meta, float scale);
    /// <summary>
    /// The scale of model. The value is the physical scale divided by model coordinate system scale. The default value is 1. (Supposing the unit of model coordinate system is 1 meter.)
    /// </summary>
    float scale();
    /// <summary>
    /// The bounding box of object, it contains the 8 points of the box.
    /// Vertices&#39;s indices are defined and stored following the rule:
    /// ::
    ///
    ///       4-----7
    ///      /|    /|
    ///     5-----6 |    z
    ///     | |   | |    |
    ///     | 0---|-3    o---y
    ///     |/    |/    /
    ///     1-----2    x
    /// </summary>
    std::vector<Vec3F> boundingBox();
    /// <summary>
    /// Sets model target scale, this will overwrite the value set in the json file or the default value. The value is the physical scale divided by model coordinate system scale. The default value is 1. (Supposing the unit of model coordinate system is 1 meter.)
    /// It is needed to set the model scale in rendering engine separately.
    /// It also should been done before loading ObjectTarget into  `ObjectTracker`_ using `ObjectTracker.loadTarget`_.
    /// </summary>
    bool setScale(float scale);
    /// <summary>
    /// Returns the target id. A target id is a integer number generated at runtime. This id is non-zero and increasing globally.
    /// </summary>
    int runtimeID();
    /// <summary>
    /// Returns the target uid. A target uid is useful in cloud based algorithms. If no cloud is used, you can set this uid in the json config as a alternative method to distinguish from targets.
    /// </summary>
    std::string uid();
    /// <summary>
    /// Returns the target name. Name is used to distinguish targets in a json file.
    /// </summary>
    std::string name();
    /// <summary>
    /// Set name. It will erase previously set data or data from cloud.
    /// </summary>
    void setName(std::string name);
    /// <summary>
    /// Returns the meta data set by setMetaData. Or, in a cloud returned target, returns the meta data set in the cloud server.
    /// </summary>
    std::string meta();
    /// <summary>
    /// Set meta data. It will erase previously set data or data from cloud.
    /// </summary>
    void setMeta(std::string data);
};

/// <summary>
/// FrameFilterResult is the base class for result classes of all synchronous algorithm components.
/// </summary>
class FrameFilterResult
{
protected:
    std::shared_ptr<easyar_FrameFilterResult> cdata_;
    void init_cdata(std::shared_ptr<easyar_FrameFilterResult> cdata);
    FrameFilterResult & operator=(const FrameFilterResult & data) = delete;
public:
    FrameFilterResult(std::shared_ptr<easyar_FrameFilterResult> cdata);
    virtual ~FrameFilterResult();

    std::shared_ptr<easyar_FrameFilterResult> get_cdata();
    static std::shared_ptr<FrameFilterResult> from_cdata(std::shared_ptr<easyar_FrameFilterResult> cdata);

};

/// <summary>
/// TargetTrackerResult is the base class of `ImageTrackerResult`_ and `ObjectTrackerResult`_ .
/// </summary>
class TargetTrackerResult : public FrameFilterResult
{
protected:
    std::shared_ptr<easyar_TargetTrackerResult> cdata_;
    void init_cdata(std::shared_ptr<easyar_TargetTrackerResult> cdata);
    TargetTrackerResult & operator=(const TargetTrackerResult & data) = delete;
public:
    TargetTrackerResult(std::shared_ptr<easyar_TargetTrackerResult> cdata);
    virtual ~TargetTrackerResult();

    std::shared_ptr<easyar_TargetTrackerResult> get_cdata();
    static std::shared_ptr<TargetTrackerResult> from_cdata(std::shared_ptr<easyar_TargetTrackerResult> cdata);

    /// <summary>
    /// Returns the list of `TargetInstance`_ contained in the result.
    /// </summary>
    std::vector<std::shared_ptr<TargetInstance>> targetInstances();
    /// <summary>
    /// Sets the list of `TargetInstance`_ contained in the result.
    /// </summary>
    void setTargetInstances(std::vector<std::shared_ptr<TargetInstance>> instances);
};

/// <summary>
/// Result of `ObjectTracker`_ .
/// </summary>
class ObjectTrackerResult : public TargetTrackerResult
{
protected:
    std::shared_ptr<easyar_ObjectTrackerResult> cdata_;
    void init_cdata(std::shared_ptr<easyar_ObjectTrackerResult> cdata);
    ObjectTrackerResult & operator=(const ObjectTrackerResult & data) = delete;
public:
    ObjectTrackerResult(std::shared_ptr<easyar_ObjectTrackerResult> cdata);
    virtual ~ObjectTrackerResult();

    std::shared_ptr<easyar_ObjectTrackerResult> get_cdata();
    static std::shared_ptr<ObjectTrackerResult> from_cdata(std::shared_ptr<easyar_ObjectTrackerResult> cdata);

    /// <summary>
    /// Returns the list of `TargetInstance`_ contained in the result.
    /// </summary>
    std::vector<std::shared_ptr<TargetInstance>> targetInstances();
    /// <summary>
    /// Sets the list of `TargetInstance`_ contained in the result.
    /// </summary>
    void setTargetInstances(std::vector<std::shared_ptr<TargetInstance>> instances);
};

/// <summary>
/// ObjectTracker implements 3D object target detection and tracking.
/// ObjectTracker occupies (1 + SimultaneousNum) buffers of camera. Use setBufferCapacity of camera to set an amount of buffers that is not less than the sum of amount of buffers occupied by all components.
/// After creation, you can call start/stop to enable/disable the track process. start and stop are very lightweight calls.
/// When the component is not needed anymore, call close function to close it. It shall not be used after calling close.
/// ObjectTracker inputs `FeedbackFrame`_ from feedbackFrameSink. `FeedbackFrameSource`_ shall be connected to feedbackFrameSink for use.
/// Before a `Target`_ can be tracked by ObjectTracker, you have to load it using loadTarget/unloadTarget. You can get load/unload results from callbacks passed into the interfaces.
/// </summary>
class ObjectTracker
{
protected:
    std::shared_ptr<easyar_ObjectTracker> cdata_;
    void init_cdata(std::shared_ptr<easyar_ObjectTracker> cdata);
    ObjectTracker & operator=(const ObjectTracker & data) = delete;
public:
    ObjectTracker(std::shared_ptr<easyar_ObjectTracker> cdata);
    virtual ~ObjectTracker();

    std::shared_ptr<easyar_ObjectTracker> get_cdata();
    static std::shared_ptr<ObjectTracker> from_cdata(std::shared_ptr<easyar_ObjectTracker> cdata);

    /// <summary>
    /// Returns true.
    /// </summary>
    static bool isAvailable();
    /// <summary>
    /// `FeedbackFrame`_ input port. The InputFrame member of FeedbackFrame must have raw image, timestamp, and camera parameters. Both pinhole and fisheye camera are supported.
    /// </summary>
    std::shared_ptr<FeedbackFrameSink> feedbackFrameSink();
    /// <summary>
    /// Camera buffers occupied in this component.
    /// </summary>
    int bufferRequirement();
    /// <summary>
    /// `OutputFrame`_ output port.
    /// </summary>
    std::shared_ptr<OutputFrameSource> outputFrameSource();
    /// <summary>
    /// Creates an instance.
    /// </summary>
    static std::shared_ptr<ObjectTracker> create();
    /// <summary>
    /// Sets result post-processing.
    /// enablePersistentTargetInstance defaults to false. When it is enabled and `InputFrame`_ contains spatial information, targetInstances in `ImageTrackerResult`_ will contain all recognized instances (with not tracking target instances).
    /// enableMotionFusion defaults to false. When it is enabled and `InputFrame`_ contains temporal information and spatial information, pose of targetInstances in `ImageTrackerResult`_ will utilize RealTimeCoordinateTransform .
    /// </summary>
    void setResultPostProcessing(bool enablePersistentTargetInstance, bool enableMotionFusion);
    /// <summary>
    /// Sets result async mode. Set true If results are to be outputted via outputFrameSource, false if results are to be fetched via getSyncResult. enableAsync defaults to true. Sync mode is only available with input frames including spatial information and with a XR license.
    /// </summary>
    bool setResultAsyncMode(bool enableAsync);
    /// <summary>
    /// Starts the track algorithm.
    /// </summary>
    bool start();
    /// <summary>
    /// Stops the track algorithm. Call start to start the track again.
    /// </summary>
    void stop();
    /// <summary>
    /// Close. The component shall not be used after calling close.
    /// </summary>
    void close();
    /// <summary>
    /// Load a `Target`_ into the tracker. A Target can only be tracked by tracker after a successful load.
    /// This method is an asynchronous method. A load operation may take some time to finish and detection of a new/lost target may take more time during the load. The track time after detection will not be affected. If you want to know the load result, you have to handle the callback data. The callback will be called from the thread specified by `CallbackScheduler`_ . It will not block the track thread or any other operations except other load/unload.
    /// </summary>
    void loadTarget(std::shared_ptr<Target> target, std::shared_ptr<CallbackScheduler> callbackScheduler, std::function<void(std::shared_ptr<Target>, bool)> callback);
    /// <summary>
    /// Unload a `Target`_ from the tracker.
    /// This method is an asynchronous method. An unload operation may take some time to finish and detection of a new/lost target may take more time during the unload. If you want to know the unload result, you have to handle the callback data. The callback will be called from the thread specified by `CallbackScheduler`_ . It will not block the track thread or any other operations except other load/unload.
    /// </summary>
    void unloadTarget(std::shared_ptr<Target> target, std::shared_ptr<CallbackScheduler> callbackScheduler, std::function<void(std::shared_ptr<Target>, bool)> callback);
    /// <summary>
    /// Returns current loaded targets in the tracker. If an asynchronous load/unload is in progress, the returned value will not reflect the result until all load/unload finish.
    /// </summary>
    std::vector<std::shared_ptr<Target>> targets();
    /// <summary>
    /// Sets the max number of targets which will be the simultaneously tracked by the tracker. The default value is 1.
    /// </summary>
    bool setSimultaneousNum(int num);
    /// <summary>
    /// Gets the max number of targets which will be the simultaneously tracked by the tracker. The default value is 1.
    /// </summary>
    int simultaneousNum();
    /// <summary>
    /// Get synchronized result. If ObjectTracker is paused, or the result async mode is not set to false through setResultAsyncMode, the return value is empty.
    /// </summary>
    std::optional<std::shared_ptr<ObjectTrackerResult>> getSyncResult(std::shared_ptr<MotionInputData> motionInputData);
};

/// <summary>
/// ARCoreDeviceListDownloader is used for download and update of device list data in ARCoreCameraDevice.
/// </summary>
class ARCoreDeviceListDownloader
{
protected:
    std::shared_ptr<easyar_ARCoreDeviceListDownloader> cdata_;
    void init_cdata(std::shared_ptr<easyar_ARCoreDeviceListDownloader> cdata);
    ARCoreDeviceListDownloader & operator=(const ARCoreDeviceListDownloader & data) = delete;
public:
    ARCoreDeviceListDownloader(std::shared_ptr<easyar_ARCoreDeviceListDownloader> cdata);
    virtual ~ARCoreDeviceListDownloader();

    std::shared_ptr<easyar_ARCoreDeviceListDownloader> get_cdata();
    static std::shared_ptr<ARCoreDeviceListDownloader> from_cdata(std::shared_ptr<easyar_ARCoreDeviceListDownloader> cdata);

    ARCoreDeviceListDownloader();
    void download(std::optional<int> timeoutMilliseconds, std::shared_ptr<CallbackScheduler> callbackScheduler, std::function<void(ARCoreDeviceListDownloadStatus, std::optional<std::string>)> onCompleted);
};

/// <summary>
/// CalibrationDownloader is used for download and update of calibration data in MotionTracker. The calibration data will only take effect after reallocation of MotionTracker.
/// </summary>
class CalibrationDownloader
{
protected:
    std::shared_ptr<easyar_CalibrationDownloader> cdata_;
    void init_cdata(std::shared_ptr<easyar_CalibrationDownloader> cdata);
    CalibrationDownloader & operator=(const CalibrationDownloader & data) = delete;
public:
    CalibrationDownloader(std::shared_ptr<easyar_CalibrationDownloader> cdata);
    virtual ~CalibrationDownloader();

    std::shared_ptr<easyar_CalibrationDownloader> get_cdata();
    static std::shared_ptr<CalibrationDownloader> from_cdata(std::shared_ptr<easyar_CalibrationDownloader> cdata);

    CalibrationDownloader();
    void download(std::optional<int> timeoutMilliseconds, std::shared_ptr<CallbackScheduler> callbackScheduler, std::function<void(CalibrationDownloadStatus, std::optional<std::string>)> onCompleted);
};

/// <summary>
/// The block instance localized by MegaTracker.
/// </summary>
class CloudLocalizerBlockInstance
{
protected:
    std::shared_ptr<easyar_CloudLocalizerBlockInstance> cdata_;
    void init_cdata(std::shared_ptr<easyar_CloudLocalizerBlockInstance> cdata);
    CloudLocalizerBlockInstance & operator=(const CloudLocalizerBlockInstance & data) = delete;
public:
    CloudLocalizerBlockInstance(std::shared_ptr<easyar_CloudLocalizerBlockInstance> cdata);
    virtual ~CloudLocalizerBlockInstance();

    std::shared_ptr<easyar_CloudLocalizerBlockInstance> get_cdata();
    static std::shared_ptr<CloudLocalizerBlockInstance> from_cdata(std::shared_ptr<easyar_CloudLocalizerBlockInstance> cdata);

    /// <summary>
    /// The ID of the block.
    /// </summary>
    std::string blockId();
    /// <summary>
    /// The name of the block.
    /// </summary>
    std::string name();
    /// <summary>
    /// The map pose in the camera coordinates.
    /// </summary>
    Matrix44F pose();
};

class CloudLocalizerResult
{
protected:
    std::shared_ptr<easyar_CloudLocalizerResult> cdata_;
    void init_cdata(std::shared_ptr<easyar_CloudLocalizerResult> cdata);
    CloudLocalizerResult & operator=(const CloudLocalizerResult & data) = delete;
public:
    CloudLocalizerResult(std::shared_ptr<easyar_CloudLocalizerResult> cdata);
    virtual ~CloudLocalizerResult();

    std::shared_ptr<easyar_CloudLocalizerResult> get_cdata();
    static std::shared_ptr<CloudLocalizerResult> from_cdata(std::shared_ptr<easyar_CloudLocalizerResult> cdata);

    /// <summary>
    /// Localization status.
    /// </summary>
    CloudLocalizerStatus localizeStatus();
    /// <summary>
    /// The spot version ID. Only available with `MegaApiType`_.Landmark .
    /// </summary>
    std::optional<std::string> spotVersionId();
    /// <summary>
    /// Current localized block instances.
    /// </summary>
    std::vector<std::shared_ptr<CloudLocalizerBlockInstance>> blockInstances();
    /// <summary>
    /// Extra informations of the localization.
    /// </summary>
    std::string extraInfo();
    /// <summary>
    /// Detailed exception message.
    /// </summary>
    std::string exceptionInfo();
    /// <summary>
    /// The duration in seconds for server response.
    /// </summary>
    std::optional<double> serverResponseDuration();
    /// <summary>
    /// The duration in seconds for server internal calculation.
    /// </summary>
    std::optional<double> serverCalculationDuration();
};

class DeviceAuxiliaryInfo
{
protected:
    std::shared_ptr<easyar_DeviceAuxiliaryInfo> cdata_;
    void init_cdata(std::shared_ptr<easyar_DeviceAuxiliaryInfo> cdata);
    DeviceAuxiliaryInfo & operator=(const DeviceAuxiliaryInfo & data) = delete;
public:
    DeviceAuxiliaryInfo(std::shared_ptr<easyar_DeviceAuxiliaryInfo> cdata);
    virtual ~DeviceAuxiliaryInfo();

    std::shared_ptr<easyar_DeviceAuxiliaryInfo> get_cdata();
    static std::shared_ptr<DeviceAuxiliaryInfo> from_cdata(std::shared_ptr<easyar_DeviceAuxiliaryInfo> cdata);

    static std::shared_ptr<DeviceAuxiliaryInfo> create();
    void setAcceleration(AccelerometerResult acce);
    void setGPSLocation(LocationResult gps);
    void setProximityLocation(ProximityLocationResult proximity);
    void setBlockPrior(std::shared_ptr<BlockPriorResult> blockPrior);
    void setECompass(double northHeading, double headingAccuracy);
};

/// <summary>
/// CloudLocalizer implements cloud based localization.
/// </summary>
class CloudLocalizer
{
protected:
    std::shared_ptr<easyar_CloudLocalizer> cdata_;
    void init_cdata(std::shared_ptr<easyar_CloudLocalizer> cdata);
    CloudLocalizer & operator=(const CloudLocalizer & data) = delete;
public:
    CloudLocalizer(std::shared_ptr<easyar_CloudLocalizer> cdata);
    virtual ~CloudLocalizer();

    std::shared_ptr<easyar_CloudLocalizer> get_cdata();
    static std::shared_ptr<CloudLocalizer> from_cdata(std::shared_ptr<easyar_CloudLocalizer> cdata);

    /// <summary>
    /// Returns true.
    /// </summary>
    static bool isAvailable();
    /// <summary>
    /// Creates an instance and connects to the server.
    /// </summary>
    static std::shared_ptr<CloudLocalizer> create(std::string server, std::string apiKey, std::string apiSecret, std::string appId);
    /// <summary>
    /// Creates an instance with API Token and connects to the server.
    /// </summary>
    static std::shared_ptr<CloudLocalizer> createWithToken(std::string server, std::string apiToken, std::string appId);
    /// <summary>
    /// Updates API Token.
    /// </summary>
    void updateToken(std::string apiToken);
    /// <summary>
    /// Sets MEGA API Type. The default is Block.
    /// </summary>
    void setMegaApiType(MegaApiType type);
    /// <summary>
    /// Send localization request.
    /// Send `InputFrame`_ to resolve a cloud localization. `InputFrame`_ should have at least image data and camera parameters.
    /// message input is a json string.
    /// </summary>
    void resolve(std::shared_ptr<InputFrame> inputFrame, std::string message, std::shared_ptr<DeviceAuxiliaryInfo> deviceAuxInfo, std::optional<int> timeoutMilliseconds, std::shared_ptr<CallbackScheduler> callbackScheduler, std::function<void(std::shared_ptr<CloudLocalizerResult>)> callback);
    /// <summary>
    /// Send localization request.
    /// Send `InputFrame`_ to resolve a cloud localization. `InputFrame`_ should have at least image data and camera parameters.
    /// message input is a json string.
    /// </summary>
    void resolveLandmark(std::shared_ptr<InputFrame> inputFrame, std::string message, std::shared_ptr<DeviceAuxiliaryInfo> deviceAuxInfo, std::string spotVersionId, std::optional<int> timeoutMilliseconds, std::shared_ptr<CallbackScheduler> callbackScheduler, std::function<void(std::shared_ptr<CloudLocalizerResult>)> callback);
    /// <summary>
    /// Stops the localization and closes connection. The component shall not be used after calling close.
    /// </summary>
    void close();
};

class MegaLandmarkFilterResult
{
protected:
    std::shared_ptr<easyar_MegaLandmarkFilterResult> cdata_;
    void init_cdata(std::shared_ptr<easyar_MegaLandmarkFilterResult> cdata);
    MegaLandmarkFilterResult & operator=(const MegaLandmarkFilterResult & data) = delete;
public:
    MegaLandmarkFilterResult(std::shared_ptr<easyar_MegaLandmarkFilterResult> cdata);
    virtual ~MegaLandmarkFilterResult();

    std::shared_ptr<easyar_MegaLandmarkFilterResult> get_cdata();
    static std::shared_ptr<MegaLandmarkFilterResult> from_cdata(std::shared_ptr<easyar_MegaLandmarkFilterResult> cdata);

    /// <summary>
    /// Request status.
    /// </summary>
    MegaLandmarkFilterStatus status();
    /// <summary>
    /// The spot version ID.
    /// </summary>
    std::optional<std::string> spotVersionId();
    /// <summary>
    /// Detailed exception message.
    /// </summary>
    std::string exceptionInfo();
};

/// <summary>
/// MegaLandmarkFilter implements cloud based visual positioning localization filtering.
/// </summary>
class MegaLandmarkFilter
{
protected:
    std::shared_ptr<easyar_MegaLandmarkFilter> cdata_;
    void init_cdata(std::shared_ptr<easyar_MegaLandmarkFilter> cdata);
    MegaLandmarkFilter & operator=(const MegaLandmarkFilter & data) = delete;
public:
    MegaLandmarkFilter(std::shared_ptr<easyar_MegaLandmarkFilter> cdata);
    virtual ~MegaLandmarkFilter();

    std::shared_ptr<easyar_MegaLandmarkFilter> get_cdata();
    static std::shared_ptr<MegaLandmarkFilter> from_cdata(std::shared_ptr<easyar_MegaLandmarkFilter> cdata);

    /// <summary>
    /// Returns true.
    /// </summary>
    static bool isAvailable();
    /// <summary>
    /// Creates an instance and connects to the server.
    /// </summary>
    static std::shared_ptr<MegaLandmarkFilter> create(std::string server, std::string apiKey, std::string apiSecret, std::string appId);
    /// <summary>
    /// Creates an instance with API Token.
    /// </summary>
    static std::shared_ptr<MegaLandmarkFilter> createWithToken(std::string server, std::string apiToken, std::string appId);
    /// <summary>
    /// Updates API Token.
    /// </summary>
    void updateToken(std::string apiToken);
    /// <summary>
    /// Location filtering.
    /// Send GPS information to get SpotVersionId.
    /// </summary>
    void filterByLocation(LocationResult gps, std::optional<int> timeoutMilliseconds, std::shared_ptr<CallbackScheduler> callbackScheduler, std::function<void(std::shared_ptr<MegaLandmarkFilterResult>)> callback);
    /// <summary>
    /// Filtering by SpotId.
    /// Returns SpotVersionId.
    /// </summary>
    void filterBySpotId(std::string spotId, std::optional<int> timeoutMilliseconds, std::shared_ptr<CallbackScheduler> callbackScheduler, std::function<void(std::shared_ptr<MegaLandmarkFilterResult>)> callback);
    /// <summary>
    /// Closes connection. The component shall not be used after calling close.
    /// </summary>
    void close();
};

/// <summary>
/// The block instance localized by MegaTracker.
/// </summary>
class MegaTrackerBlockInstance
{
protected:
    std::shared_ptr<easyar_MegaTrackerBlockInstance> cdata_;
    void init_cdata(std::shared_ptr<easyar_MegaTrackerBlockInstance> cdata);
    MegaTrackerBlockInstance & operator=(const MegaTrackerBlockInstance & data) = delete;
public:
    MegaTrackerBlockInstance(std::shared_ptr<easyar_MegaTrackerBlockInstance> cdata);
    virtual ~MegaTrackerBlockInstance();

    std::shared_ptr<easyar_MegaTrackerBlockInstance> get_cdata();
    static std::shared_ptr<MegaTrackerBlockInstance> from_cdata(std::shared_ptr<easyar_MegaTrackerBlockInstance> cdata);

    /// <summary>
    /// The appId of service.
    /// </summary>
    std::string appId();
    /// <summary>
    /// The ID of the block.
    /// </summary>
    std::string blockId();
    /// <summary>
    /// The name of the block.
    /// </summary>
    std::string name();
    /// <summary>
    /// The map block pose in the camera coordinates.
    /// </summary>
    Matrix44F pose();
};

/// <summary>
/// The result of MegaTracker. Updated at the same frame rate with OutputFrame.
/// </summary>
class MegaTrackerResult : public FrameFilterResult
{
protected:
    std::shared_ptr<easyar_MegaTrackerResult> cdata_;
    void init_cdata(std::shared_ptr<easyar_MegaTrackerResult> cdata);
    MegaTrackerResult & operator=(const MegaTrackerResult & data) = delete;
public:
    MegaTrackerResult(std::shared_ptr<easyar_MegaTrackerResult> cdata);
    virtual ~MegaTrackerResult();

    std::shared_ptr<easyar_MegaTrackerResult> get_cdata();
    static std::shared_ptr<MegaTrackerResult> from_cdata(std::shared_ptr<easyar_MegaTrackerResult> cdata);

    /// <summary>
    /// Current localized block instances. An existing instance will be preserved until another block is localized, or when MegaTracker is stopped or paused.
    /// </summary>
    std::vector<std::shared_ptr<MegaTrackerBlockInstance>> instances();
};

/// <summary>
/// The response of MegaTracker localization request.
/// </summary>
class MegaTrackerLocalizationResponse
{
protected:
    std::shared_ptr<easyar_MegaTrackerLocalizationResponse> cdata_;
    void init_cdata(std::shared_ptr<easyar_MegaTrackerLocalizationResponse> cdata);
    MegaTrackerLocalizationResponse & operator=(const MegaTrackerLocalizationResponse & data) = delete;
public:
    MegaTrackerLocalizationResponse(std::shared_ptr<easyar_MegaTrackerLocalizationResponse> cdata);
    virtual ~MegaTrackerLocalizationResponse();

    std::shared_ptr<easyar_MegaTrackerLocalizationResponse> get_cdata();
    static std::shared_ptr<MegaTrackerLocalizationResponse> from_cdata(std::shared_ptr<easyar_MegaTrackerLocalizationResponse> cdata);

    /// <summary>
    /// The input frame on request.
    /// </summary>
    std::shared_ptr<InputFrame> inputFrame();
    /// <summary>
    /// The accelerometer reading on request.
    /// </summary>
    std::optional<AccelerometerResult> acceleration();
    /// <summary>
    /// The location reading on request.
    /// </summary>
    std::optional<LocationResult> location();
    /// <summary>
    /// Localization status.
    /// </summary>
    MegaTrackerLocalizationStatus status();
    /// <summary>
    /// The spot version ID.
    /// </summary>
    std::optional<std::string> spotVersionId();
    /// <summary>
    /// Current localized block instances. An existing instance will be preserved until another block is localized, or when MegaTracker is stopped or paused.
    /// </summary>
    std::vector<std::shared_ptr<MegaTrackerBlockInstance>> instances();
    /// <summary>
    /// The appId of service.
    /// </summary>
    std::string appId();
    /// <summary>
    /// The duration in seconds for server response.
    /// </summary>
    std::optional<double> serverResponseDuration();
    /// <summary>
    /// The duration in seconds for server internal calculation.
    /// </summary>
    std::optional<double> serverCalculationDuration();
    /// <summary>
    /// Error message. It is filled when status is UnknownError.
    /// </summary>
    std::optional<std::string> errorMessage();
    std::string extraInfo();
};

/// <summary>
/// Provides cloud based localization.
/// MegaTracker occupies 1 buffers of camera.
/// </summary>
class MegaTracker
{
protected:
    std::shared_ptr<easyar_MegaTracker> cdata_;
    void init_cdata(std::shared_ptr<easyar_MegaTracker> cdata);
    MegaTracker & operator=(const MegaTracker & data) = delete;
public:
    MegaTracker(std::shared_ptr<easyar_MegaTracker> cdata);
    virtual ~MegaTracker();

    std::shared_ptr<easyar_MegaTracker> get_cdata();
    static std::shared_ptr<MegaTracker> from_cdata(std::shared_ptr<easyar_MegaTracker> cdata);

    /// <summary>
    /// Check whether SparseSpatialMap is is available, always return true.
    /// </summary>
    static bool isAvailable();
    /// <summary>
    /// Input port for input frame. For MegaTracker to work, the inputFrame must include camera parameters, timestamp and spatial information. See also `InputFrameSink`_ .
    /// </summary>
    std::shared_ptr<InputFrameSink> inputFrameSink();
    /// <summary>
    /// Input port for accelerometer result. See also `AccelerometerResultSink`_ .
    /// </summary>
    std::shared_ptr<AccelerometerResultSink> accelerometerResultSink();
    /// <summary>
    /// Optional. Input port for location result. See also `LocationResultSink`_ .
    /// </summary>
    std::shared_ptr<LocationResultSink> locationResultSink();
    /// <summary>
    /// Optional. Input port for proximity location result. See also `ProximityLocationResultSink`_ .
    /// </summary>
    std::shared_ptr<ProximityLocationResultSink> proximityLocationResultSink();
    /// <summary>
    /// Camera buffers occupied in this component.
    /// </summary>
    int bufferRequirement();
    /// <summary>
    /// Output port for output frame. See also `OutputFrameSource`_ .
    /// </summary>
    std::shared_ptr<OutputFrameSource> outputFrameSource();
    /// <summary>
    /// Creates an instance.
    /// </summary>
    static std::shared_ptr<MegaTracker> create(std::string server, std::string apiKey, std::string apiSecret, std::string appId);
    /// <summary>
    /// Creates an instance with API Token.
    /// </summary>
    static std::shared_ptr<MegaTracker> createWithToken(std::string server, std::string apiToken, std::string appId);
    /// <summary>
    /// Updates API Token.
    /// </summary>
    void updateToken(std::string apiToken);
    /// <summary>
    /// Sets MEGA API Type. The default is Block.
    /// </summary>
    void setMegaApiType(MegaApiType type);
    /// <summary>
    /// Sets the spot version ID. Only available with `MegaApiType`_.Landmark .
    /// </summary>
    void setSpotVersionId(std::optional<std::string> spotVersionId);
    /// <summary>
    /// Switches remote end point.
    /// </summary>
    void switchEndPoint(std::string server, std::string apiKey, std::string apiSecret, std::string appId);
    /// <summary>
    /// Switches remote end point with API Token.
    /// </summary>
    void switchEndPointWithToken(std::string server, std::string apiToken, std::string appId);
    /// <summary>
    /// Binds to a specific block prior. An automatic unbind will be performed during reset or end point switching.
    /// </summary>
    void bindBlockPrior(std::shared_ptr<BlockPriorResult> blockPrior);
    /// <summary>
    /// Release bind to any block.
    /// </summary>
    void unbindBlockPrior();
    /// <summary>
    /// Sets request time parameters. timeoutMilliseconds is connection timeout. requestIntervalMilliseconds is the expected request interval, and the default value is 1000 and the minimum value is 300, with a longer value results a larger overall error.
    /// </summary>
    void setRequestTimeParameters(std::optional<int> timeoutMilliseconds, int requestIntervalMilliseconds);
    /// <summary>
    /// Sets whether to enable localzation. If disabled, localization result from server response will not be in the output. Defaults to true.
    /// </summary>
    void setEnableLocalization(bool enableLocalization);
    /// <summary>
    /// Sets whether to enable stateless localzation. If enabled, previous result will not be used in localization. Defaults to false.
    /// </summary>
    void setEnableStatelessLocalization(bool enableStatelessLocalization);
    /// <summary>
    /// Sets result async mode. Set true If results are to be outputted via outputFrameSource, false if results are to be fetched via getSyncResult. enableAsync defaults to true. Sync mode is only available with a XR license.
    /// </summary>
    bool setResultAsyncMode(bool enableAsync);
    void setRequestMessage(std::string message);
    /// <summary>
    /// Sets localization callback. On every localization, the callback will be triggered.
    /// </summary>
    void setLocalizationCallback(std::shared_ptr<CallbackScheduler> callbackScheduler, std::optional<std::function<void(std::shared_ptr<MegaTrackerLocalizationResponse>)>> callback);
    /// <summary>
    /// Sets the override value for camera position from map block. When set, MegaTracker will output override value instead of the position in input frame. This option can be utilized to improve output pose precision when there is known map info but limited sensor capability.
    /// </summary>
    void setCameraPositionOverride(std::optional<float> x, std::optional<float> y, std::optional<float> z);
    /// <summary>
    /// Start MegaTracker.
    /// </summary>
    bool start();
    /// <summary>
    /// Stop MegaTracker. Call start() to resume running.
    /// </summary>
    void stop();
    /// <summary>
    /// Reset MegaTracker and clear all internal states.
    /// </summary>
    void reset();
    /// <summary>
    /// Close MegaTracker. MegaTracker can no longer be used.
    /// </summary>
    void close();
    /// <summary>
    /// Get synchronized result. If MegaTracker is paused, or the result async mode is not set to false through setResultAsyncMode, the return value is empty.
    /// </summary>
    std::optional<std::shared_ptr<MegaTrackerResult>> getSyncResult(std::shared_ptr<MotionInputData> motionInputData);
};

class CloudRecognizationResult
{
protected:
    std::shared_ptr<easyar_CloudRecognizationResult> cdata_;
    void init_cdata(std::shared_ptr<easyar_CloudRecognizationResult> cdata);
    CloudRecognizationResult & operator=(const CloudRecognizationResult & data) = delete;
public:
    CloudRecognizationResult(std::shared_ptr<easyar_CloudRecognizationResult> cdata);
    virtual ~CloudRecognizationResult();

    std::shared_ptr<easyar_CloudRecognizationResult> get_cdata();
    static std::shared_ptr<CloudRecognizationResult> from_cdata(std::shared_ptr<easyar_CloudRecognizationResult> cdata);

    /// <summary>
    /// Returns recognition status.
    /// </summary>
    CloudRecognizationStatus getStatus();
    /// <summary>
    /// Returns the recognized target when status is FoundTarget.
    /// </summary>
    std::optional<std::shared_ptr<ImageTarget>> getTarget();
    /// <summary>
    /// Returns the error message when status is UnknownError.
    /// </summary>
    std::optional<std::string> getUnknownErrorMessage();
};

/// <summary>
/// CloudRecognizer implements cloud recognition. It can only be used after created a recognition image library on the cloud. Please refer to EasyAR CRS documentation.
/// When the component is not needed anymore, call close function to close it. It shall not be used after calling close.
/// Before using a CloudRecognizer, an `ImageTracker`_ must be setup and prepared. Any target returned from cloud should be manually put into the `ImageTracker`_ using `ImageTracker.loadTarget`_ if it need to be tracked. Then the target can be used as same as a local target after loaded into the tracker. When a target is recognized, you can get it from callback, and you should use target uid to distinguish different targets. The target runtimeID is dynamically created and cannot be used as unique identifier in the cloud situation.
/// </summary>
class CloudRecognizer
{
protected:
    std::shared_ptr<easyar_CloudRecognizer> cdata_;
    void init_cdata(std::shared_ptr<easyar_CloudRecognizer> cdata);
    CloudRecognizer & operator=(const CloudRecognizer & data) = delete;
public:
    CloudRecognizer(std::shared_ptr<easyar_CloudRecognizer> cdata);
    virtual ~CloudRecognizer();

    std::shared_ptr<easyar_CloudRecognizer> get_cdata();
    static std::shared_ptr<CloudRecognizer> from_cdata(std::shared_ptr<easyar_CloudRecognizer> cdata);

    /// <summary>
    /// Returns true.
    /// </summary>
    static bool isAvailable();
    /// <summary>
    /// Creates an instance and connects to the server.
    /// </summary>
    static std::shared_ptr<CloudRecognizer> create(std::string cloudRecognitionServiceServerAddress, std::string apiKey, std::string apiSecret, std::string cloudRecognitionServiceAppId);
    /// <summary>
    /// Creates an instance with API Token and connects to the server.
    /// </summary>
    static std::shared_ptr<CloudRecognizer> createWithToken(std::string cloudRecognitionServiceServerAddress, std::string apiToken, std::string cloudRecognitionServiceAppId);
    /// <summary>
    /// Creates an instance and connects to the server with Cloud Secret.
    /// </summary>
    static std::shared_ptr<CloudRecognizer> createByCloudSecret(std::string cloudRecognitionServiceServerAddress, std::string cloudRecognitionServiceSecret, std::string cloudRecognitionServiceAppId);
    /// <summary>
    /// Updates API Token.
    /// </summary>
    void updateToken(std::string apiToken);
    /// <summary>
    /// Send recognition request. The lowest available request interval is 300ms.
    /// </summary>
    void resolve(std::shared_ptr<InputFrame> inputFrame, std::optional<int> timeoutMilliseconds, std::shared_ptr<CallbackScheduler> callbackScheduler, std::function<void(std::shared_ptr<CloudRecognizationResult>)> callback);
    /// <summary>
    /// Stops the recognition and closes connection. The component shall not be used after calling close.
    /// </summary>
    void close();
};

/// <summary>
/// Buffer stores a raw byte array, which can be used to access image data.
/// To access image data in Java API, get buffer from `Image`_ and copy to a Java byte array.
/// You can always access image data since the first version of EasyAR Sense. Refer to `Image`_ .
/// </summary>
class Buffer
{
protected:
    std::shared_ptr<easyar_Buffer> cdata_;
    void init_cdata(std::shared_ptr<easyar_Buffer> cdata);
    Buffer & operator=(const Buffer & data) = delete;
public:
    Buffer(std::shared_ptr<easyar_Buffer> cdata);
    virtual ~Buffer();

    std::shared_ptr<easyar_Buffer> get_cdata();
    static std::shared_ptr<Buffer> from_cdata(std::shared_ptr<easyar_Buffer> cdata);

    /// <summary>
    /// Wraps a raw memory block. When Buffer is released by all holders, deleter callback will be invoked to execute user-defined memory destruction. deleter must be thread-safe.
    /// </summary>
    static std::shared_ptr<Buffer> wrap(void * ptr, int size, std::function<void()> deleter);
    /// <summary>
    /// Creates a Buffer of specified byte size.
    /// </summary>
    static std::shared_ptr<Buffer> create(int size);
    /// <summary>
    /// Returns raw data address.
    /// </summary>
    void * data();
    /// <summary>
    /// Byte size of raw data.
    /// </summary>
    int size();
    /// <summary>
    /// Copies raw memory. It can be used in languages or platforms without complete support for memory operations.
    /// </summary>
    static void memoryCopy(void * src, void * dest, int length);
    /// <summary>
    /// Tries to copy data from a raw memory address into Buffer. If copy succeeds, it returns true, or else it returns false. Possible failure causes includes: source or destination data range overflow.
    /// </summary>
    bool tryCopyFrom(void * src, int srcIndex, int index, int length);
    /// <summary>
    /// Tries to copy data from Buffer to user array. If copy succeeds, it returns true, or else it returns false. Possible failure causes includes: source or destination data range overflow.
    /// </summary>
    bool tryCopyTo(int index, void * dest, int destIndex, int length);
    /// <summary>
    /// Creates a sub-buffer with a reference to the original Buffer. A Buffer will only be released after all its sub-buffers are released.
    /// </summary>
    std::shared_ptr<Buffer> partition(int index, int length);
};

/// <summary>
/// A mapping from file path to `Buffer`_ . It can be used to represent multiple files in the memory.
/// </summary>
class BufferDictionary
{
protected:
    std::shared_ptr<easyar_BufferDictionary> cdata_;
    void init_cdata(std::shared_ptr<easyar_BufferDictionary> cdata);
    BufferDictionary & operator=(const BufferDictionary & data) = delete;
public:
    BufferDictionary(std::shared_ptr<easyar_BufferDictionary> cdata);
    virtual ~BufferDictionary();

    std::shared_ptr<easyar_BufferDictionary> get_cdata();
    static std::shared_ptr<BufferDictionary> from_cdata(std::shared_ptr<easyar_BufferDictionary> cdata);

    BufferDictionary();
    /// <summary>
    /// Current file count.
    /// </summary>
    int count();
    /// <summary>
    /// Checks if a specified path is in the dictionary.
    /// </summary>
    bool contains(std::string path);
    /// <summary>
    /// Tries to get the corresponding `Buffer`_ for a specified path.
    /// </summary>
    std::optional<std::shared_ptr<Buffer>> tryGet(std::string path);
    /// <summary>
    /// Sets `Buffer`_ for a specified path.
    /// </summary>
    void set(std::string path, std::shared_ptr<Buffer> buffer);
    /// <summary>
    /// Removes a specified path.
    /// </summary>
    bool remove(std::string path);
    /// <summary>
    /// Clears the dictionary.
    /// </summary>
    void clear();
};

/// <summary>
/// BufferPool is a memory pool to reduce memory allocation time consumption for functionality like custom camera interoperability, which needs to allocate memory buffers of a fixed size repeatedly.
/// </summary>
class BufferPool
{
protected:
    std::shared_ptr<easyar_BufferPool> cdata_;
    void init_cdata(std::shared_ptr<easyar_BufferPool> cdata);
    BufferPool & operator=(const BufferPool & data) = delete;
public:
    BufferPool(std::shared_ptr<easyar_BufferPool> cdata);
    virtual ~BufferPool();

    std::shared_ptr<easyar_BufferPool> get_cdata();
    static std::shared_ptr<BufferPool> from_cdata(std::shared_ptr<easyar_BufferPool> cdata);

    /// <summary>
    /// block_size is the byte size of each `Buffer`_ .
    /// capacity is the maximum count of `Buffer`_ .
    /// </summary>
    BufferPool(int block_size, int capacity);
    /// <summary>
    /// The byte size of each `Buffer`_ .
    /// </summary>
    int block_size();
    /// <summary>
    /// The maximum count of `Buffer`_ .
    /// </summary>
    int capacity();
    /// <summary>
    /// Current acquired count of `Buffer`_ .
    /// </summary>
    int size();
    /// <summary>
    /// Tries to acquire a memory block. If current acquired count of `Buffer`_ does not reach maximum, a new `Buffer`_ is fetched or allocated, or else null is returned.
    /// </summary>
    std::optional<std::shared_ptr<Buffer>> tryAcquire();
};

/// <summary>
/// Image stores an image data and represents an image in memory.
/// Image raw data can be accessed as byte array. The width/height/etc information are also accessible.
/// You can always access image data since the first version of EasyAR Sense.
///
/// You can do this in iOS
/// ::
///
///     #import &lt;easyar/buffer.oc.h&gt;
///     #import &lt;easyar/image.oc.h&gt;
///
///     easyar_OutputFrame * outputFrame = [outputFrameBuffer peek];
///     if (outputFrame != nil) {
///         easyar_Image * i = [[outputFrame inputFrame] image];
///         easyar_Buffer * b = [i buffer];
///         char * bytes = calloc([b size], 1);
///         memcpy(bytes, [b data], [b size]);
///         // use bytes here
///         free(bytes);
///     }
///
/// Or in Android
/// ::
///
///     import cn.easyar.*;
///
///     OutputFrame outputFrame = outputFrameBuffer.peek();
///     if (outputFrame != null) {
///         InputFrame inputFrame = outputFrame.inputFrame();
///         Image i = inputFrame.image();
///         Buffer b = i.buffer();
///         byte[] bytes = new byte[b.size()];
///         b.copyToByteArray(0, bytes, 0, bytes.length);
///         // use bytes here
///         b.dispose();
///         i.dispose();
///         inputFrame.dispose();
///         outputFrame.dispose();
///     }
/// </summary>
class Image
{
protected:
    std::shared_ptr<easyar_Image> cdata_;
    void init_cdata(std::shared_ptr<easyar_Image> cdata);
    Image & operator=(const Image & data) = delete;
public:
    Image(std::shared_ptr<easyar_Image> cdata);
    virtual ~Image();

    std::shared_ptr<easyar_Image> get_cdata();
    static std::shared_ptr<Image> from_cdata(std::shared_ptr<easyar_Image> cdata);

    Image(std::shared_ptr<Buffer> buffer, PixelFormat format, int width, int height);
    /// <summary>
    /// Returns buffer inside image. It can be used to access internal data of image. The content of `Buffer`_ shall not be modified, as they may be accessed from other threads.
    /// </summary>
    std::shared_ptr<Buffer> buffer();
    /// <summary>
    /// Returns image format.
    /// </summary>
    PixelFormat format();
    /// <summary>
    /// Returns image width. There is a padding of (pixelWidth - width) pixels at the right side of the image.
    /// </summary>
    int width();
    /// <summary>
    /// Returns image height. There is a padding of (pixelHeight - height) pixels at the bottom of the image.
    /// </summary>
    int height();
    /// <summary>
    /// Returns image pixel width for encoding.
    /// </summary>
    int pixelWidth();
    /// <summary>
    /// Returns image pixel height for encoding.
    /// </summary>
    int pixelHeight();
    static std::shared_ptr<Image> create(std::shared_ptr<Buffer> buffer, PixelFormat format, int width, int height, int pixelWidth, int pixelHeight);
};

/// <summary>
/// record
/// Square matrix of 4. The data arrangement is row-major.
/// </summary>
struct Matrix44F
{
    /// <summary>
    /// The raw data of matrix.
    /// </summary>
    std::array<float, 16> data;
};

/// <summary>
/// record
/// Square matrix of 3. The data arrangement is row-major.
/// </summary>
struct Matrix33F
{
    /// <summary>
    /// The raw data of matrix.
    /// </summary>
    std::array<float, 9> data;
};

/// <summary>
/// record
/// Accelerometer reading.
///
/// The positive direction of x-axis is from the device center to its right side of the screen.
/// The positive direction of y-axis is from the device center to its top side of the screen.
/// The positive direction of z-axis is from the device center perpendicular to the screen outward.
///
/// The unit of x, y, z is m/s^2.
/// The unit of timestamp is second.
/// </summary>
struct AccelerometerResult
{
    float x;
    float y;
    float z;
    double timestamp;
};

/// <summary>
/// record
/// Gyroscope reading.
///
/// The positive direction of x-axis is from the device center to its right side of the screen.
/// The positive direction of y-axis is from the device center to its top side of the screen.
/// The positive direction of z-axis is from the device center perpendicular to the screen outward.
///
/// The x, y, z values represent the angular speed around the corresponding axis in radians/second.
/// The rotation is positive in counter-clockwise, looking from the positive location on the axis at the device.
/// The unit of timestamp is second.
/// </summary>
struct GyroscopeResult
{
    float x;
    float y;
    float z;
    double timestamp;
};

/// <summary>
/// record
/// Attitude sensor reading.
///
/// The positive direction of x-axis is from the device center to its right side.
/// The positive direction of y-axis is from the device center to its top side.
/// The positive direction of z-axis is from the device center to its front.
///
/// The device is rotated trough an angle θ around an axis (x, y, z).
/// A unit quaternion can by obtained by (cos(θ/2), x*sin(θ/2), y*sin(θ/2), z*sin(θ/2)).
/// (v0, v1, v2, v3) = (cos(θ/2), x*sin(θ/2), y*sin(θ/2), z*sin(θ/2)).
///
/// The reference coordinate system is defined as a direct orthonormal basis, where:
///     Z points towards the sky and is perpendicular to the ground.
///     (X, Y, Z) is right-handed.
///
/// The unit of timestamp is second.
/// </summary>
struct AttitudeSensorResult
{
    float v0;
    float v1;
    float v2;
    float v3;
    double timestamp;
};

/// <summary>
/// record
/// Magnetometer reading.
///
/// The positive direction of x-axis is from the device center to its right side of the screen.
/// The positive direction of y-axis is from the device center to its top side of the screen.
/// The positive direction of z-axis is from the device center perpendicular to the screen outward.
///
/// The unit of x, y, z is uT(micro-Tesla).
/// The unit of timestamp is second.
/// </summary>
struct MagnetometerResult
{
    float x;
    float y;
    float z;
    double timestamp;
};

/// <summary>
/// record
/// Location reading.
///
/// The unit of latitude, longitude is meter.
/// The unit of altitude is meter.
/// The unit of horizontalAccuracy is meter.
/// verticalAccuracy is the accuracy in the direction of gravity of earth, and its unit is meter.
/// </summary>
struct LocationResult
{
    double latitude;
    double longitude;
    double altitude;
    double horizontalAccuracy;
    double verticalAccuracy;
    bool hasAltitude;
    bool hasHorizontalAccuracy;
    bool hasVerticalAccuracy;
};

/// <summary>
/// record
/// Proximity location reading.
///
/// The unit of x, y, z is meter. Origin is at map block origin. y is up.
/// The unit of accuracy is meter.
/// The unit of timestamp and validTime is second.
/// is2d is whether y is disabled.
/// </summary>
struct ProximityLocationResult
{
    float x;
    float y;
    float z;
    float accuracy;
    double timestamp;
    bool is2d;
    double validTime;
};

/// <summary>
/// Prior infos about the block maps.
///
/// blockIds are a list of the map id of block maps.
/// mode is to indicate in which way the system will utilize it, soft or hard. Refer to `BlockPriorMode`_.
/// </summary>
class BlockPriorResult
{
protected:
    std::shared_ptr<easyar_BlockPriorResult> cdata_;
    void init_cdata(std::shared_ptr<easyar_BlockPriorResult> cdata);
    BlockPriorResult & operator=(const BlockPriorResult & data) = delete;
public:
    BlockPriorResult(std::shared_ptr<easyar_BlockPriorResult> cdata);
    virtual ~BlockPriorResult();

    std::shared_ptr<easyar_BlockPriorResult> get_cdata();
    static std::shared_ptr<BlockPriorResult> from_cdata(std::shared_ptr<easyar_BlockPriorResult> cdata);

    std::vector<std::string> blockIds();
    std::string mode();
    static std::shared_ptr<BlockPriorResult> create(std::vector<std::string> blockIds, BlockPriorMode mode);
};

/// <summary>
/// record
/// 3 dimensional vector of double.
/// </summary>
struct Vec3D
{
    /// <summary>
    /// The raw data of vector.
    /// </summary>
    std::array<double, 3> data;
};

/// <summary>
/// record
/// 4 dimensional vector of float.
/// </summary>
struct Vec4F
{
    /// <summary>
    /// The raw data of vector.
    /// </summary>
    std::array<float, 4> data;
};

/// <summary>
/// record
/// 3 dimensional vector of float.
/// </summary>
struct Vec3F
{
    /// <summary>
    /// The raw data of vector.
    /// </summary>
    std::array<float, 3> data;
};

/// <summary>
/// record
/// 2 dimensional vector of float.
/// </summary>
struct Vec2F
{
    /// <summary>
    /// The raw data of vector.
    /// </summary>
    std::array<float, 2> data;
};

/// <summary>
/// record
/// 4 dimensional vector of int.
/// </summary>
struct Vec4I
{
    /// <summary>
    /// The raw data of vector.
    /// </summary>
    std::array<int, 4> data;
};

/// <summary>
/// record
/// 2 dimensional vector of int.
/// </summary>
struct Vec2I
{
    /// <summary>
    /// The raw data of vector.
    /// </summary>
    std::array<int, 2> data;
};

/// <summary>
/// DenseSpatialMap is used to reconstruct the environment accurately and densely. The reconstructed model is represented by `triangle mesh`, which is denoted simply by `mesh`.
/// DenseSpatialMap occupies 1 buffers of camera.
/// </summary>
class DenseSpatialMap
{
protected:
    std::shared_ptr<easyar_DenseSpatialMap> cdata_;
    void init_cdata(std::shared_ptr<easyar_DenseSpatialMap> cdata);
    DenseSpatialMap & operator=(const DenseSpatialMap & data) = delete;
public:
    DenseSpatialMap(std::shared_ptr<easyar_DenseSpatialMap> cdata);
    virtual ~DenseSpatialMap();

    std::shared_ptr<easyar_DenseSpatialMap> get_cdata();
    static std::shared_ptr<DenseSpatialMap> from_cdata(std::shared_ptr<easyar_DenseSpatialMap> cdata);

    /// <summary>
    /// Returns True when the device supports dense reconstruction, otherwise returns False.
    /// </summary>
    static bool isAvailable();
    /// <summary>
    /// Input port for input frame. For DenseSpatialMap to work, the inputFrame must include image and it&#39;s camera parameters and spatial information (cameraTransform and trackingStatus). See also `InputFrameSink`_ .
    /// Note: Both pinhole and fisheye camera are supported. But performance may decrease while using a fisheye camera.
    /// </summary>
    std::shared_ptr<InputFrameSink> inputFrameSink();
    /// <summary>
    /// Camera buffers occupied in this component.
    /// </summary>
    int bufferRequirement();
    /// <summary>
    /// Create `DenseSpatialMap`_ object.
    /// </summary>
    static std::shared_ptr<DenseSpatialMap> create();
    /// <summary>
    /// Start or continue runninng `DenseSpatialMap`_ algorithm.
    /// </summary>
    bool start();
    /// <summary>
    /// Pause the reconstruction algorithm. Call `start` to resume reconstruction.
    /// </summary>
    void stop();
    /// <summary>
    /// Close `DenseSpatialMap`_ algorithm.
    /// </summary>
    void close();
    /// <summary>
    /// Get the mesh management object of type `SceneMesh`_ . The contents will automatically update after calling the `DenseSpatialMap.updateSceneMesh`_ function.
    /// </summary>
    std::shared_ptr<SceneMesh> getMesh();
    /// <summary>
    /// Get the lastest updated mesh and save it to the `SceneMesh`_ object obtained by `DenseSpatialMap.getMesh`_ .
    /// The parameter `updateMeshAll` indicates whether to perform a `full update` or an `incremental update`. When `updateMeshAll` is True, `full update` is performed. All meshes are saved to `SceneMesh`_ . When `updateMeshAll` is False, `incremental update` is performed, and only the most recently updated mesh is saved to `SceneMesh`_ .
    /// `Full update` will take extra time and memory space, causing performance degradation.
    /// </summary>
    bool updateSceneMesh(bool updateMeshAll);
};

/// <summary>
/// record
/// The dense reconstructed model is represented by triangle mesh, or simply denoted as mesh. Because mesh updates frequently, in order to ensure efficiency, the mesh of the whole reconstruction model is divided into many mesh blocks. A mesh block is composed of a cube about 1 meter long, with attributes such as vertices and indices.
///
/// BlockInfo is used to describe the content of a mesh block. (x, y, z) is the index of mesh block, the coordinates of a mesh block&#39;s origin in world coordinate system can be obtained by  multiplying (x, y, z) by the physical size of mesh block. You may filter the part you want to display in advance by the mesh block&#39;s world coordinates for the sake of saving rendering time.
/// </summary>
struct BlockInfo
{
    /// <summary>
    /// x in index (x, y, z) of mesh block.
    /// </summary>
    int x;
    /// <summary>
    /// y in index (x, y, z) of mesh block.
    /// </summary>
    int y;
    /// <summary>
    /// z in index (x, y, z) of mesh block.
    /// </summary>
    int z;
    /// <summary>
    /// Number of vertices in a mesh block.
    /// </summary>
    int numOfVertex;
    /// <summary>
    /// startPointOfVertex is the starting position of the vertex data stored in the vertex buffer, indicating from where the stored vertices belong to current mesh block. It is not equal to the number of bytes of the offset from the beginning of vertex buffer. The offset is startPointOfVertex*3*4 bytes.
    /// </summary>
    int startPointOfVertex;
    /// <summary>
    /// The number of indices in a mesh block. Each of three consecutive vertices form a triangle.
    /// </summary>
    int numOfIndex;
    /// <summary>
    /// Similar to startPointOfVertex. startPointOfIndex is the starting position of the index data stored in the index buffer, indicating from where the stored indices belong to current mesh block. It is not equal to the number of bytes of the offset from the beginning of index buffer. The offset is startPointOfIndex*3*4 bytes.
    /// </summary>
    int startPointOfIndex;
    /// <summary>
    /// Version represents how many times the mesh block has updated. The larger the version, the newer the block. If the version of a mesh block increases after calling `DenseSpatialMap.updateSceneMesh`_ , it indicates that the mash block has changed.
    /// </summary>
    int version;
};

/// <summary>
/// SceneMesh is used to manage and preserve the results of `DenseSpatialMap`_.
/// There are two kinds of meshes saved in SceneMesh, one is the mesh of the whole reconstructed scene, hereinafter referred to as `meshAll`, the other is the recently updated mesh, hereinafter referred to as `meshUpdated`. `meshAll` is a whole mesh, including all vertex data and index data, etc. `meshUpdated` is composed of several `mesh block` s, each `mesh block` is a cube, which contains the mesh formed by the object surface in the corresponding cube space.
/// `meshAll` is available only when the `DenseSpatialMap.updateSceneMesh`_ method is called specifying that all meshes need to be updated. If `meshAll` has been updated previously and not updated in recent times, the data in `meshAll` is remain the same.
/// </summary>
class SceneMesh
{
protected:
    std::shared_ptr<easyar_SceneMesh> cdata_;
    void init_cdata(std::shared_ptr<easyar_SceneMesh> cdata);
    SceneMesh & operator=(const SceneMesh & data) = delete;
public:
    SceneMesh(std::shared_ptr<easyar_SceneMesh> cdata);
    virtual ~SceneMesh();

    std::shared_ptr<easyar_SceneMesh> get_cdata();
    static std::shared_ptr<SceneMesh> from_cdata(std::shared_ptr<easyar_SceneMesh> cdata);

    /// <summary>
    /// Get the number of vertices in `meshAll`.
    /// </summary>
    int getNumOfVertexAll();
    /// <summary>
    /// Get the number of indices in `meshAll`. Since every 3 indices form a triangle, the returned value should be a multiple of 3.
    /// </summary>
    int getNumOfIndexAll();
    /// <summary>
    /// Get the position component of the vertices in `meshAll` (in the world coordinate system). The position of a vertex is described by three coordinates (x, y, z) in meters. The position data are stored tightly in `Buffer`_ by `x1, y1, z1, x2, y2, z2, ...` Each component is of `float` type.
    /// </summary>
    std::shared_ptr<Buffer> getVerticesAll();
    /// <summary>
    /// Get the normal component of vertices in `meshAll`. The normal of a vertex is described by three components (nx, ny, nz). The normal is normalized, that is, the length is 1. Normal data are stored tightly in `Buffer`_ by `nx1, ny1, nz1, nx2, ny2, nz2,....` Each component is of `float` type.
    /// </summary>
    std::shared_ptr<Buffer> getNormalsAll();
    /// <summary>
    /// Get the index data in `meshAll`. Each triangle is composed of three indices (ix, iy, iz). Indices are stored tightly in `Buffer`_ by `ix1, iy1, iz1, ix2, iy2, iz2,...` Each component is of `int32` type.
    /// </summary>
    std::shared_ptr<Buffer> getIndicesAll();
    /// <summary>
    /// Get the number of vertices in `meshUpdated`.
    /// </summary>
    int getNumOfVertexIncremental();
    /// <summary>
    /// Get the number of indices in `meshUpdated`. Since every 3 indices form a triangle, the returned value should be a multiple of 3.
    /// </summary>
    int getNumOfIndexIncremental();
    /// <summary>
    /// Get the position component of the vertices in `meshUpdated` (in the world coordinate system). The position of a vertex is described by three coordinates (x, y, z) in meters. The position data are stored tightly in `Buffer`_ by `x1, y1, z1, x2, y2, z2, ...` Each component is of `float` type.
    /// </summary>
    std::shared_ptr<Buffer> getVerticesIncremental();
    /// <summary>
    /// Get the normal component of vertices in `meshUpdated`. The normal of a vertex is described by three components (nx, ny, nz). The normal is normalized, that is, the length is 1. Normal data are stored tightly in `Buffer`_ by `nx1, ny1, nz1, nx2, ny2, nz2,....` Each component is of `float` type.
    /// </summary>
    std::shared_ptr<Buffer> getNormalsIncremental();
    /// <summary>
    /// Get the index data in `meshUpdated`. Each triangle is composed of three indices (ix, iy, iz). Indices are stored tightly in `Buffer`_ by `ix1, iy1, iz1, ix2, iy2, iz2,...` Each component is of `int32` type.
    /// </summary>
    std::shared_ptr<Buffer> getIndicesIncremental();
    /// <summary>
    /// Gets the description object of `mesh block` in `meshUpdate`. The return value is an array of `BlockInfo`_ elements, each of which is a detailed description of a `mesh block`.
    /// </summary>
    std::vector<BlockInfo> getBlocksInfoIncremental();
    /// <summary>
    /// Get the edge length of a `mesh block` in meters.
    /// </summary>
    float getBlockDimensionInMeters();
};

/// <summary>
/// Accelerometer calls the accelerometer provided by the operating system, and outputs `AccelerometerResult`_ .
/// When it is not needed anymore, call close function to close it. It shall not be used after calling close.
/// It is not recommended to open multiple times simultaneously, which may cause failure on open or cause precision downgrade.
/// </summary>
class Accelerometer
{
protected:
    std::shared_ptr<easyar_Accelerometer> cdata_;
    void init_cdata(std::shared_ptr<easyar_Accelerometer> cdata);
    Accelerometer & operator=(const Accelerometer & data) = delete;
public:
    Accelerometer(std::shared_ptr<easyar_Accelerometer> cdata);
    virtual ~Accelerometer();

    std::shared_ptr<easyar_Accelerometer> get_cdata();
    static std::shared_ptr<Accelerometer> from_cdata(std::shared_ptr<easyar_Accelerometer> cdata);

    Accelerometer();
    /// <summary>
    /// Checks if the component is available. It returns true only on Android or iOS with supported hardware. On other operating systems, it is not supported.
    /// </summary>
    bool isAvailable();
    /// <summary>
    /// Output port.
    /// </summary>
    std::shared_ptr<AccelerometerResultSource> output();
    /// <summary>
    /// Opens the device. Sampling period is defined by implementation. If failed, it will return false.
    /// </summary>
    bool open();
    /// <summary>
    /// Opens the device with a specific sampling period. Sampling period is limited by hardware and may not reach the specified value. If failed, it will return false.
    /// </summary>
    bool openWithSamplingPeriod(int samplingPeriodMilliseconds);
    /// <summary>
    /// Closes. It shall not be used after calling close.
    /// </summary>
    void close();
    /// <summary>
    /// Gets the most recent result. If there is no result, it returns empty.
    /// </summary>
    std::optional<AccelerometerResult> getCurrentResult();
};

/// <summary>
/// ARCoreCameraDevice implements a camera device based on ARCore, which outputs `InputFrame`_  (including image, camera parameters, timestamp, 6DOF location, and tracking status).
/// Loading of libarcore_sdk_c.so with java.lang.System.loadLibrary is required.
/// After creation, start/stop can be invoked to start or stop video stream capture.
/// When the component is not needed anymore, call close function to close it. It shall not be used after calling close.
/// ARCoreCameraDevice outputs `InputFrame`_ from inputFrameSource. inputFrameSource shall be connected to `InputFrameSink`_ for use.
/// bufferCapacity is the capacity of `InputFrame`_ buffer. If the count of `InputFrame`_ which has been output from the device and have not been released is more than this number, the device will not output new `InputFrame`_ , until previous `InputFrame`_ have been released. This may cause screen stuck.
/// Caution: Currently, ARCore(v1.13.0) has memory leaks on creating and destroying sessions. Repeated creations and destructions will cause an increasing and non-reclaimable memory footprint.
/// </summary>
class ARCoreCameraDevice
{
protected:
    std::shared_ptr<easyar_ARCoreCameraDevice> cdata_;
    void init_cdata(std::shared_ptr<easyar_ARCoreCameraDevice> cdata);
    ARCoreCameraDevice & operator=(const ARCoreCameraDevice & data) = delete;
public:
    ARCoreCameraDevice(std::shared_ptr<easyar_ARCoreCameraDevice> cdata);
    virtual ~ARCoreCameraDevice();

    std::shared_ptr<easyar_ARCoreCameraDevice> get_cdata();
    static std::shared_ptr<ARCoreCameraDevice> from_cdata(std::shared_ptr<easyar_ARCoreCameraDevice> cdata);

    ARCoreCameraDevice();
    /// <summary>
    /// Checks if the component is available. It returns true only on Android when ARCore is installed.
    /// If called with libarcore_sdk_c.so not loaded, it returns false.
    /// Notice: If ARCore is not supported on the device but ARCore apk is installed via side-loading, it will return true, but ARCore will not function properly.
    /// </summary>
    static bool isAvailable();
    /// <summary>
    /// Checks if the current device is supported.
    /// </summary>
    static bool isDeviceSupported();
    /// <summary>
    /// `InputFrame`_ buffer capacity. The default is 8.
    /// </summary>
    int bufferCapacity();
    /// <summary>
    /// Sets `InputFrame`_ buffer capacity.
    /// </summary>
    void setBufferCapacity(int capacity);
    /// <summary>
    /// `InputFrame`_ output port.
    /// </summary>
    std::shared_ptr<InputFrameSource> inputFrameSource();
    /// <summary>
    /// Sets focus mode to focusMode.
    /// </summary>
    void setFocusMode(ARCoreCameraDeviceFocusMode focusMode);
    /// <summary>
    /// Starts video stream capture.
    /// </summary>
    bool start();
    /// <summary>
    /// Stops video stream capture.
    /// </summary>
    void stop();
    /// <summary>
    /// Close. The component shall not be used after calling close.
    /// </summary>
    void close();
    /// <summary>
    /// Camera type.
    /// </summary>
    CameraDeviceType type();
    /// <summary>
    /// Angles rotation required to rotate clockwise and display camera image on device with natural orientation.
    /// </summary>
    int cameraOrientation();
    /// <summary>
    /// Gets the current preview size.
    /// </summary>
    Vec2I size();
    /// <summary>
    /// Gets lower bound of current frame rate range.
    /// </summary>
    double frameRateRangeLower();
    /// <summary>
    /// Gets upper bound of current frame rate range.
    /// </summary>
    double frameRateRangeUpper();
};

/// <summary>
/// ARKitCameraDevice implements a camera device based on ARKit, which outputs `InputFrame`_ (including image, camera parameters, timestamp, 6DOF location, and tracking status).
/// After creation, start/stop can be invoked to start or stop data collection.
/// When the component is not needed anymore, call close function to close it. It shall not be used after calling close.
/// ARKitCameraDevice outputs `InputFrame`_ from inputFrameSource. inputFrameSource shall be connected to `InputFrameSink`_ for use.
/// bufferCapacity is the capacity of `InputFrame`_ buffer. If the count of `InputFrame`_ which has been output from the device and have not been released is more than this number, the device will not output new `InputFrame`_ , until previous `InputFrame`_ have been released. This may cause screen stuck.
/// </summary>
class ARKitCameraDevice
{
protected:
    std::shared_ptr<easyar_ARKitCameraDevice> cdata_;
    void init_cdata(std::shared_ptr<easyar_ARKitCameraDevice> cdata);
    ARKitCameraDevice & operator=(const ARKitCameraDevice & data) = delete;
public:
    ARKitCameraDevice(std::shared_ptr<easyar_ARKitCameraDevice> cdata);
    virtual ~ARKitCameraDevice();

    std::shared_ptr<easyar_ARKitCameraDevice> get_cdata();
    static std::shared_ptr<ARKitCameraDevice> from_cdata(std::shared_ptr<easyar_ARKitCameraDevice> cdata);

    ARKitCameraDevice();
    /// <summary>
    /// Checks if the component is available. It returns true only on iOS 11 or later when ARKit is supported by hardware.
    /// </summary>
    static bool isAvailable();
    /// <summary>
    /// `InputFrame`_ buffer capacity. The default is 8.
    /// </summary>
    int bufferCapacity();
    /// <summary>
    /// Sets `InputFrame`_ buffer capacity.
    /// </summary>
    void setBufferCapacity(int capacity);
    /// <summary>
    /// `InputFrame`_ output port.
    /// </summary>
    std::shared_ptr<InputFrameSource> inputFrameSource();
    /// <summary>
    /// Sets focus mode to focusMode. Call before start. Valid since iOS 11.3.
    /// </summary>
    void setFocusMode(ARKitCameraDeviceFocusMode focusMode);
    /// <summary>
    /// Starts video stream capture.
    /// </summary>
    bool start();
    /// <summary>
    /// Stops video stream capture.
    /// </summary>
    void stop();
    /// <summary>
    /// Close. The component shall not be used after calling close.
    /// </summary>
    void close();
    /// <summary>
    /// Camera type.
    /// </summary>
    CameraDeviceType type();
    /// <summary>
    /// Angles rotation required to rotate clockwise and display camera image on device with natural orientation.
    /// </summary>
    int cameraOrientation();
    /// <summary>
    /// Gets the current preview size.
    /// </summary>
    Vec2I size();
    /// <summary>
    /// Gets the current frame rate.
    /// </summary>
    double frameRate();
    /// <summary>
    /// Gets the number of supported preview sizes.
    /// </summary>
    int supportedSizeCount();
    /// <summary>
    /// Gets the index-th supported preview size. It returns {0, 0} if index is out of range.
    /// </summary>
    Vec2I supportedSize(int index);
    /// <summary>
    /// Sets the preview size. The available nearest value will be selected. Call size to get the actual size. frameRateRange may change after calling setSize.
    /// </summary>
    bool setSize(Vec2I size);
    /// <summary>
    /// Gets the number of supported frame rates.
    /// </summary>
    int supportedFrameRateCount();
    /// <summary>
    /// Gets the index-th supported frame rates
    /// </summary>
    double supportedFrameRate(int index);
    /// <summary>
    /// Sets frame rate.
    /// </summary>
    bool setFrameRate(double frameRate);
};

/// <summary>
/// AttitudeSensor calls the attitude sensor provided by the operating system, and outputs `AttitudeSensorResult`_ .
/// When it is not needed anymore, call close function to close it. It shall not be used after calling close.
/// It is not recommended to open multiple times simultaneously, which may cause failure on open or cause precision downgrade.
/// </summary>
class AttitudeSensor
{
protected:
    std::shared_ptr<easyar_AttitudeSensor> cdata_;
    void init_cdata(std::shared_ptr<easyar_AttitudeSensor> cdata);
    AttitudeSensor & operator=(const AttitudeSensor & data) = delete;
public:
    AttitudeSensor(std::shared_ptr<easyar_AttitudeSensor> cdata);
    virtual ~AttitudeSensor();

    std::shared_ptr<easyar_AttitudeSensor> get_cdata();
    static std::shared_ptr<AttitudeSensor> from_cdata(std::shared_ptr<easyar_AttitudeSensor> cdata);

    AttitudeSensor();
    /// <summary>
    /// Checks if the component is available. It returns true only on Android or iOS with supported hardware. On other operating systems, it is not supported.
    /// </summary>
    bool isAvailable();
    /// <summary>
    /// Output port.
    /// </summary>
    std::shared_ptr<AttitudeSensorResultSource> output();
    /// <summary>
    /// Opens the device. Sampling period is defined by implementation. If failed, it will return false.
    /// </summary>
    bool open();
    /// <summary>
    /// Opens the device with a specific sampling period. Sampling period is limited by hardware and may not reach the specified value. If failed, it will return false.
    /// </summary>
    bool openWithSamplingPeriod(int samplingPeriodMilliseconds);
    /// <summary>
    /// Closes. It shall not be used after calling close.
    /// </summary>
    void close();
    /// <summary>
    /// Gets the most recent result. If there is no result, it returns empty.
    /// </summary>
    std::optional<AttitudeSensorResult> getCurrentResult();
};

/// <summary>
/// CameraDevice implements a camera device, which outputs `InputFrame`_ (including image, camera paramters, and timestamp). It is available on Windows, Mac, Android and iOS.
/// After open, start/stop can be invoked to start or stop data collection. start/stop will not change previous set camera parameters.
/// When the component is not needed anymore, call close function to close it. It shall not be used after calling close.
/// CameraDevice outputs `InputFrame`_ from inputFrameSource. inputFrameSource shall be connected to `InputFrameSink`_ for use.
/// bufferCapacity is the capacity of `InputFrame`_ buffer. If the count of `InputFrame`_ which has been output from the device and have not been released is more than this number, the device will not output new `InputFrame`_ , until previous `InputFrame`_ have been released. This may cause screen stuck.
/// On Android, it is required to add android.permission.CAMERA to AndroidManifest.xml for use.
/// On iOS, it is required to add NSCameraUsageDescription to Info.plist for use.
/// </summary>
class CameraDevice
{
protected:
    std::shared_ptr<easyar_CameraDevice> cdata_;
    void init_cdata(std::shared_ptr<easyar_CameraDevice> cdata);
    CameraDevice & operator=(const CameraDevice & data) = delete;
public:
    CameraDevice(std::shared_ptr<easyar_CameraDevice> cdata);
    virtual ~CameraDevice();

    std::shared_ptr<easyar_CameraDevice> get_cdata();
    static std::shared_ptr<CameraDevice> from_cdata(std::shared_ptr<easyar_CameraDevice> cdata);

    CameraDevice();
    /// <summary>
    /// Checks if the component is available. It returns true only on Windows, Mac, Android or iOS.
    /// </summary>
    static bool isAvailable();
    /// <summary>
    /// Gets current camera API (camera1 or camera2) on Android. camera1 is better for compatibility, but lacks some necessary information such as timestamp. camera2 has compatibility issues on some devices.
    /// </summary>
    AndroidCameraApiType androidCameraApiType();
    /// <summary>
    /// Sets current camera API (camera1 or camera2) on Android. It must be called before calling openWithIndex, openWithSpecificType or openWithPreferredType, or it will not take effect.
    /// It is recommended to use `CameraDeviceSelector`_ to create camera with camera API set to recommended based on primary algorithm to run.
    /// </summary>
    void setAndroidCameraApiType(AndroidCameraApiType type);
    /// <summary>
    /// `InputFrame`_ buffer capacity. The default is 8.
    /// </summary>
    int bufferCapacity();
    /// <summary>
    /// Sets `InputFrame`_ buffer capacity.
    /// </summary>
    void setBufferCapacity(int capacity);
    /// <summary>
    /// `InputFrame`_ output port.
    /// </summary>
    std::shared_ptr<InputFrameSource> inputFrameSource();
    /// <summary>
    /// Sets callback on state change to notify state of camera disconnection or preemption. It is only available on Windows.
    /// </summary>
    void setStateChangedCallback(std::shared_ptr<CallbackScheduler> callbackScheduler, std::optional<std::function<void(CameraState)>> stateChangedCallback);
    /// <summary>
    /// Requests camera permission from operating system. You can call this function or request permission directly from operating system. It is only available on Android and iOS. On other platforms, it will call the callback directly with status being granted. This function need to be called from the UI thread.
    /// </summary>
    static void requestPermissions(std::shared_ptr<CallbackScheduler> callbackScheduler, std::optional<std::function<void(PermissionStatus, std::string)>> permissionCallback);
    /// <summary>
    /// Gets count of cameras recognized by the operating system.
    /// </summary>
    static int cameraCount();
    /// <summary>
    /// Opens a camera by index.
    /// </summary>
    bool openWithIndex(int cameraIndex);
    /// <summary>
    /// Opens a camera by specific camera device type. If no camera is matched, false will be returned. On Mac, camera device types can not be distinguished.
    /// </summary>
    bool openWithSpecificType(CameraDeviceType type);
    /// <summary>
    /// Opens a camera by camera device type. If no camera is matched, the first camera will be used.
    /// </summary>
    bool openWithPreferredType(CameraDeviceType type);
    /// <summary>
    /// Starts video stream capture.
    /// </summary>
    bool start();
    /// <summary>
    /// Stops video stream capture. It will only stop capture and will not change previous set camera parameters and connection.
    /// </summary>
    void stop();
    /// <summary>
    /// Close. The component shall not be used after calling close.
    /// </summary>
    void close();
    /// <summary>
    /// Camera index. Call after a successful open.
    /// </summary>
    int index();
    /// <summary>
    /// Camera type. Call after a successful open.
    /// </summary>
    CameraDeviceType type();
    /// <summary>
    /// Angles rotation required to rotate clockwise and display camera image on device with natural orientation. Call after a successful open.
    /// </summary>
    int cameraOrientation();
    /// <summary>
    /// Camera parameters, including image size, focal length, principal point, camera type and camera rotation against natural orientation. Call after a successful open.
    /// </summary>
    std::shared_ptr<CameraParameters> cameraParameters();
    /// <summary>
    /// Sets camera parameters. Call after a successful open.
    /// </summary>
    void setCameraParameters(std::shared_ptr<CameraParameters> cameraParameters);
    /// <summary>
    /// Gets the current preview size. Call after a successful open.
    /// </summary>
    Vec2I size();
    /// <summary>
    /// Gets the number of supported preview sizes. Call after a successful open.
    /// </summary>
    int supportedSizeCount();
    /// <summary>
    /// Gets the index-th supported preview size. It returns {0, 0} if index is out of range. Call after a successful open.
    /// </summary>
    Vec2I supportedSize(int index);
    /// <summary>
    /// Sets the preview size. The available nearest value will be selected. Call size to get the actual size. Call after a successful open. frameRateRange may change after calling setSize.
    /// </summary>
    bool setSize(Vec2I size);
    /// <summary>
    /// Gets the number of supported frame rate ranges. Call after a successful open.
    /// </summary>
    int supportedFrameRateRangeCount();
    /// <summary>
    /// Gets range lower bound of the index-th supported frame rate range. Call after a successful open.
    /// </summary>
    float supportedFrameRateRangeLower(int index);
    /// <summary>
    /// Gets range upper bound of the index-th supported frame rate range. Call after a successful open.
    /// </summary>
    float supportedFrameRateRangeUpper(int index);
    /// <summary>
    /// Gets current index of frame rate range. Call after a successful open. On iOS/macOS, this can return -1, meaning variable frame rate, which can be used to get lower and upper bounds with supportedFrameRateRangeLower and supportedFrameRateRangeUpper.
    /// </summary>
    int frameRateRange();
    /// <summary>
    /// Sets current index of frame rate range. Call after a successful open.
    /// </summary>
    bool setFrameRateRange(int index);
    /// <summary>
    /// Sets flash torch mode to on. Call after a successful open.
    /// </summary>
    bool setFlashTorchMode(bool on);
    /// <summary>
    /// Sets focus mode to focusMode. Call after a successful open.
    /// </summary>
    bool setFocusMode(CameraDeviceFocusMode focusMode);
    /// <summary>
    /// Does auto focus once. Call after start. It is only available when FocusMode is Normal or Macro.
    /// </summary>
    bool autoFocus();
};

/// <summary>
/// It is used for selecting camera API (camera1 or camera2) on Android. camera1 is better for compatibility, but lacks some necessary information such as timestamp. camera2 has compatibility issues on some devices.
/// Different preferences will choose camera1 or camera2 based on usage.
/// </summary>
class CameraDeviceSelector
{
public:
    /// <summary>
    /// Gets recommended Android Camera API type by a specified preference.
    /// </summary>
    static AndroidCameraApiType getAndroidCameraApiType(CameraDevicePreference preference);
    /// <summary>
    /// Creates `CameraDevice`_ by a specified preference.
    /// </summary>
    static std::shared_ptr<CameraDevice> createCameraDevice(CameraDevicePreference preference);
    /// <summary>
    /// Gets recommended Camera FocusMode type by a specified preference.
    /// </summary>
    static CameraDeviceFocusMode getFocusMode(CameraDevicePreference preference);
};

/// <summary>
/// Gyroscope calls the gyroscope provided by the operating system, and outputs `GyroscopeResult`_ .
/// When it is not needed anymore, call close function to close it. It shall not be used after calling close.
/// It is not recommended to open multiple times simultaneously, which may cause failure on open or cause precision downgrade.
/// </summary>
class Gyroscope
{
protected:
    std::shared_ptr<easyar_Gyroscope> cdata_;
    void init_cdata(std::shared_ptr<easyar_Gyroscope> cdata);
    Gyroscope & operator=(const Gyroscope & data) = delete;
public:
    Gyroscope(std::shared_ptr<easyar_Gyroscope> cdata);
    virtual ~Gyroscope();

    std::shared_ptr<easyar_Gyroscope> get_cdata();
    static std::shared_ptr<Gyroscope> from_cdata(std::shared_ptr<easyar_Gyroscope> cdata);

    Gyroscope();
    /// <summary>
    /// Checks if the component is available. It returns true only on Android or iOS with supported hardware. On other operating systems, it is not supported.
    /// </summary>
    bool isAvailable();
    /// <summary>
    /// Output port.
    /// </summary>
    std::shared_ptr<GyroscopeResultSource> output();
    /// <summary>
    /// Opens the device. Sampling period is defined by implementation. If failed, it will return false.
    /// </summary>
    bool open();
    /// <summary>
    /// Opens the device with a specific sampling period. Sampling period is limited by hardware and may not reach the specified value. If failed, it will return false.
    /// </summary>
    bool openWithSamplingPeriod(int samplingPeriodMilliseconds);
    /// <summary>
    /// Closes. It shall not be used after calling close.
    /// </summary>
    void close();
    /// <summary>
    /// Gets the most recent result. If there is no result, it returns empty.
    /// </summary>
    std::optional<GyroscopeResult> getCurrentResult();
};

/// <summary>
/// Magnetometer calls the magnetometer provided by the operating system, and outputs `MagnetometerResult`_ .
/// When it is not needed anymore, call close function to close it. It shall not be used after calling close.
/// It is not recommended to open multiple times simultaneously, which may cause failure on open or cause precision downgrade.
/// </summary>
class Magnetometer
{
protected:
    std::shared_ptr<easyar_Magnetometer> cdata_;
    void init_cdata(std::shared_ptr<easyar_Magnetometer> cdata);
    Magnetometer & operator=(const Magnetometer & data) = delete;
public:
    Magnetometer(std::shared_ptr<easyar_Magnetometer> cdata);
    virtual ~Magnetometer();

    std::shared_ptr<easyar_Magnetometer> get_cdata();
    static std::shared_ptr<Magnetometer> from_cdata(std::shared_ptr<easyar_Magnetometer> cdata);

    Magnetometer();
    /// <summary>
    /// Checks if the component is available. It returns true only on Android or iOS with supported hardware. On other operating systems, it is not supported.
    /// </summary>
    bool isAvailable();
    /// <summary>
    /// Output port.
    /// </summary>
    std::shared_ptr<MagnetometerResultSource> output();
    /// <summary>
    /// Opens the device. Sampling period is defined by implementation. If failed, it will return false.
    /// </summary>
    bool open();
    /// <summary>
    /// Opens the device with a specific sampling period. Sampling period is limited by hardware and may not reach the specified value. If failed, it will return false.
    /// </summary>
    bool openWithSamplingPeriod(int samplingPeriodMilliseconds);
    /// <summary>
    /// Closes. It shall not be used after calling close.
    /// </summary>
    void close();
    /// <summary>
    /// Gets the most recent result. If there is no result, it returns empty.
    /// </summary>
    std::optional<MagnetometerResult> getCurrentResult();
};

/// <summary>
/// ThreeDofCameraDevice implements a three dof camera device, which outputs `InputFrame`_ which `CameraTransformType`_ is ThreeDofRotOnly (including image, camera parameters, timestamp, camera transform matrix and tracking status).
/// After creation, start/stop can be invoked to start or stop video stream capture.
/// When the component is not needed anymore, call close function to close it. It shall not be used after calling close.
/// ThreeDofCameraDevice outputs `InputFrame`_ from inputFrameSource. inputFrameSource shall be connected to `InputFrameSink`_ for use.
/// bufferCapacity is the capacity of `InputFrame`_ buffer. If the count of `InputFrame`_ which has been output from the device and have not been released is more than this number, the device will not output new `InputFrame`_ , until previous `InputFrame`_ have been released. This may cause screen stuck.
/// </summary>
class ThreeDofCameraDevice
{
protected:
    std::shared_ptr<easyar_ThreeDofCameraDevice> cdata_;
    void init_cdata(std::shared_ptr<easyar_ThreeDofCameraDevice> cdata);
    ThreeDofCameraDevice & operator=(const ThreeDofCameraDevice & data) = delete;
public:
    ThreeDofCameraDevice(std::shared_ptr<easyar_ThreeDofCameraDevice> cdata);
    virtual ~ThreeDofCameraDevice();

    std::shared_ptr<easyar_ThreeDofCameraDevice> get_cdata();
    static std::shared_ptr<ThreeDofCameraDevice> from_cdata(std::shared_ptr<easyar_ThreeDofCameraDevice> cdata);

    /// <summary>
    /// Default create method.
    /// </summary>
    ThreeDofCameraDevice();
    /// <summary>
    /// Checks if the component is available. It returns true only on Android or IOS when the gyroscope is available.
    /// </summary>
    static bool isAvailable();
    /// <summary>
    /// `InputFrame`_ buffer capacity. The default is 8.
    /// </summary>
    int bufferCapacity();
    /// <summary>
    /// Sets `InputFrame`_ buffer capacity.
    /// </summary>
    void setBufferCapacity(int capacity);
    /// <summary>
    /// `InputFrame`_ output port.
    /// </summary>
    std::shared_ptr<InputFrameSource> inputFrameSource();
    /// <summary>
    /// Sets focus mode to focusMode. Call before start.
    /// </summary>
    void setFocusMode(ThreeDofCameraDeviceFocusMode focusMode);
    /// <summary>
    /// Camera type. Call after a successful open.
    /// </summary>
    CameraDeviceType type();
    /// <summary>
    /// Angles rotation required to rotate clockwise and display camera image on device with natural orientation. Call after a successful open.
    /// </summary>
    int cameraOrientation();
    /// <summary>
    /// Gets the current preview size. Call after a successful open.
    /// </summary>
    Vec2I size();
    /// <summary>
    /// Gets the number of supported preview sizes. Call after a successful open.
    /// </summary>
    int supportedSizeCount();
    /// <summary>
    /// Gets the index-th supported preview size. It returns {0, 0} if index is out of range. Call after a successful open.
    /// </summary>
    Vec2I supportedSize(int index);
    /// <summary>
    /// Sets the preview size. The available nearest value will be selected. Call size to get the actual size. Call after a successful open. frameRateRange may change after calling setSize.
    /// </summary>
    bool setSize(Vec2I size);
    /// <summary>
    /// Opens back camera of device. If the opening fails will return false.
    /// </summary>
    bool open();
    /// <summary>
    /// Starts video stream capture.
    /// </summary>
    bool start();
    /// <summary>
    /// Stops video stream capture.
    /// </summary>
    void stop();
    /// <summary>
    /// Close. The component shall not be used after calling close.
    /// </summary>
    void close();
    /// <summary>
    /// Gets lower bound of current frame rate range. Call after a successful open.
    /// </summary>
    double frameRateRangeLower();
    /// <summary>
    /// Gets upper bound of current frame rate range. Call after a successful open.
    /// </summary>
    double frameRateRangeUpper();
};

/// <summary>
/// VisionOSARKitCameraDevice implements a camera device based on VisionOS ARKit, which outputs `InputFrame`_ (including image, camera parameters, timestamp, 6DOF location, and tracking status).
/// After creation, start/stop can be invoked to start or stop data collection.
/// When the component is not needed anymore, call close function to close it. It shall not be used after calling close.
/// VisionOSARKitCameraDevice outputs `InputFrame`_ from inputFrameSource. inputFrameSource shall be connected to `InputFrameSink`_ for use.
/// bufferCapacity is the capacity of `InputFrame`_ buffer. If the count of `InputFrame`_ which has been output from the device and have not been released is more than this number, the device will not output new `InputFrame`_ , until previous `InputFrame`_ have been released. This may cause screen stuck.
/// </summary>
class VisionOSARKitCameraDevice
{
protected:
    std::shared_ptr<easyar_VisionOSARKitCameraDevice> cdata_;
    void init_cdata(std::shared_ptr<easyar_VisionOSARKitCameraDevice> cdata);
    VisionOSARKitCameraDevice & operator=(const VisionOSARKitCameraDevice & data) = delete;
public:
    VisionOSARKitCameraDevice(std::shared_ptr<easyar_VisionOSARKitCameraDevice> cdata);
    virtual ~VisionOSARKitCameraDevice();

    std::shared_ptr<easyar_VisionOSARKitCameraDevice> get_cdata();
    static std::shared_ptr<VisionOSARKitCameraDevice> from_cdata(std::shared_ptr<easyar_VisionOSARKitCameraDevice> cdata);

    VisionOSARKitCameraDevice();
    static bool isAvailable();
    /// <summary>
    /// `InputFrame`_ buffer capacity. The default is 8.
    /// </summary>
    int bufferCapacity();
    /// <summary>
    /// Sets `InputFrame`_ buffer capacity.
    /// </summary>
    void setBufferCapacity(int capacity);
    /// <summary>
    /// Requests necessary permissions from VisionOS including [World Sensing] and [Camera Access]
    /// </summary>
    void requestPermissions(std::shared_ptr<CallbackScheduler> callbackScheduler, std::optional<std::function<void(PermissionStatus, std::string)>> permissionCallback);
    /// <summary>
    /// `InputFrame`_ output port.
    /// </summary>
    std::shared_ptr<InputFrameSource> inputFrameSource();
    /// <summary>
    /// Get synchoronous motion input data.
    /// </summary>
    std::optional<std::shared_ptr<MotionInputData>> getMotionInputData();
    /// <summary>
    /// Starts video stream capture.
    /// </summary>
    bool start();
    /// <summary>
    /// Stops video stream capture.
    /// </summary>
    void stop();
    /// <summary>
    /// Close. The component shall not be used after calling close.
    /// </summary>
    void close();
    /// <summary>
    /// Gets the current preview size.
    /// </summary>
    Vec2I size();
    /// <summary>
    /// Camera type.
    /// </summary>
    CameraDeviceType type();
    /// <summary>
    /// Angles rotation required to rotate clockwise and display camera image on device with natural orientation.
    /// </summary>
    int cameraOrientation();
    /// <summary>
    /// Gets lower bound of current frame rate range.
    /// </summary>
    double frameRateRangeLower();
    /// <summary>
    /// Gets upper bound of current frame rate range.
    /// </summary>
    double frameRateRangeUpper();
};

/// <summary>
/// XREALCameraDevice implements a camera device based on XREAL Enterprise Native SDK Plugin, which outputs `InputFrame`_ (image, camera parameters, timestamp, 6DOF location, and tracking status cannot be accessed).
/// After creation, start/stop can be invoked to start or stop data collection. Start must not be called before isDeviceSupported returns true.
/// When the component is not needed anymore, call close function to close it. It shall not be used after calling close.
/// XREALCameraDevice outputs `InputFrame`_ from inputFrameSource. inputFrameSource shall be connected to `InputFrameSink`_ for use.
/// bufferCapacity is the capacity of `InputFrame`_ buffer. If the count of `InputFrame`_ which has been output from the device and have not been released is more than this number, the device will not output new `InputFrame`_ , until previous `InputFrame`_ have been released. This may cause screen stuck.
/// </summary>
class XREALCameraDevice
{
protected:
    std::shared_ptr<easyar_XREALCameraDevice> cdata_;
    void init_cdata(std::shared_ptr<easyar_XREALCameraDevice> cdata);
    XREALCameraDevice & operator=(const XREALCameraDevice & data) = delete;
public:
    XREALCameraDevice(std::shared_ptr<easyar_XREALCameraDevice> cdata);
    virtual ~XREALCameraDevice();

    std::shared_ptr<easyar_XREALCameraDevice> get_cdata();
    static std::shared_ptr<XREALCameraDevice> from_cdata(std::shared_ptr<easyar_XREALCameraDevice> cdata);

    XREALCameraDevice();
    /// <summary>
    /// Checks if the component is available. It returns true only when XREAL eyewear is connected on the device supported.
    /// </summary>
    static bool isAvailable();
    /// <summary>
    /// Checks if the eyewear is supported. Has value only after XREAL finishes initialization on devices where isAvailable is ture.
    /// </summary>
    static std::optional<bool> isDeviceSupported();
    /// <summary>
    /// `InputFrame`_ buffer capacity. The default is 8.
    /// </summary>
    int bufferCapacity();
    /// <summary>
    /// Sets `InputFrame`_ buffer capacity.
    /// </summary>
    void setBufferCapacity(int capacity);
    /// <summary>
    /// `InputFrame`_ output port.
    /// </summary>
    std::shared_ptr<InputFrameSource> inputFrameSource();
    /// <summary>
    /// Get synchoronous motion input data. Call after isDeviceSupported return true.
    /// </summary>
    std::optional<std::shared_ptr<MotionInputData>> getMotionInputData();
    /// <summary>
    /// Received frame count from camera. It should continously increase after start, otherwise the device connection may not be stable or XREAL service/SDK not working correctly, and you need to get help from XREAL directly.
    /// </summary>
    int receivedFrameCount();
    /// <summary>
    /// Opens camera. Call after isDeviceSupported return true. XREAL license must be validated through XREAL official method on Air2 Ultra and some other devices before open.
    /// </summary>
    bool open();
    /// <summary>
    /// Starts video stream capture.
    /// </summary>
    bool start();
    /// <summary>
    /// Stops video stream capture.
    /// </summary>
    void stop();
    /// <summary>
    /// Close. The component shall not be used after calling close.
    /// </summary>
    void close();
    /// <summary>
    /// Camera type. Call after a successful open.
    /// </summary>
    CameraDeviceType type();
    /// <summary>
    /// Angles rotation required to rotate clockwise and display camera image on device with natural orientation. Call after a successful open.
    /// </summary>
    int cameraOrientation();
    /// <summary>
    /// Gets the current preview size. Call after a successful open.
    /// </summary>
    Vec2I size();
    /// <summary>
    /// Gets the current frame rate. Call after a successful open.
    /// </summary>
    double frameRate();
};

/// <summary>
/// Result of `SurfaceTracker`_ .
/// </summary>
class SurfaceTrackerResult : public FrameFilterResult
{
protected:
    std::shared_ptr<easyar_SurfaceTrackerResult> cdata_;
    void init_cdata(std::shared_ptr<easyar_SurfaceTrackerResult> cdata);
    SurfaceTrackerResult & operator=(const SurfaceTrackerResult & data) = delete;
public:
    SurfaceTrackerResult(std::shared_ptr<easyar_SurfaceTrackerResult> cdata);
    virtual ~SurfaceTrackerResult();

    std::shared_ptr<easyar_SurfaceTrackerResult> get_cdata();
    static std::shared_ptr<SurfaceTrackerResult> from_cdata(std::shared_ptr<easyar_SurfaceTrackerResult> cdata);

    /// <summary>
    /// Camera transform against world coordinate system. Camera coordinate system and world coordinate system are all right-handed. For the camera coordinate system, the origin is the optical center, x-right, y-up, and z in the direction of light going into camera. (The right and up, on mobile devices, is the right and up when the device is in the natural orientation.) For the world coordinate system, y is up (to the opposite of gravity). The data arrangement is row-major, not like OpenGL&#39;s column-major.
    /// </summary>
    Matrix44F transform();
};

/// <summary>
/// SurfaceTracker implements tracking with environmental surfaces.
/// SurfaceTracker occupies one buffer of camera. Use setBufferCapacity of camera to set an amount of buffers that is not less than the sum of amount of buffers occupied by all components.
/// After creation, you can call start/stop to enable/disable the track process. start and stop are very lightweight calls.
/// When the component is not needed anymore, call close function to close it. It shall not be used after calling close.
/// SurfaceTracker inputs `InputFrame`_ from inputFrameSink. `InputFrameSource`_ shall be connected to inputFrameSink for use.
/// </summary>
class SurfaceTracker
{
protected:
    std::shared_ptr<easyar_SurfaceTracker> cdata_;
    void init_cdata(std::shared_ptr<easyar_SurfaceTracker> cdata);
    SurfaceTracker & operator=(const SurfaceTracker & data) = delete;
public:
    SurfaceTracker(std::shared_ptr<easyar_SurfaceTracker> cdata);
    virtual ~SurfaceTracker();

    std::shared_ptr<easyar_SurfaceTracker> get_cdata();
    static std::shared_ptr<SurfaceTracker> from_cdata(std::shared_ptr<easyar_SurfaceTracker> cdata);

    /// <summary>
    /// Returns true only on Android or iOS when accelerometer and gyroscope are available.
    /// </summary>
    static bool isAvailable();
    /// <summary>
    /// `InputFrame`_ input port. InputFrame must have raw image, timestamp, and camera parameters.
    /// Note: fisheye camera model is NOT supported.
    /// </summary>
    std::shared_ptr<InputFrameSink> inputFrameSink();
    /// <summary>
    /// Camera buffers occupied in this component.
    /// </summary>
    int bufferRequirement();
    /// <summary>
    /// `OutputFrame`_ output port.
    /// </summary>
    std::shared_ptr<OutputFrameSource> outputFrameSource();
    /// <summary>
    /// Creates an instance.
    /// </summary>
    static std::shared_ptr<SurfaceTracker> create();
    /// <summary>
    /// Starts the track algorithm.
    /// </summary>
    bool start();
    /// <summary>
    /// Stops the track algorithm. Call start to start the track again.
    /// </summary>
    void stop();
    /// <summary>
    /// Close. The component shall not be used after calling close.
    /// </summary>
    void close();
    /// <summary>
    /// Sets the tracking target to a point on camera image. For the camera image coordinate system ([0, 1]^2), x-right, y-down, and origin is at left-top corner. `CameraParameters.imageCoordinatesFromScreenCoordinates`_ can be used to convert points from screen coordinate system to camera image coordinate system.
    /// </summary>
    void alignTargetToCameraImagePoint(Vec2F cameraImagePoint);
};

/// <summary>
/// Event dump recorder.
/// It can be used to record some crucial diagnostic information into an EED file.
/// All members of this class is thread-safe.
/// </summary>
class EventDumpRecorder
{
protected:
    std::shared_ptr<easyar_EventDumpRecorder> cdata_;
    void init_cdata(std::shared_ptr<easyar_EventDumpRecorder> cdata);
    EventDumpRecorder & operator=(const EventDumpRecorder & data) = delete;
public:
    EventDumpRecorder(std::shared_ptr<easyar_EventDumpRecorder> cdata);
    virtual ~EventDumpRecorder();

    std::shared_ptr<easyar_EventDumpRecorder> get_cdata();
    static std::shared_ptr<EventDumpRecorder> from_cdata(std::shared_ptr<easyar_EventDumpRecorder> cdata);

    /// <summary>
    /// Creates an instance.
    /// </summary>
    static std::shared_ptr<EventDumpRecorder> create();
    /// <summary>
    /// Starts recording.
    /// </summary>
    bool start(std::string filePath, int initalScreenRotation);
    /// <summary>
    /// Stops recording.
    /// </summary>
    void stop();
};

/// <summary>
/// MotionTrackerCameraDevice implements a camera device with metric-scale six degree-of-freedom motion tracking, which outputs `InputFrame`_  (including image, camera parameters, timestamp, 6DOF pose and tracking status).
/// After creation, start/stop can be invoked to start or stop data flow.
/// When the component is not needed anymore, call close function to close it. It shall not be used after calling close.
/// MotionTrackerCameraDevice outputs `InputFrame`_ from inputFrameSource. inputFrameSource shall be connected to `InputFrameSink`_ for further use.
/// </summary>
class MotionTrackerCameraDevice
{
protected:
    std::shared_ptr<easyar_MotionTrackerCameraDevice> cdata_;
    void init_cdata(std::shared_ptr<easyar_MotionTrackerCameraDevice> cdata);
    MotionTrackerCameraDevice & operator=(const MotionTrackerCameraDevice & data) = delete;
public:
    MotionTrackerCameraDevice(std::shared_ptr<easyar_MotionTrackerCameraDevice> cdata);
    virtual ~MotionTrackerCameraDevice();

    std::shared_ptr<easyar_MotionTrackerCameraDevice> get_cdata();
    static std::shared_ptr<MotionTrackerCameraDevice> from_cdata(std::shared_ptr<easyar_MotionTrackerCameraDevice> cdata);

    /// <summary>
    /// Create MotionTrackerCameraDevice object.
    /// </summary>
    MotionTrackerCameraDevice();
    /// <summary>
    /// Check if the devices supports motion tracking. It returns True if the device supports Motion Tracking, otherwise it returns False.
    /// </summary>
    static bool isAvailable();
    /// <summary>
    /// Get the quality of Motion Tracking on the device. You can decide whether to start Motion Tracking.
    /// </summary>
    static MotionTrackerCameraDeviceQualityLevel getQualityLevel();
    /// <summary>
    /// Sets current frame rate. Call before start. If this function is not called, the default is 30 fps.
    /// </summary>
    bool setFrameRateType(MotionTrackerCameraDeviceFPS fps);
    /// <summary>
    /// Sets focus mode. Call before start. If this function is not called, the default is Continousauto.
    /// </summary>
    bool setFocusMode(MotionTrackerCameraDeviceFocusMode focusMode);
    /// <summary>
    /// Sets frame resolution. Call before start. If this function is not called, the default is 1280 x 960 or 1280 x 720.
    /// </summary>
    bool setFrameResolutionType(MotionTrackerCameraDeviceResolution resolution);
    /// <summary>
    /// Sets tracking mode. Call before start. If this function is not called, the default is Anchor.
    /// </summary>
    bool setTrackingMode(MotionTrackerCameraDeviceTrackingMode trackingMode);
    /// <summary>
    /// Set `InputFrame`_ buffer capacity.
    /// bufferCapacity is the capacity of `InputFrame`_ buffer. If the count of `InputFrame`_ which has been output from the device and have not been released is higher than this number, the device will not output new `InputFrame`_ until previous `InputFrame`_ has been released. This may cause screen stuck.
    /// </summary>
    void setBufferCapacity(int capacity);
    /// <summary>
    /// Get `InputFrame`_ buffer capacity. The default is 8.
    /// </summary>
    int bufferCapacity();
    /// <summary>
    /// `InputFrame`_ output port.
    /// </summary>
    std::shared_ptr<InputFrameSource> inputFrameSource();
    /// <summary>
    /// Start motion tracking or resume motion tracking after pause.
    /// Notice: Calling start after pausing will trigger device relocalization. Tracking will resume when the relocalization process succeeds.
    /// </summary>
    bool start();
    /// <summary>
    /// Pause motion tracking. Call `start` to trigger relocation, resume motion tracking if the relocation succeeds.
    /// </summary>
    void stop();
    /// <summary>
    /// Close motion tracking. The component shall not be used after calling close.
    /// </summary>
    void close();
    /// <summary>
    /// Camera type. Call after a successful start.
    /// </summary>
    CameraDeviceType type();
    /// <summary>
    /// Angles rotation required to rotate clockwise and display camera image on device with natural orientation. Call after a successful start.
    /// </summary>
    int cameraOrientation();
    /// <summary>
    /// Gets the current preview size. Call after a successful start.
    /// </summary>
    Vec2I size();
    /// <summary>
    /// Gets lower bound of current frame rate range. Call after a successful open.
    /// </summary>
    double frameRateRangeLower();
    /// <summary>
    /// Gets upper bound of current frame rate range. Call after a successful open.
    /// </summary>
    double frameRateRangeUpper();
    /// <summary>
    /// Perform hit test against the point cloud and return the nearest 3D point. The 3D point is represented by three consecutive values, representing X, Y, Z position coordinates in the world coordinate space.
    /// For the camera image coordinate system ([0, 1]^2), x-right, y-down, and origin is at left-top corner. `CameraParameters.imageCoordinatesFromScreenCoordinates`_ can be used to convert points from screen coordinate system to camera image coordinate system.
    /// </summary>
    std::vector<Vec3F> hitTestAgainstPointCloud(Vec2F cameraImagePoint);
    /// <summary>
    /// Performs ray cast from the user&#39;s device in the direction of given screen point.
    /// Intersections with horizontal plane is detected in real time in the current field of view,and return the 3D point nearest to ray on horizontal plane.
    /// For the camera image coordinate system ([0, 1]^2), x-right, y-down, and origin is at left-top corner. `CameraParameters.imageCoordinatesFromScreenCoordinates`_ can be used to convert points from screen coordinate system to camera image coordinate system.
    /// The output point cloud coordinate on Horizontal plane is in the world coordinate system. The 3D point is represented by three consecutive values, representing X, Y, Z position coordinates in the world coordinate space.
    /// </summary>
    std::vector<Vec3F> hitTestAgainstHorizontalPlane(Vec2F cameraImagePoint);
    /// <summary>
    /// Returns the vector of point cloud coordinate. Each 3D point is represented by three consecutive values, representing X, Y, Z position coordinates in the world coordinate space.
    /// </summary>
    std::vector<Vec3F> getLocalPointsCloud();
};

/// <summary>
/// Input frame recorder.
/// There is an input frame input port and an input frame output port. It can be used to record input frames into an EIF file.
/// All members of this class is thread-safe.
/// </summary>
class InputFrameRecorder
{
protected:
    std::shared_ptr<easyar_InputFrameRecorder> cdata_;
    void init_cdata(std::shared_ptr<easyar_InputFrameRecorder> cdata);
    InputFrameRecorder & operator=(const InputFrameRecorder & data) = delete;
public:
    InputFrameRecorder(std::shared_ptr<easyar_InputFrameRecorder> cdata);
    virtual ~InputFrameRecorder();

    std::shared_ptr<easyar_InputFrameRecorder> get_cdata();
    static std::shared_ptr<InputFrameRecorder> from_cdata(std::shared_ptr<easyar_InputFrameRecorder> cdata);

    /// <summary>
    /// Input port.
    /// </summary>
    std::shared_ptr<InputFrameSink> input();
    /// <summary>
    /// Camera buffers occupied in this component.
    /// </summary>
    int bufferRequirement();
    /// <summary>
    /// Output port.
    /// </summary>
    std::shared_ptr<InputFrameSource> output();
    /// <summary>
    /// Creates an instance.
    /// </summary>
    static std::shared_ptr<InputFrameRecorder> create();
    /// <summary>
    /// Starts frame recording. initialScreenRotation is the initial screen rotation when recording data, and it will be used in rendering for playback. The definition of screen rotation is the same as in `CameraParameters`_ .
    /// </summary>
    bool start(std::string filePath, int initialScreenRotation);
    /// <summary>
    /// Stops frame recording. It will only stop recording and will not affect connection.
    /// </summary>
    void stop();
};

/// <summary>
/// Input frame player.
/// There is an input frame output port. It can be used to get input frame from an EIF file.
/// All members of this class is thread-safe.
/// </summary>
class InputFramePlayer
{
protected:
    std::shared_ptr<easyar_InputFramePlayer> cdata_;
    void init_cdata(std::shared_ptr<easyar_InputFramePlayer> cdata);
    InputFramePlayer & operator=(const InputFramePlayer & data) = delete;
public:
    InputFramePlayer(std::shared_ptr<easyar_InputFramePlayer> cdata);
    virtual ~InputFramePlayer();

    std::shared_ptr<easyar_InputFramePlayer> get_cdata();
    static std::shared_ptr<InputFramePlayer> from_cdata(std::shared_ptr<easyar_InputFramePlayer> cdata);

    /// <summary>
    /// Output port.
    /// </summary>
    std::shared_ptr<InputFrameSource> output();
    /// <summary>
    /// Creates an instance.
    /// </summary>
    static std::shared_ptr<InputFramePlayer> create();
    /// <summary>
    /// Starts frame play.
    /// </summary>
    bool start(std::string filePath);
    /// <summary>
    /// Stops frame play.
    /// </summary>
    void stop();
    /// <summary>
    /// Pauses frame play.
    /// </summary>
    void pause();
    /// <summary>
    /// Resumes frame play.
    /// </summary>
    bool resume();
    /// <summary>
    /// Total expected playback time span. The unit is second.
    /// </summary>
    double totalTime();
    /// <summary>
    /// Current playback time point. The unit is second. The initial value is 0.
    /// </summary>
    double currentTime();
    /// <summary>
    /// The initial screen rotation when recording data.
    /// </summary>
    int initalScreenRotation();
    /// <summary>
    /// Whether the playback is completed.
    /// </summary>
    bool isCompleted();
};

/// <summary>
/// Input frame recorder.
/// There is an input frame input port and an input frame output port. It can be used to record input frames into an EIF MKV file.
/// All members of this class is thread-safe.
/// </summary>
class VideoInputFrameRecorder
{
protected:
    std::shared_ptr<easyar_VideoInputFrameRecorder> cdata_;
    void init_cdata(std::shared_ptr<easyar_VideoInputFrameRecorder> cdata);
    VideoInputFrameRecorder & operator=(const VideoInputFrameRecorder & data) = delete;
public:
    VideoInputFrameRecorder(std::shared_ptr<easyar_VideoInputFrameRecorder> cdata);
    virtual ~VideoInputFrameRecorder();

    std::shared_ptr<easyar_VideoInputFrameRecorder> get_cdata();
    static std::shared_ptr<VideoInputFrameRecorder> from_cdata(std::shared_ptr<easyar_VideoInputFrameRecorder> cdata);

    /// <summary>
    /// Checks if the component is available. It returns true only on MacOS, iOS and Android.
    /// </summary>
    static bool isAvailable();
    /// <summary>
    /// Input port.
    /// </summary>
    std::shared_ptr<InputFrameSink> input();
    /// <summary>
    /// Optional. Input port for accelerometer result. See also `AccelerometerResultSink`_ .
    /// </summary>
    std::shared_ptr<AccelerometerResultSink> accelerometerResultSink();
    /// <summary>
    /// Optional. Input port for gyroscope result. See also `GyroscopeResultSink`_ .
    /// </summary>
    std::shared_ptr<GyroscopeResultSink> gyroscopeResultSink();
    /// <summary>
    /// Optional. Input port for attitude sensor. See also `AttitudeSensorResultSink`_ .
    /// </summary>
    std::shared_ptr<AttitudeSensorResultSink> attitudeSensorResultSink();
    /// <summary>
    /// Optional. Input port for magnetometer. See also `MagnetometerResultSink`_ .
    /// </summary>
    std::shared_ptr<MagnetometerResultSink> magnetometerResultSink();
    /// <summary>
    /// Optional. Input port for location result. See also `LocationResultSink`_ .
    /// </summary>
    std::shared_ptr<LocationResultSink> locationResultSink();
    /// <summary>
    /// Optional. Input port for proximity location result. See also `ProximityLocationResultSink`_ .
    /// </summary>
    std::shared_ptr<ProximityLocationResultSink> proximityLocationResultSink();
    /// <summary>
    /// Camera buffers occupied in this component.
    /// </summary>
    int bufferRequirement();
    /// <summary>
    /// Output port.
    /// </summary>
    std::shared_ptr<InputFrameSource> output();
    /// <summary>
    /// Creates an instance.
    /// </summary>
    static std::shared_ptr<VideoInputFrameRecorder> create();
    /// <summary>
    /// Starts frame recording. The definitions of cameraDeviceType, cameraOrientation and cameraOrientation are the same as in `CameraParameters`_ . initialScreenRotation is the initial screen rotation when recording data, and it will be used in rendering for playback.
    /// </summary>
    bool start(std::string filePath, CameraDeviceType cameraDeviceType, int cameraOrientation, int initialScreenRotation, VideoInputFrameRecorderVideoCodec codec, int width, int height, double frameRate, std::string metadata);
    /// <summary>
    /// Stops frame recording. It will only stop recording and will not affect connection.
    /// </summary>
    void stop();
    /// <summary>
    /// Sets callback for automatic completion of recording.
    /// </summary>
    void setAutomaticCompletionCallback(std::shared_ptr<CallbackScheduler> callbackScheduler, std::optional<std::function<void(VideoInputFrameRecorderCompletionReason)>> automaticCompletionCallback);
};

/// <summary>
/// Input frame player.
/// There is an input frame output port. It can be used to get input frame from an EIF MKV file.
/// All members of this class is thread-safe.
/// </summary>
class VideoInputFramePlayer
{
protected:
    std::shared_ptr<easyar_VideoInputFramePlayer> cdata_;
    void init_cdata(std::shared_ptr<easyar_VideoInputFramePlayer> cdata);
    VideoInputFramePlayer & operator=(const VideoInputFramePlayer & data) = delete;
public:
    VideoInputFramePlayer(std::shared_ptr<easyar_VideoInputFramePlayer> cdata);
    virtual ~VideoInputFramePlayer();

    std::shared_ptr<easyar_VideoInputFramePlayer> get_cdata();
    static std::shared_ptr<VideoInputFramePlayer> from_cdata(std::shared_ptr<easyar_VideoInputFramePlayer> cdata);

    /// <summary>
    /// Checks if the component is available. It returns true only on Windows.
    /// </summary>
    static bool isAvailable();
    /// <summary>
    /// Output port.
    /// </summary>
    std::shared_ptr<InputFrameSource> output();
    /// <summary>
    /// Output port for accelerometer result. See also `AccelerometerResultSource`_ .
    /// </summary>
    std::shared_ptr<AccelerometerResultSource> accelerometerResultSource();
    /// <summary>
    /// Output port for gyroscope result. See also `GyroscopeResultSource`_ .
    /// </summary>
    std::shared_ptr<GyroscopeResultSource> gyroscopeResultSource();
    /// <summary>
    /// Output port for attitude sensor. See also `AttitudeSensorResultSource`_ .
    /// </summary>
    std::shared_ptr<AttitudeSensorResultSource> attitudeSensorResultSource();
    /// <summary>
    /// Output port for magnetometer. See also `MagnetometerResultSource`_ .
    /// </summary>
    std::shared_ptr<MagnetometerResultSource> magnetometerResultSource();
    /// <summary>
    /// Output port for location result. See also `LocationResultSource`_ .
    /// </summary>
    std::shared_ptr<LocationResultSource> locationResultSource();
    /// <summary>
    /// Output port for proximity location result. See also `ProximityLocationResultSource`_ .
    /// </summary>
    std::shared_ptr<ProximityLocationResultSource> proximityLocationResultSource();
    /// <summary>
    /// Creates an instance.
    /// </summary>
    static std::shared_ptr<VideoInputFramePlayer> create();
    /// <summary>
    /// Starts frame play.
    /// </summary>
    bool start(std::string filePath);
    /// <summary>
    /// Stops frame play.
    /// </summary>
    void stop();
    /// <summary>
    /// Pauses frame play.
    /// </summary>
    void pause();
    /// <summary>
    /// Resumes frame play.
    /// </summary>
    bool resume();
    /// <summary>
    /// Total expected playback time span. The unit is second. If recording halts improperly, it may be missing.
    /// </summary>
    std::optional<double> totalTime();
    /// <summary>
    /// Current playback time point. The unit is second. The initial value is 0.
    /// </summary>
    double currentTime();
    /// <summary>
    /// Whether the current playback time point can be relocated. If recording halts improperly, index data to set playback time point may be missing.
    /// </summary>
    bool isSeekable();
    /// <summary>
    /// Sets current playback time point. The unit is second. If index data is missing, it returns false.
    /// </summary>
    bool seek(double time);
    /// <summary>
    /// Current playback speed. The initial value is 1.
    /// </summary>
    double speed();
    /// <summary>
    /// Sets current playback speed.
    /// </summary>
    void setSpeed(double _value);
    /// <summary>
    /// The initial screen rotation when recording data.
    /// </summary>
    int initalScreenRotation();
    /// <summary>
    /// The metadata when recording data.
    /// </summary>
    std::string metadata();
    /// <summary>
    /// Whether the playback is completed.
    /// </summary>
    bool isCompleted();
};

/// <summary>
/// Image helper class.
/// </summary>
class ImageHelper
{
public:
    /// <summary>
    /// Decodes a JPEG or PNG file.
    /// </summary>
    static std::optional<std::shared_ptr<Image>> decode(std::shared_ptr<Buffer> buffer);
};

/// <summary>
/// InertialCameraDevice implements an inertial camera device, which outputs `InputFrame`_ which `CameraTransformType`_ is FiveDofRotXZ (including image, camera parameters, timestamp, camera transform matrix and tracking status).
/// After creation, start/stop can be invoked to start or stop video stream capture.
/// When the component is not needed anymore, call close function to close it. It shall not be used after calling close.
/// InertialCameraDevice outputs `InputFrame`_ from inputFrameSource. inputFrameSource shall be connected to `InputFrameSink`_ for use.
/// bufferCapacity is the capacity of `InputFrame`_ buffer. If the count of `InputFrame`_ which has been output from the device and have not been released is more than this number, the device will not output new `InputFrame`_ , until previous `InputFrame`_ have been released. This may cause screen stuck.
/// </summary>
class InertialCameraDevice
{
protected:
    std::shared_ptr<easyar_InertialCameraDevice> cdata_;
    void init_cdata(std::shared_ptr<easyar_InertialCameraDevice> cdata);
    InertialCameraDevice & operator=(const InertialCameraDevice & data) = delete;
public:
    InertialCameraDevice(std::shared_ptr<easyar_InertialCameraDevice> cdata);
    virtual ~InertialCameraDevice();

    std::shared_ptr<easyar_InertialCameraDevice> get_cdata();
    static std::shared_ptr<InertialCameraDevice> from_cdata(std::shared_ptr<easyar_InertialCameraDevice> cdata);

    /// <summary>
    /// Default create method.
    /// </summary>
    InertialCameraDevice();
    /// <summary>
    /// Checks if the component is available. It returns true only on Android 7.0 (API Level 24+) when accelerometer, gyroscope and attitude sensor are all available.
    /// </summary>
    static bool isAvailable();
    /// <summary>
    /// `InputFrame`_ buffer capacity. The default is 8.
    /// </summary>
    int bufferCapacity();
    /// <summary>
    /// Sets `InputFrame`_ buffer capacity.
    /// </summary>
    void setBufferCapacity(int capacity);
    /// <summary>
    /// `InputFrame`_ output port.
    /// </summary>
    std::shared_ptr<InputFrameSource> inputFrameSource();
    /// <summary>
    /// Sets focus mode to focusMode. Call before start.
    /// </summary>
    void setFocusMode(InertialCameraDeviceFocusMode focusMode);
    /// <summary>
    /// Camera type. Call after a successful open.
    /// </summary>
    CameraDeviceType type();
    /// <summary>
    /// Angles rotation required to rotate clockwise and display camera image on device with natural orientation. Call after a successful open.
    /// </summary>
    int cameraOrientation();
    /// <summary>
    /// Gets the current preview size. Call after a successful open.
    /// </summary>
    Vec2I size();
    /// <summary>
    /// Gets the number of supported preview sizes. Call after a successful open.
    /// </summary>
    int supportedSizeCount();
    /// <summary>
    /// Gets the index-th supported preview size. It returns {0, 0} if index is out of range. Call after a successful open.
    /// </summary>
    Vec2I supportedSize(int index);
    /// <summary>
    /// Sets the preview size. The available nearest value will be selected. Call size to get the actual size. Call after a successful open. frameRateRange may change after calling setSize.
    /// </summary>
    bool setSize(Vec2I size);
    /// <summary>
    /// Opens back camera of device. If the opening fails will return false.
    /// </summary>
    bool open();
    /// <summary>
    /// Starts video stream capture.
    /// </summary>
    bool start();
    /// <summary>
    /// Stops video stream capture.
    /// </summary>
    void stop();
    /// <summary>
    /// Resets states.
    /// </summary>
    void reset();
    /// <summary>
    /// Close. The component shall not be used after calling close.
    /// </summary>
    void close();
    /// <summary>
    /// Gets lower bound of current frame rate range. Call after a successful open.
    /// </summary>
    double frameRateRangeLower();
    /// <summary>
    /// Gets upper bound of current frame rate range. Call after a successful open.
    /// </summary>
    double frameRateRangeUpper();
};

/// <summary>
/// Callback scheduler.
/// There are two subclasses: `DelayedCallbackScheduler`_ and `ImmediateCallbackScheduler`_ .
/// `DelayedCallbackScheduler`_ is used to delay callback to be invoked manually, and it can be used in single-threaded environments (such as various UI environments).
/// `ImmediateCallbackScheduler`_ is used to mark callback to be invoked when event is dispatched, and it can be used in multi-threaded environments (such as server or service daemon).
/// </summary>
class CallbackScheduler
{
protected:
    std::shared_ptr<easyar_CallbackScheduler> cdata_;
    void init_cdata(std::shared_ptr<easyar_CallbackScheduler> cdata);
    CallbackScheduler & operator=(const CallbackScheduler & data) = delete;
public:
    CallbackScheduler(std::shared_ptr<easyar_CallbackScheduler> cdata);
    virtual ~CallbackScheduler();

    std::shared_ptr<easyar_CallbackScheduler> get_cdata();
    static std::shared_ptr<CallbackScheduler> from_cdata(std::shared_ptr<easyar_CallbackScheduler> cdata);

};

/// <summary>
/// Delayed callback scheduler.
/// It is used to delay callback to be invoked manually, and it can be used in single-threaded environments (such as various UI environments).
/// All members of this class is thread-safe.
/// </summary>
class DelayedCallbackScheduler : public CallbackScheduler
{
protected:
    std::shared_ptr<easyar_DelayedCallbackScheduler> cdata_;
    void init_cdata(std::shared_ptr<easyar_DelayedCallbackScheduler> cdata);
    DelayedCallbackScheduler & operator=(const DelayedCallbackScheduler & data) = delete;
public:
    DelayedCallbackScheduler(std::shared_ptr<easyar_DelayedCallbackScheduler> cdata);
    virtual ~DelayedCallbackScheduler();

    std::shared_ptr<easyar_DelayedCallbackScheduler> get_cdata();
    static std::shared_ptr<DelayedCallbackScheduler> from_cdata(std::shared_ptr<easyar_DelayedCallbackScheduler> cdata);

    DelayedCallbackScheduler();
    /// <summary>
    /// Executes a callback. If there is no callback to execute, false is returned.
    /// </summary>
    bool runOne();
};

/// <summary>
/// Immediate callback scheduler.
/// It is used to mark callback to be invoked when event is dispatched, and it can be used in multi-threaded environments (such as server or service daemon).
/// All members of this class is thread-safe.
/// </summary>
class ImmediateCallbackScheduler : public CallbackScheduler
{
protected:
    std::shared_ptr<easyar_ImmediateCallbackScheduler> cdata_;
    void init_cdata(std::shared_ptr<easyar_ImmediateCallbackScheduler> cdata);
    ImmediateCallbackScheduler & operator=(const ImmediateCallbackScheduler & data) = delete;
public:
    ImmediateCallbackScheduler(std::shared_ptr<easyar_ImmediateCallbackScheduler> cdata);
    virtual ~ImmediateCallbackScheduler();

    std::shared_ptr<easyar_ImmediateCallbackScheduler> get_cdata();
    static std::shared_ptr<ImmediateCallbackScheduler> from_cdata(std::shared_ptr<easyar_ImmediateCallbackScheduler> cdata);

    /// <summary>
    /// Gets a default immediate callback scheduler.
    /// </summary>
    static std::shared_ptr<ImmediateCallbackScheduler> getDefault();
};

/// <summary>
/// JNI utility class.
/// It is used in Unity to wrap Java byte array and ByteBuffer.
/// It is not supported on iOS.
/// </summary>
class JniUtility
{
public:
    /// <summary>
    /// Wraps Java&#39;s byte[]。
    /// </summary>
    static std::shared_ptr<Buffer> wrapByteArray(void * bytes, bool readOnly, std::function<void()> deleter);
    /// <summary>
    /// Wraps Java&#39;s java.nio.ByteBuffer, which must be a direct buffer.
    /// </summary>
    static std::shared_ptr<Buffer> wrapBuffer(void * directBuffer, std::function<void()> deleter);
    /// <summary>
    /// Get the raw address of a direct buffer of java.nio.ByteBuffer by calling JNIEnv-&gt;GetDirectBufferAddress.
    /// </summary>
    static void * getDirectBufferAddress(void * directBuffer);
};

/// <summary>
/// Log class.
/// It is used to output log or setup a custom log output function.
/// </summary>
class Log
{
public:
    /// <summary>
    /// Outputs a log.
    /// </summary>
    static void logMessage(LogLevel level, std::string message);
    /// <summary>
    /// Sets custom log output function. The log output function should be thread-safe.
    /// </summary>
    static void setLogFunc(std::function<void(LogLevel, std::string)> func);
    /// <summary>
    /// Sets custom log output function and run it in scheduler.
    /// </summary>
    static void setLogFuncWithScheduler(std::shared_ptr<CallbackScheduler> scheduler, std::function<void(LogLevel, std::string)> func);
    /// <summary>
    /// Clears custom log output function and reverts to default log output function.
    /// </summary>
    static void resetLogFunc();
};

class Storage
{
public:
    /// <summary>
    /// Sets asset root path.
    /// </summary>
    static void setAssetDirPath(std::string path);
};

/// <summary>
/// ImageTargetParameters represents the parameters to create a `ImageTarget`_ .
/// </summary>
class ImageTargetParameters
{
protected:
    std::shared_ptr<easyar_ImageTargetParameters> cdata_;
    void init_cdata(std::shared_ptr<easyar_ImageTargetParameters> cdata);
    ImageTargetParameters & operator=(const ImageTargetParameters & data) = delete;
public:
    ImageTargetParameters(std::shared_ptr<easyar_ImageTargetParameters> cdata);
    virtual ~ImageTargetParameters();

    std::shared_ptr<easyar_ImageTargetParameters> get_cdata();
    static std::shared_ptr<ImageTargetParameters> from_cdata(std::shared_ptr<easyar_ImageTargetParameters> cdata);

    ImageTargetParameters();
    /// <summary>
    /// Gets image.
    /// </summary>
    std::shared_ptr<Image> image();
    /// <summary>
    /// Sets image.
    /// </summary>
    void setImage(std::shared_ptr<Image> image);
    /// <summary>
    /// Gets target name. It can be used to distinguish targets.
    /// </summary>
    std::string name();
    /// <summary>
    /// Sets target name.
    /// </summary>
    void setName(std::string name);
    /// <summary>
    /// Gets the target uid. A target uid is useful in cloud based algorithms. If no cloud is used, you can set this uid in the json config as an alternative method to distinguish from targets.
    /// </summary>
    std::string uid();
    /// <summary>
    /// Sets target uid.
    /// </summary>
    void setUid(std::string uid);
    /// <summary>
    /// Gets meta data.
    /// </summary>
    std::string meta();
    /// <summary>
    /// Sets meta data。
    /// </summary>
    void setMeta(std::string meta);
    /// <summary>
    /// Gets the scale of image. The value is the physical image width divided by 1 meter. The default value is 1.
    /// </summary>
    float scale();
    /// <summary>
    /// Sets the scale of image. The value is the physical image width divided by 1 meter. The default value is 1.
    /// It is needed to set the model scale in rendering engine separately.
    /// </summary>
    void setScale(float scale);
};

/// <summary>
/// ImageTarget represents planar image targets that can be tracked by `ImageTracker`_ .
/// The fields of ImageTarget need to be filled with the create... method before it can be read. And ImageTarget can be tracked by `ImageTracker`_ after a successful load into the `ImageTracker`_ using `ImageTracker.loadTarget`_ .
/// </summary>
class ImageTarget : public Target
{
protected:
    std::shared_ptr<easyar_ImageTarget> cdata_;
    void init_cdata(std::shared_ptr<easyar_ImageTarget> cdata);
    ImageTarget & operator=(const ImageTarget & data) = delete;
public:
    ImageTarget(std::shared_ptr<easyar_ImageTarget> cdata);
    virtual ~ImageTarget();

    std::shared_ptr<easyar_ImageTarget> get_cdata();
    static std::shared_ptr<ImageTarget> from_cdata(std::shared_ptr<easyar_ImageTarget> cdata);

    ImageTarget();
    /// <summary>
    /// Creates a target from parameters.
    /// </summary>
    static std::optional<std::shared_ptr<ImageTarget>> createFromParameters(std::shared_ptr<ImageTargetParameters> parameters);
    /// <summary>
    /// Creates a target from an etd file.
    /// </summary>
    static std::optional<std::shared_ptr<ImageTarget>> createFromTargetFile(std::string path, StorageType storageType);
    /// <summary>
    /// Creates a target from an etd data buffer.
    /// </summary>
    static std::optional<std::shared_ptr<ImageTarget>> createFromTargetData(std::shared_ptr<Buffer> buffer);
    /// <summary>
    /// Saves as an etd file.
    /// </summary>
    bool save(std::string path);
    /// <summary>
    /// Creates a target from an image file. If not needed, name, uid, meta can be passed with empty string, and scale can be passed with default value 1. Jpeg and png files are supported.
    /// </summary>
    static std::optional<std::shared_ptr<ImageTarget>> createFromImageFile(std::string path, StorageType storageType, std::string name, std::string uid, std::string meta, float scale);
    /// <summary>
    /// The scale of image. The value is the physical image width divided by 1 meter. The default value is 1.
    /// </summary>
    float scale();
    /// <summary>
    /// The aspect ratio of image, width divided by height.
    /// </summary>
    float aspectRatio();
    /// <summary>
    /// Sets image target scale, this will overwrite the value set in the json file or the default value. The value is the physical image width divided by 1 meter. The default value is 1.
    /// It is needed to set the model scale in rendering engine separately.
    /// </summary>
    bool setScale(float scale);
    /// <summary>
    /// Returns a list of images that stored in the target. It is generally used to get image data from cloud returned target.
    /// </summary>
    std::vector<std::shared_ptr<Image>> images();
    /// <summary>
    /// Returns the target id. A target id is a integer number generated at runtime. This id is non-zero and increasing globally.
    /// </summary>
    int runtimeID();
    /// <summary>
    /// Returns the target uid. A target uid is useful in cloud based algorithms. If no cloud is used, you can set this uid in the json config as a alternative method to distinguish from targets.
    /// </summary>
    std::string uid();
    /// <summary>
    /// Returns the target name. Name is used to distinguish targets in a json file.
    /// </summary>
    std::string name();
    /// <summary>
    /// Set name. It will erase previously set data or data from cloud.
    /// </summary>
    void setName(std::string name);
    /// <summary>
    /// Returns the meta data set by setMetaData. Or, in a cloud returned target, returns the meta data set in the cloud server.
    /// </summary>
    std::string meta();
    /// <summary>
    /// Set meta data. It will erase previously set data or data from cloud.
    /// </summary>
    void setMeta(std::string data);
};

/// <summary>
/// Config for creating `ImageTracker`_ .
/// </summary>
class ImageTrackerConfig
{
protected:
    std::shared_ptr<easyar_ImageTrackerConfig> cdata_;
    void init_cdata(std::shared_ptr<easyar_ImageTrackerConfig> cdata);
    ImageTrackerConfig & operator=(const ImageTrackerConfig & data) = delete;
public:
    ImageTrackerConfig(std::shared_ptr<easyar_ImageTrackerConfig> cdata);
    virtual ~ImageTrackerConfig();

    std::shared_ptr<easyar_ImageTrackerConfig> get_cdata();
    static std::shared_ptr<ImageTrackerConfig> from_cdata(std::shared_ptr<easyar_ImageTrackerConfig> cdata);

    ImageTrackerConfig();
    /// <summary>
    /// Mode for ImageTracker. It defaults to PreferQuality.
    /// </summary>
    ImageTrackerMode trackerMode();
    void setTrackerMode(ImageTrackerMode _value);
};

/// <summary>
/// Result of `ImageTracker`_ .
/// </summary>
class ImageTrackerResult : public TargetTrackerResult
{
protected:
    std::shared_ptr<easyar_ImageTrackerResult> cdata_;
    void init_cdata(std::shared_ptr<easyar_ImageTrackerResult> cdata);
    ImageTrackerResult & operator=(const ImageTrackerResult & data) = delete;
public:
    ImageTrackerResult(std::shared_ptr<easyar_ImageTrackerResult> cdata);
    virtual ~ImageTrackerResult();

    std::shared_ptr<easyar_ImageTrackerResult> get_cdata();
    static std::shared_ptr<ImageTrackerResult> from_cdata(std::shared_ptr<easyar_ImageTrackerResult> cdata);

    /// <summary>
    /// Returns the list of `TargetInstance`_ contained in the result.
    /// </summary>
    std::vector<std::shared_ptr<TargetInstance>> targetInstances();
    /// <summary>
    /// Sets the list of `TargetInstance`_ contained in the result.
    /// </summary>
    void setTargetInstances(std::vector<std::shared_ptr<TargetInstance>> instances);
};

/// <summary>
/// ImageTracker implements image target detection and tracking.
/// ImageTracker occupies (1 + SimultaneousNum) buffers of camera. Use setBufferCapacity of camera to set an amount of buffers that is not less than the sum of amount of buffers occupied by all components.
/// After creation, you can call start/stop to enable/disable the track process. start and stop are very lightweight calls.
/// When the component is not needed anymore, call close function to close it. It shall not be used after calling close.
/// ImageTracker inputs `FeedbackFrame`_ from feedbackFrameSink. `FeedbackFrameSource`_ shall be connected to feedbackFrameSink for use.
/// Before a `Target`_ can be tracked by ImageTracker, you have to load it using loadTarget/unloadTarget. You can get load/unload results from callbacks passed into the interfaces.
/// </summary>
class ImageTracker
{
protected:
    std::shared_ptr<easyar_ImageTracker> cdata_;
    void init_cdata(std::shared_ptr<easyar_ImageTracker> cdata);
    ImageTracker & operator=(const ImageTracker & data) = delete;
public:
    ImageTracker(std::shared_ptr<easyar_ImageTracker> cdata);
    virtual ~ImageTracker();

    std::shared_ptr<easyar_ImageTracker> get_cdata();
    static std::shared_ptr<ImageTracker> from_cdata(std::shared_ptr<easyar_ImageTracker> cdata);

    /// <summary>
    /// Returns true.
    /// </summary>
    static bool isAvailable();
    /// <summary>
    /// `FeedbackFrame`_ input port. The InputFrame member of FeedbackFrame must have raw image, timestamp, and camera parameters. Both pinhole and fisheye camera are supported.
    /// </summary>
    std::shared_ptr<FeedbackFrameSink> feedbackFrameSink();
    /// <summary>
    /// Camera buffers occupied in this component.
    /// </summary>
    int bufferRequirement();
    /// <summary>
    /// `OutputFrame`_ output port.
    /// </summary>
    std::shared_ptr<OutputFrameSource> outputFrameSource();
    /// <summary>
    /// Creates an instance. The default track mode is `ImageTrackerMode`_.PreferQuality .
    /// </summary>
    static std::shared_ptr<ImageTracker> create();
    /// <summary>
    /// Creates an instance with a specified track mode. On lower-end phones, `ImageTrackerMode`_.PreferPerformance can be used to keep a better performance with a little quality loss.
    /// </summary>
    static std::shared_ptr<ImageTracker> createWithMode(ImageTrackerMode trackMode);
    /// <summary>
    /// Creates an instance with a specified config.
    /// </summary>
    static std::shared_ptr<ImageTracker> createWithConfig(std::shared_ptr<ImageTrackerConfig> config);
    /// <summary>
    /// Sets result post-processing.
    /// enablePersistentTargetInstance defaults to false. When it is enabled and `InputFrame`_ contains spatial information, targetInstances in `ImageTrackerResult`_ will contain all recognized instances (with not tracking target instances).
    /// enableMotionFusion defaults to false. When it is enabled and `InputFrame`_ contains temporal information and spatial information, pose of targetInstances in `ImageTrackerResult`_ will utilize RealTimeCoordinateTransform .
    /// </summary>
    void setResultPostProcessing(bool enablePersistentTargetInstance, bool enableMotionFusion);
    /// <summary>
    /// Sets result async mode. Set true If results are to be outputted via outputFrameSource, false if results are to be fetched via getSyncResult. enableAsync defaults to true. Sync mode is only available with input frames including spatial information and with a XR license.
    /// </summary>
    bool setResultAsyncMode(bool enableAsync);
    /// <summary>
    /// Starts the track algorithm.
    /// </summary>
    bool start();
    /// <summary>
    /// Stops the track algorithm. Call start to start the track again.
    /// </summary>
    void stop();
    /// <summary>
    /// Close. The component shall not be used after calling close.
    /// </summary>
    void close();
    /// <summary>
    /// Load a `Target`_ into the tracker. A Target can only be tracked by tracker after a successful load.
    /// This method is an asynchronous method. A load operation may take some time to finish and detection of a new/lost target may take more time during the load. The track time after detection will not be affected. If you want to know the load result, you have to handle the callback data. The callback will be called from the thread specified by `CallbackScheduler`_ . It will not block the track thread or any other operations except other load/unload.
    /// </summary>
    void loadTarget(std::shared_ptr<Target> target, std::shared_ptr<CallbackScheduler> callbackScheduler, std::function<void(std::shared_ptr<Target>, bool)> callback);
    /// <summary>
    /// Unload a `Target`_ from the tracker.
    /// This method is an asynchronous method. An unload operation may take some time to finish and detection of a new/lost target may take more time during the unload. If you want to know the unload result, you have to handle the callback data. The callback will be called from the thread specified by `CallbackScheduler`_ . It will not block the track thread or any other operations except other load/unload.
    /// </summary>
    void unloadTarget(std::shared_ptr<Target> target, std::shared_ptr<CallbackScheduler> callbackScheduler, std::function<void(std::shared_ptr<Target>, bool)> callback);
    /// <summary>
    /// Returns current loaded targets in the tracker. If an asynchronous load/unload is in progress, the returned value will not reflect the result until all load/unload finish.
    /// </summary>
    std::vector<std::shared_ptr<Target>> targets();
    /// <summary>
    /// Sets the max number of targets which will be the simultaneously tracked by the tracker. The default value is 1.
    /// </summary>
    bool setSimultaneousNum(int num);
    /// <summary>
    /// Gets the max number of targets which will be the simultaneously tracked by the tracker. The default value is 1.
    /// </summary>
    int simultaneousNum();
    /// <summary>
    /// Get synchronized result. If ImageTracker is paused, or the result async mode is not set to false through setResultAsyncMode, the return value is empty.
    /// </summary>
    std::optional<std::shared_ptr<ImageTrackerResult>> getSyncResult(std::shared_ptr<MotionInputData> motionInputData);
};

/// <summary>
/// Recorder implements recording for current rendering screen.
/// Currently Recorder only works on Android (4.3 or later) and iOS with OpenGL ES 3.0 context.
/// Due to the dependency to OpenGLES, every method in this class (except requestPermissions, including the destructor) has to be called in a single thread containing an OpenGLES context.
/// **Unity Only** If in Unity, Multi-threaded rendering is enabled, scripting thread and rendering thread will be two separate threads, which makes it impossible to call updateFrame in the rendering thread. For this reason, to use Recorder, Multi-threaded rendering option shall be disabled.
/// On Android, it is required to add android.permission.RECORD_AUDIO to AndroidManifest.xml for use.
/// On iOS, it is required to add NSMicrophoneUsageDescription to Info.plist for use.
/// </summary>
class Recorder
{
protected:
    std::shared_ptr<easyar_Recorder> cdata_;
    void init_cdata(std::shared_ptr<easyar_Recorder> cdata);
    Recorder & operator=(const Recorder & data) = delete;
public:
    Recorder(std::shared_ptr<easyar_Recorder> cdata);
    virtual ~Recorder();

    std::shared_ptr<easyar_Recorder> get_cdata();
    static std::shared_ptr<Recorder> from_cdata(std::shared_ptr<easyar_Recorder> cdata);

    /// <summary>
    /// Returns true only on Android 4.3 or later, or on iOS.
    /// </summary>
    static bool isAvailable();
    /// <summary>
    /// Requests recording permissions from operating system. You can call this function or request permission directly from operating system. It is only available on Android and iOS. On other platforms, it will call the callback directly with status being granted. This function need to be called from the UI thread.
    /// </summary>
    static void requestPermissions(std::shared_ptr<CallbackScheduler> callbackScheduler, std::optional<std::function<void(PermissionStatus, std::string)>> permissionCallback);
    /// <summary>
    /// Creates an instance and initialize recording. statusCallback will dispatch event of status change and corresponding log.
    /// </summary>
    static std::shared_ptr<Recorder> create(std::shared_ptr<RecorderConfiguration> config, std::shared_ptr<CallbackScheduler> callbackScheduler, std::optional<std::function<void(RecordStatus, std::string)>> statusCallback);
    /// <summary>
    /// Start recording.
    /// </summary>
    void start();
    /// <summary>
    /// Update and record a frame using texture data.
    /// </summary>
    void updateFrame(std::shared_ptr<TextureId> texture, int width, int height);
    /// <summary>
    /// Stop recording. When calling stop, it will wait for file write to end and returns whether recording is successful.
    /// </summary>
    bool stop();
};

/// <summary>
/// RecorderConfiguration is startup configuration for `Recorder`_ .
/// </summary>
class RecorderConfiguration
{
protected:
    std::shared_ptr<easyar_RecorderConfiguration> cdata_;
    void init_cdata(std::shared_ptr<easyar_RecorderConfiguration> cdata);
    RecorderConfiguration & operator=(const RecorderConfiguration & data) = delete;
public:
    RecorderConfiguration(std::shared_ptr<easyar_RecorderConfiguration> cdata);
    virtual ~RecorderConfiguration();

    std::shared_ptr<easyar_RecorderConfiguration> get_cdata();
    static std::shared_ptr<RecorderConfiguration> from_cdata(std::shared_ptr<easyar_RecorderConfiguration> cdata);

    RecorderConfiguration();
    /// <summary>
    /// Sets absolute path for output video file.
    /// </summary>
    void setOutputFile(std::string path);
    /// <summary>
    /// Sets recording profile. Default value is Quality_720P_Middle.
    /// This is an all-in-one configuration, you can control in more advanced mode with other APIs.
    /// </summary>
    bool setProfile(RecordProfile profile);
    /// <summary>
    /// Sets recording video size. Default value is Vid720p.
    /// </summary>
    void setVideoSize(RecordVideoSize framesize);
    /// <summary>
    /// Sets recording video bit rate. Default value is 2500000.
    /// </summary>
    void setVideoBitrate(int bitrate);
    /// <summary>
    /// Sets recording audio channel count. Default value is 1.
    /// </summary>
    void setChannelCount(int count);
    /// <summary>
    /// Sets recording audio sample rate. Default value is 44100.
    /// </summary>
    void setAudioSampleRate(int samplerate);
    /// <summary>
    /// Sets recording audio bit rate. Default value is 96000.
    /// </summary>
    void setAudioBitrate(int bitrate);
    /// <summary>
    /// Sets recording video orientation. Default value is Landscape.
    /// </summary>
    void setVideoOrientation(RecordVideoOrientation mode);
    /// <summary>
    /// Sets recording zoom mode. Default value is NoZoomAndClip.
    /// </summary>
    void setZoomMode(RecordZoomMode mode);
};

/// <summary>
/// Describes the result of mapping and localization. Updated at the same frame rate with OutputFrame.
/// </summary>
class SparseSpatialMapResult : public FrameFilterResult
{
protected:
    std::shared_ptr<easyar_SparseSpatialMapResult> cdata_;
    void init_cdata(std::shared_ptr<easyar_SparseSpatialMapResult> cdata);
    SparseSpatialMapResult & operator=(const SparseSpatialMapResult & data) = delete;
public:
    SparseSpatialMapResult(std::shared_ptr<easyar_SparseSpatialMapResult> cdata);
    virtual ~SparseSpatialMapResult();

    std::shared_ptr<easyar_SparseSpatialMapResult> get_cdata();
    static std::shared_ptr<SparseSpatialMapResult> from_cdata(std::shared_ptr<easyar_SparseSpatialMapResult> cdata);

    /// <summary>
    /// Obtain motion tracking status.
    /// </summary>
    MotionTrackingStatus getMotionTrackingStatus();
    /// <summary>
    /// Returns pose of the origin of VIO system in camera coordinate system.
    /// </summary>
    std::optional<Matrix44F> getVioPose();
    /// <summary>
    /// Returns the pose of origin of the map in camera coordinate system, when localization is successful.
    /// Otherwise, returns pose of the origin of VIO system in camera coordinate system.
    /// </summary>
    std::optional<Matrix44F> getMapPose();
    /// <summary>
    /// Returns true if the system can reliablly locate the pose of the device with regard to the map.
    /// Once relocalization succeeds, relative pose can be updated by motion tracking module.
    /// As long as the motion tracking module returns normal tracking status, the localization status is also true.
    /// </summary>
    bool getLocalizationStatus();
    /// <summary>
    /// Returns current localized map ID.
    /// </summary>
    std::string getLocalizationMapID();
};

class PlaneData
{
protected:
    std::shared_ptr<easyar_PlaneData> cdata_;
    void init_cdata(std::shared_ptr<easyar_PlaneData> cdata);
    PlaneData & operator=(const PlaneData & data) = delete;
public:
    PlaneData(std::shared_ptr<easyar_PlaneData> cdata);
    virtual ~PlaneData();

    std::shared_ptr<easyar_PlaneData> get_cdata();
    static std::shared_ptr<PlaneData> from_cdata(std::shared_ptr<easyar_PlaneData> cdata);

    /// <summary>
    /// Constructor
    /// </summary>
    PlaneData();
    /// <summary>
    /// Returns the type of this plane.
    /// </summary>
    PlaneType getType();
    /// <summary>
    /// Returns the pose of the center of the detected plane.The pose&#39;s transformed +Y axis will be point normal out of the plane, with the +X and +Z axes orienting the extents of the bounding rectangle.
    /// </summary>
    Matrix44F getPose();
    /// <summary>
    /// Returns the length of this plane&#39;s bounding rectangle measured along the local X-axis of the coordinate space centered on the plane.
    /// </summary>
    float getExtentX();
    /// <summary>
    /// Returns the length of this plane&#39;s bounding rectangle measured along the local Z-axis of the coordinate frame centered on the plane.
    /// </summary>
    float getExtentZ();
};

/// <summary>
/// Configuration used to set the localization mode.
/// </summary>
class SparseSpatialMapConfig
{
protected:
    std::shared_ptr<easyar_SparseSpatialMapConfig> cdata_;
    void init_cdata(std::shared_ptr<easyar_SparseSpatialMapConfig> cdata);
    SparseSpatialMapConfig & operator=(const SparseSpatialMapConfig & data) = delete;
public:
    SparseSpatialMapConfig(std::shared_ptr<easyar_SparseSpatialMapConfig> cdata);
    virtual ~SparseSpatialMapConfig();

    std::shared_ptr<easyar_SparseSpatialMapConfig> get_cdata();
    static std::shared_ptr<SparseSpatialMapConfig> from_cdata(std::shared_ptr<easyar_SparseSpatialMapConfig> cdata);

    /// <summary>
    /// Constructor
    /// </summary>
    SparseSpatialMapConfig();
    /// <summary>
    /// Sets localization configurations. See also `LocalizationMode`_.
    /// </summary>
    void setLocalizationMode(LocalizationMode _value);
    /// <summary>
    /// Returns localization configurations. See also `LocalizationMode`_.
    /// </summary>
    LocalizationMode getLocalizationMode();
};

/// <summary>
/// Provides core components for SparseSpatialMap, can be used for sparse spatial map building as well as localization using existing map. Also provides utilities for point cloud and plane access.
/// SparseSpatialMap occupies 2 buffers of camera. Use setBufferCapacity of camera to set an amount of buffers that is not less than the sum of amount of buffers occupied by all components.
/// </summary>
class SparseSpatialMap
{
protected:
    std::shared_ptr<easyar_SparseSpatialMap> cdata_;
    void init_cdata(std::shared_ptr<easyar_SparseSpatialMap> cdata);
    SparseSpatialMap & operator=(const SparseSpatialMap & data) = delete;
public:
    SparseSpatialMap(std::shared_ptr<easyar_SparseSpatialMap> cdata);
    virtual ~SparseSpatialMap();

    std::shared_ptr<easyar_SparseSpatialMap> get_cdata();
    static std::shared_ptr<SparseSpatialMap> from_cdata(std::shared_ptr<easyar_SparseSpatialMap> cdata);

    /// <summary>
    /// Check whether SparseSpatialMap is is available, always return true.
    /// </summary>
    static bool isAvailable();
    /// <summary>
    /// Input port for input frame. For SparseSpatialMap to work, the inputFrame must include camera parameters, timestamp and spatial information. See also `InputFrameSink`_
    /// Note: Both pinhole and fisheye camera are supported. But performance may decrease while using a fisheye camera.
    /// </summary>
    std::shared_ptr<InputFrameSink> inputFrameSink();
    /// <summary>
    /// Camera buffers occupied in this component.
    /// </summary>
    int bufferRequirement();
    /// <summary>
    /// Output port for output frame. See also `OutputFrameSource`_
    /// </summary>
    std::shared_ptr<OutputFrameSource> outputFrameSource();
    /// <summary>
    /// Construct SparseSpatialMap.
    /// </summary>
    static std::shared_ptr<SparseSpatialMap> create();
    /// <summary>
    /// Sets type of result pose. enableStabilization defaults to false. It only takes effect when `InputFrame`_ contains spatial information.
    /// </summary>
    void setResultPoseType(bool enableStabilization);
    /// <summary>
    /// Sets result async mode. Set true If results are to be outputted via outputFrameSource, false if results are to be fetched via getSyncResult. enableAsync defaults to true. Sync mode is only available with input frames including spatial information and with a XR license.
    /// </summary>
    bool setResultAsyncMode(bool enableAsync);
    /// <summary>
    /// Start SparseSpatialMap system.
    /// </summary>
    bool start();
    /// <summary>
    /// Stop SparseSpatialMap from running。Can resume running by calling start().
    /// </summary>
    void stop();
    /// <summary>
    /// Close SparseSpatialMap. SparseSpatialMap can no longer be used.
    /// </summary>
    void close();
    /// <summary>
    /// Returns the buffer of point cloud coordinate. Each 3D point is represented by three consecutive values, representing X, Y, Z position coordinates in the world coordinate space, each of which takes 4 bytes.
    /// </summary>
    std::shared_ptr<Buffer> getPointCloudBuffer();
    /// <summary>
    /// Returns detected planes in SparseSpatialMap.
    /// </summary>
    std::vector<std::shared_ptr<PlaneData>> getMapPlanes();
    /// <summary>
    /// Perform hit test against the point cloud. The results are returned sorted by their distance to the camera in ascending order.
    /// </summary>
    std::vector<Vec3F> hitTestAgainstPointCloud(Vec2F cameraImagePoint);
    /// <summary>
    /// Performs ray cast from the user&#39;s device in the direction of given screen point.
    /// Intersections with detected planes are returned. 3D positions on physical planes are sorted by distance from the device in ascending order.
    /// For the camera image coordinate system ([0, 1]^2), x-right, y-down, and origin is at left-top corner. `CameraParameters.imageCoordinatesFromScreenCoordinates`_ can be used to convert points from screen coordinate system to camera image coordinate system.
    /// The output point cloud coordinate is in the world coordinate system.
    /// </summary>
    std::vector<Vec3F> hitTestAgainstPlanes(Vec2F cameraImagePoint);
    /// <summary>
    /// Get the map data version of the current SparseSpatialMap.
    /// </summary>
    static std::string getMapVersion();
    /// <summary>
    /// UnloadMap specified SparseSpatialMap data via callback function.The return value of callback indicates whether unload map succeeds (true) or fails (false).
    /// </summary>
    void unloadMap(std::string mapID, std::shared_ptr<CallbackScheduler> callbackScheduler, std::optional<std::function<void(bool)>> resultCallBack);
    /// <summary>
    /// Set configurations for SparseSpatialMap. See also `SparseSpatialMapConfig`_.
    /// </summary>
    void setConfig(std::shared_ptr<SparseSpatialMapConfig> config);
    /// <summary>
    /// Returns configurations for SparseSpatialMap. See also `SparseSpatialMapConfig`_.
    /// </summary>
    std::shared_ptr<SparseSpatialMapConfig> getConfig();
    /// <summary>
    /// Start localization in loaded maps. Should set `LocalizationMode`_ first.
    /// </summary>
    bool startLocalization();
    /// <summary>
    /// Stop localization in loaded maps.
    /// </summary>
    void stopLocalization();
    /// <summary>
    /// Get synchronized result. If SparseSpatialMap is paused, or the result async mode is not set to false through setResultAsyncMode, the return value is empty.
    /// </summary>
    std::optional<std::shared_ptr<SparseSpatialMapResult>> getSyncResult(std::shared_ptr<MotionInputData> motionInputData);
};

/// <summary>
/// SparseSpatialMap manager class, for managing sharing.
/// </summary>
class SparseSpatialMapManager
{
protected:
    std::shared_ptr<easyar_SparseSpatialMapManager> cdata_;
    void init_cdata(std::shared_ptr<easyar_SparseSpatialMapManager> cdata);
    SparseSpatialMapManager & operator=(const SparseSpatialMapManager & data) = delete;
public:
    SparseSpatialMapManager(std::shared_ptr<easyar_SparseSpatialMapManager> cdata);
    virtual ~SparseSpatialMapManager();

    std::shared_ptr<easyar_SparseSpatialMapManager> get_cdata();
    static std::shared_ptr<SparseSpatialMapManager> from_cdata(std::shared_ptr<easyar_SparseSpatialMapManager> cdata);

    /// <summary>
    /// Check whether SparseSpatialMapManager is is available. It returns true when the operating system is Windows, Mac, iOS or Android.
    /// </summary>
    static bool isAvailable();
    /// <summary>
    /// Creates an instance.
    /// </summary>
    static std::shared_ptr<SparseSpatialMapManager> create();
    /// <summary>
    /// Creates a map from `SparseSpatialMap`_ and upload it to EasyAR cloud servers. After completion, a serverMapId will be returned for loading map from EasyAR cloud servers.
    /// </summary>
    void host(std::shared_ptr<SparseSpatialMap> mapBuilder, std::string apiKey, std::string apiSecret, std::string sparseSpatialMapAppId, std::string name, std::optional<std::shared_ptr<Image>> preview, std::optional<int> timeoutMilliseconds, std::shared_ptr<CallbackScheduler> callbackScheduler, std::function<void(bool, std::string, std::string)> onCompleted);
    /// <summary>
    /// Loads a map from EasyAR cloud servers by serverMapId. To unload the map, call `SparseSpatialMap.unloadMap`_ with serverMapId.
    /// </summary>
    void load(std::shared_ptr<SparseSpatialMap> mapTracker, std::string serverMapId, std::string apiKey, std::string apiSecret, std::string sparseSpatialMapAppId, std::optional<int> timeoutMilliseconds, std::shared_ptr<CallbackScheduler> callbackScheduler, std::function<void(bool, std::string)> onCompleted);
    /// <summary>
    /// Clears allocated cache space.
    /// </summary>
    void clear();
};

class Engine
{
public:
    /// <summary>
    /// Gets the version schema hash, which can be used to ensure type declarations consistent with runtime library.
    /// </summary>
    static int schemaHash();
    static bool initialize(std::string licenseKey);
    /// <summary>
    /// Handles the app onPause, pauses internal tasks.
    /// </summary>
    static void onPause();
    /// <summary>
    /// Handles the app onResume, resumes internal tasks.
    /// </summary>
    static void onResume();
    /// <summary>
    /// Gets license validation state.
    /// </summary>
    static ValidationState validationState();
    /// <summary>
    /// Gets error message on initialization failure.
    /// </summary>
    static std::string errorMessage();
    /// <summary>
    /// Gets the version number of EasyARSense.
    /// </summary>
    static std::string versionString();
    /// <summary>
    /// Gets the product name of EasyARSense. (Including variant, operating system and CPU architecture.)
    /// </summary>
    static std::string name();
    /// <summary>
    /// Gets the release variant of EasyARSense.
    /// </summary>
    static std::string variant();
    /// <summary>
    /// Checks whether the license key matches the provided release variant, package name(or bundle id) and operating system.
    /// </summary>
    static bool isLicenseKeyMatched(std::string licenseKey, std::string packageName, std::string variant, EngineOperatingSystem operatingSystem);
    /// <summary>
    /// Enable eyewear support.
    /// </summary>
    static void enableEyewearSupport();
};

/// <summary>
/// VideoPlayer is the class for video playback.
/// EasyAR supports normal videos, transparent videos and streaming videos. The video content will be rendered into a texture passed into the player through setRenderTexture.
/// This class only supports OpenGLES 3.0 texture.
/// Due to the dependency to OpenGLES, every method in this class (including the destructor) has to be called in a single thread containing an OpenGLES context.
/// Current version requires width and height being mutiples of 16.
///
/// Supported video file formats
/// Windows: Media Foundation-compatible formats, more can be supported via extra codecs. Please refer to `Supported Media Formats in Media Foundation &lt;https://docs.microsoft.com/en-us/windows/win32/medfound/supported-media-formats-in-media-foundation&gt;`__ . DirectShow is not supported.
/// Mac: Not supported.
/// Android: System supported formats. Please refer to `Supported media formats &lt;https://developer.android.com/guide/topics/media/media-formats&gt;`__ .
/// iOS: System supported formats. There is no reference in effect currently.
/// </summary>
class VideoPlayer
{
protected:
    std::shared_ptr<easyar_VideoPlayer> cdata_;
    void init_cdata(std::shared_ptr<easyar_VideoPlayer> cdata);
    VideoPlayer & operator=(const VideoPlayer & data) = delete;
public:
    VideoPlayer(std::shared_ptr<easyar_VideoPlayer> cdata);
    virtual ~VideoPlayer();

    std::shared_ptr<easyar_VideoPlayer> get_cdata();
    static std::shared_ptr<VideoPlayer> from_cdata(std::shared_ptr<easyar_VideoPlayer> cdata);

    VideoPlayer();
    /// <summary>
    /// Checks if the component is available. It returns true only on Windows, Android or iOS. It&#39;s not available on Mac.
    /// </summary>
    static bool isAvailable();
    /// <summary>
    /// Sets the video type. The type will default to normal video if not set manually. It should be called before open.
    /// </summary>
    void setVideoType(VideoType videoType);
    /// <summary>
    /// Passes the texture to display video into player. It should be set before open.
    /// </summary>
    void setRenderTexture(std::shared_ptr<TextureId> texture);
    /// <summary>
    /// Opens a video from path.
    /// path can be a local video file (path/to/video.mp4) or url (http://www.../.../video.mp4). storageType indicates the type of path. See `StorageType`_ for more description.
    /// This method is an asynchronous method. Open may take some time to finish. If you want to know the open result or the play status while playing, you have to handle callback. The callback will be called from a different thread. You can check if the open finished successfully and start play after a successful open.
    /// </summary>
    void open(std::string path, StorageType storageType, std::shared_ptr<CallbackScheduler> callbackScheduler, std::optional<std::function<void(VideoStatus)>> callback);
    /// <summary>
    /// Closes the video.
    /// </summary>
    void close();
    /// <summary>
    /// Starts or continues to play video.
    /// </summary>
    bool play();
    /// <summary>
    /// Stops the video playback.
    /// </summary>
    void stop();
    /// <summary>
    /// Pauses the video playback.
    /// </summary>
    void pause();
    /// <summary>
    /// Checks whether video texture is ready for render. Use this to check if texture passed into the player has been touched.
    /// </summary>
    bool isRenderTextureAvailable();
    /// <summary>
    /// Updates texture data. This should be called in the renderer thread when isRenderTextureAvailable returns true.
    /// </summary>
    void updateFrame();
    /// <summary>
    /// Returns the video duration. Use after a successful open.
    /// </summary>
    int duration();
    /// <summary>
    /// Returns the current position of video. Use after a successful open.
    /// </summary>
    int currentPosition();
    /// <summary>
    /// Seeks to play to position . Use after a successful open.
    /// </summary>
    bool seek(int position);
    /// <summary>
    /// Returns the video size. Use after a successful open.
    /// </summary>
    Vec2I size();
    /// <summary>
    /// Returns current volume. Use after a successful open.
    /// </summary>
    float volume();
    /// <summary>
    /// Sets volume of the video. Use after a successful open.
    /// </summary>
    bool setVolume(float volume);
};

/// <summary>
/// Camera parameters, including image size, focal length, principal point, camera type and camera rotation against natural orientation.
/// </summary>
class CameraParameters
{
protected:
    std::shared_ptr<easyar_CameraParameters> cdata_;
    void init_cdata(std::shared_ptr<easyar_CameraParameters> cdata);
    CameraParameters & operator=(const CameraParameters & data) = delete;
public:
    CameraParameters(std::shared_ptr<easyar_CameraParameters> cdata);
    virtual ~CameraParameters();

    std::shared_ptr<easyar_CameraParameters> get_cdata();
    static std::shared_ptr<CameraParameters> from_cdata(std::shared_ptr<easyar_CameraParameters> cdata);

    CameraParameters(Vec2I imageSize, Vec2F focalLength, Vec2F principalPoint, CameraDeviceType cameraDeviceType, int cameraOrientation);
    /// <summary>
    /// Image size.
    /// </summary>
    Vec2I size();
    /// <summary>
    /// Focal length, the distance from effective optical center to CCD plane, divided by unit pixel density in width and height directions. The unit is pixel.
    /// </summary>
    Vec2F focalLength();
    /// <summary>
    /// Principal point, coordinates of the intersection point of principal axis on CCD plane against the left-top corner of the image. The unit is pixel.
    /// </summary>
    Vec2F principalPoint();
    /// <summary>
    /// Optics model camera used.
    /// </summary>
    CameraModelType cameraModelType();
    /// <summary>
    /// Camera device type. Default, back or front camera. On desktop devices, there are only default cameras. On mobile devices, there is a differentiation between back and front cameras.
    /// </summary>
    CameraDeviceType cameraDeviceType();
    /// <summary>
    /// Angles rotation required to rotate clockwise and display camera image on device with natural orientation. The range is [0, 360).
    /// For Android phones and some Android tablets, this value is 90 degrees.
    /// For Android eye-wear and some Android tablets, this value is 0 degrees.
    /// For all current iOS devices, this value is 90 degrees.
    /// </summary>
    int cameraOrientation();
    /// <summary>
    /// Creates CameraParameters with default camera intrinsics. Default intrinsics are calculated by image size, which is not very precise.
    /// </summary>
    static std::shared_ptr<CameraParameters> createWithDefaultIntrinsics(Vec2I imageSize, CameraDeviceType cameraDeviceType, int cameraOrientation);
    /// <summary>
    /// Creates CameraParameters with custom camera intrinsics. Refer to CameraModelType to see the support of different camera models.
    /// Note: Use this interface with caution. Incorrect input data may cause a fail, resulting in a null return.&quot;
    /// </summary>
    static std::optional<std::shared_ptr<CameraParameters>> tryCreateWithCustomIntrinsics(Vec2I imageSize, std::vector<float> cameraParamList, CameraModelType cameraModel, CameraDeviceType cameraDeviceType, int cameraOrientation);
    /// <summary>
    /// Get equivalent CameraParameters for a different camera image size.
    /// </summary>
    std::shared_ptr<CameraParameters> getResized(Vec2I imageSize);
    /// <summary>
    /// Calculates the angle required to rotate the camera image clockwise to align it with the screen.
    /// screenRotation is the angle of rotation of displaying screen image against device natural orientation in clockwise in degrees.
    /// For iOS(UIInterfaceOrientationPortrait as natural orientation):
    /// * UIInterfaceOrientationPortrait: rotation = 0
    /// * UIInterfaceOrientationLandscapeRight: rotation = 90
    /// * UIInterfaceOrientationPortraitUpsideDown: rotation = 180
    /// * UIInterfaceOrientationLandscapeLeft: rotation = 270
    /// For Android:
    /// * Surface.ROTATION_0 = 0
    /// * Surface.ROTATION_90 = 90
    /// * Surface.ROTATION_180 = 180
    /// * Surface.ROTATION_270 = 270
    /// </summary>
    int imageOrientation(int screenRotation);
    /// <summary>
    /// Calculates whether the image needed to be flipped horizontally. The image is rotated, then flipped in rendering. When cameraDeviceType is front, a flip is automatically applied. Pass manualHorizontalFlip with true to add a manual flip.
    /// </summary>
    bool imageHorizontalFlip(bool manualHorizontalFlip);
    /// <summary>
    /// Calculates the perspective projection matrix needed by virtual object rendering. The projection transforms points from camera coordinate system to clip coordinate system ([-1, 1]^4)  (including rotation around z-axis). The form of perspective projection matrix is the same as OpenGL, that matrix multiply column vector of homogeneous coordinates of point on the right, ant not like Direct3D, that matrix multiply row vector of homogeneous coordinates of point on the left. But data arrangement is row-major, not like OpenGL&#39;s column-major. Clip coordinate system and normalized device coordinate system are defined as the same as OpenGL&#39;s default.
    /// </summary>
    Matrix44F projection(float nearPlane, float farPlane, float viewportAspectRatio, int screenRotation, bool combiningFlip, bool manualHorizontalFlip);
    /// <summary>
    /// Calculates the orthogonal projection matrix needed by camera background rendering. The projection transforms points from image quad coordinate system ([-1, 1]^2) to clip coordinate system ([-1, 1]^4) (including rotation around z-axis), with the undefined two dimensions unchanged. The form of orthogonal projection matrix is the same as OpenGL, that matrix multiply column vector of homogeneous coordinates of point on the right, ant not like Direct3D, that matrix multiply row vector of homogeneous coordinates of point on the left. But data arrangement is row-major, not like OpenGL&#39;s column-major. Clip coordinate system and normalized device coordinate system are defined as the same as OpenGL&#39;s default.
    /// </summary>
    Matrix44F imageProjection(float viewportAspectRatio, int screenRotation, bool combiningFlip, bool manualHorizontalFlip);
    /// <summary>
    /// Transforms points from image coordinate system ([0, 1]^2) to screen coordinate system ([0, 1]^2). Both coordinate system is x-left, y-down, with origin at left-top.
    /// </summary>
    Vec2F screenCoordinatesFromImageCoordinates(float viewportAspectRatio, int screenRotation, bool combiningFlip, bool manualHorizontalFlip, Vec2F imageCoordinates);
    /// <summary>
    /// Transforms points from screen coordinate system ([0, 1]^2) to image coordinate system ([0, 1]^2). Both coordinate system is x-left, y-down, with origin at left-top.
    /// </summary>
    Vec2F imageCoordinatesFromScreenCoordinates(float viewportAspectRatio, int screenRotation, bool combiningFlip, bool manualHorizontalFlip, Vec2F screenCoordinates);
    /// <summary>
    /// Checks if two groups of parameters are equal.
    /// </summary>
    bool equalsTo(std::shared_ptr<CameraParameters> other);
};

/// <summary>
/// Signal input port.
/// It is used to expose input port for a component.
/// All members of this class is thread-safe.
/// </summary>
class SignalSink
{
protected:
    std::shared_ptr<easyar_SignalSink> cdata_;
    void init_cdata(std::shared_ptr<easyar_SignalSink> cdata);
    SignalSink & operator=(const SignalSink & data) = delete;
public:
    SignalSink(std::shared_ptr<easyar_SignalSink> cdata);
    virtual ~SignalSink();

    std::shared_ptr<easyar_SignalSink> get_cdata();
    static std::shared_ptr<SignalSink> from_cdata(std::shared_ptr<easyar_SignalSink> cdata);

    /// <summary>
    /// Input data.
    /// </summary>
    void handle();
};

/// <summary>
/// Signal output port.
/// It is used to expose output port for a component.
/// All members of this class is thread-safe.
/// </summary>
class SignalSource
{
protected:
    std::shared_ptr<easyar_SignalSource> cdata_;
    void init_cdata(std::shared_ptr<easyar_SignalSource> cdata);
    SignalSource & operator=(const SignalSource & data) = delete;
public:
    SignalSource(std::shared_ptr<easyar_SignalSource> cdata);
    virtual ~SignalSource();

    std::shared_ptr<easyar_SignalSource> get_cdata();
    static std::shared_ptr<SignalSource> from_cdata(std::shared_ptr<easyar_SignalSource> cdata);

    /// <summary>
    /// Sets data handler.
    /// </summary>
    void setHandler(std::optional<std::function<void()>> handler);
    /// <summary>
    /// Connects to input port.
    /// </summary>
    void connect(std::shared_ptr<SignalSink> sink);
    /// <summary>
    /// Disconnects.
    /// </summary>
    void disconnect();
};

/// <summary>
/// Accelerometer result input port.
/// It is used to expose input port for a component.
/// All members of this class is thread-safe.
/// </summary>
class AccelerometerResultSink
{
protected:
    std::shared_ptr<easyar_AccelerometerResultSink> cdata_;
    void init_cdata(std::shared_ptr<easyar_AccelerometerResultSink> cdata);
    AccelerometerResultSink & operator=(const AccelerometerResultSink & data) = delete;
public:
    AccelerometerResultSink(std::shared_ptr<easyar_AccelerometerResultSink> cdata);
    virtual ~AccelerometerResultSink();

    std::shared_ptr<easyar_AccelerometerResultSink> get_cdata();
    static std::shared_ptr<AccelerometerResultSink> from_cdata(std::shared_ptr<easyar_AccelerometerResultSink> cdata);

    /// <summary>
    /// Input data.
    /// </summary>
    void handle(AccelerometerResult inputData);
};

/// <summary>
/// Accelerometer result output port.
/// It is used to expose output port for a component.
/// All members of this class is thread-safe.
/// </summary>
class AccelerometerResultSource
{
protected:
    std::shared_ptr<easyar_AccelerometerResultSource> cdata_;
    void init_cdata(std::shared_ptr<easyar_AccelerometerResultSource> cdata);
    AccelerometerResultSource & operator=(const AccelerometerResultSource & data) = delete;
public:
    AccelerometerResultSource(std::shared_ptr<easyar_AccelerometerResultSource> cdata);
    virtual ~AccelerometerResultSource();

    std::shared_ptr<easyar_AccelerometerResultSource> get_cdata();
    static std::shared_ptr<AccelerometerResultSource> from_cdata(std::shared_ptr<easyar_AccelerometerResultSource> cdata);

    /// <summary>
    /// Sets data handler.
    /// </summary>
    void setHandler(std::optional<std::function<void(AccelerometerResult)>> handler);
    /// <summary>
    /// Connects to input port.
    /// </summary>
    void connect(std::shared_ptr<AccelerometerResultSink> sink);
    /// <summary>
    /// Disconnects.
    /// </summary>
    void disconnect();
};

/// <summary>
/// Gyroscope result input port.
/// It is used to expose input port for a component.
/// All members of this class is thread-safe.
/// </summary>
class GyroscopeResultSink
{
protected:
    std::shared_ptr<easyar_GyroscopeResultSink> cdata_;
    void init_cdata(std::shared_ptr<easyar_GyroscopeResultSink> cdata);
    GyroscopeResultSink & operator=(const GyroscopeResultSink & data) = delete;
public:
    GyroscopeResultSink(std::shared_ptr<easyar_GyroscopeResultSink> cdata);
    virtual ~GyroscopeResultSink();

    std::shared_ptr<easyar_GyroscopeResultSink> get_cdata();
    static std::shared_ptr<GyroscopeResultSink> from_cdata(std::shared_ptr<easyar_GyroscopeResultSink> cdata);

    /// <summary>
    /// Input data.
    /// </summary>
    void handle(GyroscopeResult inputData);
};

/// <summary>
/// Gyroscope result output port.
/// It is used to expose output port for a component.
/// All members of this class is thread-safe.
/// </summary>
class GyroscopeResultSource
{
protected:
    std::shared_ptr<easyar_GyroscopeResultSource> cdata_;
    void init_cdata(std::shared_ptr<easyar_GyroscopeResultSource> cdata);
    GyroscopeResultSource & operator=(const GyroscopeResultSource & data) = delete;
public:
    GyroscopeResultSource(std::shared_ptr<easyar_GyroscopeResultSource> cdata);
    virtual ~GyroscopeResultSource();

    std::shared_ptr<easyar_GyroscopeResultSource> get_cdata();
    static std::shared_ptr<GyroscopeResultSource> from_cdata(std::shared_ptr<easyar_GyroscopeResultSource> cdata);

    /// <summary>
    /// Sets data handler.
    /// </summary>
    void setHandler(std::optional<std::function<void(GyroscopeResult)>> handler);
    /// <summary>
    /// Connects to input port.
    /// </summary>
    void connect(std::shared_ptr<GyroscopeResultSink> sink);
    /// <summary>
    /// Disconnects.
    /// </summary>
    void disconnect();
};

/// <summary>
/// Attitude sensor result input port.
/// It is used to expose input port for a component.
/// All members of this class is thread-safe.
/// </summary>
class AttitudeSensorResultSink
{
protected:
    std::shared_ptr<easyar_AttitudeSensorResultSink> cdata_;
    void init_cdata(std::shared_ptr<easyar_AttitudeSensorResultSink> cdata);
    AttitudeSensorResultSink & operator=(const AttitudeSensorResultSink & data) = delete;
public:
    AttitudeSensorResultSink(std::shared_ptr<easyar_AttitudeSensorResultSink> cdata);
    virtual ~AttitudeSensorResultSink();

    std::shared_ptr<easyar_AttitudeSensorResultSink> get_cdata();
    static std::shared_ptr<AttitudeSensorResultSink> from_cdata(std::shared_ptr<easyar_AttitudeSensorResultSink> cdata);

    /// <summary>
    /// Input data.
    /// </summary>
    void handle(AttitudeSensorResult inputData);
};

/// <summary>
/// Attitude sensor result output port.
/// It is used to expose output port for a component.
/// All members of this class is thread-safe.
/// </summary>
class AttitudeSensorResultSource
{
protected:
    std::shared_ptr<easyar_AttitudeSensorResultSource> cdata_;
    void init_cdata(std::shared_ptr<easyar_AttitudeSensorResultSource> cdata);
    AttitudeSensorResultSource & operator=(const AttitudeSensorResultSource & data) = delete;
public:
    AttitudeSensorResultSource(std::shared_ptr<easyar_AttitudeSensorResultSource> cdata);
    virtual ~AttitudeSensorResultSource();

    std::shared_ptr<easyar_AttitudeSensorResultSource> get_cdata();
    static std::shared_ptr<AttitudeSensorResultSource> from_cdata(std::shared_ptr<easyar_AttitudeSensorResultSource> cdata);

    /// <summary>
    /// Sets data handler.
    /// </summary>
    void setHandler(std::optional<std::function<void(AttitudeSensorResult)>> handler);
    /// <summary>
    /// Connects to input port.
    /// </summary>
    void connect(std::shared_ptr<AttitudeSensorResultSink> sink);
    /// <summary>
    /// Disconnects.
    /// </summary>
    void disconnect();
};

/// <summary>
/// Magnetometer result input port.
/// It is used to expose input port for a component.
/// All members of this class is thread-safe.
/// </summary>
class MagnetometerResultSink
{
protected:
    std::shared_ptr<easyar_MagnetometerResultSink> cdata_;
    void init_cdata(std::shared_ptr<easyar_MagnetometerResultSink> cdata);
    MagnetometerResultSink & operator=(const MagnetometerResultSink & data) = delete;
public:
    MagnetometerResultSink(std::shared_ptr<easyar_MagnetometerResultSink> cdata);
    virtual ~MagnetometerResultSink();

    std::shared_ptr<easyar_MagnetometerResultSink> get_cdata();
    static std::shared_ptr<MagnetometerResultSink> from_cdata(std::shared_ptr<easyar_MagnetometerResultSink> cdata);

    /// <summary>
    /// Input data.
    /// </summary>
    void handle(MagnetometerResult inputData);
};

/// <summary>
/// Magnetometer result output port.
/// It is used to expose output port for a component.
/// All members of this class is thread-safe.
/// </summary>
class MagnetometerResultSource
{
protected:
    std::shared_ptr<easyar_MagnetometerResultSource> cdata_;
    void init_cdata(std::shared_ptr<easyar_MagnetometerResultSource> cdata);
    MagnetometerResultSource & operator=(const MagnetometerResultSource & data) = delete;
public:
    MagnetometerResultSource(std::shared_ptr<easyar_MagnetometerResultSource> cdata);
    virtual ~MagnetometerResultSource();

    std::shared_ptr<easyar_MagnetometerResultSource> get_cdata();
    static std::shared_ptr<MagnetometerResultSource> from_cdata(std::shared_ptr<easyar_MagnetometerResultSource> cdata);

    /// <summary>
    /// Sets data handler.
    /// </summary>
    void setHandler(std::optional<std::function<void(MagnetometerResult)>> handler);
    /// <summary>
    /// Connects to input port.
    /// </summary>
    void connect(std::shared_ptr<MagnetometerResultSink> sink);
    /// <summary>
    /// Disconnects.
    /// </summary>
    void disconnect();
};

/// <summary>
/// Location result input port.
/// It is used to expose input port for a component.
/// All members of this class is thread-safe.
/// </summary>
class LocationResultSink
{
protected:
    std::shared_ptr<easyar_LocationResultSink> cdata_;
    void init_cdata(std::shared_ptr<easyar_LocationResultSink> cdata);
    LocationResultSink & operator=(const LocationResultSink & data) = delete;
public:
    LocationResultSink(std::shared_ptr<easyar_LocationResultSink> cdata);
    virtual ~LocationResultSink();

    std::shared_ptr<easyar_LocationResultSink> get_cdata();
    static std::shared_ptr<LocationResultSink> from_cdata(std::shared_ptr<easyar_LocationResultSink> cdata);

    /// <summary>
    /// Input data.
    /// </summary>
    void handle(LocationResult inputData);
};

/// <summary>
/// Location result output port.
/// It is used to expose output port for a component.
/// All members of this class is thread-safe.
/// </summary>
class LocationResultSource
{
protected:
    std::shared_ptr<easyar_LocationResultSource> cdata_;
    void init_cdata(std::shared_ptr<easyar_LocationResultSource> cdata);
    LocationResultSource & operator=(const LocationResultSource & data) = delete;
public:
    LocationResultSource(std::shared_ptr<easyar_LocationResultSource> cdata);
    virtual ~LocationResultSource();

    std::shared_ptr<easyar_LocationResultSource> get_cdata();
    static std::shared_ptr<LocationResultSource> from_cdata(std::shared_ptr<easyar_LocationResultSource> cdata);

    /// <summary>
    /// Sets data handler.
    /// </summary>
    void setHandler(std::optional<std::function<void(LocationResult)>> handler);
    /// <summary>
    /// Connects to input port.
    /// </summary>
    void connect(std::shared_ptr<LocationResultSink> sink);
    /// <summary>
    /// Disconnects.
    /// </summary>
    void disconnect();
};

/// <summary>
/// Proximity location result input port.
/// It is used to expose input port for a component.
/// All members of this class is thread-safe.
/// </summary>
class ProximityLocationResultSink
{
protected:
    std::shared_ptr<easyar_ProximityLocationResultSink> cdata_;
    void init_cdata(std::shared_ptr<easyar_ProximityLocationResultSink> cdata);
    ProximityLocationResultSink & operator=(const ProximityLocationResultSink & data) = delete;
public:
    ProximityLocationResultSink(std::shared_ptr<easyar_ProximityLocationResultSink> cdata);
    virtual ~ProximityLocationResultSink();

    std::shared_ptr<easyar_ProximityLocationResultSink> get_cdata();
    static std::shared_ptr<ProximityLocationResultSink> from_cdata(std::shared_ptr<easyar_ProximityLocationResultSink> cdata);

    /// <summary>
    /// Input data.
    /// </summary>
    void handle(ProximityLocationResult inputData);
};

/// <summary>
/// Proximity location result output port.
/// It is used to expose output port for a component.
/// All members of this class is thread-safe.
/// </summary>
class ProximityLocationResultSource
{
protected:
    std::shared_ptr<easyar_ProximityLocationResultSource> cdata_;
    void init_cdata(std::shared_ptr<easyar_ProximityLocationResultSource> cdata);
    ProximityLocationResultSource & operator=(const ProximityLocationResultSource & data) = delete;
public:
    ProximityLocationResultSource(std::shared_ptr<easyar_ProximityLocationResultSource> cdata);
    virtual ~ProximityLocationResultSource();

    std::shared_ptr<easyar_ProximityLocationResultSource> get_cdata();
    static std::shared_ptr<ProximityLocationResultSource> from_cdata(std::shared_ptr<easyar_ProximityLocationResultSource> cdata);

    /// <summary>
    /// Sets data handler.
    /// </summary>
    void setHandler(std::optional<std::function<void(ProximityLocationResult)>> handler);
    /// <summary>
    /// Connects to input port.
    /// </summary>
    void connect(std::shared_ptr<ProximityLocationResultSink> sink);
    /// <summary>
    /// Disconnects.
    /// </summary>
    void disconnect();
};

/// <summary>
/// Input frame input port.
/// It is used to expose input port for a component.
/// All members of this class is thread-safe.
/// </summary>
class InputFrameSink
{
protected:
    std::shared_ptr<easyar_InputFrameSink> cdata_;
    void init_cdata(std::shared_ptr<easyar_InputFrameSink> cdata);
    InputFrameSink & operator=(const InputFrameSink & data) = delete;
public:
    InputFrameSink(std::shared_ptr<easyar_InputFrameSink> cdata);
    virtual ~InputFrameSink();

    std::shared_ptr<easyar_InputFrameSink> get_cdata();
    static std::shared_ptr<InputFrameSink> from_cdata(std::shared_ptr<easyar_InputFrameSink> cdata);

    /// <summary>
    /// Input data.
    /// </summary>
    void handle(std::shared_ptr<InputFrame> inputData);
};

/// <summary>
/// Input frame output port.
/// It is used to expose output port for a component.
/// All members of this class is thread-safe.
/// </summary>
class InputFrameSource
{
protected:
    std::shared_ptr<easyar_InputFrameSource> cdata_;
    void init_cdata(std::shared_ptr<easyar_InputFrameSource> cdata);
    InputFrameSource & operator=(const InputFrameSource & data) = delete;
public:
    InputFrameSource(std::shared_ptr<easyar_InputFrameSource> cdata);
    virtual ~InputFrameSource();

    std::shared_ptr<easyar_InputFrameSource> get_cdata();
    static std::shared_ptr<InputFrameSource> from_cdata(std::shared_ptr<easyar_InputFrameSource> cdata);

    /// <summary>
    /// Sets data handler.
    /// </summary>
    void setHandler(std::optional<std::function<void(std::shared_ptr<InputFrame>)>> handler);
    /// <summary>
    /// Connects to input port.
    /// </summary>
    void connect(std::shared_ptr<InputFrameSink> sink);
    /// <summary>
    /// Disconnects.
    /// </summary>
    void disconnect();
};

/// <summary>
/// Output frame input port.
/// It is used to expose input port for a component.
/// All members of this class is thread-safe.
/// </summary>
class OutputFrameSink
{
protected:
    std::shared_ptr<easyar_OutputFrameSink> cdata_;
    void init_cdata(std::shared_ptr<easyar_OutputFrameSink> cdata);
    OutputFrameSink & operator=(const OutputFrameSink & data) = delete;
public:
    OutputFrameSink(std::shared_ptr<easyar_OutputFrameSink> cdata);
    virtual ~OutputFrameSink();

    std::shared_ptr<easyar_OutputFrameSink> get_cdata();
    static std::shared_ptr<OutputFrameSink> from_cdata(std::shared_ptr<easyar_OutputFrameSink> cdata);

    /// <summary>
    /// Input data.
    /// </summary>
    void handle(std::shared_ptr<OutputFrame> inputData);
};

/// <summary>
/// Output frame output port.
/// It is used to expose output port for a component.
/// All members of this class is thread-safe.
/// </summary>
class OutputFrameSource
{
protected:
    std::shared_ptr<easyar_OutputFrameSource> cdata_;
    void init_cdata(std::shared_ptr<easyar_OutputFrameSource> cdata);
    OutputFrameSource & operator=(const OutputFrameSource & data) = delete;
public:
    OutputFrameSource(std::shared_ptr<easyar_OutputFrameSource> cdata);
    virtual ~OutputFrameSource();

    std::shared_ptr<easyar_OutputFrameSource> get_cdata();
    static std::shared_ptr<OutputFrameSource> from_cdata(std::shared_ptr<easyar_OutputFrameSource> cdata);

    /// <summary>
    /// Sets data handler.
    /// </summary>
    void setHandler(std::optional<std::function<void(std::shared_ptr<OutputFrame>)>> handler);
    /// <summary>
    /// Connects to input port.
    /// </summary>
    void connect(std::shared_ptr<OutputFrameSink> sink);
    /// <summary>
    /// Disconnects.
    /// </summary>
    void disconnect();
};

/// <summary>
/// Feedback frame input port.
/// It is used to expose input port for a component.
/// All members of this class is thread-safe.
/// </summary>
class FeedbackFrameSink
{
protected:
    std::shared_ptr<easyar_FeedbackFrameSink> cdata_;
    void init_cdata(std::shared_ptr<easyar_FeedbackFrameSink> cdata);
    FeedbackFrameSink & operator=(const FeedbackFrameSink & data) = delete;
public:
    FeedbackFrameSink(std::shared_ptr<easyar_FeedbackFrameSink> cdata);
    virtual ~FeedbackFrameSink();

    std::shared_ptr<easyar_FeedbackFrameSink> get_cdata();
    static std::shared_ptr<FeedbackFrameSink> from_cdata(std::shared_ptr<easyar_FeedbackFrameSink> cdata);

    /// <summary>
    /// Input data.
    /// </summary>
    void handle(std::shared_ptr<FeedbackFrame> inputData);
};

/// <summary>
/// Feedback frame output port.
/// It is used to expose output port for a component.
/// All members of this class is thread-safe.
/// </summary>
class FeedbackFrameSource
{
protected:
    std::shared_ptr<easyar_FeedbackFrameSource> cdata_;
    void init_cdata(std::shared_ptr<easyar_FeedbackFrameSource> cdata);
    FeedbackFrameSource & operator=(const FeedbackFrameSource & data) = delete;
public:
    FeedbackFrameSource(std::shared_ptr<easyar_FeedbackFrameSource> cdata);
    virtual ~FeedbackFrameSource();

    std::shared_ptr<easyar_FeedbackFrameSource> get_cdata();
    static std::shared_ptr<FeedbackFrameSource> from_cdata(std::shared_ptr<easyar_FeedbackFrameSource> cdata);

    /// <summary>
    /// Sets data handler.
    /// </summary>
    void setHandler(std::optional<std::function<void(std::shared_ptr<FeedbackFrame>)>> handler);
    /// <summary>
    /// Connects to input port.
    /// </summary>
    void connect(std::shared_ptr<FeedbackFrameSink> sink);
    /// <summary>
    /// Disconnects.
    /// </summary>
    void disconnect();
};

/// <summary>
/// Input frame fork.
/// It is used to branch and transfer input frame to multiple components in parallel.
/// All members of this class is thread-safe.
/// </summary>
class InputFrameFork
{
protected:
    std::shared_ptr<easyar_InputFrameFork> cdata_;
    void init_cdata(std::shared_ptr<easyar_InputFrameFork> cdata);
    InputFrameFork & operator=(const InputFrameFork & data) = delete;
public:
    InputFrameFork(std::shared_ptr<easyar_InputFrameFork> cdata);
    virtual ~InputFrameFork();

    std::shared_ptr<easyar_InputFrameFork> get_cdata();
    static std::shared_ptr<InputFrameFork> from_cdata(std::shared_ptr<easyar_InputFrameFork> cdata);

    /// <summary>
    /// Input port.
    /// </summary>
    std::shared_ptr<InputFrameSink> input();
    /// <summary>
    /// Output port.
    /// </summary>
    std::shared_ptr<InputFrameSource> output(int index);
    /// <summary>
    /// Output count.
    /// </summary>
    int outputCount();
    /// <summary>
    /// Creates an instance.
    /// </summary>
    static std::shared_ptr<InputFrameFork> create(int outputCount);
};

/// <summary>
/// Output frame fork.
/// It is used to branch and transfer output frame to multiple components in parallel.
/// All members of this class is thread-safe.
/// </summary>
class OutputFrameFork
{
protected:
    std::shared_ptr<easyar_OutputFrameFork> cdata_;
    void init_cdata(std::shared_ptr<easyar_OutputFrameFork> cdata);
    OutputFrameFork & operator=(const OutputFrameFork & data) = delete;
public:
    OutputFrameFork(std::shared_ptr<easyar_OutputFrameFork> cdata);
    virtual ~OutputFrameFork();

    std::shared_ptr<easyar_OutputFrameFork> get_cdata();
    static std::shared_ptr<OutputFrameFork> from_cdata(std::shared_ptr<easyar_OutputFrameFork> cdata);

    /// <summary>
    /// Input port.
    /// </summary>
    std::shared_ptr<OutputFrameSink> input();
    /// <summary>
    /// Output port.
    /// </summary>
    std::shared_ptr<OutputFrameSource> output(int index);
    /// <summary>
    /// Output count.
    /// </summary>
    int outputCount();
    /// <summary>
    /// Creates an instance.
    /// </summary>
    static std::shared_ptr<OutputFrameFork> create(int outputCount);
};

/// <summary>
/// Output frame join.
/// It is used to aggregate output frame from multiple components in parallel.
/// All members of this class is thread-safe.
/// It shall be noticed that connections and disconnections to the inputs shall not be performed during the flowing of data, or it may stuck in a state that no frame can be output. (It is recommended to complete dataflow connection before start a camera.)
/// </summary>
class OutputFrameJoin
{
protected:
    std::shared_ptr<easyar_OutputFrameJoin> cdata_;
    void init_cdata(std::shared_ptr<easyar_OutputFrameJoin> cdata);
    OutputFrameJoin & operator=(const OutputFrameJoin & data) = delete;
public:
    OutputFrameJoin(std::shared_ptr<easyar_OutputFrameJoin> cdata);
    virtual ~OutputFrameJoin();

    std::shared_ptr<easyar_OutputFrameJoin> get_cdata();
    static std::shared_ptr<OutputFrameJoin> from_cdata(std::shared_ptr<easyar_OutputFrameJoin> cdata);

    /// <summary>
    /// Input port.
    /// </summary>
    std::shared_ptr<OutputFrameSink> input(int index);
    /// <summary>
    /// Output port.
    /// </summary>
    std::shared_ptr<OutputFrameSource> output();
    /// <summary>
    /// Input count.
    /// </summary>
    int inputCount();
    /// <summary>
    /// Creates an instance. The default joiner will be used, which takes input frame from the first input and first result or null of each input. The first result of every input will be placed at the corresponding input index of results of the final output frame.
    /// </summary>
    static std::shared_ptr<OutputFrameJoin> create(int inputCount);
    /// <summary>
    /// Creates an instance. A custom joiner is specified.
    /// </summary>
    static std::shared_ptr<OutputFrameJoin> createWithJoiner(int inputCount, std::function<std::shared_ptr<OutputFrame>(std::vector<std::shared_ptr<OutputFrame>>)> joiner);
};

/// <summary>
/// Feedback frame fork.
/// It is used to branch and transfer feedback frame to multiple components in parallel.
/// All members of this class is thread-safe.
/// </summary>
class FeedbackFrameFork
{
protected:
    std::shared_ptr<easyar_FeedbackFrameFork> cdata_;
    void init_cdata(std::shared_ptr<easyar_FeedbackFrameFork> cdata);
    FeedbackFrameFork & operator=(const FeedbackFrameFork & data) = delete;
public:
    FeedbackFrameFork(std::shared_ptr<easyar_FeedbackFrameFork> cdata);
    virtual ~FeedbackFrameFork();

    std::shared_ptr<easyar_FeedbackFrameFork> get_cdata();
    static std::shared_ptr<FeedbackFrameFork> from_cdata(std::shared_ptr<easyar_FeedbackFrameFork> cdata);

    /// <summary>
    /// Input port.
    /// </summary>
    std::shared_ptr<FeedbackFrameSink> input();
    /// <summary>
    /// Output port.
    /// </summary>
    std::shared_ptr<FeedbackFrameSource> output(int index);
    /// <summary>
    /// Output count.
    /// </summary>
    int outputCount();
    /// <summary>
    /// Creates an instance.
    /// </summary>
    static std::shared_ptr<FeedbackFrameFork> create(int outputCount);
};

/// <summary>
/// Input frame throttler.
/// There is a input frame input port and a input frame output port. It can be used to prevent incoming frames from entering algorithm components when they have not finished handling previous workload.
/// InputFrameThrottler occupies one buffer of camera. Use setBufferCapacity of camera to set an amount of buffers that is not less than the sum of amount of buffers occupied by all components.
/// All members of this class is thread-safe.
/// It shall be noticed that connections and disconnections to signalInput shall not be performed during the flowing of data, or it may stuck in a state that no frame can be output. (It is recommended to complete dataflow connection before start a camera.)
/// </summary>
class InputFrameThrottler
{
protected:
    std::shared_ptr<easyar_InputFrameThrottler> cdata_;
    void init_cdata(std::shared_ptr<easyar_InputFrameThrottler> cdata);
    InputFrameThrottler & operator=(const InputFrameThrottler & data) = delete;
public:
    InputFrameThrottler(std::shared_ptr<easyar_InputFrameThrottler> cdata);
    virtual ~InputFrameThrottler();

    std::shared_ptr<easyar_InputFrameThrottler> get_cdata();
    static std::shared_ptr<InputFrameThrottler> from_cdata(std::shared_ptr<easyar_InputFrameThrottler> cdata);

    /// <summary>
    /// Input port.
    /// </summary>
    std::shared_ptr<InputFrameSink> input();
    /// <summary>
    /// Camera buffers occupied in this component.
    /// </summary>
    int bufferRequirement();
    /// <summary>
    /// Output port.
    /// </summary>
    std::shared_ptr<InputFrameSource> output();
    /// <summary>
    /// Input port for clearance signal.
    /// </summary>
    std::shared_ptr<SignalSink> signalInput();
    /// <summary>
    /// Creates an instance.
    /// </summary>
    static std::shared_ptr<InputFrameThrottler> create();
};

/// <summary>
/// Output frame buffer.
/// There is an output frame input port and output frame fetching function. It can be used to convert output frame fetching from asynchronous pattern to synchronous polling pattern, which fits frame by frame rendering.
/// OutputFrameBuffer occupies one buffer of camera. Use setBufferCapacity of camera to set an amount of buffers that is not less than the sum of amount of buffers occupied by all components.
/// All members of this class is thread-safe.
/// </summary>
class OutputFrameBuffer
{
protected:
    std::shared_ptr<easyar_OutputFrameBuffer> cdata_;
    void init_cdata(std::shared_ptr<easyar_OutputFrameBuffer> cdata);
    OutputFrameBuffer & operator=(const OutputFrameBuffer & data) = delete;
public:
    OutputFrameBuffer(std::shared_ptr<easyar_OutputFrameBuffer> cdata);
    virtual ~OutputFrameBuffer();

    std::shared_ptr<easyar_OutputFrameBuffer> get_cdata();
    static std::shared_ptr<OutputFrameBuffer> from_cdata(std::shared_ptr<easyar_OutputFrameBuffer> cdata);

    /// <summary>
    /// Input port.
    /// </summary>
    std::shared_ptr<OutputFrameSink> input();
    /// <summary>
    /// Camera buffers occupied in this component.
    /// </summary>
    int bufferRequirement();
    /// <summary>
    /// Output port for frame arrival. It can be connected to `InputFrameThrottler.signalInput`_ .
    /// </summary>
    std::shared_ptr<SignalSource> signalOutput();
    /// <summary>
    /// Fetches the most recent `OutputFrame`_ .
    /// </summary>
    std::optional<std::shared_ptr<OutputFrame>> peek();
    /// <summary>
    /// Creates an instance.
    /// </summary>
    static std::shared_ptr<OutputFrameBuffer> create();
    /// <summary>
    /// Pauses output of `OutputFrame`_ . After execution, all results of `OutputFrameBuffer.peek`_ will be empty. `OutputFrameBuffer.signalOutput`_  is not affected.
    /// </summary>
    void pause();
    /// <summary>
    /// Resumes output of `OutputFrame`_ .
    /// </summary>
    void resume();
};

/// <summary>
/// Input frame to output frame adapter.
/// There is an input frame input port and an output frame output port. It can be used to wrap an input frame into an output frame, which can be used for rendering without an algorithm component.
/// All members of this class is thread-safe.
/// </summary>
class InputFrameToOutputFrameAdapter
{
protected:
    std::shared_ptr<easyar_InputFrameToOutputFrameAdapter> cdata_;
    void init_cdata(std::shared_ptr<easyar_InputFrameToOutputFrameAdapter> cdata);
    InputFrameToOutputFrameAdapter & operator=(const InputFrameToOutputFrameAdapter & data) = delete;
public:
    InputFrameToOutputFrameAdapter(std::shared_ptr<easyar_InputFrameToOutputFrameAdapter> cdata);
    virtual ~InputFrameToOutputFrameAdapter();

    std::shared_ptr<easyar_InputFrameToOutputFrameAdapter> get_cdata();
    static std::shared_ptr<InputFrameToOutputFrameAdapter> from_cdata(std::shared_ptr<easyar_InputFrameToOutputFrameAdapter> cdata);

    /// <summary>
    /// Input port.
    /// </summary>
    std::shared_ptr<InputFrameSink> input();
    /// <summary>
    /// Output port.
    /// </summary>
    std::shared_ptr<OutputFrameSource> output();
    /// <summary>
    /// Creates an instance.
    /// </summary>
    static std::shared_ptr<InputFrameToOutputFrameAdapter> create();
};

/// <summary>
/// Input frame to feedback frame adapter.
/// There is an input frame input port, a historic output frame input port and a feedback frame output port. It can be used to combine an input frame and a historic output frame into a feedback frame, which is required by algorithm components such as `ImageTracker`_ .
/// On every input of an input frame, a feedback frame is generated with a previously input historic feedback frame. If there is no previously input historic feedback frame, it is null in the feedback frame.
/// InputFrameToFeedbackFrameAdapter occupies one buffer of camera. Use setBufferCapacity of camera to set an amount of buffers that is not less than the sum of amount of buffers occupied by all components.
/// All members of this class is thread-safe.
/// </summary>
class InputFrameToFeedbackFrameAdapter
{
protected:
    std::shared_ptr<easyar_InputFrameToFeedbackFrameAdapter> cdata_;
    void init_cdata(std::shared_ptr<easyar_InputFrameToFeedbackFrameAdapter> cdata);
    InputFrameToFeedbackFrameAdapter & operator=(const InputFrameToFeedbackFrameAdapter & data) = delete;
public:
    InputFrameToFeedbackFrameAdapter(std::shared_ptr<easyar_InputFrameToFeedbackFrameAdapter> cdata);
    virtual ~InputFrameToFeedbackFrameAdapter();

    std::shared_ptr<easyar_InputFrameToFeedbackFrameAdapter> get_cdata();
    static std::shared_ptr<InputFrameToFeedbackFrameAdapter> from_cdata(std::shared_ptr<easyar_InputFrameToFeedbackFrameAdapter> cdata);

    /// <summary>
    /// Input port.
    /// </summary>
    std::shared_ptr<InputFrameSink> input();
    /// <summary>
    /// Camera buffers occupied in this component.
    /// </summary>
    int bufferRequirement();
    /// <summary>
    /// Side input port for historic output frame input.
    /// </summary>
    std::shared_ptr<OutputFrameSink> sideInput();
    /// <summary>
    /// Output port.
    /// </summary>
    std::shared_ptr<FeedbackFrameSource> output();
    /// <summary>
    /// Creates an instance.
    /// </summary>
    static std::shared_ptr<InputFrameToFeedbackFrameAdapter> create();
};

/// <summary>
/// Motion input data.
/// It includes timestamp, transform matrix against world coordinate system, and tracking status.
/// </summary>
class MotionInputData
{
protected:
    std::shared_ptr<easyar_MotionInputData> cdata_;
    void init_cdata(std::shared_ptr<easyar_MotionInputData> cdata);
    MotionInputData & operator=(const MotionInputData & data) = delete;
public:
    MotionInputData(std::shared_ptr<easyar_MotionInputData> cdata);
    virtual ~MotionInputData();

    std::shared_ptr<easyar_MotionInputData> get_cdata();
    static std::shared_ptr<MotionInputData> from_cdata(std::shared_ptr<easyar_MotionInputData> cdata);

    /// <summary>
    /// Creates with 6DOF transform of both rotation and position. rotation is quaternion, ordered as wxyz.
    /// </summary>
    static std::optional<std::shared_ptr<MotionInputData>> tryCreateSixDof(double timestamp, Vec3F position, Vec4F rotation, MotionTrackingStatus tracking_status);
    /// <summary>
    /// Creates with 5DOF transform of both rotation and 2D position. rotation is quaternion, ordered as wxyz.
    /// </summary>
    static std::optional<std::shared_ptr<MotionInputData>> tryCreateFiveDofRotXZ(double timestamp, Vec3F position, Vec4F rotation);
    /// <summary>
    /// Creates with 3DOF transform of rotation only. rotation is quaternion, ordered as wxyz.
    /// </summary>
    static std::optional<std::shared_ptr<MotionInputData>> tryCreateThreeDofRotOnly(double timestamp, Vec4F rotation);
    /// <summary>
    /// Timestamp. In seconds.
    /// </summary>
    double timestamp();
    /// <summary>
    /// Transform type.
    /// </summary>
    CameraTransformType transformType();
    /// <summary>
    /// Transform matrix against world coordinate system.
    /// </summary>
    Matrix44F transform();
    /// <summary>
    /// Gets device motion tracking status: `MotionTrackingStatus`_ . Only for 6DOF.
    /// </summary>
    MotionTrackingStatus trackingStatus();
};

/// <summary>
/// Input frame.
/// It includes image, camera parameters, timestamp, camera transform matrix against world coordinate system, and tracking status,
/// among which, camera parameters, timestamp, camera transform matrix and tracking status are all optional, but specific algorithms may have special requirements on the input.
/// </summary>
class InputFrame
{
protected:
    std::shared_ptr<easyar_InputFrame> cdata_;
    void init_cdata(std::shared_ptr<easyar_InputFrame> cdata);
    InputFrame & operator=(const InputFrame & data) = delete;
public:
    InputFrame(std::shared_ptr<easyar_InputFrame> cdata);
    virtual ~InputFrame();

    std::shared_ptr<easyar_InputFrame> get_cdata();
    static std::shared_ptr<InputFrame> from_cdata(std::shared_ptr<easyar_InputFrame> cdata);

    /// <summary>
    /// Index, an automatic incremental value, which is different for every input frame.
    /// </summary>
    int index();
    /// <summary>
    /// Gets image.
    /// </summary>
    std::shared_ptr<Image> image();
    /// <summary>
    /// Checks if there are camera parameters.
    /// </summary>
    bool hasCameraParameters();
    /// <summary>
    /// Gets camera parameters.
    /// </summary>
    std::shared_ptr<CameraParameters> cameraParameters();
    /// <summary>
    /// Checks if there is temporal information (timestamp).
    /// </summary>
    bool hasTemporalInformation();
    /// <summary>
    /// Timestamp. In seconds.
    /// </summary>
    double timestamp();
    /// <summary>
    /// Checks if there is spatial information (cameraTransform and trackingStatus).
    /// </summary>
    bool hasSpatialInformation();
    /// <summary>
    /// Camera transform matrix against world coordinate system. Camera coordinate system and world coordinate system are all right-handed. For the camera coordinate system, the origin is the optical center, x-right, y-up, and z in the direction of light going into camera. (The right and up, is right and up in the camera image, which can be different from these in the natural orientation of the device.) The data arrangement is row-major, not like OpenGL&#39;s column-major.
    /// </summary>
    Matrix44F cameraTransform();
    /// <summary>
    /// Camera transform type.
    /// </summary>
    CameraTransformType cameraTransformType();
    /// <summary>
    /// Gets device motion tracking status: `MotionTrackingStatus`_ .
    /// </summary>
    MotionTrackingStatus trackingStatus();
    /// <summary>
    /// Motion input data.
    /// </summary>
    std::optional<std::shared_ptr<MotionInputData>> motion();
    /// <summary>
    /// Creates an instance.
    /// </summary>
    static std::optional<std::shared_ptr<InputFrame>> tryCreate(std::shared_ptr<Image> image, std::shared_ptr<CameraParameters> cameraParameters, double timestamp, Matrix44F cameraTransform, CameraTransformType cameraTransformType, MotionTrackingStatus trackingStatus);
    /// <summary>
    /// Creates an instance with image, camera parameters, and timestamp.
    /// </summary>
    static std::shared_ptr<InputFrame> createWithImageAndCameraParametersAndTemporal(std::shared_ptr<Image> image, std::shared_ptr<CameraParameters> cameraParameters, double timestamp);
    /// <summary>
    /// Creates an instance with image and camera parameters. Nothing but `CloudRecognizer`_ can work with input created by this method.
    /// </summary>
    static std::shared_ptr<InputFrame> createWithImageAndCameraParameters(std::shared_ptr<Image> image, std::shared_ptr<CameraParameters> cameraParameters);
    /// <summary>
    /// Creates an instance with image. Nothing but `CloudRecognizer`_ can work with input created by this method.
    /// </summary>
    static std::shared_ptr<InputFrame> createWithImage(std::shared_ptr<Image> image);
};

/// <summary>
/// Output frame.
/// It includes input frame and results of synchronous components.
/// </summary>
class OutputFrame
{
protected:
    std::shared_ptr<easyar_OutputFrame> cdata_;
    void init_cdata(std::shared_ptr<easyar_OutputFrame> cdata);
    OutputFrame & operator=(const OutputFrame & data) = delete;
public:
    OutputFrame(std::shared_ptr<easyar_OutputFrame> cdata);
    virtual ~OutputFrame();

    std::shared_ptr<easyar_OutputFrame> get_cdata();
    static std::shared_ptr<OutputFrame> from_cdata(std::shared_ptr<easyar_OutputFrame> cdata);

    OutputFrame(std::shared_ptr<InputFrame> inputFrame, std::vector<std::optional<std::shared_ptr<FrameFilterResult>>> results);
    /// <summary>
    /// Index, an automatic incremental value, which is different for every output frame.
    /// </summary>
    int index();
    /// <summary>
    /// Corresponding input frame.
    /// </summary>
    std::shared_ptr<InputFrame> inputFrame();
    /// <summary>
    /// Results of synchronous components.
    /// </summary>
    std::vector<std::optional<std::shared_ptr<FrameFilterResult>>> results();
};

/// <summary>
/// Feedback frame.
/// It includes an input frame and a historic output frame for use in feedback synchronous components such as `ImageTracker`_ .
/// </summary>
class FeedbackFrame
{
protected:
    std::shared_ptr<easyar_FeedbackFrame> cdata_;
    void init_cdata(std::shared_ptr<easyar_FeedbackFrame> cdata);
    FeedbackFrame & operator=(const FeedbackFrame & data) = delete;
public:
    FeedbackFrame(std::shared_ptr<easyar_FeedbackFrame> cdata);
    virtual ~FeedbackFrame();

    std::shared_ptr<easyar_FeedbackFrame> get_cdata();
    static std::shared_ptr<FeedbackFrame> from_cdata(std::shared_ptr<easyar_FeedbackFrame> cdata);

    FeedbackFrame(std::shared_ptr<InputFrame> inputFrame, std::optional<std::shared_ptr<OutputFrame>> previousOutputFrame);
    /// <summary>
    /// Input frame.
    /// </summary>
    std::shared_ptr<InputFrame> inputFrame();
    /// <summary>
    /// Historic output frame.
    /// </summary>
    std::optional<std::shared_ptr<OutputFrame>> previousOutputFrame();
};

class PoseUtility
{
protected:
    std::shared_ptr<easyar_PoseUtility> cdata_;
    void init_cdata(std::shared_ptr<easyar_PoseUtility> cdata);
    PoseUtility & operator=(const PoseUtility & data) = delete;
public:
    PoseUtility(std::shared_ptr<easyar_PoseUtility> cdata);
    virtual ~PoseUtility();

    std::shared_ptr<easyar_PoseUtility> get_cdata();
    static std::shared_ptr<PoseUtility> from_cdata(std::shared_ptr<easyar_PoseUtility> cdata);

    static std::optional<Matrix44F> createPoseWithHardwareOffset(Vec3F position, Vec4F rotation, std::optional<Vec3F> offsetPosition, std::optional<Vec4F> offsetRotation);
};

/// <summary>
/// TargetInstance is the tracked target by trackers.
/// An TargetInstance contains a raw `Target`_ that is tracked and current status and pose of the `Target`_ .
/// </summary>
class TargetInstance
{
protected:
    std::shared_ptr<easyar_TargetInstance> cdata_;
    void init_cdata(std::shared_ptr<easyar_TargetInstance> cdata);
    TargetInstance & operator=(const TargetInstance & data) = delete;
public:
    TargetInstance(std::shared_ptr<easyar_TargetInstance> cdata);
    virtual ~TargetInstance();

    std::shared_ptr<easyar_TargetInstance> get_cdata();
    static std::shared_ptr<TargetInstance> from_cdata(std::shared_ptr<easyar_TargetInstance> cdata);

    /// <summary>
    /// Returns current status of the tracked target. Usually you can check if the status equals `TargetStatus.Tracked` to determine current status of the target.
    /// </summary>
    TargetStatus status();
    /// <summary>
    /// Gets the raw target. It will return the same `Target`_ you loaded into a tracker if it was previously loaded into the tracker.
    /// </summary>
    std::shared_ptr<Target> target();
    /// <summary>
    /// Returns current pose of the tracked target. Camera coordinate system and target coordinate system are all right-handed. For the camera coordinate system, the origin is the optical center, x-right, y-up, and z in the direction of light going into camera. (The right and up, is right and up in the camera image, which can be different from these in the natural orientation of the device.) The data arrangement is row-major, not like OpenGL&#39;s column-major.
    /// </summary>
    Matrix44F pose();
};

/// <summary>
/// TextureId encapsulates a texture object in rendering API.
/// For OpenGL/OpenGLES, getInt and fromInt shall be used. For Direct3D, getPointer and fromPointer shall be used.
/// </summary>
class TextureId
{
protected:
    std::shared_ptr<easyar_TextureId> cdata_;
    void init_cdata(std::shared_ptr<easyar_TextureId> cdata);
    TextureId & operator=(const TextureId & data) = delete;
public:
    TextureId(std::shared_ptr<easyar_TextureId> cdata);
    virtual ~TextureId();

    std::shared_ptr<easyar_TextureId> get_cdata();
    static std::shared_ptr<TextureId> from_cdata(std::shared_ptr<easyar_TextureId> cdata);

    /// <summary>
    /// Gets ID of an OpenGL/OpenGLES texture object.
    /// </summary>
    int getInt();
    /// <summary>
    /// Gets pointer of a Direct3D texture object.
    /// </summary>
    void * getPointer();
    /// <summary>
    /// Creates from ID of an OpenGL/OpenGLES texture object.
    /// </summary>
    static std::shared_ptr<TextureId> fromInt(int _value);
    /// <summary>
    /// Creates from pointer of a Direct3D texture object.
    /// </summary>
    static std::shared_ptr<TextureId> fromPointer(void * ptr);
};

}

#endif

#ifndef _EASYAR_DECLARATION_ONLY_

#include "easyar/objecttarget.h"
#include "easyar/objecttracker.h"
#include "easyar/arcoredevicelist.h"
#include "easyar/calibration.h"
#include "easyar/cloudlocalize.h"
#include "easyar/megalandmark.h"
#include "easyar/megatracker.h"
#include "easyar/cloudrecognizer.h"
#include "easyar/buffer.h"
#include "easyar/bufferpool.h"
#include "easyar/image.h"
#include "easyar/sensor.h"
#include "easyar/densespatialmap.h"
#include "easyar/scenemesh.h"
#include "easyar/accelerometer.h"
#include "easyar/arcorecamera.h"
#include "easyar/arkitcamera.h"
#include "easyar/attitude_sensor.h"
#include "easyar/camera.h"
#include "easyar/gyroscope.h"
#include "easyar/magnetometer.h"
#include "easyar/threedof_camera.h"
#include "easyar/visionos_arkitcamera.h"
#include "easyar/xrealcamera.h"
#include "easyar/surfacetracker.h"
#include "easyar/eventdumprecorder.h"
#include "easyar/motiontracker.h"
#include "easyar/framerecorder.h"
#include "easyar/videoframerecorder.h"
#include "easyar/imagehelper.h"
#include "easyar/ins.h"
#include "easyar/callbackscheduler.h"
#include "easyar/jniutility.h"
#include "easyar/log.h"
#include "easyar/storage.h"
#include "easyar/imagetarget.h"
#include "easyar/imagetracker.h"
#include "easyar/recorder.h"
#include "easyar/recorder_configuration.h"
#include "easyar/sparsespatialmap.h"
#include "easyar/sparsespatialmapmanager.h"
#include "easyar/engine.h"
#include "easyar/videoplayer.h"
#include "easyar/cameraparameters.h"
#include "easyar/dataflow.h"
#include "easyar/frame.h"
#include "easyar/poseutility.h"
#include "easyar/target.h"
#include "easyar/texture.h"

namespace easyar {

static inline std::shared_ptr<easyar_String> std_string_to_easyar_String(std::string s)
{
    easyar_String * ptr;
    easyar_String_from_utf8(s.data(), s.data() + s.size(), &ptr);
    return std::shared_ptr<easyar_String>(ptr, [](easyar_String * ptr) { easyar_String__dtor(ptr); });
}
static inline std::string std_string_from_easyar_String(std::shared_ptr<easyar_String> s)
{
    return std::string(easyar_String_begin(s.get()), easyar_String_end(s.get()));
}

static void FunctorOfVoid_func(void * _state, /* OUT */ easyar_String * * _exception);
static void FunctorOfVoid_destroy(void * _state);
static inline easyar_FunctorOfVoid FunctorOfVoid_to_c(std::function<void()> f);

static inline std::shared_ptr<easyar_ListOfVec3F> std_vector_to_easyar_ListOfVec3F(std::vector<Vec3F> l);
static inline std::vector<Vec3F> std_vector_from_easyar_ListOfVec3F(std::shared_ptr<easyar_ListOfVec3F> pl);
static inline bool easyar_ListOfVec3F_check_external_cpp(const std::vector<Vec3F> & l);

static inline std::shared_ptr<easyar_ListOfTargetInstance> std_vector_to_easyar_ListOfTargetInstance(std::vector<std::shared_ptr<TargetInstance>> l);
static inline std::vector<std::shared_ptr<TargetInstance>> std_vector_from_easyar_ListOfTargetInstance(std::shared_ptr<easyar_ListOfTargetInstance> pl);
static inline bool easyar_ListOfTargetInstance_check_external_cpp(const std::vector<std::shared_ptr<TargetInstance>> & l);

static inline std::shared_ptr<easyar_ListOfFloat> std_vector_to_easyar_ListOfFloat(std::vector<float> l);
static inline std::vector<float> std_vector_from_easyar_ListOfFloat(std::shared_ptr<easyar_ListOfFloat> pl);
static inline bool easyar_ListOfFloat_check_external_cpp(const std::vector<float> & l);

static inline std::shared_ptr<easyar_ListOfOptionalOfFrameFilterResult> std_vector_to_easyar_ListOfOptionalOfFrameFilterResult(std::vector<std::optional<std::shared_ptr<FrameFilterResult>>> l);
static inline std::vector<std::optional<std::shared_ptr<FrameFilterResult>>> std_vector_from_easyar_ListOfOptionalOfFrameFilterResult(std::shared_ptr<easyar_ListOfOptionalOfFrameFilterResult> pl);
static inline bool easyar_ListOfOptionalOfFrameFilterResult_check_external_cpp(const std::vector<std::optional<std::shared_ptr<FrameFilterResult>>> & l);

static void FunctorOfVoidFromOutputFrame_func(void * _state, easyar_OutputFrame *, /* OUT */ easyar_String * * _exception);
static void FunctorOfVoidFromOutputFrame_destroy(void * _state);
static inline easyar_FunctorOfVoidFromOutputFrame FunctorOfVoidFromOutputFrame_to_c(std::function<void(std::shared_ptr<OutputFrame>)> f);

static void FunctorOfVoidFromTargetAndBool_func(void * _state, easyar_Target *, bool, /* OUT */ easyar_String * * _exception);
static void FunctorOfVoidFromTargetAndBool_destroy(void * _state);
static inline easyar_FunctorOfVoidFromTargetAndBool FunctorOfVoidFromTargetAndBool_to_c(std::function<void(std::shared_ptr<Target>, bool)> f);

static inline std::shared_ptr<easyar_ListOfTarget> std_vector_to_easyar_ListOfTarget(std::vector<std::shared_ptr<Target>> l);
static inline std::vector<std::shared_ptr<Target>> std_vector_from_easyar_ListOfTarget(std::shared_ptr<easyar_ListOfTarget> pl);
static inline bool easyar_ListOfTarget_check_external_cpp(const std::vector<std::shared_ptr<Target>> & l);

static void FunctorOfVoidFromARCoreDeviceListDownloadStatusAndOptionalOfString_func(void * _state, easyar_ARCoreDeviceListDownloadStatus, easyar_OptionalOfString, /* OUT */ easyar_String * * _exception);
static void FunctorOfVoidFromARCoreDeviceListDownloadStatusAndOptionalOfString_destroy(void * _state);
static inline easyar_FunctorOfVoidFromARCoreDeviceListDownloadStatusAndOptionalOfString FunctorOfVoidFromARCoreDeviceListDownloadStatusAndOptionalOfString_to_c(std::function<void(ARCoreDeviceListDownloadStatus, std::optional<std::string>)> f);

static void FunctorOfVoidFromCalibrationDownloadStatusAndOptionalOfString_func(void * _state, easyar_CalibrationDownloadStatus, easyar_OptionalOfString, /* OUT */ easyar_String * * _exception);
static void FunctorOfVoidFromCalibrationDownloadStatusAndOptionalOfString_destroy(void * _state);
static inline easyar_FunctorOfVoidFromCalibrationDownloadStatusAndOptionalOfString FunctorOfVoidFromCalibrationDownloadStatusAndOptionalOfString_to_c(std::function<void(CalibrationDownloadStatus, std::optional<std::string>)> f);

static inline std::shared_ptr<easyar_ListOfCloudLocalizerBlockInstance> std_vector_to_easyar_ListOfCloudLocalizerBlockInstance(std::vector<std::shared_ptr<CloudLocalizerBlockInstance>> l);
static inline std::vector<std::shared_ptr<CloudLocalizerBlockInstance>> std_vector_from_easyar_ListOfCloudLocalizerBlockInstance(std::shared_ptr<easyar_ListOfCloudLocalizerBlockInstance> pl);
static inline bool easyar_ListOfCloudLocalizerBlockInstance_check_external_cpp(const std::vector<std::shared_ptr<CloudLocalizerBlockInstance>> & l);

static inline std::shared_ptr<easyar_ListOfString> std_vector_to_easyar_ListOfString(std::vector<std::string> l);
static inline std::vector<std::string> std_vector_from_easyar_ListOfString(std::shared_ptr<easyar_ListOfString> pl);
static inline bool easyar_ListOfString_check_external_cpp(const std::vector<std::string> & l);

static void FunctorOfVoidFromCloudLocalizerResult_func(void * _state, easyar_CloudLocalizerResult *, /* OUT */ easyar_String * * _exception);
static void FunctorOfVoidFromCloudLocalizerResult_destroy(void * _state);
static inline easyar_FunctorOfVoidFromCloudLocalizerResult FunctorOfVoidFromCloudLocalizerResult_to_c(std::function<void(std::shared_ptr<CloudLocalizerResult>)> f);

static void FunctorOfVoidFromMegaLandmarkFilterResult_func(void * _state, easyar_MegaLandmarkFilterResult *, /* OUT */ easyar_String * * _exception);
static void FunctorOfVoidFromMegaLandmarkFilterResult_destroy(void * _state);
static inline easyar_FunctorOfVoidFromMegaLandmarkFilterResult FunctorOfVoidFromMegaLandmarkFilterResult_to_c(std::function<void(std::shared_ptr<MegaLandmarkFilterResult>)> f);

static inline std::shared_ptr<easyar_ListOfMegaTrackerBlockInstance> std_vector_to_easyar_ListOfMegaTrackerBlockInstance(std::vector<std::shared_ptr<MegaTrackerBlockInstance>> l);
static inline std::vector<std::shared_ptr<MegaTrackerBlockInstance>> std_vector_from_easyar_ListOfMegaTrackerBlockInstance(std::shared_ptr<easyar_ListOfMegaTrackerBlockInstance> pl);
static inline bool easyar_ListOfMegaTrackerBlockInstance_check_external_cpp(const std::vector<std::shared_ptr<MegaTrackerBlockInstance>> & l);

static void FunctorOfVoidFromMegaTrackerLocalizationResponse_func(void * _state, easyar_MegaTrackerLocalizationResponse *, /* OUT */ easyar_String * * _exception);
static void FunctorOfVoidFromMegaTrackerLocalizationResponse_destroy(void * _state);
static inline easyar_FunctorOfVoidFromMegaTrackerLocalizationResponse FunctorOfVoidFromMegaTrackerLocalizationResponse_to_c(std::function<void(std::shared_ptr<MegaTrackerLocalizationResponse>)> f);

static inline std::shared_ptr<easyar_ListOfImage> std_vector_to_easyar_ListOfImage(std::vector<std::shared_ptr<Image>> l);
static inline std::vector<std::shared_ptr<Image>> std_vector_from_easyar_ListOfImage(std::shared_ptr<easyar_ListOfImage> pl);
static inline bool easyar_ListOfImage_check_external_cpp(const std::vector<std::shared_ptr<Image>> & l);

static void FunctorOfVoidFromCloudRecognizationResult_func(void * _state, easyar_CloudRecognizationResult *, /* OUT */ easyar_String * * _exception);
static void FunctorOfVoidFromCloudRecognizationResult_destroy(void * _state);
static inline easyar_FunctorOfVoidFromCloudRecognizationResult FunctorOfVoidFromCloudRecognizationResult_to_c(std::function<void(std::shared_ptr<CloudRecognizationResult>)> f);

static inline std::shared_ptr<easyar_ListOfBlockInfo> std_vector_to_easyar_ListOfBlockInfo(std::vector<BlockInfo> l);
static inline std::vector<BlockInfo> std_vector_from_easyar_ListOfBlockInfo(std::shared_ptr<easyar_ListOfBlockInfo> pl);
static inline bool easyar_ListOfBlockInfo_check_external_cpp(const std::vector<BlockInfo> & l);

static void FunctorOfVoidFromAccelerometerResult_func(void * _state, easyar_AccelerometerResult, /* OUT */ easyar_String * * _exception);
static void FunctorOfVoidFromAccelerometerResult_destroy(void * _state);
static inline easyar_FunctorOfVoidFromAccelerometerResult FunctorOfVoidFromAccelerometerResult_to_c(std::function<void(AccelerometerResult)> f);

static void FunctorOfVoidFromInputFrame_func(void * _state, easyar_InputFrame *, /* OUT */ easyar_String * * _exception);
static void FunctorOfVoidFromInputFrame_destroy(void * _state);
static inline easyar_FunctorOfVoidFromInputFrame FunctorOfVoidFromInputFrame_to_c(std::function<void(std::shared_ptr<InputFrame>)> f);

static void FunctorOfVoidFromAttitudeSensorResult_func(void * _state, easyar_AttitudeSensorResult, /* OUT */ easyar_String * * _exception);
static void FunctorOfVoidFromAttitudeSensorResult_destroy(void * _state);
static inline easyar_FunctorOfVoidFromAttitudeSensorResult FunctorOfVoidFromAttitudeSensorResult_to_c(std::function<void(AttitudeSensorResult)> f);

static void FunctorOfVoidFromCameraState_func(void * _state, easyar_CameraState, /* OUT */ easyar_String * * _exception);
static void FunctorOfVoidFromCameraState_destroy(void * _state);
static inline easyar_FunctorOfVoidFromCameraState FunctorOfVoidFromCameraState_to_c(std::function<void(CameraState)> f);

static void FunctorOfVoidFromPermissionStatusAndString_func(void * _state, easyar_PermissionStatus, easyar_String *, /* OUT */ easyar_String * * _exception);
static void FunctorOfVoidFromPermissionStatusAndString_destroy(void * _state);
static inline easyar_FunctorOfVoidFromPermissionStatusAndString FunctorOfVoidFromPermissionStatusAndString_to_c(std::function<void(PermissionStatus, std::string)> f);

static void FunctorOfVoidFromGyroscopeResult_func(void * _state, easyar_GyroscopeResult, /* OUT */ easyar_String * * _exception);
static void FunctorOfVoidFromGyroscopeResult_destroy(void * _state);
static inline easyar_FunctorOfVoidFromGyroscopeResult FunctorOfVoidFromGyroscopeResult_to_c(std::function<void(GyroscopeResult)> f);

static void FunctorOfVoidFromMagnetometerResult_func(void * _state, easyar_MagnetometerResult, /* OUT */ easyar_String * * _exception);
static void FunctorOfVoidFromMagnetometerResult_destroy(void * _state);
static inline easyar_FunctorOfVoidFromMagnetometerResult FunctorOfVoidFromMagnetometerResult_to_c(std::function<void(MagnetometerResult)> f);

static void FunctorOfVoidFromVideoInputFrameRecorderCompletionReason_func(void * _state, easyar_VideoInputFrameRecorderCompletionReason, /* OUT */ easyar_String * * _exception);
static void FunctorOfVoidFromVideoInputFrameRecorderCompletionReason_destroy(void * _state);
static inline easyar_FunctorOfVoidFromVideoInputFrameRecorderCompletionReason FunctorOfVoidFromVideoInputFrameRecorderCompletionReason_to_c(std::function<void(VideoInputFrameRecorderCompletionReason)> f);

static void FunctorOfVoidFromLocationResult_func(void * _state, easyar_LocationResult, /* OUT */ easyar_String * * _exception);
static void FunctorOfVoidFromLocationResult_destroy(void * _state);
static inline easyar_FunctorOfVoidFromLocationResult FunctorOfVoidFromLocationResult_to_c(std::function<void(LocationResult)> f);

static void FunctorOfVoidFromProximityLocationResult_func(void * _state, easyar_ProximityLocationResult, /* OUT */ easyar_String * * _exception);
static void FunctorOfVoidFromProximityLocationResult_destroy(void * _state);
static inline easyar_FunctorOfVoidFromProximityLocationResult FunctorOfVoidFromProximityLocationResult_to_c(std::function<void(ProximityLocationResult)> f);

static void FunctorOfVoidFromLogLevelAndString_func(void * _state, easyar_LogLevel, easyar_String *, /* OUT */ easyar_String * * _exception);
static void FunctorOfVoidFromLogLevelAndString_destroy(void * _state);
static inline easyar_FunctorOfVoidFromLogLevelAndString FunctorOfVoidFromLogLevelAndString_to_c(std::function<void(LogLevel, std::string)> f);

static void FunctorOfVoidFromRecordStatusAndString_func(void * _state, easyar_RecordStatus, easyar_String *, /* OUT */ easyar_String * * _exception);
static void FunctorOfVoidFromRecordStatusAndString_destroy(void * _state);
static inline easyar_FunctorOfVoidFromRecordStatusAndString FunctorOfVoidFromRecordStatusAndString_to_c(std::function<void(RecordStatus, std::string)> f);

static inline std::shared_ptr<easyar_ListOfPlaneData> std_vector_to_easyar_ListOfPlaneData(std::vector<std::shared_ptr<PlaneData>> l);
static inline std::vector<std::shared_ptr<PlaneData>> std_vector_from_easyar_ListOfPlaneData(std::shared_ptr<easyar_ListOfPlaneData> pl);
static inline bool easyar_ListOfPlaneData_check_external_cpp(const std::vector<std::shared_ptr<PlaneData>> & l);

static void FunctorOfVoidFromBool_func(void * _state, bool, /* OUT */ easyar_String * * _exception);
static void FunctorOfVoidFromBool_destroy(void * _state);
static inline easyar_FunctorOfVoidFromBool FunctorOfVoidFromBool_to_c(std::function<void(bool)> f);

static void FunctorOfVoidFromBoolAndStringAndString_func(void * _state, bool, easyar_String *, easyar_String *, /* OUT */ easyar_String * * _exception);
static void FunctorOfVoidFromBoolAndStringAndString_destroy(void * _state);
static inline easyar_FunctorOfVoidFromBoolAndStringAndString FunctorOfVoidFromBoolAndStringAndString_to_c(std::function<void(bool, std::string, std::string)> f);

static void FunctorOfVoidFromBoolAndString_func(void * _state, bool, easyar_String *, /* OUT */ easyar_String * * _exception);
static void FunctorOfVoidFromBoolAndString_destroy(void * _state);
static inline easyar_FunctorOfVoidFromBoolAndString FunctorOfVoidFromBoolAndString_to_c(std::function<void(bool, std::string)> f);

static void FunctorOfVoidFromVideoStatus_func(void * _state, easyar_VideoStatus, /* OUT */ easyar_String * * _exception);
static void FunctorOfVoidFromVideoStatus_destroy(void * _state);
static inline easyar_FunctorOfVoidFromVideoStatus FunctorOfVoidFromVideoStatus_to_c(std::function<void(VideoStatus)> f);

static void FunctorOfVoidFromFeedbackFrame_func(void * _state, easyar_FeedbackFrame *, /* OUT */ easyar_String * * _exception);
static void FunctorOfVoidFromFeedbackFrame_destroy(void * _state);
static inline easyar_FunctorOfVoidFromFeedbackFrame FunctorOfVoidFromFeedbackFrame_to_c(std::function<void(std::shared_ptr<FeedbackFrame>)> f);

static void FunctorOfOutputFrameFromListOfOutputFrame_func(void * _state, easyar_ListOfOutputFrame *, /* OUT */ easyar_OutputFrame * *, /* OUT */ easyar_String * * _exception);
static void FunctorOfOutputFrameFromListOfOutputFrame_destroy(void * _state);
static inline easyar_FunctorOfOutputFrameFromListOfOutputFrame FunctorOfOutputFrameFromListOfOutputFrame_to_c(std::function<std::shared_ptr<OutputFrame>(std::vector<std::shared_ptr<OutputFrame>>)> f);

static inline std::shared_ptr<easyar_ListOfOutputFrame> std_vector_to_easyar_ListOfOutputFrame(std::vector<std::shared_ptr<OutputFrame>> l);
static inline std::vector<std::shared_ptr<OutputFrame>> std_vector_from_easyar_ListOfOutputFrame(std::shared_ptr<easyar_ListOfOutputFrame> pl);
static inline bool easyar_ListOfOutputFrame_check_external_cpp(const std::vector<std::shared_ptr<OutputFrame>> & l);

_INLINE_SPECIFIER_ ObjectTargetParameters::ObjectTargetParameters(std::shared_ptr<easyar_ObjectTargetParameters> cdata)
    :
    cdata_(nullptr)
{
    init_cdata(cdata);
}
_INLINE_SPECIFIER_ ObjectTargetParameters::~ObjectTargetParameters()
{
    cdata_ = nullptr;
}

_INLINE_SPECIFIER_ std::shared_ptr<easyar_ObjectTargetParameters> ObjectTargetParameters::get_cdata()
{
    return cdata_;
}
_INLINE_SPECIFIER_ void ObjectTargetParameters::init_cdata(std::shared_ptr<easyar_ObjectTargetParameters> cdata)
{
    cdata_ = cdata;
}
_INLINE_SPECIFIER_ std::shared_ptr<ObjectTargetParameters> ObjectTargetParameters::from_cdata(std::shared_ptr<easyar_ObjectTargetParameters> cdata)
{
    if (cdata == nullptr) {
        return nullptr;
    }
    return std::make_shared<ObjectTargetParameters>(cdata);
}
_INLINE_SPECIFIER_ ObjectTargetParameters::ObjectTargetParameters()
    :
    cdata_(nullptr)
{
    easyar_ObjectTargetParameters * _return_value_;
    easyar_ObjectTargetParameters__ctor(&_return_value_);
    if (!(_return_value_ != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    init_cdata(std::shared_ptr<easyar_ObjectTargetParameters>(_return_value_, [](easyar_ObjectTargetParameters * ptr) { easyar_ObjectTargetParameters__dtor(ptr); }));
}
_INLINE_SPECIFIER_ std::shared_ptr<BufferDictionary> ObjectTargetParameters::bufferDictionary()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_BufferDictionary * _return_value_;
    easyar_ObjectTargetParameters_bufferDictionary(this->cdata_.get(), &_return_value_);
    if (!(_return_value_ != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    return BufferDictionary::from_cdata(std::shared_ptr<easyar_BufferDictionary>(_return_value_, [](easyar_BufferDictionary * ptr) { easyar_BufferDictionary__dtor(ptr); }));
}
_INLINE_SPECIFIER_ void ObjectTargetParameters::setBufferDictionary(std::shared_ptr<BufferDictionary> bufferDictionary)
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    if (!(bufferDictionary != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: bufferDictionary");
#else
        std::terminate();
#endif
    }
    easyar_ObjectTargetParameters_setBufferDictionary(this->cdata_.get(), bufferDictionary->get_cdata().get());
}
_INLINE_SPECIFIER_ std::string ObjectTargetParameters::objPath()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_String * _return_value_;
    easyar_ObjectTargetParameters_objPath(this->cdata_.get(), &_return_value_);
    if (!(_return_value_ != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    return std_string_from_easyar_String(std::shared_ptr<easyar_String>(_return_value_, [](easyar_String * ptr) { easyar_String__dtor(ptr); }));
}
_INLINE_SPECIFIER_ void ObjectTargetParameters::setObjPath(std::string objPath)
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_ObjectTargetParameters_setObjPath(this->cdata_.get(), std_string_to_easyar_String(objPath).get());
}
_INLINE_SPECIFIER_ std::string ObjectTargetParameters::name()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_String * _return_value_;
    easyar_ObjectTargetParameters_name(this->cdata_.get(), &_return_value_);
    if (!(_return_value_ != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    return std_string_from_easyar_String(std::shared_ptr<easyar_String>(_return_value_, [](easyar_String * ptr) { easyar_String__dtor(ptr); }));
}
_INLINE_SPECIFIER_ void ObjectTargetParameters::setName(std::string name)
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_ObjectTargetParameters_setName(this->cdata_.get(), std_string_to_easyar_String(name).get());
}
_INLINE_SPECIFIER_ std::string ObjectTargetParameters::uid()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_String * _return_value_;
    easyar_ObjectTargetParameters_uid(this->cdata_.get(), &_return_value_);
    if (!(_return_value_ != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    return std_string_from_easyar_String(std::shared_ptr<easyar_String>(_return_value_, [](easyar_String * ptr) { easyar_String__dtor(ptr); }));
}
_INLINE_SPECIFIER_ void ObjectTargetParameters::setUid(std::string uid)
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_ObjectTargetParameters_setUid(this->cdata_.get(), std_string_to_easyar_String(uid).get());
}
_INLINE_SPECIFIER_ std::string ObjectTargetParameters::meta()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_String * _return_value_;
    easyar_ObjectTargetParameters_meta(this->cdata_.get(), &_return_value_);
    if (!(_return_value_ != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    return std_string_from_easyar_String(std::shared_ptr<easyar_String>(_return_value_, [](easyar_String * ptr) { easyar_String__dtor(ptr); }));
}
_INLINE_SPECIFIER_ void ObjectTargetParameters::setMeta(std::string meta)
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_ObjectTargetParameters_setMeta(this->cdata_.get(), std_string_to_easyar_String(meta).get());
}
_INLINE_SPECIFIER_ float ObjectTargetParameters::scale()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_ObjectTargetParameters_scale(this->cdata_.get());
    return _return_value_;
}
_INLINE_SPECIFIER_ void ObjectTargetParameters::setScale(float size)
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_ObjectTargetParameters_setScale(this->cdata_.get(), size);
}

_INLINE_SPECIFIER_ ObjectTarget::ObjectTarget(std::shared_ptr<easyar_ObjectTarget> cdata)
    :
    Target(std::shared_ptr<easyar_Target>(nullptr)),
    cdata_(nullptr)
{
    init_cdata(cdata);
}
_INLINE_SPECIFIER_ ObjectTarget::~ObjectTarget()
{
    cdata_ = nullptr;
}

_INLINE_SPECIFIER_ std::shared_ptr<easyar_ObjectTarget> ObjectTarget::get_cdata()
{
    return cdata_;
}
_INLINE_SPECIFIER_ void ObjectTarget::init_cdata(std::shared_ptr<easyar_ObjectTarget> cdata)
{
    cdata_ = cdata;
    {
        easyar_Target * ptr = nullptr;
        easyar_castObjectTargetToTarget(cdata_.get(), &ptr);
        Target::init_cdata(std::shared_ptr<easyar_Target>(ptr, [](easyar_Target * ptr) { easyar_Target__dtor(ptr); }));
    }
}
_INLINE_SPECIFIER_ std::shared_ptr<ObjectTarget> ObjectTarget::from_cdata(std::shared_ptr<easyar_ObjectTarget> cdata)
{
    if (cdata == nullptr) {
        return nullptr;
    }
    return std::make_shared<ObjectTarget>(cdata);
}
_INLINE_SPECIFIER_ ObjectTarget::ObjectTarget()
    :
    Target(std::shared_ptr<easyar_Target>(nullptr)),
    cdata_(nullptr)
{
    easyar_ObjectTarget * _return_value_;
    easyar_ObjectTarget__ctor(&_return_value_);
    if (!(_return_value_ != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    init_cdata(std::shared_ptr<easyar_ObjectTarget>(_return_value_, [](easyar_ObjectTarget * ptr) { easyar_ObjectTarget__dtor(ptr); }));
}
_INLINE_SPECIFIER_ std::optional<std::shared_ptr<ObjectTarget>> ObjectTarget::createFromParameters(std::shared_ptr<ObjectTargetParameters> parameters)
{
    if (!(parameters != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: parameters");
#else
        std::terminate();
#endif
    }
    easyar_OptionalOfObjectTarget _return_value_;
    easyar_ObjectTarget_createFromParameters(parameters->get_cdata().get(), &_return_value_);
    if (!(!_return_value_.has_value || (_return_value_.value != nullptr))) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    return (_return_value_.has_value ? ObjectTarget::from_cdata(std::shared_ptr<easyar_ObjectTarget>(_return_value_.value, [](easyar_ObjectTarget * ptr) { easyar_ObjectTarget__dtor(ptr); })) : std::optional<std::shared_ptr<ObjectTarget>>{});
}
_INLINE_SPECIFIER_ std::optional<std::shared_ptr<ObjectTarget>> ObjectTarget::createFromObjectFile(std::string path, StorageType storageType, std::string name, std::string uid, std::string meta, float scale)
{
    easyar_OptionalOfObjectTarget _return_value_;
    easyar_ObjectTarget_createFromObjectFile(std_string_to_easyar_String(path).get(), static_cast<easyar_StorageType>(storageType), std_string_to_easyar_String(name).get(), std_string_to_easyar_String(uid).get(), std_string_to_easyar_String(meta).get(), scale, &_return_value_);
    if (!(!_return_value_.has_value || (_return_value_.value != nullptr))) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    return (_return_value_.has_value ? ObjectTarget::from_cdata(std::shared_ptr<easyar_ObjectTarget>(_return_value_.value, [](easyar_ObjectTarget * ptr) { easyar_ObjectTarget__dtor(ptr); })) : std::optional<std::shared_ptr<ObjectTarget>>{});
}
_INLINE_SPECIFIER_ float ObjectTarget::scale()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_ObjectTarget_scale(this->cdata_.get());
    return _return_value_;
}
_INLINE_SPECIFIER_ std::vector<Vec3F> ObjectTarget::boundingBox()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_ListOfVec3F * _return_value_;
    easyar_ObjectTarget_boundingBox(this->cdata_.get(), &_return_value_);
    if (!(_return_value_ != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    return std_vector_from_easyar_ListOfVec3F(std::shared_ptr<easyar_ListOfVec3F>(_return_value_, [](easyar_ListOfVec3F * ptr) { easyar_ListOfVec3F__dtor(ptr); }));
}
_INLINE_SPECIFIER_ bool ObjectTarget::setScale(float scale)
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_ObjectTarget_setScale(this->cdata_.get(), scale);
    return _return_value_;
}
_INLINE_SPECIFIER_ int ObjectTarget::runtimeID()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_ObjectTarget_runtimeID(this->cdata_.get());
    return _return_value_;
}
_INLINE_SPECIFIER_ std::string ObjectTarget::uid()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_String * _return_value_;
    easyar_ObjectTarget_uid(this->cdata_.get(), &_return_value_);
    if (!(_return_value_ != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    return std_string_from_easyar_String(std::shared_ptr<easyar_String>(_return_value_, [](easyar_String * ptr) { easyar_String__dtor(ptr); }));
}
_INLINE_SPECIFIER_ std::string ObjectTarget::name()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_String * _return_value_;
    easyar_ObjectTarget_name(this->cdata_.get(), &_return_value_);
    if (!(_return_value_ != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    return std_string_from_easyar_String(std::shared_ptr<easyar_String>(_return_value_, [](easyar_String * ptr) { easyar_String__dtor(ptr); }));
}
_INLINE_SPECIFIER_ void ObjectTarget::setName(std::string name)
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_ObjectTarget_setName(this->cdata_.get(), std_string_to_easyar_String(name).get());
}
_INLINE_SPECIFIER_ std::string ObjectTarget::meta()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_String * _return_value_;
    easyar_ObjectTarget_meta(this->cdata_.get(), &_return_value_);
    if (!(_return_value_ != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    return std_string_from_easyar_String(std::shared_ptr<easyar_String>(_return_value_, [](easyar_String * ptr) { easyar_String__dtor(ptr); }));
}
_INLINE_SPECIFIER_ void ObjectTarget::setMeta(std::string data)
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_ObjectTarget_setMeta(this->cdata_.get(), std_string_to_easyar_String(data).get());
}

_INLINE_SPECIFIER_ ObjectTrackerResult::ObjectTrackerResult(std::shared_ptr<easyar_ObjectTrackerResult> cdata)
    :
    TargetTrackerResult(std::shared_ptr<easyar_TargetTrackerResult>(nullptr)),
    cdata_(nullptr)
{
    init_cdata(cdata);
}
_INLINE_SPECIFIER_ ObjectTrackerResult::~ObjectTrackerResult()
{
    cdata_ = nullptr;
}

_INLINE_SPECIFIER_ std::shared_ptr<easyar_ObjectTrackerResult> ObjectTrackerResult::get_cdata()
{
    return cdata_;
}
_INLINE_SPECIFIER_ void ObjectTrackerResult::init_cdata(std::shared_ptr<easyar_ObjectTrackerResult> cdata)
{
    cdata_ = cdata;
    {
        easyar_TargetTrackerResult * ptr = nullptr;
        easyar_castObjectTrackerResultToTargetTrackerResult(cdata_.get(), &ptr);
        TargetTrackerResult::init_cdata(std::shared_ptr<easyar_TargetTrackerResult>(ptr, [](easyar_TargetTrackerResult * ptr) { easyar_TargetTrackerResult__dtor(ptr); }));
    }
}
_INLINE_SPECIFIER_ std::shared_ptr<ObjectTrackerResult> ObjectTrackerResult::from_cdata(std::shared_ptr<easyar_ObjectTrackerResult> cdata)
{
    if (cdata == nullptr) {
        return nullptr;
    }
    return std::make_shared<ObjectTrackerResult>(cdata);
}
_INLINE_SPECIFIER_ std::vector<std::shared_ptr<TargetInstance>> ObjectTrackerResult::targetInstances()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_ListOfTargetInstance * _return_value_;
    easyar_ObjectTrackerResult_targetInstances(this->cdata_.get(), &_return_value_);
    if (!(_return_value_ != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    return std_vector_from_easyar_ListOfTargetInstance(std::shared_ptr<easyar_ListOfTargetInstance>(_return_value_, [](easyar_ListOfTargetInstance * ptr) { easyar_ListOfTargetInstance__dtor(ptr); }));
}
_INLINE_SPECIFIER_ void ObjectTrackerResult::setTargetInstances(std::vector<std::shared_ptr<TargetInstance>> instances)
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    if (!easyar_ListOfTargetInstance_check_external_cpp(instances)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: instances");
#else
        std::terminate();
#endif
    }
    easyar_ObjectTrackerResult_setTargetInstances(this->cdata_.get(), std_vector_to_easyar_ListOfTargetInstance(instances).get());
}

_INLINE_SPECIFIER_ ObjectTracker::ObjectTracker(std::shared_ptr<easyar_ObjectTracker> cdata)
    :
    cdata_(nullptr)
{
    init_cdata(cdata);
}
_INLINE_SPECIFIER_ ObjectTracker::~ObjectTracker()
{
    cdata_ = nullptr;
}

_INLINE_SPECIFIER_ std::shared_ptr<easyar_ObjectTracker> ObjectTracker::get_cdata()
{
    return cdata_;
}
_INLINE_SPECIFIER_ void ObjectTracker::init_cdata(std::shared_ptr<easyar_ObjectTracker> cdata)
{
    cdata_ = cdata;
}
_INLINE_SPECIFIER_ std::shared_ptr<ObjectTracker> ObjectTracker::from_cdata(std::shared_ptr<easyar_ObjectTracker> cdata)
{
    if (cdata == nullptr) {
        return nullptr;
    }
    return std::make_shared<ObjectTracker>(cdata);
}
_INLINE_SPECIFIER_ bool ObjectTracker::isAvailable()
{
    auto _return_value_ = easyar_ObjectTracker_isAvailable();
    return _return_value_;
}
_INLINE_SPECIFIER_ std::shared_ptr<FeedbackFrameSink> ObjectTracker::feedbackFrameSink()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_FeedbackFrameSink * _return_value_;
    easyar_ObjectTracker_feedbackFrameSink(this->cdata_.get(), &_return_value_);
    if (!(_return_value_ != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    return FeedbackFrameSink::from_cdata(std::shared_ptr<easyar_FeedbackFrameSink>(_return_value_, [](easyar_FeedbackFrameSink * ptr) { easyar_FeedbackFrameSink__dtor(ptr); }));
}
_INLINE_SPECIFIER_ int ObjectTracker::bufferRequirement()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_ObjectTracker_bufferRequirement(this->cdata_.get());
    return _return_value_;
}
_INLINE_SPECIFIER_ std::shared_ptr<OutputFrameSource> ObjectTracker::outputFrameSource()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_OutputFrameSource * _return_value_;
    easyar_ObjectTracker_outputFrameSource(this->cdata_.get(), &_return_value_);
    if (!(_return_value_ != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    return OutputFrameSource::from_cdata(std::shared_ptr<easyar_OutputFrameSource>(_return_value_, [](easyar_OutputFrameSource * ptr) { easyar_OutputFrameSource__dtor(ptr); }));
}
_INLINE_SPECIFIER_ std::shared_ptr<ObjectTracker> ObjectTracker::create()
{
    easyar_ObjectTracker * _return_value_;
    easyar_ObjectTracker_create(&_return_value_);
    if (!(_return_value_ != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    return ObjectTracker::from_cdata(std::shared_ptr<easyar_ObjectTracker>(_return_value_, [](easyar_ObjectTracker * ptr) { easyar_ObjectTracker__dtor(ptr); }));
}
_INLINE_SPECIFIER_ void ObjectTracker::setResultPostProcessing(bool enablePersistentTargetInstance, bool enableMotionFusion)
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_ObjectTracker_setResultPostProcessing(this->cdata_.get(), enablePersistentTargetInstance, enableMotionFusion);
}
_INLINE_SPECIFIER_ bool ObjectTracker::setResultAsyncMode(bool enableAsync)
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_ObjectTracker_setResultAsyncMode(this->cdata_.get(), enableAsync);
    return _return_value_;
}
_INLINE_SPECIFIER_ bool ObjectTracker::start()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_ObjectTracker_start(this->cdata_.get());
    return _return_value_;
}
_INLINE_SPECIFIER_ void ObjectTracker::stop()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_ObjectTracker_stop(this->cdata_.get());
}
_INLINE_SPECIFIER_ void ObjectTracker::close()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_ObjectTracker_close(this->cdata_.get());
}
_INLINE_SPECIFIER_ void ObjectTracker::loadTarget(std::shared_ptr<Target> target, std::shared_ptr<CallbackScheduler> callbackScheduler, std::function<void(std::shared_ptr<Target>, bool)> callback)
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    if (!(target != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: target");
#else
        std::terminate();
#endif
    }
    if (!(callbackScheduler != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: callbackScheduler");
#else
        std::terminate();
#endif
    }
    if (!(callback != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: callback");
#else
        std::terminate();
#endif
    }
    easyar_ObjectTracker_loadTarget(this->cdata_.get(), target->get_cdata().get(), callbackScheduler->get_cdata().get(), FunctorOfVoidFromTargetAndBool_to_c(callback));
}
_INLINE_SPECIFIER_ void ObjectTracker::unloadTarget(std::shared_ptr<Target> target, std::shared_ptr<CallbackScheduler> callbackScheduler, std::function<void(std::shared_ptr<Target>, bool)> callback)
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    if (!(target != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: target");
#else
        std::terminate();
#endif
    }
    if (!(callbackScheduler != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: callbackScheduler");
#else
        std::terminate();
#endif
    }
    if (!(callback != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: callback");
#else
        std::terminate();
#endif
    }
    easyar_ObjectTracker_unloadTarget(this->cdata_.get(), target->get_cdata().get(), callbackScheduler->get_cdata().get(), FunctorOfVoidFromTargetAndBool_to_c(callback));
}
_INLINE_SPECIFIER_ std::vector<std::shared_ptr<Target>> ObjectTracker::targets()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_ListOfTarget * _return_value_;
    easyar_ObjectTracker_targets(this->cdata_.get(), &_return_value_);
    if (!(_return_value_ != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    return std_vector_from_easyar_ListOfTarget(std::shared_ptr<easyar_ListOfTarget>(_return_value_, [](easyar_ListOfTarget * ptr) { easyar_ListOfTarget__dtor(ptr); }));
}
_INLINE_SPECIFIER_ bool ObjectTracker::setSimultaneousNum(int num)
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_ObjectTracker_setSimultaneousNum(this->cdata_.get(), num);
    return _return_value_;
}
_INLINE_SPECIFIER_ int ObjectTracker::simultaneousNum()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_ObjectTracker_simultaneousNum(this->cdata_.get());
    return _return_value_;
}
_INLINE_SPECIFIER_ std::optional<std::shared_ptr<ObjectTrackerResult>> ObjectTracker::getSyncResult(std::shared_ptr<MotionInputData> motionInputData)
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    if (!(motionInputData != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: motionInputData");
#else
        std::terminate();
#endif
    }
    easyar_OptionalOfObjectTrackerResult _return_value_;
    easyar_ObjectTracker_getSyncResult(this->cdata_.get(), motionInputData->get_cdata().get(), &_return_value_);
    if (!(!_return_value_.has_value || (_return_value_.value != nullptr))) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    return (_return_value_.has_value ? ObjectTrackerResult::from_cdata(std::shared_ptr<easyar_ObjectTrackerResult>(_return_value_.value, [](easyar_ObjectTrackerResult * ptr) { easyar_ObjectTrackerResult__dtor(ptr); })) : std::optional<std::shared_ptr<ObjectTrackerResult>>{});
}

_INLINE_SPECIFIER_ ARCoreDeviceListDownloader::ARCoreDeviceListDownloader(std::shared_ptr<easyar_ARCoreDeviceListDownloader> cdata)
    :
    cdata_(nullptr)
{
    init_cdata(cdata);
}
_INLINE_SPECIFIER_ ARCoreDeviceListDownloader::~ARCoreDeviceListDownloader()
{
    cdata_ = nullptr;
}

_INLINE_SPECIFIER_ std::shared_ptr<easyar_ARCoreDeviceListDownloader> ARCoreDeviceListDownloader::get_cdata()
{
    return cdata_;
}
_INLINE_SPECIFIER_ void ARCoreDeviceListDownloader::init_cdata(std::shared_ptr<easyar_ARCoreDeviceListDownloader> cdata)
{
    cdata_ = cdata;
}
_INLINE_SPECIFIER_ std::shared_ptr<ARCoreDeviceListDownloader> ARCoreDeviceListDownloader::from_cdata(std::shared_ptr<easyar_ARCoreDeviceListDownloader> cdata)
{
    if (cdata == nullptr) {
        return nullptr;
    }
    return std::make_shared<ARCoreDeviceListDownloader>(cdata);
}
_INLINE_SPECIFIER_ ARCoreDeviceListDownloader::ARCoreDeviceListDownloader()
    :
    cdata_(nullptr)
{
    easyar_ARCoreDeviceListDownloader * _return_value_;
    easyar_ARCoreDeviceListDownloader__ctor(&_return_value_);
    if (!(_return_value_ != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    init_cdata(std::shared_ptr<easyar_ARCoreDeviceListDownloader>(_return_value_, [](easyar_ARCoreDeviceListDownloader * ptr) { easyar_ARCoreDeviceListDownloader__dtor(ptr); }));
}
_INLINE_SPECIFIER_ void ARCoreDeviceListDownloader::download(std::optional<int> timeoutMilliseconds, std::shared_ptr<CallbackScheduler> callbackScheduler, std::function<void(ARCoreDeviceListDownloadStatus, std::optional<std::string>)> onCompleted)
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    if (!(callbackScheduler != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: callbackScheduler");
#else
        std::terminate();
#endif
    }
    if (!(onCompleted != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: onCompleted");
#else
        std::terminate();
#endif
    }
    easyar_ARCoreDeviceListDownloader_download(this->cdata_.get(), (timeoutMilliseconds.has_value() ? easyar_OptionalOfInt{true, timeoutMilliseconds.value()} : easyar_OptionalOfInt{false, {}}), callbackScheduler->get_cdata().get(), FunctorOfVoidFromARCoreDeviceListDownloadStatusAndOptionalOfString_to_c(onCompleted));
}

_INLINE_SPECIFIER_ CalibrationDownloader::CalibrationDownloader(std::shared_ptr<easyar_CalibrationDownloader> cdata)
    :
    cdata_(nullptr)
{
    init_cdata(cdata);
}
_INLINE_SPECIFIER_ CalibrationDownloader::~CalibrationDownloader()
{
    cdata_ = nullptr;
}

_INLINE_SPECIFIER_ std::shared_ptr<easyar_CalibrationDownloader> CalibrationDownloader::get_cdata()
{
    return cdata_;
}
_INLINE_SPECIFIER_ void CalibrationDownloader::init_cdata(std::shared_ptr<easyar_CalibrationDownloader> cdata)
{
    cdata_ = cdata;
}
_INLINE_SPECIFIER_ std::shared_ptr<CalibrationDownloader> CalibrationDownloader::from_cdata(std::shared_ptr<easyar_CalibrationDownloader> cdata)
{
    if (cdata == nullptr) {
        return nullptr;
    }
    return std::make_shared<CalibrationDownloader>(cdata);
}
_INLINE_SPECIFIER_ CalibrationDownloader::CalibrationDownloader()
    :
    cdata_(nullptr)
{
    easyar_CalibrationDownloader * _return_value_;
    easyar_CalibrationDownloader__ctor(&_return_value_);
    if (!(_return_value_ != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    init_cdata(std::shared_ptr<easyar_CalibrationDownloader>(_return_value_, [](easyar_CalibrationDownloader * ptr) { easyar_CalibrationDownloader__dtor(ptr); }));
}
_INLINE_SPECIFIER_ void CalibrationDownloader::download(std::optional<int> timeoutMilliseconds, std::shared_ptr<CallbackScheduler> callbackScheduler, std::function<void(CalibrationDownloadStatus, std::optional<std::string>)> onCompleted)
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    if (!(callbackScheduler != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: callbackScheduler");
#else
        std::terminate();
#endif
    }
    if (!(onCompleted != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: onCompleted");
#else
        std::terminate();
#endif
    }
    easyar_CalibrationDownloader_download(this->cdata_.get(), (timeoutMilliseconds.has_value() ? easyar_OptionalOfInt{true, timeoutMilliseconds.value()} : easyar_OptionalOfInt{false, {}}), callbackScheduler->get_cdata().get(), FunctorOfVoidFromCalibrationDownloadStatusAndOptionalOfString_to_c(onCompleted));
}

_INLINE_SPECIFIER_ CloudLocalizerBlockInstance::CloudLocalizerBlockInstance(std::shared_ptr<easyar_CloudLocalizerBlockInstance> cdata)
    :
    cdata_(nullptr)
{
    init_cdata(cdata);
}
_INLINE_SPECIFIER_ CloudLocalizerBlockInstance::~CloudLocalizerBlockInstance()
{
    cdata_ = nullptr;
}

_INLINE_SPECIFIER_ std::shared_ptr<easyar_CloudLocalizerBlockInstance> CloudLocalizerBlockInstance::get_cdata()
{
    return cdata_;
}
_INLINE_SPECIFIER_ void CloudLocalizerBlockInstance::init_cdata(std::shared_ptr<easyar_CloudLocalizerBlockInstance> cdata)
{
    cdata_ = cdata;
}
_INLINE_SPECIFIER_ std::shared_ptr<CloudLocalizerBlockInstance> CloudLocalizerBlockInstance::from_cdata(std::shared_ptr<easyar_CloudLocalizerBlockInstance> cdata)
{
    if (cdata == nullptr) {
        return nullptr;
    }
    return std::make_shared<CloudLocalizerBlockInstance>(cdata);
}
_INLINE_SPECIFIER_ std::string CloudLocalizerBlockInstance::blockId()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_String * _return_value_;
    easyar_CloudLocalizerBlockInstance_blockId(this->cdata_.get(), &_return_value_);
    if (!(_return_value_ != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    return std_string_from_easyar_String(std::shared_ptr<easyar_String>(_return_value_, [](easyar_String * ptr) { easyar_String__dtor(ptr); }));
}
_INLINE_SPECIFIER_ std::string CloudLocalizerBlockInstance::name()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_String * _return_value_;
    easyar_CloudLocalizerBlockInstance_name(this->cdata_.get(), &_return_value_);
    if (!(_return_value_ != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    return std_string_from_easyar_String(std::shared_ptr<easyar_String>(_return_value_, [](easyar_String * ptr) { easyar_String__dtor(ptr); }));
}
_INLINE_SPECIFIER_ Matrix44F CloudLocalizerBlockInstance::pose()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_CloudLocalizerBlockInstance_pose(this->cdata_.get());
    return Matrix44F{{{_return_value_.data[0], _return_value_.data[1], _return_value_.data[2], _return_value_.data[3], _return_value_.data[4], _return_value_.data[5], _return_value_.data[6], _return_value_.data[7], _return_value_.data[8], _return_value_.data[9], _return_value_.data[10], _return_value_.data[11], _return_value_.data[12], _return_value_.data[13], _return_value_.data[14], _return_value_.data[15]}}};
}

_INLINE_SPECIFIER_ CloudLocalizerResult::CloudLocalizerResult(std::shared_ptr<easyar_CloudLocalizerResult> cdata)
    :
    cdata_(nullptr)
{
    init_cdata(cdata);
}
_INLINE_SPECIFIER_ CloudLocalizerResult::~CloudLocalizerResult()
{
    cdata_ = nullptr;
}

_INLINE_SPECIFIER_ std::shared_ptr<easyar_CloudLocalizerResult> CloudLocalizerResult::get_cdata()
{
    return cdata_;
}
_INLINE_SPECIFIER_ void CloudLocalizerResult::init_cdata(std::shared_ptr<easyar_CloudLocalizerResult> cdata)
{
    cdata_ = cdata;
}
_INLINE_SPECIFIER_ std::shared_ptr<CloudLocalizerResult> CloudLocalizerResult::from_cdata(std::shared_ptr<easyar_CloudLocalizerResult> cdata)
{
    if (cdata == nullptr) {
        return nullptr;
    }
    return std::make_shared<CloudLocalizerResult>(cdata);
}
_INLINE_SPECIFIER_ CloudLocalizerStatus CloudLocalizerResult::localizeStatus()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_CloudLocalizerResult_localizeStatus(this->cdata_.get());
    return static_cast<CloudLocalizerStatus>(_return_value_);
}
_INLINE_SPECIFIER_ std::optional<std::string> CloudLocalizerResult::spotVersionId()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_OptionalOfString _return_value_;
    easyar_CloudLocalizerResult_spotVersionId(this->cdata_.get(), &_return_value_);
    if (!(!_return_value_.has_value || (_return_value_.value != nullptr))) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    return (_return_value_.has_value ? std_string_from_easyar_String(std::shared_ptr<easyar_String>(_return_value_.value, [](easyar_String * ptr) { easyar_String__dtor(ptr); })) : std::optional<std::string>{});
}
_INLINE_SPECIFIER_ std::vector<std::shared_ptr<CloudLocalizerBlockInstance>> CloudLocalizerResult::blockInstances()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_ListOfCloudLocalizerBlockInstance * _return_value_;
    easyar_CloudLocalizerResult_blockInstances(this->cdata_.get(), &_return_value_);
    if (!(_return_value_ != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    return std_vector_from_easyar_ListOfCloudLocalizerBlockInstance(std::shared_ptr<easyar_ListOfCloudLocalizerBlockInstance>(_return_value_, [](easyar_ListOfCloudLocalizerBlockInstance * ptr) { easyar_ListOfCloudLocalizerBlockInstance__dtor(ptr); }));
}
_INLINE_SPECIFIER_ std::string CloudLocalizerResult::extraInfo()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_String * _return_value_;
    easyar_CloudLocalizerResult_extraInfo(this->cdata_.get(), &_return_value_);
    if (!(_return_value_ != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    return std_string_from_easyar_String(std::shared_ptr<easyar_String>(_return_value_, [](easyar_String * ptr) { easyar_String__dtor(ptr); }));
}
_INLINE_SPECIFIER_ std::string CloudLocalizerResult::exceptionInfo()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_String * _return_value_;
    easyar_CloudLocalizerResult_exceptionInfo(this->cdata_.get(), &_return_value_);
    if (!(_return_value_ != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    return std_string_from_easyar_String(std::shared_ptr<easyar_String>(_return_value_, [](easyar_String * ptr) { easyar_String__dtor(ptr); }));
}
_INLINE_SPECIFIER_ std::optional<double> CloudLocalizerResult::serverResponseDuration()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_CloudLocalizerResult_serverResponseDuration(this->cdata_.get());
    return (_return_value_.has_value ? _return_value_.value : std::optional<double>{});
}
_INLINE_SPECIFIER_ std::optional<double> CloudLocalizerResult::serverCalculationDuration()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_CloudLocalizerResult_serverCalculationDuration(this->cdata_.get());
    return (_return_value_.has_value ? _return_value_.value : std::optional<double>{});
}

_INLINE_SPECIFIER_ DeviceAuxiliaryInfo::DeviceAuxiliaryInfo(std::shared_ptr<easyar_DeviceAuxiliaryInfo> cdata)
    :
    cdata_(nullptr)
{
    init_cdata(cdata);
}
_INLINE_SPECIFIER_ DeviceAuxiliaryInfo::~DeviceAuxiliaryInfo()
{
    cdata_ = nullptr;
}

_INLINE_SPECIFIER_ std::shared_ptr<easyar_DeviceAuxiliaryInfo> DeviceAuxiliaryInfo::get_cdata()
{
    return cdata_;
}
_INLINE_SPECIFIER_ void DeviceAuxiliaryInfo::init_cdata(std::shared_ptr<easyar_DeviceAuxiliaryInfo> cdata)
{
    cdata_ = cdata;
}
_INLINE_SPECIFIER_ std::shared_ptr<DeviceAuxiliaryInfo> DeviceAuxiliaryInfo::from_cdata(std::shared_ptr<easyar_DeviceAuxiliaryInfo> cdata)
{
    if (cdata == nullptr) {
        return nullptr;
    }
    return std::make_shared<DeviceAuxiliaryInfo>(cdata);
}
_INLINE_SPECIFIER_ std::shared_ptr<DeviceAuxiliaryInfo> DeviceAuxiliaryInfo::create()
{
    easyar_DeviceAuxiliaryInfo * _return_value_;
    easyar_DeviceAuxiliaryInfo_create(&_return_value_);
    if (!(_return_value_ != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    return DeviceAuxiliaryInfo::from_cdata(std::shared_ptr<easyar_DeviceAuxiliaryInfo>(_return_value_, [](easyar_DeviceAuxiliaryInfo * ptr) { easyar_DeviceAuxiliaryInfo__dtor(ptr); }));
}
_INLINE_SPECIFIER_ void DeviceAuxiliaryInfo::setAcceleration(AccelerometerResult acce)
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_DeviceAuxiliaryInfo_setAcceleration(this->cdata_.get(), easyar_AccelerometerResult{acce.x, acce.y, acce.z, acce.timestamp});
}
_INLINE_SPECIFIER_ void DeviceAuxiliaryInfo::setGPSLocation(LocationResult gps)
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_DeviceAuxiliaryInfo_setGPSLocation(this->cdata_.get(), easyar_LocationResult{gps.latitude, gps.longitude, gps.altitude, gps.horizontalAccuracy, gps.verticalAccuracy, gps.hasAltitude, gps.hasHorizontalAccuracy, gps.hasVerticalAccuracy});
}
_INLINE_SPECIFIER_ void DeviceAuxiliaryInfo::setProximityLocation(ProximityLocationResult proximity)
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_DeviceAuxiliaryInfo_setProximityLocation(this->cdata_.get(), easyar_ProximityLocationResult{proximity.x, proximity.y, proximity.z, proximity.accuracy, proximity.timestamp, proximity.is2d, proximity.validTime});
}
_INLINE_SPECIFIER_ void DeviceAuxiliaryInfo::setBlockPrior(std::shared_ptr<BlockPriorResult> blockPrior)
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    if (!(blockPrior != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: blockPrior");
#else
        std::terminate();
#endif
    }
    easyar_DeviceAuxiliaryInfo_setBlockPrior(this->cdata_.get(), blockPrior->get_cdata().get());
}
_INLINE_SPECIFIER_ void DeviceAuxiliaryInfo::setECompass(double northHeading, double headingAccuracy)
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_DeviceAuxiliaryInfo_setECompass(this->cdata_.get(), northHeading, headingAccuracy);
}

_INLINE_SPECIFIER_ CloudLocalizer::CloudLocalizer(std::shared_ptr<easyar_CloudLocalizer> cdata)
    :
    cdata_(nullptr)
{
    init_cdata(cdata);
}
_INLINE_SPECIFIER_ CloudLocalizer::~CloudLocalizer()
{
    cdata_ = nullptr;
}

_INLINE_SPECIFIER_ std::shared_ptr<easyar_CloudLocalizer> CloudLocalizer::get_cdata()
{
    return cdata_;
}
_INLINE_SPECIFIER_ void CloudLocalizer::init_cdata(std::shared_ptr<easyar_CloudLocalizer> cdata)
{
    cdata_ = cdata;
}
_INLINE_SPECIFIER_ std::shared_ptr<CloudLocalizer> CloudLocalizer::from_cdata(std::shared_ptr<easyar_CloudLocalizer> cdata)
{
    if (cdata == nullptr) {
        return nullptr;
    }
    return std::make_shared<CloudLocalizer>(cdata);
}
_INLINE_SPECIFIER_ bool CloudLocalizer::isAvailable()
{
    auto _return_value_ = easyar_CloudLocalizer_isAvailable();
    return _return_value_;
}
_INLINE_SPECIFIER_ std::shared_ptr<CloudLocalizer> CloudLocalizer::create(std::string server, std::string apiKey, std::string apiSecret, std::string appId)
{
    easyar_CloudLocalizer * _return_value_;
    easyar_CloudLocalizer_create(std_string_to_easyar_String(server).get(), std_string_to_easyar_String(apiKey).get(), std_string_to_easyar_String(apiSecret).get(), std_string_to_easyar_String(appId).get(), &_return_value_);
    if (!(_return_value_ != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    return CloudLocalizer::from_cdata(std::shared_ptr<easyar_CloudLocalizer>(_return_value_, [](easyar_CloudLocalizer * ptr) { easyar_CloudLocalizer__dtor(ptr); }));
}
_INLINE_SPECIFIER_ std::shared_ptr<CloudLocalizer> CloudLocalizer::createWithToken(std::string server, std::string apiToken, std::string appId)
{
    easyar_CloudLocalizer * _return_value_;
    easyar_CloudLocalizer_createWithToken(std_string_to_easyar_String(server).get(), std_string_to_easyar_String(apiToken).get(), std_string_to_easyar_String(appId).get(), &_return_value_);
    if (!(_return_value_ != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    return CloudLocalizer::from_cdata(std::shared_ptr<easyar_CloudLocalizer>(_return_value_, [](easyar_CloudLocalizer * ptr) { easyar_CloudLocalizer__dtor(ptr); }));
}
_INLINE_SPECIFIER_ void CloudLocalizer::updateToken(std::string apiToken)
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_CloudLocalizer_updateToken(this->cdata_.get(), std_string_to_easyar_String(apiToken).get());
}
_INLINE_SPECIFIER_ void CloudLocalizer::setMegaApiType(MegaApiType type)
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_CloudLocalizer_setMegaApiType(this->cdata_.get(), static_cast<easyar_MegaApiType>(type));
}
_INLINE_SPECIFIER_ void CloudLocalizer::resolve(std::shared_ptr<InputFrame> inputFrame, std::string message, std::shared_ptr<DeviceAuxiliaryInfo> deviceAuxInfo, std::optional<int> timeoutMilliseconds, std::shared_ptr<CallbackScheduler> callbackScheduler, std::function<void(std::shared_ptr<CloudLocalizerResult>)> callback)
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    if (!(inputFrame != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: inputFrame");
#else
        std::terminate();
#endif
    }
    if (!(deviceAuxInfo != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: deviceAuxInfo");
#else
        std::terminate();
#endif
    }
    if (!(callbackScheduler != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: callbackScheduler");
#else
        std::terminate();
#endif
    }
    if (!(callback != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: callback");
#else
        std::terminate();
#endif
    }
    easyar_CloudLocalizer_resolve(this->cdata_.get(), inputFrame->get_cdata().get(), std_string_to_easyar_String(message).get(), deviceAuxInfo->get_cdata().get(), (timeoutMilliseconds.has_value() ? easyar_OptionalOfInt{true, timeoutMilliseconds.value()} : easyar_OptionalOfInt{false, {}}), callbackScheduler->get_cdata().get(), FunctorOfVoidFromCloudLocalizerResult_to_c(callback));
}
_INLINE_SPECIFIER_ void CloudLocalizer::resolveLandmark(std::shared_ptr<InputFrame> inputFrame, std::string message, std::shared_ptr<DeviceAuxiliaryInfo> deviceAuxInfo, std::string spotVersionId, std::optional<int> timeoutMilliseconds, std::shared_ptr<CallbackScheduler> callbackScheduler, std::function<void(std::shared_ptr<CloudLocalizerResult>)> callback)
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    if (!(inputFrame != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: inputFrame");
#else
        std::terminate();
#endif
    }
    if (!(deviceAuxInfo != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: deviceAuxInfo");
#else
        std::terminate();
#endif
    }
    if (!(callbackScheduler != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: callbackScheduler");
#else
        std::terminate();
#endif
    }
    if (!(callback != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: callback");
#else
        std::terminate();
#endif
    }
    easyar_CloudLocalizer_resolveLandmark(this->cdata_.get(), inputFrame->get_cdata().get(), std_string_to_easyar_String(message).get(), deviceAuxInfo->get_cdata().get(), std_string_to_easyar_String(spotVersionId).get(), (timeoutMilliseconds.has_value() ? easyar_OptionalOfInt{true, timeoutMilliseconds.value()} : easyar_OptionalOfInt{false, {}}), callbackScheduler->get_cdata().get(), FunctorOfVoidFromCloudLocalizerResult_to_c(callback));
}
_INLINE_SPECIFIER_ void CloudLocalizer::close()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_CloudLocalizer_close(this->cdata_.get());
}

_INLINE_SPECIFIER_ MegaLandmarkFilterResult::MegaLandmarkFilterResult(std::shared_ptr<easyar_MegaLandmarkFilterResult> cdata)
    :
    cdata_(nullptr)
{
    init_cdata(cdata);
}
_INLINE_SPECIFIER_ MegaLandmarkFilterResult::~MegaLandmarkFilterResult()
{
    cdata_ = nullptr;
}

_INLINE_SPECIFIER_ std::shared_ptr<easyar_MegaLandmarkFilterResult> MegaLandmarkFilterResult::get_cdata()
{
    return cdata_;
}
_INLINE_SPECIFIER_ void MegaLandmarkFilterResult::init_cdata(std::shared_ptr<easyar_MegaLandmarkFilterResult> cdata)
{
    cdata_ = cdata;
}
_INLINE_SPECIFIER_ std::shared_ptr<MegaLandmarkFilterResult> MegaLandmarkFilterResult::from_cdata(std::shared_ptr<easyar_MegaLandmarkFilterResult> cdata)
{
    if (cdata == nullptr) {
        return nullptr;
    }
    return std::make_shared<MegaLandmarkFilterResult>(cdata);
}
_INLINE_SPECIFIER_ MegaLandmarkFilterStatus MegaLandmarkFilterResult::status()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_MegaLandmarkFilterResult_status(this->cdata_.get());
    return static_cast<MegaLandmarkFilterStatus>(_return_value_);
}
_INLINE_SPECIFIER_ std::optional<std::string> MegaLandmarkFilterResult::spotVersionId()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_OptionalOfString _return_value_;
    easyar_MegaLandmarkFilterResult_spotVersionId(this->cdata_.get(), &_return_value_);
    if (!(!_return_value_.has_value || (_return_value_.value != nullptr))) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    return (_return_value_.has_value ? std_string_from_easyar_String(std::shared_ptr<easyar_String>(_return_value_.value, [](easyar_String * ptr) { easyar_String__dtor(ptr); })) : std::optional<std::string>{});
}
_INLINE_SPECIFIER_ std::string MegaLandmarkFilterResult::exceptionInfo()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_String * _return_value_;
    easyar_MegaLandmarkFilterResult_exceptionInfo(this->cdata_.get(), &_return_value_);
    if (!(_return_value_ != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    return std_string_from_easyar_String(std::shared_ptr<easyar_String>(_return_value_, [](easyar_String * ptr) { easyar_String__dtor(ptr); }));
}

_INLINE_SPECIFIER_ MegaLandmarkFilter::MegaLandmarkFilter(std::shared_ptr<easyar_MegaLandmarkFilter> cdata)
    :
    cdata_(nullptr)
{
    init_cdata(cdata);
}
_INLINE_SPECIFIER_ MegaLandmarkFilter::~MegaLandmarkFilter()
{
    cdata_ = nullptr;
}

_INLINE_SPECIFIER_ std::shared_ptr<easyar_MegaLandmarkFilter> MegaLandmarkFilter::get_cdata()
{
    return cdata_;
}
_INLINE_SPECIFIER_ void MegaLandmarkFilter::init_cdata(std::shared_ptr<easyar_MegaLandmarkFilter> cdata)
{
    cdata_ = cdata;
}
_INLINE_SPECIFIER_ std::shared_ptr<MegaLandmarkFilter> MegaLandmarkFilter::from_cdata(std::shared_ptr<easyar_MegaLandmarkFilter> cdata)
{
    if (cdata == nullptr) {
        return nullptr;
    }
    return std::make_shared<MegaLandmarkFilter>(cdata);
}
_INLINE_SPECIFIER_ bool MegaLandmarkFilter::isAvailable()
{
    auto _return_value_ = easyar_MegaLandmarkFilter_isAvailable();
    return _return_value_;
}
_INLINE_SPECIFIER_ std::shared_ptr<MegaLandmarkFilter> MegaLandmarkFilter::create(std::string server, std::string apiKey, std::string apiSecret, std::string appId)
{
    easyar_MegaLandmarkFilter * _return_value_;
    easyar_MegaLandmarkFilter_create(std_string_to_easyar_String(server).get(), std_string_to_easyar_String(apiKey).get(), std_string_to_easyar_String(apiSecret).get(), std_string_to_easyar_String(appId).get(), &_return_value_);
    if (!(_return_value_ != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    return MegaLandmarkFilter::from_cdata(std::shared_ptr<easyar_MegaLandmarkFilter>(_return_value_, [](easyar_MegaLandmarkFilter * ptr) { easyar_MegaLandmarkFilter__dtor(ptr); }));
}
_INLINE_SPECIFIER_ std::shared_ptr<MegaLandmarkFilter> MegaLandmarkFilter::createWithToken(std::string server, std::string apiToken, std::string appId)
{
    easyar_MegaLandmarkFilter * _return_value_;
    easyar_MegaLandmarkFilter_createWithToken(std_string_to_easyar_String(server).get(), std_string_to_easyar_String(apiToken).get(), std_string_to_easyar_String(appId).get(), &_return_value_);
    if (!(_return_value_ != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    return MegaLandmarkFilter::from_cdata(std::shared_ptr<easyar_MegaLandmarkFilter>(_return_value_, [](easyar_MegaLandmarkFilter * ptr) { easyar_MegaLandmarkFilter__dtor(ptr); }));
}
_INLINE_SPECIFIER_ void MegaLandmarkFilter::updateToken(std::string apiToken)
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_MegaLandmarkFilter_updateToken(this->cdata_.get(), std_string_to_easyar_String(apiToken).get());
}
_INLINE_SPECIFIER_ void MegaLandmarkFilter::filterByLocation(LocationResult gps, std::optional<int> timeoutMilliseconds, std::shared_ptr<CallbackScheduler> callbackScheduler, std::function<void(std::shared_ptr<MegaLandmarkFilterResult>)> callback)
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    if (!(callbackScheduler != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: callbackScheduler");
#else
        std::terminate();
#endif
    }
    if (!(callback != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: callback");
#else
        std::terminate();
#endif
    }
    easyar_MegaLandmarkFilter_filterByLocation(this->cdata_.get(), easyar_LocationResult{gps.latitude, gps.longitude, gps.altitude, gps.horizontalAccuracy, gps.verticalAccuracy, gps.hasAltitude, gps.hasHorizontalAccuracy, gps.hasVerticalAccuracy}, (timeoutMilliseconds.has_value() ? easyar_OptionalOfInt{true, timeoutMilliseconds.value()} : easyar_OptionalOfInt{false, {}}), callbackScheduler->get_cdata().get(), FunctorOfVoidFromMegaLandmarkFilterResult_to_c(callback));
}
_INLINE_SPECIFIER_ void MegaLandmarkFilter::filterBySpotId(std::string spotId, std::optional<int> timeoutMilliseconds, std::shared_ptr<CallbackScheduler> callbackScheduler, std::function<void(std::shared_ptr<MegaLandmarkFilterResult>)> callback)
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    if (!(callbackScheduler != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: callbackScheduler");
#else
        std::terminate();
#endif
    }
    if (!(callback != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: callback");
#else
        std::terminate();
#endif
    }
    easyar_MegaLandmarkFilter_filterBySpotId(this->cdata_.get(), std_string_to_easyar_String(spotId).get(), (timeoutMilliseconds.has_value() ? easyar_OptionalOfInt{true, timeoutMilliseconds.value()} : easyar_OptionalOfInt{false, {}}), callbackScheduler->get_cdata().get(), FunctorOfVoidFromMegaLandmarkFilterResult_to_c(callback));
}
_INLINE_SPECIFIER_ void MegaLandmarkFilter::close()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_MegaLandmarkFilter_close(this->cdata_.get());
}

_INLINE_SPECIFIER_ MegaTrackerBlockInstance::MegaTrackerBlockInstance(std::shared_ptr<easyar_MegaTrackerBlockInstance> cdata)
    :
    cdata_(nullptr)
{
    init_cdata(cdata);
}
_INLINE_SPECIFIER_ MegaTrackerBlockInstance::~MegaTrackerBlockInstance()
{
    cdata_ = nullptr;
}

_INLINE_SPECIFIER_ std::shared_ptr<easyar_MegaTrackerBlockInstance> MegaTrackerBlockInstance::get_cdata()
{
    return cdata_;
}
_INLINE_SPECIFIER_ void MegaTrackerBlockInstance::init_cdata(std::shared_ptr<easyar_MegaTrackerBlockInstance> cdata)
{
    cdata_ = cdata;
}
_INLINE_SPECIFIER_ std::shared_ptr<MegaTrackerBlockInstance> MegaTrackerBlockInstance::from_cdata(std::shared_ptr<easyar_MegaTrackerBlockInstance> cdata)
{
    if (cdata == nullptr) {
        return nullptr;
    }
    return std::make_shared<MegaTrackerBlockInstance>(cdata);
}
_INLINE_SPECIFIER_ std::string MegaTrackerBlockInstance::appId()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_String * _return_value_;
    easyar_MegaTrackerBlockInstance_appId(this->cdata_.get(), &_return_value_);
    if (!(_return_value_ != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    return std_string_from_easyar_String(std::shared_ptr<easyar_String>(_return_value_, [](easyar_String * ptr) { easyar_String__dtor(ptr); }));
}
_INLINE_SPECIFIER_ std::string MegaTrackerBlockInstance::blockId()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_String * _return_value_;
    easyar_MegaTrackerBlockInstance_blockId(this->cdata_.get(), &_return_value_);
    if (!(_return_value_ != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    return std_string_from_easyar_String(std::shared_ptr<easyar_String>(_return_value_, [](easyar_String * ptr) { easyar_String__dtor(ptr); }));
}
_INLINE_SPECIFIER_ std::string MegaTrackerBlockInstance::name()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_String * _return_value_;
    easyar_MegaTrackerBlockInstance_name(this->cdata_.get(), &_return_value_);
    if (!(_return_value_ != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    return std_string_from_easyar_String(std::shared_ptr<easyar_String>(_return_value_, [](easyar_String * ptr) { easyar_String__dtor(ptr); }));
}
_INLINE_SPECIFIER_ Matrix44F MegaTrackerBlockInstance::pose()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_MegaTrackerBlockInstance_pose(this->cdata_.get());
    return Matrix44F{{{_return_value_.data[0], _return_value_.data[1], _return_value_.data[2], _return_value_.data[3], _return_value_.data[4], _return_value_.data[5], _return_value_.data[6], _return_value_.data[7], _return_value_.data[8], _return_value_.data[9], _return_value_.data[10], _return_value_.data[11], _return_value_.data[12], _return_value_.data[13], _return_value_.data[14], _return_value_.data[15]}}};
}

_INLINE_SPECIFIER_ MegaTrackerResult::MegaTrackerResult(std::shared_ptr<easyar_MegaTrackerResult> cdata)
    :
    FrameFilterResult(std::shared_ptr<easyar_FrameFilterResult>(nullptr)),
    cdata_(nullptr)
{
    init_cdata(cdata);
}
_INLINE_SPECIFIER_ MegaTrackerResult::~MegaTrackerResult()
{
    cdata_ = nullptr;
}

_INLINE_SPECIFIER_ std::shared_ptr<easyar_MegaTrackerResult> MegaTrackerResult::get_cdata()
{
    return cdata_;
}
_INLINE_SPECIFIER_ void MegaTrackerResult::init_cdata(std::shared_ptr<easyar_MegaTrackerResult> cdata)
{
    cdata_ = cdata;
    {
        easyar_FrameFilterResult * ptr = nullptr;
        easyar_castMegaTrackerResultToFrameFilterResult(cdata_.get(), &ptr);
        FrameFilterResult::init_cdata(std::shared_ptr<easyar_FrameFilterResult>(ptr, [](easyar_FrameFilterResult * ptr) { easyar_FrameFilterResult__dtor(ptr); }));
    }
}
_INLINE_SPECIFIER_ std::shared_ptr<MegaTrackerResult> MegaTrackerResult::from_cdata(std::shared_ptr<easyar_MegaTrackerResult> cdata)
{
    if (cdata == nullptr) {
        return nullptr;
    }
    return std::make_shared<MegaTrackerResult>(cdata);
}
_INLINE_SPECIFIER_ std::vector<std::shared_ptr<MegaTrackerBlockInstance>> MegaTrackerResult::instances()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_ListOfMegaTrackerBlockInstance * _return_value_;
    easyar_MegaTrackerResult_instances(this->cdata_.get(), &_return_value_);
    if (!(_return_value_ != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    return std_vector_from_easyar_ListOfMegaTrackerBlockInstance(std::shared_ptr<easyar_ListOfMegaTrackerBlockInstance>(_return_value_, [](easyar_ListOfMegaTrackerBlockInstance * ptr) { easyar_ListOfMegaTrackerBlockInstance__dtor(ptr); }));
}

_INLINE_SPECIFIER_ MegaTrackerLocalizationResponse::MegaTrackerLocalizationResponse(std::shared_ptr<easyar_MegaTrackerLocalizationResponse> cdata)
    :
    cdata_(nullptr)
{
    init_cdata(cdata);
}
_INLINE_SPECIFIER_ MegaTrackerLocalizationResponse::~MegaTrackerLocalizationResponse()
{
    cdata_ = nullptr;
}

_INLINE_SPECIFIER_ std::shared_ptr<easyar_MegaTrackerLocalizationResponse> MegaTrackerLocalizationResponse::get_cdata()
{
    return cdata_;
}
_INLINE_SPECIFIER_ void MegaTrackerLocalizationResponse::init_cdata(std::shared_ptr<easyar_MegaTrackerLocalizationResponse> cdata)
{
    cdata_ = cdata;
}
_INLINE_SPECIFIER_ std::shared_ptr<MegaTrackerLocalizationResponse> MegaTrackerLocalizationResponse::from_cdata(std::shared_ptr<easyar_MegaTrackerLocalizationResponse> cdata)
{
    if (cdata == nullptr) {
        return nullptr;
    }
    return std::make_shared<MegaTrackerLocalizationResponse>(cdata);
}
_INLINE_SPECIFIER_ std::shared_ptr<InputFrame> MegaTrackerLocalizationResponse::inputFrame()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_InputFrame * _return_value_;
    easyar_MegaTrackerLocalizationResponse_inputFrame(this->cdata_.get(), &_return_value_);
    if (!(_return_value_ != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    return InputFrame::from_cdata(std::shared_ptr<easyar_InputFrame>(_return_value_, [](easyar_InputFrame * ptr) { easyar_InputFrame__dtor(ptr); }));
}
_INLINE_SPECIFIER_ std::optional<AccelerometerResult> MegaTrackerLocalizationResponse::acceleration()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_MegaTrackerLocalizationResponse_acceleration(this->cdata_.get());
    return (_return_value_.has_value ? AccelerometerResult{_return_value_.value.x, _return_value_.value.y, _return_value_.value.z, _return_value_.value.timestamp} : std::optional<AccelerometerResult>{});
}
_INLINE_SPECIFIER_ std::optional<LocationResult> MegaTrackerLocalizationResponse::location()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_MegaTrackerLocalizationResponse_location(this->cdata_.get());
    return (_return_value_.has_value ? LocationResult{_return_value_.value.latitude, _return_value_.value.longitude, _return_value_.value.altitude, _return_value_.value.horizontalAccuracy, _return_value_.value.verticalAccuracy, _return_value_.value.hasAltitude, _return_value_.value.hasHorizontalAccuracy, _return_value_.value.hasVerticalAccuracy} : std::optional<LocationResult>{});
}
_INLINE_SPECIFIER_ MegaTrackerLocalizationStatus MegaTrackerLocalizationResponse::status()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_MegaTrackerLocalizationResponse_status(this->cdata_.get());
    return static_cast<MegaTrackerLocalizationStatus>(_return_value_);
}
_INLINE_SPECIFIER_ std::optional<std::string> MegaTrackerLocalizationResponse::spotVersionId()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_OptionalOfString _return_value_;
    easyar_MegaTrackerLocalizationResponse_spotVersionId(this->cdata_.get(), &_return_value_);
    if (!(!_return_value_.has_value || (_return_value_.value != nullptr))) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    return (_return_value_.has_value ? std_string_from_easyar_String(std::shared_ptr<easyar_String>(_return_value_.value, [](easyar_String * ptr) { easyar_String__dtor(ptr); })) : std::optional<std::string>{});
}
_INLINE_SPECIFIER_ std::vector<std::shared_ptr<MegaTrackerBlockInstance>> MegaTrackerLocalizationResponse::instances()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_ListOfMegaTrackerBlockInstance * _return_value_;
    easyar_MegaTrackerLocalizationResponse_instances(this->cdata_.get(), &_return_value_);
    if (!(_return_value_ != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    return std_vector_from_easyar_ListOfMegaTrackerBlockInstance(std::shared_ptr<easyar_ListOfMegaTrackerBlockInstance>(_return_value_, [](easyar_ListOfMegaTrackerBlockInstance * ptr) { easyar_ListOfMegaTrackerBlockInstance__dtor(ptr); }));
}
_INLINE_SPECIFIER_ std::string MegaTrackerLocalizationResponse::appId()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_String * _return_value_;
    easyar_MegaTrackerLocalizationResponse_appId(this->cdata_.get(), &_return_value_);
    if (!(_return_value_ != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    return std_string_from_easyar_String(std::shared_ptr<easyar_String>(_return_value_, [](easyar_String * ptr) { easyar_String__dtor(ptr); }));
}
_INLINE_SPECIFIER_ std::optional<double> MegaTrackerLocalizationResponse::serverResponseDuration()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_MegaTrackerLocalizationResponse_serverResponseDuration(this->cdata_.get());
    return (_return_value_.has_value ? _return_value_.value : std::optional<double>{});
}
_INLINE_SPECIFIER_ std::optional<double> MegaTrackerLocalizationResponse::serverCalculationDuration()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_MegaTrackerLocalizationResponse_serverCalculationDuration(this->cdata_.get());
    return (_return_value_.has_value ? _return_value_.value : std::optional<double>{});
}
_INLINE_SPECIFIER_ std::optional<std::string> MegaTrackerLocalizationResponse::errorMessage()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_OptionalOfString _return_value_;
    easyar_MegaTrackerLocalizationResponse_errorMessage(this->cdata_.get(), &_return_value_);
    if (!(!_return_value_.has_value || (_return_value_.value != nullptr))) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    return (_return_value_.has_value ? std_string_from_easyar_String(std::shared_ptr<easyar_String>(_return_value_.value, [](easyar_String * ptr) { easyar_String__dtor(ptr); })) : std::optional<std::string>{});
}
_INLINE_SPECIFIER_ std::string MegaTrackerLocalizationResponse::extraInfo()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_String * _return_value_;
    easyar_MegaTrackerLocalizationResponse_extraInfo(this->cdata_.get(), &_return_value_);
    if (!(_return_value_ != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    return std_string_from_easyar_String(std::shared_ptr<easyar_String>(_return_value_, [](easyar_String * ptr) { easyar_String__dtor(ptr); }));
}

_INLINE_SPECIFIER_ MegaTracker::MegaTracker(std::shared_ptr<easyar_MegaTracker> cdata)
    :
    cdata_(nullptr)
{
    init_cdata(cdata);
}
_INLINE_SPECIFIER_ MegaTracker::~MegaTracker()
{
    cdata_ = nullptr;
}

_INLINE_SPECIFIER_ std::shared_ptr<easyar_MegaTracker> MegaTracker::get_cdata()
{
    return cdata_;
}
_INLINE_SPECIFIER_ void MegaTracker::init_cdata(std::shared_ptr<easyar_MegaTracker> cdata)
{
    cdata_ = cdata;
}
_INLINE_SPECIFIER_ std::shared_ptr<MegaTracker> MegaTracker::from_cdata(std::shared_ptr<easyar_MegaTracker> cdata)
{
    if (cdata == nullptr) {
        return nullptr;
    }
    return std::make_shared<MegaTracker>(cdata);
}
_INLINE_SPECIFIER_ bool MegaTracker::isAvailable()
{
    auto _return_value_ = easyar_MegaTracker_isAvailable();
    return _return_value_;
}
_INLINE_SPECIFIER_ std::shared_ptr<InputFrameSink> MegaTracker::inputFrameSink()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_InputFrameSink * _return_value_;
    easyar_MegaTracker_inputFrameSink(this->cdata_.get(), &_return_value_);
    if (!(_return_value_ != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    return InputFrameSink::from_cdata(std::shared_ptr<easyar_InputFrameSink>(_return_value_, [](easyar_InputFrameSink * ptr) { easyar_InputFrameSink__dtor(ptr); }));
}
_INLINE_SPECIFIER_ std::shared_ptr<AccelerometerResultSink> MegaTracker::accelerometerResultSink()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_AccelerometerResultSink * _return_value_;
    easyar_MegaTracker_accelerometerResultSink(this->cdata_.get(), &_return_value_);
    if (!(_return_value_ != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    return AccelerometerResultSink::from_cdata(std::shared_ptr<easyar_AccelerometerResultSink>(_return_value_, [](easyar_AccelerometerResultSink * ptr) { easyar_AccelerometerResultSink__dtor(ptr); }));
}
_INLINE_SPECIFIER_ std::shared_ptr<LocationResultSink> MegaTracker::locationResultSink()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_LocationResultSink * _return_value_;
    easyar_MegaTracker_locationResultSink(this->cdata_.get(), &_return_value_);
    if (!(_return_value_ != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    return LocationResultSink::from_cdata(std::shared_ptr<easyar_LocationResultSink>(_return_value_, [](easyar_LocationResultSink * ptr) { easyar_LocationResultSink__dtor(ptr); }));
}
_INLINE_SPECIFIER_ std::shared_ptr<ProximityLocationResultSink> MegaTracker::proximityLocationResultSink()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_ProximityLocationResultSink * _return_value_;
    easyar_MegaTracker_proximityLocationResultSink(this->cdata_.get(), &_return_value_);
    if (!(_return_value_ != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    return ProximityLocationResultSink::from_cdata(std::shared_ptr<easyar_ProximityLocationResultSink>(_return_value_, [](easyar_ProximityLocationResultSink * ptr) { easyar_ProximityLocationResultSink__dtor(ptr); }));
}
_INLINE_SPECIFIER_ int MegaTracker::bufferRequirement()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_MegaTracker_bufferRequirement(this->cdata_.get());
    return _return_value_;
}
_INLINE_SPECIFIER_ std::shared_ptr<OutputFrameSource> MegaTracker::outputFrameSource()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_OutputFrameSource * _return_value_;
    easyar_MegaTracker_outputFrameSource(this->cdata_.get(), &_return_value_);
    if (!(_return_value_ != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    return OutputFrameSource::from_cdata(std::shared_ptr<easyar_OutputFrameSource>(_return_value_, [](easyar_OutputFrameSource * ptr) { easyar_OutputFrameSource__dtor(ptr); }));
}
_INLINE_SPECIFIER_ std::shared_ptr<MegaTracker> MegaTracker::create(std::string server, std::string apiKey, std::string apiSecret, std::string appId)
{
    easyar_MegaTracker * _return_value_;
    easyar_MegaTracker_create(std_string_to_easyar_String(server).get(), std_string_to_easyar_String(apiKey).get(), std_string_to_easyar_String(apiSecret).get(), std_string_to_easyar_String(appId).get(), &_return_value_);
    if (!(_return_value_ != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    return MegaTracker::from_cdata(std::shared_ptr<easyar_MegaTracker>(_return_value_, [](easyar_MegaTracker * ptr) { easyar_MegaTracker__dtor(ptr); }));
}
_INLINE_SPECIFIER_ std::shared_ptr<MegaTracker> MegaTracker::createWithToken(std::string server, std::string apiToken, std::string appId)
{
    easyar_MegaTracker * _return_value_;
    easyar_MegaTracker_createWithToken(std_string_to_easyar_String(server).get(), std_string_to_easyar_String(apiToken).get(), std_string_to_easyar_String(appId).get(), &_return_value_);
    if (!(_return_value_ != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    return MegaTracker::from_cdata(std::shared_ptr<easyar_MegaTracker>(_return_value_, [](easyar_MegaTracker * ptr) { easyar_MegaTracker__dtor(ptr); }));
}
_INLINE_SPECIFIER_ void MegaTracker::updateToken(std::string apiToken)
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_MegaTracker_updateToken(this->cdata_.get(), std_string_to_easyar_String(apiToken).get());
}
_INLINE_SPECIFIER_ void MegaTracker::setMegaApiType(MegaApiType type)
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_MegaTracker_setMegaApiType(this->cdata_.get(), static_cast<easyar_MegaApiType>(type));
}
_INLINE_SPECIFIER_ void MegaTracker::setSpotVersionId(std::optional<std::string> spotVersionId)
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_MegaTracker_setSpotVersionId(this->cdata_.get(), (spotVersionId.has_value() ? easyar_OptionalOfString{true, std_string_to_easyar_String(spotVersionId.value()).get()} : easyar_OptionalOfString{false, {}}));
}
_INLINE_SPECIFIER_ void MegaTracker::switchEndPoint(std::string server, std::string apiKey, std::string apiSecret, std::string appId)
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_MegaTracker_switchEndPoint(this->cdata_.get(), std_string_to_easyar_String(server).get(), std_string_to_easyar_String(apiKey).get(), std_string_to_easyar_String(apiSecret).get(), std_string_to_easyar_String(appId).get());
}
_INLINE_SPECIFIER_ void MegaTracker::switchEndPointWithToken(std::string server, std::string apiToken, std::string appId)
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_MegaTracker_switchEndPointWithToken(this->cdata_.get(), std_string_to_easyar_String(server).get(), std_string_to_easyar_String(apiToken).get(), std_string_to_easyar_String(appId).get());
}
_INLINE_SPECIFIER_ void MegaTracker::bindBlockPrior(std::shared_ptr<BlockPriorResult> blockPrior)
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    if (!(blockPrior != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: blockPrior");
#else
        std::terminate();
#endif
    }
    easyar_MegaTracker_bindBlockPrior(this->cdata_.get(), blockPrior->get_cdata().get());
}
_INLINE_SPECIFIER_ void MegaTracker::unbindBlockPrior()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_MegaTracker_unbindBlockPrior(this->cdata_.get());
}
_INLINE_SPECIFIER_ void MegaTracker::setRequestTimeParameters(std::optional<int> timeoutMilliseconds, int requestIntervalMilliseconds)
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_MegaTracker_setRequestTimeParameters(this->cdata_.get(), (timeoutMilliseconds.has_value() ? easyar_OptionalOfInt{true, timeoutMilliseconds.value()} : easyar_OptionalOfInt{false, {}}), requestIntervalMilliseconds);
}
_INLINE_SPECIFIER_ void MegaTracker::setEnableLocalization(bool enableLocalization)
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_MegaTracker_setEnableLocalization(this->cdata_.get(), enableLocalization);
}
_INLINE_SPECIFIER_ void MegaTracker::setEnableStatelessLocalization(bool enableStatelessLocalization)
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_MegaTracker_setEnableStatelessLocalization(this->cdata_.get(), enableStatelessLocalization);
}
_INLINE_SPECIFIER_ bool MegaTracker::setResultAsyncMode(bool enableAsync)
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_MegaTracker_setResultAsyncMode(this->cdata_.get(), enableAsync);
    return _return_value_;
}
_INLINE_SPECIFIER_ void MegaTracker::setRequestMessage(std::string message)
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_MegaTracker_setRequestMessage(this->cdata_.get(), std_string_to_easyar_String(message).get());
}
_INLINE_SPECIFIER_ void MegaTracker::setLocalizationCallback(std::shared_ptr<CallbackScheduler> callbackScheduler, std::optional<std::function<void(std::shared_ptr<MegaTrackerLocalizationResponse>)>> callback)
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    if (!(callbackScheduler != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: callbackScheduler");
#else
        std::terminate();
#endif
    }
    if (!(!callback.has_value() || (callback.value() != nullptr))) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: callback");
#else
        std::terminate();
#endif
    }
    easyar_MegaTracker_setLocalizationCallback(this->cdata_.get(), callbackScheduler->get_cdata().get(), (callback.has_value() ? easyar_OptionalOfFunctorOfVoidFromMegaTrackerLocalizationResponse{true, FunctorOfVoidFromMegaTrackerLocalizationResponse_to_c(callback.value())} : easyar_OptionalOfFunctorOfVoidFromMegaTrackerLocalizationResponse{false, {}}));
}
_INLINE_SPECIFIER_ void MegaTracker::setCameraPositionOverride(std::optional<float> x, std::optional<float> y, std::optional<float> z)
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_MegaTracker_setCameraPositionOverride(this->cdata_.get(), (x.has_value() ? easyar_OptionalOfFloat{true, x.value()} : easyar_OptionalOfFloat{false, {}}), (y.has_value() ? easyar_OptionalOfFloat{true, y.value()} : easyar_OptionalOfFloat{false, {}}), (z.has_value() ? easyar_OptionalOfFloat{true, z.value()} : easyar_OptionalOfFloat{false, {}}));
}
_INLINE_SPECIFIER_ bool MegaTracker::start()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_MegaTracker_start(this->cdata_.get());
    return _return_value_;
}
_INLINE_SPECIFIER_ void MegaTracker::stop()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_MegaTracker_stop(this->cdata_.get());
}
_INLINE_SPECIFIER_ void MegaTracker::reset()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_MegaTracker_reset(this->cdata_.get());
}
_INLINE_SPECIFIER_ void MegaTracker::close()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_MegaTracker_close(this->cdata_.get());
}
_INLINE_SPECIFIER_ std::optional<std::shared_ptr<MegaTrackerResult>> MegaTracker::getSyncResult(std::shared_ptr<MotionInputData> motionInputData)
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    if (!(motionInputData != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: motionInputData");
#else
        std::terminate();
#endif
    }
    easyar_OptionalOfMegaTrackerResult _return_value_;
    easyar_MegaTracker_getSyncResult(this->cdata_.get(), motionInputData->get_cdata().get(), &_return_value_);
    if (!(!_return_value_.has_value || (_return_value_.value != nullptr))) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    return (_return_value_.has_value ? MegaTrackerResult::from_cdata(std::shared_ptr<easyar_MegaTrackerResult>(_return_value_.value, [](easyar_MegaTrackerResult * ptr) { easyar_MegaTrackerResult__dtor(ptr); })) : std::optional<std::shared_ptr<MegaTrackerResult>>{});
}

_INLINE_SPECIFIER_ CloudRecognizationResult::CloudRecognizationResult(std::shared_ptr<easyar_CloudRecognizationResult> cdata)
    :
    cdata_(nullptr)
{
    init_cdata(cdata);
}
_INLINE_SPECIFIER_ CloudRecognizationResult::~CloudRecognizationResult()
{
    cdata_ = nullptr;
}

_INLINE_SPECIFIER_ std::shared_ptr<easyar_CloudRecognizationResult> CloudRecognizationResult::get_cdata()
{
    return cdata_;
}
_INLINE_SPECIFIER_ void CloudRecognizationResult::init_cdata(std::shared_ptr<easyar_CloudRecognizationResult> cdata)
{
    cdata_ = cdata;
}
_INLINE_SPECIFIER_ std::shared_ptr<CloudRecognizationResult> CloudRecognizationResult::from_cdata(std::shared_ptr<easyar_CloudRecognizationResult> cdata)
{
    if (cdata == nullptr) {
        return nullptr;
    }
    return std::make_shared<CloudRecognizationResult>(cdata);
}
_INLINE_SPECIFIER_ CloudRecognizationStatus CloudRecognizationResult::getStatus()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_CloudRecognizationResult_getStatus(this->cdata_.get());
    return static_cast<CloudRecognizationStatus>(_return_value_);
}
_INLINE_SPECIFIER_ std::optional<std::shared_ptr<ImageTarget>> CloudRecognizationResult::getTarget()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_OptionalOfImageTarget _return_value_;
    easyar_CloudRecognizationResult_getTarget(this->cdata_.get(), &_return_value_);
    if (!(!_return_value_.has_value || (_return_value_.value != nullptr))) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    return (_return_value_.has_value ? ImageTarget::from_cdata(std::shared_ptr<easyar_ImageTarget>(_return_value_.value, [](easyar_ImageTarget * ptr) { easyar_ImageTarget__dtor(ptr); })) : std::optional<std::shared_ptr<ImageTarget>>{});
}
_INLINE_SPECIFIER_ std::optional<std::string> CloudRecognizationResult::getUnknownErrorMessage()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_OptionalOfString _return_value_;
    easyar_CloudRecognizationResult_getUnknownErrorMessage(this->cdata_.get(), &_return_value_);
    if (!(!_return_value_.has_value || (_return_value_.value != nullptr))) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    return (_return_value_.has_value ? std_string_from_easyar_String(std::shared_ptr<easyar_String>(_return_value_.value, [](easyar_String * ptr) { easyar_String__dtor(ptr); })) : std::optional<std::string>{});
}

_INLINE_SPECIFIER_ CloudRecognizer::CloudRecognizer(std::shared_ptr<easyar_CloudRecognizer> cdata)
    :
    cdata_(nullptr)
{
    init_cdata(cdata);
}
_INLINE_SPECIFIER_ CloudRecognizer::~CloudRecognizer()
{
    cdata_ = nullptr;
}

_INLINE_SPECIFIER_ std::shared_ptr<easyar_CloudRecognizer> CloudRecognizer::get_cdata()
{
    return cdata_;
}
_INLINE_SPECIFIER_ void CloudRecognizer::init_cdata(std::shared_ptr<easyar_CloudRecognizer> cdata)
{
    cdata_ = cdata;
}
_INLINE_SPECIFIER_ std::shared_ptr<CloudRecognizer> CloudRecognizer::from_cdata(std::shared_ptr<easyar_CloudRecognizer> cdata)
{
    if (cdata == nullptr) {
        return nullptr;
    }
    return std::make_shared<CloudRecognizer>(cdata);
}
_INLINE_SPECIFIER_ bool CloudRecognizer::isAvailable()
{
    auto _return_value_ = easyar_CloudRecognizer_isAvailable();
    return _return_value_;
}
_INLINE_SPECIFIER_ std::shared_ptr<CloudRecognizer> CloudRecognizer::create(std::string cloudRecognitionServiceServerAddress, std::string apiKey, std::string apiSecret, std::string cloudRecognitionServiceAppId)
{
    easyar_CloudRecognizer * _return_value_;
    easyar_CloudRecognizer_create(std_string_to_easyar_String(cloudRecognitionServiceServerAddress).get(), std_string_to_easyar_String(apiKey).get(), std_string_to_easyar_String(apiSecret).get(), std_string_to_easyar_String(cloudRecognitionServiceAppId).get(), &_return_value_);
    if (!(_return_value_ != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    return CloudRecognizer::from_cdata(std::shared_ptr<easyar_CloudRecognizer>(_return_value_, [](easyar_CloudRecognizer * ptr) { easyar_CloudRecognizer__dtor(ptr); }));
}
_INLINE_SPECIFIER_ std::shared_ptr<CloudRecognizer> CloudRecognizer::createWithToken(std::string cloudRecognitionServiceServerAddress, std::string apiToken, std::string cloudRecognitionServiceAppId)
{
    easyar_CloudRecognizer * _return_value_;
    easyar_CloudRecognizer_createWithToken(std_string_to_easyar_String(cloudRecognitionServiceServerAddress).get(), std_string_to_easyar_String(apiToken).get(), std_string_to_easyar_String(cloudRecognitionServiceAppId).get(), &_return_value_);
    if (!(_return_value_ != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    return CloudRecognizer::from_cdata(std::shared_ptr<easyar_CloudRecognizer>(_return_value_, [](easyar_CloudRecognizer * ptr) { easyar_CloudRecognizer__dtor(ptr); }));
}
_INLINE_SPECIFIER_ std::shared_ptr<CloudRecognizer> CloudRecognizer::createByCloudSecret(std::string cloudRecognitionServiceServerAddress, std::string cloudRecognitionServiceSecret, std::string cloudRecognitionServiceAppId)
{
    easyar_CloudRecognizer * _return_value_;
    easyar_CloudRecognizer_createByCloudSecret(std_string_to_easyar_String(cloudRecognitionServiceServerAddress).get(), std_string_to_easyar_String(cloudRecognitionServiceSecret).get(), std_string_to_easyar_String(cloudRecognitionServiceAppId).get(), &_return_value_);
    if (!(_return_value_ != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    return CloudRecognizer::from_cdata(std::shared_ptr<easyar_CloudRecognizer>(_return_value_, [](easyar_CloudRecognizer * ptr) { easyar_CloudRecognizer__dtor(ptr); }));
}
_INLINE_SPECIFIER_ void CloudRecognizer::updateToken(std::string apiToken)
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_CloudRecognizer_updateToken(this->cdata_.get(), std_string_to_easyar_String(apiToken).get());
}
_INLINE_SPECIFIER_ void CloudRecognizer::resolve(std::shared_ptr<InputFrame> inputFrame, std::optional<int> timeoutMilliseconds, std::shared_ptr<CallbackScheduler> callbackScheduler, std::function<void(std::shared_ptr<CloudRecognizationResult>)> callback)
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    if (!(inputFrame != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: inputFrame");
#else
        std::terminate();
#endif
    }
    if (!(callbackScheduler != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: callbackScheduler");
#else
        std::terminate();
#endif
    }
    if (!(callback != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: callback");
#else
        std::terminate();
#endif
    }
    easyar_CloudRecognizer_resolve(this->cdata_.get(), inputFrame->get_cdata().get(), (timeoutMilliseconds.has_value() ? easyar_OptionalOfInt{true, timeoutMilliseconds.value()} : easyar_OptionalOfInt{false, {}}), callbackScheduler->get_cdata().get(), FunctorOfVoidFromCloudRecognizationResult_to_c(callback));
}
_INLINE_SPECIFIER_ void CloudRecognizer::close()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_CloudRecognizer_close(this->cdata_.get());
}

_INLINE_SPECIFIER_ Buffer::Buffer(std::shared_ptr<easyar_Buffer> cdata)
    :
    cdata_(nullptr)
{
    init_cdata(cdata);
}
_INLINE_SPECIFIER_ Buffer::~Buffer()
{
    cdata_ = nullptr;
}

_INLINE_SPECIFIER_ std::shared_ptr<easyar_Buffer> Buffer::get_cdata()
{
    return cdata_;
}
_INLINE_SPECIFIER_ void Buffer::init_cdata(std::shared_ptr<easyar_Buffer> cdata)
{
    cdata_ = cdata;
}
_INLINE_SPECIFIER_ std::shared_ptr<Buffer> Buffer::from_cdata(std::shared_ptr<easyar_Buffer> cdata)
{
    if (cdata == nullptr) {
        return nullptr;
    }
    return std::make_shared<Buffer>(cdata);
}
_INLINE_SPECIFIER_ std::shared_ptr<Buffer> Buffer::wrap(void * ptr, int size, std::function<void()> deleter)
{
    if (!(deleter != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: deleter");
#else
        std::terminate();
#endif
    }
    easyar_Buffer * _return_value_;
    easyar_Buffer_wrap(ptr, size, FunctorOfVoid_to_c(deleter), &_return_value_);
    if (!(_return_value_ != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    return Buffer::from_cdata(std::shared_ptr<easyar_Buffer>(_return_value_, [](easyar_Buffer * ptr) { easyar_Buffer__dtor(ptr); }));
}
_INLINE_SPECIFIER_ std::shared_ptr<Buffer> Buffer::create(int size)
{
    easyar_Buffer * _return_value_;
    easyar_Buffer_create(size, &_return_value_);
    if (!(_return_value_ != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    return Buffer::from_cdata(std::shared_ptr<easyar_Buffer>(_return_value_, [](easyar_Buffer * ptr) { easyar_Buffer__dtor(ptr); }));
}
_INLINE_SPECIFIER_ void * Buffer::data()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_Buffer_data(this->cdata_.get());
    return _return_value_;
}
_INLINE_SPECIFIER_ int Buffer::size()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_Buffer_size(this->cdata_.get());
    return _return_value_;
}
_INLINE_SPECIFIER_ void Buffer::memoryCopy(void * src, void * dest, int length)
{
    easyar_Buffer_memoryCopy(src, dest, length);
}
_INLINE_SPECIFIER_ bool Buffer::tryCopyFrom(void * src, int srcIndex, int index, int length)
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_Buffer_tryCopyFrom(this->cdata_.get(), src, srcIndex, index, length);
    return _return_value_;
}
_INLINE_SPECIFIER_ bool Buffer::tryCopyTo(int index, void * dest, int destIndex, int length)
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_Buffer_tryCopyTo(this->cdata_.get(), index, dest, destIndex, length);
    return _return_value_;
}
_INLINE_SPECIFIER_ std::shared_ptr<Buffer> Buffer::partition(int index, int length)
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_Buffer * _return_value_;
    easyar_Buffer_partition(this->cdata_.get(), index, length, &_return_value_);
    if (!(_return_value_ != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    return Buffer::from_cdata(std::shared_ptr<easyar_Buffer>(_return_value_, [](easyar_Buffer * ptr) { easyar_Buffer__dtor(ptr); }));
}

_INLINE_SPECIFIER_ BufferDictionary::BufferDictionary(std::shared_ptr<easyar_BufferDictionary> cdata)
    :
    cdata_(nullptr)
{
    init_cdata(cdata);
}
_INLINE_SPECIFIER_ BufferDictionary::~BufferDictionary()
{
    cdata_ = nullptr;
}

_INLINE_SPECIFIER_ std::shared_ptr<easyar_BufferDictionary> BufferDictionary::get_cdata()
{
    return cdata_;
}
_INLINE_SPECIFIER_ void BufferDictionary::init_cdata(std::shared_ptr<easyar_BufferDictionary> cdata)
{
    cdata_ = cdata;
}
_INLINE_SPECIFIER_ std::shared_ptr<BufferDictionary> BufferDictionary::from_cdata(std::shared_ptr<easyar_BufferDictionary> cdata)
{
    if (cdata == nullptr) {
        return nullptr;
    }
    return std::make_shared<BufferDictionary>(cdata);
}
_INLINE_SPECIFIER_ BufferDictionary::BufferDictionary()
    :
    cdata_(nullptr)
{
    easyar_BufferDictionary * _return_value_;
    easyar_BufferDictionary__ctor(&_return_value_);
    if (!(_return_value_ != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    init_cdata(std::shared_ptr<easyar_BufferDictionary>(_return_value_, [](easyar_BufferDictionary * ptr) { easyar_BufferDictionary__dtor(ptr); }));
}
_INLINE_SPECIFIER_ int BufferDictionary::count()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_BufferDictionary_count(this->cdata_.get());
    return _return_value_;
}
_INLINE_SPECIFIER_ bool BufferDictionary::contains(std::string path)
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_BufferDictionary_contains(this->cdata_.get(), std_string_to_easyar_String(path).get());
    return _return_value_;
}
_INLINE_SPECIFIER_ std::optional<std::shared_ptr<Buffer>> BufferDictionary::tryGet(std::string path)
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_OptionalOfBuffer _return_value_;
    easyar_BufferDictionary_tryGet(this->cdata_.get(), std_string_to_easyar_String(path).get(), &_return_value_);
    if (!(!_return_value_.has_value || (_return_value_.value != nullptr))) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    return (_return_value_.has_value ? Buffer::from_cdata(std::shared_ptr<easyar_Buffer>(_return_value_.value, [](easyar_Buffer * ptr) { easyar_Buffer__dtor(ptr); })) : std::optional<std::shared_ptr<Buffer>>{});
}
_INLINE_SPECIFIER_ void BufferDictionary::set(std::string path, std::shared_ptr<Buffer> buffer)
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    if (!(buffer != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: buffer");
#else
        std::terminate();
#endif
    }
    easyar_BufferDictionary_set(this->cdata_.get(), std_string_to_easyar_String(path).get(), buffer->get_cdata().get());
}
_INLINE_SPECIFIER_ bool BufferDictionary::remove(std::string path)
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_BufferDictionary_remove(this->cdata_.get(), std_string_to_easyar_String(path).get());
    return _return_value_;
}
_INLINE_SPECIFIER_ void BufferDictionary::clear()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_BufferDictionary_clear(this->cdata_.get());
}

_INLINE_SPECIFIER_ BufferPool::BufferPool(std::shared_ptr<easyar_BufferPool> cdata)
    :
    cdata_(nullptr)
{
    init_cdata(cdata);
}
_INLINE_SPECIFIER_ BufferPool::~BufferPool()
{
    cdata_ = nullptr;
}

_INLINE_SPECIFIER_ std::shared_ptr<easyar_BufferPool> BufferPool::get_cdata()
{
    return cdata_;
}
_INLINE_SPECIFIER_ void BufferPool::init_cdata(std::shared_ptr<easyar_BufferPool> cdata)
{
    cdata_ = cdata;
}
_INLINE_SPECIFIER_ std::shared_ptr<BufferPool> BufferPool::from_cdata(std::shared_ptr<easyar_BufferPool> cdata)
{
    if (cdata == nullptr) {
        return nullptr;
    }
    return std::make_shared<BufferPool>(cdata);
}
_INLINE_SPECIFIER_ BufferPool::BufferPool(int block_size, int capacity)
    :
    cdata_(nullptr)
{
    easyar_BufferPool * _return_value_;
    easyar_BufferPool__ctor(block_size, capacity, &_return_value_);
    if (!(_return_value_ != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    init_cdata(std::shared_ptr<easyar_BufferPool>(_return_value_, [](easyar_BufferPool * ptr) { easyar_BufferPool__dtor(ptr); }));
}
_INLINE_SPECIFIER_ int BufferPool::block_size()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_BufferPool_block_size(this->cdata_.get());
    return _return_value_;
}
_INLINE_SPECIFIER_ int BufferPool::capacity()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_BufferPool_capacity(this->cdata_.get());
    return _return_value_;
}
_INLINE_SPECIFIER_ int BufferPool::size()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_BufferPool_size(this->cdata_.get());
    return _return_value_;
}
_INLINE_SPECIFIER_ std::optional<std::shared_ptr<Buffer>> BufferPool::tryAcquire()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_OptionalOfBuffer _return_value_;
    easyar_BufferPool_tryAcquire(this->cdata_.get(), &_return_value_);
    if (!(!_return_value_.has_value || (_return_value_.value != nullptr))) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    return (_return_value_.has_value ? Buffer::from_cdata(std::shared_ptr<easyar_Buffer>(_return_value_.value, [](easyar_Buffer * ptr) { easyar_Buffer__dtor(ptr); })) : std::optional<std::shared_ptr<Buffer>>{});
}

_INLINE_SPECIFIER_ Image::Image(std::shared_ptr<easyar_Image> cdata)
    :
    cdata_(nullptr)
{
    init_cdata(cdata);
}
_INLINE_SPECIFIER_ Image::~Image()
{
    cdata_ = nullptr;
}

_INLINE_SPECIFIER_ std::shared_ptr<easyar_Image> Image::get_cdata()
{
    return cdata_;
}
_INLINE_SPECIFIER_ void Image::init_cdata(std::shared_ptr<easyar_Image> cdata)
{
    cdata_ = cdata;
}
_INLINE_SPECIFIER_ std::shared_ptr<Image> Image::from_cdata(std::shared_ptr<easyar_Image> cdata)
{
    if (cdata == nullptr) {
        return nullptr;
    }
    return std::make_shared<Image>(cdata);
}
_INLINE_SPECIFIER_ Image::Image(std::shared_ptr<Buffer> buffer, PixelFormat format, int width, int height)
    :
    cdata_(nullptr)
{
    if (!(buffer != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: buffer");
#else
        std::terminate();
#endif
    }
    easyar_Image * _return_value_;
    easyar_Image__ctor(buffer->get_cdata().get(), static_cast<easyar_PixelFormat>(format), width, height, &_return_value_);
    if (!(_return_value_ != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    init_cdata(std::shared_ptr<easyar_Image>(_return_value_, [](easyar_Image * ptr) { easyar_Image__dtor(ptr); }));
}
_INLINE_SPECIFIER_ std::shared_ptr<Buffer> Image::buffer()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_Buffer * _return_value_;
    easyar_Image_buffer(this->cdata_.get(), &_return_value_);
    if (!(_return_value_ != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    return Buffer::from_cdata(std::shared_ptr<easyar_Buffer>(_return_value_, [](easyar_Buffer * ptr) { easyar_Buffer__dtor(ptr); }));
}
_INLINE_SPECIFIER_ PixelFormat Image::format()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_Image_format(this->cdata_.get());
    return static_cast<PixelFormat>(_return_value_);
}
_INLINE_SPECIFIER_ int Image::width()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_Image_width(this->cdata_.get());
    return _return_value_;
}
_INLINE_SPECIFIER_ int Image::height()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_Image_height(this->cdata_.get());
    return _return_value_;
}
_INLINE_SPECIFIER_ int Image::pixelWidth()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_Image_pixelWidth(this->cdata_.get());
    return _return_value_;
}
_INLINE_SPECIFIER_ int Image::pixelHeight()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_Image_pixelHeight(this->cdata_.get());
    return _return_value_;
}
_INLINE_SPECIFIER_ std::shared_ptr<Image> Image::create(std::shared_ptr<Buffer> buffer, PixelFormat format, int width, int height, int pixelWidth, int pixelHeight)
{
    if (!(buffer != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: buffer");
#else
        std::terminate();
#endif
    }
    easyar_Image * _return_value_;
    easyar_Image_create(buffer->get_cdata().get(), static_cast<easyar_PixelFormat>(format), width, height, pixelWidth, pixelHeight, &_return_value_);
    if (!(_return_value_ != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    return Image::from_cdata(std::shared_ptr<easyar_Image>(_return_value_, [](easyar_Image * ptr) { easyar_Image__dtor(ptr); }));
}

_INLINE_SPECIFIER_ BlockPriorResult::BlockPriorResult(std::shared_ptr<easyar_BlockPriorResult> cdata)
    :
    cdata_(nullptr)
{
    init_cdata(cdata);
}
_INLINE_SPECIFIER_ BlockPriorResult::~BlockPriorResult()
{
    cdata_ = nullptr;
}

_INLINE_SPECIFIER_ std::shared_ptr<easyar_BlockPriorResult> BlockPriorResult::get_cdata()
{
    return cdata_;
}
_INLINE_SPECIFIER_ void BlockPriorResult::init_cdata(std::shared_ptr<easyar_BlockPriorResult> cdata)
{
    cdata_ = cdata;
}
_INLINE_SPECIFIER_ std::shared_ptr<BlockPriorResult> BlockPriorResult::from_cdata(std::shared_ptr<easyar_BlockPriorResult> cdata)
{
    if (cdata == nullptr) {
        return nullptr;
    }
    return std::make_shared<BlockPriorResult>(cdata);
}
_INLINE_SPECIFIER_ std::vector<std::string> BlockPriorResult::blockIds()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_ListOfString * _return_value_;
    easyar_BlockPriorResult_blockIds(this->cdata_.get(), &_return_value_);
    if (!(_return_value_ != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    return std_vector_from_easyar_ListOfString(std::shared_ptr<easyar_ListOfString>(_return_value_, [](easyar_ListOfString * ptr) { easyar_ListOfString__dtor(ptr); }));
}
_INLINE_SPECIFIER_ std::string BlockPriorResult::mode()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_String * _return_value_;
    easyar_BlockPriorResult_mode(this->cdata_.get(), &_return_value_);
    if (!(_return_value_ != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    return std_string_from_easyar_String(std::shared_ptr<easyar_String>(_return_value_, [](easyar_String * ptr) { easyar_String__dtor(ptr); }));
}
_INLINE_SPECIFIER_ std::shared_ptr<BlockPriorResult> BlockPriorResult::create(std::vector<std::string> blockIds, BlockPriorMode mode)
{
    if (!easyar_ListOfString_check_external_cpp(blockIds)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: blockIds");
#else
        std::terminate();
#endif
    }
    easyar_BlockPriorResult * _return_value_;
    easyar_BlockPriorResult_create(std_vector_to_easyar_ListOfString(blockIds).get(), static_cast<easyar_BlockPriorMode>(mode), &_return_value_);
    if (!(_return_value_ != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    return BlockPriorResult::from_cdata(std::shared_ptr<easyar_BlockPriorResult>(_return_value_, [](easyar_BlockPriorResult * ptr) { easyar_BlockPriorResult__dtor(ptr); }));
}

_INLINE_SPECIFIER_ DenseSpatialMap::DenseSpatialMap(std::shared_ptr<easyar_DenseSpatialMap> cdata)
    :
    cdata_(nullptr)
{
    init_cdata(cdata);
}
_INLINE_SPECIFIER_ DenseSpatialMap::~DenseSpatialMap()
{
    cdata_ = nullptr;
}

_INLINE_SPECIFIER_ std::shared_ptr<easyar_DenseSpatialMap> DenseSpatialMap::get_cdata()
{
    return cdata_;
}
_INLINE_SPECIFIER_ void DenseSpatialMap::init_cdata(std::shared_ptr<easyar_DenseSpatialMap> cdata)
{
    cdata_ = cdata;
}
_INLINE_SPECIFIER_ std::shared_ptr<DenseSpatialMap> DenseSpatialMap::from_cdata(std::shared_ptr<easyar_DenseSpatialMap> cdata)
{
    if (cdata == nullptr) {
        return nullptr;
    }
    return std::make_shared<DenseSpatialMap>(cdata);
}
_INLINE_SPECIFIER_ bool DenseSpatialMap::isAvailable()
{
    auto _return_value_ = easyar_DenseSpatialMap_isAvailable();
    return _return_value_;
}
_INLINE_SPECIFIER_ std::shared_ptr<InputFrameSink> DenseSpatialMap::inputFrameSink()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_InputFrameSink * _return_value_;
    easyar_DenseSpatialMap_inputFrameSink(this->cdata_.get(), &_return_value_);
    if (!(_return_value_ != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    return InputFrameSink::from_cdata(std::shared_ptr<easyar_InputFrameSink>(_return_value_, [](easyar_InputFrameSink * ptr) { easyar_InputFrameSink__dtor(ptr); }));
}
_INLINE_SPECIFIER_ int DenseSpatialMap::bufferRequirement()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_DenseSpatialMap_bufferRequirement(this->cdata_.get());
    return _return_value_;
}
_INLINE_SPECIFIER_ std::shared_ptr<DenseSpatialMap> DenseSpatialMap::create()
{
    easyar_DenseSpatialMap * _return_value_;
    easyar_DenseSpatialMap_create(&_return_value_);
    if (!(_return_value_ != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    return DenseSpatialMap::from_cdata(std::shared_ptr<easyar_DenseSpatialMap>(_return_value_, [](easyar_DenseSpatialMap * ptr) { easyar_DenseSpatialMap__dtor(ptr); }));
}
_INLINE_SPECIFIER_ bool DenseSpatialMap::start()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_DenseSpatialMap_start(this->cdata_.get());
    return _return_value_;
}
_INLINE_SPECIFIER_ void DenseSpatialMap::stop()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_DenseSpatialMap_stop(this->cdata_.get());
}
_INLINE_SPECIFIER_ void DenseSpatialMap::close()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_DenseSpatialMap_close(this->cdata_.get());
}
_INLINE_SPECIFIER_ std::shared_ptr<SceneMesh> DenseSpatialMap::getMesh()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_SceneMesh * _return_value_;
    easyar_DenseSpatialMap_getMesh(this->cdata_.get(), &_return_value_);
    if (!(_return_value_ != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    return SceneMesh::from_cdata(std::shared_ptr<easyar_SceneMesh>(_return_value_, [](easyar_SceneMesh * ptr) { easyar_SceneMesh__dtor(ptr); }));
}
_INLINE_SPECIFIER_ bool DenseSpatialMap::updateSceneMesh(bool updateMeshAll)
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_DenseSpatialMap_updateSceneMesh(this->cdata_.get(), updateMeshAll);
    return _return_value_;
}

_INLINE_SPECIFIER_ SceneMesh::SceneMesh(std::shared_ptr<easyar_SceneMesh> cdata)
    :
    cdata_(nullptr)
{
    init_cdata(cdata);
}
_INLINE_SPECIFIER_ SceneMesh::~SceneMesh()
{
    cdata_ = nullptr;
}

_INLINE_SPECIFIER_ std::shared_ptr<easyar_SceneMesh> SceneMesh::get_cdata()
{
    return cdata_;
}
_INLINE_SPECIFIER_ void SceneMesh::init_cdata(std::shared_ptr<easyar_SceneMesh> cdata)
{
    cdata_ = cdata;
}
_INLINE_SPECIFIER_ std::shared_ptr<SceneMesh> SceneMesh::from_cdata(std::shared_ptr<easyar_SceneMesh> cdata)
{
    if (cdata == nullptr) {
        return nullptr;
    }
    return std::make_shared<SceneMesh>(cdata);
}
_INLINE_SPECIFIER_ int SceneMesh::getNumOfVertexAll()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_SceneMesh_getNumOfVertexAll(this->cdata_.get());
    return _return_value_;
}
_INLINE_SPECIFIER_ int SceneMesh::getNumOfIndexAll()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_SceneMesh_getNumOfIndexAll(this->cdata_.get());
    return _return_value_;
}
_INLINE_SPECIFIER_ std::shared_ptr<Buffer> SceneMesh::getVerticesAll()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_Buffer * _return_value_;
    easyar_SceneMesh_getVerticesAll(this->cdata_.get(), &_return_value_);
    if (!(_return_value_ != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    return Buffer::from_cdata(std::shared_ptr<easyar_Buffer>(_return_value_, [](easyar_Buffer * ptr) { easyar_Buffer__dtor(ptr); }));
}
_INLINE_SPECIFIER_ std::shared_ptr<Buffer> SceneMesh::getNormalsAll()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_Buffer * _return_value_;
    easyar_SceneMesh_getNormalsAll(this->cdata_.get(), &_return_value_);
    if (!(_return_value_ != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    return Buffer::from_cdata(std::shared_ptr<easyar_Buffer>(_return_value_, [](easyar_Buffer * ptr) { easyar_Buffer__dtor(ptr); }));
}
_INLINE_SPECIFIER_ std::shared_ptr<Buffer> SceneMesh::getIndicesAll()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_Buffer * _return_value_;
    easyar_SceneMesh_getIndicesAll(this->cdata_.get(), &_return_value_);
    if (!(_return_value_ != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    return Buffer::from_cdata(std::shared_ptr<easyar_Buffer>(_return_value_, [](easyar_Buffer * ptr) { easyar_Buffer__dtor(ptr); }));
}
_INLINE_SPECIFIER_ int SceneMesh::getNumOfVertexIncremental()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_SceneMesh_getNumOfVertexIncremental(this->cdata_.get());
    return _return_value_;
}
_INLINE_SPECIFIER_ int SceneMesh::getNumOfIndexIncremental()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_SceneMesh_getNumOfIndexIncremental(this->cdata_.get());
    return _return_value_;
}
_INLINE_SPECIFIER_ std::shared_ptr<Buffer> SceneMesh::getVerticesIncremental()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_Buffer * _return_value_;
    easyar_SceneMesh_getVerticesIncremental(this->cdata_.get(), &_return_value_);
    if (!(_return_value_ != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    return Buffer::from_cdata(std::shared_ptr<easyar_Buffer>(_return_value_, [](easyar_Buffer * ptr) { easyar_Buffer__dtor(ptr); }));
}
_INLINE_SPECIFIER_ std::shared_ptr<Buffer> SceneMesh::getNormalsIncremental()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_Buffer * _return_value_;
    easyar_SceneMesh_getNormalsIncremental(this->cdata_.get(), &_return_value_);
    if (!(_return_value_ != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    return Buffer::from_cdata(std::shared_ptr<easyar_Buffer>(_return_value_, [](easyar_Buffer * ptr) { easyar_Buffer__dtor(ptr); }));
}
_INLINE_SPECIFIER_ std::shared_ptr<Buffer> SceneMesh::getIndicesIncremental()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_Buffer * _return_value_;
    easyar_SceneMesh_getIndicesIncremental(this->cdata_.get(), &_return_value_);
    if (!(_return_value_ != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    return Buffer::from_cdata(std::shared_ptr<easyar_Buffer>(_return_value_, [](easyar_Buffer * ptr) { easyar_Buffer__dtor(ptr); }));
}
_INLINE_SPECIFIER_ std::vector<BlockInfo> SceneMesh::getBlocksInfoIncremental()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_ListOfBlockInfo * _return_value_;
    easyar_SceneMesh_getBlocksInfoIncremental(this->cdata_.get(), &_return_value_);
    if (!(_return_value_ != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    return std_vector_from_easyar_ListOfBlockInfo(std::shared_ptr<easyar_ListOfBlockInfo>(_return_value_, [](easyar_ListOfBlockInfo * ptr) { easyar_ListOfBlockInfo__dtor(ptr); }));
}
_INLINE_SPECIFIER_ float SceneMesh::getBlockDimensionInMeters()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_SceneMesh_getBlockDimensionInMeters(this->cdata_.get());
    return _return_value_;
}

_INLINE_SPECIFIER_ Accelerometer::Accelerometer(std::shared_ptr<easyar_Accelerometer> cdata)
    :
    cdata_(nullptr)
{
    init_cdata(cdata);
}
_INLINE_SPECIFIER_ Accelerometer::~Accelerometer()
{
    cdata_ = nullptr;
}

_INLINE_SPECIFIER_ std::shared_ptr<easyar_Accelerometer> Accelerometer::get_cdata()
{
    return cdata_;
}
_INLINE_SPECIFIER_ void Accelerometer::init_cdata(std::shared_ptr<easyar_Accelerometer> cdata)
{
    cdata_ = cdata;
}
_INLINE_SPECIFIER_ std::shared_ptr<Accelerometer> Accelerometer::from_cdata(std::shared_ptr<easyar_Accelerometer> cdata)
{
    if (cdata == nullptr) {
        return nullptr;
    }
    return std::make_shared<Accelerometer>(cdata);
}
_INLINE_SPECIFIER_ Accelerometer::Accelerometer()
    :
    cdata_(nullptr)
{
    easyar_Accelerometer * _return_value_;
    easyar_Accelerometer__ctor(&_return_value_);
    if (!(_return_value_ != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    init_cdata(std::shared_ptr<easyar_Accelerometer>(_return_value_, [](easyar_Accelerometer * ptr) { easyar_Accelerometer__dtor(ptr); }));
}
_INLINE_SPECIFIER_ bool Accelerometer::isAvailable()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_Accelerometer_isAvailable(this->cdata_.get());
    return _return_value_;
}
_INLINE_SPECIFIER_ std::shared_ptr<AccelerometerResultSource> Accelerometer::output()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_AccelerometerResultSource * _return_value_;
    easyar_Accelerometer_output(this->cdata_.get(), &_return_value_);
    if (!(_return_value_ != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    return AccelerometerResultSource::from_cdata(std::shared_ptr<easyar_AccelerometerResultSource>(_return_value_, [](easyar_AccelerometerResultSource * ptr) { easyar_AccelerometerResultSource__dtor(ptr); }));
}
_INLINE_SPECIFIER_ bool Accelerometer::open()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_Accelerometer_open(this->cdata_.get());
    return _return_value_;
}
_INLINE_SPECIFIER_ bool Accelerometer::openWithSamplingPeriod(int samplingPeriodMilliseconds)
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_Accelerometer_openWithSamplingPeriod(this->cdata_.get(), samplingPeriodMilliseconds);
    return _return_value_;
}
_INLINE_SPECIFIER_ void Accelerometer::close()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_Accelerometer_close(this->cdata_.get());
}
_INLINE_SPECIFIER_ std::optional<AccelerometerResult> Accelerometer::getCurrentResult()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_Accelerometer_getCurrentResult(this->cdata_.get());
    return (_return_value_.has_value ? AccelerometerResult{_return_value_.value.x, _return_value_.value.y, _return_value_.value.z, _return_value_.value.timestamp} : std::optional<AccelerometerResult>{});
}

_INLINE_SPECIFIER_ ARCoreCameraDevice::ARCoreCameraDevice(std::shared_ptr<easyar_ARCoreCameraDevice> cdata)
    :
    cdata_(nullptr)
{
    init_cdata(cdata);
}
_INLINE_SPECIFIER_ ARCoreCameraDevice::~ARCoreCameraDevice()
{
    cdata_ = nullptr;
}

_INLINE_SPECIFIER_ std::shared_ptr<easyar_ARCoreCameraDevice> ARCoreCameraDevice::get_cdata()
{
    return cdata_;
}
_INLINE_SPECIFIER_ void ARCoreCameraDevice::init_cdata(std::shared_ptr<easyar_ARCoreCameraDevice> cdata)
{
    cdata_ = cdata;
}
_INLINE_SPECIFIER_ std::shared_ptr<ARCoreCameraDevice> ARCoreCameraDevice::from_cdata(std::shared_ptr<easyar_ARCoreCameraDevice> cdata)
{
    if (cdata == nullptr) {
        return nullptr;
    }
    return std::make_shared<ARCoreCameraDevice>(cdata);
}
_INLINE_SPECIFIER_ ARCoreCameraDevice::ARCoreCameraDevice()
    :
    cdata_(nullptr)
{
    easyar_ARCoreCameraDevice * _return_value_;
    easyar_ARCoreCameraDevice__ctor(&_return_value_);
    if (!(_return_value_ != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    init_cdata(std::shared_ptr<easyar_ARCoreCameraDevice>(_return_value_, [](easyar_ARCoreCameraDevice * ptr) { easyar_ARCoreCameraDevice__dtor(ptr); }));
}
_INLINE_SPECIFIER_ bool ARCoreCameraDevice::isAvailable()
{
    auto _return_value_ = easyar_ARCoreCameraDevice_isAvailable();
    return _return_value_;
}
_INLINE_SPECIFIER_ bool ARCoreCameraDevice::isDeviceSupported()
{
    auto _return_value_ = easyar_ARCoreCameraDevice_isDeviceSupported();
    return _return_value_;
}
_INLINE_SPECIFIER_ int ARCoreCameraDevice::bufferCapacity()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_ARCoreCameraDevice_bufferCapacity(this->cdata_.get());
    return _return_value_;
}
_INLINE_SPECIFIER_ void ARCoreCameraDevice::setBufferCapacity(int capacity)
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_ARCoreCameraDevice_setBufferCapacity(this->cdata_.get(), capacity);
}
_INLINE_SPECIFIER_ std::shared_ptr<InputFrameSource> ARCoreCameraDevice::inputFrameSource()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_InputFrameSource * _return_value_;
    easyar_ARCoreCameraDevice_inputFrameSource(this->cdata_.get(), &_return_value_);
    if (!(_return_value_ != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    return InputFrameSource::from_cdata(std::shared_ptr<easyar_InputFrameSource>(_return_value_, [](easyar_InputFrameSource * ptr) { easyar_InputFrameSource__dtor(ptr); }));
}
_INLINE_SPECIFIER_ void ARCoreCameraDevice::setFocusMode(ARCoreCameraDeviceFocusMode focusMode)
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_ARCoreCameraDevice_setFocusMode(this->cdata_.get(), static_cast<easyar_ARCoreCameraDeviceFocusMode>(focusMode));
}
_INLINE_SPECIFIER_ bool ARCoreCameraDevice::start()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_ARCoreCameraDevice_start(this->cdata_.get());
    return _return_value_;
}
_INLINE_SPECIFIER_ void ARCoreCameraDevice::stop()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_ARCoreCameraDevice_stop(this->cdata_.get());
}
_INLINE_SPECIFIER_ void ARCoreCameraDevice::close()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_ARCoreCameraDevice_close(this->cdata_.get());
}
_INLINE_SPECIFIER_ CameraDeviceType ARCoreCameraDevice::type()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_ARCoreCameraDevice_type(this->cdata_.get());
    return static_cast<CameraDeviceType>(_return_value_);
}
_INLINE_SPECIFIER_ int ARCoreCameraDevice::cameraOrientation()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_ARCoreCameraDevice_cameraOrientation(this->cdata_.get());
    return _return_value_;
}
_INLINE_SPECIFIER_ Vec2I ARCoreCameraDevice::size()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_ARCoreCameraDevice_size(this->cdata_.get());
    return Vec2I{{{_return_value_.data[0], _return_value_.data[1]}}};
}
_INLINE_SPECIFIER_ double ARCoreCameraDevice::frameRateRangeLower()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_ARCoreCameraDevice_frameRateRangeLower(this->cdata_.get());
    return _return_value_;
}
_INLINE_SPECIFIER_ double ARCoreCameraDevice::frameRateRangeUpper()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_ARCoreCameraDevice_frameRateRangeUpper(this->cdata_.get());
    return _return_value_;
}

_INLINE_SPECIFIER_ ARKitCameraDevice::ARKitCameraDevice(std::shared_ptr<easyar_ARKitCameraDevice> cdata)
    :
    cdata_(nullptr)
{
    init_cdata(cdata);
}
_INLINE_SPECIFIER_ ARKitCameraDevice::~ARKitCameraDevice()
{
    cdata_ = nullptr;
}

_INLINE_SPECIFIER_ std::shared_ptr<easyar_ARKitCameraDevice> ARKitCameraDevice::get_cdata()
{
    return cdata_;
}
_INLINE_SPECIFIER_ void ARKitCameraDevice::init_cdata(std::shared_ptr<easyar_ARKitCameraDevice> cdata)
{
    cdata_ = cdata;
}
_INLINE_SPECIFIER_ std::shared_ptr<ARKitCameraDevice> ARKitCameraDevice::from_cdata(std::shared_ptr<easyar_ARKitCameraDevice> cdata)
{
    if (cdata == nullptr) {
        return nullptr;
    }
    return std::make_shared<ARKitCameraDevice>(cdata);
}
_INLINE_SPECIFIER_ ARKitCameraDevice::ARKitCameraDevice()
    :
    cdata_(nullptr)
{
    easyar_ARKitCameraDevice * _return_value_;
    easyar_ARKitCameraDevice__ctor(&_return_value_);
    if (!(_return_value_ != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    init_cdata(std::shared_ptr<easyar_ARKitCameraDevice>(_return_value_, [](easyar_ARKitCameraDevice * ptr) { easyar_ARKitCameraDevice__dtor(ptr); }));
}
_INLINE_SPECIFIER_ bool ARKitCameraDevice::isAvailable()
{
    auto _return_value_ = easyar_ARKitCameraDevice_isAvailable();
    return _return_value_;
}
_INLINE_SPECIFIER_ int ARKitCameraDevice::bufferCapacity()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_ARKitCameraDevice_bufferCapacity(this->cdata_.get());
    return _return_value_;
}
_INLINE_SPECIFIER_ void ARKitCameraDevice::setBufferCapacity(int capacity)
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_ARKitCameraDevice_setBufferCapacity(this->cdata_.get(), capacity);
}
_INLINE_SPECIFIER_ std::shared_ptr<InputFrameSource> ARKitCameraDevice::inputFrameSource()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_InputFrameSource * _return_value_;
    easyar_ARKitCameraDevice_inputFrameSource(this->cdata_.get(), &_return_value_);
    if (!(_return_value_ != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    return InputFrameSource::from_cdata(std::shared_ptr<easyar_InputFrameSource>(_return_value_, [](easyar_InputFrameSource * ptr) { easyar_InputFrameSource__dtor(ptr); }));
}
_INLINE_SPECIFIER_ void ARKitCameraDevice::setFocusMode(ARKitCameraDeviceFocusMode focusMode)
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_ARKitCameraDevice_setFocusMode(this->cdata_.get(), static_cast<easyar_ARKitCameraDeviceFocusMode>(focusMode));
}
_INLINE_SPECIFIER_ bool ARKitCameraDevice::start()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_ARKitCameraDevice_start(this->cdata_.get());
    return _return_value_;
}
_INLINE_SPECIFIER_ void ARKitCameraDevice::stop()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_ARKitCameraDevice_stop(this->cdata_.get());
}
_INLINE_SPECIFIER_ void ARKitCameraDevice::close()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_ARKitCameraDevice_close(this->cdata_.get());
}
_INLINE_SPECIFIER_ CameraDeviceType ARKitCameraDevice::type()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_ARKitCameraDevice_type(this->cdata_.get());
    return static_cast<CameraDeviceType>(_return_value_);
}
_INLINE_SPECIFIER_ int ARKitCameraDevice::cameraOrientation()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_ARKitCameraDevice_cameraOrientation(this->cdata_.get());
    return _return_value_;
}
_INLINE_SPECIFIER_ Vec2I ARKitCameraDevice::size()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_ARKitCameraDevice_size(this->cdata_.get());
    return Vec2I{{{_return_value_.data[0], _return_value_.data[1]}}};
}
_INLINE_SPECIFIER_ double ARKitCameraDevice::frameRate()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_ARKitCameraDevice_frameRate(this->cdata_.get());
    return _return_value_;
}
_INLINE_SPECIFIER_ int ARKitCameraDevice::supportedSizeCount()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_ARKitCameraDevice_supportedSizeCount(this->cdata_.get());
    return _return_value_;
}
_INLINE_SPECIFIER_ Vec2I ARKitCameraDevice::supportedSize(int index)
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_ARKitCameraDevice_supportedSize(this->cdata_.get(), index);
    return Vec2I{{{_return_value_.data[0], _return_value_.data[1]}}};
}
_INLINE_SPECIFIER_ bool ARKitCameraDevice::setSize(Vec2I size)
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_ARKitCameraDevice_setSize(this->cdata_.get(), easyar_Vec2I{{size.data[0], size.data[1]}});
    return _return_value_;
}
_INLINE_SPECIFIER_ int ARKitCameraDevice::supportedFrameRateCount()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_ARKitCameraDevice_supportedFrameRateCount(this->cdata_.get());
    return _return_value_;
}
_INLINE_SPECIFIER_ double ARKitCameraDevice::supportedFrameRate(int index)
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_ARKitCameraDevice_supportedFrameRate(this->cdata_.get(), index);
    return _return_value_;
}
_INLINE_SPECIFIER_ bool ARKitCameraDevice::setFrameRate(double frameRate)
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_ARKitCameraDevice_setFrameRate(this->cdata_.get(), frameRate);
    return _return_value_;
}

_INLINE_SPECIFIER_ AttitudeSensor::AttitudeSensor(std::shared_ptr<easyar_AttitudeSensor> cdata)
    :
    cdata_(nullptr)
{
    init_cdata(cdata);
}
_INLINE_SPECIFIER_ AttitudeSensor::~AttitudeSensor()
{
    cdata_ = nullptr;
}

_INLINE_SPECIFIER_ std::shared_ptr<easyar_AttitudeSensor> AttitudeSensor::get_cdata()
{
    return cdata_;
}
_INLINE_SPECIFIER_ void AttitudeSensor::init_cdata(std::shared_ptr<easyar_AttitudeSensor> cdata)
{
    cdata_ = cdata;
}
_INLINE_SPECIFIER_ std::shared_ptr<AttitudeSensor> AttitudeSensor::from_cdata(std::shared_ptr<easyar_AttitudeSensor> cdata)
{
    if (cdata == nullptr) {
        return nullptr;
    }
    return std::make_shared<AttitudeSensor>(cdata);
}
_INLINE_SPECIFIER_ AttitudeSensor::AttitudeSensor()
    :
    cdata_(nullptr)
{
    easyar_AttitudeSensor * _return_value_;
    easyar_AttitudeSensor__ctor(&_return_value_);
    if (!(_return_value_ != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    init_cdata(std::shared_ptr<easyar_AttitudeSensor>(_return_value_, [](easyar_AttitudeSensor * ptr) { easyar_AttitudeSensor__dtor(ptr); }));
}
_INLINE_SPECIFIER_ bool AttitudeSensor::isAvailable()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_AttitudeSensor_isAvailable(this->cdata_.get());
    return _return_value_;
}
_INLINE_SPECIFIER_ std::shared_ptr<AttitudeSensorResultSource> AttitudeSensor::output()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_AttitudeSensorResultSource * _return_value_;
    easyar_AttitudeSensor_output(this->cdata_.get(), &_return_value_);
    if (!(_return_value_ != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    return AttitudeSensorResultSource::from_cdata(std::shared_ptr<easyar_AttitudeSensorResultSource>(_return_value_, [](easyar_AttitudeSensorResultSource * ptr) { easyar_AttitudeSensorResultSource__dtor(ptr); }));
}
_INLINE_SPECIFIER_ bool AttitudeSensor::open()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_AttitudeSensor_open(this->cdata_.get());
    return _return_value_;
}
_INLINE_SPECIFIER_ bool AttitudeSensor::openWithSamplingPeriod(int samplingPeriodMilliseconds)
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_AttitudeSensor_openWithSamplingPeriod(this->cdata_.get(), samplingPeriodMilliseconds);
    return _return_value_;
}
_INLINE_SPECIFIER_ void AttitudeSensor::close()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_AttitudeSensor_close(this->cdata_.get());
}
_INLINE_SPECIFIER_ std::optional<AttitudeSensorResult> AttitudeSensor::getCurrentResult()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_AttitudeSensor_getCurrentResult(this->cdata_.get());
    return (_return_value_.has_value ? AttitudeSensorResult{_return_value_.value.v0, _return_value_.value.v1, _return_value_.value.v2, _return_value_.value.v3, _return_value_.value.timestamp} : std::optional<AttitudeSensorResult>{});
}

_INLINE_SPECIFIER_ CameraDevice::CameraDevice(std::shared_ptr<easyar_CameraDevice> cdata)
    :
    cdata_(nullptr)
{
    init_cdata(cdata);
}
_INLINE_SPECIFIER_ CameraDevice::~CameraDevice()
{
    cdata_ = nullptr;
}

_INLINE_SPECIFIER_ std::shared_ptr<easyar_CameraDevice> CameraDevice::get_cdata()
{
    return cdata_;
}
_INLINE_SPECIFIER_ void CameraDevice::init_cdata(std::shared_ptr<easyar_CameraDevice> cdata)
{
    cdata_ = cdata;
}
_INLINE_SPECIFIER_ std::shared_ptr<CameraDevice> CameraDevice::from_cdata(std::shared_ptr<easyar_CameraDevice> cdata)
{
    if (cdata == nullptr) {
        return nullptr;
    }
    return std::make_shared<CameraDevice>(cdata);
}
_INLINE_SPECIFIER_ CameraDevice::CameraDevice()
    :
    cdata_(nullptr)
{
    easyar_CameraDevice * _return_value_;
    easyar_CameraDevice__ctor(&_return_value_);
    if (!(_return_value_ != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    init_cdata(std::shared_ptr<easyar_CameraDevice>(_return_value_, [](easyar_CameraDevice * ptr) { easyar_CameraDevice__dtor(ptr); }));
}
_INLINE_SPECIFIER_ bool CameraDevice::isAvailable()
{
    auto _return_value_ = easyar_CameraDevice_isAvailable();
    return _return_value_;
}
_INLINE_SPECIFIER_ AndroidCameraApiType CameraDevice::androidCameraApiType()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_CameraDevice_androidCameraApiType(this->cdata_.get());
    return static_cast<AndroidCameraApiType>(_return_value_);
}
_INLINE_SPECIFIER_ void CameraDevice::setAndroidCameraApiType(AndroidCameraApiType type)
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_CameraDevice_setAndroidCameraApiType(this->cdata_.get(), static_cast<easyar_AndroidCameraApiType>(type));
}
_INLINE_SPECIFIER_ int CameraDevice::bufferCapacity()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_CameraDevice_bufferCapacity(this->cdata_.get());
    return _return_value_;
}
_INLINE_SPECIFIER_ void CameraDevice::setBufferCapacity(int capacity)
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_CameraDevice_setBufferCapacity(this->cdata_.get(), capacity);
}
_INLINE_SPECIFIER_ std::shared_ptr<InputFrameSource> CameraDevice::inputFrameSource()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_InputFrameSource * _return_value_;
    easyar_CameraDevice_inputFrameSource(this->cdata_.get(), &_return_value_);
    if (!(_return_value_ != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    return InputFrameSource::from_cdata(std::shared_ptr<easyar_InputFrameSource>(_return_value_, [](easyar_InputFrameSource * ptr) { easyar_InputFrameSource__dtor(ptr); }));
}
_INLINE_SPECIFIER_ void CameraDevice::setStateChangedCallback(std::shared_ptr<CallbackScheduler> callbackScheduler, std::optional<std::function<void(CameraState)>> stateChangedCallback)
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    if (!(callbackScheduler != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: callbackScheduler");
#else
        std::terminate();
#endif
    }
    if (!(!stateChangedCallback.has_value() || (stateChangedCallback.value() != nullptr))) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: stateChangedCallback");
#else
        std::terminate();
#endif
    }
    easyar_CameraDevice_setStateChangedCallback(this->cdata_.get(), callbackScheduler->get_cdata().get(), (stateChangedCallback.has_value() ? easyar_OptionalOfFunctorOfVoidFromCameraState{true, FunctorOfVoidFromCameraState_to_c(stateChangedCallback.value())} : easyar_OptionalOfFunctorOfVoidFromCameraState{false, {}}));
}
_INLINE_SPECIFIER_ void CameraDevice::requestPermissions(std::shared_ptr<CallbackScheduler> callbackScheduler, std::optional<std::function<void(PermissionStatus, std::string)>> permissionCallback)
{
    if (!(callbackScheduler != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: callbackScheduler");
#else
        std::terminate();
#endif
    }
    if (!(!permissionCallback.has_value() || (permissionCallback.value() != nullptr))) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: permissionCallback");
#else
        std::terminate();
#endif
    }
    easyar_CameraDevice_requestPermissions(callbackScheduler->get_cdata().get(), (permissionCallback.has_value() ? easyar_OptionalOfFunctorOfVoidFromPermissionStatusAndString{true, FunctorOfVoidFromPermissionStatusAndString_to_c(permissionCallback.value())} : easyar_OptionalOfFunctorOfVoidFromPermissionStatusAndString{false, {}}));
}
_INLINE_SPECIFIER_ int CameraDevice::cameraCount()
{
    auto _return_value_ = easyar_CameraDevice_cameraCount();
    return _return_value_;
}
_INLINE_SPECIFIER_ bool CameraDevice::openWithIndex(int cameraIndex)
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_CameraDevice_openWithIndex(this->cdata_.get(), cameraIndex);
    return _return_value_;
}
_INLINE_SPECIFIER_ bool CameraDevice::openWithSpecificType(CameraDeviceType type)
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_CameraDevice_openWithSpecificType(this->cdata_.get(), static_cast<easyar_CameraDeviceType>(type));
    return _return_value_;
}
_INLINE_SPECIFIER_ bool CameraDevice::openWithPreferredType(CameraDeviceType type)
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_CameraDevice_openWithPreferredType(this->cdata_.get(), static_cast<easyar_CameraDeviceType>(type));
    return _return_value_;
}
_INLINE_SPECIFIER_ bool CameraDevice::start()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_CameraDevice_start(this->cdata_.get());
    return _return_value_;
}
_INLINE_SPECIFIER_ void CameraDevice::stop()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_CameraDevice_stop(this->cdata_.get());
}
_INLINE_SPECIFIER_ void CameraDevice::close()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_CameraDevice_close(this->cdata_.get());
}
_INLINE_SPECIFIER_ int CameraDevice::index()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_CameraDevice_index(this->cdata_.get());
    return _return_value_;
}
_INLINE_SPECIFIER_ CameraDeviceType CameraDevice::type()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_CameraDevice_type(this->cdata_.get());
    return static_cast<CameraDeviceType>(_return_value_);
}
_INLINE_SPECIFIER_ int CameraDevice::cameraOrientation()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_CameraDevice_cameraOrientation(this->cdata_.get());
    return _return_value_;
}
_INLINE_SPECIFIER_ std::shared_ptr<CameraParameters> CameraDevice::cameraParameters()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_CameraParameters * _return_value_;
    easyar_CameraDevice_cameraParameters(this->cdata_.get(), &_return_value_);
    if (!(_return_value_ != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    return CameraParameters::from_cdata(std::shared_ptr<easyar_CameraParameters>(_return_value_, [](easyar_CameraParameters * ptr) { easyar_CameraParameters__dtor(ptr); }));
}
_INLINE_SPECIFIER_ void CameraDevice::setCameraParameters(std::shared_ptr<CameraParameters> cameraParameters)
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    if (!(cameraParameters != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: cameraParameters");
#else
        std::terminate();
#endif
    }
    easyar_CameraDevice_setCameraParameters(this->cdata_.get(), cameraParameters->get_cdata().get());
}
_INLINE_SPECIFIER_ Vec2I CameraDevice::size()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_CameraDevice_size(this->cdata_.get());
    return Vec2I{{{_return_value_.data[0], _return_value_.data[1]}}};
}
_INLINE_SPECIFIER_ int CameraDevice::supportedSizeCount()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_CameraDevice_supportedSizeCount(this->cdata_.get());
    return _return_value_;
}
_INLINE_SPECIFIER_ Vec2I CameraDevice::supportedSize(int index)
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_CameraDevice_supportedSize(this->cdata_.get(), index);
    return Vec2I{{{_return_value_.data[0], _return_value_.data[1]}}};
}
_INLINE_SPECIFIER_ bool CameraDevice::setSize(Vec2I size)
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_CameraDevice_setSize(this->cdata_.get(), easyar_Vec2I{{size.data[0], size.data[1]}});
    return _return_value_;
}
_INLINE_SPECIFIER_ int CameraDevice::supportedFrameRateRangeCount()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_CameraDevice_supportedFrameRateRangeCount(this->cdata_.get());
    return _return_value_;
}
_INLINE_SPECIFIER_ float CameraDevice::supportedFrameRateRangeLower(int index)
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_CameraDevice_supportedFrameRateRangeLower(this->cdata_.get(), index);
    return _return_value_;
}
_INLINE_SPECIFIER_ float CameraDevice::supportedFrameRateRangeUpper(int index)
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_CameraDevice_supportedFrameRateRangeUpper(this->cdata_.get(), index);
    return _return_value_;
}
_INLINE_SPECIFIER_ int CameraDevice::frameRateRange()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_CameraDevice_frameRateRange(this->cdata_.get());
    return _return_value_;
}
_INLINE_SPECIFIER_ bool CameraDevice::setFrameRateRange(int index)
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_CameraDevice_setFrameRateRange(this->cdata_.get(), index);
    return _return_value_;
}
_INLINE_SPECIFIER_ bool CameraDevice::setFlashTorchMode(bool on)
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_CameraDevice_setFlashTorchMode(this->cdata_.get(), on);
    return _return_value_;
}
_INLINE_SPECIFIER_ bool CameraDevice::setFocusMode(CameraDeviceFocusMode focusMode)
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_CameraDevice_setFocusMode(this->cdata_.get(), static_cast<easyar_CameraDeviceFocusMode>(focusMode));
    return _return_value_;
}
_INLINE_SPECIFIER_ bool CameraDevice::autoFocus()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_CameraDevice_autoFocus(this->cdata_.get());
    return _return_value_;
}

_INLINE_SPECIFIER_ AndroidCameraApiType CameraDeviceSelector::getAndroidCameraApiType(CameraDevicePreference preference)
{
    auto _return_value_ = easyar_CameraDeviceSelector_getAndroidCameraApiType(static_cast<easyar_CameraDevicePreference>(preference));
    return static_cast<AndroidCameraApiType>(_return_value_);
}
_INLINE_SPECIFIER_ std::shared_ptr<CameraDevice> CameraDeviceSelector::createCameraDevice(CameraDevicePreference preference)
{
    easyar_CameraDevice * _return_value_;
    easyar_CameraDeviceSelector_createCameraDevice(static_cast<easyar_CameraDevicePreference>(preference), &_return_value_);
    if (!(_return_value_ != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    return CameraDevice::from_cdata(std::shared_ptr<easyar_CameraDevice>(_return_value_, [](easyar_CameraDevice * ptr) { easyar_CameraDevice__dtor(ptr); }));
}
_INLINE_SPECIFIER_ CameraDeviceFocusMode CameraDeviceSelector::getFocusMode(CameraDevicePreference preference)
{
    auto _return_value_ = easyar_CameraDeviceSelector_getFocusMode(static_cast<easyar_CameraDevicePreference>(preference));
    return static_cast<CameraDeviceFocusMode>(_return_value_);
}

_INLINE_SPECIFIER_ Gyroscope::Gyroscope(std::shared_ptr<easyar_Gyroscope> cdata)
    :
    cdata_(nullptr)
{
    init_cdata(cdata);
}
_INLINE_SPECIFIER_ Gyroscope::~Gyroscope()
{
    cdata_ = nullptr;
}

_INLINE_SPECIFIER_ std::shared_ptr<easyar_Gyroscope> Gyroscope::get_cdata()
{
    return cdata_;
}
_INLINE_SPECIFIER_ void Gyroscope::init_cdata(std::shared_ptr<easyar_Gyroscope> cdata)
{
    cdata_ = cdata;
}
_INLINE_SPECIFIER_ std::shared_ptr<Gyroscope> Gyroscope::from_cdata(std::shared_ptr<easyar_Gyroscope> cdata)
{
    if (cdata == nullptr) {
        return nullptr;
    }
    return std::make_shared<Gyroscope>(cdata);
}
_INLINE_SPECIFIER_ Gyroscope::Gyroscope()
    :
    cdata_(nullptr)
{
    easyar_Gyroscope * _return_value_;
    easyar_Gyroscope__ctor(&_return_value_);
    if (!(_return_value_ != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    init_cdata(std::shared_ptr<easyar_Gyroscope>(_return_value_, [](easyar_Gyroscope * ptr) { easyar_Gyroscope__dtor(ptr); }));
}
_INLINE_SPECIFIER_ bool Gyroscope::isAvailable()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_Gyroscope_isAvailable(this->cdata_.get());
    return _return_value_;
}
_INLINE_SPECIFIER_ std::shared_ptr<GyroscopeResultSource> Gyroscope::output()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_GyroscopeResultSource * _return_value_;
    easyar_Gyroscope_output(this->cdata_.get(), &_return_value_);
    if (!(_return_value_ != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    return GyroscopeResultSource::from_cdata(std::shared_ptr<easyar_GyroscopeResultSource>(_return_value_, [](easyar_GyroscopeResultSource * ptr) { easyar_GyroscopeResultSource__dtor(ptr); }));
}
_INLINE_SPECIFIER_ bool Gyroscope::open()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_Gyroscope_open(this->cdata_.get());
    return _return_value_;
}
_INLINE_SPECIFIER_ bool Gyroscope::openWithSamplingPeriod(int samplingPeriodMilliseconds)
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_Gyroscope_openWithSamplingPeriod(this->cdata_.get(), samplingPeriodMilliseconds);
    return _return_value_;
}
_INLINE_SPECIFIER_ void Gyroscope::close()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_Gyroscope_close(this->cdata_.get());
}
_INLINE_SPECIFIER_ std::optional<GyroscopeResult> Gyroscope::getCurrentResult()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_Gyroscope_getCurrentResult(this->cdata_.get());
    return (_return_value_.has_value ? GyroscopeResult{_return_value_.value.x, _return_value_.value.y, _return_value_.value.z, _return_value_.value.timestamp} : std::optional<GyroscopeResult>{});
}

_INLINE_SPECIFIER_ Magnetometer::Magnetometer(std::shared_ptr<easyar_Magnetometer> cdata)
    :
    cdata_(nullptr)
{
    init_cdata(cdata);
}
_INLINE_SPECIFIER_ Magnetometer::~Magnetometer()
{
    cdata_ = nullptr;
}

_INLINE_SPECIFIER_ std::shared_ptr<easyar_Magnetometer> Magnetometer::get_cdata()
{
    return cdata_;
}
_INLINE_SPECIFIER_ void Magnetometer::init_cdata(std::shared_ptr<easyar_Magnetometer> cdata)
{
    cdata_ = cdata;
}
_INLINE_SPECIFIER_ std::shared_ptr<Magnetometer> Magnetometer::from_cdata(std::shared_ptr<easyar_Magnetometer> cdata)
{
    if (cdata == nullptr) {
        return nullptr;
    }
    return std::make_shared<Magnetometer>(cdata);
}
_INLINE_SPECIFIER_ Magnetometer::Magnetometer()
    :
    cdata_(nullptr)
{
    easyar_Magnetometer * _return_value_;
    easyar_Magnetometer__ctor(&_return_value_);
    if (!(_return_value_ != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    init_cdata(std::shared_ptr<easyar_Magnetometer>(_return_value_, [](easyar_Magnetometer * ptr) { easyar_Magnetometer__dtor(ptr); }));
}
_INLINE_SPECIFIER_ bool Magnetometer::isAvailable()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_Magnetometer_isAvailable(this->cdata_.get());
    return _return_value_;
}
_INLINE_SPECIFIER_ std::shared_ptr<MagnetometerResultSource> Magnetometer::output()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_MagnetometerResultSource * _return_value_;
    easyar_Magnetometer_output(this->cdata_.get(), &_return_value_);
    if (!(_return_value_ != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    return MagnetometerResultSource::from_cdata(std::shared_ptr<easyar_MagnetometerResultSource>(_return_value_, [](easyar_MagnetometerResultSource * ptr) { easyar_MagnetometerResultSource__dtor(ptr); }));
}
_INLINE_SPECIFIER_ bool Magnetometer::open()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_Magnetometer_open(this->cdata_.get());
    return _return_value_;
}
_INLINE_SPECIFIER_ bool Magnetometer::openWithSamplingPeriod(int samplingPeriodMilliseconds)
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_Magnetometer_openWithSamplingPeriod(this->cdata_.get(), samplingPeriodMilliseconds);
    return _return_value_;
}
_INLINE_SPECIFIER_ void Magnetometer::close()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_Magnetometer_close(this->cdata_.get());
}
_INLINE_SPECIFIER_ std::optional<MagnetometerResult> Magnetometer::getCurrentResult()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_Magnetometer_getCurrentResult(this->cdata_.get());
    return (_return_value_.has_value ? MagnetometerResult{_return_value_.value.x, _return_value_.value.y, _return_value_.value.z, _return_value_.value.timestamp} : std::optional<MagnetometerResult>{});
}

_INLINE_SPECIFIER_ ThreeDofCameraDevice::ThreeDofCameraDevice(std::shared_ptr<easyar_ThreeDofCameraDevice> cdata)
    :
    cdata_(nullptr)
{
    init_cdata(cdata);
}
_INLINE_SPECIFIER_ ThreeDofCameraDevice::~ThreeDofCameraDevice()
{
    cdata_ = nullptr;
}

_INLINE_SPECIFIER_ std::shared_ptr<easyar_ThreeDofCameraDevice> ThreeDofCameraDevice::get_cdata()
{
    return cdata_;
}
_INLINE_SPECIFIER_ void ThreeDofCameraDevice::init_cdata(std::shared_ptr<easyar_ThreeDofCameraDevice> cdata)
{
    cdata_ = cdata;
}
_INLINE_SPECIFIER_ std::shared_ptr<ThreeDofCameraDevice> ThreeDofCameraDevice::from_cdata(std::shared_ptr<easyar_ThreeDofCameraDevice> cdata)
{
    if (cdata == nullptr) {
        return nullptr;
    }
    return std::make_shared<ThreeDofCameraDevice>(cdata);
}
_INLINE_SPECIFIER_ ThreeDofCameraDevice::ThreeDofCameraDevice()
    :
    cdata_(nullptr)
{
    easyar_ThreeDofCameraDevice * _return_value_;
    easyar_ThreeDofCameraDevice__ctor(&_return_value_);
    if (!(_return_value_ != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    init_cdata(std::shared_ptr<easyar_ThreeDofCameraDevice>(_return_value_, [](easyar_ThreeDofCameraDevice * ptr) { easyar_ThreeDofCameraDevice__dtor(ptr); }));
}
_INLINE_SPECIFIER_ bool ThreeDofCameraDevice::isAvailable()
{
    auto _return_value_ = easyar_ThreeDofCameraDevice_isAvailable();
    return _return_value_;
}
_INLINE_SPECIFIER_ int ThreeDofCameraDevice::bufferCapacity()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_ThreeDofCameraDevice_bufferCapacity(this->cdata_.get());
    return _return_value_;
}
_INLINE_SPECIFIER_ void ThreeDofCameraDevice::setBufferCapacity(int capacity)
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_ThreeDofCameraDevice_setBufferCapacity(this->cdata_.get(), capacity);
}
_INLINE_SPECIFIER_ std::shared_ptr<InputFrameSource> ThreeDofCameraDevice::inputFrameSource()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_InputFrameSource * _return_value_;
    easyar_ThreeDofCameraDevice_inputFrameSource(this->cdata_.get(), &_return_value_);
    if (!(_return_value_ != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    return InputFrameSource::from_cdata(std::shared_ptr<easyar_InputFrameSource>(_return_value_, [](easyar_InputFrameSource * ptr) { easyar_InputFrameSource__dtor(ptr); }));
}
_INLINE_SPECIFIER_ void ThreeDofCameraDevice::setFocusMode(ThreeDofCameraDeviceFocusMode focusMode)
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_ThreeDofCameraDevice_setFocusMode(this->cdata_.get(), static_cast<easyar_ThreeDofCameraDeviceFocusMode>(focusMode));
}
_INLINE_SPECIFIER_ CameraDeviceType ThreeDofCameraDevice::type()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_ThreeDofCameraDevice_type(this->cdata_.get());
    return static_cast<CameraDeviceType>(_return_value_);
}
_INLINE_SPECIFIER_ int ThreeDofCameraDevice::cameraOrientation()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_ThreeDofCameraDevice_cameraOrientation(this->cdata_.get());
    return _return_value_;
}
_INLINE_SPECIFIER_ Vec2I ThreeDofCameraDevice::size()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_ThreeDofCameraDevice_size(this->cdata_.get());
    return Vec2I{{{_return_value_.data[0], _return_value_.data[1]}}};
}
_INLINE_SPECIFIER_ int ThreeDofCameraDevice::supportedSizeCount()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_ThreeDofCameraDevice_supportedSizeCount(this->cdata_.get());
    return _return_value_;
}
_INLINE_SPECIFIER_ Vec2I ThreeDofCameraDevice::supportedSize(int index)
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_ThreeDofCameraDevice_supportedSize(this->cdata_.get(), index);
    return Vec2I{{{_return_value_.data[0], _return_value_.data[1]}}};
}
_INLINE_SPECIFIER_ bool ThreeDofCameraDevice::setSize(Vec2I size)
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_ThreeDofCameraDevice_setSize(this->cdata_.get(), easyar_Vec2I{{size.data[0], size.data[1]}});
    return _return_value_;
}
_INLINE_SPECIFIER_ bool ThreeDofCameraDevice::open()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_ThreeDofCameraDevice_open(this->cdata_.get());
    return _return_value_;
}
_INLINE_SPECIFIER_ bool ThreeDofCameraDevice::start()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_ThreeDofCameraDevice_start(this->cdata_.get());
    return _return_value_;
}
_INLINE_SPECIFIER_ void ThreeDofCameraDevice::stop()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_ThreeDofCameraDevice_stop(this->cdata_.get());
}
_INLINE_SPECIFIER_ void ThreeDofCameraDevice::close()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_ThreeDofCameraDevice_close(this->cdata_.get());
}
_INLINE_SPECIFIER_ double ThreeDofCameraDevice::frameRateRangeLower()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_ThreeDofCameraDevice_frameRateRangeLower(this->cdata_.get());
    return _return_value_;
}
_INLINE_SPECIFIER_ double ThreeDofCameraDevice::frameRateRangeUpper()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_ThreeDofCameraDevice_frameRateRangeUpper(this->cdata_.get());
    return _return_value_;
}

_INLINE_SPECIFIER_ VisionOSARKitCameraDevice::VisionOSARKitCameraDevice(std::shared_ptr<easyar_VisionOSARKitCameraDevice> cdata)
    :
    cdata_(nullptr)
{
    init_cdata(cdata);
}
_INLINE_SPECIFIER_ VisionOSARKitCameraDevice::~VisionOSARKitCameraDevice()
{
    cdata_ = nullptr;
}

_INLINE_SPECIFIER_ std::shared_ptr<easyar_VisionOSARKitCameraDevice> VisionOSARKitCameraDevice::get_cdata()
{
    return cdata_;
}
_INLINE_SPECIFIER_ void VisionOSARKitCameraDevice::init_cdata(std::shared_ptr<easyar_VisionOSARKitCameraDevice> cdata)
{
    cdata_ = cdata;
}
_INLINE_SPECIFIER_ std::shared_ptr<VisionOSARKitCameraDevice> VisionOSARKitCameraDevice::from_cdata(std::shared_ptr<easyar_VisionOSARKitCameraDevice> cdata)
{
    if (cdata == nullptr) {
        return nullptr;
    }
    return std::make_shared<VisionOSARKitCameraDevice>(cdata);
}
_INLINE_SPECIFIER_ VisionOSARKitCameraDevice::VisionOSARKitCameraDevice()
    :
    cdata_(nullptr)
{
    easyar_VisionOSARKitCameraDevice * _return_value_;
    easyar_VisionOSARKitCameraDevice__ctor(&_return_value_);
    if (!(_return_value_ != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    init_cdata(std::shared_ptr<easyar_VisionOSARKitCameraDevice>(_return_value_, [](easyar_VisionOSARKitCameraDevice * ptr) { easyar_VisionOSARKitCameraDevice__dtor(ptr); }));
}
_INLINE_SPECIFIER_ bool VisionOSARKitCameraDevice::isAvailable()
{
    auto _return_value_ = easyar_VisionOSARKitCameraDevice_isAvailable();
    return _return_value_;
}
_INLINE_SPECIFIER_ int VisionOSARKitCameraDevice::bufferCapacity()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_VisionOSARKitCameraDevice_bufferCapacity(this->cdata_.get());
    return _return_value_;
}
_INLINE_SPECIFIER_ void VisionOSARKitCameraDevice::setBufferCapacity(int capacity)
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_VisionOSARKitCameraDevice_setBufferCapacity(this->cdata_.get(), capacity);
}
_INLINE_SPECIFIER_ void VisionOSARKitCameraDevice::requestPermissions(std::shared_ptr<CallbackScheduler> callbackScheduler, std::optional<std::function<void(PermissionStatus, std::string)>> permissionCallback)
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    if (!(callbackScheduler != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: callbackScheduler");
#else
        std::terminate();
#endif
    }
    if (!(!permissionCallback.has_value() || (permissionCallback.value() != nullptr))) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: permissionCallback");
#else
        std::terminate();
#endif
    }
    easyar_VisionOSARKitCameraDevice_requestPermissions(this->cdata_.get(), callbackScheduler->get_cdata().get(), (permissionCallback.has_value() ? easyar_OptionalOfFunctorOfVoidFromPermissionStatusAndString{true, FunctorOfVoidFromPermissionStatusAndString_to_c(permissionCallback.value())} : easyar_OptionalOfFunctorOfVoidFromPermissionStatusAndString{false, {}}));
}
_INLINE_SPECIFIER_ std::shared_ptr<InputFrameSource> VisionOSARKitCameraDevice::inputFrameSource()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_InputFrameSource * _return_value_;
    easyar_VisionOSARKitCameraDevice_inputFrameSource(this->cdata_.get(), &_return_value_);
    if (!(_return_value_ != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    return InputFrameSource::from_cdata(std::shared_ptr<easyar_InputFrameSource>(_return_value_, [](easyar_InputFrameSource * ptr) { easyar_InputFrameSource__dtor(ptr); }));
}
_INLINE_SPECIFIER_ std::optional<std::shared_ptr<MotionInputData>> VisionOSARKitCameraDevice::getMotionInputData()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_OptionalOfMotionInputData _return_value_;
    easyar_VisionOSARKitCameraDevice_getMotionInputData(this->cdata_.get(), &_return_value_);
    if (!(!_return_value_.has_value || (_return_value_.value != nullptr))) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    return (_return_value_.has_value ? MotionInputData::from_cdata(std::shared_ptr<easyar_MotionInputData>(_return_value_.value, [](easyar_MotionInputData * ptr) { easyar_MotionInputData__dtor(ptr); })) : std::optional<std::shared_ptr<MotionInputData>>{});
}
_INLINE_SPECIFIER_ bool VisionOSARKitCameraDevice::start()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_VisionOSARKitCameraDevice_start(this->cdata_.get());
    return _return_value_;
}
_INLINE_SPECIFIER_ void VisionOSARKitCameraDevice::stop()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_VisionOSARKitCameraDevice_stop(this->cdata_.get());
}
_INLINE_SPECIFIER_ void VisionOSARKitCameraDevice::close()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_VisionOSARKitCameraDevice_close(this->cdata_.get());
}
_INLINE_SPECIFIER_ Vec2I VisionOSARKitCameraDevice::size()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_VisionOSARKitCameraDevice_size(this->cdata_.get());
    return Vec2I{{{_return_value_.data[0], _return_value_.data[1]}}};
}
_INLINE_SPECIFIER_ CameraDeviceType VisionOSARKitCameraDevice::type()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_VisionOSARKitCameraDevice_type(this->cdata_.get());
    return static_cast<CameraDeviceType>(_return_value_);
}
_INLINE_SPECIFIER_ int VisionOSARKitCameraDevice::cameraOrientation()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_VisionOSARKitCameraDevice_cameraOrientation(this->cdata_.get());
    return _return_value_;
}
_INLINE_SPECIFIER_ double VisionOSARKitCameraDevice::frameRateRangeLower()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_VisionOSARKitCameraDevice_frameRateRangeLower(this->cdata_.get());
    return _return_value_;
}
_INLINE_SPECIFIER_ double VisionOSARKitCameraDevice::frameRateRangeUpper()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_VisionOSARKitCameraDevice_frameRateRangeUpper(this->cdata_.get());
    return _return_value_;
}

_INLINE_SPECIFIER_ XREALCameraDevice::XREALCameraDevice(std::shared_ptr<easyar_XREALCameraDevice> cdata)
    :
    cdata_(nullptr)
{
    init_cdata(cdata);
}
_INLINE_SPECIFIER_ XREALCameraDevice::~XREALCameraDevice()
{
    cdata_ = nullptr;
}

_INLINE_SPECIFIER_ std::shared_ptr<easyar_XREALCameraDevice> XREALCameraDevice::get_cdata()
{
    return cdata_;
}
_INLINE_SPECIFIER_ void XREALCameraDevice::init_cdata(std::shared_ptr<easyar_XREALCameraDevice> cdata)
{
    cdata_ = cdata;
}
_INLINE_SPECIFIER_ std::shared_ptr<XREALCameraDevice> XREALCameraDevice::from_cdata(std::shared_ptr<easyar_XREALCameraDevice> cdata)
{
    if (cdata == nullptr) {
        return nullptr;
    }
    return std::make_shared<XREALCameraDevice>(cdata);
}
_INLINE_SPECIFIER_ XREALCameraDevice::XREALCameraDevice()
    :
    cdata_(nullptr)
{
    easyar_XREALCameraDevice * _return_value_;
    easyar_XREALCameraDevice__ctor(&_return_value_);
    if (!(_return_value_ != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    init_cdata(std::shared_ptr<easyar_XREALCameraDevice>(_return_value_, [](easyar_XREALCameraDevice * ptr) { easyar_XREALCameraDevice__dtor(ptr); }));
}
_INLINE_SPECIFIER_ bool XREALCameraDevice::isAvailable()
{
    auto _return_value_ = easyar_XREALCameraDevice_isAvailable();
    return _return_value_;
}
_INLINE_SPECIFIER_ std::optional<bool> XREALCameraDevice::isDeviceSupported()
{
    auto _return_value_ = easyar_XREALCameraDevice_isDeviceSupported();
    return (_return_value_.has_value ? _return_value_.value : std::optional<bool>{});
}
_INLINE_SPECIFIER_ int XREALCameraDevice::bufferCapacity()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_XREALCameraDevice_bufferCapacity(this->cdata_.get());
    return _return_value_;
}
_INLINE_SPECIFIER_ void XREALCameraDevice::setBufferCapacity(int capacity)
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_XREALCameraDevice_setBufferCapacity(this->cdata_.get(), capacity);
}
_INLINE_SPECIFIER_ std::shared_ptr<InputFrameSource> XREALCameraDevice::inputFrameSource()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_InputFrameSource * _return_value_;
    easyar_XREALCameraDevice_inputFrameSource(this->cdata_.get(), &_return_value_);
    if (!(_return_value_ != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    return InputFrameSource::from_cdata(std::shared_ptr<easyar_InputFrameSource>(_return_value_, [](easyar_InputFrameSource * ptr) { easyar_InputFrameSource__dtor(ptr); }));
}
_INLINE_SPECIFIER_ std::optional<std::shared_ptr<MotionInputData>> XREALCameraDevice::getMotionInputData()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_OptionalOfMotionInputData _return_value_;
    easyar_XREALCameraDevice_getMotionInputData(this->cdata_.get(), &_return_value_);
    if (!(!_return_value_.has_value || (_return_value_.value != nullptr))) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    return (_return_value_.has_value ? MotionInputData::from_cdata(std::shared_ptr<easyar_MotionInputData>(_return_value_.value, [](easyar_MotionInputData * ptr) { easyar_MotionInputData__dtor(ptr); })) : std::optional<std::shared_ptr<MotionInputData>>{});
}
_INLINE_SPECIFIER_ int XREALCameraDevice::receivedFrameCount()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_XREALCameraDevice_receivedFrameCount(this->cdata_.get());
    return _return_value_;
}
_INLINE_SPECIFIER_ bool XREALCameraDevice::open()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_XREALCameraDevice_open(this->cdata_.get());
    return _return_value_;
}
_INLINE_SPECIFIER_ bool XREALCameraDevice::start()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_XREALCameraDevice_start(this->cdata_.get());
    return _return_value_;
}
_INLINE_SPECIFIER_ void XREALCameraDevice::stop()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_XREALCameraDevice_stop(this->cdata_.get());
}
_INLINE_SPECIFIER_ void XREALCameraDevice::close()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_XREALCameraDevice_close(this->cdata_.get());
}
_INLINE_SPECIFIER_ CameraDeviceType XREALCameraDevice::type()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_XREALCameraDevice_type(this->cdata_.get());
    return static_cast<CameraDeviceType>(_return_value_);
}
_INLINE_SPECIFIER_ int XREALCameraDevice::cameraOrientation()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_XREALCameraDevice_cameraOrientation(this->cdata_.get());
    return _return_value_;
}
_INLINE_SPECIFIER_ Vec2I XREALCameraDevice::size()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_XREALCameraDevice_size(this->cdata_.get());
    return Vec2I{{{_return_value_.data[0], _return_value_.data[1]}}};
}
_INLINE_SPECIFIER_ double XREALCameraDevice::frameRate()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_XREALCameraDevice_frameRate(this->cdata_.get());
    return _return_value_;
}

_INLINE_SPECIFIER_ SurfaceTrackerResult::SurfaceTrackerResult(std::shared_ptr<easyar_SurfaceTrackerResult> cdata)
    :
    FrameFilterResult(std::shared_ptr<easyar_FrameFilterResult>(nullptr)),
    cdata_(nullptr)
{
    init_cdata(cdata);
}
_INLINE_SPECIFIER_ SurfaceTrackerResult::~SurfaceTrackerResult()
{
    cdata_ = nullptr;
}

_INLINE_SPECIFIER_ std::shared_ptr<easyar_SurfaceTrackerResult> SurfaceTrackerResult::get_cdata()
{
    return cdata_;
}
_INLINE_SPECIFIER_ void SurfaceTrackerResult::init_cdata(std::shared_ptr<easyar_SurfaceTrackerResult> cdata)
{
    cdata_ = cdata;
    {
        easyar_FrameFilterResult * ptr = nullptr;
        easyar_castSurfaceTrackerResultToFrameFilterResult(cdata_.get(), &ptr);
        FrameFilterResult::init_cdata(std::shared_ptr<easyar_FrameFilterResult>(ptr, [](easyar_FrameFilterResult * ptr) { easyar_FrameFilterResult__dtor(ptr); }));
    }
}
_INLINE_SPECIFIER_ std::shared_ptr<SurfaceTrackerResult> SurfaceTrackerResult::from_cdata(std::shared_ptr<easyar_SurfaceTrackerResult> cdata)
{
    if (cdata == nullptr) {
        return nullptr;
    }
    return std::make_shared<SurfaceTrackerResult>(cdata);
}
_INLINE_SPECIFIER_ Matrix44F SurfaceTrackerResult::transform()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_SurfaceTrackerResult_transform(this->cdata_.get());
    return Matrix44F{{{_return_value_.data[0], _return_value_.data[1], _return_value_.data[2], _return_value_.data[3], _return_value_.data[4], _return_value_.data[5], _return_value_.data[6], _return_value_.data[7], _return_value_.data[8], _return_value_.data[9], _return_value_.data[10], _return_value_.data[11], _return_value_.data[12], _return_value_.data[13], _return_value_.data[14], _return_value_.data[15]}}};
}

_INLINE_SPECIFIER_ SurfaceTracker::SurfaceTracker(std::shared_ptr<easyar_SurfaceTracker> cdata)
    :
    cdata_(nullptr)
{
    init_cdata(cdata);
}
_INLINE_SPECIFIER_ SurfaceTracker::~SurfaceTracker()
{
    cdata_ = nullptr;
}

_INLINE_SPECIFIER_ std::shared_ptr<easyar_SurfaceTracker> SurfaceTracker::get_cdata()
{
    return cdata_;
}
_INLINE_SPECIFIER_ void SurfaceTracker::init_cdata(std::shared_ptr<easyar_SurfaceTracker> cdata)
{
    cdata_ = cdata;
}
_INLINE_SPECIFIER_ std::shared_ptr<SurfaceTracker> SurfaceTracker::from_cdata(std::shared_ptr<easyar_SurfaceTracker> cdata)
{
    if (cdata == nullptr) {
        return nullptr;
    }
    return std::make_shared<SurfaceTracker>(cdata);
}
_INLINE_SPECIFIER_ bool SurfaceTracker::isAvailable()
{
    auto _return_value_ = easyar_SurfaceTracker_isAvailable();
    return _return_value_;
}
_INLINE_SPECIFIER_ std::shared_ptr<InputFrameSink> SurfaceTracker::inputFrameSink()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_InputFrameSink * _return_value_;
    easyar_SurfaceTracker_inputFrameSink(this->cdata_.get(), &_return_value_);
    if (!(_return_value_ != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    return InputFrameSink::from_cdata(std::shared_ptr<easyar_InputFrameSink>(_return_value_, [](easyar_InputFrameSink * ptr) { easyar_InputFrameSink__dtor(ptr); }));
}
_INLINE_SPECIFIER_ int SurfaceTracker::bufferRequirement()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_SurfaceTracker_bufferRequirement(this->cdata_.get());
    return _return_value_;
}
_INLINE_SPECIFIER_ std::shared_ptr<OutputFrameSource> SurfaceTracker::outputFrameSource()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_OutputFrameSource * _return_value_;
    easyar_SurfaceTracker_outputFrameSource(this->cdata_.get(), &_return_value_);
    if (!(_return_value_ != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    return OutputFrameSource::from_cdata(std::shared_ptr<easyar_OutputFrameSource>(_return_value_, [](easyar_OutputFrameSource * ptr) { easyar_OutputFrameSource__dtor(ptr); }));
}
_INLINE_SPECIFIER_ std::shared_ptr<SurfaceTracker> SurfaceTracker::create()
{
    easyar_SurfaceTracker * _return_value_;
    easyar_SurfaceTracker_create(&_return_value_);
    if (!(_return_value_ != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    return SurfaceTracker::from_cdata(std::shared_ptr<easyar_SurfaceTracker>(_return_value_, [](easyar_SurfaceTracker * ptr) { easyar_SurfaceTracker__dtor(ptr); }));
}
_INLINE_SPECIFIER_ bool SurfaceTracker::start()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_SurfaceTracker_start(this->cdata_.get());
    return _return_value_;
}
_INLINE_SPECIFIER_ void SurfaceTracker::stop()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_SurfaceTracker_stop(this->cdata_.get());
}
_INLINE_SPECIFIER_ void SurfaceTracker::close()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_SurfaceTracker_close(this->cdata_.get());
}
_INLINE_SPECIFIER_ void SurfaceTracker::alignTargetToCameraImagePoint(Vec2F cameraImagePoint)
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_SurfaceTracker_alignTargetToCameraImagePoint(this->cdata_.get(), easyar_Vec2F{{cameraImagePoint.data[0], cameraImagePoint.data[1]}});
}

_INLINE_SPECIFIER_ EventDumpRecorder::EventDumpRecorder(std::shared_ptr<easyar_EventDumpRecorder> cdata)
    :
    cdata_(nullptr)
{
    init_cdata(cdata);
}
_INLINE_SPECIFIER_ EventDumpRecorder::~EventDumpRecorder()
{
    cdata_ = nullptr;
}

_INLINE_SPECIFIER_ std::shared_ptr<easyar_EventDumpRecorder> EventDumpRecorder::get_cdata()
{
    return cdata_;
}
_INLINE_SPECIFIER_ void EventDumpRecorder::init_cdata(std::shared_ptr<easyar_EventDumpRecorder> cdata)
{
    cdata_ = cdata;
}
_INLINE_SPECIFIER_ std::shared_ptr<EventDumpRecorder> EventDumpRecorder::from_cdata(std::shared_ptr<easyar_EventDumpRecorder> cdata)
{
    if (cdata == nullptr) {
        return nullptr;
    }
    return std::make_shared<EventDumpRecorder>(cdata);
}
_INLINE_SPECIFIER_ std::shared_ptr<EventDumpRecorder> EventDumpRecorder::create()
{
    easyar_EventDumpRecorder * _return_value_;
    easyar_EventDumpRecorder_create(&_return_value_);
    if (!(_return_value_ != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    return EventDumpRecorder::from_cdata(std::shared_ptr<easyar_EventDumpRecorder>(_return_value_, [](easyar_EventDumpRecorder * ptr) { easyar_EventDumpRecorder__dtor(ptr); }));
}
_INLINE_SPECIFIER_ bool EventDumpRecorder::start(std::string filePath, int initalScreenRotation)
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_EventDumpRecorder_start(this->cdata_.get(), std_string_to_easyar_String(filePath).get(), initalScreenRotation);
    return _return_value_;
}
_INLINE_SPECIFIER_ void EventDumpRecorder::stop()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_EventDumpRecorder_stop(this->cdata_.get());
}

_INLINE_SPECIFIER_ MotionTrackerCameraDevice::MotionTrackerCameraDevice(std::shared_ptr<easyar_MotionTrackerCameraDevice> cdata)
    :
    cdata_(nullptr)
{
    init_cdata(cdata);
}
_INLINE_SPECIFIER_ MotionTrackerCameraDevice::~MotionTrackerCameraDevice()
{
    cdata_ = nullptr;
}

_INLINE_SPECIFIER_ std::shared_ptr<easyar_MotionTrackerCameraDevice> MotionTrackerCameraDevice::get_cdata()
{
    return cdata_;
}
_INLINE_SPECIFIER_ void MotionTrackerCameraDevice::init_cdata(std::shared_ptr<easyar_MotionTrackerCameraDevice> cdata)
{
    cdata_ = cdata;
}
_INLINE_SPECIFIER_ std::shared_ptr<MotionTrackerCameraDevice> MotionTrackerCameraDevice::from_cdata(std::shared_ptr<easyar_MotionTrackerCameraDevice> cdata)
{
    if (cdata == nullptr) {
        return nullptr;
    }
    return std::make_shared<MotionTrackerCameraDevice>(cdata);
}
_INLINE_SPECIFIER_ MotionTrackerCameraDevice::MotionTrackerCameraDevice()
    :
    cdata_(nullptr)
{
    easyar_MotionTrackerCameraDevice * _return_value_;
    easyar_MotionTrackerCameraDevice__ctor(&_return_value_);
    if (!(_return_value_ != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    init_cdata(std::shared_ptr<easyar_MotionTrackerCameraDevice>(_return_value_, [](easyar_MotionTrackerCameraDevice * ptr) { easyar_MotionTrackerCameraDevice__dtor(ptr); }));
}
_INLINE_SPECIFIER_ bool MotionTrackerCameraDevice::isAvailable()
{
    auto _return_value_ = easyar_MotionTrackerCameraDevice_isAvailable();
    return _return_value_;
}
_INLINE_SPECIFIER_ MotionTrackerCameraDeviceQualityLevel MotionTrackerCameraDevice::getQualityLevel()
{
    auto _return_value_ = easyar_MotionTrackerCameraDevice_getQualityLevel();
    return static_cast<MotionTrackerCameraDeviceQualityLevel>(_return_value_);
}
_INLINE_SPECIFIER_ bool MotionTrackerCameraDevice::setFrameRateType(MotionTrackerCameraDeviceFPS fps)
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_MotionTrackerCameraDevice_setFrameRateType(this->cdata_.get(), static_cast<easyar_MotionTrackerCameraDeviceFPS>(fps));
    return _return_value_;
}
_INLINE_SPECIFIER_ bool MotionTrackerCameraDevice::setFocusMode(MotionTrackerCameraDeviceFocusMode focusMode)
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_MotionTrackerCameraDevice_setFocusMode(this->cdata_.get(), static_cast<easyar_MotionTrackerCameraDeviceFocusMode>(focusMode));
    return _return_value_;
}
_INLINE_SPECIFIER_ bool MotionTrackerCameraDevice::setFrameResolutionType(MotionTrackerCameraDeviceResolution resolution)
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_MotionTrackerCameraDevice_setFrameResolutionType(this->cdata_.get(), static_cast<easyar_MotionTrackerCameraDeviceResolution>(resolution));
    return _return_value_;
}
_INLINE_SPECIFIER_ bool MotionTrackerCameraDevice::setTrackingMode(MotionTrackerCameraDeviceTrackingMode trackingMode)
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_MotionTrackerCameraDevice_setTrackingMode(this->cdata_.get(), static_cast<easyar_MotionTrackerCameraDeviceTrackingMode>(trackingMode));
    return _return_value_;
}
_INLINE_SPECIFIER_ void MotionTrackerCameraDevice::setBufferCapacity(int capacity)
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_MotionTrackerCameraDevice_setBufferCapacity(this->cdata_.get(), capacity);
}
_INLINE_SPECIFIER_ int MotionTrackerCameraDevice::bufferCapacity()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_MotionTrackerCameraDevice_bufferCapacity(this->cdata_.get());
    return _return_value_;
}
_INLINE_SPECIFIER_ std::shared_ptr<InputFrameSource> MotionTrackerCameraDevice::inputFrameSource()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_InputFrameSource * _return_value_;
    easyar_MotionTrackerCameraDevice_inputFrameSource(this->cdata_.get(), &_return_value_);
    if (!(_return_value_ != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    return InputFrameSource::from_cdata(std::shared_ptr<easyar_InputFrameSource>(_return_value_, [](easyar_InputFrameSource * ptr) { easyar_InputFrameSource__dtor(ptr); }));
}
_INLINE_SPECIFIER_ bool MotionTrackerCameraDevice::start()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_MotionTrackerCameraDevice_start(this->cdata_.get());
    return _return_value_;
}
_INLINE_SPECIFIER_ void MotionTrackerCameraDevice::stop()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_MotionTrackerCameraDevice_stop(this->cdata_.get());
}
_INLINE_SPECIFIER_ void MotionTrackerCameraDevice::close()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_MotionTrackerCameraDevice_close(this->cdata_.get());
}
_INLINE_SPECIFIER_ CameraDeviceType MotionTrackerCameraDevice::type()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_MotionTrackerCameraDevice_type(this->cdata_.get());
    return static_cast<CameraDeviceType>(_return_value_);
}
_INLINE_SPECIFIER_ int MotionTrackerCameraDevice::cameraOrientation()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_MotionTrackerCameraDevice_cameraOrientation(this->cdata_.get());
    return _return_value_;
}
_INLINE_SPECIFIER_ Vec2I MotionTrackerCameraDevice::size()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_MotionTrackerCameraDevice_size(this->cdata_.get());
    return Vec2I{{{_return_value_.data[0], _return_value_.data[1]}}};
}
_INLINE_SPECIFIER_ double MotionTrackerCameraDevice::frameRateRangeLower()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_MotionTrackerCameraDevice_frameRateRangeLower(this->cdata_.get());
    return _return_value_;
}
_INLINE_SPECIFIER_ double MotionTrackerCameraDevice::frameRateRangeUpper()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_MotionTrackerCameraDevice_frameRateRangeUpper(this->cdata_.get());
    return _return_value_;
}
_INLINE_SPECIFIER_ std::vector<Vec3F> MotionTrackerCameraDevice::hitTestAgainstPointCloud(Vec2F cameraImagePoint)
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_ListOfVec3F * _return_value_;
    easyar_MotionTrackerCameraDevice_hitTestAgainstPointCloud(this->cdata_.get(), easyar_Vec2F{{cameraImagePoint.data[0], cameraImagePoint.data[1]}}, &_return_value_);
    if (!(_return_value_ != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    return std_vector_from_easyar_ListOfVec3F(std::shared_ptr<easyar_ListOfVec3F>(_return_value_, [](easyar_ListOfVec3F * ptr) { easyar_ListOfVec3F__dtor(ptr); }));
}
_INLINE_SPECIFIER_ std::vector<Vec3F> MotionTrackerCameraDevice::hitTestAgainstHorizontalPlane(Vec2F cameraImagePoint)
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_ListOfVec3F * _return_value_;
    easyar_MotionTrackerCameraDevice_hitTestAgainstHorizontalPlane(this->cdata_.get(), easyar_Vec2F{{cameraImagePoint.data[0], cameraImagePoint.data[1]}}, &_return_value_);
    if (!(_return_value_ != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    return std_vector_from_easyar_ListOfVec3F(std::shared_ptr<easyar_ListOfVec3F>(_return_value_, [](easyar_ListOfVec3F * ptr) { easyar_ListOfVec3F__dtor(ptr); }));
}
_INLINE_SPECIFIER_ std::vector<Vec3F> MotionTrackerCameraDevice::getLocalPointsCloud()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_ListOfVec3F * _return_value_;
    easyar_MotionTrackerCameraDevice_getLocalPointsCloud(this->cdata_.get(), &_return_value_);
    if (!(_return_value_ != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    return std_vector_from_easyar_ListOfVec3F(std::shared_ptr<easyar_ListOfVec3F>(_return_value_, [](easyar_ListOfVec3F * ptr) { easyar_ListOfVec3F__dtor(ptr); }));
}

_INLINE_SPECIFIER_ InputFrameRecorder::InputFrameRecorder(std::shared_ptr<easyar_InputFrameRecorder> cdata)
    :
    cdata_(nullptr)
{
    init_cdata(cdata);
}
_INLINE_SPECIFIER_ InputFrameRecorder::~InputFrameRecorder()
{
    cdata_ = nullptr;
}

_INLINE_SPECIFIER_ std::shared_ptr<easyar_InputFrameRecorder> InputFrameRecorder::get_cdata()
{
    return cdata_;
}
_INLINE_SPECIFIER_ void InputFrameRecorder::init_cdata(std::shared_ptr<easyar_InputFrameRecorder> cdata)
{
    cdata_ = cdata;
}
_INLINE_SPECIFIER_ std::shared_ptr<InputFrameRecorder> InputFrameRecorder::from_cdata(std::shared_ptr<easyar_InputFrameRecorder> cdata)
{
    if (cdata == nullptr) {
        return nullptr;
    }
    return std::make_shared<InputFrameRecorder>(cdata);
}
_INLINE_SPECIFIER_ std::shared_ptr<InputFrameSink> InputFrameRecorder::input()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_InputFrameSink * _return_value_;
    easyar_InputFrameRecorder_input(this->cdata_.get(), &_return_value_);
    if (!(_return_value_ != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    return InputFrameSink::from_cdata(std::shared_ptr<easyar_InputFrameSink>(_return_value_, [](easyar_InputFrameSink * ptr) { easyar_InputFrameSink__dtor(ptr); }));
}
_INLINE_SPECIFIER_ int InputFrameRecorder::bufferRequirement()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_InputFrameRecorder_bufferRequirement(this->cdata_.get());
    return _return_value_;
}
_INLINE_SPECIFIER_ std::shared_ptr<InputFrameSource> InputFrameRecorder::output()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_InputFrameSource * _return_value_;
    easyar_InputFrameRecorder_output(this->cdata_.get(), &_return_value_);
    if (!(_return_value_ != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    return InputFrameSource::from_cdata(std::shared_ptr<easyar_InputFrameSource>(_return_value_, [](easyar_InputFrameSource * ptr) { easyar_InputFrameSource__dtor(ptr); }));
}
_INLINE_SPECIFIER_ std::shared_ptr<InputFrameRecorder> InputFrameRecorder::create()
{
    easyar_InputFrameRecorder * _return_value_;
    easyar_InputFrameRecorder_create(&_return_value_);
    if (!(_return_value_ != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    return InputFrameRecorder::from_cdata(std::shared_ptr<easyar_InputFrameRecorder>(_return_value_, [](easyar_InputFrameRecorder * ptr) { easyar_InputFrameRecorder__dtor(ptr); }));
}
_INLINE_SPECIFIER_ bool InputFrameRecorder::start(std::string filePath, int initialScreenRotation)
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_InputFrameRecorder_start(this->cdata_.get(), std_string_to_easyar_String(filePath).get(), initialScreenRotation);
    return _return_value_;
}
_INLINE_SPECIFIER_ void InputFrameRecorder::stop()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_InputFrameRecorder_stop(this->cdata_.get());
}

_INLINE_SPECIFIER_ InputFramePlayer::InputFramePlayer(std::shared_ptr<easyar_InputFramePlayer> cdata)
    :
    cdata_(nullptr)
{
    init_cdata(cdata);
}
_INLINE_SPECIFIER_ InputFramePlayer::~InputFramePlayer()
{
    cdata_ = nullptr;
}

_INLINE_SPECIFIER_ std::shared_ptr<easyar_InputFramePlayer> InputFramePlayer::get_cdata()
{
    return cdata_;
}
_INLINE_SPECIFIER_ void InputFramePlayer::init_cdata(std::shared_ptr<easyar_InputFramePlayer> cdata)
{
    cdata_ = cdata;
}
_INLINE_SPECIFIER_ std::shared_ptr<InputFramePlayer> InputFramePlayer::from_cdata(std::shared_ptr<easyar_InputFramePlayer> cdata)
{
    if (cdata == nullptr) {
        return nullptr;
    }
    return std::make_shared<InputFramePlayer>(cdata);
}
_INLINE_SPECIFIER_ std::shared_ptr<InputFrameSource> InputFramePlayer::output()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_InputFrameSource * _return_value_;
    easyar_InputFramePlayer_output(this->cdata_.get(), &_return_value_);
    if (!(_return_value_ != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    return InputFrameSource::from_cdata(std::shared_ptr<easyar_InputFrameSource>(_return_value_, [](easyar_InputFrameSource * ptr) { easyar_InputFrameSource__dtor(ptr); }));
}
_INLINE_SPECIFIER_ std::shared_ptr<InputFramePlayer> InputFramePlayer::create()
{
    easyar_InputFramePlayer * _return_value_;
    easyar_InputFramePlayer_create(&_return_value_);
    if (!(_return_value_ != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    return InputFramePlayer::from_cdata(std::shared_ptr<easyar_InputFramePlayer>(_return_value_, [](easyar_InputFramePlayer * ptr) { easyar_InputFramePlayer__dtor(ptr); }));
}
_INLINE_SPECIFIER_ bool InputFramePlayer::start(std::string filePath)
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_InputFramePlayer_start(this->cdata_.get(), std_string_to_easyar_String(filePath).get());
    return _return_value_;
}
_INLINE_SPECIFIER_ void InputFramePlayer::stop()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_InputFramePlayer_stop(this->cdata_.get());
}
_INLINE_SPECIFIER_ void InputFramePlayer::pause()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_InputFramePlayer_pause(this->cdata_.get());
}
_INLINE_SPECIFIER_ bool InputFramePlayer::resume()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_InputFramePlayer_resume(this->cdata_.get());
    return _return_value_;
}
_INLINE_SPECIFIER_ double InputFramePlayer::totalTime()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_InputFramePlayer_totalTime(this->cdata_.get());
    return _return_value_;
}
_INLINE_SPECIFIER_ double InputFramePlayer::currentTime()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_InputFramePlayer_currentTime(this->cdata_.get());
    return _return_value_;
}
_INLINE_SPECIFIER_ int InputFramePlayer::initalScreenRotation()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_InputFramePlayer_initalScreenRotation(this->cdata_.get());
    return _return_value_;
}
_INLINE_SPECIFIER_ bool InputFramePlayer::isCompleted()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_InputFramePlayer_isCompleted(this->cdata_.get());
    return _return_value_;
}

_INLINE_SPECIFIER_ VideoInputFrameRecorder::VideoInputFrameRecorder(std::shared_ptr<easyar_VideoInputFrameRecorder> cdata)
    :
    cdata_(nullptr)
{
    init_cdata(cdata);
}
_INLINE_SPECIFIER_ VideoInputFrameRecorder::~VideoInputFrameRecorder()
{
    cdata_ = nullptr;
}

_INLINE_SPECIFIER_ std::shared_ptr<easyar_VideoInputFrameRecorder> VideoInputFrameRecorder::get_cdata()
{
    return cdata_;
}
_INLINE_SPECIFIER_ void VideoInputFrameRecorder::init_cdata(std::shared_ptr<easyar_VideoInputFrameRecorder> cdata)
{
    cdata_ = cdata;
}
_INLINE_SPECIFIER_ std::shared_ptr<VideoInputFrameRecorder> VideoInputFrameRecorder::from_cdata(std::shared_ptr<easyar_VideoInputFrameRecorder> cdata)
{
    if (cdata == nullptr) {
        return nullptr;
    }
    return std::make_shared<VideoInputFrameRecorder>(cdata);
}
_INLINE_SPECIFIER_ bool VideoInputFrameRecorder::isAvailable()
{
    auto _return_value_ = easyar_VideoInputFrameRecorder_isAvailable();
    return _return_value_;
}
_INLINE_SPECIFIER_ std::shared_ptr<InputFrameSink> VideoInputFrameRecorder::input()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_InputFrameSink * _return_value_;
    easyar_VideoInputFrameRecorder_input(this->cdata_.get(), &_return_value_);
    if (!(_return_value_ != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    return InputFrameSink::from_cdata(std::shared_ptr<easyar_InputFrameSink>(_return_value_, [](easyar_InputFrameSink * ptr) { easyar_InputFrameSink__dtor(ptr); }));
}
_INLINE_SPECIFIER_ std::shared_ptr<AccelerometerResultSink> VideoInputFrameRecorder::accelerometerResultSink()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_AccelerometerResultSink * _return_value_;
    easyar_VideoInputFrameRecorder_accelerometerResultSink(this->cdata_.get(), &_return_value_);
    if (!(_return_value_ != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    return AccelerometerResultSink::from_cdata(std::shared_ptr<easyar_AccelerometerResultSink>(_return_value_, [](easyar_AccelerometerResultSink * ptr) { easyar_AccelerometerResultSink__dtor(ptr); }));
}
_INLINE_SPECIFIER_ std::shared_ptr<GyroscopeResultSink> VideoInputFrameRecorder::gyroscopeResultSink()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_GyroscopeResultSink * _return_value_;
    easyar_VideoInputFrameRecorder_gyroscopeResultSink(this->cdata_.get(), &_return_value_);
    if (!(_return_value_ != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    return GyroscopeResultSink::from_cdata(std::shared_ptr<easyar_GyroscopeResultSink>(_return_value_, [](easyar_GyroscopeResultSink * ptr) { easyar_GyroscopeResultSink__dtor(ptr); }));
}
_INLINE_SPECIFIER_ std::shared_ptr<AttitudeSensorResultSink> VideoInputFrameRecorder::attitudeSensorResultSink()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_AttitudeSensorResultSink * _return_value_;
    easyar_VideoInputFrameRecorder_attitudeSensorResultSink(this->cdata_.get(), &_return_value_);
    if (!(_return_value_ != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    return AttitudeSensorResultSink::from_cdata(std::shared_ptr<easyar_AttitudeSensorResultSink>(_return_value_, [](easyar_AttitudeSensorResultSink * ptr) { easyar_AttitudeSensorResultSink__dtor(ptr); }));
}
_INLINE_SPECIFIER_ std::shared_ptr<MagnetometerResultSink> VideoInputFrameRecorder::magnetometerResultSink()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_MagnetometerResultSink * _return_value_;
    easyar_VideoInputFrameRecorder_magnetometerResultSink(this->cdata_.get(), &_return_value_);
    if (!(_return_value_ != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    return MagnetometerResultSink::from_cdata(std::shared_ptr<easyar_MagnetometerResultSink>(_return_value_, [](easyar_MagnetometerResultSink * ptr) { easyar_MagnetometerResultSink__dtor(ptr); }));
}
_INLINE_SPECIFIER_ std::shared_ptr<LocationResultSink> VideoInputFrameRecorder::locationResultSink()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_LocationResultSink * _return_value_;
    easyar_VideoInputFrameRecorder_locationResultSink(this->cdata_.get(), &_return_value_);
    if (!(_return_value_ != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    return LocationResultSink::from_cdata(std::shared_ptr<easyar_LocationResultSink>(_return_value_, [](easyar_LocationResultSink * ptr) { easyar_LocationResultSink__dtor(ptr); }));
}
_INLINE_SPECIFIER_ std::shared_ptr<ProximityLocationResultSink> VideoInputFrameRecorder::proximityLocationResultSink()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_ProximityLocationResultSink * _return_value_;
    easyar_VideoInputFrameRecorder_proximityLocationResultSink(this->cdata_.get(), &_return_value_);
    if (!(_return_value_ != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    return ProximityLocationResultSink::from_cdata(std::shared_ptr<easyar_ProximityLocationResultSink>(_return_value_, [](easyar_ProximityLocationResultSink * ptr) { easyar_ProximityLocationResultSink__dtor(ptr); }));
}
_INLINE_SPECIFIER_ int VideoInputFrameRecorder::bufferRequirement()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_VideoInputFrameRecorder_bufferRequirement(this->cdata_.get());
    return _return_value_;
}
_INLINE_SPECIFIER_ std::shared_ptr<InputFrameSource> VideoInputFrameRecorder::output()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_InputFrameSource * _return_value_;
    easyar_VideoInputFrameRecorder_output(this->cdata_.get(), &_return_value_);
    if (!(_return_value_ != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    return InputFrameSource::from_cdata(std::shared_ptr<easyar_InputFrameSource>(_return_value_, [](easyar_InputFrameSource * ptr) { easyar_InputFrameSource__dtor(ptr); }));
}
_INLINE_SPECIFIER_ std::shared_ptr<VideoInputFrameRecorder> VideoInputFrameRecorder::create()
{
    easyar_VideoInputFrameRecorder * _return_value_;
    easyar_VideoInputFrameRecorder_create(&_return_value_);
    if (!(_return_value_ != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    return VideoInputFrameRecorder::from_cdata(std::shared_ptr<easyar_VideoInputFrameRecorder>(_return_value_, [](easyar_VideoInputFrameRecorder * ptr) { easyar_VideoInputFrameRecorder__dtor(ptr); }));
}
_INLINE_SPECIFIER_ bool VideoInputFrameRecorder::start(std::string filePath, CameraDeviceType cameraDeviceType, int cameraOrientation, int initialScreenRotation, VideoInputFrameRecorderVideoCodec codec, int width, int height, double frameRate, std::string metadata)
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_VideoInputFrameRecorder_start(this->cdata_.get(), std_string_to_easyar_String(filePath).get(), static_cast<easyar_CameraDeviceType>(cameraDeviceType), cameraOrientation, initialScreenRotation, static_cast<easyar_VideoInputFrameRecorderVideoCodec>(codec), width, height, frameRate, std_string_to_easyar_String(metadata).get());
    return _return_value_;
}
_INLINE_SPECIFIER_ void VideoInputFrameRecorder::stop()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_VideoInputFrameRecorder_stop(this->cdata_.get());
}
_INLINE_SPECIFIER_ void VideoInputFrameRecorder::setAutomaticCompletionCallback(std::shared_ptr<CallbackScheduler> callbackScheduler, std::optional<std::function<void(VideoInputFrameRecorderCompletionReason)>> automaticCompletionCallback)
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    if (!(callbackScheduler != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: callbackScheduler");
#else
        std::terminate();
#endif
    }
    if (!(!automaticCompletionCallback.has_value() || (automaticCompletionCallback.value() != nullptr))) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: automaticCompletionCallback");
#else
        std::terminate();
#endif
    }
    easyar_VideoInputFrameRecorder_setAutomaticCompletionCallback(this->cdata_.get(), callbackScheduler->get_cdata().get(), (automaticCompletionCallback.has_value() ? easyar_OptionalOfFunctorOfVoidFromVideoInputFrameRecorderCompletionReason{true, FunctorOfVoidFromVideoInputFrameRecorderCompletionReason_to_c(automaticCompletionCallback.value())} : easyar_OptionalOfFunctorOfVoidFromVideoInputFrameRecorderCompletionReason{false, {}}));
}

_INLINE_SPECIFIER_ VideoInputFramePlayer::VideoInputFramePlayer(std::shared_ptr<easyar_VideoInputFramePlayer> cdata)
    :
    cdata_(nullptr)
{
    init_cdata(cdata);
}
_INLINE_SPECIFIER_ VideoInputFramePlayer::~VideoInputFramePlayer()
{
    cdata_ = nullptr;
}

_INLINE_SPECIFIER_ std::shared_ptr<easyar_VideoInputFramePlayer> VideoInputFramePlayer::get_cdata()
{
    return cdata_;
}
_INLINE_SPECIFIER_ void VideoInputFramePlayer::init_cdata(std::shared_ptr<easyar_VideoInputFramePlayer> cdata)
{
    cdata_ = cdata;
}
_INLINE_SPECIFIER_ std::shared_ptr<VideoInputFramePlayer> VideoInputFramePlayer::from_cdata(std::shared_ptr<easyar_VideoInputFramePlayer> cdata)
{
    if (cdata == nullptr) {
        return nullptr;
    }
    return std::make_shared<VideoInputFramePlayer>(cdata);
}
_INLINE_SPECIFIER_ bool VideoInputFramePlayer::isAvailable()
{
    auto _return_value_ = easyar_VideoInputFramePlayer_isAvailable();
    return _return_value_;
}
_INLINE_SPECIFIER_ std::shared_ptr<InputFrameSource> VideoInputFramePlayer::output()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_InputFrameSource * _return_value_;
    easyar_VideoInputFramePlayer_output(this->cdata_.get(), &_return_value_);
    if (!(_return_value_ != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    return InputFrameSource::from_cdata(std::shared_ptr<easyar_InputFrameSource>(_return_value_, [](easyar_InputFrameSource * ptr) { easyar_InputFrameSource__dtor(ptr); }));
}
_INLINE_SPECIFIER_ std::shared_ptr<AccelerometerResultSource> VideoInputFramePlayer::accelerometerResultSource()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_AccelerometerResultSource * _return_value_;
    easyar_VideoInputFramePlayer_accelerometerResultSource(this->cdata_.get(), &_return_value_);
    if (!(_return_value_ != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    return AccelerometerResultSource::from_cdata(std::shared_ptr<easyar_AccelerometerResultSource>(_return_value_, [](easyar_AccelerometerResultSource * ptr) { easyar_AccelerometerResultSource__dtor(ptr); }));
}
_INLINE_SPECIFIER_ std::shared_ptr<GyroscopeResultSource> VideoInputFramePlayer::gyroscopeResultSource()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_GyroscopeResultSource * _return_value_;
    easyar_VideoInputFramePlayer_gyroscopeResultSource(this->cdata_.get(), &_return_value_);
    if (!(_return_value_ != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    return GyroscopeResultSource::from_cdata(std::shared_ptr<easyar_GyroscopeResultSource>(_return_value_, [](easyar_GyroscopeResultSource * ptr) { easyar_GyroscopeResultSource__dtor(ptr); }));
}
_INLINE_SPECIFIER_ std::shared_ptr<AttitudeSensorResultSource> VideoInputFramePlayer::attitudeSensorResultSource()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_AttitudeSensorResultSource * _return_value_;
    easyar_VideoInputFramePlayer_attitudeSensorResultSource(this->cdata_.get(), &_return_value_);
    if (!(_return_value_ != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    return AttitudeSensorResultSource::from_cdata(std::shared_ptr<easyar_AttitudeSensorResultSource>(_return_value_, [](easyar_AttitudeSensorResultSource * ptr) { easyar_AttitudeSensorResultSource__dtor(ptr); }));
}
_INLINE_SPECIFIER_ std::shared_ptr<MagnetometerResultSource> VideoInputFramePlayer::magnetometerResultSource()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_MagnetometerResultSource * _return_value_;
    easyar_VideoInputFramePlayer_magnetometerResultSource(this->cdata_.get(), &_return_value_);
    if (!(_return_value_ != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    return MagnetometerResultSource::from_cdata(std::shared_ptr<easyar_MagnetometerResultSource>(_return_value_, [](easyar_MagnetometerResultSource * ptr) { easyar_MagnetometerResultSource__dtor(ptr); }));
}
_INLINE_SPECIFIER_ std::shared_ptr<LocationResultSource> VideoInputFramePlayer::locationResultSource()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_LocationResultSource * _return_value_;
    easyar_VideoInputFramePlayer_locationResultSource(this->cdata_.get(), &_return_value_);
    if (!(_return_value_ != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    return LocationResultSource::from_cdata(std::shared_ptr<easyar_LocationResultSource>(_return_value_, [](easyar_LocationResultSource * ptr) { easyar_LocationResultSource__dtor(ptr); }));
}
_INLINE_SPECIFIER_ std::shared_ptr<ProximityLocationResultSource> VideoInputFramePlayer::proximityLocationResultSource()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_ProximityLocationResultSource * _return_value_;
    easyar_VideoInputFramePlayer_proximityLocationResultSource(this->cdata_.get(), &_return_value_);
    if (!(_return_value_ != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    return ProximityLocationResultSource::from_cdata(std::shared_ptr<easyar_ProximityLocationResultSource>(_return_value_, [](easyar_ProximityLocationResultSource * ptr) { easyar_ProximityLocationResultSource__dtor(ptr); }));
}
_INLINE_SPECIFIER_ std::shared_ptr<VideoInputFramePlayer> VideoInputFramePlayer::create()
{
    easyar_VideoInputFramePlayer * _return_value_;
    easyar_VideoInputFramePlayer_create(&_return_value_);
    if (!(_return_value_ != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    return VideoInputFramePlayer::from_cdata(std::shared_ptr<easyar_VideoInputFramePlayer>(_return_value_, [](easyar_VideoInputFramePlayer * ptr) { easyar_VideoInputFramePlayer__dtor(ptr); }));
}
_INLINE_SPECIFIER_ bool VideoInputFramePlayer::start(std::string filePath)
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_VideoInputFramePlayer_start(this->cdata_.get(), std_string_to_easyar_String(filePath).get());
    return _return_value_;
}
_INLINE_SPECIFIER_ void VideoInputFramePlayer::stop()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_VideoInputFramePlayer_stop(this->cdata_.get());
}
_INLINE_SPECIFIER_ void VideoInputFramePlayer::pause()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_VideoInputFramePlayer_pause(this->cdata_.get());
}
_INLINE_SPECIFIER_ bool VideoInputFramePlayer::resume()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_VideoInputFramePlayer_resume(this->cdata_.get());
    return _return_value_;
}
_INLINE_SPECIFIER_ std::optional<double> VideoInputFramePlayer::totalTime()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_VideoInputFramePlayer_totalTime(this->cdata_.get());
    return (_return_value_.has_value ? _return_value_.value : std::optional<double>{});
}
_INLINE_SPECIFIER_ double VideoInputFramePlayer::currentTime()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_VideoInputFramePlayer_currentTime(this->cdata_.get());
    return _return_value_;
}
_INLINE_SPECIFIER_ bool VideoInputFramePlayer::isSeekable()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_VideoInputFramePlayer_isSeekable(this->cdata_.get());
    return _return_value_;
}
_INLINE_SPECIFIER_ bool VideoInputFramePlayer::seek(double time)
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_VideoInputFramePlayer_seek(this->cdata_.get(), time);
    return _return_value_;
}
_INLINE_SPECIFIER_ double VideoInputFramePlayer::speed()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_VideoInputFramePlayer_speed(this->cdata_.get());
    return _return_value_;
}
_INLINE_SPECIFIER_ void VideoInputFramePlayer::setSpeed(double _value)
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_VideoInputFramePlayer_setSpeed(this->cdata_.get(), _value);
}
_INLINE_SPECIFIER_ int VideoInputFramePlayer::initalScreenRotation()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_VideoInputFramePlayer_initalScreenRotation(this->cdata_.get());
    return _return_value_;
}
_INLINE_SPECIFIER_ std::string VideoInputFramePlayer::metadata()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_String * _return_value_;
    easyar_VideoInputFramePlayer_metadata(this->cdata_.get(), &_return_value_);
    if (!(_return_value_ != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    return std_string_from_easyar_String(std::shared_ptr<easyar_String>(_return_value_, [](easyar_String * ptr) { easyar_String__dtor(ptr); }));
}
_INLINE_SPECIFIER_ bool VideoInputFramePlayer::isCompleted()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_VideoInputFramePlayer_isCompleted(this->cdata_.get());
    return _return_value_;
}

_INLINE_SPECIFIER_ std::optional<std::shared_ptr<Image>> ImageHelper::decode(std::shared_ptr<Buffer> buffer)
{
    if (!(buffer != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: buffer");
#else
        std::terminate();
#endif
    }
    easyar_OptionalOfImage _return_value_;
    easyar_ImageHelper_decode(buffer->get_cdata().get(), &_return_value_);
    if (!(!_return_value_.has_value || (_return_value_.value != nullptr))) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    return (_return_value_.has_value ? Image::from_cdata(std::shared_ptr<easyar_Image>(_return_value_.value, [](easyar_Image * ptr) { easyar_Image__dtor(ptr); })) : std::optional<std::shared_ptr<Image>>{});
}

_INLINE_SPECIFIER_ InertialCameraDevice::InertialCameraDevice(std::shared_ptr<easyar_InertialCameraDevice> cdata)
    :
    cdata_(nullptr)
{
    init_cdata(cdata);
}
_INLINE_SPECIFIER_ InertialCameraDevice::~InertialCameraDevice()
{
    cdata_ = nullptr;
}

_INLINE_SPECIFIER_ std::shared_ptr<easyar_InertialCameraDevice> InertialCameraDevice::get_cdata()
{
    return cdata_;
}
_INLINE_SPECIFIER_ void InertialCameraDevice::init_cdata(std::shared_ptr<easyar_InertialCameraDevice> cdata)
{
    cdata_ = cdata;
}
_INLINE_SPECIFIER_ std::shared_ptr<InertialCameraDevice> InertialCameraDevice::from_cdata(std::shared_ptr<easyar_InertialCameraDevice> cdata)
{
    if (cdata == nullptr) {
        return nullptr;
    }
    return std::make_shared<InertialCameraDevice>(cdata);
}
_INLINE_SPECIFIER_ InertialCameraDevice::InertialCameraDevice()
    :
    cdata_(nullptr)
{
    easyar_InertialCameraDevice * _return_value_;
    easyar_InertialCameraDevice__ctor(&_return_value_);
    if (!(_return_value_ != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    init_cdata(std::shared_ptr<easyar_InertialCameraDevice>(_return_value_, [](easyar_InertialCameraDevice * ptr) { easyar_InertialCameraDevice__dtor(ptr); }));
}
_INLINE_SPECIFIER_ bool InertialCameraDevice::isAvailable()
{
    auto _return_value_ = easyar_InertialCameraDevice_isAvailable();
    return _return_value_;
}
_INLINE_SPECIFIER_ int InertialCameraDevice::bufferCapacity()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_InertialCameraDevice_bufferCapacity(this->cdata_.get());
    return _return_value_;
}
_INLINE_SPECIFIER_ void InertialCameraDevice::setBufferCapacity(int capacity)
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_InertialCameraDevice_setBufferCapacity(this->cdata_.get(), capacity);
}
_INLINE_SPECIFIER_ std::shared_ptr<InputFrameSource> InertialCameraDevice::inputFrameSource()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_InputFrameSource * _return_value_;
    easyar_InertialCameraDevice_inputFrameSource(this->cdata_.get(), &_return_value_);
    if (!(_return_value_ != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    return InputFrameSource::from_cdata(std::shared_ptr<easyar_InputFrameSource>(_return_value_, [](easyar_InputFrameSource * ptr) { easyar_InputFrameSource__dtor(ptr); }));
}
_INLINE_SPECIFIER_ void InertialCameraDevice::setFocusMode(InertialCameraDeviceFocusMode focusMode)
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_InertialCameraDevice_setFocusMode(this->cdata_.get(), static_cast<easyar_InertialCameraDeviceFocusMode>(focusMode));
}
_INLINE_SPECIFIER_ CameraDeviceType InertialCameraDevice::type()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_InertialCameraDevice_type(this->cdata_.get());
    return static_cast<CameraDeviceType>(_return_value_);
}
_INLINE_SPECIFIER_ int InertialCameraDevice::cameraOrientation()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_InertialCameraDevice_cameraOrientation(this->cdata_.get());
    return _return_value_;
}
_INLINE_SPECIFIER_ Vec2I InertialCameraDevice::size()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_InertialCameraDevice_size(this->cdata_.get());
    return Vec2I{{{_return_value_.data[0], _return_value_.data[1]}}};
}
_INLINE_SPECIFIER_ int InertialCameraDevice::supportedSizeCount()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_InertialCameraDevice_supportedSizeCount(this->cdata_.get());
    return _return_value_;
}
_INLINE_SPECIFIER_ Vec2I InertialCameraDevice::supportedSize(int index)
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_InertialCameraDevice_supportedSize(this->cdata_.get(), index);
    return Vec2I{{{_return_value_.data[0], _return_value_.data[1]}}};
}
_INLINE_SPECIFIER_ bool InertialCameraDevice::setSize(Vec2I size)
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_InertialCameraDevice_setSize(this->cdata_.get(), easyar_Vec2I{{size.data[0], size.data[1]}});
    return _return_value_;
}
_INLINE_SPECIFIER_ bool InertialCameraDevice::open()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_InertialCameraDevice_open(this->cdata_.get());
    return _return_value_;
}
_INLINE_SPECIFIER_ bool InertialCameraDevice::start()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_InertialCameraDevice_start(this->cdata_.get());
    return _return_value_;
}
_INLINE_SPECIFIER_ void InertialCameraDevice::stop()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_InertialCameraDevice_stop(this->cdata_.get());
}
_INLINE_SPECIFIER_ void InertialCameraDevice::reset()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_InertialCameraDevice_reset(this->cdata_.get());
}
_INLINE_SPECIFIER_ void InertialCameraDevice::close()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_InertialCameraDevice_close(this->cdata_.get());
}
_INLINE_SPECIFIER_ double InertialCameraDevice::frameRateRangeLower()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_InertialCameraDevice_frameRateRangeLower(this->cdata_.get());
    return _return_value_;
}
_INLINE_SPECIFIER_ double InertialCameraDevice::frameRateRangeUpper()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_InertialCameraDevice_frameRateRangeUpper(this->cdata_.get());
    return _return_value_;
}

_INLINE_SPECIFIER_ CallbackScheduler::CallbackScheduler(std::shared_ptr<easyar_CallbackScheduler> cdata)
    :
    cdata_(nullptr)
{
    init_cdata(cdata);
}
_INLINE_SPECIFIER_ CallbackScheduler::~CallbackScheduler()
{
    cdata_ = nullptr;
}

_INLINE_SPECIFIER_ std::shared_ptr<easyar_CallbackScheduler> CallbackScheduler::get_cdata()
{
    return cdata_;
}
_INLINE_SPECIFIER_ void CallbackScheduler::init_cdata(std::shared_ptr<easyar_CallbackScheduler> cdata)
{
    cdata_ = cdata;
}
_INLINE_SPECIFIER_ std::shared_ptr<CallbackScheduler> CallbackScheduler::from_cdata(std::shared_ptr<easyar_CallbackScheduler> cdata)
{
    if (cdata == nullptr) {
        return nullptr;
    }
    std::string typeName = easyar_CallbackScheduler__typeName(cdata.get());
    if (typeName == "DelayedCallbackScheduler") {
        easyar_DelayedCallbackScheduler * st_cdata;
        easyar_tryCastCallbackSchedulerToDelayedCallbackScheduler(cdata.get(), &st_cdata);
        return std::static_pointer_cast<CallbackScheduler>(std::make_shared<DelayedCallbackScheduler>(std::shared_ptr<easyar_DelayedCallbackScheduler>(st_cdata, [](easyar_DelayedCallbackScheduler * ptr) { easyar_DelayedCallbackScheduler__dtor(ptr); })));
    }
    if (typeName == "ImmediateCallbackScheduler") {
        easyar_ImmediateCallbackScheduler * st_cdata;
        easyar_tryCastCallbackSchedulerToImmediateCallbackScheduler(cdata.get(), &st_cdata);
        return std::static_pointer_cast<CallbackScheduler>(std::make_shared<ImmediateCallbackScheduler>(std::shared_ptr<easyar_ImmediateCallbackScheduler>(st_cdata, [](easyar_ImmediateCallbackScheduler * ptr) { easyar_ImmediateCallbackScheduler__dtor(ptr); })));
    }
    return std::make_shared<CallbackScheduler>(cdata);
}

_INLINE_SPECIFIER_ DelayedCallbackScheduler::DelayedCallbackScheduler(std::shared_ptr<easyar_DelayedCallbackScheduler> cdata)
    :
    CallbackScheduler(std::shared_ptr<easyar_CallbackScheduler>(nullptr)),
    cdata_(nullptr)
{
    init_cdata(cdata);
}
_INLINE_SPECIFIER_ DelayedCallbackScheduler::~DelayedCallbackScheduler()
{
    cdata_ = nullptr;
}

_INLINE_SPECIFIER_ std::shared_ptr<easyar_DelayedCallbackScheduler> DelayedCallbackScheduler::get_cdata()
{
    return cdata_;
}
_INLINE_SPECIFIER_ void DelayedCallbackScheduler::init_cdata(std::shared_ptr<easyar_DelayedCallbackScheduler> cdata)
{
    cdata_ = cdata;
    {
        easyar_CallbackScheduler * ptr = nullptr;
        easyar_castDelayedCallbackSchedulerToCallbackScheduler(cdata_.get(), &ptr);
        CallbackScheduler::init_cdata(std::shared_ptr<easyar_CallbackScheduler>(ptr, [](easyar_CallbackScheduler * ptr) { easyar_CallbackScheduler__dtor(ptr); }));
    }
}
_INLINE_SPECIFIER_ std::shared_ptr<DelayedCallbackScheduler> DelayedCallbackScheduler::from_cdata(std::shared_ptr<easyar_DelayedCallbackScheduler> cdata)
{
    if (cdata == nullptr) {
        return nullptr;
    }
    return std::make_shared<DelayedCallbackScheduler>(cdata);
}
_INLINE_SPECIFIER_ DelayedCallbackScheduler::DelayedCallbackScheduler()
    :
    CallbackScheduler(std::shared_ptr<easyar_CallbackScheduler>(nullptr)),
    cdata_(nullptr)
{
    easyar_DelayedCallbackScheduler * _return_value_;
    easyar_DelayedCallbackScheduler__ctor(&_return_value_);
    if (!(_return_value_ != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    init_cdata(std::shared_ptr<easyar_DelayedCallbackScheduler>(_return_value_, [](easyar_DelayedCallbackScheduler * ptr) { easyar_DelayedCallbackScheduler__dtor(ptr); }));
}
_INLINE_SPECIFIER_ bool DelayedCallbackScheduler::runOne()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_DelayedCallbackScheduler_runOne(this->cdata_.get());
    return _return_value_;
}

_INLINE_SPECIFIER_ ImmediateCallbackScheduler::ImmediateCallbackScheduler(std::shared_ptr<easyar_ImmediateCallbackScheduler> cdata)
    :
    CallbackScheduler(std::shared_ptr<easyar_CallbackScheduler>(nullptr)),
    cdata_(nullptr)
{
    init_cdata(cdata);
}
_INLINE_SPECIFIER_ ImmediateCallbackScheduler::~ImmediateCallbackScheduler()
{
    cdata_ = nullptr;
}

_INLINE_SPECIFIER_ std::shared_ptr<easyar_ImmediateCallbackScheduler> ImmediateCallbackScheduler::get_cdata()
{
    return cdata_;
}
_INLINE_SPECIFIER_ void ImmediateCallbackScheduler::init_cdata(std::shared_ptr<easyar_ImmediateCallbackScheduler> cdata)
{
    cdata_ = cdata;
    {
        easyar_CallbackScheduler * ptr = nullptr;
        easyar_castImmediateCallbackSchedulerToCallbackScheduler(cdata_.get(), &ptr);
        CallbackScheduler::init_cdata(std::shared_ptr<easyar_CallbackScheduler>(ptr, [](easyar_CallbackScheduler * ptr) { easyar_CallbackScheduler__dtor(ptr); }));
    }
}
_INLINE_SPECIFIER_ std::shared_ptr<ImmediateCallbackScheduler> ImmediateCallbackScheduler::from_cdata(std::shared_ptr<easyar_ImmediateCallbackScheduler> cdata)
{
    if (cdata == nullptr) {
        return nullptr;
    }
    return std::make_shared<ImmediateCallbackScheduler>(cdata);
}
_INLINE_SPECIFIER_ std::shared_ptr<ImmediateCallbackScheduler> ImmediateCallbackScheduler::getDefault()
{
    easyar_ImmediateCallbackScheduler * _return_value_;
    easyar_ImmediateCallbackScheduler_getDefault(&_return_value_);
    if (!(_return_value_ != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    return ImmediateCallbackScheduler::from_cdata(std::shared_ptr<easyar_ImmediateCallbackScheduler>(_return_value_, [](easyar_ImmediateCallbackScheduler * ptr) { easyar_ImmediateCallbackScheduler__dtor(ptr); }));
}

_INLINE_SPECIFIER_ std::shared_ptr<Buffer> JniUtility::wrapByteArray(void * bytes, bool readOnly, std::function<void()> deleter)
{
    if (!(deleter != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: deleter");
#else
        std::terminate();
#endif
    }
    easyar_Buffer * _return_value_;
    easyar_JniUtility_wrapByteArray(bytes, readOnly, FunctorOfVoid_to_c(deleter), &_return_value_);
    if (!(_return_value_ != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    return Buffer::from_cdata(std::shared_ptr<easyar_Buffer>(_return_value_, [](easyar_Buffer * ptr) { easyar_Buffer__dtor(ptr); }));
}
_INLINE_SPECIFIER_ std::shared_ptr<Buffer> JniUtility::wrapBuffer(void * directBuffer, std::function<void()> deleter)
{
    if (!(deleter != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: deleter");
#else
        std::terminate();
#endif
    }
    easyar_Buffer * _return_value_;
    easyar_JniUtility_wrapBuffer(directBuffer, FunctorOfVoid_to_c(deleter), &_return_value_);
    if (!(_return_value_ != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    return Buffer::from_cdata(std::shared_ptr<easyar_Buffer>(_return_value_, [](easyar_Buffer * ptr) { easyar_Buffer__dtor(ptr); }));
}
_INLINE_SPECIFIER_ void * JniUtility::getDirectBufferAddress(void * directBuffer)
{
    auto _return_value_ = easyar_JniUtility_getDirectBufferAddress(directBuffer);
    return _return_value_;
}

_INLINE_SPECIFIER_ void Log::logMessage(LogLevel level, std::string message)
{
    easyar_Log_logMessage(static_cast<easyar_LogLevel>(level), std_string_to_easyar_String(message).get());
}
_INLINE_SPECIFIER_ void Log::setLogFunc(std::function<void(LogLevel, std::string)> func)
{
    if (!(func != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: func");
#else
        std::terminate();
#endif
    }
    easyar_Log_setLogFunc(FunctorOfVoidFromLogLevelAndString_to_c(func));
}
_INLINE_SPECIFIER_ void Log::setLogFuncWithScheduler(std::shared_ptr<CallbackScheduler> scheduler, std::function<void(LogLevel, std::string)> func)
{
    if (!(scheduler != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: scheduler");
#else
        std::terminate();
#endif
    }
    if (!(func != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: func");
#else
        std::terminate();
#endif
    }
    easyar_Log_setLogFuncWithScheduler(scheduler->get_cdata().get(), FunctorOfVoidFromLogLevelAndString_to_c(func));
}
_INLINE_SPECIFIER_ void Log::resetLogFunc()
{
    easyar_Log_resetLogFunc();
}

_INLINE_SPECIFIER_ void Storage::setAssetDirPath(std::string path)
{
    easyar_Storage_setAssetDirPath(std_string_to_easyar_String(path).get());
}

_INLINE_SPECIFIER_ ImageTargetParameters::ImageTargetParameters(std::shared_ptr<easyar_ImageTargetParameters> cdata)
    :
    cdata_(nullptr)
{
    init_cdata(cdata);
}
_INLINE_SPECIFIER_ ImageTargetParameters::~ImageTargetParameters()
{
    cdata_ = nullptr;
}

_INLINE_SPECIFIER_ std::shared_ptr<easyar_ImageTargetParameters> ImageTargetParameters::get_cdata()
{
    return cdata_;
}
_INLINE_SPECIFIER_ void ImageTargetParameters::init_cdata(std::shared_ptr<easyar_ImageTargetParameters> cdata)
{
    cdata_ = cdata;
}
_INLINE_SPECIFIER_ std::shared_ptr<ImageTargetParameters> ImageTargetParameters::from_cdata(std::shared_ptr<easyar_ImageTargetParameters> cdata)
{
    if (cdata == nullptr) {
        return nullptr;
    }
    return std::make_shared<ImageTargetParameters>(cdata);
}
_INLINE_SPECIFIER_ ImageTargetParameters::ImageTargetParameters()
    :
    cdata_(nullptr)
{
    easyar_ImageTargetParameters * _return_value_;
    easyar_ImageTargetParameters__ctor(&_return_value_);
    if (!(_return_value_ != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    init_cdata(std::shared_ptr<easyar_ImageTargetParameters>(_return_value_, [](easyar_ImageTargetParameters * ptr) { easyar_ImageTargetParameters__dtor(ptr); }));
}
_INLINE_SPECIFIER_ std::shared_ptr<Image> ImageTargetParameters::image()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_Image * _return_value_;
    easyar_ImageTargetParameters_image(this->cdata_.get(), &_return_value_);
    if (!(_return_value_ != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    return Image::from_cdata(std::shared_ptr<easyar_Image>(_return_value_, [](easyar_Image * ptr) { easyar_Image__dtor(ptr); }));
}
_INLINE_SPECIFIER_ void ImageTargetParameters::setImage(std::shared_ptr<Image> image)
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    if (!(image != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: image");
#else
        std::terminate();
#endif
    }
    easyar_ImageTargetParameters_setImage(this->cdata_.get(), image->get_cdata().get());
}
_INLINE_SPECIFIER_ std::string ImageTargetParameters::name()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_String * _return_value_;
    easyar_ImageTargetParameters_name(this->cdata_.get(), &_return_value_);
    if (!(_return_value_ != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    return std_string_from_easyar_String(std::shared_ptr<easyar_String>(_return_value_, [](easyar_String * ptr) { easyar_String__dtor(ptr); }));
}
_INLINE_SPECIFIER_ void ImageTargetParameters::setName(std::string name)
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_ImageTargetParameters_setName(this->cdata_.get(), std_string_to_easyar_String(name).get());
}
_INLINE_SPECIFIER_ std::string ImageTargetParameters::uid()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_String * _return_value_;
    easyar_ImageTargetParameters_uid(this->cdata_.get(), &_return_value_);
    if (!(_return_value_ != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    return std_string_from_easyar_String(std::shared_ptr<easyar_String>(_return_value_, [](easyar_String * ptr) { easyar_String__dtor(ptr); }));
}
_INLINE_SPECIFIER_ void ImageTargetParameters::setUid(std::string uid)
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_ImageTargetParameters_setUid(this->cdata_.get(), std_string_to_easyar_String(uid).get());
}
_INLINE_SPECIFIER_ std::string ImageTargetParameters::meta()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_String * _return_value_;
    easyar_ImageTargetParameters_meta(this->cdata_.get(), &_return_value_);
    if (!(_return_value_ != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    return std_string_from_easyar_String(std::shared_ptr<easyar_String>(_return_value_, [](easyar_String * ptr) { easyar_String__dtor(ptr); }));
}
_INLINE_SPECIFIER_ void ImageTargetParameters::setMeta(std::string meta)
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_ImageTargetParameters_setMeta(this->cdata_.get(), std_string_to_easyar_String(meta).get());
}
_INLINE_SPECIFIER_ float ImageTargetParameters::scale()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_ImageTargetParameters_scale(this->cdata_.get());
    return _return_value_;
}
_INLINE_SPECIFIER_ void ImageTargetParameters::setScale(float scale)
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_ImageTargetParameters_setScale(this->cdata_.get(), scale);
}

_INLINE_SPECIFIER_ ImageTarget::ImageTarget(std::shared_ptr<easyar_ImageTarget> cdata)
    :
    Target(std::shared_ptr<easyar_Target>(nullptr)),
    cdata_(nullptr)
{
    init_cdata(cdata);
}
_INLINE_SPECIFIER_ ImageTarget::~ImageTarget()
{
    cdata_ = nullptr;
}

_INLINE_SPECIFIER_ std::shared_ptr<easyar_ImageTarget> ImageTarget::get_cdata()
{
    return cdata_;
}
_INLINE_SPECIFIER_ void ImageTarget::init_cdata(std::shared_ptr<easyar_ImageTarget> cdata)
{
    cdata_ = cdata;
    {
        easyar_Target * ptr = nullptr;
        easyar_castImageTargetToTarget(cdata_.get(), &ptr);
        Target::init_cdata(std::shared_ptr<easyar_Target>(ptr, [](easyar_Target * ptr) { easyar_Target__dtor(ptr); }));
    }
}
_INLINE_SPECIFIER_ std::shared_ptr<ImageTarget> ImageTarget::from_cdata(std::shared_ptr<easyar_ImageTarget> cdata)
{
    if (cdata == nullptr) {
        return nullptr;
    }
    return std::make_shared<ImageTarget>(cdata);
}
_INLINE_SPECIFIER_ ImageTarget::ImageTarget()
    :
    Target(std::shared_ptr<easyar_Target>(nullptr)),
    cdata_(nullptr)
{
    easyar_ImageTarget * _return_value_;
    easyar_ImageTarget__ctor(&_return_value_);
    if (!(_return_value_ != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    init_cdata(std::shared_ptr<easyar_ImageTarget>(_return_value_, [](easyar_ImageTarget * ptr) { easyar_ImageTarget__dtor(ptr); }));
}
_INLINE_SPECIFIER_ std::optional<std::shared_ptr<ImageTarget>> ImageTarget::createFromParameters(std::shared_ptr<ImageTargetParameters> parameters)
{
    if (!(parameters != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: parameters");
#else
        std::terminate();
#endif
    }
    easyar_OptionalOfImageTarget _return_value_;
    easyar_ImageTarget_createFromParameters(parameters->get_cdata().get(), &_return_value_);
    if (!(!_return_value_.has_value || (_return_value_.value != nullptr))) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    return (_return_value_.has_value ? ImageTarget::from_cdata(std::shared_ptr<easyar_ImageTarget>(_return_value_.value, [](easyar_ImageTarget * ptr) { easyar_ImageTarget__dtor(ptr); })) : std::optional<std::shared_ptr<ImageTarget>>{});
}
_INLINE_SPECIFIER_ std::optional<std::shared_ptr<ImageTarget>> ImageTarget::createFromTargetFile(std::string path, StorageType storageType)
{
    easyar_OptionalOfImageTarget _return_value_;
    easyar_ImageTarget_createFromTargetFile(std_string_to_easyar_String(path).get(), static_cast<easyar_StorageType>(storageType), &_return_value_);
    if (!(!_return_value_.has_value || (_return_value_.value != nullptr))) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    return (_return_value_.has_value ? ImageTarget::from_cdata(std::shared_ptr<easyar_ImageTarget>(_return_value_.value, [](easyar_ImageTarget * ptr) { easyar_ImageTarget__dtor(ptr); })) : std::optional<std::shared_ptr<ImageTarget>>{});
}
_INLINE_SPECIFIER_ std::optional<std::shared_ptr<ImageTarget>> ImageTarget::createFromTargetData(std::shared_ptr<Buffer> buffer)
{
    if (!(buffer != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: buffer");
#else
        std::terminate();
#endif
    }
    easyar_OptionalOfImageTarget _return_value_;
    easyar_ImageTarget_createFromTargetData(buffer->get_cdata().get(), &_return_value_);
    if (!(!_return_value_.has_value || (_return_value_.value != nullptr))) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    return (_return_value_.has_value ? ImageTarget::from_cdata(std::shared_ptr<easyar_ImageTarget>(_return_value_.value, [](easyar_ImageTarget * ptr) { easyar_ImageTarget__dtor(ptr); })) : std::optional<std::shared_ptr<ImageTarget>>{});
}
_INLINE_SPECIFIER_ bool ImageTarget::save(std::string path)
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_ImageTarget_save(this->cdata_.get(), std_string_to_easyar_String(path).get());
    return _return_value_;
}
_INLINE_SPECIFIER_ std::optional<std::shared_ptr<ImageTarget>> ImageTarget::createFromImageFile(std::string path, StorageType storageType, std::string name, std::string uid, std::string meta, float scale)
{
    easyar_OptionalOfImageTarget _return_value_;
    easyar_ImageTarget_createFromImageFile(std_string_to_easyar_String(path).get(), static_cast<easyar_StorageType>(storageType), std_string_to_easyar_String(name).get(), std_string_to_easyar_String(uid).get(), std_string_to_easyar_String(meta).get(), scale, &_return_value_);
    if (!(!_return_value_.has_value || (_return_value_.value != nullptr))) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    return (_return_value_.has_value ? ImageTarget::from_cdata(std::shared_ptr<easyar_ImageTarget>(_return_value_.value, [](easyar_ImageTarget * ptr) { easyar_ImageTarget__dtor(ptr); })) : std::optional<std::shared_ptr<ImageTarget>>{});
}
_INLINE_SPECIFIER_ float ImageTarget::scale()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_ImageTarget_scale(this->cdata_.get());
    return _return_value_;
}
_INLINE_SPECIFIER_ float ImageTarget::aspectRatio()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_ImageTarget_aspectRatio(this->cdata_.get());
    return _return_value_;
}
_INLINE_SPECIFIER_ bool ImageTarget::setScale(float scale)
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_ImageTarget_setScale(this->cdata_.get(), scale);
    return _return_value_;
}
_INLINE_SPECIFIER_ std::vector<std::shared_ptr<Image>> ImageTarget::images()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_ListOfImage * _return_value_;
    easyar_ImageTarget_images(this->cdata_.get(), &_return_value_);
    if (!(_return_value_ != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    return std_vector_from_easyar_ListOfImage(std::shared_ptr<easyar_ListOfImage>(_return_value_, [](easyar_ListOfImage * ptr) { easyar_ListOfImage__dtor(ptr); }));
}
_INLINE_SPECIFIER_ int ImageTarget::runtimeID()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_ImageTarget_runtimeID(this->cdata_.get());
    return _return_value_;
}
_INLINE_SPECIFIER_ std::string ImageTarget::uid()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_String * _return_value_;
    easyar_ImageTarget_uid(this->cdata_.get(), &_return_value_);
    if (!(_return_value_ != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    return std_string_from_easyar_String(std::shared_ptr<easyar_String>(_return_value_, [](easyar_String * ptr) { easyar_String__dtor(ptr); }));
}
_INLINE_SPECIFIER_ std::string ImageTarget::name()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_String * _return_value_;
    easyar_ImageTarget_name(this->cdata_.get(), &_return_value_);
    if (!(_return_value_ != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    return std_string_from_easyar_String(std::shared_ptr<easyar_String>(_return_value_, [](easyar_String * ptr) { easyar_String__dtor(ptr); }));
}
_INLINE_SPECIFIER_ void ImageTarget::setName(std::string name)
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_ImageTarget_setName(this->cdata_.get(), std_string_to_easyar_String(name).get());
}
_INLINE_SPECIFIER_ std::string ImageTarget::meta()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_String * _return_value_;
    easyar_ImageTarget_meta(this->cdata_.get(), &_return_value_);
    if (!(_return_value_ != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    return std_string_from_easyar_String(std::shared_ptr<easyar_String>(_return_value_, [](easyar_String * ptr) { easyar_String__dtor(ptr); }));
}
_INLINE_SPECIFIER_ void ImageTarget::setMeta(std::string data)
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_ImageTarget_setMeta(this->cdata_.get(), std_string_to_easyar_String(data).get());
}

_INLINE_SPECIFIER_ ImageTrackerConfig::ImageTrackerConfig(std::shared_ptr<easyar_ImageTrackerConfig> cdata)
    :
    cdata_(nullptr)
{
    init_cdata(cdata);
}
_INLINE_SPECIFIER_ ImageTrackerConfig::~ImageTrackerConfig()
{
    cdata_ = nullptr;
}

_INLINE_SPECIFIER_ std::shared_ptr<easyar_ImageTrackerConfig> ImageTrackerConfig::get_cdata()
{
    return cdata_;
}
_INLINE_SPECIFIER_ void ImageTrackerConfig::init_cdata(std::shared_ptr<easyar_ImageTrackerConfig> cdata)
{
    cdata_ = cdata;
}
_INLINE_SPECIFIER_ std::shared_ptr<ImageTrackerConfig> ImageTrackerConfig::from_cdata(std::shared_ptr<easyar_ImageTrackerConfig> cdata)
{
    if (cdata == nullptr) {
        return nullptr;
    }
    return std::make_shared<ImageTrackerConfig>(cdata);
}
_INLINE_SPECIFIER_ ImageTrackerConfig::ImageTrackerConfig()
    :
    cdata_(nullptr)
{
    easyar_ImageTrackerConfig * _return_value_;
    easyar_ImageTrackerConfig__ctor(&_return_value_);
    if (!(_return_value_ != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    init_cdata(std::shared_ptr<easyar_ImageTrackerConfig>(_return_value_, [](easyar_ImageTrackerConfig * ptr) { easyar_ImageTrackerConfig__dtor(ptr); }));
}
_INLINE_SPECIFIER_ ImageTrackerMode ImageTrackerConfig::trackerMode()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_ImageTrackerConfig_trackerMode(this->cdata_.get());
    return static_cast<ImageTrackerMode>(_return_value_);
}
_INLINE_SPECIFIER_ void ImageTrackerConfig::setTrackerMode(ImageTrackerMode _value)
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_ImageTrackerConfig_setTrackerMode(this->cdata_.get(), static_cast<easyar_ImageTrackerMode>(_value));
}

_INLINE_SPECIFIER_ ImageTrackerResult::ImageTrackerResult(std::shared_ptr<easyar_ImageTrackerResult> cdata)
    :
    TargetTrackerResult(std::shared_ptr<easyar_TargetTrackerResult>(nullptr)),
    cdata_(nullptr)
{
    init_cdata(cdata);
}
_INLINE_SPECIFIER_ ImageTrackerResult::~ImageTrackerResult()
{
    cdata_ = nullptr;
}

_INLINE_SPECIFIER_ std::shared_ptr<easyar_ImageTrackerResult> ImageTrackerResult::get_cdata()
{
    return cdata_;
}
_INLINE_SPECIFIER_ void ImageTrackerResult::init_cdata(std::shared_ptr<easyar_ImageTrackerResult> cdata)
{
    cdata_ = cdata;
    {
        easyar_TargetTrackerResult * ptr = nullptr;
        easyar_castImageTrackerResultToTargetTrackerResult(cdata_.get(), &ptr);
        TargetTrackerResult::init_cdata(std::shared_ptr<easyar_TargetTrackerResult>(ptr, [](easyar_TargetTrackerResult * ptr) { easyar_TargetTrackerResult__dtor(ptr); }));
    }
}
_INLINE_SPECIFIER_ std::shared_ptr<ImageTrackerResult> ImageTrackerResult::from_cdata(std::shared_ptr<easyar_ImageTrackerResult> cdata)
{
    if (cdata == nullptr) {
        return nullptr;
    }
    return std::make_shared<ImageTrackerResult>(cdata);
}
_INLINE_SPECIFIER_ std::vector<std::shared_ptr<TargetInstance>> ImageTrackerResult::targetInstances()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_ListOfTargetInstance * _return_value_;
    easyar_ImageTrackerResult_targetInstances(this->cdata_.get(), &_return_value_);
    if (!(_return_value_ != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    return std_vector_from_easyar_ListOfTargetInstance(std::shared_ptr<easyar_ListOfTargetInstance>(_return_value_, [](easyar_ListOfTargetInstance * ptr) { easyar_ListOfTargetInstance__dtor(ptr); }));
}
_INLINE_SPECIFIER_ void ImageTrackerResult::setTargetInstances(std::vector<std::shared_ptr<TargetInstance>> instances)
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    if (!easyar_ListOfTargetInstance_check_external_cpp(instances)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: instances");
#else
        std::terminate();
#endif
    }
    easyar_ImageTrackerResult_setTargetInstances(this->cdata_.get(), std_vector_to_easyar_ListOfTargetInstance(instances).get());
}

_INLINE_SPECIFIER_ ImageTracker::ImageTracker(std::shared_ptr<easyar_ImageTracker> cdata)
    :
    cdata_(nullptr)
{
    init_cdata(cdata);
}
_INLINE_SPECIFIER_ ImageTracker::~ImageTracker()
{
    cdata_ = nullptr;
}

_INLINE_SPECIFIER_ std::shared_ptr<easyar_ImageTracker> ImageTracker::get_cdata()
{
    return cdata_;
}
_INLINE_SPECIFIER_ void ImageTracker::init_cdata(std::shared_ptr<easyar_ImageTracker> cdata)
{
    cdata_ = cdata;
}
_INLINE_SPECIFIER_ std::shared_ptr<ImageTracker> ImageTracker::from_cdata(std::shared_ptr<easyar_ImageTracker> cdata)
{
    if (cdata == nullptr) {
        return nullptr;
    }
    return std::make_shared<ImageTracker>(cdata);
}
_INLINE_SPECIFIER_ bool ImageTracker::isAvailable()
{
    auto _return_value_ = easyar_ImageTracker_isAvailable();
    return _return_value_;
}
_INLINE_SPECIFIER_ std::shared_ptr<FeedbackFrameSink> ImageTracker::feedbackFrameSink()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_FeedbackFrameSink * _return_value_;
    easyar_ImageTracker_feedbackFrameSink(this->cdata_.get(), &_return_value_);
    if (!(_return_value_ != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    return FeedbackFrameSink::from_cdata(std::shared_ptr<easyar_FeedbackFrameSink>(_return_value_, [](easyar_FeedbackFrameSink * ptr) { easyar_FeedbackFrameSink__dtor(ptr); }));
}
_INLINE_SPECIFIER_ int ImageTracker::bufferRequirement()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_ImageTracker_bufferRequirement(this->cdata_.get());
    return _return_value_;
}
_INLINE_SPECIFIER_ std::shared_ptr<OutputFrameSource> ImageTracker::outputFrameSource()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_OutputFrameSource * _return_value_;
    easyar_ImageTracker_outputFrameSource(this->cdata_.get(), &_return_value_);
    if (!(_return_value_ != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    return OutputFrameSource::from_cdata(std::shared_ptr<easyar_OutputFrameSource>(_return_value_, [](easyar_OutputFrameSource * ptr) { easyar_OutputFrameSource__dtor(ptr); }));
}
_INLINE_SPECIFIER_ std::shared_ptr<ImageTracker> ImageTracker::create()
{
    easyar_ImageTracker * _return_value_;
    easyar_ImageTracker_create(&_return_value_);
    if (!(_return_value_ != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    return ImageTracker::from_cdata(std::shared_ptr<easyar_ImageTracker>(_return_value_, [](easyar_ImageTracker * ptr) { easyar_ImageTracker__dtor(ptr); }));
}
_INLINE_SPECIFIER_ std::shared_ptr<ImageTracker> ImageTracker::createWithMode(ImageTrackerMode trackMode)
{
    easyar_ImageTracker * _return_value_;
    easyar_ImageTracker_createWithMode(static_cast<easyar_ImageTrackerMode>(trackMode), &_return_value_);
    if (!(_return_value_ != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    return ImageTracker::from_cdata(std::shared_ptr<easyar_ImageTracker>(_return_value_, [](easyar_ImageTracker * ptr) { easyar_ImageTracker__dtor(ptr); }));
}
_INLINE_SPECIFIER_ std::shared_ptr<ImageTracker> ImageTracker::createWithConfig(std::shared_ptr<ImageTrackerConfig> config)
{
    if (!(config != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: config");
#else
        std::terminate();
#endif
    }
    easyar_ImageTracker * _return_value_;
    easyar_ImageTracker_createWithConfig(config->get_cdata().get(), &_return_value_);
    if (!(_return_value_ != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    return ImageTracker::from_cdata(std::shared_ptr<easyar_ImageTracker>(_return_value_, [](easyar_ImageTracker * ptr) { easyar_ImageTracker__dtor(ptr); }));
}
_INLINE_SPECIFIER_ void ImageTracker::setResultPostProcessing(bool enablePersistentTargetInstance, bool enableMotionFusion)
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_ImageTracker_setResultPostProcessing(this->cdata_.get(), enablePersistentTargetInstance, enableMotionFusion);
}
_INLINE_SPECIFIER_ bool ImageTracker::setResultAsyncMode(bool enableAsync)
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_ImageTracker_setResultAsyncMode(this->cdata_.get(), enableAsync);
    return _return_value_;
}
_INLINE_SPECIFIER_ bool ImageTracker::start()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_ImageTracker_start(this->cdata_.get());
    return _return_value_;
}
_INLINE_SPECIFIER_ void ImageTracker::stop()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_ImageTracker_stop(this->cdata_.get());
}
_INLINE_SPECIFIER_ void ImageTracker::close()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_ImageTracker_close(this->cdata_.get());
}
_INLINE_SPECIFIER_ void ImageTracker::loadTarget(std::shared_ptr<Target> target, std::shared_ptr<CallbackScheduler> callbackScheduler, std::function<void(std::shared_ptr<Target>, bool)> callback)
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    if (!(target != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: target");
#else
        std::terminate();
#endif
    }
    if (!(callbackScheduler != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: callbackScheduler");
#else
        std::terminate();
#endif
    }
    if (!(callback != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: callback");
#else
        std::terminate();
#endif
    }
    easyar_ImageTracker_loadTarget(this->cdata_.get(), target->get_cdata().get(), callbackScheduler->get_cdata().get(), FunctorOfVoidFromTargetAndBool_to_c(callback));
}
_INLINE_SPECIFIER_ void ImageTracker::unloadTarget(std::shared_ptr<Target> target, std::shared_ptr<CallbackScheduler> callbackScheduler, std::function<void(std::shared_ptr<Target>, bool)> callback)
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    if (!(target != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: target");
#else
        std::terminate();
#endif
    }
    if (!(callbackScheduler != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: callbackScheduler");
#else
        std::terminate();
#endif
    }
    if (!(callback != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: callback");
#else
        std::terminate();
#endif
    }
    easyar_ImageTracker_unloadTarget(this->cdata_.get(), target->get_cdata().get(), callbackScheduler->get_cdata().get(), FunctorOfVoidFromTargetAndBool_to_c(callback));
}
_INLINE_SPECIFIER_ std::vector<std::shared_ptr<Target>> ImageTracker::targets()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_ListOfTarget * _return_value_;
    easyar_ImageTracker_targets(this->cdata_.get(), &_return_value_);
    if (!(_return_value_ != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    return std_vector_from_easyar_ListOfTarget(std::shared_ptr<easyar_ListOfTarget>(_return_value_, [](easyar_ListOfTarget * ptr) { easyar_ListOfTarget__dtor(ptr); }));
}
_INLINE_SPECIFIER_ bool ImageTracker::setSimultaneousNum(int num)
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_ImageTracker_setSimultaneousNum(this->cdata_.get(), num);
    return _return_value_;
}
_INLINE_SPECIFIER_ int ImageTracker::simultaneousNum()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_ImageTracker_simultaneousNum(this->cdata_.get());
    return _return_value_;
}
_INLINE_SPECIFIER_ std::optional<std::shared_ptr<ImageTrackerResult>> ImageTracker::getSyncResult(std::shared_ptr<MotionInputData> motionInputData)
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    if (!(motionInputData != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: motionInputData");
#else
        std::terminate();
#endif
    }
    easyar_OptionalOfImageTrackerResult _return_value_;
    easyar_ImageTracker_getSyncResult(this->cdata_.get(), motionInputData->get_cdata().get(), &_return_value_);
    if (!(!_return_value_.has_value || (_return_value_.value != nullptr))) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    return (_return_value_.has_value ? ImageTrackerResult::from_cdata(std::shared_ptr<easyar_ImageTrackerResult>(_return_value_.value, [](easyar_ImageTrackerResult * ptr) { easyar_ImageTrackerResult__dtor(ptr); })) : std::optional<std::shared_ptr<ImageTrackerResult>>{});
}

_INLINE_SPECIFIER_ Recorder::Recorder(std::shared_ptr<easyar_Recorder> cdata)
    :
    cdata_(nullptr)
{
    init_cdata(cdata);
}
_INLINE_SPECIFIER_ Recorder::~Recorder()
{
    cdata_ = nullptr;
}

_INLINE_SPECIFIER_ std::shared_ptr<easyar_Recorder> Recorder::get_cdata()
{
    return cdata_;
}
_INLINE_SPECIFIER_ void Recorder::init_cdata(std::shared_ptr<easyar_Recorder> cdata)
{
    cdata_ = cdata;
}
_INLINE_SPECIFIER_ std::shared_ptr<Recorder> Recorder::from_cdata(std::shared_ptr<easyar_Recorder> cdata)
{
    if (cdata == nullptr) {
        return nullptr;
    }
    return std::make_shared<Recorder>(cdata);
}
_INLINE_SPECIFIER_ bool Recorder::isAvailable()
{
    auto _return_value_ = easyar_Recorder_isAvailable();
    return _return_value_;
}
_INLINE_SPECIFIER_ void Recorder::requestPermissions(std::shared_ptr<CallbackScheduler> callbackScheduler, std::optional<std::function<void(PermissionStatus, std::string)>> permissionCallback)
{
    if (!(callbackScheduler != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: callbackScheduler");
#else
        std::terminate();
#endif
    }
    if (!(!permissionCallback.has_value() || (permissionCallback.value() != nullptr))) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: permissionCallback");
#else
        std::terminate();
#endif
    }
    easyar_Recorder_requestPermissions(callbackScheduler->get_cdata().get(), (permissionCallback.has_value() ? easyar_OptionalOfFunctorOfVoidFromPermissionStatusAndString{true, FunctorOfVoidFromPermissionStatusAndString_to_c(permissionCallback.value())} : easyar_OptionalOfFunctorOfVoidFromPermissionStatusAndString{false, {}}));
}
_INLINE_SPECIFIER_ std::shared_ptr<Recorder> Recorder::create(std::shared_ptr<RecorderConfiguration> config, std::shared_ptr<CallbackScheduler> callbackScheduler, std::optional<std::function<void(RecordStatus, std::string)>> statusCallback)
{
    if (!(config != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: config");
#else
        std::terminate();
#endif
    }
    if (!(callbackScheduler != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: callbackScheduler");
#else
        std::terminate();
#endif
    }
    if (!(!statusCallback.has_value() || (statusCallback.value() != nullptr))) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: statusCallback");
#else
        std::terminate();
#endif
    }
    easyar_Recorder * _return_value_;
    easyar_Recorder_create(config->get_cdata().get(), callbackScheduler->get_cdata().get(), (statusCallback.has_value() ? easyar_OptionalOfFunctorOfVoidFromRecordStatusAndString{true, FunctorOfVoidFromRecordStatusAndString_to_c(statusCallback.value())} : easyar_OptionalOfFunctorOfVoidFromRecordStatusAndString{false, {}}), &_return_value_);
    if (!(_return_value_ != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    return Recorder::from_cdata(std::shared_ptr<easyar_Recorder>(_return_value_, [](easyar_Recorder * ptr) { easyar_Recorder__dtor(ptr); }));
}
_INLINE_SPECIFIER_ void Recorder::start()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_Recorder_start(this->cdata_.get());
}
_INLINE_SPECIFIER_ void Recorder::updateFrame(std::shared_ptr<TextureId> texture, int width, int height)
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    if (!(texture != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: texture");
#else
        std::terminate();
#endif
    }
    easyar_Recorder_updateFrame(this->cdata_.get(), texture->get_cdata().get(), width, height);
}
_INLINE_SPECIFIER_ bool Recorder::stop()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_Recorder_stop(this->cdata_.get());
    return _return_value_;
}

_INLINE_SPECIFIER_ RecorderConfiguration::RecorderConfiguration(std::shared_ptr<easyar_RecorderConfiguration> cdata)
    :
    cdata_(nullptr)
{
    init_cdata(cdata);
}
_INLINE_SPECIFIER_ RecorderConfiguration::~RecorderConfiguration()
{
    cdata_ = nullptr;
}

_INLINE_SPECIFIER_ std::shared_ptr<easyar_RecorderConfiguration> RecorderConfiguration::get_cdata()
{
    return cdata_;
}
_INLINE_SPECIFIER_ void RecorderConfiguration::init_cdata(std::shared_ptr<easyar_RecorderConfiguration> cdata)
{
    cdata_ = cdata;
}
_INLINE_SPECIFIER_ std::shared_ptr<RecorderConfiguration> RecorderConfiguration::from_cdata(std::shared_ptr<easyar_RecorderConfiguration> cdata)
{
    if (cdata == nullptr) {
        return nullptr;
    }
    return std::make_shared<RecorderConfiguration>(cdata);
}
_INLINE_SPECIFIER_ RecorderConfiguration::RecorderConfiguration()
    :
    cdata_(nullptr)
{
    easyar_RecorderConfiguration * _return_value_;
    easyar_RecorderConfiguration__ctor(&_return_value_);
    if (!(_return_value_ != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    init_cdata(std::shared_ptr<easyar_RecorderConfiguration>(_return_value_, [](easyar_RecorderConfiguration * ptr) { easyar_RecorderConfiguration__dtor(ptr); }));
}
_INLINE_SPECIFIER_ void RecorderConfiguration::setOutputFile(std::string path)
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_RecorderConfiguration_setOutputFile(this->cdata_.get(), std_string_to_easyar_String(path).get());
}
_INLINE_SPECIFIER_ bool RecorderConfiguration::setProfile(RecordProfile profile)
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_RecorderConfiguration_setProfile(this->cdata_.get(), static_cast<easyar_RecordProfile>(profile));
    return _return_value_;
}
_INLINE_SPECIFIER_ void RecorderConfiguration::setVideoSize(RecordVideoSize framesize)
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_RecorderConfiguration_setVideoSize(this->cdata_.get(), static_cast<easyar_RecordVideoSize>(framesize));
}
_INLINE_SPECIFIER_ void RecorderConfiguration::setVideoBitrate(int bitrate)
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_RecorderConfiguration_setVideoBitrate(this->cdata_.get(), bitrate);
}
_INLINE_SPECIFIER_ void RecorderConfiguration::setChannelCount(int count)
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_RecorderConfiguration_setChannelCount(this->cdata_.get(), count);
}
_INLINE_SPECIFIER_ void RecorderConfiguration::setAudioSampleRate(int samplerate)
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_RecorderConfiguration_setAudioSampleRate(this->cdata_.get(), samplerate);
}
_INLINE_SPECIFIER_ void RecorderConfiguration::setAudioBitrate(int bitrate)
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_RecorderConfiguration_setAudioBitrate(this->cdata_.get(), bitrate);
}
_INLINE_SPECIFIER_ void RecorderConfiguration::setVideoOrientation(RecordVideoOrientation mode)
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_RecorderConfiguration_setVideoOrientation(this->cdata_.get(), static_cast<easyar_RecordVideoOrientation>(mode));
}
_INLINE_SPECIFIER_ void RecorderConfiguration::setZoomMode(RecordZoomMode mode)
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_RecorderConfiguration_setZoomMode(this->cdata_.get(), static_cast<easyar_RecordZoomMode>(mode));
}

_INLINE_SPECIFIER_ SparseSpatialMapResult::SparseSpatialMapResult(std::shared_ptr<easyar_SparseSpatialMapResult> cdata)
    :
    FrameFilterResult(std::shared_ptr<easyar_FrameFilterResult>(nullptr)),
    cdata_(nullptr)
{
    init_cdata(cdata);
}
_INLINE_SPECIFIER_ SparseSpatialMapResult::~SparseSpatialMapResult()
{
    cdata_ = nullptr;
}

_INLINE_SPECIFIER_ std::shared_ptr<easyar_SparseSpatialMapResult> SparseSpatialMapResult::get_cdata()
{
    return cdata_;
}
_INLINE_SPECIFIER_ void SparseSpatialMapResult::init_cdata(std::shared_ptr<easyar_SparseSpatialMapResult> cdata)
{
    cdata_ = cdata;
    {
        easyar_FrameFilterResult * ptr = nullptr;
        easyar_castSparseSpatialMapResultToFrameFilterResult(cdata_.get(), &ptr);
        FrameFilterResult::init_cdata(std::shared_ptr<easyar_FrameFilterResult>(ptr, [](easyar_FrameFilterResult * ptr) { easyar_FrameFilterResult__dtor(ptr); }));
    }
}
_INLINE_SPECIFIER_ std::shared_ptr<SparseSpatialMapResult> SparseSpatialMapResult::from_cdata(std::shared_ptr<easyar_SparseSpatialMapResult> cdata)
{
    if (cdata == nullptr) {
        return nullptr;
    }
    return std::make_shared<SparseSpatialMapResult>(cdata);
}
_INLINE_SPECIFIER_ MotionTrackingStatus SparseSpatialMapResult::getMotionTrackingStatus()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_SparseSpatialMapResult_getMotionTrackingStatus(this->cdata_.get());
    return static_cast<MotionTrackingStatus>(_return_value_);
}
_INLINE_SPECIFIER_ std::optional<Matrix44F> SparseSpatialMapResult::getVioPose()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_SparseSpatialMapResult_getVioPose(this->cdata_.get());
    return (_return_value_.has_value ? Matrix44F{{{_return_value_.value.data[0], _return_value_.value.data[1], _return_value_.value.data[2], _return_value_.value.data[3], _return_value_.value.data[4], _return_value_.value.data[5], _return_value_.value.data[6], _return_value_.value.data[7], _return_value_.value.data[8], _return_value_.value.data[9], _return_value_.value.data[10], _return_value_.value.data[11], _return_value_.value.data[12], _return_value_.value.data[13], _return_value_.value.data[14], _return_value_.value.data[15]}}} : std::optional<Matrix44F>{});
}
_INLINE_SPECIFIER_ std::optional<Matrix44F> SparseSpatialMapResult::getMapPose()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_SparseSpatialMapResult_getMapPose(this->cdata_.get());
    return (_return_value_.has_value ? Matrix44F{{{_return_value_.value.data[0], _return_value_.value.data[1], _return_value_.value.data[2], _return_value_.value.data[3], _return_value_.value.data[4], _return_value_.value.data[5], _return_value_.value.data[6], _return_value_.value.data[7], _return_value_.value.data[8], _return_value_.value.data[9], _return_value_.value.data[10], _return_value_.value.data[11], _return_value_.value.data[12], _return_value_.value.data[13], _return_value_.value.data[14], _return_value_.value.data[15]}}} : std::optional<Matrix44F>{});
}
_INLINE_SPECIFIER_ bool SparseSpatialMapResult::getLocalizationStatus()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_SparseSpatialMapResult_getLocalizationStatus(this->cdata_.get());
    return _return_value_;
}
_INLINE_SPECIFIER_ std::string SparseSpatialMapResult::getLocalizationMapID()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_String * _return_value_;
    easyar_SparseSpatialMapResult_getLocalizationMapID(this->cdata_.get(), &_return_value_);
    if (!(_return_value_ != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    return std_string_from_easyar_String(std::shared_ptr<easyar_String>(_return_value_, [](easyar_String * ptr) { easyar_String__dtor(ptr); }));
}

_INLINE_SPECIFIER_ PlaneData::PlaneData(std::shared_ptr<easyar_PlaneData> cdata)
    :
    cdata_(nullptr)
{
    init_cdata(cdata);
}
_INLINE_SPECIFIER_ PlaneData::~PlaneData()
{
    cdata_ = nullptr;
}

_INLINE_SPECIFIER_ std::shared_ptr<easyar_PlaneData> PlaneData::get_cdata()
{
    return cdata_;
}
_INLINE_SPECIFIER_ void PlaneData::init_cdata(std::shared_ptr<easyar_PlaneData> cdata)
{
    cdata_ = cdata;
}
_INLINE_SPECIFIER_ std::shared_ptr<PlaneData> PlaneData::from_cdata(std::shared_ptr<easyar_PlaneData> cdata)
{
    if (cdata == nullptr) {
        return nullptr;
    }
    return std::make_shared<PlaneData>(cdata);
}
_INLINE_SPECIFIER_ PlaneData::PlaneData()
    :
    cdata_(nullptr)
{
    easyar_PlaneData * _return_value_;
    easyar_PlaneData__ctor(&_return_value_);
    if (!(_return_value_ != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    init_cdata(std::shared_ptr<easyar_PlaneData>(_return_value_, [](easyar_PlaneData * ptr) { easyar_PlaneData__dtor(ptr); }));
}
_INLINE_SPECIFIER_ PlaneType PlaneData::getType()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_PlaneData_getType(this->cdata_.get());
    return static_cast<PlaneType>(_return_value_);
}
_INLINE_SPECIFIER_ Matrix44F PlaneData::getPose()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_PlaneData_getPose(this->cdata_.get());
    return Matrix44F{{{_return_value_.data[0], _return_value_.data[1], _return_value_.data[2], _return_value_.data[3], _return_value_.data[4], _return_value_.data[5], _return_value_.data[6], _return_value_.data[7], _return_value_.data[8], _return_value_.data[9], _return_value_.data[10], _return_value_.data[11], _return_value_.data[12], _return_value_.data[13], _return_value_.data[14], _return_value_.data[15]}}};
}
_INLINE_SPECIFIER_ float PlaneData::getExtentX()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_PlaneData_getExtentX(this->cdata_.get());
    return _return_value_;
}
_INLINE_SPECIFIER_ float PlaneData::getExtentZ()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_PlaneData_getExtentZ(this->cdata_.get());
    return _return_value_;
}

_INLINE_SPECIFIER_ SparseSpatialMapConfig::SparseSpatialMapConfig(std::shared_ptr<easyar_SparseSpatialMapConfig> cdata)
    :
    cdata_(nullptr)
{
    init_cdata(cdata);
}
_INLINE_SPECIFIER_ SparseSpatialMapConfig::~SparseSpatialMapConfig()
{
    cdata_ = nullptr;
}

_INLINE_SPECIFIER_ std::shared_ptr<easyar_SparseSpatialMapConfig> SparseSpatialMapConfig::get_cdata()
{
    return cdata_;
}
_INLINE_SPECIFIER_ void SparseSpatialMapConfig::init_cdata(std::shared_ptr<easyar_SparseSpatialMapConfig> cdata)
{
    cdata_ = cdata;
}
_INLINE_SPECIFIER_ std::shared_ptr<SparseSpatialMapConfig> SparseSpatialMapConfig::from_cdata(std::shared_ptr<easyar_SparseSpatialMapConfig> cdata)
{
    if (cdata == nullptr) {
        return nullptr;
    }
    return std::make_shared<SparseSpatialMapConfig>(cdata);
}
_INLINE_SPECIFIER_ SparseSpatialMapConfig::SparseSpatialMapConfig()
    :
    cdata_(nullptr)
{
    easyar_SparseSpatialMapConfig * _return_value_;
    easyar_SparseSpatialMapConfig__ctor(&_return_value_);
    if (!(_return_value_ != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    init_cdata(std::shared_ptr<easyar_SparseSpatialMapConfig>(_return_value_, [](easyar_SparseSpatialMapConfig * ptr) { easyar_SparseSpatialMapConfig__dtor(ptr); }));
}
_INLINE_SPECIFIER_ void SparseSpatialMapConfig::setLocalizationMode(LocalizationMode _value)
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_SparseSpatialMapConfig_setLocalizationMode(this->cdata_.get(), static_cast<easyar_LocalizationMode>(_value));
}
_INLINE_SPECIFIER_ LocalizationMode SparseSpatialMapConfig::getLocalizationMode()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_SparseSpatialMapConfig_getLocalizationMode(this->cdata_.get());
    return static_cast<LocalizationMode>(_return_value_);
}

_INLINE_SPECIFIER_ SparseSpatialMap::SparseSpatialMap(std::shared_ptr<easyar_SparseSpatialMap> cdata)
    :
    cdata_(nullptr)
{
    init_cdata(cdata);
}
_INLINE_SPECIFIER_ SparseSpatialMap::~SparseSpatialMap()
{
    cdata_ = nullptr;
}

_INLINE_SPECIFIER_ std::shared_ptr<easyar_SparseSpatialMap> SparseSpatialMap::get_cdata()
{
    return cdata_;
}
_INLINE_SPECIFIER_ void SparseSpatialMap::init_cdata(std::shared_ptr<easyar_SparseSpatialMap> cdata)
{
    cdata_ = cdata;
}
_INLINE_SPECIFIER_ std::shared_ptr<SparseSpatialMap> SparseSpatialMap::from_cdata(std::shared_ptr<easyar_SparseSpatialMap> cdata)
{
    if (cdata == nullptr) {
        return nullptr;
    }
    return std::make_shared<SparseSpatialMap>(cdata);
}
_INLINE_SPECIFIER_ bool SparseSpatialMap::isAvailable()
{
    auto _return_value_ = easyar_SparseSpatialMap_isAvailable();
    return _return_value_;
}
_INLINE_SPECIFIER_ std::shared_ptr<InputFrameSink> SparseSpatialMap::inputFrameSink()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_InputFrameSink * _return_value_;
    easyar_SparseSpatialMap_inputFrameSink(this->cdata_.get(), &_return_value_);
    if (!(_return_value_ != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    return InputFrameSink::from_cdata(std::shared_ptr<easyar_InputFrameSink>(_return_value_, [](easyar_InputFrameSink * ptr) { easyar_InputFrameSink__dtor(ptr); }));
}
_INLINE_SPECIFIER_ int SparseSpatialMap::bufferRequirement()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_SparseSpatialMap_bufferRequirement(this->cdata_.get());
    return _return_value_;
}
_INLINE_SPECIFIER_ std::shared_ptr<OutputFrameSource> SparseSpatialMap::outputFrameSource()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_OutputFrameSource * _return_value_;
    easyar_SparseSpatialMap_outputFrameSource(this->cdata_.get(), &_return_value_);
    if (!(_return_value_ != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    return OutputFrameSource::from_cdata(std::shared_ptr<easyar_OutputFrameSource>(_return_value_, [](easyar_OutputFrameSource * ptr) { easyar_OutputFrameSource__dtor(ptr); }));
}
_INLINE_SPECIFIER_ std::shared_ptr<SparseSpatialMap> SparseSpatialMap::create()
{
    easyar_SparseSpatialMap * _return_value_;
    easyar_SparseSpatialMap_create(&_return_value_);
    if (!(_return_value_ != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    return SparseSpatialMap::from_cdata(std::shared_ptr<easyar_SparseSpatialMap>(_return_value_, [](easyar_SparseSpatialMap * ptr) { easyar_SparseSpatialMap__dtor(ptr); }));
}
_INLINE_SPECIFIER_ void SparseSpatialMap::setResultPoseType(bool enableStabilization)
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_SparseSpatialMap_setResultPoseType(this->cdata_.get(), enableStabilization);
}
_INLINE_SPECIFIER_ bool SparseSpatialMap::setResultAsyncMode(bool enableAsync)
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_SparseSpatialMap_setResultAsyncMode(this->cdata_.get(), enableAsync);
    return _return_value_;
}
_INLINE_SPECIFIER_ bool SparseSpatialMap::start()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_SparseSpatialMap_start(this->cdata_.get());
    return _return_value_;
}
_INLINE_SPECIFIER_ void SparseSpatialMap::stop()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_SparseSpatialMap_stop(this->cdata_.get());
}
_INLINE_SPECIFIER_ void SparseSpatialMap::close()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_SparseSpatialMap_close(this->cdata_.get());
}
_INLINE_SPECIFIER_ std::shared_ptr<Buffer> SparseSpatialMap::getPointCloudBuffer()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_Buffer * _return_value_;
    easyar_SparseSpatialMap_getPointCloudBuffer(this->cdata_.get(), &_return_value_);
    if (!(_return_value_ != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    return Buffer::from_cdata(std::shared_ptr<easyar_Buffer>(_return_value_, [](easyar_Buffer * ptr) { easyar_Buffer__dtor(ptr); }));
}
_INLINE_SPECIFIER_ std::vector<std::shared_ptr<PlaneData>> SparseSpatialMap::getMapPlanes()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_ListOfPlaneData * _return_value_;
    easyar_SparseSpatialMap_getMapPlanes(this->cdata_.get(), &_return_value_);
    if (!(_return_value_ != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    return std_vector_from_easyar_ListOfPlaneData(std::shared_ptr<easyar_ListOfPlaneData>(_return_value_, [](easyar_ListOfPlaneData * ptr) { easyar_ListOfPlaneData__dtor(ptr); }));
}
_INLINE_SPECIFIER_ std::vector<Vec3F> SparseSpatialMap::hitTestAgainstPointCloud(Vec2F cameraImagePoint)
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_ListOfVec3F * _return_value_;
    easyar_SparseSpatialMap_hitTestAgainstPointCloud(this->cdata_.get(), easyar_Vec2F{{cameraImagePoint.data[0], cameraImagePoint.data[1]}}, &_return_value_);
    if (!(_return_value_ != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    return std_vector_from_easyar_ListOfVec3F(std::shared_ptr<easyar_ListOfVec3F>(_return_value_, [](easyar_ListOfVec3F * ptr) { easyar_ListOfVec3F__dtor(ptr); }));
}
_INLINE_SPECIFIER_ std::vector<Vec3F> SparseSpatialMap::hitTestAgainstPlanes(Vec2F cameraImagePoint)
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_ListOfVec3F * _return_value_;
    easyar_SparseSpatialMap_hitTestAgainstPlanes(this->cdata_.get(), easyar_Vec2F{{cameraImagePoint.data[0], cameraImagePoint.data[1]}}, &_return_value_);
    if (!(_return_value_ != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    return std_vector_from_easyar_ListOfVec3F(std::shared_ptr<easyar_ListOfVec3F>(_return_value_, [](easyar_ListOfVec3F * ptr) { easyar_ListOfVec3F__dtor(ptr); }));
}
_INLINE_SPECIFIER_ std::string SparseSpatialMap::getMapVersion()
{
    easyar_String * _return_value_;
    easyar_SparseSpatialMap_getMapVersion(&_return_value_);
    if (!(_return_value_ != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    return std_string_from_easyar_String(std::shared_ptr<easyar_String>(_return_value_, [](easyar_String * ptr) { easyar_String__dtor(ptr); }));
}
_INLINE_SPECIFIER_ void SparseSpatialMap::unloadMap(std::string mapID, std::shared_ptr<CallbackScheduler> callbackScheduler, std::optional<std::function<void(bool)>> resultCallBack)
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    if (!(callbackScheduler != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: callbackScheduler");
#else
        std::terminate();
#endif
    }
    if (!(!resultCallBack.has_value() || (resultCallBack.value() != nullptr))) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: resultCallBack");
#else
        std::terminate();
#endif
    }
    easyar_SparseSpatialMap_unloadMap(this->cdata_.get(), std_string_to_easyar_String(mapID).get(), callbackScheduler->get_cdata().get(), (resultCallBack.has_value() ? easyar_OptionalOfFunctorOfVoidFromBool{true, FunctorOfVoidFromBool_to_c(resultCallBack.value())} : easyar_OptionalOfFunctorOfVoidFromBool{false, {}}));
}
_INLINE_SPECIFIER_ void SparseSpatialMap::setConfig(std::shared_ptr<SparseSpatialMapConfig> config)
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    if (!(config != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: config");
#else
        std::terminate();
#endif
    }
    easyar_SparseSpatialMap_setConfig(this->cdata_.get(), config->get_cdata().get());
}
_INLINE_SPECIFIER_ std::shared_ptr<SparseSpatialMapConfig> SparseSpatialMap::getConfig()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_SparseSpatialMapConfig * _return_value_;
    easyar_SparseSpatialMap_getConfig(this->cdata_.get(), &_return_value_);
    if (!(_return_value_ != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    return SparseSpatialMapConfig::from_cdata(std::shared_ptr<easyar_SparseSpatialMapConfig>(_return_value_, [](easyar_SparseSpatialMapConfig * ptr) { easyar_SparseSpatialMapConfig__dtor(ptr); }));
}
_INLINE_SPECIFIER_ bool SparseSpatialMap::startLocalization()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_SparseSpatialMap_startLocalization(this->cdata_.get());
    return _return_value_;
}
_INLINE_SPECIFIER_ void SparseSpatialMap::stopLocalization()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_SparseSpatialMap_stopLocalization(this->cdata_.get());
}
_INLINE_SPECIFIER_ std::optional<std::shared_ptr<SparseSpatialMapResult>> SparseSpatialMap::getSyncResult(std::shared_ptr<MotionInputData> motionInputData)
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    if (!(motionInputData != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: motionInputData");
#else
        std::terminate();
#endif
    }
    easyar_OptionalOfSparseSpatialMapResult _return_value_;
    easyar_SparseSpatialMap_getSyncResult(this->cdata_.get(), motionInputData->get_cdata().get(), &_return_value_);
    if (!(!_return_value_.has_value || (_return_value_.value != nullptr))) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    return (_return_value_.has_value ? SparseSpatialMapResult::from_cdata(std::shared_ptr<easyar_SparseSpatialMapResult>(_return_value_.value, [](easyar_SparseSpatialMapResult * ptr) { easyar_SparseSpatialMapResult__dtor(ptr); })) : std::optional<std::shared_ptr<SparseSpatialMapResult>>{});
}

_INLINE_SPECIFIER_ SparseSpatialMapManager::SparseSpatialMapManager(std::shared_ptr<easyar_SparseSpatialMapManager> cdata)
    :
    cdata_(nullptr)
{
    init_cdata(cdata);
}
_INLINE_SPECIFIER_ SparseSpatialMapManager::~SparseSpatialMapManager()
{
    cdata_ = nullptr;
}

_INLINE_SPECIFIER_ std::shared_ptr<easyar_SparseSpatialMapManager> SparseSpatialMapManager::get_cdata()
{
    return cdata_;
}
_INLINE_SPECIFIER_ void SparseSpatialMapManager::init_cdata(std::shared_ptr<easyar_SparseSpatialMapManager> cdata)
{
    cdata_ = cdata;
}
_INLINE_SPECIFIER_ std::shared_ptr<SparseSpatialMapManager> SparseSpatialMapManager::from_cdata(std::shared_ptr<easyar_SparseSpatialMapManager> cdata)
{
    if (cdata == nullptr) {
        return nullptr;
    }
    return std::make_shared<SparseSpatialMapManager>(cdata);
}
_INLINE_SPECIFIER_ bool SparseSpatialMapManager::isAvailable()
{
    auto _return_value_ = easyar_SparseSpatialMapManager_isAvailable();
    return _return_value_;
}
_INLINE_SPECIFIER_ std::shared_ptr<SparseSpatialMapManager> SparseSpatialMapManager::create()
{
    easyar_SparseSpatialMapManager * _return_value_;
    easyar_SparseSpatialMapManager_create(&_return_value_);
    if (!(_return_value_ != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    return SparseSpatialMapManager::from_cdata(std::shared_ptr<easyar_SparseSpatialMapManager>(_return_value_, [](easyar_SparseSpatialMapManager * ptr) { easyar_SparseSpatialMapManager__dtor(ptr); }));
}
_INLINE_SPECIFIER_ void SparseSpatialMapManager::host(std::shared_ptr<SparseSpatialMap> mapBuilder, std::string apiKey, std::string apiSecret, std::string sparseSpatialMapAppId, std::string name, std::optional<std::shared_ptr<Image>> preview, std::optional<int> timeoutMilliseconds, std::shared_ptr<CallbackScheduler> callbackScheduler, std::function<void(bool, std::string, std::string)> onCompleted)
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    if (!(mapBuilder != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: mapBuilder");
#else
        std::terminate();
#endif
    }
    if (!(!preview.has_value() || (preview.value() != nullptr))) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: preview");
#else
        std::terminate();
#endif
    }
    if (!(callbackScheduler != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: callbackScheduler");
#else
        std::terminate();
#endif
    }
    if (!(onCompleted != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: onCompleted");
#else
        std::terminate();
#endif
    }
    easyar_SparseSpatialMapManager_host(this->cdata_.get(), mapBuilder->get_cdata().get(), std_string_to_easyar_String(apiKey).get(), std_string_to_easyar_String(apiSecret).get(), std_string_to_easyar_String(sparseSpatialMapAppId).get(), std_string_to_easyar_String(name).get(), (preview.has_value() ? easyar_OptionalOfImage{true, preview.value()->get_cdata().get()} : easyar_OptionalOfImage{false, {}}), (timeoutMilliseconds.has_value() ? easyar_OptionalOfInt{true, timeoutMilliseconds.value()} : easyar_OptionalOfInt{false, {}}), callbackScheduler->get_cdata().get(), FunctorOfVoidFromBoolAndStringAndString_to_c(onCompleted));
}
_INLINE_SPECIFIER_ void SparseSpatialMapManager::load(std::shared_ptr<SparseSpatialMap> mapTracker, std::string serverMapId, std::string apiKey, std::string apiSecret, std::string sparseSpatialMapAppId, std::optional<int> timeoutMilliseconds, std::shared_ptr<CallbackScheduler> callbackScheduler, std::function<void(bool, std::string)> onCompleted)
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    if (!(mapTracker != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: mapTracker");
#else
        std::terminate();
#endif
    }
    if (!(callbackScheduler != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: callbackScheduler");
#else
        std::terminate();
#endif
    }
    if (!(onCompleted != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: onCompleted");
#else
        std::terminate();
#endif
    }
    easyar_SparseSpatialMapManager_load(this->cdata_.get(), mapTracker->get_cdata().get(), std_string_to_easyar_String(serverMapId).get(), std_string_to_easyar_String(apiKey).get(), std_string_to_easyar_String(apiSecret).get(), std_string_to_easyar_String(sparseSpatialMapAppId).get(), (timeoutMilliseconds.has_value() ? easyar_OptionalOfInt{true, timeoutMilliseconds.value()} : easyar_OptionalOfInt{false, {}}), callbackScheduler->get_cdata().get(), FunctorOfVoidFromBoolAndString_to_c(onCompleted));
}
_INLINE_SPECIFIER_ void SparseSpatialMapManager::clear()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_SparseSpatialMapManager_clear(this->cdata_.get());
}

_INLINE_SPECIFIER_ int Engine::schemaHash()
{
    auto _return_value_ = easyar_Engine_schemaHash();
    return _return_value_;
}
_INLINE_SPECIFIER_ bool Engine::initialize(std::string licenseKey)
{
    if (easyar_Engine_schemaHash() != -1782020803) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("SchemaHashNotMatched");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_Engine_initialize(std_string_to_easyar_String(licenseKey).get());
    return _return_value_;
}
_INLINE_SPECIFIER_ void Engine::onPause()
{
    easyar_Engine_onPause();
}
_INLINE_SPECIFIER_ void Engine::onResume()
{
    easyar_Engine_onResume();
}
_INLINE_SPECIFIER_ ValidationState Engine::validationState()
{
    auto _return_value_ = easyar_Engine_validationState();
    return static_cast<ValidationState>(_return_value_);
}
_INLINE_SPECIFIER_ std::string Engine::errorMessage()
{
    easyar_String * _return_value_;
    easyar_Engine_errorMessage(&_return_value_);
    if (!(_return_value_ != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    return std_string_from_easyar_String(std::shared_ptr<easyar_String>(_return_value_, [](easyar_String * ptr) { easyar_String__dtor(ptr); }));
}
_INLINE_SPECIFIER_ std::string Engine::versionString()
{
    easyar_String * _return_value_;
    easyar_Engine_versionString(&_return_value_);
    if (!(_return_value_ != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    return std_string_from_easyar_String(std::shared_ptr<easyar_String>(_return_value_, [](easyar_String * ptr) { easyar_String__dtor(ptr); }));
}
_INLINE_SPECIFIER_ std::string Engine::name()
{
    easyar_String * _return_value_;
    easyar_Engine_name(&_return_value_);
    if (!(_return_value_ != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    return std_string_from_easyar_String(std::shared_ptr<easyar_String>(_return_value_, [](easyar_String * ptr) { easyar_String__dtor(ptr); }));
}
_INLINE_SPECIFIER_ std::string Engine::variant()
{
    easyar_String * _return_value_;
    easyar_Engine_variant(&_return_value_);
    if (!(_return_value_ != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    return std_string_from_easyar_String(std::shared_ptr<easyar_String>(_return_value_, [](easyar_String * ptr) { easyar_String__dtor(ptr); }));
}
_INLINE_SPECIFIER_ bool Engine::isLicenseKeyMatched(std::string licenseKey, std::string packageName, std::string variant, EngineOperatingSystem operatingSystem)
{
    auto _return_value_ = easyar_Engine_isLicenseKeyMatched(std_string_to_easyar_String(licenseKey).get(), std_string_to_easyar_String(packageName).get(), std_string_to_easyar_String(variant).get(), static_cast<easyar_EngineOperatingSystem>(operatingSystem));
    return _return_value_;
}
_INLINE_SPECIFIER_ void Engine::enableEyewearSupport()
{
    easyar_Engine_enableEyewearSupport();
}

_INLINE_SPECIFIER_ VideoPlayer::VideoPlayer(std::shared_ptr<easyar_VideoPlayer> cdata)
    :
    cdata_(nullptr)
{
    init_cdata(cdata);
}
_INLINE_SPECIFIER_ VideoPlayer::~VideoPlayer()
{
    cdata_ = nullptr;
}

_INLINE_SPECIFIER_ std::shared_ptr<easyar_VideoPlayer> VideoPlayer::get_cdata()
{
    return cdata_;
}
_INLINE_SPECIFIER_ void VideoPlayer::init_cdata(std::shared_ptr<easyar_VideoPlayer> cdata)
{
    cdata_ = cdata;
}
_INLINE_SPECIFIER_ std::shared_ptr<VideoPlayer> VideoPlayer::from_cdata(std::shared_ptr<easyar_VideoPlayer> cdata)
{
    if (cdata == nullptr) {
        return nullptr;
    }
    return std::make_shared<VideoPlayer>(cdata);
}
_INLINE_SPECIFIER_ VideoPlayer::VideoPlayer()
    :
    cdata_(nullptr)
{
    easyar_VideoPlayer * _return_value_;
    easyar_VideoPlayer__ctor(&_return_value_);
    if (!(_return_value_ != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    init_cdata(std::shared_ptr<easyar_VideoPlayer>(_return_value_, [](easyar_VideoPlayer * ptr) { easyar_VideoPlayer__dtor(ptr); }));
}
_INLINE_SPECIFIER_ bool VideoPlayer::isAvailable()
{
    auto _return_value_ = easyar_VideoPlayer_isAvailable();
    return _return_value_;
}
_INLINE_SPECIFIER_ void VideoPlayer::setVideoType(VideoType videoType)
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_VideoPlayer_setVideoType(this->cdata_.get(), static_cast<easyar_VideoType>(videoType));
}
_INLINE_SPECIFIER_ void VideoPlayer::setRenderTexture(std::shared_ptr<TextureId> texture)
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    if (!(texture != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: texture");
#else
        std::terminate();
#endif
    }
    easyar_VideoPlayer_setRenderTexture(this->cdata_.get(), texture->get_cdata().get());
}
_INLINE_SPECIFIER_ void VideoPlayer::open(std::string path, StorageType storageType, std::shared_ptr<CallbackScheduler> callbackScheduler, std::optional<std::function<void(VideoStatus)>> callback)
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    if (!(callbackScheduler != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: callbackScheduler");
#else
        std::terminate();
#endif
    }
    if (!(!callback.has_value() || (callback.value() != nullptr))) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: callback");
#else
        std::terminate();
#endif
    }
    easyar_VideoPlayer_open(this->cdata_.get(), std_string_to_easyar_String(path).get(), static_cast<easyar_StorageType>(storageType), callbackScheduler->get_cdata().get(), (callback.has_value() ? easyar_OptionalOfFunctorOfVoidFromVideoStatus{true, FunctorOfVoidFromVideoStatus_to_c(callback.value())} : easyar_OptionalOfFunctorOfVoidFromVideoStatus{false, {}}));
}
_INLINE_SPECIFIER_ void VideoPlayer::close()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_VideoPlayer_close(this->cdata_.get());
}
_INLINE_SPECIFIER_ bool VideoPlayer::play()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_VideoPlayer_play(this->cdata_.get());
    return _return_value_;
}
_INLINE_SPECIFIER_ void VideoPlayer::stop()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_VideoPlayer_stop(this->cdata_.get());
}
_INLINE_SPECIFIER_ void VideoPlayer::pause()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_VideoPlayer_pause(this->cdata_.get());
}
_INLINE_SPECIFIER_ bool VideoPlayer::isRenderTextureAvailable()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_VideoPlayer_isRenderTextureAvailable(this->cdata_.get());
    return _return_value_;
}
_INLINE_SPECIFIER_ void VideoPlayer::updateFrame()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_VideoPlayer_updateFrame(this->cdata_.get());
}
_INLINE_SPECIFIER_ int VideoPlayer::duration()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_VideoPlayer_duration(this->cdata_.get());
    return _return_value_;
}
_INLINE_SPECIFIER_ int VideoPlayer::currentPosition()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_VideoPlayer_currentPosition(this->cdata_.get());
    return _return_value_;
}
_INLINE_SPECIFIER_ bool VideoPlayer::seek(int position)
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_VideoPlayer_seek(this->cdata_.get(), position);
    return _return_value_;
}
_INLINE_SPECIFIER_ Vec2I VideoPlayer::size()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_VideoPlayer_size(this->cdata_.get());
    return Vec2I{{{_return_value_.data[0], _return_value_.data[1]}}};
}
_INLINE_SPECIFIER_ float VideoPlayer::volume()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_VideoPlayer_volume(this->cdata_.get());
    return _return_value_;
}
_INLINE_SPECIFIER_ bool VideoPlayer::setVolume(float volume)
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_VideoPlayer_setVolume(this->cdata_.get(), volume);
    return _return_value_;
}

_INLINE_SPECIFIER_ CameraParameters::CameraParameters(std::shared_ptr<easyar_CameraParameters> cdata)
    :
    cdata_(nullptr)
{
    init_cdata(cdata);
}
_INLINE_SPECIFIER_ CameraParameters::~CameraParameters()
{
    cdata_ = nullptr;
}

_INLINE_SPECIFIER_ std::shared_ptr<easyar_CameraParameters> CameraParameters::get_cdata()
{
    return cdata_;
}
_INLINE_SPECIFIER_ void CameraParameters::init_cdata(std::shared_ptr<easyar_CameraParameters> cdata)
{
    cdata_ = cdata;
}
_INLINE_SPECIFIER_ std::shared_ptr<CameraParameters> CameraParameters::from_cdata(std::shared_ptr<easyar_CameraParameters> cdata)
{
    if (cdata == nullptr) {
        return nullptr;
    }
    return std::make_shared<CameraParameters>(cdata);
}
_INLINE_SPECIFIER_ CameraParameters::CameraParameters(Vec2I imageSize, Vec2F focalLength, Vec2F principalPoint, CameraDeviceType cameraDeviceType, int cameraOrientation)
    :
    cdata_(nullptr)
{
    easyar_CameraParameters * _return_value_;
    easyar_CameraParameters__ctor(easyar_Vec2I{{imageSize.data[0], imageSize.data[1]}}, easyar_Vec2F{{focalLength.data[0], focalLength.data[1]}}, easyar_Vec2F{{principalPoint.data[0], principalPoint.data[1]}}, static_cast<easyar_CameraDeviceType>(cameraDeviceType), cameraOrientation, &_return_value_);
    if (!(_return_value_ != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    init_cdata(std::shared_ptr<easyar_CameraParameters>(_return_value_, [](easyar_CameraParameters * ptr) { easyar_CameraParameters__dtor(ptr); }));
}
_INLINE_SPECIFIER_ Vec2I CameraParameters::size()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_CameraParameters_size(this->cdata_.get());
    return Vec2I{{{_return_value_.data[0], _return_value_.data[1]}}};
}
_INLINE_SPECIFIER_ Vec2F CameraParameters::focalLength()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_CameraParameters_focalLength(this->cdata_.get());
    return Vec2F{{{_return_value_.data[0], _return_value_.data[1]}}};
}
_INLINE_SPECIFIER_ Vec2F CameraParameters::principalPoint()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_CameraParameters_principalPoint(this->cdata_.get());
    return Vec2F{{{_return_value_.data[0], _return_value_.data[1]}}};
}
_INLINE_SPECIFIER_ CameraModelType CameraParameters::cameraModelType()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_CameraParameters_cameraModelType(this->cdata_.get());
    return static_cast<CameraModelType>(_return_value_);
}
_INLINE_SPECIFIER_ CameraDeviceType CameraParameters::cameraDeviceType()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_CameraParameters_cameraDeviceType(this->cdata_.get());
    return static_cast<CameraDeviceType>(_return_value_);
}
_INLINE_SPECIFIER_ int CameraParameters::cameraOrientation()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_CameraParameters_cameraOrientation(this->cdata_.get());
    return _return_value_;
}
_INLINE_SPECIFIER_ std::shared_ptr<CameraParameters> CameraParameters::createWithDefaultIntrinsics(Vec2I imageSize, CameraDeviceType cameraDeviceType, int cameraOrientation)
{
    easyar_CameraParameters * _return_value_;
    easyar_CameraParameters_createWithDefaultIntrinsics(easyar_Vec2I{{imageSize.data[0], imageSize.data[1]}}, static_cast<easyar_CameraDeviceType>(cameraDeviceType), cameraOrientation, &_return_value_);
    if (!(_return_value_ != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    return CameraParameters::from_cdata(std::shared_ptr<easyar_CameraParameters>(_return_value_, [](easyar_CameraParameters * ptr) { easyar_CameraParameters__dtor(ptr); }));
}
_INLINE_SPECIFIER_ std::optional<std::shared_ptr<CameraParameters>> CameraParameters::tryCreateWithCustomIntrinsics(Vec2I imageSize, std::vector<float> cameraParamList, CameraModelType cameraModel, CameraDeviceType cameraDeviceType, int cameraOrientation)
{
    if (!easyar_ListOfFloat_check_external_cpp(cameraParamList)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: cameraParamList");
#else
        std::terminate();
#endif
    }
    easyar_OptionalOfCameraParameters _return_value_;
    easyar_CameraParameters_tryCreateWithCustomIntrinsics(easyar_Vec2I{{imageSize.data[0], imageSize.data[1]}}, std_vector_to_easyar_ListOfFloat(cameraParamList).get(), static_cast<easyar_CameraModelType>(cameraModel), static_cast<easyar_CameraDeviceType>(cameraDeviceType), cameraOrientation, &_return_value_);
    if (!(!_return_value_.has_value || (_return_value_.value != nullptr))) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    return (_return_value_.has_value ? CameraParameters::from_cdata(std::shared_ptr<easyar_CameraParameters>(_return_value_.value, [](easyar_CameraParameters * ptr) { easyar_CameraParameters__dtor(ptr); })) : std::optional<std::shared_ptr<CameraParameters>>{});
}
_INLINE_SPECIFIER_ std::shared_ptr<CameraParameters> CameraParameters::getResized(Vec2I imageSize)
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_CameraParameters * _return_value_;
    easyar_CameraParameters_getResized(this->cdata_.get(), easyar_Vec2I{{imageSize.data[0], imageSize.data[1]}}, &_return_value_);
    if (!(_return_value_ != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    return CameraParameters::from_cdata(std::shared_ptr<easyar_CameraParameters>(_return_value_, [](easyar_CameraParameters * ptr) { easyar_CameraParameters__dtor(ptr); }));
}
_INLINE_SPECIFIER_ int CameraParameters::imageOrientation(int screenRotation)
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_CameraParameters_imageOrientation(this->cdata_.get(), screenRotation);
    return _return_value_;
}
_INLINE_SPECIFIER_ bool CameraParameters::imageHorizontalFlip(bool manualHorizontalFlip)
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_CameraParameters_imageHorizontalFlip(this->cdata_.get(), manualHorizontalFlip);
    return _return_value_;
}
_INLINE_SPECIFIER_ Matrix44F CameraParameters::projection(float nearPlane, float farPlane, float viewportAspectRatio, int screenRotation, bool combiningFlip, bool manualHorizontalFlip)
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_CameraParameters_projection(this->cdata_.get(), nearPlane, farPlane, viewportAspectRatio, screenRotation, combiningFlip, manualHorizontalFlip);
    return Matrix44F{{{_return_value_.data[0], _return_value_.data[1], _return_value_.data[2], _return_value_.data[3], _return_value_.data[4], _return_value_.data[5], _return_value_.data[6], _return_value_.data[7], _return_value_.data[8], _return_value_.data[9], _return_value_.data[10], _return_value_.data[11], _return_value_.data[12], _return_value_.data[13], _return_value_.data[14], _return_value_.data[15]}}};
}
_INLINE_SPECIFIER_ Matrix44F CameraParameters::imageProjection(float viewportAspectRatio, int screenRotation, bool combiningFlip, bool manualHorizontalFlip)
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_CameraParameters_imageProjection(this->cdata_.get(), viewportAspectRatio, screenRotation, combiningFlip, manualHorizontalFlip);
    return Matrix44F{{{_return_value_.data[0], _return_value_.data[1], _return_value_.data[2], _return_value_.data[3], _return_value_.data[4], _return_value_.data[5], _return_value_.data[6], _return_value_.data[7], _return_value_.data[8], _return_value_.data[9], _return_value_.data[10], _return_value_.data[11], _return_value_.data[12], _return_value_.data[13], _return_value_.data[14], _return_value_.data[15]}}};
}
_INLINE_SPECIFIER_ Vec2F CameraParameters::screenCoordinatesFromImageCoordinates(float viewportAspectRatio, int screenRotation, bool combiningFlip, bool manualHorizontalFlip, Vec2F imageCoordinates)
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_CameraParameters_screenCoordinatesFromImageCoordinates(this->cdata_.get(), viewportAspectRatio, screenRotation, combiningFlip, manualHorizontalFlip, easyar_Vec2F{{imageCoordinates.data[0], imageCoordinates.data[1]}});
    return Vec2F{{{_return_value_.data[0], _return_value_.data[1]}}};
}
_INLINE_SPECIFIER_ Vec2F CameraParameters::imageCoordinatesFromScreenCoordinates(float viewportAspectRatio, int screenRotation, bool combiningFlip, bool manualHorizontalFlip, Vec2F screenCoordinates)
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_CameraParameters_imageCoordinatesFromScreenCoordinates(this->cdata_.get(), viewportAspectRatio, screenRotation, combiningFlip, manualHorizontalFlip, easyar_Vec2F{{screenCoordinates.data[0], screenCoordinates.data[1]}});
    return Vec2F{{{_return_value_.data[0], _return_value_.data[1]}}};
}
_INLINE_SPECIFIER_ bool CameraParameters::equalsTo(std::shared_ptr<CameraParameters> other)
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    if (!(other != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: other");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_CameraParameters_equalsTo(this->cdata_.get(), other->get_cdata().get());
    return _return_value_;
}

_INLINE_SPECIFIER_ SignalSink::SignalSink(std::shared_ptr<easyar_SignalSink> cdata)
    :
    cdata_(nullptr)
{
    init_cdata(cdata);
}
_INLINE_SPECIFIER_ SignalSink::~SignalSink()
{
    cdata_ = nullptr;
}

_INLINE_SPECIFIER_ std::shared_ptr<easyar_SignalSink> SignalSink::get_cdata()
{
    return cdata_;
}
_INLINE_SPECIFIER_ void SignalSink::init_cdata(std::shared_ptr<easyar_SignalSink> cdata)
{
    cdata_ = cdata;
}
_INLINE_SPECIFIER_ std::shared_ptr<SignalSink> SignalSink::from_cdata(std::shared_ptr<easyar_SignalSink> cdata)
{
    if (cdata == nullptr) {
        return nullptr;
    }
    return std::make_shared<SignalSink>(cdata);
}
_INLINE_SPECIFIER_ void SignalSink::handle()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_SignalSink_handle(this->cdata_.get());
}

_INLINE_SPECIFIER_ SignalSource::SignalSource(std::shared_ptr<easyar_SignalSource> cdata)
    :
    cdata_(nullptr)
{
    init_cdata(cdata);
}
_INLINE_SPECIFIER_ SignalSource::~SignalSource()
{
    cdata_ = nullptr;
}

_INLINE_SPECIFIER_ std::shared_ptr<easyar_SignalSource> SignalSource::get_cdata()
{
    return cdata_;
}
_INLINE_SPECIFIER_ void SignalSource::init_cdata(std::shared_ptr<easyar_SignalSource> cdata)
{
    cdata_ = cdata;
}
_INLINE_SPECIFIER_ std::shared_ptr<SignalSource> SignalSource::from_cdata(std::shared_ptr<easyar_SignalSource> cdata)
{
    if (cdata == nullptr) {
        return nullptr;
    }
    return std::make_shared<SignalSource>(cdata);
}
_INLINE_SPECIFIER_ void SignalSource::setHandler(std::optional<std::function<void()>> handler)
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    if (!(!handler.has_value() || (handler.value() != nullptr))) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: handler");
#else
        std::terminate();
#endif
    }
    easyar_SignalSource_setHandler(this->cdata_.get(), (handler.has_value() ? easyar_OptionalOfFunctorOfVoid{true, FunctorOfVoid_to_c(handler.value())} : easyar_OptionalOfFunctorOfVoid{false, {}}));
}
_INLINE_SPECIFIER_ void SignalSource::connect(std::shared_ptr<SignalSink> sink)
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    if (!(sink != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: sink");
#else
        std::terminate();
#endif
    }
    easyar_SignalSource_connect(this->cdata_.get(), sink->get_cdata().get());
}
_INLINE_SPECIFIER_ void SignalSource::disconnect()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_SignalSource_disconnect(this->cdata_.get());
}

_INLINE_SPECIFIER_ AccelerometerResultSink::AccelerometerResultSink(std::shared_ptr<easyar_AccelerometerResultSink> cdata)
    :
    cdata_(nullptr)
{
    init_cdata(cdata);
}
_INLINE_SPECIFIER_ AccelerometerResultSink::~AccelerometerResultSink()
{
    cdata_ = nullptr;
}

_INLINE_SPECIFIER_ std::shared_ptr<easyar_AccelerometerResultSink> AccelerometerResultSink::get_cdata()
{
    return cdata_;
}
_INLINE_SPECIFIER_ void AccelerometerResultSink::init_cdata(std::shared_ptr<easyar_AccelerometerResultSink> cdata)
{
    cdata_ = cdata;
}
_INLINE_SPECIFIER_ std::shared_ptr<AccelerometerResultSink> AccelerometerResultSink::from_cdata(std::shared_ptr<easyar_AccelerometerResultSink> cdata)
{
    if (cdata == nullptr) {
        return nullptr;
    }
    return std::make_shared<AccelerometerResultSink>(cdata);
}
_INLINE_SPECIFIER_ void AccelerometerResultSink::handle(AccelerometerResult inputData)
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_AccelerometerResultSink_handle(this->cdata_.get(), easyar_AccelerometerResult{inputData.x, inputData.y, inputData.z, inputData.timestamp});
}

_INLINE_SPECIFIER_ AccelerometerResultSource::AccelerometerResultSource(std::shared_ptr<easyar_AccelerometerResultSource> cdata)
    :
    cdata_(nullptr)
{
    init_cdata(cdata);
}
_INLINE_SPECIFIER_ AccelerometerResultSource::~AccelerometerResultSource()
{
    cdata_ = nullptr;
}

_INLINE_SPECIFIER_ std::shared_ptr<easyar_AccelerometerResultSource> AccelerometerResultSource::get_cdata()
{
    return cdata_;
}
_INLINE_SPECIFIER_ void AccelerometerResultSource::init_cdata(std::shared_ptr<easyar_AccelerometerResultSource> cdata)
{
    cdata_ = cdata;
}
_INLINE_SPECIFIER_ std::shared_ptr<AccelerometerResultSource> AccelerometerResultSource::from_cdata(std::shared_ptr<easyar_AccelerometerResultSource> cdata)
{
    if (cdata == nullptr) {
        return nullptr;
    }
    return std::make_shared<AccelerometerResultSource>(cdata);
}
_INLINE_SPECIFIER_ void AccelerometerResultSource::setHandler(std::optional<std::function<void(AccelerometerResult)>> handler)
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    if (!(!handler.has_value() || (handler.value() != nullptr))) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: handler");
#else
        std::terminate();
#endif
    }
    easyar_AccelerometerResultSource_setHandler(this->cdata_.get(), (handler.has_value() ? easyar_OptionalOfFunctorOfVoidFromAccelerometerResult{true, FunctorOfVoidFromAccelerometerResult_to_c(handler.value())} : easyar_OptionalOfFunctorOfVoidFromAccelerometerResult{false, {}}));
}
_INLINE_SPECIFIER_ void AccelerometerResultSource::connect(std::shared_ptr<AccelerometerResultSink> sink)
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    if (!(sink != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: sink");
#else
        std::terminate();
#endif
    }
    easyar_AccelerometerResultSource_connect(this->cdata_.get(), sink->get_cdata().get());
}
_INLINE_SPECIFIER_ void AccelerometerResultSource::disconnect()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_AccelerometerResultSource_disconnect(this->cdata_.get());
}

_INLINE_SPECIFIER_ GyroscopeResultSink::GyroscopeResultSink(std::shared_ptr<easyar_GyroscopeResultSink> cdata)
    :
    cdata_(nullptr)
{
    init_cdata(cdata);
}
_INLINE_SPECIFIER_ GyroscopeResultSink::~GyroscopeResultSink()
{
    cdata_ = nullptr;
}

_INLINE_SPECIFIER_ std::shared_ptr<easyar_GyroscopeResultSink> GyroscopeResultSink::get_cdata()
{
    return cdata_;
}
_INLINE_SPECIFIER_ void GyroscopeResultSink::init_cdata(std::shared_ptr<easyar_GyroscopeResultSink> cdata)
{
    cdata_ = cdata;
}
_INLINE_SPECIFIER_ std::shared_ptr<GyroscopeResultSink> GyroscopeResultSink::from_cdata(std::shared_ptr<easyar_GyroscopeResultSink> cdata)
{
    if (cdata == nullptr) {
        return nullptr;
    }
    return std::make_shared<GyroscopeResultSink>(cdata);
}
_INLINE_SPECIFIER_ void GyroscopeResultSink::handle(GyroscopeResult inputData)
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_GyroscopeResultSink_handle(this->cdata_.get(), easyar_GyroscopeResult{inputData.x, inputData.y, inputData.z, inputData.timestamp});
}

_INLINE_SPECIFIER_ GyroscopeResultSource::GyroscopeResultSource(std::shared_ptr<easyar_GyroscopeResultSource> cdata)
    :
    cdata_(nullptr)
{
    init_cdata(cdata);
}
_INLINE_SPECIFIER_ GyroscopeResultSource::~GyroscopeResultSource()
{
    cdata_ = nullptr;
}

_INLINE_SPECIFIER_ std::shared_ptr<easyar_GyroscopeResultSource> GyroscopeResultSource::get_cdata()
{
    return cdata_;
}
_INLINE_SPECIFIER_ void GyroscopeResultSource::init_cdata(std::shared_ptr<easyar_GyroscopeResultSource> cdata)
{
    cdata_ = cdata;
}
_INLINE_SPECIFIER_ std::shared_ptr<GyroscopeResultSource> GyroscopeResultSource::from_cdata(std::shared_ptr<easyar_GyroscopeResultSource> cdata)
{
    if (cdata == nullptr) {
        return nullptr;
    }
    return std::make_shared<GyroscopeResultSource>(cdata);
}
_INLINE_SPECIFIER_ void GyroscopeResultSource::setHandler(std::optional<std::function<void(GyroscopeResult)>> handler)
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    if (!(!handler.has_value() || (handler.value() != nullptr))) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: handler");
#else
        std::terminate();
#endif
    }
    easyar_GyroscopeResultSource_setHandler(this->cdata_.get(), (handler.has_value() ? easyar_OptionalOfFunctorOfVoidFromGyroscopeResult{true, FunctorOfVoidFromGyroscopeResult_to_c(handler.value())} : easyar_OptionalOfFunctorOfVoidFromGyroscopeResult{false, {}}));
}
_INLINE_SPECIFIER_ void GyroscopeResultSource::connect(std::shared_ptr<GyroscopeResultSink> sink)
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    if (!(sink != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: sink");
#else
        std::terminate();
#endif
    }
    easyar_GyroscopeResultSource_connect(this->cdata_.get(), sink->get_cdata().get());
}
_INLINE_SPECIFIER_ void GyroscopeResultSource::disconnect()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_GyroscopeResultSource_disconnect(this->cdata_.get());
}

_INLINE_SPECIFIER_ AttitudeSensorResultSink::AttitudeSensorResultSink(std::shared_ptr<easyar_AttitudeSensorResultSink> cdata)
    :
    cdata_(nullptr)
{
    init_cdata(cdata);
}
_INLINE_SPECIFIER_ AttitudeSensorResultSink::~AttitudeSensorResultSink()
{
    cdata_ = nullptr;
}

_INLINE_SPECIFIER_ std::shared_ptr<easyar_AttitudeSensorResultSink> AttitudeSensorResultSink::get_cdata()
{
    return cdata_;
}
_INLINE_SPECIFIER_ void AttitudeSensorResultSink::init_cdata(std::shared_ptr<easyar_AttitudeSensorResultSink> cdata)
{
    cdata_ = cdata;
}
_INLINE_SPECIFIER_ std::shared_ptr<AttitudeSensorResultSink> AttitudeSensorResultSink::from_cdata(std::shared_ptr<easyar_AttitudeSensorResultSink> cdata)
{
    if (cdata == nullptr) {
        return nullptr;
    }
    return std::make_shared<AttitudeSensorResultSink>(cdata);
}
_INLINE_SPECIFIER_ void AttitudeSensorResultSink::handle(AttitudeSensorResult inputData)
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_AttitudeSensorResultSink_handle(this->cdata_.get(), easyar_AttitudeSensorResult{inputData.v0, inputData.v1, inputData.v2, inputData.v3, inputData.timestamp});
}

_INLINE_SPECIFIER_ AttitudeSensorResultSource::AttitudeSensorResultSource(std::shared_ptr<easyar_AttitudeSensorResultSource> cdata)
    :
    cdata_(nullptr)
{
    init_cdata(cdata);
}
_INLINE_SPECIFIER_ AttitudeSensorResultSource::~AttitudeSensorResultSource()
{
    cdata_ = nullptr;
}

_INLINE_SPECIFIER_ std::shared_ptr<easyar_AttitudeSensorResultSource> AttitudeSensorResultSource::get_cdata()
{
    return cdata_;
}
_INLINE_SPECIFIER_ void AttitudeSensorResultSource::init_cdata(std::shared_ptr<easyar_AttitudeSensorResultSource> cdata)
{
    cdata_ = cdata;
}
_INLINE_SPECIFIER_ std::shared_ptr<AttitudeSensorResultSource> AttitudeSensorResultSource::from_cdata(std::shared_ptr<easyar_AttitudeSensorResultSource> cdata)
{
    if (cdata == nullptr) {
        return nullptr;
    }
    return std::make_shared<AttitudeSensorResultSource>(cdata);
}
_INLINE_SPECIFIER_ void AttitudeSensorResultSource::setHandler(std::optional<std::function<void(AttitudeSensorResult)>> handler)
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    if (!(!handler.has_value() || (handler.value() != nullptr))) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: handler");
#else
        std::terminate();
#endif
    }
    easyar_AttitudeSensorResultSource_setHandler(this->cdata_.get(), (handler.has_value() ? easyar_OptionalOfFunctorOfVoidFromAttitudeSensorResult{true, FunctorOfVoidFromAttitudeSensorResult_to_c(handler.value())} : easyar_OptionalOfFunctorOfVoidFromAttitudeSensorResult{false, {}}));
}
_INLINE_SPECIFIER_ void AttitudeSensorResultSource::connect(std::shared_ptr<AttitudeSensorResultSink> sink)
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    if (!(sink != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: sink");
#else
        std::terminate();
#endif
    }
    easyar_AttitudeSensorResultSource_connect(this->cdata_.get(), sink->get_cdata().get());
}
_INLINE_SPECIFIER_ void AttitudeSensorResultSource::disconnect()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_AttitudeSensorResultSource_disconnect(this->cdata_.get());
}

_INLINE_SPECIFIER_ MagnetometerResultSink::MagnetometerResultSink(std::shared_ptr<easyar_MagnetometerResultSink> cdata)
    :
    cdata_(nullptr)
{
    init_cdata(cdata);
}
_INLINE_SPECIFIER_ MagnetometerResultSink::~MagnetometerResultSink()
{
    cdata_ = nullptr;
}

_INLINE_SPECIFIER_ std::shared_ptr<easyar_MagnetometerResultSink> MagnetometerResultSink::get_cdata()
{
    return cdata_;
}
_INLINE_SPECIFIER_ void MagnetometerResultSink::init_cdata(std::shared_ptr<easyar_MagnetometerResultSink> cdata)
{
    cdata_ = cdata;
}
_INLINE_SPECIFIER_ std::shared_ptr<MagnetometerResultSink> MagnetometerResultSink::from_cdata(std::shared_ptr<easyar_MagnetometerResultSink> cdata)
{
    if (cdata == nullptr) {
        return nullptr;
    }
    return std::make_shared<MagnetometerResultSink>(cdata);
}
_INLINE_SPECIFIER_ void MagnetometerResultSink::handle(MagnetometerResult inputData)
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_MagnetometerResultSink_handle(this->cdata_.get(), easyar_MagnetometerResult{inputData.x, inputData.y, inputData.z, inputData.timestamp});
}

_INLINE_SPECIFIER_ MagnetometerResultSource::MagnetometerResultSource(std::shared_ptr<easyar_MagnetometerResultSource> cdata)
    :
    cdata_(nullptr)
{
    init_cdata(cdata);
}
_INLINE_SPECIFIER_ MagnetometerResultSource::~MagnetometerResultSource()
{
    cdata_ = nullptr;
}

_INLINE_SPECIFIER_ std::shared_ptr<easyar_MagnetometerResultSource> MagnetometerResultSource::get_cdata()
{
    return cdata_;
}
_INLINE_SPECIFIER_ void MagnetometerResultSource::init_cdata(std::shared_ptr<easyar_MagnetometerResultSource> cdata)
{
    cdata_ = cdata;
}
_INLINE_SPECIFIER_ std::shared_ptr<MagnetometerResultSource> MagnetometerResultSource::from_cdata(std::shared_ptr<easyar_MagnetometerResultSource> cdata)
{
    if (cdata == nullptr) {
        return nullptr;
    }
    return std::make_shared<MagnetometerResultSource>(cdata);
}
_INLINE_SPECIFIER_ void MagnetometerResultSource::setHandler(std::optional<std::function<void(MagnetometerResult)>> handler)
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    if (!(!handler.has_value() || (handler.value() != nullptr))) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: handler");
#else
        std::terminate();
#endif
    }
    easyar_MagnetometerResultSource_setHandler(this->cdata_.get(), (handler.has_value() ? easyar_OptionalOfFunctorOfVoidFromMagnetometerResult{true, FunctorOfVoidFromMagnetometerResult_to_c(handler.value())} : easyar_OptionalOfFunctorOfVoidFromMagnetometerResult{false, {}}));
}
_INLINE_SPECIFIER_ void MagnetometerResultSource::connect(std::shared_ptr<MagnetometerResultSink> sink)
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    if (!(sink != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: sink");
#else
        std::terminate();
#endif
    }
    easyar_MagnetometerResultSource_connect(this->cdata_.get(), sink->get_cdata().get());
}
_INLINE_SPECIFIER_ void MagnetometerResultSource::disconnect()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_MagnetometerResultSource_disconnect(this->cdata_.get());
}

_INLINE_SPECIFIER_ LocationResultSink::LocationResultSink(std::shared_ptr<easyar_LocationResultSink> cdata)
    :
    cdata_(nullptr)
{
    init_cdata(cdata);
}
_INLINE_SPECIFIER_ LocationResultSink::~LocationResultSink()
{
    cdata_ = nullptr;
}

_INLINE_SPECIFIER_ std::shared_ptr<easyar_LocationResultSink> LocationResultSink::get_cdata()
{
    return cdata_;
}
_INLINE_SPECIFIER_ void LocationResultSink::init_cdata(std::shared_ptr<easyar_LocationResultSink> cdata)
{
    cdata_ = cdata;
}
_INLINE_SPECIFIER_ std::shared_ptr<LocationResultSink> LocationResultSink::from_cdata(std::shared_ptr<easyar_LocationResultSink> cdata)
{
    if (cdata == nullptr) {
        return nullptr;
    }
    return std::make_shared<LocationResultSink>(cdata);
}
_INLINE_SPECIFIER_ void LocationResultSink::handle(LocationResult inputData)
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_LocationResultSink_handle(this->cdata_.get(), easyar_LocationResult{inputData.latitude, inputData.longitude, inputData.altitude, inputData.horizontalAccuracy, inputData.verticalAccuracy, inputData.hasAltitude, inputData.hasHorizontalAccuracy, inputData.hasVerticalAccuracy});
}

_INLINE_SPECIFIER_ LocationResultSource::LocationResultSource(std::shared_ptr<easyar_LocationResultSource> cdata)
    :
    cdata_(nullptr)
{
    init_cdata(cdata);
}
_INLINE_SPECIFIER_ LocationResultSource::~LocationResultSource()
{
    cdata_ = nullptr;
}

_INLINE_SPECIFIER_ std::shared_ptr<easyar_LocationResultSource> LocationResultSource::get_cdata()
{
    return cdata_;
}
_INLINE_SPECIFIER_ void LocationResultSource::init_cdata(std::shared_ptr<easyar_LocationResultSource> cdata)
{
    cdata_ = cdata;
}
_INLINE_SPECIFIER_ std::shared_ptr<LocationResultSource> LocationResultSource::from_cdata(std::shared_ptr<easyar_LocationResultSource> cdata)
{
    if (cdata == nullptr) {
        return nullptr;
    }
    return std::make_shared<LocationResultSource>(cdata);
}
_INLINE_SPECIFIER_ void LocationResultSource::setHandler(std::optional<std::function<void(LocationResult)>> handler)
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    if (!(!handler.has_value() || (handler.value() != nullptr))) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: handler");
#else
        std::terminate();
#endif
    }
    easyar_LocationResultSource_setHandler(this->cdata_.get(), (handler.has_value() ? easyar_OptionalOfFunctorOfVoidFromLocationResult{true, FunctorOfVoidFromLocationResult_to_c(handler.value())} : easyar_OptionalOfFunctorOfVoidFromLocationResult{false, {}}));
}
_INLINE_SPECIFIER_ void LocationResultSource::connect(std::shared_ptr<LocationResultSink> sink)
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    if (!(sink != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: sink");
#else
        std::terminate();
#endif
    }
    easyar_LocationResultSource_connect(this->cdata_.get(), sink->get_cdata().get());
}
_INLINE_SPECIFIER_ void LocationResultSource::disconnect()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_LocationResultSource_disconnect(this->cdata_.get());
}

_INLINE_SPECIFIER_ ProximityLocationResultSink::ProximityLocationResultSink(std::shared_ptr<easyar_ProximityLocationResultSink> cdata)
    :
    cdata_(nullptr)
{
    init_cdata(cdata);
}
_INLINE_SPECIFIER_ ProximityLocationResultSink::~ProximityLocationResultSink()
{
    cdata_ = nullptr;
}

_INLINE_SPECIFIER_ std::shared_ptr<easyar_ProximityLocationResultSink> ProximityLocationResultSink::get_cdata()
{
    return cdata_;
}
_INLINE_SPECIFIER_ void ProximityLocationResultSink::init_cdata(std::shared_ptr<easyar_ProximityLocationResultSink> cdata)
{
    cdata_ = cdata;
}
_INLINE_SPECIFIER_ std::shared_ptr<ProximityLocationResultSink> ProximityLocationResultSink::from_cdata(std::shared_ptr<easyar_ProximityLocationResultSink> cdata)
{
    if (cdata == nullptr) {
        return nullptr;
    }
    return std::make_shared<ProximityLocationResultSink>(cdata);
}
_INLINE_SPECIFIER_ void ProximityLocationResultSink::handle(ProximityLocationResult inputData)
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_ProximityLocationResultSink_handle(this->cdata_.get(), easyar_ProximityLocationResult{inputData.x, inputData.y, inputData.z, inputData.accuracy, inputData.timestamp, inputData.is2d, inputData.validTime});
}

_INLINE_SPECIFIER_ ProximityLocationResultSource::ProximityLocationResultSource(std::shared_ptr<easyar_ProximityLocationResultSource> cdata)
    :
    cdata_(nullptr)
{
    init_cdata(cdata);
}
_INLINE_SPECIFIER_ ProximityLocationResultSource::~ProximityLocationResultSource()
{
    cdata_ = nullptr;
}

_INLINE_SPECIFIER_ std::shared_ptr<easyar_ProximityLocationResultSource> ProximityLocationResultSource::get_cdata()
{
    return cdata_;
}
_INLINE_SPECIFIER_ void ProximityLocationResultSource::init_cdata(std::shared_ptr<easyar_ProximityLocationResultSource> cdata)
{
    cdata_ = cdata;
}
_INLINE_SPECIFIER_ std::shared_ptr<ProximityLocationResultSource> ProximityLocationResultSource::from_cdata(std::shared_ptr<easyar_ProximityLocationResultSource> cdata)
{
    if (cdata == nullptr) {
        return nullptr;
    }
    return std::make_shared<ProximityLocationResultSource>(cdata);
}
_INLINE_SPECIFIER_ void ProximityLocationResultSource::setHandler(std::optional<std::function<void(ProximityLocationResult)>> handler)
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    if (!(!handler.has_value() || (handler.value() != nullptr))) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: handler");
#else
        std::terminate();
#endif
    }
    easyar_ProximityLocationResultSource_setHandler(this->cdata_.get(), (handler.has_value() ? easyar_OptionalOfFunctorOfVoidFromProximityLocationResult{true, FunctorOfVoidFromProximityLocationResult_to_c(handler.value())} : easyar_OptionalOfFunctorOfVoidFromProximityLocationResult{false, {}}));
}
_INLINE_SPECIFIER_ void ProximityLocationResultSource::connect(std::shared_ptr<ProximityLocationResultSink> sink)
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    if (!(sink != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: sink");
#else
        std::terminate();
#endif
    }
    easyar_ProximityLocationResultSource_connect(this->cdata_.get(), sink->get_cdata().get());
}
_INLINE_SPECIFIER_ void ProximityLocationResultSource::disconnect()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_ProximityLocationResultSource_disconnect(this->cdata_.get());
}

_INLINE_SPECIFIER_ InputFrameSink::InputFrameSink(std::shared_ptr<easyar_InputFrameSink> cdata)
    :
    cdata_(nullptr)
{
    init_cdata(cdata);
}
_INLINE_SPECIFIER_ InputFrameSink::~InputFrameSink()
{
    cdata_ = nullptr;
}

_INLINE_SPECIFIER_ std::shared_ptr<easyar_InputFrameSink> InputFrameSink::get_cdata()
{
    return cdata_;
}
_INLINE_SPECIFIER_ void InputFrameSink::init_cdata(std::shared_ptr<easyar_InputFrameSink> cdata)
{
    cdata_ = cdata;
}
_INLINE_SPECIFIER_ std::shared_ptr<InputFrameSink> InputFrameSink::from_cdata(std::shared_ptr<easyar_InputFrameSink> cdata)
{
    if (cdata == nullptr) {
        return nullptr;
    }
    return std::make_shared<InputFrameSink>(cdata);
}
_INLINE_SPECIFIER_ void InputFrameSink::handle(std::shared_ptr<InputFrame> inputData)
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    if (!(inputData != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: inputData");
#else
        std::terminate();
#endif
    }
    easyar_InputFrameSink_handle(this->cdata_.get(), inputData->get_cdata().get());
}

_INLINE_SPECIFIER_ InputFrameSource::InputFrameSource(std::shared_ptr<easyar_InputFrameSource> cdata)
    :
    cdata_(nullptr)
{
    init_cdata(cdata);
}
_INLINE_SPECIFIER_ InputFrameSource::~InputFrameSource()
{
    cdata_ = nullptr;
}

_INLINE_SPECIFIER_ std::shared_ptr<easyar_InputFrameSource> InputFrameSource::get_cdata()
{
    return cdata_;
}
_INLINE_SPECIFIER_ void InputFrameSource::init_cdata(std::shared_ptr<easyar_InputFrameSource> cdata)
{
    cdata_ = cdata;
}
_INLINE_SPECIFIER_ std::shared_ptr<InputFrameSource> InputFrameSource::from_cdata(std::shared_ptr<easyar_InputFrameSource> cdata)
{
    if (cdata == nullptr) {
        return nullptr;
    }
    return std::make_shared<InputFrameSource>(cdata);
}
_INLINE_SPECIFIER_ void InputFrameSource::setHandler(std::optional<std::function<void(std::shared_ptr<InputFrame>)>> handler)
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    if (!(!handler.has_value() || (handler.value() != nullptr))) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: handler");
#else
        std::terminate();
#endif
    }
    easyar_InputFrameSource_setHandler(this->cdata_.get(), (handler.has_value() ? easyar_OptionalOfFunctorOfVoidFromInputFrame{true, FunctorOfVoidFromInputFrame_to_c(handler.value())} : easyar_OptionalOfFunctorOfVoidFromInputFrame{false, {}}));
}
_INLINE_SPECIFIER_ void InputFrameSource::connect(std::shared_ptr<InputFrameSink> sink)
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    if (!(sink != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: sink");
#else
        std::terminate();
#endif
    }
    easyar_InputFrameSource_connect(this->cdata_.get(), sink->get_cdata().get());
}
_INLINE_SPECIFIER_ void InputFrameSource::disconnect()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_InputFrameSource_disconnect(this->cdata_.get());
}

_INLINE_SPECIFIER_ OutputFrameSink::OutputFrameSink(std::shared_ptr<easyar_OutputFrameSink> cdata)
    :
    cdata_(nullptr)
{
    init_cdata(cdata);
}
_INLINE_SPECIFIER_ OutputFrameSink::~OutputFrameSink()
{
    cdata_ = nullptr;
}

_INLINE_SPECIFIER_ std::shared_ptr<easyar_OutputFrameSink> OutputFrameSink::get_cdata()
{
    return cdata_;
}
_INLINE_SPECIFIER_ void OutputFrameSink::init_cdata(std::shared_ptr<easyar_OutputFrameSink> cdata)
{
    cdata_ = cdata;
}
_INLINE_SPECIFIER_ std::shared_ptr<OutputFrameSink> OutputFrameSink::from_cdata(std::shared_ptr<easyar_OutputFrameSink> cdata)
{
    if (cdata == nullptr) {
        return nullptr;
    }
    return std::make_shared<OutputFrameSink>(cdata);
}
_INLINE_SPECIFIER_ void OutputFrameSink::handle(std::shared_ptr<OutputFrame> inputData)
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    if (!(inputData != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: inputData");
#else
        std::terminate();
#endif
    }
    easyar_OutputFrameSink_handle(this->cdata_.get(), inputData->get_cdata().get());
}

_INLINE_SPECIFIER_ OutputFrameSource::OutputFrameSource(std::shared_ptr<easyar_OutputFrameSource> cdata)
    :
    cdata_(nullptr)
{
    init_cdata(cdata);
}
_INLINE_SPECIFIER_ OutputFrameSource::~OutputFrameSource()
{
    cdata_ = nullptr;
}

_INLINE_SPECIFIER_ std::shared_ptr<easyar_OutputFrameSource> OutputFrameSource::get_cdata()
{
    return cdata_;
}
_INLINE_SPECIFIER_ void OutputFrameSource::init_cdata(std::shared_ptr<easyar_OutputFrameSource> cdata)
{
    cdata_ = cdata;
}
_INLINE_SPECIFIER_ std::shared_ptr<OutputFrameSource> OutputFrameSource::from_cdata(std::shared_ptr<easyar_OutputFrameSource> cdata)
{
    if (cdata == nullptr) {
        return nullptr;
    }
    return std::make_shared<OutputFrameSource>(cdata);
}
_INLINE_SPECIFIER_ void OutputFrameSource::setHandler(std::optional<std::function<void(std::shared_ptr<OutputFrame>)>> handler)
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    if (!(!handler.has_value() || (handler.value() != nullptr))) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: handler");
#else
        std::terminate();
#endif
    }
    easyar_OutputFrameSource_setHandler(this->cdata_.get(), (handler.has_value() ? easyar_OptionalOfFunctorOfVoidFromOutputFrame{true, FunctorOfVoidFromOutputFrame_to_c(handler.value())} : easyar_OptionalOfFunctorOfVoidFromOutputFrame{false, {}}));
}
_INLINE_SPECIFIER_ void OutputFrameSource::connect(std::shared_ptr<OutputFrameSink> sink)
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    if (!(sink != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: sink");
#else
        std::terminate();
#endif
    }
    easyar_OutputFrameSource_connect(this->cdata_.get(), sink->get_cdata().get());
}
_INLINE_SPECIFIER_ void OutputFrameSource::disconnect()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_OutputFrameSource_disconnect(this->cdata_.get());
}

_INLINE_SPECIFIER_ FeedbackFrameSink::FeedbackFrameSink(std::shared_ptr<easyar_FeedbackFrameSink> cdata)
    :
    cdata_(nullptr)
{
    init_cdata(cdata);
}
_INLINE_SPECIFIER_ FeedbackFrameSink::~FeedbackFrameSink()
{
    cdata_ = nullptr;
}

_INLINE_SPECIFIER_ std::shared_ptr<easyar_FeedbackFrameSink> FeedbackFrameSink::get_cdata()
{
    return cdata_;
}
_INLINE_SPECIFIER_ void FeedbackFrameSink::init_cdata(std::shared_ptr<easyar_FeedbackFrameSink> cdata)
{
    cdata_ = cdata;
}
_INLINE_SPECIFIER_ std::shared_ptr<FeedbackFrameSink> FeedbackFrameSink::from_cdata(std::shared_ptr<easyar_FeedbackFrameSink> cdata)
{
    if (cdata == nullptr) {
        return nullptr;
    }
    return std::make_shared<FeedbackFrameSink>(cdata);
}
_INLINE_SPECIFIER_ void FeedbackFrameSink::handle(std::shared_ptr<FeedbackFrame> inputData)
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    if (!(inputData != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: inputData");
#else
        std::terminate();
#endif
    }
    easyar_FeedbackFrameSink_handle(this->cdata_.get(), inputData->get_cdata().get());
}

_INLINE_SPECIFIER_ FeedbackFrameSource::FeedbackFrameSource(std::shared_ptr<easyar_FeedbackFrameSource> cdata)
    :
    cdata_(nullptr)
{
    init_cdata(cdata);
}
_INLINE_SPECIFIER_ FeedbackFrameSource::~FeedbackFrameSource()
{
    cdata_ = nullptr;
}

_INLINE_SPECIFIER_ std::shared_ptr<easyar_FeedbackFrameSource> FeedbackFrameSource::get_cdata()
{
    return cdata_;
}
_INLINE_SPECIFIER_ void FeedbackFrameSource::init_cdata(std::shared_ptr<easyar_FeedbackFrameSource> cdata)
{
    cdata_ = cdata;
}
_INLINE_SPECIFIER_ std::shared_ptr<FeedbackFrameSource> FeedbackFrameSource::from_cdata(std::shared_ptr<easyar_FeedbackFrameSource> cdata)
{
    if (cdata == nullptr) {
        return nullptr;
    }
    return std::make_shared<FeedbackFrameSource>(cdata);
}
_INLINE_SPECIFIER_ void FeedbackFrameSource::setHandler(std::optional<std::function<void(std::shared_ptr<FeedbackFrame>)>> handler)
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    if (!(!handler.has_value() || (handler.value() != nullptr))) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: handler");
#else
        std::terminate();
#endif
    }
    easyar_FeedbackFrameSource_setHandler(this->cdata_.get(), (handler.has_value() ? easyar_OptionalOfFunctorOfVoidFromFeedbackFrame{true, FunctorOfVoidFromFeedbackFrame_to_c(handler.value())} : easyar_OptionalOfFunctorOfVoidFromFeedbackFrame{false, {}}));
}
_INLINE_SPECIFIER_ void FeedbackFrameSource::connect(std::shared_ptr<FeedbackFrameSink> sink)
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    if (!(sink != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: sink");
#else
        std::terminate();
#endif
    }
    easyar_FeedbackFrameSource_connect(this->cdata_.get(), sink->get_cdata().get());
}
_INLINE_SPECIFIER_ void FeedbackFrameSource::disconnect()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_FeedbackFrameSource_disconnect(this->cdata_.get());
}

_INLINE_SPECIFIER_ InputFrameFork::InputFrameFork(std::shared_ptr<easyar_InputFrameFork> cdata)
    :
    cdata_(nullptr)
{
    init_cdata(cdata);
}
_INLINE_SPECIFIER_ InputFrameFork::~InputFrameFork()
{
    cdata_ = nullptr;
}

_INLINE_SPECIFIER_ std::shared_ptr<easyar_InputFrameFork> InputFrameFork::get_cdata()
{
    return cdata_;
}
_INLINE_SPECIFIER_ void InputFrameFork::init_cdata(std::shared_ptr<easyar_InputFrameFork> cdata)
{
    cdata_ = cdata;
}
_INLINE_SPECIFIER_ std::shared_ptr<InputFrameFork> InputFrameFork::from_cdata(std::shared_ptr<easyar_InputFrameFork> cdata)
{
    if (cdata == nullptr) {
        return nullptr;
    }
    return std::make_shared<InputFrameFork>(cdata);
}
_INLINE_SPECIFIER_ std::shared_ptr<InputFrameSink> InputFrameFork::input()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_InputFrameSink * _return_value_;
    easyar_InputFrameFork_input(this->cdata_.get(), &_return_value_);
    if (!(_return_value_ != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    return InputFrameSink::from_cdata(std::shared_ptr<easyar_InputFrameSink>(_return_value_, [](easyar_InputFrameSink * ptr) { easyar_InputFrameSink__dtor(ptr); }));
}
_INLINE_SPECIFIER_ std::shared_ptr<InputFrameSource> InputFrameFork::output(int index)
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_InputFrameSource * _return_value_;
    easyar_InputFrameFork_output(this->cdata_.get(), index, &_return_value_);
    if (!(_return_value_ != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    return InputFrameSource::from_cdata(std::shared_ptr<easyar_InputFrameSource>(_return_value_, [](easyar_InputFrameSource * ptr) { easyar_InputFrameSource__dtor(ptr); }));
}
_INLINE_SPECIFIER_ int InputFrameFork::outputCount()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_InputFrameFork_outputCount(this->cdata_.get());
    return _return_value_;
}
_INLINE_SPECIFIER_ std::shared_ptr<InputFrameFork> InputFrameFork::create(int outputCount)
{
    easyar_InputFrameFork * _return_value_;
    easyar_InputFrameFork_create(outputCount, &_return_value_);
    if (!(_return_value_ != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    return InputFrameFork::from_cdata(std::shared_ptr<easyar_InputFrameFork>(_return_value_, [](easyar_InputFrameFork * ptr) { easyar_InputFrameFork__dtor(ptr); }));
}

_INLINE_SPECIFIER_ OutputFrameFork::OutputFrameFork(std::shared_ptr<easyar_OutputFrameFork> cdata)
    :
    cdata_(nullptr)
{
    init_cdata(cdata);
}
_INLINE_SPECIFIER_ OutputFrameFork::~OutputFrameFork()
{
    cdata_ = nullptr;
}

_INLINE_SPECIFIER_ std::shared_ptr<easyar_OutputFrameFork> OutputFrameFork::get_cdata()
{
    return cdata_;
}
_INLINE_SPECIFIER_ void OutputFrameFork::init_cdata(std::shared_ptr<easyar_OutputFrameFork> cdata)
{
    cdata_ = cdata;
}
_INLINE_SPECIFIER_ std::shared_ptr<OutputFrameFork> OutputFrameFork::from_cdata(std::shared_ptr<easyar_OutputFrameFork> cdata)
{
    if (cdata == nullptr) {
        return nullptr;
    }
    return std::make_shared<OutputFrameFork>(cdata);
}
_INLINE_SPECIFIER_ std::shared_ptr<OutputFrameSink> OutputFrameFork::input()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_OutputFrameSink * _return_value_;
    easyar_OutputFrameFork_input(this->cdata_.get(), &_return_value_);
    if (!(_return_value_ != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    return OutputFrameSink::from_cdata(std::shared_ptr<easyar_OutputFrameSink>(_return_value_, [](easyar_OutputFrameSink * ptr) { easyar_OutputFrameSink__dtor(ptr); }));
}
_INLINE_SPECIFIER_ std::shared_ptr<OutputFrameSource> OutputFrameFork::output(int index)
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_OutputFrameSource * _return_value_;
    easyar_OutputFrameFork_output(this->cdata_.get(), index, &_return_value_);
    if (!(_return_value_ != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    return OutputFrameSource::from_cdata(std::shared_ptr<easyar_OutputFrameSource>(_return_value_, [](easyar_OutputFrameSource * ptr) { easyar_OutputFrameSource__dtor(ptr); }));
}
_INLINE_SPECIFIER_ int OutputFrameFork::outputCount()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_OutputFrameFork_outputCount(this->cdata_.get());
    return _return_value_;
}
_INLINE_SPECIFIER_ std::shared_ptr<OutputFrameFork> OutputFrameFork::create(int outputCount)
{
    easyar_OutputFrameFork * _return_value_;
    easyar_OutputFrameFork_create(outputCount, &_return_value_);
    if (!(_return_value_ != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    return OutputFrameFork::from_cdata(std::shared_ptr<easyar_OutputFrameFork>(_return_value_, [](easyar_OutputFrameFork * ptr) { easyar_OutputFrameFork__dtor(ptr); }));
}

_INLINE_SPECIFIER_ OutputFrameJoin::OutputFrameJoin(std::shared_ptr<easyar_OutputFrameJoin> cdata)
    :
    cdata_(nullptr)
{
    init_cdata(cdata);
}
_INLINE_SPECIFIER_ OutputFrameJoin::~OutputFrameJoin()
{
    cdata_ = nullptr;
}

_INLINE_SPECIFIER_ std::shared_ptr<easyar_OutputFrameJoin> OutputFrameJoin::get_cdata()
{
    return cdata_;
}
_INLINE_SPECIFIER_ void OutputFrameJoin::init_cdata(std::shared_ptr<easyar_OutputFrameJoin> cdata)
{
    cdata_ = cdata;
}
_INLINE_SPECIFIER_ std::shared_ptr<OutputFrameJoin> OutputFrameJoin::from_cdata(std::shared_ptr<easyar_OutputFrameJoin> cdata)
{
    if (cdata == nullptr) {
        return nullptr;
    }
    return std::make_shared<OutputFrameJoin>(cdata);
}
_INLINE_SPECIFIER_ std::shared_ptr<OutputFrameSink> OutputFrameJoin::input(int index)
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_OutputFrameSink * _return_value_;
    easyar_OutputFrameJoin_input(this->cdata_.get(), index, &_return_value_);
    if (!(_return_value_ != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    return OutputFrameSink::from_cdata(std::shared_ptr<easyar_OutputFrameSink>(_return_value_, [](easyar_OutputFrameSink * ptr) { easyar_OutputFrameSink__dtor(ptr); }));
}
_INLINE_SPECIFIER_ std::shared_ptr<OutputFrameSource> OutputFrameJoin::output()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_OutputFrameSource * _return_value_;
    easyar_OutputFrameJoin_output(this->cdata_.get(), &_return_value_);
    if (!(_return_value_ != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    return OutputFrameSource::from_cdata(std::shared_ptr<easyar_OutputFrameSource>(_return_value_, [](easyar_OutputFrameSource * ptr) { easyar_OutputFrameSource__dtor(ptr); }));
}
_INLINE_SPECIFIER_ int OutputFrameJoin::inputCount()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_OutputFrameJoin_inputCount(this->cdata_.get());
    return _return_value_;
}
_INLINE_SPECIFIER_ std::shared_ptr<OutputFrameJoin> OutputFrameJoin::create(int inputCount)
{
    easyar_OutputFrameJoin * _return_value_;
    easyar_OutputFrameJoin_create(inputCount, &_return_value_);
    if (!(_return_value_ != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    return OutputFrameJoin::from_cdata(std::shared_ptr<easyar_OutputFrameJoin>(_return_value_, [](easyar_OutputFrameJoin * ptr) { easyar_OutputFrameJoin__dtor(ptr); }));
}
_INLINE_SPECIFIER_ std::shared_ptr<OutputFrameJoin> OutputFrameJoin::createWithJoiner(int inputCount, std::function<std::shared_ptr<OutputFrame>(std::vector<std::shared_ptr<OutputFrame>>)> joiner)
{
    if (!(joiner != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: joiner");
#else
        std::terminate();
#endif
    }
    easyar_OutputFrameJoin * _return_value_;
    easyar_OutputFrameJoin_createWithJoiner(inputCount, FunctorOfOutputFrameFromListOfOutputFrame_to_c(joiner), &_return_value_);
    if (!(_return_value_ != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    return OutputFrameJoin::from_cdata(std::shared_ptr<easyar_OutputFrameJoin>(_return_value_, [](easyar_OutputFrameJoin * ptr) { easyar_OutputFrameJoin__dtor(ptr); }));
}

_INLINE_SPECIFIER_ FeedbackFrameFork::FeedbackFrameFork(std::shared_ptr<easyar_FeedbackFrameFork> cdata)
    :
    cdata_(nullptr)
{
    init_cdata(cdata);
}
_INLINE_SPECIFIER_ FeedbackFrameFork::~FeedbackFrameFork()
{
    cdata_ = nullptr;
}

_INLINE_SPECIFIER_ std::shared_ptr<easyar_FeedbackFrameFork> FeedbackFrameFork::get_cdata()
{
    return cdata_;
}
_INLINE_SPECIFIER_ void FeedbackFrameFork::init_cdata(std::shared_ptr<easyar_FeedbackFrameFork> cdata)
{
    cdata_ = cdata;
}
_INLINE_SPECIFIER_ std::shared_ptr<FeedbackFrameFork> FeedbackFrameFork::from_cdata(std::shared_ptr<easyar_FeedbackFrameFork> cdata)
{
    if (cdata == nullptr) {
        return nullptr;
    }
    return std::make_shared<FeedbackFrameFork>(cdata);
}
_INLINE_SPECIFIER_ std::shared_ptr<FeedbackFrameSink> FeedbackFrameFork::input()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_FeedbackFrameSink * _return_value_;
    easyar_FeedbackFrameFork_input(this->cdata_.get(), &_return_value_);
    if (!(_return_value_ != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    return FeedbackFrameSink::from_cdata(std::shared_ptr<easyar_FeedbackFrameSink>(_return_value_, [](easyar_FeedbackFrameSink * ptr) { easyar_FeedbackFrameSink__dtor(ptr); }));
}
_INLINE_SPECIFIER_ std::shared_ptr<FeedbackFrameSource> FeedbackFrameFork::output(int index)
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_FeedbackFrameSource * _return_value_;
    easyar_FeedbackFrameFork_output(this->cdata_.get(), index, &_return_value_);
    if (!(_return_value_ != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    return FeedbackFrameSource::from_cdata(std::shared_ptr<easyar_FeedbackFrameSource>(_return_value_, [](easyar_FeedbackFrameSource * ptr) { easyar_FeedbackFrameSource__dtor(ptr); }));
}
_INLINE_SPECIFIER_ int FeedbackFrameFork::outputCount()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_FeedbackFrameFork_outputCount(this->cdata_.get());
    return _return_value_;
}
_INLINE_SPECIFIER_ std::shared_ptr<FeedbackFrameFork> FeedbackFrameFork::create(int outputCount)
{
    easyar_FeedbackFrameFork * _return_value_;
    easyar_FeedbackFrameFork_create(outputCount, &_return_value_);
    if (!(_return_value_ != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    return FeedbackFrameFork::from_cdata(std::shared_ptr<easyar_FeedbackFrameFork>(_return_value_, [](easyar_FeedbackFrameFork * ptr) { easyar_FeedbackFrameFork__dtor(ptr); }));
}

_INLINE_SPECIFIER_ InputFrameThrottler::InputFrameThrottler(std::shared_ptr<easyar_InputFrameThrottler> cdata)
    :
    cdata_(nullptr)
{
    init_cdata(cdata);
}
_INLINE_SPECIFIER_ InputFrameThrottler::~InputFrameThrottler()
{
    cdata_ = nullptr;
}

_INLINE_SPECIFIER_ std::shared_ptr<easyar_InputFrameThrottler> InputFrameThrottler::get_cdata()
{
    return cdata_;
}
_INLINE_SPECIFIER_ void InputFrameThrottler::init_cdata(std::shared_ptr<easyar_InputFrameThrottler> cdata)
{
    cdata_ = cdata;
}
_INLINE_SPECIFIER_ std::shared_ptr<InputFrameThrottler> InputFrameThrottler::from_cdata(std::shared_ptr<easyar_InputFrameThrottler> cdata)
{
    if (cdata == nullptr) {
        return nullptr;
    }
    return std::make_shared<InputFrameThrottler>(cdata);
}
_INLINE_SPECIFIER_ std::shared_ptr<InputFrameSink> InputFrameThrottler::input()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_InputFrameSink * _return_value_;
    easyar_InputFrameThrottler_input(this->cdata_.get(), &_return_value_);
    if (!(_return_value_ != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    return InputFrameSink::from_cdata(std::shared_ptr<easyar_InputFrameSink>(_return_value_, [](easyar_InputFrameSink * ptr) { easyar_InputFrameSink__dtor(ptr); }));
}
_INLINE_SPECIFIER_ int InputFrameThrottler::bufferRequirement()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_InputFrameThrottler_bufferRequirement(this->cdata_.get());
    return _return_value_;
}
_INLINE_SPECIFIER_ std::shared_ptr<InputFrameSource> InputFrameThrottler::output()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_InputFrameSource * _return_value_;
    easyar_InputFrameThrottler_output(this->cdata_.get(), &_return_value_);
    if (!(_return_value_ != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    return InputFrameSource::from_cdata(std::shared_ptr<easyar_InputFrameSource>(_return_value_, [](easyar_InputFrameSource * ptr) { easyar_InputFrameSource__dtor(ptr); }));
}
_INLINE_SPECIFIER_ std::shared_ptr<SignalSink> InputFrameThrottler::signalInput()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_SignalSink * _return_value_;
    easyar_InputFrameThrottler_signalInput(this->cdata_.get(), &_return_value_);
    if (!(_return_value_ != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    return SignalSink::from_cdata(std::shared_ptr<easyar_SignalSink>(_return_value_, [](easyar_SignalSink * ptr) { easyar_SignalSink__dtor(ptr); }));
}
_INLINE_SPECIFIER_ std::shared_ptr<InputFrameThrottler> InputFrameThrottler::create()
{
    easyar_InputFrameThrottler * _return_value_;
    easyar_InputFrameThrottler_create(&_return_value_);
    if (!(_return_value_ != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    return InputFrameThrottler::from_cdata(std::shared_ptr<easyar_InputFrameThrottler>(_return_value_, [](easyar_InputFrameThrottler * ptr) { easyar_InputFrameThrottler__dtor(ptr); }));
}

_INLINE_SPECIFIER_ OutputFrameBuffer::OutputFrameBuffer(std::shared_ptr<easyar_OutputFrameBuffer> cdata)
    :
    cdata_(nullptr)
{
    init_cdata(cdata);
}
_INLINE_SPECIFIER_ OutputFrameBuffer::~OutputFrameBuffer()
{
    cdata_ = nullptr;
}

_INLINE_SPECIFIER_ std::shared_ptr<easyar_OutputFrameBuffer> OutputFrameBuffer::get_cdata()
{
    return cdata_;
}
_INLINE_SPECIFIER_ void OutputFrameBuffer::init_cdata(std::shared_ptr<easyar_OutputFrameBuffer> cdata)
{
    cdata_ = cdata;
}
_INLINE_SPECIFIER_ std::shared_ptr<OutputFrameBuffer> OutputFrameBuffer::from_cdata(std::shared_ptr<easyar_OutputFrameBuffer> cdata)
{
    if (cdata == nullptr) {
        return nullptr;
    }
    return std::make_shared<OutputFrameBuffer>(cdata);
}
_INLINE_SPECIFIER_ std::shared_ptr<OutputFrameSink> OutputFrameBuffer::input()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_OutputFrameSink * _return_value_;
    easyar_OutputFrameBuffer_input(this->cdata_.get(), &_return_value_);
    if (!(_return_value_ != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    return OutputFrameSink::from_cdata(std::shared_ptr<easyar_OutputFrameSink>(_return_value_, [](easyar_OutputFrameSink * ptr) { easyar_OutputFrameSink__dtor(ptr); }));
}
_INLINE_SPECIFIER_ int OutputFrameBuffer::bufferRequirement()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_OutputFrameBuffer_bufferRequirement(this->cdata_.get());
    return _return_value_;
}
_INLINE_SPECIFIER_ std::shared_ptr<SignalSource> OutputFrameBuffer::signalOutput()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_SignalSource * _return_value_;
    easyar_OutputFrameBuffer_signalOutput(this->cdata_.get(), &_return_value_);
    if (!(_return_value_ != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    return SignalSource::from_cdata(std::shared_ptr<easyar_SignalSource>(_return_value_, [](easyar_SignalSource * ptr) { easyar_SignalSource__dtor(ptr); }));
}
_INLINE_SPECIFIER_ std::optional<std::shared_ptr<OutputFrame>> OutputFrameBuffer::peek()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_OptionalOfOutputFrame _return_value_;
    easyar_OutputFrameBuffer_peek(this->cdata_.get(), &_return_value_);
    if (!(!_return_value_.has_value || (_return_value_.value != nullptr))) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    return (_return_value_.has_value ? OutputFrame::from_cdata(std::shared_ptr<easyar_OutputFrame>(_return_value_.value, [](easyar_OutputFrame * ptr) { easyar_OutputFrame__dtor(ptr); })) : std::optional<std::shared_ptr<OutputFrame>>{});
}
_INLINE_SPECIFIER_ std::shared_ptr<OutputFrameBuffer> OutputFrameBuffer::create()
{
    easyar_OutputFrameBuffer * _return_value_;
    easyar_OutputFrameBuffer_create(&_return_value_);
    if (!(_return_value_ != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    return OutputFrameBuffer::from_cdata(std::shared_ptr<easyar_OutputFrameBuffer>(_return_value_, [](easyar_OutputFrameBuffer * ptr) { easyar_OutputFrameBuffer__dtor(ptr); }));
}
_INLINE_SPECIFIER_ void OutputFrameBuffer::pause()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_OutputFrameBuffer_pause(this->cdata_.get());
}
_INLINE_SPECIFIER_ void OutputFrameBuffer::resume()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_OutputFrameBuffer_resume(this->cdata_.get());
}

_INLINE_SPECIFIER_ InputFrameToOutputFrameAdapter::InputFrameToOutputFrameAdapter(std::shared_ptr<easyar_InputFrameToOutputFrameAdapter> cdata)
    :
    cdata_(nullptr)
{
    init_cdata(cdata);
}
_INLINE_SPECIFIER_ InputFrameToOutputFrameAdapter::~InputFrameToOutputFrameAdapter()
{
    cdata_ = nullptr;
}

_INLINE_SPECIFIER_ std::shared_ptr<easyar_InputFrameToOutputFrameAdapter> InputFrameToOutputFrameAdapter::get_cdata()
{
    return cdata_;
}
_INLINE_SPECIFIER_ void InputFrameToOutputFrameAdapter::init_cdata(std::shared_ptr<easyar_InputFrameToOutputFrameAdapter> cdata)
{
    cdata_ = cdata;
}
_INLINE_SPECIFIER_ std::shared_ptr<InputFrameToOutputFrameAdapter> InputFrameToOutputFrameAdapter::from_cdata(std::shared_ptr<easyar_InputFrameToOutputFrameAdapter> cdata)
{
    if (cdata == nullptr) {
        return nullptr;
    }
    return std::make_shared<InputFrameToOutputFrameAdapter>(cdata);
}
_INLINE_SPECIFIER_ std::shared_ptr<InputFrameSink> InputFrameToOutputFrameAdapter::input()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_InputFrameSink * _return_value_;
    easyar_InputFrameToOutputFrameAdapter_input(this->cdata_.get(), &_return_value_);
    if (!(_return_value_ != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    return InputFrameSink::from_cdata(std::shared_ptr<easyar_InputFrameSink>(_return_value_, [](easyar_InputFrameSink * ptr) { easyar_InputFrameSink__dtor(ptr); }));
}
_INLINE_SPECIFIER_ std::shared_ptr<OutputFrameSource> InputFrameToOutputFrameAdapter::output()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_OutputFrameSource * _return_value_;
    easyar_InputFrameToOutputFrameAdapter_output(this->cdata_.get(), &_return_value_);
    if (!(_return_value_ != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    return OutputFrameSource::from_cdata(std::shared_ptr<easyar_OutputFrameSource>(_return_value_, [](easyar_OutputFrameSource * ptr) { easyar_OutputFrameSource__dtor(ptr); }));
}
_INLINE_SPECIFIER_ std::shared_ptr<InputFrameToOutputFrameAdapter> InputFrameToOutputFrameAdapter::create()
{
    easyar_InputFrameToOutputFrameAdapter * _return_value_;
    easyar_InputFrameToOutputFrameAdapter_create(&_return_value_);
    if (!(_return_value_ != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    return InputFrameToOutputFrameAdapter::from_cdata(std::shared_ptr<easyar_InputFrameToOutputFrameAdapter>(_return_value_, [](easyar_InputFrameToOutputFrameAdapter * ptr) { easyar_InputFrameToOutputFrameAdapter__dtor(ptr); }));
}

_INLINE_SPECIFIER_ InputFrameToFeedbackFrameAdapter::InputFrameToFeedbackFrameAdapter(std::shared_ptr<easyar_InputFrameToFeedbackFrameAdapter> cdata)
    :
    cdata_(nullptr)
{
    init_cdata(cdata);
}
_INLINE_SPECIFIER_ InputFrameToFeedbackFrameAdapter::~InputFrameToFeedbackFrameAdapter()
{
    cdata_ = nullptr;
}

_INLINE_SPECIFIER_ std::shared_ptr<easyar_InputFrameToFeedbackFrameAdapter> InputFrameToFeedbackFrameAdapter::get_cdata()
{
    return cdata_;
}
_INLINE_SPECIFIER_ void InputFrameToFeedbackFrameAdapter::init_cdata(std::shared_ptr<easyar_InputFrameToFeedbackFrameAdapter> cdata)
{
    cdata_ = cdata;
}
_INLINE_SPECIFIER_ std::shared_ptr<InputFrameToFeedbackFrameAdapter> InputFrameToFeedbackFrameAdapter::from_cdata(std::shared_ptr<easyar_InputFrameToFeedbackFrameAdapter> cdata)
{
    if (cdata == nullptr) {
        return nullptr;
    }
    return std::make_shared<InputFrameToFeedbackFrameAdapter>(cdata);
}
_INLINE_SPECIFIER_ std::shared_ptr<InputFrameSink> InputFrameToFeedbackFrameAdapter::input()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_InputFrameSink * _return_value_;
    easyar_InputFrameToFeedbackFrameAdapter_input(this->cdata_.get(), &_return_value_);
    if (!(_return_value_ != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    return InputFrameSink::from_cdata(std::shared_ptr<easyar_InputFrameSink>(_return_value_, [](easyar_InputFrameSink * ptr) { easyar_InputFrameSink__dtor(ptr); }));
}
_INLINE_SPECIFIER_ int InputFrameToFeedbackFrameAdapter::bufferRequirement()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_InputFrameToFeedbackFrameAdapter_bufferRequirement(this->cdata_.get());
    return _return_value_;
}
_INLINE_SPECIFIER_ std::shared_ptr<OutputFrameSink> InputFrameToFeedbackFrameAdapter::sideInput()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_OutputFrameSink * _return_value_;
    easyar_InputFrameToFeedbackFrameAdapter_sideInput(this->cdata_.get(), &_return_value_);
    if (!(_return_value_ != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    return OutputFrameSink::from_cdata(std::shared_ptr<easyar_OutputFrameSink>(_return_value_, [](easyar_OutputFrameSink * ptr) { easyar_OutputFrameSink__dtor(ptr); }));
}
_INLINE_SPECIFIER_ std::shared_ptr<FeedbackFrameSource> InputFrameToFeedbackFrameAdapter::output()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_FeedbackFrameSource * _return_value_;
    easyar_InputFrameToFeedbackFrameAdapter_output(this->cdata_.get(), &_return_value_);
    if (!(_return_value_ != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    return FeedbackFrameSource::from_cdata(std::shared_ptr<easyar_FeedbackFrameSource>(_return_value_, [](easyar_FeedbackFrameSource * ptr) { easyar_FeedbackFrameSource__dtor(ptr); }));
}
_INLINE_SPECIFIER_ std::shared_ptr<InputFrameToFeedbackFrameAdapter> InputFrameToFeedbackFrameAdapter::create()
{
    easyar_InputFrameToFeedbackFrameAdapter * _return_value_;
    easyar_InputFrameToFeedbackFrameAdapter_create(&_return_value_);
    if (!(_return_value_ != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    return InputFrameToFeedbackFrameAdapter::from_cdata(std::shared_ptr<easyar_InputFrameToFeedbackFrameAdapter>(_return_value_, [](easyar_InputFrameToFeedbackFrameAdapter * ptr) { easyar_InputFrameToFeedbackFrameAdapter__dtor(ptr); }));
}

_INLINE_SPECIFIER_ MotionInputData::MotionInputData(std::shared_ptr<easyar_MotionInputData> cdata)
    :
    cdata_(nullptr)
{
    init_cdata(cdata);
}
_INLINE_SPECIFIER_ MotionInputData::~MotionInputData()
{
    cdata_ = nullptr;
}

_INLINE_SPECIFIER_ std::shared_ptr<easyar_MotionInputData> MotionInputData::get_cdata()
{
    return cdata_;
}
_INLINE_SPECIFIER_ void MotionInputData::init_cdata(std::shared_ptr<easyar_MotionInputData> cdata)
{
    cdata_ = cdata;
}
_INLINE_SPECIFIER_ std::shared_ptr<MotionInputData> MotionInputData::from_cdata(std::shared_ptr<easyar_MotionInputData> cdata)
{
    if (cdata == nullptr) {
        return nullptr;
    }
    return std::make_shared<MotionInputData>(cdata);
}
_INLINE_SPECIFIER_ std::optional<std::shared_ptr<MotionInputData>> MotionInputData::tryCreateSixDof(double timestamp, Vec3F position, Vec4F rotation, MotionTrackingStatus tracking_status)
{
    easyar_OptionalOfMotionInputData _return_value_;
    easyar_MotionInputData_tryCreateSixDof(timestamp, easyar_Vec3F{{position.data[0], position.data[1], position.data[2]}}, easyar_Vec4F{{rotation.data[0], rotation.data[1], rotation.data[2], rotation.data[3]}}, static_cast<easyar_MotionTrackingStatus>(tracking_status), &_return_value_);
    if (!(!_return_value_.has_value || (_return_value_.value != nullptr))) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    return (_return_value_.has_value ? MotionInputData::from_cdata(std::shared_ptr<easyar_MotionInputData>(_return_value_.value, [](easyar_MotionInputData * ptr) { easyar_MotionInputData__dtor(ptr); })) : std::optional<std::shared_ptr<MotionInputData>>{});
}
_INLINE_SPECIFIER_ std::optional<std::shared_ptr<MotionInputData>> MotionInputData::tryCreateFiveDofRotXZ(double timestamp, Vec3F position, Vec4F rotation)
{
    easyar_OptionalOfMotionInputData _return_value_;
    easyar_MotionInputData_tryCreateFiveDofRotXZ(timestamp, easyar_Vec3F{{position.data[0], position.data[1], position.data[2]}}, easyar_Vec4F{{rotation.data[0], rotation.data[1], rotation.data[2], rotation.data[3]}}, &_return_value_);
    if (!(!_return_value_.has_value || (_return_value_.value != nullptr))) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    return (_return_value_.has_value ? MotionInputData::from_cdata(std::shared_ptr<easyar_MotionInputData>(_return_value_.value, [](easyar_MotionInputData * ptr) { easyar_MotionInputData__dtor(ptr); })) : std::optional<std::shared_ptr<MotionInputData>>{});
}
_INLINE_SPECIFIER_ std::optional<std::shared_ptr<MotionInputData>> MotionInputData::tryCreateThreeDofRotOnly(double timestamp, Vec4F rotation)
{
    easyar_OptionalOfMotionInputData _return_value_;
    easyar_MotionInputData_tryCreateThreeDofRotOnly(timestamp, easyar_Vec4F{{rotation.data[0], rotation.data[1], rotation.data[2], rotation.data[3]}}, &_return_value_);
    if (!(!_return_value_.has_value || (_return_value_.value != nullptr))) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    return (_return_value_.has_value ? MotionInputData::from_cdata(std::shared_ptr<easyar_MotionInputData>(_return_value_.value, [](easyar_MotionInputData * ptr) { easyar_MotionInputData__dtor(ptr); })) : std::optional<std::shared_ptr<MotionInputData>>{});
}
_INLINE_SPECIFIER_ double MotionInputData::timestamp()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_MotionInputData_timestamp(this->cdata_.get());
    return _return_value_;
}
_INLINE_SPECIFIER_ CameraTransformType MotionInputData::transformType()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_MotionInputData_transformType(this->cdata_.get());
    return static_cast<CameraTransformType>(_return_value_);
}
_INLINE_SPECIFIER_ Matrix44F MotionInputData::transform()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_MotionInputData_transform(this->cdata_.get());
    return Matrix44F{{{_return_value_.data[0], _return_value_.data[1], _return_value_.data[2], _return_value_.data[3], _return_value_.data[4], _return_value_.data[5], _return_value_.data[6], _return_value_.data[7], _return_value_.data[8], _return_value_.data[9], _return_value_.data[10], _return_value_.data[11], _return_value_.data[12], _return_value_.data[13], _return_value_.data[14], _return_value_.data[15]}}};
}
_INLINE_SPECIFIER_ MotionTrackingStatus MotionInputData::trackingStatus()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_MotionInputData_trackingStatus(this->cdata_.get());
    return static_cast<MotionTrackingStatus>(_return_value_);
}

_INLINE_SPECIFIER_ InputFrame::InputFrame(std::shared_ptr<easyar_InputFrame> cdata)
    :
    cdata_(nullptr)
{
    init_cdata(cdata);
}
_INLINE_SPECIFIER_ InputFrame::~InputFrame()
{
    cdata_ = nullptr;
}

_INLINE_SPECIFIER_ std::shared_ptr<easyar_InputFrame> InputFrame::get_cdata()
{
    return cdata_;
}
_INLINE_SPECIFIER_ void InputFrame::init_cdata(std::shared_ptr<easyar_InputFrame> cdata)
{
    cdata_ = cdata;
}
_INLINE_SPECIFIER_ std::shared_ptr<InputFrame> InputFrame::from_cdata(std::shared_ptr<easyar_InputFrame> cdata)
{
    if (cdata == nullptr) {
        return nullptr;
    }
    return std::make_shared<InputFrame>(cdata);
}
_INLINE_SPECIFIER_ int InputFrame::index()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_InputFrame_index(this->cdata_.get());
    return _return_value_;
}
_INLINE_SPECIFIER_ std::shared_ptr<Image> InputFrame::image()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_Image * _return_value_;
    easyar_InputFrame_image(this->cdata_.get(), &_return_value_);
    if (!(_return_value_ != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    return Image::from_cdata(std::shared_ptr<easyar_Image>(_return_value_, [](easyar_Image * ptr) { easyar_Image__dtor(ptr); }));
}
_INLINE_SPECIFIER_ bool InputFrame::hasCameraParameters()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_InputFrame_hasCameraParameters(this->cdata_.get());
    return _return_value_;
}
_INLINE_SPECIFIER_ std::shared_ptr<CameraParameters> InputFrame::cameraParameters()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_CameraParameters * _return_value_;
    easyar_InputFrame_cameraParameters(this->cdata_.get(), &_return_value_);
    if (!(_return_value_ != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    return CameraParameters::from_cdata(std::shared_ptr<easyar_CameraParameters>(_return_value_, [](easyar_CameraParameters * ptr) { easyar_CameraParameters__dtor(ptr); }));
}
_INLINE_SPECIFIER_ bool InputFrame::hasTemporalInformation()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_InputFrame_hasTemporalInformation(this->cdata_.get());
    return _return_value_;
}
_INLINE_SPECIFIER_ double InputFrame::timestamp()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_InputFrame_timestamp(this->cdata_.get());
    return _return_value_;
}
_INLINE_SPECIFIER_ bool InputFrame::hasSpatialInformation()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_InputFrame_hasSpatialInformation(this->cdata_.get());
    return _return_value_;
}
_INLINE_SPECIFIER_ Matrix44F InputFrame::cameraTransform()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_InputFrame_cameraTransform(this->cdata_.get());
    return Matrix44F{{{_return_value_.data[0], _return_value_.data[1], _return_value_.data[2], _return_value_.data[3], _return_value_.data[4], _return_value_.data[5], _return_value_.data[6], _return_value_.data[7], _return_value_.data[8], _return_value_.data[9], _return_value_.data[10], _return_value_.data[11], _return_value_.data[12], _return_value_.data[13], _return_value_.data[14], _return_value_.data[15]}}};
}
_INLINE_SPECIFIER_ CameraTransformType InputFrame::cameraTransformType()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_InputFrame_cameraTransformType(this->cdata_.get());
    return static_cast<CameraTransformType>(_return_value_);
}
_INLINE_SPECIFIER_ MotionTrackingStatus InputFrame::trackingStatus()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_InputFrame_trackingStatus(this->cdata_.get());
    return static_cast<MotionTrackingStatus>(_return_value_);
}
_INLINE_SPECIFIER_ std::optional<std::shared_ptr<MotionInputData>> InputFrame::motion()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_OptionalOfMotionInputData _return_value_;
    easyar_InputFrame_motion(this->cdata_.get(), &_return_value_);
    if (!(!_return_value_.has_value || (_return_value_.value != nullptr))) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    return (_return_value_.has_value ? MotionInputData::from_cdata(std::shared_ptr<easyar_MotionInputData>(_return_value_.value, [](easyar_MotionInputData * ptr) { easyar_MotionInputData__dtor(ptr); })) : std::optional<std::shared_ptr<MotionInputData>>{});
}
_INLINE_SPECIFIER_ std::optional<std::shared_ptr<InputFrame>> InputFrame::tryCreate(std::shared_ptr<Image> image, std::shared_ptr<CameraParameters> cameraParameters, double timestamp, Matrix44F cameraTransform, CameraTransformType cameraTransformType, MotionTrackingStatus trackingStatus)
{
    if (!(image != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: image");
#else
        std::terminate();
#endif
    }
    if (!(cameraParameters != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: cameraParameters");
#else
        std::terminate();
#endif
    }
    easyar_OptionalOfInputFrame _return_value_;
    easyar_InputFrame_tryCreate(image->get_cdata().get(), cameraParameters->get_cdata().get(), timestamp, easyar_Matrix44F{{cameraTransform.data[0], cameraTransform.data[1], cameraTransform.data[2], cameraTransform.data[3], cameraTransform.data[4], cameraTransform.data[5], cameraTransform.data[6], cameraTransform.data[7], cameraTransform.data[8], cameraTransform.data[9], cameraTransform.data[10], cameraTransform.data[11], cameraTransform.data[12], cameraTransform.data[13], cameraTransform.data[14], cameraTransform.data[15]}}, static_cast<easyar_CameraTransformType>(cameraTransformType), static_cast<easyar_MotionTrackingStatus>(trackingStatus), &_return_value_);
    if (!(!_return_value_.has_value || (_return_value_.value != nullptr))) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    return (_return_value_.has_value ? InputFrame::from_cdata(std::shared_ptr<easyar_InputFrame>(_return_value_.value, [](easyar_InputFrame * ptr) { easyar_InputFrame__dtor(ptr); })) : std::optional<std::shared_ptr<InputFrame>>{});
}
_INLINE_SPECIFIER_ std::shared_ptr<InputFrame> InputFrame::createWithImageAndCameraParametersAndTemporal(std::shared_ptr<Image> image, std::shared_ptr<CameraParameters> cameraParameters, double timestamp)
{
    if (!(image != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: image");
#else
        std::terminate();
#endif
    }
    if (!(cameraParameters != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: cameraParameters");
#else
        std::terminate();
#endif
    }
    easyar_InputFrame * _return_value_;
    easyar_InputFrame_createWithImageAndCameraParametersAndTemporal(image->get_cdata().get(), cameraParameters->get_cdata().get(), timestamp, &_return_value_);
    if (!(_return_value_ != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    return InputFrame::from_cdata(std::shared_ptr<easyar_InputFrame>(_return_value_, [](easyar_InputFrame * ptr) { easyar_InputFrame__dtor(ptr); }));
}
_INLINE_SPECIFIER_ std::shared_ptr<InputFrame> InputFrame::createWithImageAndCameraParameters(std::shared_ptr<Image> image, std::shared_ptr<CameraParameters> cameraParameters)
{
    if (!(image != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: image");
#else
        std::terminate();
#endif
    }
    if (!(cameraParameters != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: cameraParameters");
#else
        std::terminate();
#endif
    }
    easyar_InputFrame * _return_value_;
    easyar_InputFrame_createWithImageAndCameraParameters(image->get_cdata().get(), cameraParameters->get_cdata().get(), &_return_value_);
    if (!(_return_value_ != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    return InputFrame::from_cdata(std::shared_ptr<easyar_InputFrame>(_return_value_, [](easyar_InputFrame * ptr) { easyar_InputFrame__dtor(ptr); }));
}
_INLINE_SPECIFIER_ std::shared_ptr<InputFrame> InputFrame::createWithImage(std::shared_ptr<Image> image)
{
    if (!(image != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: image");
#else
        std::terminate();
#endif
    }
    easyar_InputFrame * _return_value_;
    easyar_InputFrame_createWithImage(image->get_cdata().get(), &_return_value_);
    if (!(_return_value_ != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    return InputFrame::from_cdata(std::shared_ptr<easyar_InputFrame>(_return_value_, [](easyar_InputFrame * ptr) { easyar_InputFrame__dtor(ptr); }));
}

_INLINE_SPECIFIER_ FrameFilterResult::FrameFilterResult(std::shared_ptr<easyar_FrameFilterResult> cdata)
    :
    cdata_(nullptr)
{
    init_cdata(cdata);
}
_INLINE_SPECIFIER_ FrameFilterResult::~FrameFilterResult()
{
    cdata_ = nullptr;
}

_INLINE_SPECIFIER_ std::shared_ptr<easyar_FrameFilterResult> FrameFilterResult::get_cdata()
{
    return cdata_;
}
_INLINE_SPECIFIER_ void FrameFilterResult::init_cdata(std::shared_ptr<easyar_FrameFilterResult> cdata)
{
    cdata_ = cdata;
}
_INLINE_SPECIFIER_ std::shared_ptr<FrameFilterResult> FrameFilterResult::from_cdata(std::shared_ptr<easyar_FrameFilterResult> cdata)
{
    if (cdata == nullptr) {
        return nullptr;
    }
    std::string typeName = easyar_FrameFilterResult__typeName(cdata.get());
    if (typeName == "ObjectTrackerResult") {
        easyar_ObjectTrackerResult * st_cdata;
        easyar_tryCastFrameFilterResultToObjectTrackerResult(cdata.get(), &st_cdata);
        return std::static_pointer_cast<FrameFilterResult>(std::make_shared<ObjectTrackerResult>(std::shared_ptr<easyar_ObjectTrackerResult>(st_cdata, [](easyar_ObjectTrackerResult * ptr) { easyar_ObjectTrackerResult__dtor(ptr); })));
    }
    if (typeName == "MegaTrackerResult") {
        easyar_MegaTrackerResult * st_cdata;
        easyar_tryCastFrameFilterResultToMegaTrackerResult(cdata.get(), &st_cdata);
        return std::static_pointer_cast<FrameFilterResult>(std::make_shared<MegaTrackerResult>(std::shared_ptr<easyar_MegaTrackerResult>(st_cdata, [](easyar_MegaTrackerResult * ptr) { easyar_MegaTrackerResult__dtor(ptr); })));
    }
    if (typeName == "SurfaceTrackerResult") {
        easyar_SurfaceTrackerResult * st_cdata;
        easyar_tryCastFrameFilterResultToSurfaceTrackerResult(cdata.get(), &st_cdata);
        return std::static_pointer_cast<FrameFilterResult>(std::make_shared<SurfaceTrackerResult>(std::shared_ptr<easyar_SurfaceTrackerResult>(st_cdata, [](easyar_SurfaceTrackerResult * ptr) { easyar_SurfaceTrackerResult__dtor(ptr); })));
    }
    if (typeName == "ImageTrackerResult") {
        easyar_ImageTrackerResult * st_cdata;
        easyar_tryCastFrameFilterResultToImageTrackerResult(cdata.get(), &st_cdata);
        return std::static_pointer_cast<FrameFilterResult>(std::make_shared<ImageTrackerResult>(std::shared_ptr<easyar_ImageTrackerResult>(st_cdata, [](easyar_ImageTrackerResult * ptr) { easyar_ImageTrackerResult__dtor(ptr); })));
    }
    if (typeName == "SparseSpatialMapResult") {
        easyar_SparseSpatialMapResult * st_cdata;
        easyar_tryCastFrameFilterResultToSparseSpatialMapResult(cdata.get(), &st_cdata);
        return std::static_pointer_cast<FrameFilterResult>(std::make_shared<SparseSpatialMapResult>(std::shared_ptr<easyar_SparseSpatialMapResult>(st_cdata, [](easyar_SparseSpatialMapResult * ptr) { easyar_SparseSpatialMapResult__dtor(ptr); })));
    }
    if (typeName == "TargetTrackerResult") {
        easyar_TargetTrackerResult * st_cdata;
        easyar_tryCastFrameFilterResultToTargetTrackerResult(cdata.get(), &st_cdata);
        return std::static_pointer_cast<FrameFilterResult>(std::make_shared<TargetTrackerResult>(std::shared_ptr<easyar_TargetTrackerResult>(st_cdata, [](easyar_TargetTrackerResult * ptr) { easyar_TargetTrackerResult__dtor(ptr); })));
    }
    return std::make_shared<FrameFilterResult>(cdata);
}

_INLINE_SPECIFIER_ OutputFrame::OutputFrame(std::shared_ptr<easyar_OutputFrame> cdata)
    :
    cdata_(nullptr)
{
    init_cdata(cdata);
}
_INLINE_SPECIFIER_ OutputFrame::~OutputFrame()
{
    cdata_ = nullptr;
}

_INLINE_SPECIFIER_ std::shared_ptr<easyar_OutputFrame> OutputFrame::get_cdata()
{
    return cdata_;
}
_INLINE_SPECIFIER_ void OutputFrame::init_cdata(std::shared_ptr<easyar_OutputFrame> cdata)
{
    cdata_ = cdata;
}
_INLINE_SPECIFIER_ std::shared_ptr<OutputFrame> OutputFrame::from_cdata(std::shared_ptr<easyar_OutputFrame> cdata)
{
    if (cdata == nullptr) {
        return nullptr;
    }
    return std::make_shared<OutputFrame>(cdata);
}
_INLINE_SPECIFIER_ OutputFrame::OutputFrame(std::shared_ptr<InputFrame> inputFrame, std::vector<std::optional<std::shared_ptr<FrameFilterResult>>> results)
    :
    cdata_(nullptr)
{
    if (!(inputFrame != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: inputFrame");
#else
        std::terminate();
#endif
    }
    if (!easyar_ListOfOptionalOfFrameFilterResult_check_external_cpp(results)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: results");
#else
        std::terminate();
#endif
    }
    easyar_OutputFrame * _return_value_;
    easyar_OutputFrame__ctor(inputFrame->get_cdata().get(), std_vector_to_easyar_ListOfOptionalOfFrameFilterResult(results).get(), &_return_value_);
    if (!(_return_value_ != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    init_cdata(std::shared_ptr<easyar_OutputFrame>(_return_value_, [](easyar_OutputFrame * ptr) { easyar_OutputFrame__dtor(ptr); }));
}
_INLINE_SPECIFIER_ int OutputFrame::index()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_OutputFrame_index(this->cdata_.get());
    return _return_value_;
}
_INLINE_SPECIFIER_ std::shared_ptr<InputFrame> OutputFrame::inputFrame()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_InputFrame * _return_value_;
    easyar_OutputFrame_inputFrame(this->cdata_.get(), &_return_value_);
    if (!(_return_value_ != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    return InputFrame::from_cdata(std::shared_ptr<easyar_InputFrame>(_return_value_, [](easyar_InputFrame * ptr) { easyar_InputFrame__dtor(ptr); }));
}
_INLINE_SPECIFIER_ std::vector<std::optional<std::shared_ptr<FrameFilterResult>>> OutputFrame::results()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_ListOfOptionalOfFrameFilterResult * _return_value_;
    easyar_OutputFrame_results(this->cdata_.get(), &_return_value_);
    if (!(_return_value_ != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    return std_vector_from_easyar_ListOfOptionalOfFrameFilterResult(std::shared_ptr<easyar_ListOfOptionalOfFrameFilterResult>(_return_value_, [](easyar_ListOfOptionalOfFrameFilterResult * ptr) { easyar_ListOfOptionalOfFrameFilterResult__dtor(ptr); }));
}

_INLINE_SPECIFIER_ FeedbackFrame::FeedbackFrame(std::shared_ptr<easyar_FeedbackFrame> cdata)
    :
    cdata_(nullptr)
{
    init_cdata(cdata);
}
_INLINE_SPECIFIER_ FeedbackFrame::~FeedbackFrame()
{
    cdata_ = nullptr;
}

_INLINE_SPECIFIER_ std::shared_ptr<easyar_FeedbackFrame> FeedbackFrame::get_cdata()
{
    return cdata_;
}
_INLINE_SPECIFIER_ void FeedbackFrame::init_cdata(std::shared_ptr<easyar_FeedbackFrame> cdata)
{
    cdata_ = cdata;
}
_INLINE_SPECIFIER_ std::shared_ptr<FeedbackFrame> FeedbackFrame::from_cdata(std::shared_ptr<easyar_FeedbackFrame> cdata)
{
    if (cdata == nullptr) {
        return nullptr;
    }
    return std::make_shared<FeedbackFrame>(cdata);
}
_INLINE_SPECIFIER_ FeedbackFrame::FeedbackFrame(std::shared_ptr<InputFrame> inputFrame, std::optional<std::shared_ptr<OutputFrame>> previousOutputFrame)
    :
    cdata_(nullptr)
{
    if (!(inputFrame != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: inputFrame");
#else
        std::terminate();
#endif
    }
    if (!(!previousOutputFrame.has_value() || (previousOutputFrame.value() != nullptr))) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: previousOutputFrame");
#else
        std::terminate();
#endif
    }
    easyar_FeedbackFrame * _return_value_;
    easyar_FeedbackFrame__ctor(inputFrame->get_cdata().get(), (previousOutputFrame.has_value() ? easyar_OptionalOfOutputFrame{true, previousOutputFrame.value()->get_cdata().get()} : easyar_OptionalOfOutputFrame{false, {}}), &_return_value_);
    if (!(_return_value_ != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    init_cdata(std::shared_ptr<easyar_FeedbackFrame>(_return_value_, [](easyar_FeedbackFrame * ptr) { easyar_FeedbackFrame__dtor(ptr); }));
}
_INLINE_SPECIFIER_ std::shared_ptr<InputFrame> FeedbackFrame::inputFrame()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_InputFrame * _return_value_;
    easyar_FeedbackFrame_inputFrame(this->cdata_.get(), &_return_value_);
    if (!(_return_value_ != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    return InputFrame::from_cdata(std::shared_ptr<easyar_InputFrame>(_return_value_, [](easyar_InputFrame * ptr) { easyar_InputFrame__dtor(ptr); }));
}
_INLINE_SPECIFIER_ std::optional<std::shared_ptr<OutputFrame>> FeedbackFrame::previousOutputFrame()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_OptionalOfOutputFrame _return_value_;
    easyar_FeedbackFrame_previousOutputFrame(this->cdata_.get(), &_return_value_);
    if (!(!_return_value_.has_value || (_return_value_.value != nullptr))) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    return (_return_value_.has_value ? OutputFrame::from_cdata(std::shared_ptr<easyar_OutputFrame>(_return_value_.value, [](easyar_OutputFrame * ptr) { easyar_OutputFrame__dtor(ptr); })) : std::optional<std::shared_ptr<OutputFrame>>{});
}

_INLINE_SPECIFIER_ PoseUtility::PoseUtility(std::shared_ptr<easyar_PoseUtility> cdata)
    :
    cdata_(nullptr)
{
    init_cdata(cdata);
}
_INLINE_SPECIFIER_ PoseUtility::~PoseUtility()
{
    cdata_ = nullptr;
}

_INLINE_SPECIFIER_ std::shared_ptr<easyar_PoseUtility> PoseUtility::get_cdata()
{
    return cdata_;
}
_INLINE_SPECIFIER_ void PoseUtility::init_cdata(std::shared_ptr<easyar_PoseUtility> cdata)
{
    cdata_ = cdata;
}
_INLINE_SPECIFIER_ std::shared_ptr<PoseUtility> PoseUtility::from_cdata(std::shared_ptr<easyar_PoseUtility> cdata)
{
    if (cdata == nullptr) {
        return nullptr;
    }
    return std::make_shared<PoseUtility>(cdata);
}
_INLINE_SPECIFIER_ std::optional<Matrix44F> PoseUtility::createPoseWithHardwareOffset(Vec3F position, Vec4F rotation, std::optional<Vec3F> offsetPosition, std::optional<Vec4F> offsetRotation)
{
    auto _return_value_ = easyar_PoseUtility_createPoseWithHardwareOffset(easyar_Vec3F{{position.data[0], position.data[1], position.data[2]}}, easyar_Vec4F{{rotation.data[0], rotation.data[1], rotation.data[2], rotation.data[3]}}, (offsetPosition.has_value() ? easyar_OptionalOfVec3F{true, easyar_Vec3F{{offsetPosition.value().data[0], offsetPosition.value().data[1], offsetPosition.value().data[2]}}} : easyar_OptionalOfVec3F{false, {}}), (offsetRotation.has_value() ? easyar_OptionalOfVec4F{true, easyar_Vec4F{{offsetRotation.value().data[0], offsetRotation.value().data[1], offsetRotation.value().data[2], offsetRotation.value().data[3]}}} : easyar_OptionalOfVec4F{false, {}}));
    return (_return_value_.has_value ? Matrix44F{{{_return_value_.value.data[0], _return_value_.value.data[1], _return_value_.value.data[2], _return_value_.value.data[3], _return_value_.value.data[4], _return_value_.value.data[5], _return_value_.value.data[6], _return_value_.value.data[7], _return_value_.value.data[8], _return_value_.value.data[9], _return_value_.value.data[10], _return_value_.value.data[11], _return_value_.value.data[12], _return_value_.value.data[13], _return_value_.value.data[14], _return_value_.value.data[15]}}} : std::optional<Matrix44F>{});
}

_INLINE_SPECIFIER_ Target::Target(std::shared_ptr<easyar_Target> cdata)
    :
    cdata_(nullptr)
{
    init_cdata(cdata);
}
_INLINE_SPECIFIER_ Target::~Target()
{
    cdata_ = nullptr;
}

_INLINE_SPECIFIER_ std::shared_ptr<easyar_Target> Target::get_cdata()
{
    return cdata_;
}
_INLINE_SPECIFIER_ void Target::init_cdata(std::shared_ptr<easyar_Target> cdata)
{
    cdata_ = cdata;
}
_INLINE_SPECIFIER_ std::shared_ptr<Target> Target::from_cdata(std::shared_ptr<easyar_Target> cdata)
{
    if (cdata == nullptr) {
        return nullptr;
    }
    std::string typeName = easyar_Target__typeName(cdata.get());
    if (typeName == "ObjectTarget") {
        easyar_ObjectTarget * st_cdata;
        easyar_tryCastTargetToObjectTarget(cdata.get(), &st_cdata);
        return std::static_pointer_cast<Target>(std::make_shared<ObjectTarget>(std::shared_ptr<easyar_ObjectTarget>(st_cdata, [](easyar_ObjectTarget * ptr) { easyar_ObjectTarget__dtor(ptr); })));
    }
    if (typeName == "ImageTarget") {
        easyar_ImageTarget * st_cdata;
        easyar_tryCastTargetToImageTarget(cdata.get(), &st_cdata);
        return std::static_pointer_cast<Target>(std::make_shared<ImageTarget>(std::shared_ptr<easyar_ImageTarget>(st_cdata, [](easyar_ImageTarget * ptr) { easyar_ImageTarget__dtor(ptr); })));
    }
    return std::make_shared<Target>(cdata);
}
_INLINE_SPECIFIER_ int Target::runtimeID()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_Target_runtimeID(this->cdata_.get());
    return _return_value_;
}
_INLINE_SPECIFIER_ std::string Target::uid()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_String * _return_value_;
    easyar_Target_uid(this->cdata_.get(), &_return_value_);
    if (!(_return_value_ != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    return std_string_from_easyar_String(std::shared_ptr<easyar_String>(_return_value_, [](easyar_String * ptr) { easyar_String__dtor(ptr); }));
}
_INLINE_SPECIFIER_ std::string Target::name()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_String * _return_value_;
    easyar_Target_name(this->cdata_.get(), &_return_value_);
    if (!(_return_value_ != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    return std_string_from_easyar_String(std::shared_ptr<easyar_String>(_return_value_, [](easyar_String * ptr) { easyar_String__dtor(ptr); }));
}
_INLINE_SPECIFIER_ void Target::setName(std::string name)
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_Target_setName(this->cdata_.get(), std_string_to_easyar_String(name).get());
}
_INLINE_SPECIFIER_ std::string Target::meta()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_String * _return_value_;
    easyar_Target_meta(this->cdata_.get(), &_return_value_);
    if (!(_return_value_ != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    return std_string_from_easyar_String(std::shared_ptr<easyar_String>(_return_value_, [](easyar_String * ptr) { easyar_String__dtor(ptr); }));
}
_INLINE_SPECIFIER_ void Target::setMeta(std::string data)
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_Target_setMeta(this->cdata_.get(), std_string_to_easyar_String(data).get());
}

_INLINE_SPECIFIER_ TargetInstance::TargetInstance(std::shared_ptr<easyar_TargetInstance> cdata)
    :
    cdata_(nullptr)
{
    init_cdata(cdata);
}
_INLINE_SPECIFIER_ TargetInstance::~TargetInstance()
{
    cdata_ = nullptr;
}

_INLINE_SPECIFIER_ std::shared_ptr<easyar_TargetInstance> TargetInstance::get_cdata()
{
    return cdata_;
}
_INLINE_SPECIFIER_ void TargetInstance::init_cdata(std::shared_ptr<easyar_TargetInstance> cdata)
{
    cdata_ = cdata;
}
_INLINE_SPECIFIER_ std::shared_ptr<TargetInstance> TargetInstance::from_cdata(std::shared_ptr<easyar_TargetInstance> cdata)
{
    if (cdata == nullptr) {
        return nullptr;
    }
    return std::make_shared<TargetInstance>(cdata);
}
_INLINE_SPECIFIER_ TargetStatus TargetInstance::status()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_TargetInstance_status(this->cdata_.get());
    return static_cast<TargetStatus>(_return_value_);
}
_INLINE_SPECIFIER_ std::shared_ptr<Target> TargetInstance::target()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_Target * _return_value_;
    easyar_TargetInstance_target(this->cdata_.get(), &_return_value_);
    if (!(_return_value_ != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    return Target::from_cdata(std::shared_ptr<easyar_Target>(_return_value_, [](easyar_Target * ptr) { easyar_Target__dtor(ptr); }));
}
_INLINE_SPECIFIER_ Matrix44F TargetInstance::pose()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_TargetInstance_pose(this->cdata_.get());
    return Matrix44F{{{_return_value_.data[0], _return_value_.data[1], _return_value_.data[2], _return_value_.data[3], _return_value_.data[4], _return_value_.data[5], _return_value_.data[6], _return_value_.data[7], _return_value_.data[8], _return_value_.data[9], _return_value_.data[10], _return_value_.data[11], _return_value_.data[12], _return_value_.data[13], _return_value_.data[14], _return_value_.data[15]}}};
}

_INLINE_SPECIFIER_ TargetTrackerResult::TargetTrackerResult(std::shared_ptr<easyar_TargetTrackerResult> cdata)
    :
    FrameFilterResult(std::shared_ptr<easyar_FrameFilterResult>(nullptr)),
    cdata_(nullptr)
{
    init_cdata(cdata);
}
_INLINE_SPECIFIER_ TargetTrackerResult::~TargetTrackerResult()
{
    cdata_ = nullptr;
}

_INLINE_SPECIFIER_ std::shared_ptr<easyar_TargetTrackerResult> TargetTrackerResult::get_cdata()
{
    return cdata_;
}
_INLINE_SPECIFIER_ void TargetTrackerResult::init_cdata(std::shared_ptr<easyar_TargetTrackerResult> cdata)
{
    cdata_ = cdata;
    {
        easyar_FrameFilterResult * ptr = nullptr;
        easyar_castTargetTrackerResultToFrameFilterResult(cdata_.get(), &ptr);
        FrameFilterResult::init_cdata(std::shared_ptr<easyar_FrameFilterResult>(ptr, [](easyar_FrameFilterResult * ptr) { easyar_FrameFilterResult__dtor(ptr); }));
    }
}
_INLINE_SPECIFIER_ std::shared_ptr<TargetTrackerResult> TargetTrackerResult::from_cdata(std::shared_ptr<easyar_TargetTrackerResult> cdata)
{
    if (cdata == nullptr) {
        return nullptr;
    }
    std::string typeName = easyar_TargetTrackerResult__typeName(cdata.get());
    if (typeName == "ObjectTrackerResult") {
        easyar_ObjectTrackerResult * st_cdata;
        easyar_tryCastTargetTrackerResultToObjectTrackerResult(cdata.get(), &st_cdata);
        return std::static_pointer_cast<TargetTrackerResult>(std::make_shared<ObjectTrackerResult>(std::shared_ptr<easyar_ObjectTrackerResult>(st_cdata, [](easyar_ObjectTrackerResult * ptr) { easyar_ObjectTrackerResult__dtor(ptr); })));
    }
    if (typeName == "ImageTrackerResult") {
        easyar_ImageTrackerResult * st_cdata;
        easyar_tryCastTargetTrackerResultToImageTrackerResult(cdata.get(), &st_cdata);
        return std::static_pointer_cast<TargetTrackerResult>(std::make_shared<ImageTrackerResult>(std::shared_ptr<easyar_ImageTrackerResult>(st_cdata, [](easyar_ImageTrackerResult * ptr) { easyar_ImageTrackerResult__dtor(ptr); })));
    }
    return std::make_shared<TargetTrackerResult>(cdata);
}
_INLINE_SPECIFIER_ std::vector<std::shared_ptr<TargetInstance>> TargetTrackerResult::targetInstances()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    easyar_ListOfTargetInstance * _return_value_;
    easyar_TargetTrackerResult_targetInstances(this->cdata_.get(), &_return_value_);
    if (!(_return_value_ != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    return std_vector_from_easyar_ListOfTargetInstance(std::shared_ptr<easyar_ListOfTargetInstance>(_return_value_, [](easyar_ListOfTargetInstance * ptr) { easyar_ListOfTargetInstance__dtor(ptr); }));
}
_INLINE_SPECIFIER_ void TargetTrackerResult::setTargetInstances(std::vector<std::shared_ptr<TargetInstance>> instances)
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    if (!easyar_ListOfTargetInstance_check_external_cpp(instances)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: instances");
#else
        std::terminate();
#endif
    }
    easyar_TargetTrackerResult_setTargetInstances(this->cdata_.get(), std_vector_to_easyar_ListOfTargetInstance(instances).get());
}

_INLINE_SPECIFIER_ TextureId::TextureId(std::shared_ptr<easyar_TextureId> cdata)
    :
    cdata_(nullptr)
{
    init_cdata(cdata);
}
_INLINE_SPECIFIER_ TextureId::~TextureId()
{
    cdata_ = nullptr;
}

_INLINE_SPECIFIER_ std::shared_ptr<easyar_TextureId> TextureId::get_cdata()
{
    return cdata_;
}
_INLINE_SPECIFIER_ void TextureId::init_cdata(std::shared_ptr<easyar_TextureId> cdata)
{
    cdata_ = cdata;
}
_INLINE_SPECIFIER_ std::shared_ptr<TextureId> TextureId::from_cdata(std::shared_ptr<easyar_TextureId> cdata)
{
    if (cdata == nullptr) {
        return nullptr;
    }
    return std::make_shared<TextureId>(cdata);
}
_INLINE_SPECIFIER_ int TextureId::getInt()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_TextureId_getInt(this->cdata_.get());
    return _return_value_;
}
_INLINE_SPECIFIER_ void * TextureId::getPointer()
{
    if (this->cdata_ == nullptr) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidArgument: this");
#else
        std::terminate();
#endif
    }
    auto _return_value_ = easyar_TextureId_getPointer(this->cdata_.get());
    return _return_value_;
}
_INLINE_SPECIFIER_ std::shared_ptr<TextureId> TextureId::fromInt(int _value)
{
    easyar_TextureId * _return_value_;
    easyar_TextureId_fromInt(_value, &_return_value_);
    if (!(_return_value_ != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    return TextureId::from_cdata(std::shared_ptr<easyar_TextureId>(_return_value_, [](easyar_TextureId * ptr) { easyar_TextureId__dtor(ptr); }));
}
_INLINE_SPECIFIER_ std::shared_ptr<TextureId> TextureId::fromPointer(void * ptr)
{
    easyar_TextureId * _return_value_;
    easyar_TextureId_fromPointer(ptr, &_return_value_);
    if (!(_return_value_ != nullptr)) {
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
        throw std::runtime_error("InvalidReturnValue");
#else
        std::terminate();
#endif
    }
    return TextureId::from_cdata(std::shared_ptr<easyar_TextureId>(_return_value_, [](easyar_TextureId * ptr) { easyar_TextureId__dtor(ptr); }));
}

static void FunctorOfVoid_func(void * _state, /* OUT */ easyar_String * * _exception)
{
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
    *_exception = nullptr;
    try {
#endif
        auto f = reinterpret_cast<std::function<void()> *>(_state);
        (*f)();
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
    } catch (std::exception & ex) {
#   if defined(_EASYAR_EXCEPTION_MODE_NORTTI_)
        auto message = std::string() + "Unknown std::exception\n" + ex.what();
#   else
        auto message = std::string() + typeid(*(&ex)).name() + "\n" + ex.what();
#   endif
        easyar_String_from_utf8_begin(message.c_str(), _exception);
    }
#endif
}
static void FunctorOfVoid_destroy(void * _state)
{
    auto f = reinterpret_cast<std::function<void()> *>(_state);
    delete f;
}
static inline easyar_FunctorOfVoid FunctorOfVoid_to_c(std::function<void()> f)
{
    return easyar_FunctorOfVoid{new std::function<void()>(f), FunctorOfVoid_func, FunctorOfVoid_destroy};
}

static inline std::shared_ptr<easyar_ListOfVec3F> std_vector_to_easyar_ListOfVec3F(std::vector<Vec3F> l)
{
    std::vector<easyar_Vec3F> values;
    values.reserve(l.size());
    for (auto v : l) {
        easyar_Vec3F cv;
        cv = easyar_Vec3F{{v.data[0], v.data[1], v.data[2]}};
        values.push_back(cv);
    }
    easyar_ListOfVec3F * ptr;
    easyar_ListOfVec3F__ctor(values.data(), values.data() + values.size(), &ptr);
    return std::shared_ptr<easyar_ListOfVec3F>(ptr, [](easyar_ListOfVec3F * ptr) { easyar_ListOfVec3F__dtor(ptr); });
}
static inline std::vector<Vec3F> std_vector_from_easyar_ListOfVec3F(std::shared_ptr<easyar_ListOfVec3F> pl)
{
    auto size = easyar_ListOfVec3F_size(pl.get());
    std::vector<Vec3F> values;
    values.reserve(size);
    for (int k = 0; k < size; k += 1) {
        auto v = easyar_ListOfVec3F_at(pl.get(), k);
        values.push_back(Vec3F{{{v.data[0], v.data[1], v.data[2]}}});
    }
    return values;
}
static inline bool easyar_ListOfVec3F_check_external_cpp(const std::vector<Vec3F> & l)
{
    return true;
}

static inline std::shared_ptr<easyar_ListOfTargetInstance> std_vector_to_easyar_ListOfTargetInstance(std::vector<std::shared_ptr<TargetInstance>> l)
{
    std::vector<easyar_TargetInstance *> values;
    values.reserve(l.size());
    for (auto v : l) {
        easyar_TargetInstance * cv;
        easyar_TargetInstance__retain(v->get_cdata().get(), &cv);
        values.push_back(cv);
    }
    easyar_ListOfTargetInstance * ptr;
    easyar_ListOfTargetInstance__ctor(values.data(), values.data() + values.size(), &ptr);
    return std::shared_ptr<easyar_ListOfTargetInstance>(ptr, [](easyar_ListOfTargetInstance * ptr) { easyar_ListOfTargetInstance__dtor(ptr); });
}
static inline std::vector<std::shared_ptr<TargetInstance>> std_vector_from_easyar_ListOfTargetInstance(std::shared_ptr<easyar_ListOfTargetInstance> pl)
{
    auto size = easyar_ListOfTargetInstance_size(pl.get());
    std::vector<std::shared_ptr<TargetInstance>> values;
    values.reserve(size);
    for (int k = 0; k < size; k += 1) {
        auto v = easyar_ListOfTargetInstance_at(pl.get(), k);
        easyar_TargetInstance__retain(v, &v);
        values.push_back(TargetInstance::from_cdata(std::shared_ptr<easyar_TargetInstance>(v, [](easyar_TargetInstance * ptr) { easyar_TargetInstance__dtor(ptr); })));
    }
    return values;
}
static inline bool easyar_ListOfTargetInstance_check_external_cpp(const std::vector<std::shared_ptr<TargetInstance>> & l)
{
    for (auto e : l) {
        if (!(e != nullptr)) { return false; }
    }
    return true;
}

static inline std::shared_ptr<easyar_ListOfFloat> std_vector_to_easyar_ListOfFloat(std::vector<float> l)
{
    std::vector<float> values;
    values.reserve(l.size());
    for (auto v : l) {
        float cv;
        cv = v;
        values.push_back(cv);
    }
    easyar_ListOfFloat * ptr;
    easyar_ListOfFloat__ctor(values.data(), values.data() + values.size(), &ptr);
    return std::shared_ptr<easyar_ListOfFloat>(ptr, [](easyar_ListOfFloat * ptr) { easyar_ListOfFloat__dtor(ptr); });
}
static inline std::vector<float> std_vector_from_easyar_ListOfFloat(std::shared_ptr<easyar_ListOfFloat> pl)
{
    auto size = easyar_ListOfFloat_size(pl.get());
    std::vector<float> values;
    values.reserve(size);
    for (int k = 0; k < size; k += 1) {
        auto v = easyar_ListOfFloat_at(pl.get(), k);
        values.push_back(v);
    }
    return values;
}
static inline bool easyar_ListOfFloat_check_external_cpp(const std::vector<float> & l)
{
    return true;
}

static inline std::shared_ptr<easyar_ListOfOptionalOfFrameFilterResult> std_vector_to_easyar_ListOfOptionalOfFrameFilterResult(std::vector<std::optional<std::shared_ptr<FrameFilterResult>>> l)
{
    std::vector<easyar_OptionalOfFrameFilterResult> values;
    values.reserve(l.size());
    for (auto v : l) {
        easyar_OptionalOfFrameFilterResult cv;
        cv.has_value = (v.has_value() ? easyar_OptionalOfFrameFilterResult{true, v.value()->get_cdata().get()} : easyar_OptionalOfFrameFilterResult{false, {}}).has_value;
        if ((v.has_value() ? easyar_OptionalOfFrameFilterResult{true, v.value()->get_cdata().get()} : easyar_OptionalOfFrameFilterResult{false, {}}).has_value) {
            easyar_FrameFilterResult__retain((v.has_value() ? easyar_OptionalOfFrameFilterResult{true, v.value()->get_cdata().get()} : easyar_OptionalOfFrameFilterResult{false, {}}).value, &cv.value);
        }
        values.push_back(cv);
    }
    easyar_ListOfOptionalOfFrameFilterResult * ptr;
    easyar_ListOfOptionalOfFrameFilterResult__ctor(values.data(), values.data() + values.size(), &ptr);
    return std::shared_ptr<easyar_ListOfOptionalOfFrameFilterResult>(ptr, [](easyar_ListOfOptionalOfFrameFilterResult * ptr) { easyar_ListOfOptionalOfFrameFilterResult__dtor(ptr); });
}
static inline std::vector<std::optional<std::shared_ptr<FrameFilterResult>>> std_vector_from_easyar_ListOfOptionalOfFrameFilterResult(std::shared_ptr<easyar_ListOfOptionalOfFrameFilterResult> pl)
{
    auto size = easyar_ListOfOptionalOfFrameFilterResult_size(pl.get());
    std::vector<std::optional<std::shared_ptr<FrameFilterResult>>> values;
    values.reserve(size);
    for (int k = 0; k < size; k += 1) {
        auto v = easyar_ListOfOptionalOfFrameFilterResult_at(pl.get(), k);
        if (v.has_value) {
            easyar_FrameFilterResult__retain(v.value, &v.value);
        }
        values.push_back((v.has_value ? FrameFilterResult::from_cdata(std::shared_ptr<easyar_FrameFilterResult>(v.value, [](easyar_FrameFilterResult * ptr) { easyar_FrameFilterResult__dtor(ptr); })) : std::optional<std::shared_ptr<FrameFilterResult>>{}));
    }
    return values;
}
static inline bool easyar_ListOfOptionalOfFrameFilterResult_check_external_cpp(const std::vector<std::optional<std::shared_ptr<FrameFilterResult>>> & l)
{
    for (auto e : l) {
        if (!(!e.has_value() || (e.value() != nullptr))) { return false; }
    }
    return true;
}

static void FunctorOfVoidFromOutputFrame_func(void * _state, easyar_OutputFrame * arg0, /* OUT */ easyar_String * * _exception)
{
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
    *_exception = nullptr;
    try {
#endif
        easyar_OutputFrame__retain(arg0, &arg0);
        std::shared_ptr<OutputFrame> cpparg0 = OutputFrame::from_cdata(std::shared_ptr<easyar_OutputFrame>(arg0, [](easyar_OutputFrame * ptr) { easyar_OutputFrame__dtor(ptr); }));
        auto f = reinterpret_cast<std::function<void(std::shared_ptr<OutputFrame>)> *>(_state);
        (*f)(cpparg0);
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
    } catch (std::exception & ex) {
#   if defined(_EASYAR_EXCEPTION_MODE_NORTTI_)
        auto message = std::string() + "Unknown std::exception\n" + ex.what();
#   else
        auto message = std::string() + typeid(*(&ex)).name() + "\n" + ex.what();
#   endif
        easyar_String_from_utf8_begin(message.c_str(), _exception);
    }
#endif
}
static void FunctorOfVoidFromOutputFrame_destroy(void * _state)
{
    auto f = reinterpret_cast<std::function<void(std::shared_ptr<OutputFrame>)> *>(_state);
    delete f;
}
static inline easyar_FunctorOfVoidFromOutputFrame FunctorOfVoidFromOutputFrame_to_c(std::function<void(std::shared_ptr<OutputFrame>)> f)
{
    return easyar_FunctorOfVoidFromOutputFrame{new std::function<void(std::shared_ptr<OutputFrame>)>(f), FunctorOfVoidFromOutputFrame_func, FunctorOfVoidFromOutputFrame_destroy};
}

static void FunctorOfVoidFromTargetAndBool_func(void * _state, easyar_Target * arg0, bool arg1, /* OUT */ easyar_String * * _exception)
{
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
    *_exception = nullptr;
    try {
#endif
        easyar_Target__retain(arg0, &arg0);
        std::shared_ptr<Target> cpparg0 = Target::from_cdata(std::shared_ptr<easyar_Target>(arg0, [](easyar_Target * ptr) { easyar_Target__dtor(ptr); }));
        bool cpparg1 = arg1;
        auto f = reinterpret_cast<std::function<void(std::shared_ptr<Target>, bool)> *>(_state);
        (*f)(cpparg0, cpparg1);
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
    } catch (std::exception & ex) {
#   if defined(_EASYAR_EXCEPTION_MODE_NORTTI_)
        auto message = std::string() + "Unknown std::exception\n" + ex.what();
#   else
        auto message = std::string() + typeid(*(&ex)).name() + "\n" + ex.what();
#   endif
        easyar_String_from_utf8_begin(message.c_str(), _exception);
    }
#endif
}
static void FunctorOfVoidFromTargetAndBool_destroy(void * _state)
{
    auto f = reinterpret_cast<std::function<void(std::shared_ptr<Target>, bool)> *>(_state);
    delete f;
}
static inline easyar_FunctorOfVoidFromTargetAndBool FunctorOfVoidFromTargetAndBool_to_c(std::function<void(std::shared_ptr<Target>, bool)> f)
{
    return easyar_FunctorOfVoidFromTargetAndBool{new std::function<void(std::shared_ptr<Target>, bool)>(f), FunctorOfVoidFromTargetAndBool_func, FunctorOfVoidFromTargetAndBool_destroy};
}

static inline std::shared_ptr<easyar_ListOfTarget> std_vector_to_easyar_ListOfTarget(std::vector<std::shared_ptr<Target>> l)
{
    std::vector<easyar_Target *> values;
    values.reserve(l.size());
    for (auto v : l) {
        easyar_Target * cv;
        easyar_Target__retain(v->get_cdata().get(), &cv);
        values.push_back(cv);
    }
    easyar_ListOfTarget * ptr;
    easyar_ListOfTarget__ctor(values.data(), values.data() + values.size(), &ptr);
    return std::shared_ptr<easyar_ListOfTarget>(ptr, [](easyar_ListOfTarget * ptr) { easyar_ListOfTarget__dtor(ptr); });
}
static inline std::vector<std::shared_ptr<Target>> std_vector_from_easyar_ListOfTarget(std::shared_ptr<easyar_ListOfTarget> pl)
{
    auto size = easyar_ListOfTarget_size(pl.get());
    std::vector<std::shared_ptr<Target>> values;
    values.reserve(size);
    for (int k = 0; k < size; k += 1) {
        auto v = easyar_ListOfTarget_at(pl.get(), k);
        easyar_Target__retain(v, &v);
        values.push_back(Target::from_cdata(std::shared_ptr<easyar_Target>(v, [](easyar_Target * ptr) { easyar_Target__dtor(ptr); })));
    }
    return values;
}
static inline bool easyar_ListOfTarget_check_external_cpp(const std::vector<std::shared_ptr<Target>> & l)
{
    for (auto e : l) {
        if (!(e != nullptr)) { return false; }
    }
    return true;
}

static void FunctorOfVoidFromARCoreDeviceListDownloadStatusAndOptionalOfString_func(void * _state, easyar_ARCoreDeviceListDownloadStatus arg0, easyar_OptionalOfString arg1, /* OUT */ easyar_String * * _exception)
{
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
    *_exception = nullptr;
    try {
#endif
        ARCoreDeviceListDownloadStatus cpparg0 = static_cast<ARCoreDeviceListDownloadStatus>(arg0);
        if (arg1.has_value) {
            easyar_String_copy(arg1.value, &arg1.value);
        }
        std::optional<std::string> cpparg1 = (arg1.has_value ? std_string_from_easyar_String(std::shared_ptr<easyar_String>(arg1.value, [](easyar_String * ptr) { easyar_String__dtor(ptr); })) : std::optional<std::string>{});
        auto f = reinterpret_cast<std::function<void(ARCoreDeviceListDownloadStatus, std::optional<std::string>)> *>(_state);
        (*f)(cpparg0, cpparg1);
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
    } catch (std::exception & ex) {
#   if defined(_EASYAR_EXCEPTION_MODE_NORTTI_)
        auto message = std::string() + "Unknown std::exception\n" + ex.what();
#   else
        auto message = std::string() + typeid(*(&ex)).name() + "\n" + ex.what();
#   endif
        easyar_String_from_utf8_begin(message.c_str(), _exception);
    }
#endif
}
static void FunctorOfVoidFromARCoreDeviceListDownloadStatusAndOptionalOfString_destroy(void * _state)
{
    auto f = reinterpret_cast<std::function<void(ARCoreDeviceListDownloadStatus, std::optional<std::string>)> *>(_state);
    delete f;
}
static inline easyar_FunctorOfVoidFromARCoreDeviceListDownloadStatusAndOptionalOfString FunctorOfVoidFromARCoreDeviceListDownloadStatusAndOptionalOfString_to_c(std::function<void(ARCoreDeviceListDownloadStatus, std::optional<std::string>)> f)
{
    return easyar_FunctorOfVoidFromARCoreDeviceListDownloadStatusAndOptionalOfString{new std::function<void(ARCoreDeviceListDownloadStatus, std::optional<std::string>)>(f), FunctorOfVoidFromARCoreDeviceListDownloadStatusAndOptionalOfString_func, FunctorOfVoidFromARCoreDeviceListDownloadStatusAndOptionalOfString_destroy};
}

static void FunctorOfVoidFromCalibrationDownloadStatusAndOptionalOfString_func(void * _state, easyar_CalibrationDownloadStatus arg0, easyar_OptionalOfString arg1, /* OUT */ easyar_String * * _exception)
{
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
    *_exception = nullptr;
    try {
#endif
        CalibrationDownloadStatus cpparg0 = static_cast<CalibrationDownloadStatus>(arg0);
        if (arg1.has_value) {
            easyar_String_copy(arg1.value, &arg1.value);
        }
        std::optional<std::string> cpparg1 = (arg1.has_value ? std_string_from_easyar_String(std::shared_ptr<easyar_String>(arg1.value, [](easyar_String * ptr) { easyar_String__dtor(ptr); })) : std::optional<std::string>{});
        auto f = reinterpret_cast<std::function<void(CalibrationDownloadStatus, std::optional<std::string>)> *>(_state);
        (*f)(cpparg0, cpparg1);
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
    } catch (std::exception & ex) {
#   if defined(_EASYAR_EXCEPTION_MODE_NORTTI_)
        auto message = std::string() + "Unknown std::exception\n" + ex.what();
#   else
        auto message = std::string() + typeid(*(&ex)).name() + "\n" + ex.what();
#   endif
        easyar_String_from_utf8_begin(message.c_str(), _exception);
    }
#endif
}
static void FunctorOfVoidFromCalibrationDownloadStatusAndOptionalOfString_destroy(void * _state)
{
    auto f = reinterpret_cast<std::function<void(CalibrationDownloadStatus, std::optional<std::string>)> *>(_state);
    delete f;
}
static inline easyar_FunctorOfVoidFromCalibrationDownloadStatusAndOptionalOfString FunctorOfVoidFromCalibrationDownloadStatusAndOptionalOfString_to_c(std::function<void(CalibrationDownloadStatus, std::optional<std::string>)> f)
{
    return easyar_FunctorOfVoidFromCalibrationDownloadStatusAndOptionalOfString{new std::function<void(CalibrationDownloadStatus, std::optional<std::string>)>(f), FunctorOfVoidFromCalibrationDownloadStatusAndOptionalOfString_func, FunctorOfVoidFromCalibrationDownloadStatusAndOptionalOfString_destroy};
}

static inline std::shared_ptr<easyar_ListOfCloudLocalizerBlockInstance> std_vector_to_easyar_ListOfCloudLocalizerBlockInstance(std::vector<std::shared_ptr<CloudLocalizerBlockInstance>> l)
{
    std::vector<easyar_CloudLocalizerBlockInstance *> values;
    values.reserve(l.size());
    for (auto v : l) {
        easyar_CloudLocalizerBlockInstance * cv;
        easyar_CloudLocalizerBlockInstance__retain(v->get_cdata().get(), &cv);
        values.push_back(cv);
    }
    easyar_ListOfCloudLocalizerBlockInstance * ptr;
    easyar_ListOfCloudLocalizerBlockInstance__ctor(values.data(), values.data() + values.size(), &ptr);
    return std::shared_ptr<easyar_ListOfCloudLocalizerBlockInstance>(ptr, [](easyar_ListOfCloudLocalizerBlockInstance * ptr) { easyar_ListOfCloudLocalizerBlockInstance__dtor(ptr); });
}
static inline std::vector<std::shared_ptr<CloudLocalizerBlockInstance>> std_vector_from_easyar_ListOfCloudLocalizerBlockInstance(std::shared_ptr<easyar_ListOfCloudLocalizerBlockInstance> pl)
{
    auto size = easyar_ListOfCloudLocalizerBlockInstance_size(pl.get());
    std::vector<std::shared_ptr<CloudLocalizerBlockInstance>> values;
    values.reserve(size);
    for (int k = 0; k < size; k += 1) {
        auto v = easyar_ListOfCloudLocalizerBlockInstance_at(pl.get(), k);
        easyar_CloudLocalizerBlockInstance__retain(v, &v);
        values.push_back(CloudLocalizerBlockInstance::from_cdata(std::shared_ptr<easyar_CloudLocalizerBlockInstance>(v, [](easyar_CloudLocalizerBlockInstance * ptr) { easyar_CloudLocalizerBlockInstance__dtor(ptr); })));
    }
    return values;
}
static inline bool easyar_ListOfCloudLocalizerBlockInstance_check_external_cpp(const std::vector<std::shared_ptr<CloudLocalizerBlockInstance>> & l)
{
    for (auto e : l) {
        if (!(e != nullptr)) { return false; }
    }
    return true;
}

static inline std::shared_ptr<easyar_ListOfString> std_vector_to_easyar_ListOfString(std::vector<std::string> l)
{
    std::vector<easyar_String *> values;
    values.reserve(l.size());
    for (auto v : l) {
        easyar_String * cv;
        easyar_String_copy(std_string_to_easyar_String(v).get(), &cv);
        values.push_back(cv);
    }
    easyar_ListOfString * ptr;
    easyar_ListOfString__ctor(values.data(), values.data() + values.size(), &ptr);
    return std::shared_ptr<easyar_ListOfString>(ptr, [](easyar_ListOfString * ptr) { easyar_ListOfString__dtor(ptr); });
}
static inline std::vector<std::string> std_vector_from_easyar_ListOfString(std::shared_ptr<easyar_ListOfString> pl)
{
    auto size = easyar_ListOfString_size(pl.get());
    std::vector<std::string> values;
    values.reserve(size);
    for (int k = 0; k < size; k += 1) {
        auto v = easyar_ListOfString_at(pl.get(), k);
        easyar_String_copy(v, &v);
        values.push_back(std_string_from_easyar_String(std::shared_ptr<easyar_String>(v, [](easyar_String * ptr) { easyar_String__dtor(ptr); })));
    }
    return values;
}
static inline bool easyar_ListOfString_check_external_cpp(const std::vector<std::string> & l)
{
    return true;
}

static void FunctorOfVoidFromCloudLocalizerResult_func(void * _state, easyar_CloudLocalizerResult * arg0, /* OUT */ easyar_String * * _exception)
{
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
    *_exception = nullptr;
    try {
#endif
        easyar_CloudLocalizerResult__retain(arg0, &arg0);
        std::shared_ptr<CloudLocalizerResult> cpparg0 = CloudLocalizerResult::from_cdata(std::shared_ptr<easyar_CloudLocalizerResult>(arg0, [](easyar_CloudLocalizerResult * ptr) { easyar_CloudLocalizerResult__dtor(ptr); }));
        auto f = reinterpret_cast<std::function<void(std::shared_ptr<CloudLocalizerResult>)> *>(_state);
        (*f)(cpparg0);
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
    } catch (std::exception & ex) {
#   if defined(_EASYAR_EXCEPTION_MODE_NORTTI_)
        auto message = std::string() + "Unknown std::exception\n" + ex.what();
#   else
        auto message = std::string() + typeid(*(&ex)).name() + "\n" + ex.what();
#   endif
        easyar_String_from_utf8_begin(message.c_str(), _exception);
    }
#endif
}
static void FunctorOfVoidFromCloudLocalizerResult_destroy(void * _state)
{
    auto f = reinterpret_cast<std::function<void(std::shared_ptr<CloudLocalizerResult>)> *>(_state);
    delete f;
}
static inline easyar_FunctorOfVoidFromCloudLocalizerResult FunctorOfVoidFromCloudLocalizerResult_to_c(std::function<void(std::shared_ptr<CloudLocalizerResult>)> f)
{
    return easyar_FunctorOfVoidFromCloudLocalizerResult{new std::function<void(std::shared_ptr<CloudLocalizerResult>)>(f), FunctorOfVoidFromCloudLocalizerResult_func, FunctorOfVoidFromCloudLocalizerResult_destroy};
}

static void FunctorOfVoidFromMegaLandmarkFilterResult_func(void * _state, easyar_MegaLandmarkFilterResult * arg0, /* OUT */ easyar_String * * _exception)
{
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
    *_exception = nullptr;
    try {
#endif
        easyar_MegaLandmarkFilterResult__retain(arg0, &arg0);
        std::shared_ptr<MegaLandmarkFilterResult> cpparg0 = MegaLandmarkFilterResult::from_cdata(std::shared_ptr<easyar_MegaLandmarkFilterResult>(arg0, [](easyar_MegaLandmarkFilterResult * ptr) { easyar_MegaLandmarkFilterResult__dtor(ptr); }));
        auto f = reinterpret_cast<std::function<void(std::shared_ptr<MegaLandmarkFilterResult>)> *>(_state);
        (*f)(cpparg0);
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
    } catch (std::exception & ex) {
#   if defined(_EASYAR_EXCEPTION_MODE_NORTTI_)
        auto message = std::string() + "Unknown std::exception\n" + ex.what();
#   else
        auto message = std::string() + typeid(*(&ex)).name() + "\n" + ex.what();
#   endif
        easyar_String_from_utf8_begin(message.c_str(), _exception);
    }
#endif
}
static void FunctorOfVoidFromMegaLandmarkFilterResult_destroy(void * _state)
{
    auto f = reinterpret_cast<std::function<void(std::shared_ptr<MegaLandmarkFilterResult>)> *>(_state);
    delete f;
}
static inline easyar_FunctorOfVoidFromMegaLandmarkFilterResult FunctorOfVoidFromMegaLandmarkFilterResult_to_c(std::function<void(std::shared_ptr<MegaLandmarkFilterResult>)> f)
{
    return easyar_FunctorOfVoidFromMegaLandmarkFilterResult{new std::function<void(std::shared_ptr<MegaLandmarkFilterResult>)>(f), FunctorOfVoidFromMegaLandmarkFilterResult_func, FunctorOfVoidFromMegaLandmarkFilterResult_destroy};
}

static inline std::shared_ptr<easyar_ListOfMegaTrackerBlockInstance> std_vector_to_easyar_ListOfMegaTrackerBlockInstance(std::vector<std::shared_ptr<MegaTrackerBlockInstance>> l)
{
    std::vector<easyar_MegaTrackerBlockInstance *> values;
    values.reserve(l.size());
    for (auto v : l) {
        easyar_MegaTrackerBlockInstance * cv;
        easyar_MegaTrackerBlockInstance__retain(v->get_cdata().get(), &cv);
        values.push_back(cv);
    }
    easyar_ListOfMegaTrackerBlockInstance * ptr;
    easyar_ListOfMegaTrackerBlockInstance__ctor(values.data(), values.data() + values.size(), &ptr);
    return std::shared_ptr<easyar_ListOfMegaTrackerBlockInstance>(ptr, [](easyar_ListOfMegaTrackerBlockInstance * ptr) { easyar_ListOfMegaTrackerBlockInstance__dtor(ptr); });
}
static inline std::vector<std::shared_ptr<MegaTrackerBlockInstance>> std_vector_from_easyar_ListOfMegaTrackerBlockInstance(std::shared_ptr<easyar_ListOfMegaTrackerBlockInstance> pl)
{
    auto size = easyar_ListOfMegaTrackerBlockInstance_size(pl.get());
    std::vector<std::shared_ptr<MegaTrackerBlockInstance>> values;
    values.reserve(size);
    for (int k = 0; k < size; k += 1) {
        auto v = easyar_ListOfMegaTrackerBlockInstance_at(pl.get(), k);
        easyar_MegaTrackerBlockInstance__retain(v, &v);
        values.push_back(MegaTrackerBlockInstance::from_cdata(std::shared_ptr<easyar_MegaTrackerBlockInstance>(v, [](easyar_MegaTrackerBlockInstance * ptr) { easyar_MegaTrackerBlockInstance__dtor(ptr); })));
    }
    return values;
}
static inline bool easyar_ListOfMegaTrackerBlockInstance_check_external_cpp(const std::vector<std::shared_ptr<MegaTrackerBlockInstance>> & l)
{
    for (auto e : l) {
        if (!(e != nullptr)) { return false; }
    }
    return true;
}

static void FunctorOfVoidFromMegaTrackerLocalizationResponse_func(void * _state, easyar_MegaTrackerLocalizationResponse * arg0, /* OUT */ easyar_String * * _exception)
{
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
    *_exception = nullptr;
    try {
#endif
        easyar_MegaTrackerLocalizationResponse__retain(arg0, &arg0);
        std::shared_ptr<MegaTrackerLocalizationResponse> cpparg0 = MegaTrackerLocalizationResponse::from_cdata(std::shared_ptr<easyar_MegaTrackerLocalizationResponse>(arg0, [](easyar_MegaTrackerLocalizationResponse * ptr) { easyar_MegaTrackerLocalizationResponse__dtor(ptr); }));
        auto f = reinterpret_cast<std::function<void(std::shared_ptr<MegaTrackerLocalizationResponse>)> *>(_state);
        (*f)(cpparg0);
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
    } catch (std::exception & ex) {
#   if defined(_EASYAR_EXCEPTION_MODE_NORTTI_)
        auto message = std::string() + "Unknown std::exception\n" + ex.what();
#   else
        auto message = std::string() + typeid(*(&ex)).name() + "\n" + ex.what();
#   endif
        easyar_String_from_utf8_begin(message.c_str(), _exception);
    }
#endif
}
static void FunctorOfVoidFromMegaTrackerLocalizationResponse_destroy(void * _state)
{
    auto f = reinterpret_cast<std::function<void(std::shared_ptr<MegaTrackerLocalizationResponse>)> *>(_state);
    delete f;
}
static inline easyar_FunctorOfVoidFromMegaTrackerLocalizationResponse FunctorOfVoidFromMegaTrackerLocalizationResponse_to_c(std::function<void(std::shared_ptr<MegaTrackerLocalizationResponse>)> f)
{
    return easyar_FunctorOfVoidFromMegaTrackerLocalizationResponse{new std::function<void(std::shared_ptr<MegaTrackerLocalizationResponse>)>(f), FunctorOfVoidFromMegaTrackerLocalizationResponse_func, FunctorOfVoidFromMegaTrackerLocalizationResponse_destroy};
}

static inline std::shared_ptr<easyar_ListOfImage> std_vector_to_easyar_ListOfImage(std::vector<std::shared_ptr<Image>> l)
{
    std::vector<easyar_Image *> values;
    values.reserve(l.size());
    for (auto v : l) {
        easyar_Image * cv;
        easyar_Image__retain(v->get_cdata().get(), &cv);
        values.push_back(cv);
    }
    easyar_ListOfImage * ptr;
    easyar_ListOfImage__ctor(values.data(), values.data() + values.size(), &ptr);
    return std::shared_ptr<easyar_ListOfImage>(ptr, [](easyar_ListOfImage * ptr) { easyar_ListOfImage__dtor(ptr); });
}
static inline std::vector<std::shared_ptr<Image>> std_vector_from_easyar_ListOfImage(std::shared_ptr<easyar_ListOfImage> pl)
{
    auto size = easyar_ListOfImage_size(pl.get());
    std::vector<std::shared_ptr<Image>> values;
    values.reserve(size);
    for (int k = 0; k < size; k += 1) {
        auto v = easyar_ListOfImage_at(pl.get(), k);
        easyar_Image__retain(v, &v);
        values.push_back(Image::from_cdata(std::shared_ptr<easyar_Image>(v, [](easyar_Image * ptr) { easyar_Image__dtor(ptr); })));
    }
    return values;
}
static inline bool easyar_ListOfImage_check_external_cpp(const std::vector<std::shared_ptr<Image>> & l)
{
    for (auto e : l) {
        if (!(e != nullptr)) { return false; }
    }
    return true;
}

static void FunctorOfVoidFromCloudRecognizationResult_func(void * _state, easyar_CloudRecognizationResult * arg0, /* OUT */ easyar_String * * _exception)
{
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
    *_exception = nullptr;
    try {
#endif
        easyar_CloudRecognizationResult__retain(arg0, &arg0);
        std::shared_ptr<CloudRecognizationResult> cpparg0 = CloudRecognizationResult::from_cdata(std::shared_ptr<easyar_CloudRecognizationResult>(arg0, [](easyar_CloudRecognizationResult * ptr) { easyar_CloudRecognizationResult__dtor(ptr); }));
        auto f = reinterpret_cast<std::function<void(std::shared_ptr<CloudRecognizationResult>)> *>(_state);
        (*f)(cpparg0);
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
    } catch (std::exception & ex) {
#   if defined(_EASYAR_EXCEPTION_MODE_NORTTI_)
        auto message = std::string() + "Unknown std::exception\n" + ex.what();
#   else
        auto message = std::string() + typeid(*(&ex)).name() + "\n" + ex.what();
#   endif
        easyar_String_from_utf8_begin(message.c_str(), _exception);
    }
#endif
}
static void FunctorOfVoidFromCloudRecognizationResult_destroy(void * _state)
{
    auto f = reinterpret_cast<std::function<void(std::shared_ptr<CloudRecognizationResult>)> *>(_state);
    delete f;
}
static inline easyar_FunctorOfVoidFromCloudRecognizationResult FunctorOfVoidFromCloudRecognizationResult_to_c(std::function<void(std::shared_ptr<CloudRecognizationResult>)> f)
{
    return easyar_FunctorOfVoidFromCloudRecognizationResult{new std::function<void(std::shared_ptr<CloudRecognizationResult>)>(f), FunctorOfVoidFromCloudRecognizationResult_func, FunctorOfVoidFromCloudRecognizationResult_destroy};
}

static inline std::shared_ptr<easyar_ListOfBlockInfo> std_vector_to_easyar_ListOfBlockInfo(std::vector<BlockInfo> l)
{
    std::vector<easyar_BlockInfo> values;
    values.reserve(l.size());
    for (auto v : l) {
        easyar_BlockInfo cv;
        cv = easyar_BlockInfo{v.x, v.y, v.z, v.numOfVertex, v.startPointOfVertex, v.numOfIndex, v.startPointOfIndex, v.version};
        values.push_back(cv);
    }
    easyar_ListOfBlockInfo * ptr;
    easyar_ListOfBlockInfo__ctor(values.data(), values.data() + values.size(), &ptr);
    return std::shared_ptr<easyar_ListOfBlockInfo>(ptr, [](easyar_ListOfBlockInfo * ptr) { easyar_ListOfBlockInfo__dtor(ptr); });
}
static inline std::vector<BlockInfo> std_vector_from_easyar_ListOfBlockInfo(std::shared_ptr<easyar_ListOfBlockInfo> pl)
{
    auto size = easyar_ListOfBlockInfo_size(pl.get());
    std::vector<BlockInfo> values;
    values.reserve(size);
    for (int k = 0; k < size; k += 1) {
        auto v = easyar_ListOfBlockInfo_at(pl.get(), k);
        values.push_back(BlockInfo{v.x, v.y, v.z, v.numOfVertex, v.startPointOfVertex, v.numOfIndex, v.startPointOfIndex, v.version});
    }
    return values;
}
static inline bool easyar_ListOfBlockInfo_check_external_cpp(const std::vector<BlockInfo> & l)
{
    return true;
}

static void FunctorOfVoidFromAccelerometerResult_func(void * _state, easyar_AccelerometerResult arg0, /* OUT */ easyar_String * * _exception)
{
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
    *_exception = nullptr;
    try {
#endif
        AccelerometerResult cpparg0 = AccelerometerResult{arg0.x, arg0.y, arg0.z, arg0.timestamp};
        auto f = reinterpret_cast<std::function<void(AccelerometerResult)> *>(_state);
        (*f)(cpparg0);
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
    } catch (std::exception & ex) {
#   if defined(_EASYAR_EXCEPTION_MODE_NORTTI_)
        auto message = std::string() + "Unknown std::exception\n" + ex.what();
#   else
        auto message = std::string() + typeid(*(&ex)).name() + "\n" + ex.what();
#   endif
        easyar_String_from_utf8_begin(message.c_str(), _exception);
    }
#endif
}
static void FunctorOfVoidFromAccelerometerResult_destroy(void * _state)
{
    auto f = reinterpret_cast<std::function<void(AccelerometerResult)> *>(_state);
    delete f;
}
static inline easyar_FunctorOfVoidFromAccelerometerResult FunctorOfVoidFromAccelerometerResult_to_c(std::function<void(AccelerometerResult)> f)
{
    return easyar_FunctorOfVoidFromAccelerometerResult{new std::function<void(AccelerometerResult)>(f), FunctorOfVoidFromAccelerometerResult_func, FunctorOfVoidFromAccelerometerResult_destroy};
}

static void FunctorOfVoidFromInputFrame_func(void * _state, easyar_InputFrame * arg0, /* OUT */ easyar_String * * _exception)
{
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
    *_exception = nullptr;
    try {
#endif
        easyar_InputFrame__retain(arg0, &arg0);
        std::shared_ptr<InputFrame> cpparg0 = InputFrame::from_cdata(std::shared_ptr<easyar_InputFrame>(arg0, [](easyar_InputFrame * ptr) { easyar_InputFrame__dtor(ptr); }));
        auto f = reinterpret_cast<std::function<void(std::shared_ptr<InputFrame>)> *>(_state);
        (*f)(cpparg0);
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
    } catch (std::exception & ex) {
#   if defined(_EASYAR_EXCEPTION_MODE_NORTTI_)
        auto message = std::string() + "Unknown std::exception\n" + ex.what();
#   else
        auto message = std::string() + typeid(*(&ex)).name() + "\n" + ex.what();
#   endif
        easyar_String_from_utf8_begin(message.c_str(), _exception);
    }
#endif
}
static void FunctorOfVoidFromInputFrame_destroy(void * _state)
{
    auto f = reinterpret_cast<std::function<void(std::shared_ptr<InputFrame>)> *>(_state);
    delete f;
}
static inline easyar_FunctorOfVoidFromInputFrame FunctorOfVoidFromInputFrame_to_c(std::function<void(std::shared_ptr<InputFrame>)> f)
{
    return easyar_FunctorOfVoidFromInputFrame{new std::function<void(std::shared_ptr<InputFrame>)>(f), FunctorOfVoidFromInputFrame_func, FunctorOfVoidFromInputFrame_destroy};
}

static void FunctorOfVoidFromAttitudeSensorResult_func(void * _state, easyar_AttitudeSensorResult arg0, /* OUT */ easyar_String * * _exception)
{
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
    *_exception = nullptr;
    try {
#endif
        AttitudeSensorResult cpparg0 = AttitudeSensorResult{arg0.v0, arg0.v1, arg0.v2, arg0.v3, arg0.timestamp};
        auto f = reinterpret_cast<std::function<void(AttitudeSensorResult)> *>(_state);
        (*f)(cpparg0);
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
    } catch (std::exception & ex) {
#   if defined(_EASYAR_EXCEPTION_MODE_NORTTI_)
        auto message = std::string() + "Unknown std::exception\n" + ex.what();
#   else
        auto message = std::string() + typeid(*(&ex)).name() + "\n" + ex.what();
#   endif
        easyar_String_from_utf8_begin(message.c_str(), _exception);
    }
#endif
}
static void FunctorOfVoidFromAttitudeSensorResult_destroy(void * _state)
{
    auto f = reinterpret_cast<std::function<void(AttitudeSensorResult)> *>(_state);
    delete f;
}
static inline easyar_FunctorOfVoidFromAttitudeSensorResult FunctorOfVoidFromAttitudeSensorResult_to_c(std::function<void(AttitudeSensorResult)> f)
{
    return easyar_FunctorOfVoidFromAttitudeSensorResult{new std::function<void(AttitudeSensorResult)>(f), FunctorOfVoidFromAttitudeSensorResult_func, FunctorOfVoidFromAttitudeSensorResult_destroy};
}

static void FunctorOfVoidFromCameraState_func(void * _state, easyar_CameraState arg0, /* OUT */ easyar_String * * _exception)
{
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
    *_exception = nullptr;
    try {
#endif
        CameraState cpparg0 = static_cast<CameraState>(arg0);
        auto f = reinterpret_cast<std::function<void(CameraState)> *>(_state);
        (*f)(cpparg0);
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
    } catch (std::exception & ex) {
#   if defined(_EASYAR_EXCEPTION_MODE_NORTTI_)
        auto message = std::string() + "Unknown std::exception\n" + ex.what();
#   else
        auto message = std::string() + typeid(*(&ex)).name() + "\n" + ex.what();
#   endif
        easyar_String_from_utf8_begin(message.c_str(), _exception);
    }
#endif
}
static void FunctorOfVoidFromCameraState_destroy(void * _state)
{
    auto f = reinterpret_cast<std::function<void(CameraState)> *>(_state);
    delete f;
}
static inline easyar_FunctorOfVoidFromCameraState FunctorOfVoidFromCameraState_to_c(std::function<void(CameraState)> f)
{
    return easyar_FunctorOfVoidFromCameraState{new std::function<void(CameraState)>(f), FunctorOfVoidFromCameraState_func, FunctorOfVoidFromCameraState_destroy};
}

static void FunctorOfVoidFromPermissionStatusAndString_func(void * _state, easyar_PermissionStatus arg0, easyar_String * arg1, /* OUT */ easyar_String * * _exception)
{
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
    *_exception = nullptr;
    try {
#endif
        PermissionStatus cpparg0 = static_cast<PermissionStatus>(arg0);
        easyar_String_copy(arg1, &arg1);
        std::string cpparg1 = std_string_from_easyar_String(std::shared_ptr<easyar_String>(arg1, [](easyar_String * ptr) { easyar_String__dtor(ptr); }));
        auto f = reinterpret_cast<std::function<void(PermissionStatus, std::string)> *>(_state);
        (*f)(cpparg0, cpparg1);
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
    } catch (std::exception & ex) {
#   if defined(_EASYAR_EXCEPTION_MODE_NORTTI_)
        auto message = std::string() + "Unknown std::exception\n" + ex.what();
#   else
        auto message = std::string() + typeid(*(&ex)).name() + "\n" + ex.what();
#   endif
        easyar_String_from_utf8_begin(message.c_str(), _exception);
    }
#endif
}
static void FunctorOfVoidFromPermissionStatusAndString_destroy(void * _state)
{
    auto f = reinterpret_cast<std::function<void(PermissionStatus, std::string)> *>(_state);
    delete f;
}
static inline easyar_FunctorOfVoidFromPermissionStatusAndString FunctorOfVoidFromPermissionStatusAndString_to_c(std::function<void(PermissionStatus, std::string)> f)
{
    return easyar_FunctorOfVoidFromPermissionStatusAndString{new std::function<void(PermissionStatus, std::string)>(f), FunctorOfVoidFromPermissionStatusAndString_func, FunctorOfVoidFromPermissionStatusAndString_destroy};
}

static void FunctorOfVoidFromGyroscopeResult_func(void * _state, easyar_GyroscopeResult arg0, /* OUT */ easyar_String * * _exception)
{
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
    *_exception = nullptr;
    try {
#endif
        GyroscopeResult cpparg0 = GyroscopeResult{arg0.x, arg0.y, arg0.z, arg0.timestamp};
        auto f = reinterpret_cast<std::function<void(GyroscopeResult)> *>(_state);
        (*f)(cpparg0);
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
    } catch (std::exception & ex) {
#   if defined(_EASYAR_EXCEPTION_MODE_NORTTI_)
        auto message = std::string() + "Unknown std::exception\n" + ex.what();
#   else
        auto message = std::string() + typeid(*(&ex)).name() + "\n" + ex.what();
#   endif
        easyar_String_from_utf8_begin(message.c_str(), _exception);
    }
#endif
}
static void FunctorOfVoidFromGyroscopeResult_destroy(void * _state)
{
    auto f = reinterpret_cast<std::function<void(GyroscopeResult)> *>(_state);
    delete f;
}
static inline easyar_FunctorOfVoidFromGyroscopeResult FunctorOfVoidFromGyroscopeResult_to_c(std::function<void(GyroscopeResult)> f)
{
    return easyar_FunctorOfVoidFromGyroscopeResult{new std::function<void(GyroscopeResult)>(f), FunctorOfVoidFromGyroscopeResult_func, FunctorOfVoidFromGyroscopeResult_destroy};
}

static void FunctorOfVoidFromMagnetometerResult_func(void * _state, easyar_MagnetometerResult arg0, /* OUT */ easyar_String * * _exception)
{
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
    *_exception = nullptr;
    try {
#endif
        MagnetometerResult cpparg0 = MagnetometerResult{arg0.x, arg0.y, arg0.z, arg0.timestamp};
        auto f = reinterpret_cast<std::function<void(MagnetometerResult)> *>(_state);
        (*f)(cpparg0);
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
    } catch (std::exception & ex) {
#   if defined(_EASYAR_EXCEPTION_MODE_NORTTI_)
        auto message = std::string() + "Unknown std::exception\n" + ex.what();
#   else
        auto message = std::string() + typeid(*(&ex)).name() + "\n" + ex.what();
#   endif
        easyar_String_from_utf8_begin(message.c_str(), _exception);
    }
#endif
}
static void FunctorOfVoidFromMagnetometerResult_destroy(void * _state)
{
    auto f = reinterpret_cast<std::function<void(MagnetometerResult)> *>(_state);
    delete f;
}
static inline easyar_FunctorOfVoidFromMagnetometerResult FunctorOfVoidFromMagnetometerResult_to_c(std::function<void(MagnetometerResult)> f)
{
    return easyar_FunctorOfVoidFromMagnetometerResult{new std::function<void(MagnetometerResult)>(f), FunctorOfVoidFromMagnetometerResult_func, FunctorOfVoidFromMagnetometerResult_destroy};
}

static void FunctorOfVoidFromVideoInputFrameRecorderCompletionReason_func(void * _state, easyar_VideoInputFrameRecorderCompletionReason arg0, /* OUT */ easyar_String * * _exception)
{
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
    *_exception = nullptr;
    try {
#endif
        VideoInputFrameRecorderCompletionReason cpparg0 = static_cast<VideoInputFrameRecorderCompletionReason>(arg0);
        auto f = reinterpret_cast<std::function<void(VideoInputFrameRecorderCompletionReason)> *>(_state);
        (*f)(cpparg0);
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
    } catch (std::exception & ex) {
#   if defined(_EASYAR_EXCEPTION_MODE_NORTTI_)
        auto message = std::string() + "Unknown std::exception\n" + ex.what();
#   else
        auto message = std::string() + typeid(*(&ex)).name() + "\n" + ex.what();
#   endif
        easyar_String_from_utf8_begin(message.c_str(), _exception);
    }
#endif
}
static void FunctorOfVoidFromVideoInputFrameRecorderCompletionReason_destroy(void * _state)
{
    auto f = reinterpret_cast<std::function<void(VideoInputFrameRecorderCompletionReason)> *>(_state);
    delete f;
}
static inline easyar_FunctorOfVoidFromVideoInputFrameRecorderCompletionReason FunctorOfVoidFromVideoInputFrameRecorderCompletionReason_to_c(std::function<void(VideoInputFrameRecorderCompletionReason)> f)
{
    return easyar_FunctorOfVoidFromVideoInputFrameRecorderCompletionReason{new std::function<void(VideoInputFrameRecorderCompletionReason)>(f), FunctorOfVoidFromVideoInputFrameRecorderCompletionReason_func, FunctorOfVoidFromVideoInputFrameRecorderCompletionReason_destroy};
}

static void FunctorOfVoidFromLocationResult_func(void * _state, easyar_LocationResult arg0, /* OUT */ easyar_String * * _exception)
{
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
    *_exception = nullptr;
    try {
#endif
        LocationResult cpparg0 = LocationResult{arg0.latitude, arg0.longitude, arg0.altitude, arg0.horizontalAccuracy, arg0.verticalAccuracy, arg0.hasAltitude, arg0.hasHorizontalAccuracy, arg0.hasVerticalAccuracy};
        auto f = reinterpret_cast<std::function<void(LocationResult)> *>(_state);
        (*f)(cpparg0);
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
    } catch (std::exception & ex) {
#   if defined(_EASYAR_EXCEPTION_MODE_NORTTI_)
        auto message = std::string() + "Unknown std::exception\n" + ex.what();
#   else
        auto message = std::string() + typeid(*(&ex)).name() + "\n" + ex.what();
#   endif
        easyar_String_from_utf8_begin(message.c_str(), _exception);
    }
#endif
}
static void FunctorOfVoidFromLocationResult_destroy(void * _state)
{
    auto f = reinterpret_cast<std::function<void(LocationResult)> *>(_state);
    delete f;
}
static inline easyar_FunctorOfVoidFromLocationResult FunctorOfVoidFromLocationResult_to_c(std::function<void(LocationResult)> f)
{
    return easyar_FunctorOfVoidFromLocationResult{new std::function<void(LocationResult)>(f), FunctorOfVoidFromLocationResult_func, FunctorOfVoidFromLocationResult_destroy};
}

static void FunctorOfVoidFromProximityLocationResult_func(void * _state, easyar_ProximityLocationResult arg0, /* OUT */ easyar_String * * _exception)
{
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
    *_exception = nullptr;
    try {
#endif
        ProximityLocationResult cpparg0 = ProximityLocationResult{arg0.x, arg0.y, arg0.z, arg0.accuracy, arg0.timestamp, arg0.is2d, arg0.validTime};
        auto f = reinterpret_cast<std::function<void(ProximityLocationResult)> *>(_state);
        (*f)(cpparg0);
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
    } catch (std::exception & ex) {
#   if defined(_EASYAR_EXCEPTION_MODE_NORTTI_)
        auto message = std::string() + "Unknown std::exception\n" + ex.what();
#   else
        auto message = std::string() + typeid(*(&ex)).name() + "\n" + ex.what();
#   endif
        easyar_String_from_utf8_begin(message.c_str(), _exception);
    }
#endif
}
static void FunctorOfVoidFromProximityLocationResult_destroy(void * _state)
{
    auto f = reinterpret_cast<std::function<void(ProximityLocationResult)> *>(_state);
    delete f;
}
static inline easyar_FunctorOfVoidFromProximityLocationResult FunctorOfVoidFromProximityLocationResult_to_c(std::function<void(ProximityLocationResult)> f)
{
    return easyar_FunctorOfVoidFromProximityLocationResult{new std::function<void(ProximityLocationResult)>(f), FunctorOfVoidFromProximityLocationResult_func, FunctorOfVoidFromProximityLocationResult_destroy};
}

static void FunctorOfVoidFromLogLevelAndString_func(void * _state, easyar_LogLevel arg0, easyar_String * arg1, /* OUT */ easyar_String * * _exception)
{
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
    *_exception = nullptr;
    try {
#endif
        LogLevel cpparg0 = static_cast<LogLevel>(arg0);
        easyar_String_copy(arg1, &arg1);
        std::string cpparg1 = std_string_from_easyar_String(std::shared_ptr<easyar_String>(arg1, [](easyar_String * ptr) { easyar_String__dtor(ptr); }));
        auto f = reinterpret_cast<std::function<void(LogLevel, std::string)> *>(_state);
        (*f)(cpparg0, cpparg1);
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
    } catch (std::exception & ex) {
#   if defined(_EASYAR_EXCEPTION_MODE_NORTTI_)
        auto message = std::string() + "Unknown std::exception\n" + ex.what();
#   else
        auto message = std::string() + typeid(*(&ex)).name() + "\n" + ex.what();
#   endif
        easyar_String_from_utf8_begin(message.c_str(), _exception);
    }
#endif
}
static void FunctorOfVoidFromLogLevelAndString_destroy(void * _state)
{
    auto f = reinterpret_cast<std::function<void(LogLevel, std::string)> *>(_state);
    delete f;
}
static inline easyar_FunctorOfVoidFromLogLevelAndString FunctorOfVoidFromLogLevelAndString_to_c(std::function<void(LogLevel, std::string)> f)
{
    return easyar_FunctorOfVoidFromLogLevelAndString{new std::function<void(LogLevel, std::string)>(f), FunctorOfVoidFromLogLevelAndString_func, FunctorOfVoidFromLogLevelAndString_destroy};
}

static void FunctorOfVoidFromRecordStatusAndString_func(void * _state, easyar_RecordStatus arg0, easyar_String * arg1, /* OUT */ easyar_String * * _exception)
{
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
    *_exception = nullptr;
    try {
#endif
        RecordStatus cpparg0 = static_cast<RecordStatus>(arg0);
        easyar_String_copy(arg1, &arg1);
        std::string cpparg1 = std_string_from_easyar_String(std::shared_ptr<easyar_String>(arg1, [](easyar_String * ptr) { easyar_String__dtor(ptr); }));
        auto f = reinterpret_cast<std::function<void(RecordStatus, std::string)> *>(_state);
        (*f)(cpparg0, cpparg1);
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
    } catch (std::exception & ex) {
#   if defined(_EASYAR_EXCEPTION_MODE_NORTTI_)
        auto message = std::string() + "Unknown std::exception\n" + ex.what();
#   else
        auto message = std::string() + typeid(*(&ex)).name() + "\n" + ex.what();
#   endif
        easyar_String_from_utf8_begin(message.c_str(), _exception);
    }
#endif
}
static void FunctorOfVoidFromRecordStatusAndString_destroy(void * _state)
{
    auto f = reinterpret_cast<std::function<void(RecordStatus, std::string)> *>(_state);
    delete f;
}
static inline easyar_FunctorOfVoidFromRecordStatusAndString FunctorOfVoidFromRecordStatusAndString_to_c(std::function<void(RecordStatus, std::string)> f)
{
    return easyar_FunctorOfVoidFromRecordStatusAndString{new std::function<void(RecordStatus, std::string)>(f), FunctorOfVoidFromRecordStatusAndString_func, FunctorOfVoidFromRecordStatusAndString_destroy};
}

static inline std::shared_ptr<easyar_ListOfPlaneData> std_vector_to_easyar_ListOfPlaneData(std::vector<std::shared_ptr<PlaneData>> l)
{
    std::vector<easyar_PlaneData *> values;
    values.reserve(l.size());
    for (auto v : l) {
        easyar_PlaneData * cv;
        easyar_PlaneData__retain(v->get_cdata().get(), &cv);
        values.push_back(cv);
    }
    easyar_ListOfPlaneData * ptr;
    easyar_ListOfPlaneData__ctor(values.data(), values.data() + values.size(), &ptr);
    return std::shared_ptr<easyar_ListOfPlaneData>(ptr, [](easyar_ListOfPlaneData * ptr) { easyar_ListOfPlaneData__dtor(ptr); });
}
static inline std::vector<std::shared_ptr<PlaneData>> std_vector_from_easyar_ListOfPlaneData(std::shared_ptr<easyar_ListOfPlaneData> pl)
{
    auto size = easyar_ListOfPlaneData_size(pl.get());
    std::vector<std::shared_ptr<PlaneData>> values;
    values.reserve(size);
    for (int k = 0; k < size; k += 1) {
        auto v = easyar_ListOfPlaneData_at(pl.get(), k);
        easyar_PlaneData__retain(v, &v);
        values.push_back(PlaneData::from_cdata(std::shared_ptr<easyar_PlaneData>(v, [](easyar_PlaneData * ptr) { easyar_PlaneData__dtor(ptr); })));
    }
    return values;
}
static inline bool easyar_ListOfPlaneData_check_external_cpp(const std::vector<std::shared_ptr<PlaneData>> & l)
{
    for (auto e : l) {
        if (!(e != nullptr)) { return false; }
    }
    return true;
}

static void FunctorOfVoidFromBool_func(void * _state, bool arg0, /* OUT */ easyar_String * * _exception)
{
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
    *_exception = nullptr;
    try {
#endif
        bool cpparg0 = arg0;
        auto f = reinterpret_cast<std::function<void(bool)> *>(_state);
        (*f)(cpparg0);
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
    } catch (std::exception & ex) {
#   if defined(_EASYAR_EXCEPTION_MODE_NORTTI_)
        auto message = std::string() + "Unknown std::exception\n" + ex.what();
#   else
        auto message = std::string() + typeid(*(&ex)).name() + "\n" + ex.what();
#   endif
        easyar_String_from_utf8_begin(message.c_str(), _exception);
    }
#endif
}
static void FunctorOfVoidFromBool_destroy(void * _state)
{
    auto f = reinterpret_cast<std::function<void(bool)> *>(_state);
    delete f;
}
static inline easyar_FunctorOfVoidFromBool FunctorOfVoidFromBool_to_c(std::function<void(bool)> f)
{
    return easyar_FunctorOfVoidFromBool{new std::function<void(bool)>(f), FunctorOfVoidFromBool_func, FunctorOfVoidFromBool_destroy};
}

static void FunctorOfVoidFromBoolAndStringAndString_func(void * _state, bool arg0, easyar_String * arg1, easyar_String * arg2, /* OUT */ easyar_String * * _exception)
{
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
    *_exception = nullptr;
    try {
#endif
        bool cpparg0 = arg0;
        easyar_String_copy(arg1, &arg1);
        std::string cpparg1 = std_string_from_easyar_String(std::shared_ptr<easyar_String>(arg1, [](easyar_String * ptr) { easyar_String__dtor(ptr); }));
        easyar_String_copy(arg2, &arg2);
        std::string cpparg2 = std_string_from_easyar_String(std::shared_ptr<easyar_String>(arg2, [](easyar_String * ptr) { easyar_String__dtor(ptr); }));
        auto f = reinterpret_cast<std::function<void(bool, std::string, std::string)> *>(_state);
        (*f)(cpparg0, cpparg1, cpparg2);
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
    } catch (std::exception & ex) {
#   if defined(_EASYAR_EXCEPTION_MODE_NORTTI_)
        auto message = std::string() + "Unknown std::exception\n" + ex.what();
#   else
        auto message = std::string() + typeid(*(&ex)).name() + "\n" + ex.what();
#   endif
        easyar_String_from_utf8_begin(message.c_str(), _exception);
    }
#endif
}
static void FunctorOfVoidFromBoolAndStringAndString_destroy(void * _state)
{
    auto f = reinterpret_cast<std::function<void(bool, std::string, std::string)> *>(_state);
    delete f;
}
static inline easyar_FunctorOfVoidFromBoolAndStringAndString FunctorOfVoidFromBoolAndStringAndString_to_c(std::function<void(bool, std::string, std::string)> f)
{
    return easyar_FunctorOfVoidFromBoolAndStringAndString{new std::function<void(bool, std::string, std::string)>(f), FunctorOfVoidFromBoolAndStringAndString_func, FunctorOfVoidFromBoolAndStringAndString_destroy};
}

static void FunctorOfVoidFromBoolAndString_func(void * _state, bool arg0, easyar_String * arg1, /* OUT */ easyar_String * * _exception)
{
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
    *_exception = nullptr;
    try {
#endif
        bool cpparg0 = arg0;
        easyar_String_copy(arg1, &arg1);
        std::string cpparg1 = std_string_from_easyar_String(std::shared_ptr<easyar_String>(arg1, [](easyar_String * ptr) { easyar_String__dtor(ptr); }));
        auto f = reinterpret_cast<std::function<void(bool, std::string)> *>(_state);
        (*f)(cpparg0, cpparg1);
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
    } catch (std::exception & ex) {
#   if defined(_EASYAR_EXCEPTION_MODE_NORTTI_)
        auto message = std::string() + "Unknown std::exception\n" + ex.what();
#   else
        auto message = std::string() + typeid(*(&ex)).name() + "\n" + ex.what();
#   endif
        easyar_String_from_utf8_begin(message.c_str(), _exception);
    }
#endif
}
static void FunctorOfVoidFromBoolAndString_destroy(void * _state)
{
    auto f = reinterpret_cast<std::function<void(bool, std::string)> *>(_state);
    delete f;
}
static inline easyar_FunctorOfVoidFromBoolAndString FunctorOfVoidFromBoolAndString_to_c(std::function<void(bool, std::string)> f)
{
    return easyar_FunctorOfVoidFromBoolAndString{new std::function<void(bool, std::string)>(f), FunctorOfVoidFromBoolAndString_func, FunctorOfVoidFromBoolAndString_destroy};
}

static void FunctorOfVoidFromVideoStatus_func(void * _state, easyar_VideoStatus arg0, /* OUT */ easyar_String * * _exception)
{
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
    *_exception = nullptr;
    try {
#endif
        VideoStatus cpparg0 = static_cast<VideoStatus>(arg0);
        auto f = reinterpret_cast<std::function<void(VideoStatus)> *>(_state);
        (*f)(cpparg0);
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
    } catch (std::exception & ex) {
#   if defined(_EASYAR_EXCEPTION_MODE_NORTTI_)
        auto message = std::string() + "Unknown std::exception\n" + ex.what();
#   else
        auto message = std::string() + typeid(*(&ex)).name() + "\n" + ex.what();
#   endif
        easyar_String_from_utf8_begin(message.c_str(), _exception);
    }
#endif
}
static void FunctorOfVoidFromVideoStatus_destroy(void * _state)
{
    auto f = reinterpret_cast<std::function<void(VideoStatus)> *>(_state);
    delete f;
}
static inline easyar_FunctorOfVoidFromVideoStatus FunctorOfVoidFromVideoStatus_to_c(std::function<void(VideoStatus)> f)
{
    return easyar_FunctorOfVoidFromVideoStatus{new std::function<void(VideoStatus)>(f), FunctorOfVoidFromVideoStatus_func, FunctorOfVoidFromVideoStatus_destroy};
}

static void FunctorOfVoidFromFeedbackFrame_func(void * _state, easyar_FeedbackFrame * arg0, /* OUT */ easyar_String * * _exception)
{
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
    *_exception = nullptr;
    try {
#endif
        easyar_FeedbackFrame__retain(arg0, &arg0);
        std::shared_ptr<FeedbackFrame> cpparg0 = FeedbackFrame::from_cdata(std::shared_ptr<easyar_FeedbackFrame>(arg0, [](easyar_FeedbackFrame * ptr) { easyar_FeedbackFrame__dtor(ptr); }));
        auto f = reinterpret_cast<std::function<void(std::shared_ptr<FeedbackFrame>)> *>(_state);
        (*f)(cpparg0);
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
    } catch (std::exception & ex) {
#   if defined(_EASYAR_EXCEPTION_MODE_NORTTI_)
        auto message = std::string() + "Unknown std::exception\n" + ex.what();
#   else
        auto message = std::string() + typeid(*(&ex)).name() + "\n" + ex.what();
#   endif
        easyar_String_from_utf8_begin(message.c_str(), _exception);
    }
#endif
}
static void FunctorOfVoidFromFeedbackFrame_destroy(void * _state)
{
    auto f = reinterpret_cast<std::function<void(std::shared_ptr<FeedbackFrame>)> *>(_state);
    delete f;
}
static inline easyar_FunctorOfVoidFromFeedbackFrame FunctorOfVoidFromFeedbackFrame_to_c(std::function<void(std::shared_ptr<FeedbackFrame>)> f)
{
    return easyar_FunctorOfVoidFromFeedbackFrame{new std::function<void(std::shared_ptr<FeedbackFrame>)>(f), FunctorOfVoidFromFeedbackFrame_func, FunctorOfVoidFromFeedbackFrame_destroy};
}

static void FunctorOfOutputFrameFromListOfOutputFrame_func(void * _state, easyar_ListOfOutputFrame * arg0, /* OUT */ easyar_OutputFrame * * Return, /* OUT */ easyar_String * * _exception)
{
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
    *_exception = nullptr;
    try {
#endif
        easyar_ListOfOutputFrame_copy(arg0, &arg0);
        std::vector<std::shared_ptr<OutputFrame>> cpparg0 = std_vector_from_easyar_ListOfOutputFrame(std::shared_ptr<easyar_ListOfOutputFrame>(arg0, [](easyar_ListOfOutputFrame * ptr) { easyar_ListOfOutputFrame__dtor(ptr); }));
        auto f = reinterpret_cast<std::function<std::shared_ptr<OutputFrame>(std::vector<std::shared_ptr<OutputFrame>>)> *>(_state);
        std::shared_ptr<OutputFrame> _return_value_ = (*f)(cpparg0);
        if (!(_return_value_ != nullptr)) {
            easyar_String_from_utf8_begin("InvalidReturnValue", _exception);
            return;
        }
        easyar_OutputFrame * _return_value_c_;
        easyar_OutputFrame__retain(_return_value_->get_cdata().get(), &_return_value_c_);
        *Return = _return_value_c_;
#if !defined(_EASYAR_EXCEPTION_MODE_NOEXCEPTION_)
    } catch (std::exception & ex) {
#   if defined(_EASYAR_EXCEPTION_MODE_NORTTI_)
        auto message = std::string() + "Unknown std::exception\n" + ex.what();
#   else
        auto message = std::string() + typeid(*(&ex)).name() + "\n" + ex.what();
#   endif
        easyar_String_from_utf8_begin(message.c_str(), _exception);
    }
#endif
}
static void FunctorOfOutputFrameFromListOfOutputFrame_destroy(void * _state)
{
    auto f = reinterpret_cast<std::function<std::shared_ptr<OutputFrame>(std::vector<std::shared_ptr<OutputFrame>>)> *>(_state);
    delete f;
}
static inline easyar_FunctorOfOutputFrameFromListOfOutputFrame FunctorOfOutputFrameFromListOfOutputFrame_to_c(std::function<std::shared_ptr<OutputFrame>(std::vector<std::shared_ptr<OutputFrame>>)> f)
{
    return easyar_FunctorOfOutputFrameFromListOfOutputFrame{new std::function<std::shared_ptr<OutputFrame>(std::vector<std::shared_ptr<OutputFrame>>)>(f), FunctorOfOutputFrameFromListOfOutputFrame_func, FunctorOfOutputFrameFromListOfOutputFrame_destroy};
}

static inline std::shared_ptr<easyar_ListOfOutputFrame> std_vector_to_easyar_ListOfOutputFrame(std::vector<std::shared_ptr<OutputFrame>> l)
{
    std::vector<easyar_OutputFrame *> values;
    values.reserve(l.size());
    for (auto v : l) {
        easyar_OutputFrame * cv;
        easyar_OutputFrame__retain(v->get_cdata().get(), &cv);
        values.push_back(cv);
    }
    easyar_ListOfOutputFrame * ptr;
    easyar_ListOfOutputFrame__ctor(values.data(), values.data() + values.size(), &ptr);
    return std::shared_ptr<easyar_ListOfOutputFrame>(ptr, [](easyar_ListOfOutputFrame * ptr) { easyar_ListOfOutputFrame__dtor(ptr); });
}
static inline std::vector<std::shared_ptr<OutputFrame>> std_vector_from_easyar_ListOfOutputFrame(std::shared_ptr<easyar_ListOfOutputFrame> pl)
{
    auto size = easyar_ListOfOutputFrame_size(pl.get());
    std::vector<std::shared_ptr<OutputFrame>> values;
    values.reserve(size);
    for (int k = 0; k < size; k += 1) {
        auto v = easyar_ListOfOutputFrame_at(pl.get(), k);
        easyar_OutputFrame__retain(v, &v);
        values.push_back(OutputFrame::from_cdata(std::shared_ptr<easyar_OutputFrame>(v, [](easyar_OutputFrame * ptr) { easyar_OutputFrame__dtor(ptr); })));
    }
    return values;
}
static inline bool easyar_ListOfOutputFrame_check_external_cpp(const std::vector<std::shared_ptr<OutputFrame>> & l)
{
    for (auto e : l) {
        if (!(e != nullptr)) { return false; }
    }
    return true;
}

}

#endif

#undef _INLINE_SPECIFIER_
