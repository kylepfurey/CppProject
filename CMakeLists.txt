# .txt
# TODO CMake Configuration
# by NAME

# Initialize CMake
cmake_minimum_required(VERSION 3.16)
project(libTODO CXX)

# Set C++ compiler version
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Set output directories
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/build/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/build/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/build/lib)

# Build libTODO
file(GLOB_RECURSE SOURCE ${CMAKE_SOURCE_DIR}/src/*.cpp)
list(REMOVE_ITEM SOURCE ${CMAKE_SOURCE_DIR}/src/main.cpp)
add_library(libTODO SHARED ${SOURCE})

# Rename libTODO
set_target_properties(libTODO PROPERTIES OUTPUT_NAME "TODO")

# Set include directory and build macros
target_include_directories(libTODO PUBLIC ${CMAKE_SOURCE_DIR}/include)
target_compile_definitions(libTODO PUBLIC $<$<CONFIG:Debug>:_DEBUG>)
target_compile_definitions(libTODO PRIVATE
        TODO_EXPORTS
        SDL_MAIN_HANDLED
)

# Find external libraries
set(SDL_X11_XTEST OFF CACHE BOOL "" FORCE)
add_subdirectory(${CMAKE_SOURCE_DIR}/extern/SDL EXCLUDE_FROM_ALL)

# Link external libraries to libTODO
target_link_libraries(libTODO PUBLIC
        SDL3::SDL3
)

# Build TODO
add_executable(TODO ${CMAKE_SOURCE_DIR}/src/main.cpp)
target_link_libraries(TODO PRIVATE libTODO)
