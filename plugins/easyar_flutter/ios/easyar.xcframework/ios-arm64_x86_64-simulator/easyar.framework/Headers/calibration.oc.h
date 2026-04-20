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
/// CalibrationDownloader is used for download and update of calibration data in MotionTracker. The calibration data will only take effect after reallocation of MotionTracker.
/// </summary>
@interface easyar_CalibrationDownloader : easyar_RefBase

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

+ (easyar_CalibrationDownloader *) create;
- (void)download:(NSNumber *)timeoutMilliseconds callbackScheduler:(easyar_CallbackScheduler *)callbackScheduler onCompleted:(void (^)(easyar_CalibrationDownloadStatus status, NSString * error))onCompleted;

@end
