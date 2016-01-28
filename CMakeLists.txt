cmake_minimum_required (VERSION 2.6)
project (portable_service_lib)
# The version number.
set (PORTABLE_SERVICE_LIB_VERSION_MAJOR 0)
set (PORTABLE_SERVICE_LIB_VERSION_MINOR 1)
set (PROJECT_SOURCE_DIR ${CMAKE_SOURCE_DIR}/src)
set (BUILD_SHARED_LIBS)

find_package(Boost 1.60 REQUIRED)
include_directories(${Boost_INCLUDE_DIR})

if (WIN32)
set (USE_WINDOWS_SCM TRUE CACHE BOOL "Use the windows service manager")
endif()

configure_file (
  "${PROJECT_SOURCE_DIR}/portable_service_lib.h.in"
  "${PROJECT_BINARY_DIR}/portable_service_lib.h"
  )

include_directories("${PROJECT_BINARY_DIR}")

set (CORE_SOURCE_FILES
${PROJECT_SOURCE_DIR}/portable_service_core.hpp
${PROJECT_SOURCE_DIR}/portable_service_core.cpp
${PROJECT_SOURCE_DIR}/api_adapter.hpp
)

set (WINDOWS_SCM_FILES
${PROJECT_SOURCE_DIR}/win_scm/win_scm.hpp
)

if (USE_WINDOWS_SCM)
set (PORTABLE_SERVICE_LIBRARY_FILES
${CORE_SOURCE_FILES}
${WINDOWS_SCM_FILES}
)
else()
set (PORTABLE_SERVICE_LIBRARY_FILES
${CORE_SOURCE_FILES}
)
endif()

message(STATUS "Using following source files for portable_service_lib: " 
    ${PORTABLE_SERVICE_LIBRARY_FILES})

add_library(portable_service_lib ${PORTABLE_SERVICE_LIBRARY_FILES})

set_property(TARGET portable_service_lib PROPERTY LINKER_LANGUAGE CXX)
set_property(TARGET portable_service_lib PROPERTY CXX_STANDARD 11)


enable_testing()
add_subdirectory(test)