cmake_minimum_required(VERSION 3.14)
project(audio_api)

# Set flag for building a universal binary on macOS 
if(APPLE)
	set(CMAKE_OSX_ARCHITECTURES "arm64;x86_64")
endif()

# Default to Release build for library
if(NOT CMAKE_BUILD_TYPE)
	set(CMAKE_BUILD_TYPE Release)
endif()

# Define target name
set (TARGET_NAME audio_api)

add_library(${TARGET_NAME} SHARED
	include/audio_api.h
	audio_api.c
	miniaudio.h
)

target_include_directories(${TARGET_NAME}
	PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
	PRIVATE $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
)

# Get platform target
if (APPLE)
	set(AudioEngineTarget osx)
elseif (WIN32)
	set(AudioEngineTarget x64)
elseif (UNIX)
	if(CMAKE_SYSTEM_PROCESSOR STREQUAL "aarch64")
		set(AudioEngineTarget libarm64)
	else()
		set(AudioEngineTarget lib64)
	endif()
else()
	message(FATAL_ERROR "Unknown Target!")
endif()

# Output libs to platform-specific library
set_target_properties(${TARGET_NAME}
	PROPERTIES
	ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/libs/${AudioEngineTarget}"
	ARCHIVE_OUTPUT_DIRECTORY_RELEASE "${CMAKE_CURRENT_SOURCE_DIR}/libs/${AudioEngineTarget}"
	LIBRARY_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/libs/${AudioEngineTarget}"
	LIBRARY_OUTPUT_DIRECTORY_RELEASE "${CMAKE_CURRENT_SOURCE_DIR}/libs/${AudioEngineTarget}"
	RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/libs/${AudioEngineTarget}"
	RUNTIME_OUTPUT_DIRECTORY_RELEASE "${CMAKE_CURRENT_SOURCE_DIR}/libs/${AudioEngineTarget}"
)

if (MSVC)
    # Set warning level 3
    target_compile_options(${TARGET_NAME} PRIVATE /W3)

    # Warnings as Errors Enabled
    target_compile_options(${TARGET_NAME} PRIVATE /WX)
endif()

if(WIN32)
    target_compile_definitions(${TARGET_NAME} PRIVATE _UNICODE UNICODE _CRT_SECURE_NO_WARNINGS)
    target_compile_definitions(${TARGET_NAME} PRIVATE NOMINMAX)
endif ()
