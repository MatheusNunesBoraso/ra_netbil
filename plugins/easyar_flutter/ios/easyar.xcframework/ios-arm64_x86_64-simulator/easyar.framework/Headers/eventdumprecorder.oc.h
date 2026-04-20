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
/// Event dump recorder.
/// It can be used to record some crucial diagnostic information into an EED file.
/// All members of this class is thread-safe.
/// </summary>
@interface easyar_EventDumpRecorder : easyar_RefBase

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

/// <summary>
/// Creates an instance.
/// </summary>
+ (easyar_EventDumpRecorder *)create;
/// <summary>
/// Starts recording.
/// </summary>
- (bool)start:(NSString *)filePath initalScreenRotation:(int)initalScreenRotation;
/// <summary>
/// Stops recording.
/// </summary>
- (void)stop;

@end
