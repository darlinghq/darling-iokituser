// created for Darling
//
// same deal as with `IOHIDEvent.h`

#ifndef _IOKIT_HID_IOHIDEVENTSYSTEM_CONNECTION_PRIVATE_H
#define _IOKIT_HID_IOHIDEVENTSYSTEM_CONNECTION_PRIVATE_H

#include <CoreFoundation/CoreFoundation.h>
#include <IOKit/hid/IOHIDEventSystemConnection.h>

__BEGIN_DECLS

CF_ASSUME_NONNULL_BEGIN
CF_IMPLICIT_BRIDGING_ENABLED

typedef void (*IOHIDEventSystemConnectionTerminationCallback)(IOHIDEventSystemConnectionRef client, void* _Nullable refcon);
typedef Boolean (*IOHIDEventSystemConnectionDemuxCallback)(IOHIDEventSystemConnectionRef client, mach_msg_header_t* request, mach_msg_header_t* reply, void * _Nullable refcon);

typedef union IOHIDEventSystemConnectionEntitlements IOHIDEventSystemConnectionEntitlements;

void _IOHIDEventSystemConnectionReleasePrivate(IOHIDEventSystemConnectionRef conn);

CF_IMPLICIT_BRIDGING_DISABLED
CF_ASSUME_NONNULL_END

__END_DECLS

#endif // _IOKIT_HID_IOHIDEVENTSYSTEM_CONNECTION_PRIVATE_H
