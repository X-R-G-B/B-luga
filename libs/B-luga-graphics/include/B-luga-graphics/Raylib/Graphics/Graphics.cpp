#include <memory>
extern "C" {
#include "raylib.h"
}
#include "RaylibImpl/Graphics/Graphics.hpp"
#include "B-luga-graphics/Raylib/Events/Inputs.hpp"
#include "Graphics.hpp"
#include "B-luga/PathResolver.hpp"
#include "B-luga-graphics/Raylib/Geometry/Geometry.hpp"

namespace Raylib {
    int Graphics::getEquivalentRaylibConfigFlags(ConfigFlags flags)
    {
        switch (flags) {
        case ConfigFlags::VSYNC_HINT               : return FLAG_VSYNC_HINT;
        case ConfigFlags::FULLSCREEN_MODE          : return FLAG_FULLSCREEN_MODE;
        case ConfigFlags::WINDOW_RESIZABLE         : return FLAG_WINDOW_RESIZABLE;
        case ConfigFlags::WINDOW_UNDECORATED       : return FLAG_WINDOW_UNDECORATED;
        case ConfigFlags::WINDOW_HIDDEN            : return FLAG_WINDOW_HIDDEN;
        case ConfigFlags::WINDOW_MINIMIZED         : return FLAG_WINDOW_MINIMIZED;
        case ConfigFlags::WINDOW_MAXIMIZED         : return FLAG_WINDOW_MAXIMIZED;
        case ConfigFlags::WINDOW_UNFOCUSED         : return FLAG_WINDOW_UNFOCUSED;
        case ConfigFlags::WINDOW_TOPMOST           : return FLAG_WINDOW_TOPMOST;
        case ConfigFlags::WINDOW_ALWAYS_RUN        : return FLAG_WINDOW_ALWAYS_RUN;
        case ConfigFlags::WINDOW_TRANSPARENT       : return FLAG_WINDOW_TRANSPARENT;
        case ConfigFlags::WINDOW_HIGHDPI           : return FLAG_WINDOW_HIGHDPI;
        case ConfigFlags::WINDOW_MOUSE_PASSTHROUGH : return FLAG_WINDOW_MOUSE_PASSTHROUGH;
        case ConfigFlags::MSAA_4X_HINT             : return FLAG_MSAA_4X_HINT;
        case ConfigFlags::INTERLACED_HINT          : return FLAG_INTERLACED_HINT;
        default                       : return 0;
        }
    }


            void Cursor::showCursor()
            {
                ShowCursor();
            }

            void Cursor::hideCursor()
            {
                HideCursor();
            }

            bool Cursor::isCursorHidden()
            {
                return IsCursorHidden();
            }

            void Cursor::enableCursor()
            {
                EnableCursor();
            }

            void Cursor::disableCursor()
            {
                DisableCursor();
            }

            bool Cursor::isCursorOnScreen()
            {
                return IsCursorOnScreen();
            }

            void Drawing::clearBackground(Raylib::Color color)
            {
                ClearBackground({color.r, color.g, color.b, color.a});
            }

            void Drawing::beginDrawing()
            {
                BeginDrawing();
            }

            void Drawing::endDrawing()
            {
                EndDrawing();
            }

            void Frame::setTargetFPS(int fps)
            {
                SetTargetFPS(fps);
            }

            int Frame::getFPS()
            {
                return GetFPS();
            }

            float Frame::getFrameTime()
            {
                return GetFrameTime();
            }

            double Frame::getTime()
            {
                return GetTime();
            }

            void Frame::drawFPS(int posX, int posY)
            {
                DrawFPS(posX, posY);
            }

            void Screenshot::takeScreenshot(const std::string &fileName)
            {
                TakeScreenshot(fileName.c_str());
            }

            // Collision check functions
            bool checkCollisionPointRec(Vector2 point, Rectangle rec)
            {
                return (CheckCollisionPointRec({point.x, point.y}, {rec.x, rec.y, rec.width, rec.height}));
            }

            bool KeyboardInput::isKeyPressed(KeyboardKey key)
            {
                return IsKeyPressed(static_cast<int>(Inputs::getEquivalentRaylibKey(key)));
            }

            bool KeyboardInput::isKeyDown(KeyboardKey key)
            {
                return IsKeyDown(static_cast<int>(Inputs::getEquivalentRaylibKey(key)));
            }

            bool KeyboardInput::isKeyReleased(KeyboardKey key)
            {
                return IsKeyReleased(static_cast<int>(Inputs::getEquivalentRaylibKey(key)));
            }

            bool KeyboardInput::isKeyUp(KeyboardKey key)
            {
                return IsKeyUp(static_cast<int>(Inputs::getEquivalentRaylibKey(key)));
            }

            void KeyboardInput::setExitKey(KeyboardKey key)
            {
                SetExitKey(static_cast<int>(Inputs::getEquivalentRaylibKey(key)));
            }

            int KeyboardInput::getKeyPressed()
            {
                return GetKeyPressed();
            }

            int KeyboardInput::getCharPressed()
            {
                return GetCharPressed();
            }

            bool MouseInput::isMouseButtonPressed(MouseButton button)
            {
                return IsMouseButtonPressed(static_cast<int>(button));
            }

            bool MouseInput::isMouseButtonDown(MouseButton button)
            {
                return IsMouseButtonDown(static_cast<int>(button));
            }

            bool MouseInput::isMouseButtonReleased(MouseButton button)
            {
                return IsMouseButtonReleased(static_cast<int>(button));
            }

            bool MouseInput::isMouseButtonUp(MouseButton button)
            {
                return IsMouseButtonUp(static_cast<int>(button));
            }

            Vector2 MouseInput::getMousePosition()
            {
                ::Vector2 position = GetMousePosition();
                return Vector2 {position.x, position.y};
            }

            int MouseInput::getMouseX()
            {
                return GetMouseX();
            }

            int MouseInput::getMouseY()
            {
                return GetMouseY();
            }

            void MouseInput::setMousePosition(int x, int y)
            {
                SetMousePosition(x, y);
            }

            Vector2 MouseInput::getMouseDelta()
            {
                ::Vector2 delta = GetMouseDelta();
                return Vector2 {delta.x, delta.y};
            }

            void MouseInput::setMouseOffset(int offsetX, int offsetY)
            {
                SetMouseOffset(offsetX, offsetY);
            }

            void MouseInput::setMouseScale(float scaleX, float scaleY)
            {
                SetMouseScale(scaleX, scaleY);
            }

            float MouseInput::getMouseWheelMove()
            {
                return GetMouseWheelMove();
            }

            Vector2 MouseInput::getMouseWheelMoveV()
            {
                ::Vector2 move = GetMouseWheelMoveV();
                return Vector2 {move.x, move.y};
            }

            void MouseInput::setMouseCursor(int cursor)
            {
                SetMouseCursor(cursor);
            }

            void DrawShape::drawPixel(int posX, int posY, Raylib::Color color)
            {
                ::Color c = {color.r, color.g, color.b, color.a};

                DrawPixel(posX, posY, c);
            }

            void DrawShape::drawCircle(int centerX, int centerY, float radius, Raylib::Color color)
            {
                ::Color c = {color.r, color.g, color.b, color.a};

                DrawCircle(centerX, centerY, radius, c);
            }

            void DrawShape::drawRectangle(int posX, int posY, int width, int height, Raylib::Color color)
            {
                ::Color c = {color.r, color.g, color.b, color.a};

                DrawRectangle(posX, posY, width, height, c);
            }


            Raylib::Color RayColor::fade(Raylib::Color color, float alpha)
            {
                ::Color c = {color.r, color.g, color.b, color.a};
                ::Color f = Fade(c, alpha);
                return Raylib::Color(f.r, f.g, f.b, f.a);
            }

            int RayColor::colorToInt(Raylib::Color color)
            {
                ::Color c = {color.r, color.g, color.b, color.a};
                return ColorToInt(c);
            }

            Vector4 RayColor::colorNormalize(Raylib::Color color)
            {
                ::Color c   = {color.r, color.g, color.b, color.a};
                ::Vector4 v = ColorNormalize(c);
                return Vector4 {v.x, v.y, v.z, v.w};
            }

            Raylib::Color RayColor::colorFromNormalized(Vector4 normalized)
            {
                ::Vector4 v = {normalized.x, normalized.y, normalized.z, normalized.w};
                ::Color c   = ColorFromNormalized(v);
                return Raylib::Color(c.r, c.g, c.b, c.a);
            }

            Raylib::Color RayColor::getColor(unsigned int hexValue)
            {
                ::Color c = GetColor(hexValue);
                return Raylib::Color(c.r, c.g, c.b, c.a);
            }

            std::unique_ptr<RayImage> RayImage::fromFile(const std::string &fileName)
            {
                return std::make_unique<RayImageImpl>(PathResolver::resolve(fileName));
            }

            std::unique_ptr<RayImage> RayImage::fromColor(int width, int height, Raylib::Color color)
            {
                return std::make_unique<RayImageImpl>(width, height, color);
            }

            std::shared_ptr<Sprite> Sprite::fromFile(const std::string &fileName, float width, float height, std::size_t id)
            {
                return std::make_shared<SpriteImpl>(PathResolver::resolve(fileName), width, height, id);
            }

            std::shared_ptr<Sprite> Sprite::fromRayImage(std::unique_ptr<RayImage> image, float width, float height)
            {
                return std::make_shared<SpriteImpl>(std::move(image), width, height);
            }

        void Window::initWindow(int width, int height, const std::string &title)
        {
            InitWindow(width, height, title.c_str());
        }

        void setWindowSize(int width, int height)
        {
            SetWindowSize(width, height);
        }

        bool Window::windowShouldClose()
        {
            return WindowShouldClose();
        }

        void Window::closeWindow()
        {
            CloseWindow();
        }

        bool Window::isWindowReady()
        {
            return IsWindowReady();
        }

        bool Window::isWindowFullscreen()
        {
            return IsWindowFullscreen();
        }

        bool Window::isWindowHidden()
        {
            return IsWindowHidden();
        }

        bool Window::isWindowMinimized()
        {
            return IsWindowMinimized();
        }

        bool Window::isWindowMaximized()
        {
            return IsWindowMaximized();
        }

        bool Window::isWindowFocused()
        {
            return IsWindowFocused();
        }

        void Window::setConfigFlags(ConfigFlags flags)
        {
            SetConfigFlags(static_cast<unsigned int>(flags));
        }

        bool Window::isWindowResized()
        {
            return IsWindowResized();
        }

        bool Window::isWindowState(ConfigFlags flag)
        {
            return IsWindowState(static_cast<unsigned int>(flag));
        }

        void Window::setWindowState(ConfigFlags flags)
        {
            SetWindowState(static_cast<unsigned int>(flags));
        }

        void Window::clearWindowState(ConfigFlags flags)
        {
            ClearWindowState(static_cast<unsigned int>(flags));
        }

        void Window::toggleFullscreen()
        {
            ToggleFullscreen();
        }

        void Window::maximizeWindow()
        {
            MaximizeWindow();
        }

        void Window::minimizeWindow()
        {
            MinimizeWindow();
        }

        void Window::setWindowTitle(const std::string &title)
        {
            SetWindowTitle(title.c_str());
        }

        int Window::getScreenWidth()
        {
            return GetScreenWidth();
        }

        int Window::getScreenHeight()
        {
            return GetScreenHeight();
        }

        int Window::getRenderWidth()
        {
            return GetRenderWidth();
        }

        int Window::getRenderHeight()
        {
            return GetRenderHeight();
        }

        int Window::getMonitorWidth(int monitor)
        {
            return GetMonitorWidth(monitor);
        }

        int Window::getMonitorHeight(int monitor)
        {
            return GetMonitorHeight(monitor);
        }

        int Window::getMonitorRefreshRate(int monitor)
        {
            return GetMonitorRefreshRate(monitor);
        }

        int Window::getCurrentMonitor()
        {
            return GetCurrentMonitor();
        }

        void Window::setClipboardText(const std::string &text)
        {
            SetClipboardText(text.c_str());
        }

        std::string Window::getClipboardText()
        {
            return GetClipboardText();
        }

        void Window::setWindowIcon(std::unique_ptr<RayImage> icon)
        {
            ::Image image;

            image.width   = icon->getWidth();
            image.height  = icon->getHeight();
            image.mipmaps = icon->getMipmaps();
            image.format  = icon->getFormat();
            image.data    = icon->getData();
            SetWindowIcon(image);
        }

            void Text::drawText(std::string text, int posX, int posY, int fontSize, Raylib::Color color)
            {
                ::Color textColor = {color.r, color.g, color.b, color.a};

                DrawText(text.c_str(), posX, posY, fontSize, textColor);
            }

            int Text::measureText(const std::string text, int fontSize)
            {
                return MeasureText(text.c_str(), fontSize);
            }

            std::shared_ptr<Text> Text::fromText(const std::string &text, Vector2 position, float fontSize, Color color, const std::string &keyword)
            {
                return std::make_shared<TextImpl>(text, position, fontSize, color, keyword);
            }

            TextureManager &TextureManager::getInstance()
            {
                return TextureManagerImpl::getInstance();
            }
}
