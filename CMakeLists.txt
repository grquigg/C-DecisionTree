cmake_minimum_required(VERSION 3.10)

project(DECISION_TREE VERSION 1.0)

# Set include directories
message("--Source directory: ${DECISION_TREE_SOURCE_DIR}")
include_directories(${DECISION_TREE_SOURCE_DIR}/include)

# Get CPP files
file(GLOB SRC ${DECISION_TREE_SOURCE_DIR}/src/*cpp)
message("--src: ${SRC}")

# Get executable files
file(GLOB EXECLIST ${DECISION_TREE_SOURCE_DIR}/bin/*cpp)
message("--Exec List: ${EXECLIST}")

###############
# C++ Options #
###############
# Enable C++11
set(CMAKE_CXX_STANDARD 11)

# determine build type based on directory name. Do not allow for in source building
#
if(${DECISION_TREE_SOURCE_DIR} STREQUAL ${DECISION_TREE_BINARY_DIR})
  message(FATAL_ERROR " *** In-source building not allowed. Please create a subdir 'Release' or 'Debug', and run cmake from within this directory 'cmake ..' ***")
else()
  get_filename_component(TYPE ${DECISION_TREE_BINARY_DIR} NAME)
  string(TOUPPER "${TYPE}" TYPE)
  if(${TYPE} STREQUAL "RELEASE")
    set(CMAKE_BUILD_TYPE Release)
  else()
    set(CMAKE_BUILD_TYPE Debug)
 endif()
 message("-- Build type set to: ${TYPE}")
endif()


# src libraries
if(NOT SRC STREQUAL "")
  set(LIBNAME "Decision_Tree")
  add_library(${LIBNAME} ${SRC})
endif()

# executables
foreach(EXEC ${EXECLIST})
  get_filename_component(EXECNAME ${EXEC} NAME_WE)
  add_executable(${EXECNAME} ${EXEC})

  if(NOT SRC STREQUAL "")
    message("SRC ${SRC}")
    message("${EXECNAME}")
    message("${LIBNAME}")
    target_link_libraries(${EXECNAME} LINK_PUBLIC ${LIBNAME})
  endif()

  message("-- Adding executable: ${EXECNAME}")
endforeach(EXEC)