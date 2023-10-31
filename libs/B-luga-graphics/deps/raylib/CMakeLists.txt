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

# add_library(raylibe STATIC IMPORTED)
# set_target_properties(raylibe PROPERTIES IMPORTED_LOCATION )

target_link_libraries(${PROJECT_NAME} PUBLIC $<TARGET_FILE:raylib>)

target_include_directories(
    ${PROJECT_NAME}
    INTERFACE
    $<BUILD_INTERFACE:${raylib_SOURCE_DIR}/src>
    $<INSTALL_INTERFACE:include>
)

install(
    DIRECTORY ${raylib_SOURCE_DIR}/src
    DESTINATION ${BLUGA_INCLUDE_INSTALL_DIR}
)

# install(
#     EXPORT raylib
#     DESTINATION ${BLUGA_INCLUDE_INSTALL_DIR}
# )
