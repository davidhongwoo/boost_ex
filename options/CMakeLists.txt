cmake_minimum_required(VERSION 2.8)

project(options)

set(BOOST_ROOT "/usr/local/boost_1_58_0")
set(BOOST_INCLUDEDIR "/usr/local/boost_1_58_0")
set(BOOST_LIBRARYDIR "/usr/local/boost_1_58_0/lib")
set(BIN_DIR ${CMAKE_SOURCE_DIR}/bin)

set(Boost_NO_SYSTEM_PATHS "ON")
find_package(Boost
			 1.58.0
			 COMPONENTS 
						program_options
			 REQUIRED)

include_directories(${BOOST_INCLUDE_DIRS})

IF(NOT EXISTS ${BIN_DIR})
	FILE(MAKE_DIRECTORY ${BIN_DIR})
ENDIF(NOT EXISTS ${BIN_DIR})

set(CMAKE_C_COMPILER clang)
set(CMAKE_CXX_COMPILER clang++)

set(CMAKE_CXX_FLAGS "-std=c++11 ${CMAKE_CXX_FLAGS} -g")
#set(CMAKE_CXX_FLAGS "-std=c++1y ${CMAKE_CXX_FLAGS} -g")
SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${BIN_DIR})

INCLUDE_DIRECTORIES(${BOOST_INCLUDE_DIRS}) 
ADD_EXECUTABLE(options src/main) 
TARGET_LINK_LIBRARIES(options ${Boost_LIBRARIES})
