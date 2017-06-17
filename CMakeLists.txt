cmake_minimum_required(VERSION 3.7)
project(Digital_Picture_Frame)

set(CMAKE_C_STANDARD 99)

set(MODULES_INCLUDE include/modules)
set(MODULES_SRC src/modules)

include_directories(${MODULES_INCLUDE})

find_library(LIBVLC_LIBRARY NAMES vlc libvlc
		HINTS "$ENV{LIBVLC_LIBRARY_PATH}" ${PC_LIBVLC_LIBDIR} ${PC_LIBVLC_LIBRARY_DIRS}
		PATHS
		"$ENV{LIB_DIR}/lib"
		#mingw
		c:/msys/local/lib
		)
find_library(LIBVLC_LIBRARY NAMES vlc libvlc)
MESSAGE("${LIBVLC_LIBRARY}")

find_library(LIBVLCCORE_LIBRARY NAMES vlccore libvlccore
		HINTS "$ENV{LIBVLC_LIBRARY_PATH}" ${PC_LIBVLC_LIBDIR} ${PC_LIBVLC_LIBRARY_DIRS}
		PATHS
		"$ENV{LIB_DIR}/lib"
		#mingw
		c:/msys/local/lib
		)
find_library(LIBVLCCORE_LIBRARY NAMES vlccore libvlccore)

set(SOURCE_FILES
		${MODULES_INCLUDE}/MovPlayer.h

		${MODULES_SRC}/MovPlayer.c

		src/main.c

		test/modules/MovPlayerTest.c
		test/TestStarter.c)
add_executable(Digital_Picture_Frame ${SOURCE_FILES})

target_link_libraries(Digital_Picture_Frame ${LIBVLC_LIBRARY})