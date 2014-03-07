cmake_minimum_required(VERSION 2.8)
project(graph_tool)

set(CMAKE_BUILD_TYPE RELEASE)

find_package(wxWidgets COMPONENTS core base gl)
find_package(GLEW REQUIRED)

include(${wxWidgets_USE_FILE})
include_directories(${wxWidgets_INCLUDE_DIRS})
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/common)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/algorithm)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/util)

aux_source_directory(common GT_COMMON_SRC)
aux_source_directory(algorithm GT_ALGORITHM_SRC)
aux_source_directory(util GT_UTIL_SRC)
aux_source_directory(core CORE_SRC)

add_definitions(-DUNICODE -std=c++11)

add_library(gt_common ${GT_COMMON_SRC})
add_library(gt_algorithm ${GT_ALGORITHM_SRC})
add_library(gt_util ${GT_UTIL_SRC})

add_executable(${CMAKE_PROJECT_NAME} WIN32 ${CORE_SRC})
target_link_libraries(${CMAKE_PROJECT_NAME} gt_common gt_algorithm gt_util
    ${GVC} ${GRAPH} ${GVPLUGIN_CORE} ${GVPLUGIN_GD} ${GVPLUGIN_DOT_LAYOUT} ${GVPLUGIN_NEATO_LAYOUT}
    ${wxWidgets_LIBRARIES} ${GLEW_LIBRARIES} glu32 opengl32)
add_dependencies(${CMAKE_PROJECT_NAME} gt_common gt_algorithm)

