/*
** EPITECH PROJECT, 2023
** R-Bus
** File description:
** Graphics
*/

#pragma once

#include <string>
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

            void setData(RayImage image) override;
        private:
            ::Image _image;
    };

    class SpriteImpl {
        public:
            SpriteImpl(const std::string &fileName, float width, float height, std::size_t id);

            SpriteImpl(RayImage image, float width, float height) : _texture(), _width(width), _height(height);

            void unloadSprite() override;

            unsigned int getId() const override;

            float getWidth() const override;

            float getHeight() const override;

            int getTextureWidth() const override;

            int getTextureHeight() const override;

            int getMipmaps() const override;

            int getFormat() const override;

            // draw texture functions

            void draw(int posX, int posY, Color tint) override;

            void drawV(Vector2 position, Color tint) override;

            void drawEx(Vector2 position, float rotation, float scale, Color tint) override;

            void drawRec(Rectangle source, Vector2 position, Color tint) override;

            void drawPro(Rectangle source, Rectangle dest, Vector2 origin, float rotation, Color tint) override;

        private:
            void loadTextureFromImage(RayImage image);
            ::Texture2D _texture;
            // width and height in percentage of the screen
            float _width;
            float _height;
    };


    // Text functions and classes

    class TextImpl : public Text {
        public:

            TextImpl(std::string text, Vector2 position, float fontSize, Color color);

            void draw() override;

            void drawEx(float spacing) override;

            void drawPro(Vector2 origin, float rotation, float spacing) override;

            float x() const override;

            float y() const override;

            float getFontSize() const override;

            void setFontSize(float fontSize) override;

            Vector2 getPosition() const override;

            void setPixelPosition(Vector2 position) override;

            void setColor(Color color) override;

            Color getColor() const override;

            void setCurrentFontSize(float fontSize) override;

        private:
            std::string _text;
            float _fontSize;
            float _currentFontSize;
            Color _color;
            Vector2 _position;
            Vector2 _pixelPosition;
    };
} // namespace Raylib
