extern "C" {
#include "raylib.h"
}
#include "Geometry.hpp"

namespace Raylib {
    Color::Color(ColorDef color)
    {
        switch (color) {
            case ColorDef::DarkGray   : return Raylib::Color(80, 80, 80, 255);
            case ColorDef::Yellow     : return Raylib::Color(253, 249, 0, 255);
            case ColorDef::Gold       : return Raylib::Color(255, 203, 0, 255);
            case ColorDef::Orange     : return Raylib::Color(255, 161, 0, 255);
            case ColorDef::Pink       : return Raylib::Color(255, 109, 194, 255);
            case ColorDef::Red        : return Raylib::Color(230, 41, 55, 255);
            case ColorDef::Maroon     : return Raylib::Color(190, 33, 55, 255);
            case ColorDef::Green      : return Raylib::Color(0, 228, 48, 255);
            case ColorDef::Lime       : return Raylib::Color(0, 158, 47, 255);
            case ColorDef::DarkGreen  : return Raylib::Color(0, 117, 44, 255);
            case ColorDef::SkyBlue    : return Raylib::Color(102, 191, 255, 255);
            case ColorDef::Blue       : return Raylib::Color(0, 121, 241, 255);
            case ColorDef::DarkBlue   : return Raylib::Color(0, 82, 172, 255);
            case ColorDef::Purple     : return Raylib::Color(200, 122, 255, 255);
            case ColorDef::Violet     : return Raylib::Color(135, 60, 190, 255);
            case ColorDef::DarkPurple : return Raylib::Color(112, 31, 126, 255);
            case ColorDef::Beige      : return Raylib::Color(211, 176, 131, 255);
            case ColorDef::Brown      : return Raylib::Color(127, 106, 79, 255);
            case ColorDef::DarkBrown  : return Raylib::Color(76, 63, 47, 255);
            case ColorDef::White      : return Raylib::Color(255, 255, 255, 255);
            case ColorDef::Black      : return Raylib::Color(0, 0, 0, 255);
            case ColorDef::Blank      : return Raylib::Color(0, 0, 0, 0);
            case ColorDef::Magenta    : return Raylib::Color(255, 0, 255, 255);
            case ColorDef::RayWhite   : return Raylib::Color(245, 245, 245, 255);
            default                : return Raylib::Color(0, 0, 0, 0);
        }
        return Raylib::Color(0, 0, 0, 0);
    }
}
