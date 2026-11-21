/*
 * Copyright (C) 2026 Lubos Dolezel
 *
 * Factory of the IOHIDLib plug-in: the IOHIDDevice user client interface
 * (IOHIDManager and IOHIDDevice go through it) and its obsolete predecessor.
 * The power source and fast-path service plug-in types of the same plug-in
 * are not provided.
 */
#include <TargetConditionals.h>

#include <IOKit/hid/IOHIDDevicePlugIn.h>
#include <IOKit/hid/IOHIDServicePlugIn.h>
#include "IOHIDIUnknown.h"
#import "IOHIDDeviceClass.h"
#import "IOHIDObsoleteDeviceClass.h"

extern "C" void *IOHIDLibFactory(CFAllocatorRef allocator __unused, CFUUIDRef typeID);

void *IOHIDLibFactory(CFAllocatorRef allocator __unused, CFUUIDRef typeID)
{
    IOCFPlugInInterface **interface = NULL;

    if (CFEqual(typeID, kIOHIDDeviceUserClientTypeID)) {
        IOHIDObsoleteDeviceClass *device = [[IOHIDObsoleteDeviceClass alloc] init];
        [device queryInterface:CFUUIDGetUUIDBytes(kIOHIDDeviceInterfaceID)
               outInterface:(LPVOID *)&interface];
    } else if (CFEqual(typeID, kIOHIDDeviceTypeID)) {
        IOHIDDeviceClass *device = [[IOHIDDeviceClass alloc] init];
        [device queryInterface:CFUUIDGetUUIDBytes(kIOHIDDeviceDeviceInterfaceID)
                  outInterface:(LPVOID *)&interface];
    }

    return (void *)interface;
}
