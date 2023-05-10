# CMakeList.txt : CMake project for Ex05_Zoo, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.15)
set (CMAKE_CXX_STANDARD 20)
set (CMAKE_CXX_STANDARD_REQUIRED ON)
set (CMAKE_CXX_EXTENSIONS OFF)
if (MSVC)
add_compile_options (/W4 /permissive- /Zc:externConstexpr /Zc:inline)
endif ()

project ("Ex05_Zoo")

# Add source to this project's executable.
add_executable (Ex05_Zoo)


add_subdirectory (include)
add_subdirectory (src)
include_directories(include)