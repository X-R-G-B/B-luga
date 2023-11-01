/*
** EPITECH PROJECT, 2023
** R-Bus
** File description:
** Raylib
*/

#pragma once

#include <memory>
#include "B-luga-graphics/Raylib/Audio/Audio.hpp"
#include "B-luga-graphics/Raylib/Geometry/Geometry.hpp"
#include "B-luga-graphics/Raylib/Graphics/Graphics.hpp"
#include "B-luga-graphics/Raylib/Events/Inputs.hpp"

namespace Raylib {
    using SoundShared = std::shared_ptr<Sound>;
    using MusicShared = std::shared_ptr<Music>;
    using SpriteShared = std::shared_ptr<Sprite>;
    using RayImageShared = std::shared_ptr<RayImage>;
    using TextShared = std::shared_ptr<Text>;
}
