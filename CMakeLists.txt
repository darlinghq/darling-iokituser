project(IOKitUser)

add_definitions(-DIOKIT -D_DARWIN_NO_64_BIT_INODE=1)

include_directories(
	${CMAKE_CURRENT_SOURCE_DIR}
	${CMAKE_CURRENT_SOURCE_DIR}/include
	${CMAKE_CURRENT_BINARY_DIR}
	${CMAKE_SOURCE_DIR}/kernel-include/iokit
	${CMAKE_SOURCE_DIR}/src/external/syslog/libsystem_asl.tproj/include
	${CMAKE_SOURCE_DIR}/src/external/libdispatch/include
	${CMAKE_SOURCE_DIR}/src/lkm/osfmk
	${CMAKE_SOURCE_DIR}/src
)

set(MIG_ARCH "x86_64")
set(MIG_USER_SOURCE_SUFFIX "64.c")
set(MIG_USER_HEADER_SUFFIX "64.h")
mig(iokitmig.defs)

set(MIG_ARCH "i386")
set(MIG_USER_SOURCE_SUFFIX "32.c")
set(MIG_USER_HEADER_SUFFIX "32.h")
mig(iokitmig.defs)

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
	#IOSystemConfiguration.c # doesn't build yet
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
