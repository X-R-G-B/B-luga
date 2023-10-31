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

# target_link_libraries(
#     ${PROJECT_NAME}
#     PRIVATE
#     $<TARGET_FILE:raylib>
# )

# add_library(raylib_static STATIC IMPORTED)
# set_property(TARGET raylib_static PROPERTY IMPORTED_LOCATION $<TARGET_FILE:raylib>)
set_property(TARGET ${PROJECT_NAME} PROPERTY INTERFACE_LINK_LIBRARIES raylib_static)

# install(
#     EXPORT raylib
#     DESTINATION ${BLUGA_INCLUDE_INSTALL_DIR}
# )
