// created for Darling

#include <IOKit/hid/IOHIDService.h>
#include <IOKit/hid/IOHIDServicePrivate.h>
#include "stub-log.h"

DARLING_STUB_HEADER;

CFStringRef IOHIDServiceCopyDescription(IOHIDServiceRef svc) {
	DARLING_STUB_LOG;
	return CFSTR("");
};

void _IOHIDServiceReleasePrivate(IOHIDServiceRef svc) {
	DARLING_STUB_LOG;
};
