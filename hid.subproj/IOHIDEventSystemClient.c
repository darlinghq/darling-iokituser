// created for Darling

#include <IOKit/hid/IOHIDEventSystemClient.h>
#include <IOKit/hid/IOHIDEventSystemClientPrivate.h>
#include <CoreFoundation/CFRuntime.h>
#include <pthread.h>
#include "stub-log.h"

DARLING_STUB_HEADER;

// following the same pattern as `IOHIDValue.c`
typedef struct __IOHIDEventSystemClient {
	CFRuntimeBase cfBase;
} __IOHIDEventSystemClient;

static const CFRuntimeClass __IOHIDEventSystemClientClass = {
	0,                        // version
	"IOHIDEventSystemClient", // className
	NULL,                     // init
	NULL,                     // copy
	NULL,                     // finalize
	NULL,                     // equal
	NULL,                     // hash
	NULL,                     // copyFormattingDesc
	NULL,                     // copyDebugDesc
	NULL,                     // reclaim
	NULL,                     // refcount
};

static CFTypeID __eventSystemClientTypeID = _kCFRuntimeNotATypeID;
static pthread_once_t __eventSystemClientTypeInit = PTHREAD_ONCE_INIT;

void __IOHIDEventSystemClientRegister() {
	__eventSystemClientTypeID = _CFRuntimeRegisterClass(&__IOHIDEventSystemClientClass);
};

CFTypeID IOHIDEventSystemClientGetTypeID(void) {
	/* initialize runtime */
	if (__eventSystemClientTypeID == _kCFRuntimeNotATypeID)
		pthread_once(&__eventSystemClientTypeInit, __IOHIDEventSystemClientRegister);

	return __eventSystemClientTypeID;
};

CFTypeRef IOHIDEventSystemClientCopyProperty(IOHIDEventSystemClientRef client, CFStringRef key) {
	DARLING_STUB_LOG;
	return NULL;
};

IOHIDServiceClientRef IOHIDEventSystemClientCopyServiceForRegistryID(IOHIDEventSystemClientRef client, uint64_t id) {
	DARLING_STUB_LOG;
	return NULL;
};

CFArrayRef IOHIDEventSystemClientCopyServices(IOHIDEventSystemClientRef client) {
	DARLING_STUB_LOG;
	return CFArrayCreate(NULL, NULL, 0, NULL);
};

IOHIDEventSystemClientRef IOHIDEventSystemClientCreateWithType(CFAllocatorRef allocator, IOHIDEventSystemClientType client_type, CFDictionaryRef attrs) {
	DARLING_STUB_LOG;
	uint32_t size = sizeof(__IOHIDEventSystemClient) - sizeof(CFRuntimeBase);
	return (IOHIDEventSystemClientRef)_CFRuntimeCreateInstance(allocator, IOHIDEventSystemClientGetTypeID(), size, NULL);
};

Boolean IOHIDEventSystemClientSetProperty(IOHIDEventSystemClientRef client, CFStringRef key, CFTypeRef property) {
	DARLING_STUB_LOG;
	return 0;
};
