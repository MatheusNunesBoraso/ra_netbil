//=============================================================================================================================
//
// EasyAR Sense 4.8.0.11837-e0e3282d9
// Copyright (c) 2015-2026 VisionStar Information Technology (Shanghai) Co., Ltd. All Rights Reserved.
// EasyAR is the registered trademark or trademark of VisionStar Information Technology (Shanghai) Co., Ltd in China
// and other countries for the augmented reality technology developed by VisionStar Information Technology (Shanghai) Co., Ltd.
//
//=============================================================================================================================

#ifndef __EASYAR_EVENTDUMPRECORDER_H__
#define __EASYAR_EVENTDUMPRECORDER_H__

#include "easyar/types.h"

#ifdef __cplusplus
extern "C" {
#endif

/// <summary>
/// Creates an instance.
/// </summary>
void easyar_EventDumpRecorder_create(/* OUT */ easyar_EventDumpRecorder * * Return);
/// <summary>
/// Starts recording.
/// </summary>
bool easyar_EventDumpRecorder_start(easyar_EventDumpRecorder * This, easyar_String * filePath, int initalScreenRotation);
/// <summary>
/// Stops recording.
/// </summary>
void easyar_EventDumpRecorder_stop(easyar_EventDumpRecorder * This);
void easyar_EventDumpRecorder__dtor(easyar_EventDumpRecorder * This);
void easyar_EventDumpRecorder__retain(const easyar_EventDumpRecorder * This, /* OUT */ easyar_EventDumpRecorder * * Return);
const char * easyar_EventDumpRecorder__typeName(const easyar_EventDumpRecorder * This);

#ifdef __cplusplus
}
#endif

#endif
