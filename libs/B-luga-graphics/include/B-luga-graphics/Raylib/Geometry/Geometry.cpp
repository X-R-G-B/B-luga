extern "C" {
#include "raylib.h"
}
#include "Geometry.hpp"

namespace Raylib {
    Color::Color(const Color &color) : r(color.r), g(color.g), b(color.b), a(color.a) {}

    Color::Color(ColorDef colorDef)
    {
        switch (colorDef) {
            case ColorDef::DarkGray   :
                *this = Raylib::Color(80, 80, 80, 255);
                break;
            case ColorDef::Yellow     :
                *this = Raylib::Color(253, 249, 0, 255);
                break;
            case ColorDef::Gold       :
                *this = Raylib::Color(255, 203, 0, 255);
                break;
            case ColorDef::Orange     :
                *this = Raylib::Color(255, 161, 0, 255);
                break;
            case ColorDef::Pink       :
                *this = Raylib::Color(255, 109, 194, 255);
                break;
            case ColorDef::Red        :
                *this = Raylib::Color(230, 41, 55, 255);
                break;
            case ColorDef::Maroon     :
                *this = Raylib::Color(190, 33, 55, 255);
                break;
            case ColorDef::Green      :
                *this = Raylib::Color(0, 228, 48, 255);
                break;
            case ColorDef::Lime       :
                *this = Raylib::Color(0, 158, 47, 255);
                break;
            case ColorDef::DarkGreen  :
                *this = Raylib::Color(0, 117, 44, 255);
                break;
            case ColorDef::SkyBlue    :
                *this = Raylib::Color(102, 191, 255, 255);
                break;
            case ColorDef::Blue       :
                *this = Raylib::Color(0, 121, 241, 255);
                break;
            case ColorDef::DarkBlue   :
                *this = Raylib::Color(0, 82, 172, 255);
                break;
            case ColorDef::Purple     :
                *this = Raylib::Color(200, 122, 255, 255);
                break;
            case ColorDef::Violet     :
                *this = Raylib::Color(135, 60, 190, 255);
                break;
            case ColorDef::DarkPurple :
                *this = Raylib::Color(112, 31, 126, 255);
                break;
            case ColorDef::Beige      :
                *this = Raylib::Color(211, 176, 131, 255);
                break;
            case ColorDef::Brown      :
                *this = Raylib::Color(127, 106, 79, 255);
                break;
            case ColorDef::DarkBrown  :
                *this = Raylib::Color(76, 63, 47, 255);
                break;
            case ColorDef::White      :
                *this = Raylib::Color(255, 255, 255, 255);
                break;
            case ColorDef::Black      :
                *this = Raylib::Color(0, 0, 0, 255);
                break;
            case ColorDef::Blank      :
                *this = Raylib::Color(0, 0, 0, 0);
                break;
            case ColorDef::Magenta    :
                *this = Raylib::Color(255, 0, 255, 255);
                break;
            case ColorDef::RayWhite   :
                *this = Raylib::Color(245, 245, 245, 255);
                break;
            default                :
                *this = Raylib::Color(0, 0, 0, 0);
                break;
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
