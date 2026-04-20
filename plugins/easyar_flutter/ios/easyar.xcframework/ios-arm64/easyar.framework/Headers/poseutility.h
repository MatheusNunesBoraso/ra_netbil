//=============================================================================================================================
//
// EasyAR Sense 4.8.0.11837-e0e3282d9
// Copyright (c) 2015-2026 VisionStar Information Technology (Shanghai) Co., Ltd. All Rights Reserved.
// EasyAR is the registered trademark or trademark of VisionStar Information Technology (Shanghai) Co., Ltd in China
// and other countries for the augmented reality technology developed by VisionStar Information Technology (Shanghai) Co., Ltd.
//
//=============================================================================================================================

#ifndef __EASYAR_POSEUTILITY_H__
#define __EASYAR_POSEUTILITY_H__

#include "easyar/types.h"

#ifdef __cplusplus
extern "C" {
#endif

easyar_OptionalOfMatrix44F easyar_PoseUtility_createPoseWithHardwareOffset(easyar_Vec3F position, easyar_Vec4F rotation, easyar_OptionalOfVec3F offsetPosition, easyar_OptionalOfVec4F offsetRotation);
void easyar_PoseUtility__dtor(easyar_PoseUtility * This);
void easyar_PoseUtility__retain(const easyar_PoseUtility * This, /* OUT */ easyar_PoseUtility * * Return);
const char * easyar_PoseUtility__typeName(const easyar_PoseUtility * This);

#ifdef __cplusplus
}
#endif

#endif
