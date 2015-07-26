cmake_minimum_required (VERSION 3.2.3)

###############################################################################

set(PROJECT_NAME Algie)
project (Algie)

###############################################################################

set(CMAKE_BUILD_TYPE DEBUG)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -Wunused -std=c++11")
set(CMAKE_CXX_FLAGS_DEBUG "-O0 -g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

###############################################################################

include_directories(
  ${PROJECT_SOURCE_DIR}/
)

###############################################################################

add_subdirectory(unit_tests)
add_subdirectory(stress_tests)
