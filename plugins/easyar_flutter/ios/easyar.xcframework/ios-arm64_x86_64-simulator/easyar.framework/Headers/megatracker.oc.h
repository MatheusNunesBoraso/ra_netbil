//=============================================================================================================================
//
// EasyAR Sense 4.8.0.11837-e0e3282d9
// Copyright (c) 2015-2026 VisionStar Information Technology (Shanghai) Co., Ltd. All Rights Reserved.
// EasyAR is the registered trademark or trademark of VisionStar Information Technology (Shanghai) Co., Ltd in China
// and other countries for the augmented reality technology developed by VisionStar Information Technology (Shanghai) Co., Ltd.
//
//=============================================================================================================================

#import "easyar/types.oc.h"
#import "easyar/frame.oc.h"

/// <summary>
/// The block instance localized by MegaTracker.
/// </summary>
@interface easyar_MegaTrackerBlockInstance : easyar_RefBase

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

/// <summary>
/// The appId of service.
/// </summary>
- (NSString *)appId;
/// <summary>
/// The ID of the block.
/// </summary>
- (NSString *)blockId;
/// <summary>
/// The name of the block.
/// </summary>
- (NSString *)name;
/// <summary>
/// The map block pose in the camera coordinates.
/// </summary>
- (easyar_Matrix44F *)pose;

@end

/// <summary>
/// The result of MegaTracker. Updated at the same frame rate with OutputFrame.
/// </summary>
@interface easyar_MegaTrackerResult : easyar_FrameFilterResult

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

/// <summary>
/// Current localized block instances. An existing instance will be preserved until another block is localized, or when MegaTracker is stopped or paused.
/// </summary>
- (NSArray<easyar_MegaTrackerBlockInstance *> *)instances;

@end

/// <summary>
/// The response of MegaTracker localization request.
/// </summary>
@interface easyar_MegaTrackerLocalizationResponse : easyar_RefBase

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

/// <summary>
/// The input frame on request.
/// </summary>
- (easyar_InputFrame *)inputFrame;
/// <summary>
/// The accelerometer reading on request.
/// </summary>
- (easyar_AccelerometerResult *)acceleration;
/// <summary>
/// The location reading on request.
/// </summary>
- (easyar_LocationResult *)location;
/// <summary>
/// Localization status.
/// </summary>
- (easyar_MegaTrackerLocalizationStatus)status;
/// <summary>
/// The spot version ID.
/// </summary>
- (NSString *)spotVersionId;
/// <summary>
/// Current localized block instances. An existing instance will be preserved until another block is localized, or when MegaTracker is stopped or paused.
/// </summary>
- (NSArray<easyar_MegaTrackerBlockInstance *> *)instances;
/// <summary>
/// The appId of service.
/// </summary>
- (NSString *)appId;
/// <summary>
/// The duration in seconds for server response.
/// </summary>
- (NSNumber *)serverResponseDuration;
/// <summary>
/// The duration in seconds for server internal calculation.
/// </summary>
- (NSNumber *)serverCalculationDuration;
/// <summary>
/// Error message. It is filled when status is UnknownError.
/// </summary>
- (NSString *)errorMessage;
- (NSString *)extraInfo;

@end

/// <summary>
/// Provides cloud based localization.
/// MegaTracker occupies 1 buffers of camera.
/// </summary>
@interface easyar_MegaTracker : easyar_RefBase

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

/// <summary>
/// Check whether SparseSpatialMap is is available, always return true.
/// </summary>
+ (bool)isAvailable;
/// <summary>
/// Input port for input frame. For MegaTracker to work, the inputFrame must include camera parameters, timestamp and spatial information. See also `InputFrameSink`_ .
/// </summary>
- (easyar_InputFrameSink *)inputFrameSink;
/// <summary>
/// Input port for accelerometer result. See also `AccelerometerResultSink`_ .
/// </summary>
- (easyar_AccelerometerResultSink *)accelerometerResultSink;
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
/// Output port for output frame. See also `OutputFrameSource`_ .
/// </summary>
- (easyar_OutputFrameSource *)outputFrameSource;
/// <summary>
/// Creates an instance.
/// </summary>
+ (easyar_MegaTracker *)create:(NSString *)server apiKey:(NSString *)apiKey apiSecret:(NSString *)apiSecret appId:(NSString *)appId;
/// <summary>
/// Creates an instance with API Token.
/// </summary>
+ (easyar_MegaTracker *)createWithToken:(NSString *)server apiToken:(NSString *)apiToken appId:(NSString *)appId;
/// <summary>
/// Updates API Token.
/// </summary>
- (void)updateToken:(NSString *)apiToken;
/// <summary>
/// Sets MEGA API Type. The default is Block.
/// </summary>
- (void)setMegaApiType:(easyar_MegaApiType)type;
/// <summary>
/// Sets the spot version ID. Only available with `MegaApiType`_.Landmark .
/// </summary>
- (void)setSpotVersionId:(NSString *)spotVersionId;
/// <summary>
/// Switches remote end point.
/// </summary>
- (void)switchEndPoint:(NSString *)server apiKey:(NSString *)apiKey apiSecret:(NSString *)apiSecret appId:(NSString *)appId;
/// <summary>
/// Switches remote end point with API Token.
/// </summary>
- (void)switchEndPointWithToken:(NSString *)server apiToken:(NSString *)apiToken appId:(NSString *)appId;
/// <summary>
/// Binds to a specific block prior. An automatic unbind will be performed during reset or end point switching.
/// </summary>
- (void)bindBlockPrior:(easyar_BlockPriorResult *)blockPrior;
/// <summary>
/// Release bind to any block.
/// </summary>
- (void)unbindBlockPrior;
/// <summary>
/// Sets request time parameters. timeoutMilliseconds is connection timeout. requestIntervalMilliseconds is the expected request interval, and the default value is 1000 and the minimum value is 300, with a longer value results a larger overall error.
/// </summary>
- (void)setRequestTimeParameters:(NSNumber *)timeoutMilliseconds requestIntervalMilliseconds:(int)requestIntervalMilliseconds;
/// <summary>
/// Sets whether to enable localzation. If disabled, localization result from server response will not be in the output. Defaults to true.
/// </summary>
- (void)setEnableLocalization:(bool)enableLocalization;
/// <summary>
/// Sets whether to enable stateless localzation. If enabled, previous result will not be used in localization. Defaults to false.
/// </summary>
- (void)setEnableStatelessLocalization:(bool)enableStatelessLocalization;
/// <summary>
/// Sets result async mode. Set true If results are to be outputted via outputFrameSource, false if results are to be fetched via getSyncResult. enableAsync defaults to true. Sync mode is only available with a XR license.
/// </summary>
- (bool)setResultAsyncMode:(bool)enableAsync;
- (void)setRequestMessage:(NSString *)message;
/// <summary>
/// Sets localization callback. On every localization, the callback will be triggered.
/// </summary>
- (void)setLocalizationCallback:(easyar_CallbackScheduler *)callbackScheduler callback:(void (^)(easyar_MegaTrackerLocalizationResponse * response))callback;
/// <summary>
/// Sets the override value for camera position from map block. When set, MegaTracker will output override value instead of the position in input frame. This option can be utilized to improve output pose precision when there is known map info but limited sensor capability.
/// </summary>
- (void)setCameraPositionOverride:(NSNumber *)x y:(NSNumber *)y z:(NSNumber *)z;
/// <summary>
/// Start MegaTracker.
/// </summary>
- (bool)start;
/// <summary>
/// Stop MegaTracker. Call start() to resume running.
/// </summary>
- (void)stop;
/// <summary>
/// Reset MegaTracker and clear all internal states.
/// </summary>
- (void)reset;
/// <summary>
/// Close MegaTracker. MegaTracker can no longer be used.
/// </summary>
- (void)close;
/// <summary>
/// Get synchronized result. If MegaTracker is paused, or the result async mode is not set to false through setResultAsyncMode, the return value is empty.
/// </summary>
- (easyar_MegaTrackerResult *)getSyncResult:(easyar_MotionInputData *)motionInputData;

@end
