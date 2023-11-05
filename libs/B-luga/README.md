# B-luga

*An ECS made for a 3rd year project at EPITECH*

## Hightlight

- Sparse Array
- Templated Components
- Integrated Json Parser
- Integrated Logger
- Easy Plugin Integration

## Install

```cmake
include(FetchContent)

FetchContent_Declare(
    b-luga
    URL "https://github.com/X-R-G-B/B-luga/releases/latest/download/b-luga.tar"
    DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)

FetchContent_MakeAvailable(b-luga)

target_link_libraries(
    ${PROJECT_NAME}
    PRIVATE
    b-luga
)
```

This will dowload the latest version of b-luga, and link it + add headers to the project with cmake

## Documentation

[documentation](./Documentation)

