// created for Darling
//
// same deal as with `IOHIDEvent.h`

#ifndef _IOKIT_HID_HIDSERVICE_PRIVATE_H
#define _IOKIT_HID_HIDSERVICE_PRIVATE_H

#include <CoreFoundation/CoreFoundation.h>
#include <IOKit/hid/IOHIDService.h>

__BEGIN_DECLS

CF_ASSUME_NONNULL_BEGIN
CF_IMPLICIT_BRIDGING_ENABLED

typedef struct IOHIDServiceVirtualCallbacksV2 IOHIDServiceVirtualCallbacksV2;
typedef struct __IOHIDServiceQueueContext __IOHIDServiceQueueContext;

void _IOHIDServiceReleasePrivate(IOHIDServiceRef svc);

CF_IMPLICIT_BRIDGING_DISABLED
CF_ASSUME_NONNULL_END

__END_DECLS

#endif // _IOKIT_HID_HIDSERVICE_PRIVATE_H
