/*
** EPITECH PROJECT, 2023
** R-Bus
** File description:
** Geometry
*/

#pragma once

#include <cstddef>
#include <cstdint>

namespace Raylib {

    struct Vector2 {
            Vector2(float x, float y) : x(x), y(y) {};
            float x;
            float y;
    };

    struct Vector3 {
            Vector3(float x, float y, float z) : x(x), y(y), z(z) {};
            float x;
            float y;
            float z;
    };

    struct Vector4 {
            Vector4(float x, float y, float z, float w) : x(x), y(y), z(z), w(w) {};
            float x;
            float y;
            float z;
            float w;
    };

    struct Rectangle {
            Rectangle(float x, float y, float width, float height) : x(x), y(y), width(width), height(height) {};
            float x;
            float y;
            float width;
            float height;
    };

    // COLOR CONSTANTS
    enum class ColorDef : std::size_t {
        DarkGray   ,
        Yellow     ,
        Gold       ,
        Orange     ,
        Pink       ,
        Red        ,
        Maroon     ,
        Green      ,
        Lime       ,
        DarkGreen  ,
        SkyBlue    ,
        Blue       ,
        DarkBlue   ,
        Purple     ,
        Violet     ,
        DarkPurple ,
        Beige      ,
        Brown      ,
        DarkBrown  ,
        White      ,
        Black      ,
        Blank      ,
        Magenta    ,
        RayWhite   ,
    };

    struct Color {
            Color(uint8_t r, uint8_t g, uint8_t b, uint8_t a) : r(r), g(g), b(b), a(a) {};
            Color(ColorDef color);
            uint8_t r;
            uint8_t g;
            uint8_t b;
            uint8_t a;
    };
} // namespace Raylib
