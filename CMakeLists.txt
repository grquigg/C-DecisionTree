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