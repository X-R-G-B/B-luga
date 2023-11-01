/*
** EPITECH PROJECT, 2023
** R-Bus
** File description:
** Audio
*/

#pragma once

#include <string>
extern "C"
{
#include "raylib.h"
}
#include "B-luga-graphics/Raylib/Audio/Audio.hpp"

namespace Raylib {
    // Sounds
    class SoundImpl : public Sound {
        public:
            SoundImpl(const std::string& fileName, float volume)

            bool isReady() const ovveride;

            void unload() ovveride;

            void play() const ovveride;

            void stop() const ovveride;

            void pause() const ovveride;

            void resume() const ovveride;

            bool isPlaying() const ovveride;

            void setVolume(float volume) const ovveride;

            void setPitch(float pitch) const ovveride;

            void setPan(float pan) const ovveride;

            bool NeedToPlay() const ovveride;

            void setNeedToPlay(bool needToPlay) ovveride;

            const std::string &getPath() const ovveride;

        private:
            std::string _path;
            ::Sound _sound;
            bool _needToPlay {false};
    };

    class MusicImpl : public Music {
        public:
            MusicImpl(const std::string& fileName, float volume)

            void unload() ovveride;

            bool isReady() const ovveride;

            void play() const ovveride;

            bool isPlaying() const ovveride;

            void update() const ovveride;

            void stop() const ovveride;

            void pause() const ovveride;

            void resume() const ovveride;

            void setVolume(float volume) const ovveride;

            void setPitch(float pitch) const ovveride;

            void setPan(float pan) const ovveride;

            float getTimeLength() const ovveride;

            float getTimePlayed() const ovveride;

            bool NeedToPlay() const ovveride;

            void setNeedToPlay(bool needToPlay) ovveride;

            const std::string &getPath() const ovveride;

        private:
            std::string _path;
            ::Music _music;
            bool _needToPlay {false};
    };
} // namespace Raylib
