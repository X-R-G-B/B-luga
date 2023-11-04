#include "Graphics.hpp"
#include <mutex>

namespace Raylib {

            ::Texture2D &TextureManagerImpl::getTexture(const std::string &fileName)
            {
                std::lock_guard<std::mutex> lock(_mutex);
                auto it = _textures.find(fileName);

                if (it == _textures.end()) {
                    _textures[fileName] = LoadTexture(fileName.c_str());
                }
                return _textures[fileName];
            }

            void TextureManagerImpl::unloadTextures()
        {
                std::lock_guard<std::mutex> lock(_mutex);
                for (auto &it : _textures) {
                UnloadTexture(it.second);
                }
                _textures.clear();
        }

            RayImageImpl::RayImageImpl(const std::string &fileName)
                : _image(LoadImage(fileName.c_str()))
            {
                if (!isImageReady()) {
                    const ::Color badTexture          = {255, 16, 240, 255};
                    static constexpr int badImageSize = 50;
                    _image                            = GenImageColor(badImageSize, badImageSize, badTexture);
                }
            }

            RayImageImpl::RayImageImpl(int width, int height, Raylib::Color color)
                : _image(GenImageColor(width, height, {color.r, color.g, color.b, color.a}))
            {
            }

            RayImageImpl::~RayImageImpl()
            {
                if (isImageReady()) {
                    unloadImage();
                }
            }

            bool RayImageImpl::isImageReady()
            {
                return IsImageReady(_image);
            }

            void RayImageImpl::unloadImage()
            {
                if (isImageReady()) {
                    UnloadImage(_image);
                }
            }

            int RayImageImpl::getWidth() const
            {
                return _image.width;
            }

            int RayImageImpl::getHeight() const
            {
                return _image.height;
            }

            int RayImageImpl::getMipmaps() const
            {
                return _image.mipmaps;
            }

            int RayImageImpl::getFormat() const
            {
                return _image.format;
            }

            void *RayImageImpl::getData()
            {
                return _image.data;
            }

            TextureManagerImpl &TextureManagerImpl::getInstance()
        {
            static TextureManagerImpl instance;
            return instance;
        }

            SpriteImpl::SpriteImpl(const std::string &fileName, float width, float height, std::size_t id)
                : _texture(TextureManagerImpl::getInstance().getTexture(fileName)),
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

            SpriteImpl::SpriteImpl(std::unique_ptr<RayImage> image, float width, float height) : _texture(), _width(width), _height(height)
            {
                loadTextureFromImage(std::move(image));
            }

            unsigned int SpriteImpl::getId() const
            {
                return _texture.id;
            }

            float SpriteImpl::getWidth() const
            {
                return _width;
            }

            float SpriteImpl::getHeight() const
            {
                return _height;
            }

            int SpriteImpl::getTextureWidth() const
            {
                return _texture.width;
            }

            int SpriteImpl::getTextureHeight() const
            {
                return _texture.height;
            }

            int SpriteImpl::getMipmaps() const
            {
                return _texture.mipmaps;
            }

            int SpriteImpl::getFormat() const
            {
                return _texture.format;
            }

            // draw texture functions

            void SpriteImpl::draw(int posX, int posY, Raylib::Color tint)
            {
                ::Color tnt = {tint.r, tint.g, tint.b, tint.a};

                DrawTexture(_texture, posX, posY, tnt);
            }

            void SpriteImpl::drawV(Vector2 position, Raylib::Color tint)
            {
                ::Vector2 pos = {position.x, position.y};
                ::Color tnt   = {tint.r, tint.g, tint.b, tint.a};

                DrawTextureV(_texture, pos, tnt);
            }

            void SpriteImpl::drawEx(Vector2 position, float rotation, float scale, Raylib::Color tint)
            {
                ::Vector2 pos = {position.x, position.y};
                ::Color tnt   = {tint.r, tint.g, tint.b, tint.a};

                DrawTextureEx(_texture, pos, rotation, scale, tnt);
            }

            void SpriteImpl::drawRec(Rectangle source, Vector2 position, Raylib::Color tint)
            {
                ::Rectangle src = {source.x, source.y, source.width, source.height};
                ::Vector2 pos   = {position.x, position.y};
                ::Color tnt     = {tint.r, tint.g, tint.b, tint.a};

                DrawTextureRec(_texture, src, pos, tnt);
            }

            void SpriteImpl::drawPro(Rectangle source, Rectangle dest, Vector2 origin, float rotation, Raylib::Color tint)
            {
                ::Rectangle src = {source.x, source.y, source.width, source.height};
                ::Rectangle dst = {dest.x, dest.y, dest.width, dest.height};
                ::Vector2 org   = {origin.x, origin.y};
                ::Color tnt     = {tint.r, tint.g, tint.b, tint.a};

                DrawTexturePro(_texture, src, dst, org, rotation, tnt);
            }

            void SpriteImpl::loadTextureFromImage(std::unique_ptr<RayImage> image)
            {
                _imageUnique = std::move(image);
                ::Image img;
                img.width   = _imageUnique->getWidth();
                img.height  = _imageUnique->getHeight();
                img.mipmaps = _imageUnique->getMipmaps();
                img.format  = _imageUnique->getFormat();
                img.data    = _imageUnique->getData();
                _texture    = LoadTextureFromImage(img);
            }


    // Text functions and classes

            TextImpl::TextImpl(std::string text, Vector2 position, float fontSize, Raylib::Color color)
                : _text(std::move(text)),
                  _fontSize(fontSize),
                  _color(color),
                  _position(position),
                  _pixelPosition(position)
            {
            }

            void TextImpl::draw()
            {
                ::Color textColor = {_color.r, _color.g, _color.b, _color.a};

                Logger::info("Drawing text: " + std::to_string(_fontSize));

                DrawText(
                    _text.c_str(),
                    static_cast<int>(_pixelPosition.x),
                    static_cast<int>(_pixelPosition.y),
                    static_cast<int>(_fontSize),
                    textColor);
            }

            void TextImpl::drawEx(float spacing)
            {
                ::Color textColor = {_color.r, _color.g, _color.b, _color.a};
                ::Vector2 pos     = {_pixelPosition.x, _pixelPosition.y};

                DrawTextEx(GetFontDefault(), _text.c_str(), pos, _fontSize, spacing, textColor);
            }

            void TextImpl::drawPro(Vector2 origin, float rotation, float spacing)
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
                    _fontSize,
                    spacing,
                    textColor);
            }


            float TextImpl::x() const
            {
                return _position.x;
            }

            float TextImpl::y() const
            {
                return _position.y;
            }

            float TextImpl::getFontSize() const
            {
                return _fontSize;
            }

            void TextImpl::setFontSize(float fontSize)
            {
                _fontSize = fontSize;
            }

            Vector2 TextImpl::getPosition() const
            {
                return _position;
            }

            void TextImpl::setPixelPosition(Vector2 position)
            {
                _pixelPosition = position;
            }

            void TextImpl::setColor(Raylib::Color color)
            {
                _color = color;
            }

            Raylib::Color TextImpl::getColor() const
            {
                return _color;
            }

            const std::string &TextImpl::getCurrentText() const
            {
                return (_text);
            }

            void TextImpl::setCurrentText(const std::string &text)
            {
                _text = text;
            }

} // namespace Raylib
