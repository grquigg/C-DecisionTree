cmake_minimum_required(VERSION 3.10)

project(DECISION_TREE VERSION 1.0)

# Set include directories
include_directories(${DECISION_TREE_SOURCE_DIR}/include)

# Get CPP files
file(GLOB SRC ${DECISION_TREE_SOURCE_DIR}/src/*cpp)

# Get executable files
file(GLOB EXECLIST ${DECISION_TREE_SOURCE_DIR}/bin/*cpp)

# executables
foreach(EXEC ${EXECLIST})
  get_filename_component(EXECNAME ${EXEC} NAME_WE)
  add_executable(${EXECNAME} ${EXEC})

  if(NOT SRC STREQUAL "")
    target_link_libraries(${EXECNAME} LINK_PUBLIC ${LIBNAME})
  endif()

  message("-- Adding executable: ${EXECNAME}")
endforeach(EXEC)