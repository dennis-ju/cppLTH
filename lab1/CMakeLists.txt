cmake_minimum_required (VERSION 3.5)
project (Simple)
set (CMAKE_CXX_STANDARD 11)

# set build type to DEBUG
set(CMAKE_BUILD_TYPE Debug)
# or to get an optimized build w/ debug symbols
# set(CMAKE_BUILD_TYPE RelWithDebInfo)

# add the library to the include file search path
include_directories ("${PROJECT_SOURCE_DIR}/liblab")

add_subdirectory (liblab) 

# set compiler and linker flags
add_compile_options("-Og")
#add_compile_options("-fsanitize=address")
#link_libraries("-fsanitize=address")

# add the executable
add_executable(hello hello.cc)
target_link_libraries (hello liblab)
add_executable(ltest ltest.cc)
target_link_libraries (ltest liblab)
add_executable(print_argv print_argv.cc)
target_link_libraries (print_argv liblab)
add_executable(separate_main separate_main.cc)
target_link_libraries (separate_main liblab)
add_executable(test_coding test_coding.cc)
target_link_libraries (test_coding liblab)

##################### Optional features below this line ############

# The version number. This is not needed but included
# to show how information can be passed from CMakeLists.txt
# to the program.
set (Simple_VERSION_MAJOR 1)
set (Simple_VERSION_MINOR 0)

# configure a header file to pass some of the CMake settings
# to the source code. Only needed if we want to pass some
# information or configuration from Cmake to the program 
# being built.

# add the binary tree to the search path for include files
# so that we will find SimpleConfig.h
include_directories("${PROJECT_BINARY_DIR}")

