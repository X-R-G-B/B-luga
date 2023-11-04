/*
** EPITECH PROJECT, 2023
** R-Bus
** File description:
** Graphics
*/

#pragma once

#include <memory>
#include <string>
#include <map>
extern "C"
{
#include "raylib.h"
}
#include "B-luga-graphics/Raylib/Geometry/Geometry.hpp"
#include "B-luga-graphics/Raylib/Events/Inputs.hpp"
#include "B-luga-graphics/Raylib/Graphics/Graphics.hpp"
#include "B-luga/Registry.hpp"

namespace Raylib {

    class RayImageImpl : public RayImage {
        public:
            RayImageImpl(const std::string &fileName);

            RayImageImpl(int width, int height, Color color);

            ~RayImageImpl();

            bool isImageReady() override;

            void unloadImage() override;

            int getWidth() const override;

            int getHeight() const override;

            int getMipmaps() const override;

            int getFormat() const override;

            void *getData() override;
        private:
            ::Image _image;
    };

    class TextureManagerImpl : public TextureManager {
        public:
            static TextureManagerImpl &getInstance();
            ::Texture2D &getTexture(const std::string &fileName);
            void unloadTextures() override;
            void preloadTexture(const std::string &path) override;

        private:
            std::map<std::string, ::Texture2D> _textures;
            std::mutex _mutex;
            ::Texture2D loadTexture(const std::string &path);
    };

    class SpriteImpl : public Sprite {
        public:
            SpriteImpl(const std::string &fileName, float width, float height, std::size_t id);

            SpriteImpl(std::unique_ptr<RayImage> image, float width, float height);

            unsigned int getId() const override;

            float getWidth() const override;

            float getHeight() const override;

            int getTextureWidth() const override;

            int getTextureHeight() const override;

            int getMipmaps() const override;

            int getFormat() const override;

            // draw texture functions

            void draw(int posX, int posY, Raylib::Color tint) override;

            void drawV(Vector2 position, Raylib::Color tint) override;

            void drawEx(Vector2 position, float rotation, float scale, Raylib::Color tint) override;

            void drawRec(Rectangle source, Vector2 position, Raylib::Color tint) override;

            void drawPro(Rectangle source, Rectangle dest, Vector2 origin, float rotation, Raylib::Color tint) override;

        private:
            void loadTextureFromImage(std::unique_ptr<RayImage> image);
            ::Texture2D _texture;
            std::unique_ptr<RayImage> _imageUnique;
            // width and height in percentage of the screen
            float _width;
            float _height;
    };


    // Text functions and classes

    class TextImpl : public Text {
        public:

            TextImpl(std::string text, Vector2 position, float fontSize, Raylib::Color color);

            void draw() override;

            void drawEx(float spacing) override;

            void drawPro(Vector2 origin, float rotation, float spacing) override;

            [[nodiscard]] float x() const override;

            [[nodiscard]] float y() const override;

            [[nodiscard]] float getFontSize() const override;

            void setFontSize(float fontSize) override;

            [[nodiscard]] Vector2 getPosition() const override;

            void setPixelPosition(Vector2 position) override;

            void setColor(Raylib::Color color) override;

            [[nodiscard]] Raylib::Color getColor() const override;

            [[nodiscard]] const std::string &getCurrentText() const override;

            void setCurrentText(const std::string &text) override;

        private:
            std::string _text;
            float _fontSize;
            Raylib::Color _color;
            Vector2 _position;
            Vector2 _pixelPosition;
    };
} // namespace Raylib
