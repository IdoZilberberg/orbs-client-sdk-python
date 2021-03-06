cmake_minimum_required(VERSION 3.6)

find_package(PythonInterp REQUIRED)
find_package(PythonLibs REQUIRED)
if(${PYTHON_VERSION_MAJOR} EQUAL 3)
    find_package(Boost COMPONENTS python3 REQUIRED)
else()
    if(APPLE)
        find_package(Boost COMPONENTS python27 REQUIRED)
    else()
        find_package(Boost COMPONENTS python REQUIRED)
    endif()
endif()

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif(NOT CMAKE_BUILD_TYPE)
message("CMAKE_BUILD_TYPE is ${CMAKE_BUILD_TYPE}")

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
set(CMAKE_DEBUG_POSTFIX "d" CACHE STRING "Set debug library postfix" FORCE)

set(BUILD_DIR ${PLATFORM})

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${BUILD_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${BUILD_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${BUILD_DIR}/bin)

add_subdirectory(lib)
