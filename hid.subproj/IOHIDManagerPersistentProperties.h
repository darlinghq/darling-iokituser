// created for Darling
//
// same deal as with `IOHIDEvent.h`

#ifndef _IOKIT_HID_IOHIDMANAGER_PERSISTENTPROPERTIES_H
#define _IOKIT_HID_IOHIDMANAGER_PERSISTENTPROPERTIES_H

#include <CoreFoundation/CoreFoundation.h>
#include <IOKit/hid/IOHIDManager.h>

__BEGIN_DECLS

CF_ASSUME_NONNULL_BEGIN
CF_IMPLICIT_BRIDGING_ENABLED

// these key values are guesses
//
// the exact values are probably not important because
// any code that uses them is supposed to use these constants
#define kIOHIDManagerUUIDKey "IOHIDManagerUUIDKey"
#define kIOHIDManagerKey "IOHIDManagerKey"

typedef struct __IOHIDPropertyContext {
	CFStringRef applicationID;
	CFStringRef userName;
	CFStringRef hostName;
	IOOptionBits options;
} __IOHIDPropertyContext;

typedef struct __IOHIDApplyPropertyToSetContext {
	CFStringRef key;
	CFTypeRef property;
} __IOHIDApplyPropertyToSetContext;

CFStringRef __IOHIDManagerGetRootKey();
CFStringRef __IOHIDDeviceGetUUIDKey(IOHIDDeviceRef device);

void __IOHIDSaveElementSet(const void* value, void* context);
void __IOHIDLoadElementSet(const void* value, void* context);

void __IOHIDPropertySaveToKeyWithSpecialKeys(CFDictionaryRef dictionary, CFStringRef key, CFStringRef* specialKeys, __IOHIDPropertyContext* context);

void __IOHIDElementLoadProperties(IOHIDElementRef element);

void __IOHIDPropertySaveWithContext(CFStringRef key, CFPropertyListRef value, __IOHIDPropertyContext* context);

CFMutableDictionaryRef __IOHIDPropertyLoadDictionaryFromKey(CFStringRef key);
CFMutableDictionaryRef __IOHIDPropertyLoadFromKeyWithSpecialKeys(CFStringRef key, CFStringRef* specialKeys);

void __IOHIDManagerLoadProperties(IOHIDManagerRef manager);
void __IOHIDManagerSaveProperties(IOHIDManagerRef manager, __IOHIDPropertyContext* context);

void __IOHIDDeviceSaveProperties(IOHIDDeviceRef device, __IOHIDPropertyContext* context);
void __IOHIDDeviceLoadProperties(IOHIDDeviceRef device);

void __IOHIDApplyPropertiesToDeviceFromDictionary(const void* key, const void* value, void *context);

void __IOHIDApplyPropertyToDeviceSet(const void* value, void* context);

void __IOHIDSaveDeviceSet(const void* value, void* context);

CF_IMPLICIT_BRIDGING_DISABLED
CF_ASSUME_NONNULL_END

__END_DECLS

#endif // _IOKIT_HID_IOHIDMANAGER_PERSISTENTPROPERTIES_H
