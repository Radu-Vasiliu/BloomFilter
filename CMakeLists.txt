cmake_minimum_required(VERSION 3.21)

# Set the name of the project
project(BloomFilter LANGUAGES C CXX)

# Use C99 and C++14
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Turn on the ability to create folders to organize projects (.vcproj)
# It creates "CMakePredefinedTargets" folder by default and adds CMake
# defined projects like INSTALL.vcproj and ZERO_CHECK.vcproj
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# Gather the non-built source and header files
file(GLOB BloomFilter_Sources
    src/*.cpp
    src/*.h
    inc/*.h
    test/*.h
    test/*.cpp
)

file(GLOB BloomFilter_Include
    inc/*.h
)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_executable(BloomFilterTest ${BloomFilter_Sources} ${BloomFilter_Include})

target_include_directories(BloomFilterTest PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/inc)
target_include_directories(BloomFilterTest PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src)

#set(CMAKE_SUPPRESS_REGENERATION true)
#set(EXCLUDE_FROM_ALL true) 

