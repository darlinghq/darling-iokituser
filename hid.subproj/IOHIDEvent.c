/*
 * Copyright (c) 1999-2008 Apple Computer, Inc.  All Rights Reserved.
 *
 * @APPLE_LICENSE_HEADER_START@
 * 
 * This file contains Original Code and/or Modifications of Original Code
 * as defined in and that are subject to the Apple Public Source License
 * Version 2.0 (the 'License'). You may not use this file except in
 * compliance with the License. Please obtain a copy of the License at
 * http://www.opensource.apple.com/apsl/ and read it before using this
 * file.
 * 
 * The Original Code and all software distributed under the License are
 * distributed on an 'AS IS' basis, WITHOUT WARRANTY OF ANY KIND, EITHER
 * EXPRESS OR IMPLIED, AND APPLE HEREBY DISCLAIMS ALL SUCH WARRANTIES,
 * INCLUDING WITHOUT LIMITATION, ANY WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE, QUIET ENJOYMENT OR NON-INFRINGEMENT.
 * Please see the License for the specific language governing rights and
 * limitations under the License.
 * 
 * @APPLE_LICENSE_HEADER_END@
 */
// modified for Darling
//
// technically, it was *created* for Darling, because the file used to only contain that Apple copyright header

#include <IOKit/hid/IOHIDEvent.h>
#include <IOKit/hid/IOHIDEventPrivate.h>
#include "stub-log.h"

DARLING_STUB_HEADER;

void IOHIDEventAppendEvent(IOHIDEventRef target_event, IOHIDEventRef event_to_append, IOOptionBits options) {
	DARLING_STUB_LOG;
};

boolean_t IOHIDEventConformsTo(IOHIDEventRef event, IOHIDEventType type) {
	DARLING_STUB_LOG;
	return 0;
};

CFStringRef IOHIDEventCopyDescription(IOHIDEventRef event) {
	DARLING_STUB_LOG;
	return CFSTR("");
};

IOHIDEventRef IOHIDEventCreateVendorDefinedEvent(CFAllocatorRef allocator, uint64_t timestamp, uint32_t page, uint32_t usage, uint32_t version, uint8_t* data, uint32_t length, IOOptionBits options) {
	DARLING_STUB_LOG;
	return NULL;
};

CFArrayRef IOHIDEventGetChildren(IOHIDEventRef event) {
	DARLING_STUB_LOG;
	return CFArrayCreate(NULL, NULL, 0, NULL);
};

CFIndex IOHIDEventGetIntegerValue(IOHIDEventRef event, IOHIDEventField field) {
	DARLING_STUB_LOG;
	return 0;
};

IOHIDEventType IOHIDEventGetType(IOHIDEventRef event) {
	DARLING_STUB_LOG;
	return kIOHIDEventTypeNULL;
};

void IOHIDEventGetVendorDefinedData(IOHIDEventRef event, uint8_t** data, CFIndex* data_length) {
	DARLING_STUB_LOG;
	if (data)
		*data = NULL;
	if (data_length)
		*data_length = 0;
};
