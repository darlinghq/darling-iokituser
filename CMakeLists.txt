project(IOKitUser)

add_definitions(-DIOKIT -D_DARWIN_NO_64_BIT_INODE=1 -DNO_CFPLUGIN=1 -DIOKIT_SERVER_VERSION=20150101)

include_directories(
	${CMAKE_CURRENT_SOURCE_DIR}
	${CMAKE_CURRENT_SOURCE_DIR}/include
	${CMAKE_SOURCE_DIR}/src/external/ruby/include
	${CMAKE_CURRENT_SOURCE_DIR}/internal-include
	${CMAKE_CURRENT_BINARY_DIR}
	${CMAKE_SOURCE_DIR}/kernel-include/iokit
	${CMAKE_SOURCE_DIR}/src/external/syslog/libsystem_asl.tproj/include
	${CMAKE_SOURCE_DIR}/src/external/libdispatch/include
	${CMAKE_SOURCE_DIR}/src/lkm/osfmk
)

add_compile_options(
	-iquote ${CMAKE_CURRENT_BINARY_DIR}/pwr_mgt.subproj
)

set(MIG_ARCH "x86_64")
set(MIG_USER_SOURCE_SUFFIX "64.c")
set(MIG_USER_HEADER_SUFFIX "64.h")
mig(iokitmig.defs)

set(MIG_ARCH "i386")
set(MIG_USER_SOURCE_SUFFIX "32.c")
set(MIG_USER_HEADER_SUFFIX "32.h")
mig(iokitmig.defs)

unset(MIG_ARCH)
unset(MIG_USER_SOURCE_SUFFIX)
unset(MIG_USER_HEADER_SUFFIX)
mig(pwr_mgt.subproj/powermanagement.defs)

set(iokit_sources
	IOBundle.c
	IOCFPlugIn.c
	IOCFSerialize.c
	IOCFUnserialize.tab.c
	IOCFURLAccess.c
	IODataQueueClient.c
	IOKitLib.c
	iokitmig.c
	IOMIGMachPort.c
	IOSystemConfiguration.c
	pwr_mgt.subproj/IOPMLib.c
	pwr_mgt.subproj/IOPMLibPrivate.c
	graphics.subproj/IOAccelSurfaceControl.c
	graphics.subproj/IODisplayLib.c
	graphics.subproj/IOGraphicsLib.c
	graphics.subproj/PEFSupport.c
	platform.subproj/IOPlatformSupport.c
	${CMAKE_CURRENT_BINARY_DIR}/pwr_mgt.subproj/powermanagementUser.c
)

add_framework(IOKit CURRENT_VERSION FAT
	VERSION "A"
	SOURCES
		${iokit_sources}
	DEPENDENCIES
		system
		CoreFoundation
)

add_custom_target(IOKit_migs
	DEPENDS
		${CMAKE_CURRENT_BINARY_DIR}/iokitmig32.h
		${CMAKE_CURRENT_BINARY_DIR}/iokitmig64.h
)

add_dependencies(IOKit IOKit_migs)
