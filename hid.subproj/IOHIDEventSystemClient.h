// created for Darling
//
// same deal as with `IOHIDEvent.h`

#ifndef _IOKIT_IOHIDEVENTSYSTEMCLIENT_H
#define _IOKIT_IOHIDEVENTSYSTEMCLIENT_H

#include <IOKit/hidsystem/IOHIDEventSystemClient.h>
#include <IOKit/hidsystem/IOHIDServiceClient.h>
#include <dispatch/dispatch.h>

// i'm actually not sure what kind of type this is
typedef uint32_t IOHIDEventSystemClientType;

enum {
	kIOHIDEventSystemClientTypeAdmin,
	kIOHIDEventSystemClientTypeMonitor,
	kIOHIDEventSystemClientTypePassive,
	kIOHIDEventSystemClientTypeRateControlled,
};

IOHIDEventSystemClientRef IOHIDEventSystemClientCreateWithType(CFAllocatorRef allocator, IOHIDEventSystemClientType client_type, CFDictionaryRef attrs);

IOHIDEventSystemClientRef IOHIDEventSystemClientCreate(CFAllocatorRef allocator);

void IOHIDEventSystemClientSetMatching(IOHIDEventSystemClientRef client, CFDictionaryRef matching);

IOHIDServiceClientRef IOHIDEventSystemClientCopyServiceForRegistryID(IOHIDEventSystemClientRef client, uint64_t id);

// The queue the client's callbacks run on, set before the client is activated.
void IOHIDEventSystemClientSetDispatchQueue(IOHIDEventSystemClientRef client, dispatch_queue_t queue);
// Starts and stops the delivery of the client's callbacks.
void IOHIDEventSystemClientActivate(IOHIDEventSystemClientRef client);
void IOHIDEventSystemClientCancel(IOHIDEventSystemClientRef client);

#endif // _IOKIT_IOHIDEVENTSYSTEMCLIENT_H
