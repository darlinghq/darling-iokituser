// created for Darling
//
// same deal as with `IOHIDEvent.h`

#ifndef _IOKIT_HID_IOHIDSESSIONPRIVATE_H
#define _IOKIT_HID_IOHIDSESSIONPRIVATE_H

#include <CoreFoundation/CoreFoundation.h>
#include <IOKit/hid/IOHIDSession.h>

__BEGIN_DECLS

CF_ASSUME_NONNULL_BEGIN
CF_IMPLICIT_BRIDGING_ENABLED

void _IOHIDSessionReleasePrivate(IOHIDServiceRef session);

CF_IMPLICIT_BRIDGING_DISABLED
CF_ASSUME_NONNULL_END

__END_DECLS

#endif // _IOKIT_HID_IOHIDSESSIONPRIVATE_H
