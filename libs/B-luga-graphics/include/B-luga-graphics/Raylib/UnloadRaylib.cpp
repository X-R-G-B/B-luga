/*
** EPITECH PROJECT, 2023
** R-Bus
** File description:
** unloadRaylib
*/

#include <cstddef>
#include "B-luga-graphics/Raylib/Raylib.hpp"
#include "B-luga/Registry.hpp"
#include "UnloadRaylib.hpp"

static void unloadSounds(std::size_t id)
{
    Registry::components<Raylib::SoundShared> arrSound = Registry::getInstance().getComponents<Raylib::SoundShared>();

    if (arrSound.exist(id)) {
        arrSound[id]->unload();
    }
}

static void unloadMusic(std::size_t id)
{
    Registry::components<Raylib::MusicShared> arrMusic = Registry::getInstance().getComponents<Raylib::MusicShared>();

    if (arrMusic.exist(id)) {
        arrMusic[id]->unload();
    }
}

static void unloadImage(std::size_t id)
{
    Registry::components<Raylib::RayImageShared> arrImage = Registry::getInstance().getComponents<Raylib::RayImageShared>();

    if (arrImage.exist(id)) {
        arrImage[id]->unloadImage();
    }
}

void UnloadRaylib::unloadRaylibComponents(std::size_t id)
        {
            unloadSounds(id);
            unloadMusic(id);
            unloadImage(id);
        }
