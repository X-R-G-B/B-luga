# B-luga-physics

*Plugin for b-luga ECS that add some physics and life*

## Hightlight

- Damage/Death systems
- Collision systems
- Basic and advanced Movements
- Some components can be created with json

## Install

```cmake
include(FetchContent)

FetchContent_Declare(
    b-luga-physics
    URL "https://github.com/X-R-G-B/B-luga/releases/latest/download/b-luga-physics.tar"
    DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)

FetchContent_MakeAvailable(b-luga-physics)

target_link_libraries(
    ${PROJECT_NAME}
    PRIVATE
    b-luga-physics
)
```

This will dowload the latest version of b-luga-physics, and link it + add headers to the project with cmake

## Documentation

# ECS Physics Plugin Documentation

This ECS (Entity-Component-System) physics plugin is designed to integrate seamlessly with your game engine to provide comprehensive physics management. This includes collision detection, damage handling, death states, and a variety of movement physics such as basic linear movement, zigzag patterns, and bouncing.

## Features

- **Collision Management**: Efficiently manages collisions between entities in the game world.
- **Damage System**: Automates the process of applying damage to entities upon collisions or other triggers.
- **Death Handling**: Provides a system for handling the destruction or deactivation of entities after reaching a death state.
- **Movement Physics**:
    - **Basic**: Enables entities to move in straight paths.
    - **ZigZag**: Allows entities to move in a predefined or random zigzag pattern.
    - **Bounce**: Implements bounce physics upon collisions with other entities or world boundaries.
