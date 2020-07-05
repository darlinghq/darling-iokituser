// created for Darling
//
// same deal as with `IOHIDEvent.h`

#ifndef _IOKIT_HID_IOHIDSESSION_H
#define _IOKIT_HID_IOHIDSESSION_H

#include <CoreFoundation/CoreFoundation.h>
#include <IOKit/hid/IOHIDTypes.h>

__BEGIN_DECLS

CF_ASSUME_NONNULL_BEGIN
CF_IMPLICIT_BRIDGING_ENABLED

CFTypeID IOHIDSessionGetTypeID();

CF_IMPLICIT_BRIDGING_DISABLED
CF_ASSUME_NONNULL_END

__END_DECLS

#endif // _IOKIT_HID_IOHIDSESSION_H
