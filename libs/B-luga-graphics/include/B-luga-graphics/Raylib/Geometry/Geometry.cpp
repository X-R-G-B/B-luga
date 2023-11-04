extern "C" {
#include "raylib.h"
}
#include "Geometry.hpp"

namespace Raylib {
    Color::Color(ColorDef color)
    {
        switch (color) {
            case Color::DarkGray   : return Raylib::Color(80, 80, 80, 255);
            case Color::Yellow     : return Raylib::Color(253, 249, 0, 255);
            case Color::Gold       : return Raylib::Color(255, 203, 0, 255);
            case Color::Orange     : return Raylib::Color(255, 161, 0, 255);
            case Color::Pink       : return Raylib::Color(255, 109, 194, 255);
            case Color::Red        : return Raylib::Color(230, 41, 55, 255);
            case Color::Maroon     : return Raylib::Color(190, 33, 55, 255);
            case Color::Green      : return Raylib::Color(0, 228, 48, 255);
            case Color::Lime       : return Raylib::Color(0, 158, 47, 255);
            case Color::DarkGreen  : return Raylib::Color(0, 117, 44, 255);
            case Color::SkyBlue    : return Raylib::Color(102, 191, 255, 255);
            case Color::Blue       : return Raylib::Color(0, 121, 241, 255);
            case Color::DarkBlue   : return Raylib::Color(0, 82, 172, 255);
            case Color::Purple     : return Raylib::Color(200, 122, 255, 255);
            case Color::Violet     : return Raylib::Color(135, 60, 190, 255);
            case Color::DarkPurple : return Raylib::Color(112, 31, 126, 255);
            case Color::Beige      : return Raylib::Color(211, 176, 131, 255);
            case Color::Brown      : return Raylib::Color(127, 106, 79, 255);
            case Color::DarkBrown  : return Raylib::Color(76, 63, 47, 255);
            case Color::White      : return Raylib::Color(255, 255, 255, 255);
            case Color::Black      : return Raylib::Color(0, 0, 0, 255);
            case Color::Blank      : return Raylib::Color(0, 0, 0, 0);
            case Color::Magenta    : return Raylib::Color(255, 0, 255, 255);
            case Color::RayWhite   : return Raylib::Color(245, 245, 245, 255);
            default                : return Color(0, 0, 0, 0);
        }
        return Color(0, 0, 0, 0);
    }
}
