/*
** EPITECH PROJECT, 2023
** R-Bus
** File description:
** Audio
*/

#pragma once

#include <memory>
#include <string>
#include "Audio.hpp"
#include "RaylibImpl/Audio/Audio.hpp"
extern "C" {
#include "raylib.h"
}

namespace Raylib {
    // Audio device management functions
            void Audio::initAudioDevice()
            {
                InitAudioDevice();
            }
            void Audio::closeAudioDevice()
            {
                CloseAudioDevice();
            }
            bool Audio::isAudioDeviceReady()
            {
                return IsAudioDeviceReady();
            }
            void Audio::setMasterVolume(float volume)
            {
                SetMasterVolume(volume);
            }

            std::unique_ptr<Sound> Sound::fromFile(const std::string& fileName, float volume)
    {
        return std::make_unique(SoundImpl(fileName, volume));
    }

    std::unique_ptr<Music> Music::fromFile(const std::string& fileName, float volume)
    {
        return std::make_unique(MusicImpl(fileName, volume));
    }
}
