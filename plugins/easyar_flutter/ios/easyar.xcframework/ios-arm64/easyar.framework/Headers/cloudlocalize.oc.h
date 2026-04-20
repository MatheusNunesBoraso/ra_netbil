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
/// The block instance localized by MegaTracker.
/// </summary>
@interface easyar_CloudLocalizerBlockInstance : easyar_RefBase

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

/// <summary>
/// The ID of the block.
/// </summary>
- (NSString *)blockId;
/// <summary>
/// The name of the block.
/// </summary>
- (NSString *)name;
/// <summary>
/// The map pose in the camera coordinates.
/// </summary>
- (easyar_Matrix44F *)pose;

@end

@interface easyar_CloudLocalizerResult : easyar_RefBase

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

/// <summary>
/// Localization status.
/// </summary>
- (easyar_CloudLocalizerStatus)localizeStatus;
/// <summary>
/// The spot version ID. Only available with `MegaApiType`_.Landmark .
/// </summary>
- (NSString *)spotVersionId;
/// <summary>
/// Current localized block instances.
/// </summary>
- (NSArray<easyar_CloudLocalizerBlockInstance *> *)blockInstances;
/// <summary>
/// Extra informations of the localization.
/// </summary>
- (NSString *)extraInfo;
/// <summary>
/// Detailed exception message.
/// </summary>
- (NSString *)exceptionInfo;
/// <summary>
/// The duration in seconds for server response.
/// </summary>
- (NSNumber *)serverResponseDuration;
/// <summary>
/// The duration in seconds for server internal calculation.
/// </summary>
- (NSNumber *)serverCalculationDuration;

@end

@interface easyar_DeviceAuxiliaryInfo : easyar_RefBase

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

+ (easyar_DeviceAuxiliaryInfo *)create;
- (void)setAcceleration:(easyar_AccelerometerResult *)acce;
- (void)setGPSLocation:(easyar_LocationResult *)gps;
- (void)setProximityLocation:(easyar_ProximityLocationResult *)proximity;
- (void)setBlockPrior:(easyar_BlockPriorResult *)blockPrior;
- (void)setECompass:(double)northHeading headingAccuracy:(double)headingAccuracy;

@end

/// <summary>
/// CloudLocalizer implements cloud based localization.
/// </summary>
@interface easyar_CloudLocalizer : easyar_RefBase

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

/// <summary>
/// Returns true.
/// </summary>
+ (bool)isAvailable;
/// <summary>
/// Creates an instance and connects to the server.
/// </summary>
+ (easyar_CloudLocalizer *)create:(NSString *)server apiKey:(NSString *)apiKey apiSecret:(NSString *)apiSecret appId:(NSString *)appId;
/// <summary>
/// Creates an instance with API Token and connects to the server.
/// </summary>
+ (easyar_CloudLocalizer *)createWithToken:(NSString *)server apiToken:(NSString *)apiToken appId:(NSString *)appId;
/// <summary>
/// Updates API Token.
/// </summary>
- (void)updateToken:(NSString *)apiToken;
/// <summary>
/// Sets MEGA API Type. The default is Block.
/// </summary>
- (void)setMegaApiType:(easyar_MegaApiType)type;
/// <summary>
/// Send localization request.
/// Send `InputFrame`_ to resolve a cloud localization. `InputFrame`_ should have at least image data and camera parameters.
/// message input is a json string.
/// </summary>
- (void)resolve:(easyar_InputFrame *)inputFrame message:(NSString *)message deviceAuxInfo:(easyar_DeviceAuxiliaryInfo *)deviceAuxInfo timeoutMilliseconds:(NSNumber *)timeoutMilliseconds callbackScheduler:(easyar_CallbackScheduler *)callbackScheduler callback:(void (^)(easyar_CloudLocalizerResult * result))callback;
/// <summary>
/// Send localization request.
/// Send `InputFrame`_ to resolve a cloud localization. `InputFrame`_ should have at least image data and camera parameters.
/// message input is a json string.
/// </summary>
- (void)resolveLandmark:(easyar_InputFrame *)inputFrame message:(NSString *)message deviceAuxInfo:(easyar_DeviceAuxiliaryInfo *)deviceAuxInfo spotVersionId:(NSString *)spotVersionId timeoutMilliseconds:(NSNumber *)timeoutMilliseconds callbackScheduler:(easyar_CallbackScheduler *)callbackScheduler callback:(void (^)(easyar_CloudLocalizerResult * result))callback;
/// <summary>
/// Stops the localization and closes connection. The component shall not be used after calling close.
/// </summary>
- (void)close;

@end
