#import "EasyArEngineBridge.h"

#import <easyar/engine.oc.h>
#import <easyar/camera.oc.h>
#import <easyar/imagetracker.oc.h>

@implementation EasyArEngineBridge

+ (NSString *)initializeWithKey:(NSString *)key
{
    if (key == nil || key.length == 0) {
        return @"Sense key vazia.";
    }
    BOOL ok = [easyar_Engine initialize:key];
    if (ok) {
        return nil;
    }
    NSString *err = [easyar_Engine errorMessage];
    return err.length > 0 ? err : @"Engine.initialize retornou false (sem mensagem).";
}

+ (BOOL)isCameraDeviceAvailable
{
    return [easyar_CameraDevice isAvailable];
}

+ (BOOL)isImageTrackerAvailable
{
    return [easyar_ImageTracker isAvailable];
}

+ (NSString *)sdkVersion
{
    NSString *v = [easyar_Engine versionString];
    return v != nil ? v : @"desconhecida";
}

@end
