cmake_minimum_required (VERSION 3.2.3)

###############################################################################

function(find_required_path NAME)
  find_path(${NAME}_INCLUDE_DIR ${ARGN})
  if(${NAME}_INCLUDE_DIR)
      message(STATUS "Path (${ARGV1}) found in ${${NAME}_INCLUDE_DIR}")
  else()
      message(FATAL_ERROR "Path (${ARGV1}) not found")
  endif()
endfunction(find_required_path)

###############################################################################

function(find_required_library NAME)
  find_library(${NAME}_LIB ${ARGN})
  if(${NAME}_LIB)
      message(STATUS "Library (${ARGV1}) found in ${${NAME}_LIB}")
  else()
      message(FATAL_ERROR "Library (${ARGV1}) not found")
  endif()
endfunction(find_required_library)

###############################################################################

function(create_executable BINARY_NAME SOURCE_FILE)
    add_executable(${BINARY_NAME} ${SOURCE_FILE})
    target_link_libraries(${BINARY_NAME}
        gtest
        gmock
    )
endfunction(create_executable)

###############################################################################

enable_testing()

###############################################################################

find_required_path("GTEST" gtest.h /usr/include/gtest /usr/local/include/gtest)
include_directories(
  ${GTEST_INCLUDE_DIR}/
)

###############################################################################

find_required_library(GTEST gtest PATH)
find_required_library(GMOCK gmock PATH)


###############################################################################

create_executable(unit_stable_matching
    ./unit_stable_matching.cpp
)
