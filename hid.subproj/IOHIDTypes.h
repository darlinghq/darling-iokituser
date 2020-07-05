// created for Darling
//
// same deal as with `IOHIDEvent.h`

#ifndef _IOKIT_HID_HIDTYPES_H
#define _IOKIT_HID_HIDTYPES_H

#include <CoreFoundation/CoreFoundation.h>

__BEGIN_DECLS

CF_ASSUME_NONNULL_BEGIN
CF_IMPLICIT_BRIDGING_ENABLED

typedef struct CF_BRIDGED_TYPE(id) __IOHIDService* IOHIDServiceRef;
typedef struct CF_BRIDGED_TYPE(id) __IOHIDSession* IOHIDSessionRef;
typedef const struct CF_BRIDGED_TYPE(id) __IOHIDNotification* IOHIDNotificationRef;

CF_IMPLICIT_BRIDGING_DISABLED
CF_ASSUME_NONNULL_END

__END_DECLS

#endif // _IOKIT_HID_HIDTYPES_H
