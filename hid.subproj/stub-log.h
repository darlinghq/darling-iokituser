// created for Darling

#ifndef _DARLING_IOKIT_HID_STUB_LOG_H
#define _DARLING_IOKIT_HID_STUB_LOG_H

#include <stdio.h>

#define DARLING_STUB_HEADER \
	static int darling_stub_log_verbose = 0; \
	__attribute__((constructor)) \
	static void darling_stub_log_init(void) { \
		darling_stub_log_verbose = getenv("STUB_VERBOSE") != NULL; \
	}

#define DARLING_STUB_LOG \
	if (darling_stub_log_verbose) printf("DARLING STUB CALLED: %s\n", __PRETTY_FUNCTION__);

#endif // _DARLING_IOKIT_HID_STUB_LOG_H
