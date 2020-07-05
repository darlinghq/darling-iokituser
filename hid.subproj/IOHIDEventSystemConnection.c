// created for Darling

#include <IOKit/hid/IOHIDEventSystemConnection.h>
#include <IOKit/hid/IOHIDEventSystemConnectionPrivate.h>
#include "stub-log.h"

DARLING_STUB_HEADER;

CFStringRef IOHIDEventSystemConnectionCopyDescription(IOHIDEventSystemConnectionRef conn) {
	DARLING_STUB_LOG;
	return CFSTR("");
};

void _IOHIDEventSystemConnectionReleasePrivate(IOHIDEventSystemConnectionRef conn) {
	DARLING_STUB_LOG;
};
