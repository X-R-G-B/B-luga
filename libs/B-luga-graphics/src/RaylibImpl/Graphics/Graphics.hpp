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
#include "B-luga/Registry.hpp"

namespace Raylib {

    class RayImage {
        public:
            RayImage(const std::string &fileName)
                : _image(LoadImage(fileName.c_str()))
            {
                if (!isImageReady()) {
                    const ::Color badTexture          = {255, 16, 240, 255};
                    static constexpr int badImageSize = 50;
                    _image                            = GenImageColor(badImageSize, badImageSize, badTexture);
                }
            }

            RayImage(int width, int height, Color color)
                : _image(GenImageColor(width, height, {color.r, color.g, color.b, color.a}))
            {
            }

            ~RayImage()
            {
                if (isImageReady()) {
                    unloadImage();
                }
            }

            bool isImageReady()
            {
                return IsImageReady(_image);
            }

            void unloadImage()
            {
                if (isImageReady()) {
                    UnloadImage(_image);
                }
            }

            int getWidth() const
            {
                return _image.width;
            }

            int getHeight() const
            {
                return _image.height;
            }

            int getMipmaps() const
            {
                return _image.mipmaps;
            }

            int getFormat() const
            {
                return _image.format;
            }

            void setData(RayImage image)
            {
                _image.data = image._image.data;
            }

            static void setExternData(::Image &extern_, RayImage image)
            {
                extern_.data = image._image.data;
            }
        private:
            ::Image _image;
    };

    class Sprite {
        public:
            Sprite(const std::string &fileName, float width, float height, std::size_t id)
                : _texture(LoadTexture(fileName.c_str())),
                  _width(width),
                  _height(height)
            {
                if (!IsTextureReady(_texture)) {
                    static const ::Color badTexture   = {255, 16, 240, 255};
                    static constexpr int badImageSize = 50;
                    _texture = LoadTextureFromImage(GenImageColor(badImageSize, badImageSize, badTexture));
                }
                Registry::getInstance().setToDefaultLayer(id);
            }

            Sprite(RayImage image, float width, float height) : _texture(), _width(width), _height(height)
            {
                loadTextureFromImage(image);
            }

            void unloadSprite()
            {
                UnloadTexture(_texture);
            }

            unsigned int getId() const
            {
                return _texture.id;
            }

            float getWidth() const
            {
                return _width;
            }

            float getHeight() const
            {
                return _height;
            }

            int getTextureWidth() const
            {
                return _texture.width;
            }

            int getTextureHeight() const
            {
                return _texture.height;
            }

            int getMipmaps() const
            {
                return _texture.mipmaps;
            }

            int getFormat() const
            {
                return _texture.format;
            }

            // draw texture functions

            void draw(int posX, int posY, Color tint)
            {
                ::Color tnt = {tint.r, tint.g, tint.b, tint.a};

                DrawTexture(_texture, posX, posY, tnt);
            }

            void drawV(Vector2 position, Color tint)
            {
                ::Vector2 pos = {position.x, position.y};
                ::Color tnt   = {tint.r, tint.g, tint.b, tint.a};

                DrawTextureV(_texture, pos, tnt);
            }

            void drawEx(Vector2 position, float rotation, float scale, Color tint)
            {
                ::Vector2 pos = {position.x, position.y};
                ::Color tnt   = {tint.r, tint.g, tint.b, tint.a};

                DrawTextureEx(_texture, pos, rotation, scale, tnt);
            }

            void drawRec(Rectangle source, Vector2 position, Color tint)
            {
                ::Rectangle src = {source.x, source.y, source.width, source.height};
                ::Vector2 pos   = {position.x, position.y};
                ::Color tnt     = {tint.r, tint.g, tint.b, tint.a};

                DrawTextureRec(_texture, src, pos, tnt);
            }

            void drawPro(Rectangle source, Rectangle dest, Vector2 origin, float rotation, Color tint)
            {
                ::Rectangle src = {source.x, source.y, source.width, source.height};
                ::Rectangle dst = {dest.x, dest.y, dest.width, dest.height};
                ::Vector2 org   = {origin.x, origin.y};
                ::Color tnt     = {tint.r, tint.g, tint.b, tint.a};

                DrawTexturePro(_texture, src, dst, org, rotation, tnt);
            }

        private:
            void loadTextureFromImage(RayImage image)
            {
                ::Image img;
                RayImage::setExternData(img, image);
                img.width   = image.getWidth();
                img.height  = image.getHeight();
                img.mipmaps = image.getMipmaps();
                img.format  = image.getFormat();
                _texture    = LoadTextureFromImage(img);
            }
            ::Texture2D _texture;
            // width and height in percentage of the screen
            float _width;
            float _height;
    };


    // Text functions and classes

    class Text {
        public:

            static void drawText(std::string text, int posX, int posY, int fontSize, Color color)
            {
                ::Color textColor = {color.r, color.g, color.b, color.a};

                DrawText(text.c_str(), posX, posY, fontSize, textColor);
            }

            static int measureText(const std::string text, int fontSize)
            {
                return MeasureText(text.c_str(), fontSize);
            }

            Text(std::string text, Vector2 position, float fontSize, Color color)
                : _text(std::move(text)),
                  _fontSize(fontSize),
                  _currentFontSize(fontSize),
                  _color(color),
                  _position(position),
                  _pixelPosition(position)
            {
            }

            void draw()
            {
                ::Color textColor = {_color.r, _color.g, _color.b, _color.a};

                DrawText(
                    _text.c_str(),
                    static_cast<int>(_pixelPosition.x),
                    static_cast<int>(_pixelPosition.y),
                    static_cast<int>(_currentFontSize),
                    textColor);
            }

            void drawEx(float spacing)
            {
                ::Color textColor = {_color.r, _color.g, _color.b, _color.a};
                ::Vector2 pos     = {_pixelPosition.x, _pixelPosition.y};

                DrawTextEx(GetFontDefault(), _text.c_str(), pos, _currentFontSize, spacing, textColor);
            }

            void drawPro(Vector2 origin, float rotation, float spacing)
            {
                ::Vector2 textOrigin = {origin.x, origin.y};
                ::Vector2 pos        = {_pixelPosition.x, _pixelPosition.y};
                ::Color textColor    = {_color.r, _color.g, _color.b, _color.a};

                DrawTextPro(
                    GetFontDefault(),
                    _text.c_str(),
                    pos,
                    textOrigin,
                    rotation,
                    _currentFontSize,
                    spacing,
                    textColor);
            }


            float x() const
            {
                return _position.x;
            }

            float y() const
            {
                return _position.y;
            }

            float getFontSize() const
            {
                return _fontSize;
            }

            void setFontSize(float fontSize)
            {
                _fontSize = fontSize;
            }

            Vector2 getPosition() const
            {
                return _position;
            }

            void setPixelPosition(Vector2 position)
            {
                _pixelPosition = position;
            }

            void setColor(Color color)
            {
                _color = color;
            }

            Color getColor() const
            {
                return _color;
            }

            void setCurrentFontSize(float fontSize)
            {
                _currentFontSize = fontSize;
            }

        private:
            std::string _text;
            float _fontSize;
            float _currentFontSize;
            Color _color;
            Vector2 _position;
            Vector2 _pixelPosition;
    };
} // namespace Raylib
