cmake_minimum_required(VERSION 3.20)

set(PROJECT_NAME "b-luga")

project(
    ${PROJECT_NAME}
    VERSION 1.0.0
    LANGUAGES CXX
    DESCRIPTION "ECS made for R-Type epitech project"
)

add_library(${PROJECT_NAME} INTERFACE)
add_library(${PROJECT_NAME}::${PROJECT_NAME} ALIAS ${PROJECT_NAME})

include(GNUInstallDirs)

set(BLUGA_INCLUDE_BUILD_DIR "${CMAKE_CURRENT_SOURCE_DIR}/include/")
set(BLUGA_INCLUDE_INSTALL_DIR "${CMAKE_INSTALL_INCLUDEDIR}")

add_subdirectory(deps)

target_include_directories(
    ${PROJECT_NAME}
    INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

target_compile_features(${PROJECT_NAME} INTERFACE cxx_std_20)

include(CMakePackageConfigHelpers)

install(
    DIRECTORY ${BLUGA_INCLUDE_BUILD_DIR}
    DESTINATION ${BLUGA_INCLUDE_INSTALL_DIR}
)

export(
    TARGETS ${PROJECT_NAME}
    NAMESPACE ${PROJECT_NAME}::
    FILE ${PROJECT_NAME}Config.cmake
)

install(
    TARGETS ${PROJECT_NAME}
    EXPORT ${PROJECT_NAME}Targets
    INCLUDES DESTINATION ${BLUGA_INCLUDE_INSTALL_DIR}
)
install(
    EXPORT ${PROJECT_NAME}Targets
    NAMESPACE ${PROJECT_NAME}::
    INCLUDES DESTINATION ${BLUGA_INCLUDE_INSTALL_DIR}
)
