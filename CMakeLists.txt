cmake_minimum_required(VERSION 3.10)
add_compile_options("$<$<C_COMPILER_ID:MSVC>:/utf-8>")
add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Fetch LibCPR
include(FetchContent)
FetchContent_Declare(cpr GIT_REPOSITORY https://github.com/libcpr/cpr.git
                         GIT_TAG beb9e98806bb84bcc130a2cebfbcbbc6ce62b335)
FetchContent_MakeAvailable(cpr)

project(Chiheisen LANGUAGES CXX)
set(JAVA_AWT_LIBRARY NotNeeded)
set(JAVA_JVM_LIBRARY NotNeeded)
set(JAVA_AWT_INCLUDE_PATH NotNeeded)
find_package(JNI REQUIRED)
if (JNI_FOUND)
    message (STATUS "FOUND JNI IN ${JAVA_INCLUDE_PATH}")
    set(SOURCE_PATH
            ${CMAKE_CURRENT_SOURCE_DIR}/include/3rd_include
            ${CMAKE_CURRENT_SOURCE_DIR}/include/3rd_include/utf8
            ${CMAKE_CURRENT_SOURCE_DIR}/include/3rd_include/utf8/utf8
            ${CMAKE_CURRENT_SOURCE_DIR}/include/MiraiCP
            ${JAVA_INCLUDE_PATH}/
            ${JAVA_INCLUDE_PATH2}/
            )
else()
    message(STATUS "Cannot find JNI")
endif()
add_library(
	Chiheisen
        SHARED
        include/MiraiCP/MiraiCP.cpp # MiraiCP 源文件
	src/Chiheisen.cpp
)
target_include_directories(Chiheisen PUBLIC ${SOURCE_PATH})
