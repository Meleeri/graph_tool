cmake_minimum_required(VERSION 2.8)
project(graph_tool)

set(CMAKE_BUILD_TYPE RELEASE)

set(wxWidgets_ROOT_DIR "D:/ext/wxWidgets")
set(wxWidgets_CONFIGURATION mswu)
set(GRAPHVIZ_ROOT "D:/ext/other/Graphviz/2.28")

set(CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH} ${GRAPHVIZ_ROOT})
set(CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH} "D:/ext/vs2012")
set(CMAKE_LIBRARY_PATH ${CMAKE_LIBRARY_PATH} ${GRAPHVIZ_ROOT}/lib/release/lib)

find_package(wxWidgets COMPONENTS core base gl)

find_library(GVC gvc REQUIRED)
find_library(GRAPH graph REQUIRED)
find_library(GVPLUGIN_CORE gvplugin_core)
find_library(GVPLUGIN_GD gvplugin_gd)
find_library(GVPLUGIN_DOT_LAYOUT gvplugin_dot_layout)
find_library(GVPLUGIN_NEATO_LAYOUT gvplugin_neato_layout)
FIND_PACKAGE(GLEW REQUIRED)

INCLUDE_DIRECTORIES(D:/ext/vs2012/include)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/common)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/algorithm)

include_directories(${GRAPHVIZ_ROOT}/include)
include_directories(${GRAPHVIZ_ROOT}/include/graphviz)
include_directories(${wxWidgets_INCLUDE_DIRS})

aux_source_directory(common GT_COMMON_SRC)
aux_source_directory(algorithm GT_ALGORITHM_SRC)
aux_source_directory(core CORE_SRC)

add_library(gt_common ${GT_COMMON_SRC})
add_library(gt_algorithm ${GT_ALGORITHM_SRC})

add_executable(${CMAKE_PROJECT_NAME} WIN32 ${CORE_SRC})
target_link_libraries(${CMAKE_PROJECT_NAME} gt_common gt_algorithm
    ${GVC} ${GRAPH} ${GVPLUGIN_CORE} ${GVPLUGIN_GD} ${GVPLUGIN_DOT_LAYOUT} ${GVPLUGIN_NEATO_LAYOUT}
    ${wxWidgets_LIBRARIES} ${GLEW_LIBRARIES} opengl32 glu32)

add_dependencies(${CMAKE_PROJECT_NAME} gt_common gt_algorithm)