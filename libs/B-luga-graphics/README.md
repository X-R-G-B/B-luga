# B-luga-graphics

*Plugin for b-luga ECS that add integration with Raylib graphic library*

## Hightlight

- Sprite, Text, Music, Sound
- Easy to use
- Some components can be created with json

## Install

```cmake
include(FetchContent)

FetchContent_Declare(
    b-luga-graphics
    URL "https://github.com/X-R-G-B/B-luga/releases/latest/download/b-luga-graphics.tar"
    DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)

FetchContent_Declare(
    raylib
    CMAKE_ARGS "-DCMAKE_BUILD_TYPE=Release" "-DCMAKE_CONFIGURATION_TYPES=\"Release;Release\"" "-DCONFIG=Release"
    URL "https://github.com/X-R-G-B/B-luga/releases/latest/download/raylib.tar"
    DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)

FetchContent_MakeAvailable(b-luga-graphics raylib)

target_link_libraries(
    ${PROJECT_NAME}
    PRIVATE
    b-luga-graphics
)

target_link_libraries(
    ${PROJECT_NAME}
    PRIVATE
    raylib
)
```

This will dowload the latest version of b-luga-graphics, and link it + add headers to the project with cmake

## Documentation

# Game Resource Creation and Management Plugin Documentation

This plugin is an integrated tool for the creation and management of sprites, music, sounds, and text in video game projects. It also includes systems for displaying and playing these resources, as well as an encapsulation of the `raylib` C library, which is a simple and easy-to-use library for learning video game development and multimedia programming.

## Features

- **Sprite Creation**: Simplifies the importing and manipulation of sprites for games.
- **Music Management**: Allows loading and controlling music tracks.
- **Sound Effects**: Manages the import and playback of various sound effects.
- **Text Management**: Provides tools for integrating and manipulating on-screen text.
- **Display and Playback**: Includes dedicated systems for sprite display and sound and music playback.
- **`raylib` Encapsulation**: Integrates `raylib` library to streamline development.

## Dependencies

This plugin requires the installation of the `raylib` library to function. You can obtain it here: [raylib GitHub](https://github.com/raysan5/raylib).
