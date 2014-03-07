cmake_minimum_required(VERSION 2.8)
project(graph_tool)

set(CMAKE_BUILD_TYPE RELEASE)
SET(EXT_ROOT "D:/ext/vs2012")
SET(wxWidgets_ROOT_DIR "D:/ext/wxWidgets")
SET(wxWidgets_CONFIGURATION mswu)
SET(GRAPHVIZ_ROOT "D:/ext/other/Graphviz/2.28")

SET(CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH} ${EXT_ROOT})

find_package(wxWidgets COMPONENTS core base gl)

FIND_LIBRARY(GVC gvc)
FIND_LIBRARY(GRAPH graph)
FIND_LIBRARY(GVPLUGIN_CORE gvplugin_core)
FIND_LIBRARY(GVPLUGIN_GD gvplugin_gd)
FIND_LIBRARY(GVPLUGIN_DOT_LAYOUT gvplugin_dot_layout)
FIND_LIBRARY(GVPLUGIN_NEATO_LAYOUT gvplugin_neato_layout)

include(${wxWidgets_USE_FILE})
include_directories(${wxWidgets_INCLUDE_DIRS})
INCLUDE_DIRECTORIES(${EXT_ROOT}/include)
INCLUDE_DIRECTORIES(${GRAPHVIZ_ROOT}/include)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/common)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/algorithm)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/util)

LINK_DIRECTORIES(${EXT_ROOT}/lib)

aux_source_directory(common GT_COMMON_SRC)
aux_source_directory(algorithm GT_ALGORITHM_SRC)
aux_source_directory(util GT_UTIL_SRC)
aux_source_directory(core CORE_SRC)

add_definitions(-DUNICODE)

add_library(gt_common ${GT_COMMON_SRC})
add_library(gt_algorithm ${GT_ALGORITHM_SRC})
add_library(gt_util ${GT_UTIL_SRC})

add_executable(${CMAKE_PROJECT_NAME} WIN32 ${CORE_SRC})
target_link_libraries(${CMAKE_PROJECT_NAME} gt_common gt_algorithm gt_util
    ${GVC} ${GRAPH} ${GVPLUGIN_CORE} ${GVPLUGIN_GD} ${GVPLUGIN_DOT_LAYOUT} ${GVPLUGIN_NEATO_LAYOUT}
    ${wxWidgets_LIBRARIES} glu32 opengl32)
add_dependencies(${CMAKE_PROJECT_NAME} gt_common gt_algorithm)

