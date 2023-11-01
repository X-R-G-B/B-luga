/*
** EPITECH PROJECT, 2023
** R-Bus
** File description:
** Geometry
*/

#pragma once

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

    struct Color {
            Color(uint8_t r, uint8_t g, uint8_t b, uint8_t a) : r(r), g(g), b(b), a(a) {};
            uint8_t r;
            uint8_t g;
            uint8_t b;
            uint8_t a;
    };

    // COLOR CONSTANTS
    extern const Color DarkGray   ;
    extern const Color Yellow     ;
    extern const Color Gold       ;
    extern const Color Orange     ;
    extern const Color Pink       ;
    extern const Color Red        ;
    extern const Color Maroon     ;
    extern const Color Green      ;
    extern const Color Lime       ;
    extern const Color DarkGreen  ;
    extern const Color SkyBlue    ;
    extern const Color Blue       ;
    extern const Color DarkBlue   ;
    extern const Color Purple     ;
    extern const Color Violet     ;
    extern const Color DarkPurple ;
    extern const Color Beige      ;
    extern const Color Brown      ;
    extern const Color DarkBrown  ;
    extern const Color White      ;
    extern const Color Black      ;
    extern const Color Blank      ;
    extern const Color Magenta    ;
    extern const Color RayWhite   ;
} // namespace Raylib
