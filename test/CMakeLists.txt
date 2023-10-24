# ------------------------------
# ------------------------------
# ------------------------------

include(ExternalProject)

include(FetchContent)

FetchContent_Declare(
    b-luga
    URL "https://github.com/X-R-G-B/B-luga/releases/latest/download/raylib.tar"
    DOWLOAD_EXTRACT_TIMESTAMP TRUE
)

FetchContent_MakeAvailable(b-luga)

# ------------------------------
# ------------------------------
# ------------------------------

set(PROJECT_NAME "test-ecs")

project(
    ${PROJECT_NAME}
    VERSION 1.0.0
    LANGUAGES CXX
)

add_executable(${PROJECT_NAME})

add_subdirectory(src)
