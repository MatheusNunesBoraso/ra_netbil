//=============================================================================================================================
//
// EasyAR Sense 4.8.0.11837-e0e3282d9
// Copyright (c) 2015-2026 VisionStar Information Technology (Shanghai) Co., Ltd. All Rights Reserved.
// EasyAR is the registered trademark or trademark of VisionStar Information Technology (Shanghai) Co., Ltd in China
// and other countries for the augmented reality technology developed by VisionStar Information Technology (Shanghai) Co., Ltd.
//
//=============================================================================================================================

#import "easyar/types.oc.h"

@interface easyar_MegaLandmarkFilterResult : easyar_RefBase

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

/// <summary>
/// Request status.
/// </summary>
- (easyar_MegaLandmarkFilterStatus)status;
/// <summary>
/// The spot version ID.
/// </summary>
- (NSString *)spotVersionId;
/// <summary>
/// Detailed exception message.
/// </summary>
- (NSString *)exceptionInfo;

@end

/// <summary>
/// MegaLandmarkFilter implements cloud based visual positioning localization filtering.
/// </summary>
@interface easyar_MegaLandmarkFilter : easyar_RefBase

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

/// <summary>
/// Returns true.
/// </summary>
+ (bool)isAvailable;
/// <summary>
/// Creates an instance and connects to the server.
/// </summary>
+ (easyar_MegaLandmarkFilter *)create:(NSString *)server apiKey:(NSString *)apiKey apiSecret:(NSString *)apiSecret appId:(NSString *)appId;
/// <summary>
/// Creates an instance with API Token.
/// </summary>
+ (easyar_MegaLandmarkFilter *)createWithToken:(NSString *)server apiToken:(NSString *)apiToken appId:(NSString *)appId;
/// <summary>
/// Updates API Token.
/// </summary>
- (void)updateToken:(NSString *)apiToken;
/// <summary>
/// Location filtering.
/// Send GPS information to get SpotVersionId.
/// </summary>
- (void)filterByLocation:(easyar_LocationResult *)gps timeoutMilliseconds:(NSNumber *)timeoutMilliseconds callbackScheduler:(easyar_CallbackScheduler *)callbackScheduler callback:(void (^)(easyar_MegaLandmarkFilterResult * result))callback;
/// <summary>
/// Filtering by SpotId.
/// Returns SpotVersionId.
/// </summary>
- (void)filterBySpotId:(NSString *)spotId timeoutMilliseconds:(NSNumber *)timeoutMilliseconds callbackScheduler:(easyar_CallbackScheduler *)callbackScheduler callback:(void (^)(easyar_MegaLandmarkFilterResult * result))callback;
/// <summary>
/// Closes connection. The component shall not be used after calling close.
/// </summary>
- (void)close;

@end
