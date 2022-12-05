// created for Darling
//
// same deal as with `IOHIDEvent.h`

#ifndef _IOKIT_HID_IOHIDSERVICEPLUGIN_H_
#define _IOKIT_HID_IOHIDSERVICEPLUGIN_H_

#include <CoreFoundation/CoreFoundation.h>
#include <IOKit/hid/IOHIDEvent.h>

__BEGIN_DECLS

CF_ASSUME_NONNULL_BEGIN
CF_IMPLICIT_BRIDGING_ENABLED

typedef struct IOHIDServiceInterface IOHIDServiceInterface;
typedef struct IOHIDServiceInterface2 IOHIDServiceInterface2;
typedef struct IOHIDServiceFastPathInterface IOHIDServiceFastPathInterface;

typedef void (*IOHIDServiceEventCallback)(void* _Nullable target, void* _Nullable refcon, void* _Nullable sender, IOHIDEventRef event, IOOptionBits options);

CF_IMPLICIT_BRIDGING_DISABLED
CF_ASSUME_NONNULL_END

__END_DECLS

#endif // _IOKIT_HID_IOHIDSERVICEPLUGIN_H_
