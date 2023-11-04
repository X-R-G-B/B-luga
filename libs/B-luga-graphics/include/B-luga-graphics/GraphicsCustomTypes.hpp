/*
** EPITECH PROJECT, 2023
** R-Bus
** File description:
** Custom Types
*/

#pragma once

#include <unordered_map>
#include <string>
#include <functional>
#include "nlohmann/json.hpp"
#include "B-luga-graphics/Raylib/Raylib.hpp"

namespace Types {
    struct Rect {
        float x;
        float y;
        float width;
        float height;

        NLOHMANN_DEFINE_TYPE_INTRUSIVE(Rect, x, y, width, height);
    };

    struct Parallax {
        float x;
        float y;
    };

    struct RectangleShape {
        float width;
        float height;
    };

    struct FontSize {
        float fsz;
    };

    struct Origin {
        float x;
        float y;
    };

    struct Rotation {
        float rotate;
    };

    struct Scale {
        float size;
    };

    struct Button {
        Button(std::function<void()> &fct) : callback(fct) {};
        std::function<void()> callback;
    };

    struct InputBox {
        InputBox(
            std::string &textStr,
            std::string &boxName,
            std::size_t &maxCharacters,
            bool isSelected = false)
            : name(boxName),
              text(textStr),
              maxChar(maxCharacters),
              selected(isSelected) {};
        std::string name;
        std::string text;
        std::size_t maxChar;
        bool selected;
    };

    struct Color {
            Color(Raylib::Color color) : color(color) {};
            Raylib::Color color;
    };

    static const std::unordered_map<std::string, Raylib::Color> colorMatchStrings({
            {"darkgray",   Raylib::Color(Raylib::ColorDef::DarkGray)  },
            {"yellow",     Raylib::Color(Raylib::ColorDef::Yellow)    },
            {"gold",       Raylib::Color(Raylib::ColorDef::Gold)      },
            {"orange",     Raylib::Color(Raylib::ColorDef::Orange)    },
            {"pink",       Raylib::Color(Raylib::ColorDef::Pink)      },
            {"red",        Raylib::Color(Raylib::ColorDef::Red)       },
            {"maroon",     Raylib::Color(Raylib::ColorDef::Maroon)    },
            {"green",      Raylib::Color(Raylib::ColorDef::Green)     },
            {"lime",       Raylib::Color(Raylib::ColorDef::Lime)      },
            {"darkgreen",  Raylib::Color(Raylib::ColorDef::DarkGreen) },
            {"skyblue",    Raylib::Color(Raylib::ColorDef::SkyBlue)   },
            {"blue",       Raylib::Color(Raylib::ColorDef::Blue)      },
            {"darkblue",   Raylib::Color(Raylib::ColorDef::DarkBlue)  },
            {"purple",     Raylib::Color(Raylib::ColorDef::Purple)    },
            {"violet",     Raylib::Color(Raylib::ColorDef::Violet)    },
            {"darkpurple", Raylib::Color(Raylib::ColorDef::DarkPurple)},
            {"beige",      Raylib::Color(Raylib::ColorDef::Beige)     },
            {"brown",      Raylib::Color(Raylib::ColorDef::Brown)     },
            {"darkbrown",  Raylib::Color(Raylib::ColorDef::DarkBrown) },
            {"white",      Raylib::Color(Raylib::ColorDef::White)     },
            {"black",      Raylib::Color(Raylib::ColorDef::Black)     },
            {"blank",      Raylib::Color(Raylib::ColorDef::Blank)     },
            {"magenta",    Raylib::Color(Raylib::ColorDef::Magenta)   },
            {"white",      Raylib::Color(Raylib::ColorDef::RayWhite)  }
    });
} // namespace Types
