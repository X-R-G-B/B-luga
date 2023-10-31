cmake_minimum_required(VERSION 3.20)

include(FetchContent)

FetchContent_Declare(
    b-luga-graphics
    URL "https://github.com/X-R-G-B/B-luga/releases/latest/download/b-luga-graphics.tar"
    DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)

FetchContent_MakeAvailable(b-luga)

target_link_libraries(
    ${PROJECT_NAME}
    INTERFACE
    b-luga-graphics
)
