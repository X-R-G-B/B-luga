cmake_minimum_required(VERSION 3.20)

include(FetchContent)

FetchContent_Declare(
    raylib
    CMAKE_ARGS "-DCMAKE_BUILD_TYPE=Release" "-DCMAKE_CONFIGURATION_TYPES=\"Release;Release\"" "-DCONFIG=Release"
    URL "https://github.com/X-R-G-B/B-luga/releases/latest/download/raylib.tar"
    DOWNLOAD_NO_PROGRESS FALSE
    DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)

FetchContent_MakeAvailable(raylib)

target_link_libraries(
    ${PROJECT_NAME}
    INTERFACE
    raylib
)

add_library(raylib_static_diff STATIC IMPORTED)
set_property(TARGET raylib_static_diff PROPERTY IMPORTED_LOCATION $<TARGET_FILE:raylib>)
set_property(TARGET ${PROJECT_NAME} PROPERTY INTERFACE_LINK_LIBRARIES raylib_static_diff)

target_include_directories(
    ${PROJECT_NAME}
    PUBLIC
    $<BUILD_INTERFACE:${raylib_SOURCE_DIR}/src>
    $<INSTALL_INTERFACE:${BLUGA_INCLUDE_INSTALL_DIR}/raylib>
)

# install(
#     EXPORT raylib
#     DESTINATION ${BLUGA_INCLUDE_INSTALL_DIR}
# )
