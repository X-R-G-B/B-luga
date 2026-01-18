cmake_minimum_required(VERSION 3.20)

include(GetSteamSdk.cmake)

target_include_directories(
    ${PROJECT_NAME}
    PRIVATE
    ${STEAMAPI_SOURCE_DIR}/src
)
