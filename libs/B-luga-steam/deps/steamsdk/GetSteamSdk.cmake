# https://stackoverflow.com/questions/73833679/link-external-library-steamapi-by-path-with-cmake

set(STEAMAPI_ZIP_LOCATION "${CMAKE_CURRENT_SOURCE_DIR}/steamworks_sdk_163.zip")
set(STEAMAPI_LOCATION "${CMAKE_BINARY_DIR}/cmake/steamworks_sdk")
set(STEAMAPI_BINARY_DIR "${STEAMAPI_LOCATION}/sdk/redistributable_bin/win64/steam_api64.lib")
set(STEAMAPI_SOURCE_DIR "${STEAMAPI_LOCATION}/sdk/public/steam")
set(STEAMAPI_SHARED_DIR "${STEAMAPI_LOCATION}/sdk/redistributable_bin/win64/steam_api64.dll")

if(NOT(EXISTS ${STEAMAPI_LOCATION}))
    message(STATUS "Unzipping Steam SDK to ${STEAMAPI_ZIP_LOCATION}")
    file(ARCHIVE_EXTRACT INPUT "${STEAMAPI_ZIP_LOCATION}" DESTINATION "${STEAMAPI_LOCATION}")
endif()
