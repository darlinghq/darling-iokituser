// created for Darling
//
// original file from Apple's IOKitUser was just empty
// guess they got some stuff in here they don't want others knowing about ¯\_(ツ)_/¯
//
// pretty pointless anyways since the important stuff (the typedef) was already in `hidobjcbase.h`
// and a few more clues were scattered throughout the open source code
//
// Apple, why do you always half-ass open source?

#ifndef _IOKIT_HID_IOHIDEVENT_H
#define _IOKIT_HID_IOHIDEVENT_H

#include <CoreFoundation/CoreFoundation.h>
#include <IOKit/hid/IOHIDEventTypes.h>

// looks like some files that depend on this header indirectly
// expect this to be included
#include <stdatomic.h>

__BEGIN_DECLS

CF_ASSUME_NONNULL_BEGIN
CF_IMPLICIT_BRIDGING_ENABLED

typedef struct CF_BRIDGED_TYPE(id) __IOHIDEvent* IOHIDEventRef;

typedef void (*IOHIDEventCallback)(void* _Nullable target, void* _Nullable refcon, void* _Nullable sender, IOHIDEventRef event);

CFTypeID IOHIDEventGetTypeID();

boolean_t IOHIDEventConformsTo(IOHIDEventRef event, IOHIDEventType type);

CFArrayRef IOHIDEventGetChildren(IOHIDEventRef event);

IOHIDEventType IOHIDEventGetType(IOHIDEventRef event);

CFIndex IOHIDEventGetIntegerValue(IOHIDEventRef event, IOHIDEventField field);

IOHIDEventRef IOHIDEventCreateVendorDefinedEvent(CFAllocatorRef allocator, uint64_t timestamp, uint32_t page, uint32_t usage, uint32_t version, uint8_t* data, uint32_t length, IOOptionBits options);

// `IOOptionBits` is a guess here; all calls to this function provide `0` for the last argument
void IOHIDEventAppendEvent(IOHIDEventRef target_event, IOHIDEventRef event_to_append, IOOptionBits options);

void IOHIDEventGetVendorDefinedData(IOHIDEventRef event, uint8_t** data, CFIndex* data_length);

CF_IMPLICIT_BRIDGING_DISABLED
CF_ASSUME_NONNULL_END

__END_DECLS

#endif // _IOKIT_HID_IOHIDEVENT_H
