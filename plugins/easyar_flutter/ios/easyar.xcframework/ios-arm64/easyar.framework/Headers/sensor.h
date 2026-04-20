//=============================================================================================================================
//
// EasyAR Sense 4.8.0.11837-e0e3282d9
// Copyright (c) 2015-2026 VisionStar Information Technology (Shanghai) Co., Ltd. All Rights Reserved.
// EasyAR is the registered trademark or trademark of VisionStar Information Technology (Shanghai) Co., Ltd in China
// and other countries for the augmented reality technology developed by VisionStar Information Technology (Shanghai) Co., Ltd.
//
//=============================================================================================================================

#ifndef __EASYAR_SENSOR_H__
#define __EASYAR_SENSOR_H__

#include "easyar/types.h"

#ifdef __cplusplus
extern "C" {
#endif

void easyar_BlockPriorResult_blockIds(easyar_BlockPriorResult * This, /* OUT */ easyar_ListOfString * * Return);
void easyar_BlockPriorResult_mode(easyar_BlockPriorResult * This, /* OUT */ easyar_String * * Return);
void easyar_BlockPriorResult_create(easyar_ListOfString * blockIds, easyar_BlockPriorMode mode, /* OUT */ easyar_BlockPriorResult * * Return);
void easyar_BlockPriorResult__dtor(easyar_BlockPriorResult * This);
void easyar_BlockPriorResult__retain(const easyar_BlockPriorResult * This, /* OUT */ easyar_BlockPriorResult * * Return);
const char * easyar_BlockPriorResult__typeName(const easyar_BlockPriorResult * This);

void easyar_ListOfString__ctor(easyar_String * const * begin, easyar_String * const * end, /* OUT */ easyar_ListOfString * * Return);
void easyar_ListOfString__dtor(easyar_ListOfString * This);
void easyar_ListOfString_copy(const easyar_ListOfString * This, /* OUT */ easyar_ListOfString * * Return);
int easyar_ListOfString_size(const easyar_ListOfString * This);
easyar_String * easyar_ListOfString_at(const easyar_ListOfString * This, int index);

#ifdef __cplusplus
}
#endif

#endif
