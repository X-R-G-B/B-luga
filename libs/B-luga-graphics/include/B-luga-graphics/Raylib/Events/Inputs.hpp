/*
** EPITECH PROJECT, 2023
** R-Bus
** File description:
** Inputs
*/

#pragma once

namespace Raylib {

    enum class KeyboardKey : int {
        KB_NULL           = 0,
        KB_APOSTROPHE     ,
        KB_COMMA          ,
        KB_MINUS          ,
        KB_PERIOD         ,
        KB_SLASH          ,
        KB_ZERO           ,
        KB_ONE            ,
        KB_TWO            ,
        KB_THREE          ,
        KB_FOUR           ,
        KB_FIVE           ,
        KB_SIX            ,
        KB_SEVEN          ,
        KB_EIGHT          ,
        KB_NINE           ,
        KB_SEMICOLON      ,
        KB_EQUAL          ,
        KB_A              ,
        KB_B              ,
        KB_C              ,
        KB_D              ,
        KB_E              ,
        KB_F              ,
        KB_G              ,
        KB_H              ,
        KB_I              ,
        KB_J              ,
        KB_K              ,
        KB_L              ,
        KB_M              ,
        KB_N              ,
        KB_O              ,
        KB_P              ,
        KB_Q              ,
        KB_R              ,
        KB_S              ,
        KB_T              ,
        KB_U              ,
        KB_V              ,
        KB_W              ,
        KB_X              ,
        KB_Y              ,
        KB_Z              ,
        KB_LEFT_BRACKET   ,
        KB_BACKSLASH      ,
        KB_RIGHT_BRACKET  ,
        KB_GRAVE          ,
        KB_SPACE          ,
        KB_ESCAPE         ,
        KB_ENTER          ,
        KB_TAB            ,
        KB_BACKSPACE      ,
        KB_INSERT         ,
        KB_DELETE         ,
        KB_RIGHT          ,
        KB_LEFT           ,
        KB_DOWN           ,
        KB_UP             ,
        KB_PAGE_UP        ,
        KB_PAGE_DOWN      ,
        KB_HOME           ,
        KB_END            ,
        KB_CAPS_LOCK      ,
        KB_SCROLL_LOCK    ,
        KB_NUM_LOCK       ,
        KB_PRINT_SCREEN   ,
        KB_PAUSE          ,
        KB_F1             ,
        KB_F2             ,
        KB_F3             ,
        KB_F4             ,
        KB_F5             ,
        KB_F6             ,
        KB_F7             ,
        KB_F8             ,
        KB_F9             ,
        KB_F10            ,
        KB_F11            ,
        KB_F12            ,
        KB_LEFT_SHIFT     ,
        KB_LEFT_CONTROL   ,
        KB_LEFT_ALT       ,
        KB_LEFT_SUPER     ,
        KB_RIGHT_SHIFT    ,
        KB_RIGHT_CONTROL  ,
        KB_RIGHT_ALT      ,
        KB_RIGHT_SUPER    ,
        KB_MENU           ,
        KB_MAX_MAX        ,
    };

    enum class MouseButton : int {
        MOUSE_BTN_LEFT     = 0,
        MOUSE_BTN_RIGHT    ,
        MOUSE_BTN_MIDDLE   ,
        MOUSE_BTN_SIDE     ,
        MOUSE_BTN_EXTRA    ,
        MOUSE_BTN_FORWARD  ,
        MOUSE_BTN_BACK     ,
        MOUSE_MAX_MAX      ,
    };

    class Inputs {
        public:
            static int getEquivalentRaylibKey(KeyboardKey key);
            static int getEquivalentRaylibMouse(MouseButton button);
            static KeyboardKey getRaylibKey(int equivalent);
            static MouseButton getRaylibMouse(int equivalent);
    };
} // namespace Raylib
