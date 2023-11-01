#include "Inputs.hpp"
extern "C" {
#include "raylib.h"
}

namespace Raylib {
    int Inputs::getEquivalentRaylibKey(KeyboardKey key)
    {
        switch (key) {
        case KB_NULL          : return KEY_NULL;
        case KB_APOSTROPHE    : return KEY_APOSTROPHE;
        case KB_COMMA         : return KEY_COMMA;
        case KB_MINUS         : return KEY_MINUS;
        case KB_PERIOD        : return KEY_PERIOD;
        case KB_SLASH         : return KEY_SLASH;
        case KB_ZERO          : return KEY_ZERO;
        case KB_ONE           : return KEY_ONE;
        case KB_TWO           : return KEY_TWO;
        case KB_THREE         : return KEY_THREE;
        case KB_FOUR          : return KEY_FOUR;
        case KB_FIVE          : return KEY_FIVE;
        case KB_SIX           : return KEY_SIX;
        case KB_SEVEN         : return KEY_SEVEN;
        case KB_EIGHT         : return KEY_EIGHT;
        case KB_NINE          : return KEY_NINE;
        case KB_SEMICOLON     : return KEY_SEMICOLON;
        case KB_EQUAL         : return KEY_EQUAL;
        case KB_A             : return KEY_A;
        case KB_B             : return KEY_B;
        case KB_C             : return KEY_C;
        case KB_D             : return KEY_D;
        case KB_E             : return KEY_E;
        case KB_F             : return KEY_F;
        case KB_G             : return KEY_G;
        case KB_H             : return KEY_H;
        case KB_I             : return KEY_I;
        case KB_J             : return KEY_J;
        case KB_K             : return KEY_K;
        case KB_L             : return KEY_L;
        case KB_M             : return KEY_M;
        case KB_N             : return KEY_N;
        case KB_O             : return KEY_O;
        case KB_P             : return KEY_P;
        case KB_Q             : return KEY_Q;
        case KB_R             : return KEY_R;
        case KB_S             : return KEY_S;
        case KB_T             : return KEY_T;
        case KB_U             : return KEY_U;
        case KB_V             : return KEY_V;
        case KB_W             : return KEY_W;
        case KB_X             : return KEY_X;
        case KB_Y             : return KEY_Y;
        case KB_Z             : return KEY_Z;
        case KB_LEFT_BRACKET  : return KEY_LEFT_BRACKET;
        case KB_BACKSLASH     : return KEY_BACKSLASH;
        case KB_RIGHT_BRACKET : return KEY_RIGHT_BRACKET;
        case KB_GRAVE         : return KEY_GRAVE;
        case KB_SPACE         : return KEY_SPACE;
        case KB_ESCAPE        : return KEY_ESCAPE;
        case KB_ENTER         : return KEY_ENTER;
        case KB_TAB           : return KEY_TAB;
        case KB_BACKSPACE     : return KEY_BACKSPACE;
        case KB_INSERT        : return KEY_INSERT;
        case KB_DELETE        : return KEY_DELETE;
        case KB_RIGHT         : return KEY_RIGHT;
        case KB_LEFT          : return KEY_LEFT;
        case KB_DOWN          : return KEY_DOWN;
        case KB_UP            : return KEY_UP;
        case KB_PAGE_UP       : return KEY_PAGE_UP;
        case KB_PAGE_DOWN     : return KEY_PAGE_DOWN;
        case KB_HOME          : return KEY_HOME;
        case KB_END           : return KEY_END;
        case KB_CAPS_LOCK     : return KEY_CAPS_LOCK;
        case KB_SCROLL_LOCK   : return KEY_SCROLL_LOCK;
        case KB_NUM_LOCK      : return KEY_NUM_LOCK;
        case KB_PRINT_SCREEN  : return KEY_PRINT_SCREEN;
        case KB_PAUSE         : return KEY_PAUSE;
        case KB_F1            : return KEY_F1;
        case KB_F2            : return KEY_F2;
        case KB_F3            : return KEY_F3;
        case KB_F4            : return KEY_F4;
        case KB_F5            : return KEY_F5;
        case KB_F6            : return KEY_F6;
        case KB_F7            : return KEY_F7;
        case KB_F8            : return KEY_F8;
        case KB_F9            : return KEY_F9;
        case KB_F10           : return KEY_F10;
        case KB_F11           : return KEY_F11;
        case KB_F12           : return KEY_F12;
        case KB_LEFT_SHIFT    : return KEY_LEFT_SHIFT;
        case KB_LEFT_CONTROL  : return KEY_LEFT_CONTROL;
        case KB_LEFT_ALT      : return KEY_LEFT_ALT;
        case KB_LEFT_SUPER    : return KEY_LEFT_SUPER;
        case KB_RIGHT_SHIFT   : return KEY_RIGHT_SHIFT;
        case KB_RIGHT_CONTROL : return KEY_RIGHT_CONTROL;
        case KB_RIGHT_ALT     : return KEY_RIGHT_ALT;
        case KB_RIGHT_SUPER   : return KEY_RIGHT_SUPER;
        case KB_MENU          : return KEY_MENU;
        default               : return -1;
        }
    }

    int Inputs::getEquivalentRaylibMouse(MouseButton button)
    {
        switch (button) {

        case MOUSE_BTN_LEFT    : return MOUSE_BUTTON_LEFT;
        case MOUSE_BTN_RIGHT   : return MOUSE_BUTTON_RIGHT;
        case MOUSE_BTN_MIDDLE  : return MOUSE_BUTTON_LEFT;
        case MOUSE_BTN_SIDE    : return MOUSE_BUTTON_SIDE;
        case MOUSE_BTN_EXTRA   : return MOUSE_BUTTON_EXTRA;
        case MOUSE_BTN_FORWARD : return MOUSE_BUTTON_FORWARD;
        case MOUSE_BTN_BACK    : return MOUSE_BUTTON_BACK;
        default                : return -1;
        }
    }
}
