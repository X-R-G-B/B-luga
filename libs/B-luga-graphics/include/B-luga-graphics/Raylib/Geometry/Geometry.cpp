extern "C" {
#include "raylib.h"
}
#include "Geometry.hpp"

namespace Raylib {
    Color::Color(const Color &color) : r(color.r), g(color.g), b(color.b), a(color.a) {}

    Color::Color(ColorDef colorDef)
    {
        Color color(0, 0, 0, 0);

        switch (colorDef) {
            case ColorDef::DarkGray   : *this = Raylib::Color(80, 80, 80, 255);
            case ColorDef::Yellow     : *this = Raylib::Color(253, 249, 0, 255);
            case ColorDef::Gold       : *this = Raylib::Color(255, 203, 0, 255);
            case ColorDef::Orange     : *this = Raylib::Color(255, 161, 0, 255);
            case ColorDef::Pink       : *this = Raylib::Color(255, 109, 194, 255);
            case ColorDef::Red        : *this = Raylib::Color(230, 41, 55, 255);
            case ColorDef::Maroon     : *this = Raylib::Color(190, 33, 55, 255);
            case ColorDef::Green      : *this = Raylib::Color(0, 228, 48, 255);
            case ColorDef::Lime       : *this = Raylib::Color(0, 158, 47, 255);
            case ColorDef::DarkGreen  : *this = Raylib::Color(0, 117, 44, 255);
            case ColorDef::SkyBlue    : *this = Raylib::Color(102, 191, 255, 255);
            case ColorDef::Blue       : *this = Raylib::Color(0, 121, 241, 255);
            case ColorDef::DarkBlue   : *this = Raylib::Color(0, 82, 172, 255);
            case ColorDef::Purple     : *this = Raylib::Color(200, 122, 255, 255);
            case ColorDef::Violet     : *this = Raylib::Color(135, 60, 190, 255);
            case ColorDef::DarkPurple : *this = Raylib::Color(112, 31, 126, 255);
            case ColorDef::Beige      : *this = Raylib::Color(211, 176, 131, 255);
            case ColorDef::Brown      : *this = Raylib::Color(127, 106, 79, 255);
            case ColorDef::DarkBrown  : *this = Raylib::Color(76, 63, 47, 255);
            case ColorDef::White      : *this = Raylib::Color(255, 255, 255, 255);
            case ColorDef::Black      : *this = Raylib::Color(0, 0, 0, 255);
            case ColorDef::Blank      : *this = Raylib::Color(0, 0, 0, 0);
            case ColorDef::Magenta    : *this = Raylib::Color(255, 0, 255, 255);
            case ColorDef::RayWhite   : *this = Raylib::Color(245, 245, 245, 255);
            default                : *this = Raylib::Color(0, 0, 0, 0);
        }
    }

    Color &Color::operator=(const Color& color)
    {
        this->r = color.r;
        this->g = color.g;
        this->b = color.b;
        this->a = color.a;
        return *this;
    }
}
