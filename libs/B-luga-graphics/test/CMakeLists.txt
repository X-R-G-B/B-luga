cmake_minimum_required(VERSION 3.20)

set(PROJECT_NAME "test-ecs")

project(
    ${PROJECT_NAME}
    VERSION 1.0.0
    LANGUAGES CXX
)

add_executable(${PROJECT_NAME})

# ------------------------------
# ------------------------------
# ------------------------------

include(ExternalProject)

include(FetchContent)

FetchContent_Declare(
    raylib
    CMAKE_ARGS "-DCMAKE_BUILD_TYPE=Release" "-DCMAKE_CONFIGURATION_TYPES=\"Release;Release\"" "-DCONFIG=Release"
    URL "https://github.com/X-R-G-B/R-Bus/releases/latest/download/raylib.tar"
    DOWNLOAD_NO_PROGRESS FALSE
    DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)

FetchContent_MakeAvailable(raylib)

target_link_libraries(
    ${PROJECT_NAME}
    PRIVATE
    raylib
)

FetchContent_Declare(
    b-luga-graphics
    URL "https://github.com/X-R-G-B/B-luga/releases/latest/download/b-luga-graphics.tar"
    DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)

FetchContent_MakeAvailable(b-luga-graphics)

target_link_libraries(${PROJECT_NAME} PRIVATE b-luga-graphics)

# ------------------------------
# ------------------------------
# ------------------------------

target_sources(
    ${PROJECT_NAME}
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
)
