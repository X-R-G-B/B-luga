/*
** EPITECH PROJECT, 2023
** R-Bus
** File description:
** Graphics
*/

#pragma once

#include <memory>
#include <string>
#include "B-luga-graphics/Raylib/Geometry/Geometry.hpp"
#include "B-luga-graphics/Raylib/Events/Inputs.hpp"
#include "B-luga/Registry.hpp"

namespace Raylib {

    enum class ConfigFlags : int {
        VSYNC_HINT                ,
        FULLSCREEN_MODE           ,
        WINDOW_RESIZABLE          ,
        WINDOW_UNDECORATED        ,
        WINDOW_HIDDEN             ,
        WINDOW_MINIMIZED          ,
        WINDOW_MAXIMIZED          ,
        WINDOW_UNFOCUSED          ,
        WINDOW_TOPMOST            ,
        WINDOW_ALWAYS_RUN         ,
        WINDOW_TRANSPARENT        ,
        WINDOW_HIGHDPI            ,
        WINDOW_MOUSE_PASSTHROUGH  ,
        MSAA_4X_HINT              ,
        INTERLACED_HINT           ,
    };

    class Graphics {
        public:
            static int getEquivalentRaylibConfigFlags(ConfigFlags flags);
    };

    class Cursor {
        public:
            static void showCursor();

            static void hideCursor();

            static bool isCursorHidden();

            static void enableCursor();

            static void disableCursor();

            static bool isCursorOnScreen();

    };

    class Drawing {
        public:
            static void clearBackground(Color color);

            static void beginDrawing();

            static void endDrawing();

    };

        // Timing-related functions
    class Frame {
        public:
            static void setTargetFPS(int fps);

            static int getFPS();

            static float getFrameTime();

            static double getTime();

            static void drawFPS(int posX, int posY);
    };

    class Screenshot {
        public:
            static void takeScreenshot(const std::string &fileName);
    };

    class KeyboardInput {
        public:
            static bool isKeyPressed(KeyboardKey key);

            static bool isKeyDown(KeyboardKey key);

            static bool isKeyReleased(KeyboardKey key);

            static bool isKeyUp(KeyboardKey key);

            static void setExitKey(KeyboardKey key);

            static int getKeyPressed();

            static int getCharPressed();
    };

    class MouseInput {
        public:
            static bool isMouseButtonPressed(MouseButton button);

            static bool isMouseButtonDown(MouseButton button);

            static bool isMouseButtonReleased(MouseButton button);

            static bool isMouseButtonUp(MouseButton button);

            static Vector2 getMousePosition();

            static int getMouseX();

            static int getMouseY();

            static void setMousePosition(int x, int y);

            static Vector2 getMouseDelta();

            static void setMouseOffset(int offsetX, int offsetY);

            static void setMouseScale(float scaleX, float scaleY);

            static float getMouseWheelMove();

            static Vector2 getMouseWheelMoveV();

            static void setMouseCursor(int cursor);
    };

    class DrawShape {
        public:
            static void drawPixel(int posX, int posY, Color color);

            static void drawCircle(int centerX, int centerY, float radius, Color color);

            static void drawRectangle(int posX, int posY, int width, int height, Color color);
    };

    class RayColor {
        public:
            static Color fade(Color color, float alpha);

            static int colorToInt(Color color);

            static Vector4 colorNormalize(Color color);

            static Color colorFromNormalized(Vector4 normalized);

            static Color getColor(unsigned int hexValue);
    };

    class RayImage {
        public:
            static std::unique_ptr<RayImage> fromFile(const std::string &fileName);
            static std::unique_ptr<RayImage> fromColor(int width, int height, Color color);

            virtual bool isImageReady() = 0;

            virtual void unloadImage() = 0;

            virtual int getWidth() const = 0;

            virtual int getHeight() const = 0;

            virtual int getMipmaps() const = 0;

            virtual int getFormat() const = 0;

            virtual void setData(const RayImage &image) = 0;
            virtual void *getData() = 0;
    };

    class Sprite {
        public:
            static std::unique_ptr<Sprite> fromFile(const std::string &fileName, float width, float height, std::size_t id = 0);
            static std::unique_ptr<Sprite> fromRayImage(std::unique_ptr<RayImage> image, float width, float height);

            virtual void unloadSprite() = 0;

            virtual unsigned int getId() const = 0;

            virtual float getWidth() const = 0;

            virtual float getHeight() const = 0;

            virtual int getTextureWidth() const = 0;

            virtual int getTextureHeight() const = 0;

            virtual int getMipmaps() const = 0;

            virtual int getFormat() const = 0;

            // draw texture functions

            virtual void draw(int posX, int posY, Color tint) = 0;

            virtual void drawV(Vector2 position, Color tint) = 0;

            virtual void drawEx(Vector2 position, float rotation, float scale, Color tint) = 0;

            virtual void drawRec(Rectangle source, Vector2 position, Color tint) = 0;

            virtual void drawPro(Rectangle source, Rectangle dest, Vector2 origin, float rotation, Color tint) = 0;
    };

    class Window {
        public:
        static void initWindow(int width, int height, const std::string &title);

        static bool windowShouldClose();

        static void closeWindow();

        static bool isWindowReady();

        static bool isWindowFullscreen();

        static bool isWindowHidden();

        static bool isWindowMinimized();

        static bool isWindowMaximized();

        static bool isWindowFocused();

        static void setConfigFlags(ConfigFlags flags);

        static bool isWindowResized();

        static bool isWindowState(ConfigFlags flag);

        static void setWindowState(ConfigFlags flags);

        static void clearWindowState(ConfigFlags flags);

        static void toggleFullscreen();

        static void maximizeWindow();

        static void minimizeWindow();

        static void setWindowTitle(const std::string &title);

        static int getScreenWidth();

        static int getScreenHeight();

        static int getRenderWidth();

        static int getRenderHeight();

        static int getMonitorWidth(int monitor);

        static int getMonitorHeight(int monitor);

        static int getMonitorRefreshRate(int monitor);

        static int getCurrentMonitor();

        static void setClipboardText(const std::string &text);

        static std::string getClipboardText();

        static void setWindowIcon(std::unique_ptr<RayImage> icon);
    };

    // Text functions and classes

    class Text {
        public:
            static void drawText(std::string text, int posX, int posY, int fontSize, Color color);

            static int measureText(const std::string text, int fontSize);

            static std::unique_ptr<Text> fromText(const std::string &text, Vector2 position, float fontSize, Color color);

            virtual void draw() = 0;

            virtual void drawEx(float spacing) = 0;

            virtual void drawPro(Vector2 origin, float rotation, float spacing) = 0;

            virtual float x() const = 0;

            virtual float y() const = 0;

            virtual float getFontSize() const = 0;

            virtual void setFontSize(float fontSize) = 0;

            virtual Vector2 getPosition() const = 0;

            virtual void setPixelPosition(Vector2 position) = 0;

            virtual void setColor(Color color) = 0;

            virtual Color getColor() const = 0;

            virtual void setCurrentFontSize(float fontSize) = 0;
    };
} // namespace Raylib
