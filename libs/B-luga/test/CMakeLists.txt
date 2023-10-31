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
    b-luga
    URL "https://github.com/X-R-G-B/B-luga/releases/latest/download/b-luga.tar"
    DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)

FetchContent_MakeAvailable(b-luga)

target_link_libraries(${PROJECT_NAME} PRIVATE b-luga)

# ------------------------------
# ------------------------------
# ------------------------------

target_sources(
    ${PROJECT_NAME}
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
)
