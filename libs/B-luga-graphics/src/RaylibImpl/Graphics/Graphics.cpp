#include "Graphics.hpp"

namespace Raylib {

            RayImage::RayImage(const std::string &fileName)
                : _image(LoadImage(fileName.c_str()))
            {
                if (!isImageReady()) {
                    const ::Color badTexture          = {255, 16, 240, 255};
                    static constexpr int badImageSize = 50;
                    _image                            = GenImageColor(badImageSize, badImageSize, badTexture);
                }
            }

            RayImage::RayImage(int width, int height, Color color)
                : _image(GenImageColor(width, height, {color.r, color.g, color.b, color.a}))
            {
            }

            RayImage::~RayImage()
            {
                if (isImageReady()) {
                    unloadImage();
                }
            }

            bool RayImage::isImageReady()
            {
                return IsImageReady(_image);
            }

            void RayImage::unloadImage()
            {
                if (isImageReady()) {
                    UnloadImage(_image);
                }
            }

            int RayImage::getWidth() const
            {
                return _image.width;
            }

            int RayImage::getHeight() const
            {
                return _image.height;
            }

            int RayImage::getMipmaps() const
            {
                return _image.mipmaps;
            }

            int RayImage::getFormat() const
            {
                return _image.format;
            }

            void RayImage::setData(RayImage image)
            {
                _image.data = image._image.data;
            }

            Sprite::Sprite(const std::string &fileName, float width, float height, std::size_t id)
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

            Sprite::Sprite(RayImage image, float width, float height) : _texture(), _width(width), _height(height)
            {
                loadTextureFromImage(image);
            }

            void Sprite::unloadSprite()
            {
                UnloadTexture(_texture);
            }

            unsigned int Sprite::getId() const
            {
                return _texture.id;
            }

            float Sprite::getWidth() const
            {
                return _width;
            }

            float Sprite::getHeight() const
            {
                return _height;
            }

            int Sprite::getTextureWidth() const
            {
                return _texture.width;
            }

            int Sprite::getTextureHeight() const
            {
                return _texture.height;
            }

            int Sprite::getMipmaps() const
            {
                return _texture.mipmaps;
            }

            int Sprite::getFormat() const
            {
                return _texture.format;
            }

            // draw texture functions

            void Sprite::draw(int posX, int posY, Color tint)
            {
                ::Color tnt = {tint.r, tint.g, tint.b, tint.a};

                DrawTexture(_texture, posX, posY, tnt);
            }

            void Sprite::drawV(Vector2 position, Color tint)
            {
                ::Vector2 pos = {position.x, position.y};
                ::Color tnt   = {tint.r, tint.g, tint.b, tint.a};

                DrawTextureV(_texture, pos, tnt);
            }

            void Sprite::drawEx(Vector2 position, float rotation, float scale, Color tint)
            {
                ::Vector2 pos = {position.x, position.y};
                ::Color tnt   = {tint.r, tint.g, tint.b, tint.a};

                DrawTextureEx(_texture, pos, rotation, scale, tnt);
            }

            void Sprite::drawRec(Rectangle source, Vector2 position, Color tint)
            {
                ::Rectangle src = {source.x, source.y, source.width, source.height};
                ::Vector2 pos   = {position.x, position.y};
                ::Color tnt     = {tint.r, tint.g, tint.b, tint.a};

                DrawTextureRec(_texture, src, pos, tnt);
            }

            void Sprite::drawPro(Rectangle source, Rectangle dest, Vector2 origin, float rotation, Color tint)
            {
                ::Rectangle src = {source.x, source.y, source.width, source.height};
                ::Rectangle dst = {dest.x, dest.y, dest.width, dest.height};
                ::Vector2 org   = {origin.x, origin.y};
                ::Color tnt     = {tint.r, tint.g, tint.b, tint.a};

                DrawTexturePro(_texture, src, dst, org, rotation, tnt);
            }

            void Sprite::loadTextureFromImage(RayImage image)
            {
                ::Image img;
                RayImage::setExternData(img, image);
                img.width   = image.getWidth();
                img.height  = image.getHeight();
                img.mipmaps = image.getMipmaps();
                img.format  = image.getFormat();
                _texture    = LoadTextureFromImage(img);
            }


    // Text functions and classes

            Text::Text(std::string text, Vector2 position, float fontSize, Color color)
                : _text(std::move(text)),
                  _fontSize(fontSize),
                  _currentFontSize(fontSize),
                  _color(color),
                  _position(position),
                  _pixelPosition(position)
            {
            }

            void Text::draw()
            {
                ::Color textColor = {_color.r, _color.g, _color.b, _color.a};

                DrawText(
                    _text.c_str(),
                    static_cast<int>(_pixelPosition.x),
                    static_cast<int>(_pixelPosition.y),
                    static_cast<int>(_currentFontSize),
                    textColor);
            }

            void Text::drawEx(float spacing)
            {
                ::Color textColor = {_color.r, _color.g, _color.b, _color.a};
                ::Vector2 pos     = {_pixelPosition.x, _pixelPosition.y};

                DrawTextEx(GetFontDefault(), _text.c_str(), pos, _currentFontSize, spacing, textColor);
            }

            void Text::drawPro(Vector2 origin, float rotation, float spacing)
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


            float Text::x() const
            {
                return _position.x;
            }

            float Text::y() const
            {
                return _position.y;
            }

            float Text::getFontSize() const
            {
                return _fontSize;
            }

            void Text::setFontSize(float fontSize)
            {
                _fontSize = fontSize;
            }

            Vector2 Text::getPosition() const
            {
                return _position;
            }

            void Text::setPixelPosition(Vector2 position)
            {
                _pixelPosition = position;
            }

            void Text::setColor(Color color)
            {
                _color = color;
            }

            Color Text::getColor() const
            {
                return _color;
            }

            void Text::setCurrentFontSize(float fontSize)
            {
                _currentFontSize = fontSize;
            }

} // namespace Raylib
