# .txt
# TODO CMake Configuration
# by Kyle Furey

# Initialize CMake with vcpkg (if Windows)
#set(CMAKE_TOOLCHAIN_FILE "$ENV{USERPROFILE}/vcpkg/scripts/buildsystems/vcpkg.cmake" CACHE FILEPATH "vcpkg Toolchain File")
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
add_library(libTODO SHARED
        ${CMAKE_SOURCE_DIR}/include/TODO.hpp
        ${CMAKE_SOURCE_DIR}/include/External.hpp
        ${CMAKE_SOURCE_DIR}/include/Export.hpp
        ${CMAKE_SOURCE_DIR}/include/Types.hpp
        ${CMAKE_SOURCE_DIR}/include/Error.hpp
        ${CMAKE_SOURCE_DIR}/include/Test.hpp
        ${CMAKE_SOURCE_DIR}/src/Test.cpp
)

# Rename libTODO
set_target_properties(libTODO PROPERTIES OUTPUT_NAME "TODO")

# Set include directory and build macro
target_include_directories(libTODO PUBLIC ${CMAKE_SOURCE_DIR}/include)
target_compile_definitions(libTODO PUBLIC
        $<$<CONFIG:Debug>:_DEBUG>
)
target_compile_definitions(libTODO PRIVATE
        TODO_EXPORTS
        SDL_MAIN_HANDLED
)

# Find external libraries
find_package(SDL2 REQUIRED)

# Include external libraries
target_include_directories(libTODO PUBLIC
        ${SDL2_INCLUDE_DIRS}
)

# Link external libraries to libTODO
target_link_libraries(libTODO PUBLIC
        SDL2::SDL2
        SDL2::SDL2main
)

# Build TODO
add_executable(TODO ${CMAKE_SOURCE_DIR}/main.cpp)
target_link_libraries(TODO PRIVATE libTODO)
target_include_directories(TODO PRIVATE ${CMAKE_SOURCE_DIR}/include)
