// created for Darling
//
// same deal as with `IOHIDEvent.h`

#ifndef _IOKIT_HID_IOHIDEVENTSYSTEM_CONNECTION_H
#define _IOKIT_HID_IOHIDEVENTSYSTEM_CONNECTION_H

#include <CoreFoundation/CoreFoundation.h>

__BEGIN_DECLS

CF_ASSUME_NONNULL_BEGIN
CF_IMPLICIT_BRIDGING_ENABLED

typedef struct CF_BRIDGED_TYPE(id) __IOHIDEventSystemConnection* IOHIDEventSystemConnectionRef;

CFStringRef IOHIDEventSystemConnectionCopyDescription(IOHIDEventSystemConnectionRef conn);

CF_IMPLICIT_BRIDGING_DISABLED
CF_ASSUME_NONNULL_END

__END_DECLS

#endif // _IOKIT_HID_IOHIDEVENTSYSTEM_CONNECTION_H
