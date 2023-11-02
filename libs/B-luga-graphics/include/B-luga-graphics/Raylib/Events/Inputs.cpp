#include "Inputs.hpp"
extern "C" {
#include "raylib.h"
}

namespace Raylib {
    int Inputs::getEquivalentRaylibKey(KeyboardKey key)
    {
        switch (key) {
        case KeyboardKey::KB_NULL          : return KEY_NULL;
        case KeyboardKey::KB_APOSTROPHE    : return KEY_APOSTROPHE;
        case KeyboardKey::KB_COMMA         : return KEY_COMMA;
        case KeyboardKey::KB_MINUS         : return KEY_MINUS;
        case KeyboardKey::KB_PERIOD        : return KEY_PERIOD;
        case KeyboardKey::KB_SLASH         : return KEY_SLASH;
        case KeyboardKey::KB_ZERO          : return KEY_ZERO;
        case KeyboardKey::KB_ONE           : return KEY_ONE;
        case KeyboardKey::KB_TWO           : return KEY_TWO;
        case KeyboardKey::KB_THREE         : return KEY_THREE;
        case KeyboardKey::KB_FOUR          : return KEY_FOUR;
        case KeyboardKey::KB_FIVE          : return KEY_FIVE;
        case KeyboardKey::KB_SIX           : return KEY_SIX;
        case KeyboardKey::KB_SEVEN         : return KEY_SEVEN;
        case KeyboardKey::KB_EIGHT         : return KEY_EIGHT;
        case KeyboardKey::KB_NINE          : return KEY_NINE;
        case KeyboardKey::KB_SEMICOLON     : return KEY_SEMICOLON;
        case KeyboardKey::KB_EQUAL         : return KEY_EQUAL;
        case KeyboardKey::KB_A             : return KEY_A;
        case KeyboardKey::KB_B             : return KEY_B;
        case KeyboardKey::KB_C             : return KEY_C;
        case KeyboardKey::KB_D             : return KEY_D;
        case KeyboardKey::KB_E             : return KEY_E;
        case KeyboardKey::KB_F             : return KEY_F;
        case KeyboardKey::KB_G             : return KEY_G;
        case KeyboardKey::KB_H             : return KEY_H;
        case KeyboardKey::KB_I             : return KEY_I;
        case KeyboardKey::KB_J             : return KEY_J;
        case KeyboardKey::KB_K             : return KEY_K;
        case KeyboardKey::KB_L             : return KEY_L;
        case KeyboardKey::KB_M             : return KEY_M;
        case KeyboardKey::KB_N             : return KEY_N;
        case KeyboardKey::KB_O             : return KEY_O;
        case KeyboardKey::KB_P             : return KEY_P;
        case KeyboardKey::KB_Q             : return KEY_Q;
        case KeyboardKey::KB_R             : return KEY_R;
        case KeyboardKey::KB_S             : return KEY_S;
        case KeyboardKey::KB_T             : return KEY_T;
        case KeyboardKey::KB_U             : return KEY_U;
        case KeyboardKey::KB_V             : return KEY_V;
        case KeyboardKey::KB_W             : return KEY_W;
        case KeyboardKey::KB_X             : return KEY_X;
        case KeyboardKey::KB_Y             : return KEY_Y;
        case KeyboardKey::KB_Z             : return KEY_Z;
        case KeyboardKey::KB_LEFT_BRACKET  : return KEY_LEFT_BRACKET;
        case KeyboardKey::KB_BACKSLASH     : return KEY_BACKSLASH;
        case KeyboardKey::KB_RIGHT_BRACKET : return KEY_RIGHT_BRACKET;
        case KeyboardKey::KB_GRAVE         : return KEY_GRAVE;
        case KeyboardKey::KB_SPACE         : return KEY_SPACE;
        case KeyboardKey::KB_ESCAPE        : return KEY_ESCAPE;
        case KeyboardKey::KB_ENTER         : return KEY_ENTER;
        case KeyboardKey::KB_TAB           : return KEY_TAB;
        case KeyboardKey::KB_BACKSPACE     : return KEY_BACKSPACE;
        case KeyboardKey::KB_INSERT        : return KEY_INSERT;
        case KeyboardKey::KB_DELETE        : return KEY_DELETE;
        case KeyboardKey::KB_RIGHT         : return KEY_RIGHT;
        case KeyboardKey::KB_LEFT          : return KEY_LEFT;
        case KeyboardKey::KB_DOWN          : return KEY_DOWN;
        case KeyboardKey::KB_UP            : return KEY_UP;
        case KeyboardKey::KB_PAGE_UP       : return KEY_PAGE_UP;
        case KeyboardKey::KB_PAGE_DOWN     : return KEY_PAGE_DOWN;
        case KeyboardKey::KB_HOME          : return KEY_HOME;
        case KeyboardKey::KB_END           : return KEY_END;
        case KeyboardKey::KB_CAPS_LOCK     : return KEY_CAPS_LOCK;
        case KeyboardKey::KB_SCROLL_LOCK   : return KEY_SCROLL_LOCK;
        case KeyboardKey::KB_NUM_LOCK      : return KEY_NUM_LOCK;
        case KeyboardKey::KB_PRINT_SCREEN  : return KEY_PRINT_SCREEN;
        case KeyboardKey::KB_PAUSE         : return KEY_PAUSE;
        case KeyboardKey::KB_F1            : return KEY_F1;
        case KeyboardKey::KB_F2            : return KEY_F2;
        case KeyboardKey::KB_F3            : return KEY_F3;
        case KeyboardKey::KB_F4            : return KEY_F4;
        case KeyboardKey::KB_F5            : return KEY_F5;
        case KeyboardKey::KB_F6            : return KEY_F6;
        case KeyboardKey::KB_F7            : return KEY_F7;
        case KeyboardKey::KB_F8            : return KEY_F8;
        case KeyboardKey::KB_F9            : return KEY_F9;
        case KeyboardKey::KB_F10           : return KEY_F10;
        case KeyboardKey::KB_F11           : return KEY_F11;
        case KeyboardKey::KB_F12           : return KEY_F12;
        case KeyboardKey::KB_LEFT_SHIFT    : return KEY_LEFT_SHIFT;
        case KeyboardKey::KB_LEFT_CONTROL  : return KEY_LEFT_CONTROL;
        case KeyboardKey::KB_LEFT_ALT      : return KEY_LEFT_ALT;
        case KeyboardKey::KB_LEFT_SUPER    : return KEY_LEFT_SUPER;
        case KeyboardKey::KB_RIGHT_SHIFT   : return KEY_RIGHT_SHIFT;
        case KeyboardKey::KB_RIGHT_CONTROL : return KEY_RIGHT_CONTROL;
        case KeyboardKey::KB_RIGHT_ALT     : return KEY_RIGHT_ALT;
        case KeyboardKey::KB_RIGHT_SUPER   : return KEY_RIGHT_SUPER;
        case KeyboardKey::KB_MENU          : return KEY_MENU;
        default               : return -1;
        }
    }

    int Inputs::getEquivalentRaylibMouse(MouseButton button)
    {
        switch (button) {

        case MouseButton::MOUSE_BTN_LEFT    : return MOUSE_BUTTON_LEFT;
        case MouseButton::MOUSE_BTN_RIGHT   : return MOUSE_BUTTON_RIGHT;
        case MouseButton::MOUSE_BTN_MIDDLE  : return MOUSE_BUTTON_LEFT;
        case MouseButton::MOUSE_BTN_SIDE    : return MOUSE_BUTTON_SIDE;
        case MouseButton::MOUSE_BTN_EXTRA   : return MOUSE_BUTTON_EXTRA;
        case MouseButton::MOUSE_BTN_FORWARD : return MOUSE_BUTTON_FORWARD;
        case MouseButton::MOUSE_BTN_BACK    : return MOUSE_BUTTON_BACK;
        default                : return -1;
        }
    }

    KeyboardKey Inputs::getRaylibKey(int equivalent)
    {
        for (int i = 0; i < static_cast<int>(KeyboardKey::KB_MAX_MAX); i++) {
            if (equivalent == getEquivalentRaylibKey(static_cast<KeyboardKey>(i))) {
                return static_cast<KeyboardKey>(i);
            }
        }
        return KeyboardKey::KB_MAX_MAX;
    }

    MouseButton Inputs::getRaylibMouse(int equivalent)
    {
        for (int i = 0; i < static_cast<int>(MouseButton::MOUSE_MAX_MAX); i++) {
            if (equivalent == getEquivalentRaylibMouse(static_cast<MouseButton>(i))) {
                return static_cast<MouseButton>(i);
            }
        }
        return MouseButton::MOUSE_MAX_MAX;
    }
}
