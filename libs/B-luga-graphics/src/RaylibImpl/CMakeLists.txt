cmake_minimum_required(VERSION 3.20)

target_sources(
    ${PROJECT_NAME}
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/Audio/Audio.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Graphics/Graphics.cpp
)
