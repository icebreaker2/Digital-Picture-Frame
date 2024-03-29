cmake_minimum_required(VERSION 3.6.3)
project(Digital_Picture_Frame.sh)

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

find_library(LIBVLCCORE_LIBRARY NAMES vlccore libvlccore
        HINTS "$ENV{LIBVLC_LIBRARY_PATH}" ${PC_LIBVLC_LIBDIR} ${PC_LIBVLC_LIBRARY_DIRS}
        PATHS
        "$ENV{LIB_DIR}/lib"
        #mingw
        c:/msys/local/lib
        )
find_library(LIBVLCCORE_LIBRARY NAMES vlccore libvlccore)

set(SOURCE_FILES
        ${MODULES_INCLUDE}/VLCPlayer.h
        ${MODULES_INCLUDE}/FileIterator.h
        ${MODULES_SRC}/VLCPlayer.c
        ${MODULES_SRC}/FileIterator.c
        src/main.c

        test/modules/VLCPlayerTest.c
        )

add_executable(Digital_Picture_Frame.sh ${SOURCE_FILES})

target_link_libraries(Digital_Picture_Frame.sh
        ${LIBVLC_LIBRARY}
        #${LIBVLCCORE_LIBRARY}
        )