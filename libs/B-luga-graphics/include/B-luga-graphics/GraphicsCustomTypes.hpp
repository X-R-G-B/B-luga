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
            Raylib::Color color;
    };

    static const std::unordered_map<std::string, Raylib::Color> colorMatchStrings({
            {"darkgray",   Raylib::Color(DarkGray)  },
            {"yellow",     Raylib::Color(Yellow)    },
            {"gold",       Raylib::Color(Gold)      },
            {"orange",     Raylib::Color(Orange)    },
            {"pink",       Raylib::Color(Pink)      },
            {"red",        Raylib::Color(Red)       },
            {"maroon",     Raylib::Color(Maroon)    },
            {"green",      Raylib::Color(Green)     },
            {"lime",       Raylib::Color(Lime)      },
            {"darkgreen",  Raylib::Color(DarkGreen) },
            {"skyblue",    Raylib::Color(SkyBlue)   },
            {"blue",       Raylib::Color(Blue)      },
            {"darkblue",   Raylib::Color(DarkBlue)  },
            {"purple",     Raylib::Color(Purple)    },
            {"violet",     Raylib::Color(Violet)    },
            {"darkpurple", Raylib::Color(DarkPurple)},
            {"beige",      Raylib::Color(Beige)     },
            {"brown",      Raylib::Color(Brown)     },
            {"darkbrown",  Raylib::Color(DarkBrown) },
            {"white",      Raylib::Color(White)     },
            {"black",      Raylib::Color(Black)     },
            {"blank",      Raylib::Color(Blank)     },
            {"magenta",    Raylib::Color(Magenta)   },
            {"white",      Raylib::Color(RayWhite)  }
    });
} // namespace Types
