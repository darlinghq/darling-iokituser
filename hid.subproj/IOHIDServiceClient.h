// created for Darling
//
// same deal as with `IOHIDEvent.h`

#ifndef _IOKIT_HID_IOHIDSERVICE_CLIENT_H
#define _IOKIT_HID_IOHIDSERVICE_CLIENT_H

#include <CoreFoundation/CoreFoundation.h>
#include <IOKit/hidsystem/IOHIDServiceClient.h>

__BEGIN_DECLS

CF_ASSUME_NONNULL_BEGIN
CF_IMPLICIT_BRIDGING_ENABLED

typedef void (*IOHIDServiceClientCallback)(void* target, void* refcon, IOHIDServiceClientRef service);

typedef void (^IOHIDServiceClientBlock)(void* target, void* refcon, IOHIDServiceClientRef service);

typedef struct __IOHIDVirtualServiceClientCallbacksV2 IOHIDVirtualServiceClientCallbacksV2;

typedef struct _IOHIDServiceClientUsagePair IOHIDServiceClientUsagePair;

CF_IMPLICIT_BRIDGING_DISABLED
CF_ASSUME_NONNULL_END

__END_DECLS

#endif // _IOKIT_HID_IOHIDSERVICE_CLIENT_H
