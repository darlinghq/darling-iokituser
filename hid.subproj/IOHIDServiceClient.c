// created for Darling

#include <IOKit/hid/IOHIDServiceClient.h>
#include <IOKit/hid/IOHIDServiceClientPrivate.h>
#include <IOKit/hid/IOHIDEvent.h>
#include "stub-log.h"

DARLING_STUB_HEADER;

boolean_t IOHIDServiceClientConformsTo(IOHIDServiceClientRef service, uint32_t usagePage, uint32_t usage) {
	DARLING_STUB_LOG;
	return 0;
};

CFStringRef IOHIDServiceClientCopyDescription(IOHIDServiceClientRef service) {
	DARLING_STUB_LOG;
	return CFSTR("");
};

CFTypeRef IOHIDServiceClientCopyProperty(IOHIDServiceClientRef service, CFStringRef key) {
	DARLING_STUB_LOG;
	return NULL;
};

IOHIDEventRef IOHIDServiceClientCopyEvent(IOHIDServiceClientRef service, int64_t type, int32_t options, int64_t matching) {
	DARLING_STUB_LOG;
	return NULL;
};

Boolean IOHIDServiceClientSetProperty(IOHIDServiceClientRef service, CFStringRef key, CFTypeRef property) {
	DARLING_STUB_LOG;
	return 0;
};

void _IOHIDServiceClientReleasePrivate(IOHIDServiceClientRef service) {
	DARLING_STUB_LOG;
};
