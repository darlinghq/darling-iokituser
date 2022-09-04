project(IOKitUser)

remove_sdk_framework(IOKit)

add_compile_definitions(
	# from Xcode build files
	IOKIT
	__MigTypeCheck=1
	APPLE
	_ANSI_C_SOURCE
	volatile=__volatile
	HAVE_CFPLUGIN
	HAVE_CFURLACCESS
	DISPATCH_MACH_SPI=1
	OS_CRASH_ENABLE_EXPERIMENTAL_LIBTRACE=1

	# not in Xcode build files, but seems necessary to us
	_DARWIN_NO_64_BIT_INODE=1
	PRIVATE
)

include_directories(
	${CMAKE_CURRENT_SOURCE_DIR}
	${CMAKE_CURRENT_SOURCE_DIR}/include
	${CMAKE_CURRENT_SOURCE_DIR}/internal-include
	${CMAKE_CURRENT_SOURCE_DIR}/hid.subproj
	${CMAKE_CURRENT_BINARY_DIR}
	${CMAKE_CURRENT_BINARY_DIR}/pwr_mgt.subproj
	${CMAKE_CURRENT_BINARY_DIR}/kext.subproj
)

add_compile_options(
	-fconstant-cfstrings
)

set(MIG_ARCH "x86_64")
set(MIG_USER_SOURCE_SUFFIX "64.c")
set(MIG_USER_HEADER_SUFFIX "64.h")
set(MIG_SERVER_SOURCE_SUFFIX "Server64.c")
set(MIG_SERVER_HEADER_SUFFIX "Server64.h")
set(MIG_XTRACE_SUFFIX "XtraceMig64.c")
mig(iokitmig.defs)

set(MIG_ARCH "i386")
set(MIG_USER_SOURCE_SUFFIX "32.c")
set(MIG_USER_HEADER_SUFFIX "32.h")
set(MIG_SERVER_SOURCE_SUFFIX "Server32.c")
set(MIG_SERVER_HEADER_SUFFIX "Server32.h")
set(MIG_XTRACE_SUFFIX "XtraceMig32.c")
mig(iokitmig.defs)

unset(MIG_ARCH)
unset(MIG_USER_SOURCE_SUFFIX)
unset(MIG_USER_HEADER_SUFFIX)
unset(MIG_SERVER_SOURCE_SUFFIX)
unset(MIG_SERVER_HEADER_SUFFIX)
unset(MIG_XTRACE_SUFFIX)
#mig(hid.subproj/IOHIDEventSystemClientMIG.defs)
#mig(hid.subproj/IOHIDEventSystemMIG.defs)
mig(kext.subproj/kextmanager_mig.defs)
mig(pwr_mgt.subproj/powermanagement.defs)

add_custom_target(iokit_generate_mig
	DEPENDS
		${CMAKE_CURRENT_BINARY_DIR}/iokitmig32.c
		${CMAKE_CURRENT_BINARY_DIR}/iokitmig64.c
)

set(iokit_sources
	IOCFPlugIn.c
	IOCFSerialize.c
	IOCFUnserialize.tab.c
	IOCFURLAccess.c
	IODataQueueClient.c
	IOKitLib.c
	IOMIGMachPort.c
	IOSystemConfiguration.c
	#IOTrap.S # we don't need it and even if we did, our IOKit is in userspace, so we would have a define a custom `iokit_user_client_trap` function
	graphics.subproj/IOAccelSurfaceControl.c
	graphics.subproj/IODisplayLib.c
	graphics.subproj/IOGraphicsLib.c
	hid.subproj/HIDConnectionBase.m
	hid.subproj/HIDDeviceBase.m
	hid.subproj/HIDElementBase.m
	hid.subproj/HIDEventBase.m
	hid.subproj/HIDServiceBase.m
	hid.subproj/HIDServiceClientBase.m
	hid.subproj/HIDSessionBase.m
	hid.subproj/IOHIDAnalytics.c
	hid.subproj/IOHIDConnectionFilter.c
	hid.subproj/IOHIDConnectionObjc.m
	hid.subproj/IOHIDDevice.c
	hid.subproj/IOHIDDeviceObjc.m
	hid.subproj/IOHIDElement.c
	hid.subproj/IOHIDElementObjc.m
	hid.subproj/IOHIDEvent.c
	hid.subproj/IOHIDEventObjc.m
	hid.subproj/IOHIDEventQueue.c
	hid.subproj/IOHIDEventServer.c
	hid.subproj/IOHIDEventSystem.c
	hid.subproj/IOHIDEventSystemClient.c
	hid.subproj/IOHIDEventSystemConnection.c
	hid.subproj/IOHIDEventSystemPrivate.c
	hid.subproj/IOHIDLibPrivate.c
	hid.subproj/IOHIDManager.c
	hid.subproj/IOHIDNotification.c
	hid.subproj/IOHIDPlugins.c
	hid.subproj/IOHIDQueue.c
	hid.subproj/IOHIDService.c
	hid.subproj/IOHIDServiceClient.c
	hid.subproj/IOHIDServiceClientObjc.m
	hid.subproj/IOHIDServiceConnectionCache.c
	hid.subproj/IOHIDServiceFilter.c
	hid.subproj/IOHIDServiceKeys.c
	hid.subproj/IOHIDServiceObjc.m
	hid.subproj/IOHIDSession.c
	hid.subproj/IOHIDSessionFilter.c
	hid.subproj/IOHIDSessionObjc.m
	hid.subproj/IOHIDTransaction.c
	hid.subproj/IOHIDUserDevice.c
	hid.subproj/IOHIDValue.c
	hidsystem.subproj/IOEventStatusAPI.c
	hidsystem.subproj/IOHIDLib.c
	kext.subproj/AdjustForNewSegmentLocation.cpp
	kext.subproj/Architectures.hpp
	kext.subproj/cross_link.c
	kext.subproj/fat_util.c
	kext.subproj/FileAbstraction.hpp
	kext.subproj/KextManager.c
	kext.subproj/kextsplit.h
	kext.subproj/macho_util.c
	kext.subproj/MachOFileAbstraction.hpp
	kext.subproj/misc_util.c
	kext.subproj/OSKext.c
	kext.subproj/OSKextVersion.c
	kext.subproj/printPList_new.c
	kext.subproj/Trie.hpp
	network.subproj/IONetworkLib.c
	network.subproj/IOUserEthernetController.c
	platform.subproj/IOPlatformSupport.c
	ps.subproj/IOPowerSources.c
	ps.subproj/IOPowerSourcesPrivate.c
	pwr_mgt.subproj/IOPMAssertions.c
	pwr_mgt.subproj/IOPMAutoWake.c
	pwr_mgt.subproj/IOPMEnergyPrefs.c
	pwr_mgt.subproj/IOPMLib.c
	pwr_mgt.subproj/IOPMLibPrivate.c
	pwr_mgt.subproj/IOPMPowerNotifications.c
	pwr_mgt.subproj/IOPMRepeatingPower.c
	pwr_mgt.subproj/IOPMUPSPrefs.c
	usb.subproj/IOUSBLib.c

	iokitmig.c # it'll automatically include `${CMAKE_CURRENT_BINARY_DIR}/iokitmig32.c` or `${CMAKE_CURRENT_BINARY_DIR}/iokitmig64.c`, depending on what architecture we're building for
	#${CMAKE_CURRENT_BINARY_DIR}/hid.subproj/IOHIDEventSystemClientMIGUser.c
	#${CMAKE_CURRENT_BINARY_DIR}/hid.subproj/IOHIDEventSystemClientMIGServer.c
	#${CMAKE_CURRENT_BINARY_DIR}/hid.subproj/IOHIDEventSystemMIGUser.c
	#${CMAKE_CURRENT_BINARY_DIR}/hid.subproj/IOHIDEventSystemMIGServer.h
	${CMAKE_CURRENT_BINARY_DIR}/kext.subproj/kextmanager_migUser.c
	${CMAKE_CURRENT_BINARY_DIR}/pwr_mgt.subproj/powermanagementUser.c
)

set_source_files_properties(kext.subproj/cross_link.c PROPERTIES
	COMPILE_FLAGS " -DKERNEL"
)

set(DYLIB_CURRENT_VERSION "275.0.0")

set(FRAMEWORK_VERSION "A")

generate_sdk_framework(IOKit
    VERSION ${FRAMEWORK_VERSION}
    HEADER "include/IOKit"
)

add_framework(IOKit CURRENT_VERSION FAT
	VERSION ${FRAMEWORK_VERSION}
	SOURCES
		${iokit_sources}
	DEPENDENCIES
		system
		CoreFoundation
		energytrace
		cxx
		objc
		z
		DiagnosticMessagesClient
		libkxld
)

add_dependencies(IOKit
	iokit_generate_mig
)
