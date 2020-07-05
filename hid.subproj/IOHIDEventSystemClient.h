// created for Darling
//
// same deal as with `IOHIDEvent.h`

#ifndef _IOKIT_IOHIDEVENTSYSTEMCLIENT_H
#define _IOKIT_IOHIDEVENTSYSTEMCLIENT_H

#include <IOKit/hidsystem/IOHIDEventSystemClient.h>
#include <IOKit/hidsystem/IOHIDServiceClient.h>

// i'm actually not sure what kind of type this is
typedef uint32_t IOHIDEventSystemClientType;

enum {
	kIOHIDEventSystemClientTypeAdmin,
	kIOHIDEventSystemClientTypeMonitor,
	kIOHIDEventSystemClientTypePassive,
	kIOHIDEventSystemClientTypeRateControlled,
};

IOHIDEventSystemClientRef IOHIDEventSystemClientCreateWithType(CFAllocatorRef allocator, IOHIDEventSystemClientType client_type, CFDictionaryRef attrs);

IOHIDServiceClientRef IOHIDEventSystemClientCopyServiceForRegistryID(IOHIDEventSystemClientRef client, uint64_t id);

#endif // _IOKIT_IOHIDEVENTSYSTEMCLIENT_H
