cmake_minimum_required (VERSION 2.6)
project (portable_service_lib)
# The version number.
set (PORTABLE_SERVICE_LIB_VERSION_MAJOR 0)
set (PORTABLE_SERVICE_LIB_VERSION_MINOR 1)
set (PROJECT_SOURCE_DIR src)

configure_file (
  "${PROJECT_SOURCE_DIR}/portable_service_lib.h.in"
  "${PROJECT_BINARY_DIR}/portable_service_lib.h"
  )
include_directories("${PROJECT_BINARY_DIR}")


add_library(portable_service_core ${PROJECT_SOURCE_DIR}/portable_service_core.cpp)
set_property(TARGET portable_service_core PROPERTY CXX_STANDARD 14)
