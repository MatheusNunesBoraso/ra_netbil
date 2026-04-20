#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// Bridge Obj-C que encapsula chamadas ao SDK EasyAR.
///
/// Feito em ObjC (e nao Swift direto) porque os headers do EasyAR sao
/// `.oc.h` (Objective-C) e a interop Swift <-> ObjC-framework sem
/// modulemap customizado e frágil. Swift chama essas class methods e
/// trabalha com NSString/BOOL — sem precisar importar nada do easyar.
@interface EasyArEngineBridge : NSObject

/// Inicializa a engine EasyAR com a chave Sense. Returns nil on success,
/// ou a mensagem de erro do SDK se falhar.
+ (nullable NSString *)initializeWithKey:(NSString *)key;

/// Retorna YES se o device suporta `CameraDevice` do EasyAR.
+ (BOOL)isCameraDeviceAvailable;

/// Retorna YES se o device suporta `ImageTracker` do EasyAR.
+ (BOOL)isImageTrackerAvailable;

/// Versao do SDK EasyAR linkado.
+ (NSString *)sdkVersion;

@end

NS_ASSUME_NONNULL_END
