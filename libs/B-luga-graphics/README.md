# B-luga-graphics

## Requirements

### Raylib

You need to link the final executable with the raylib library.
And provide the include directory in the cmake file.

You can do it like this:
```cmake
cmake_minimum_required(VERSION 3.20)

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
```
