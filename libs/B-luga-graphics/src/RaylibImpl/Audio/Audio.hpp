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
            SoundImpl(const std::string& fileName, float volume);

            ~SoundImpl();

            bool isReady() const override;

            void unload() override;

            void play() const override;

            void stop() const override;

            void pause() const override;

            void resume() const override;

            bool isPlaying() const override;

            void setVolume(float volume) const override;

            void setPitch(float pitch) const override;

            void setPan(float pan) const override;

            bool NeedToPlay() const override;

            void setNeedToPlay(bool needToPlay) override;

            const std::string &getPath() const override;

        private:
            std::string _path;
            ::Sound _sound;
            bool _needToPlay {false};
    };

    class MusicImpl : public Music {
        public:
            MusicImpl(const std::string& fileName, float volume);

            ~MusicImpl();

            void unload() override;

            bool isReady() const override;

            void play() const override;

            bool isPlaying() const override;

            void update() const override;

            void stop() const override;

            void pause() const override;

            void resume() const override;

            void setVolume(float volume) const override;

            void setPitch(float pitch) const override;

            void setPan(float pan) const override;

            float getTimeLength() const override;

            float getTimePlayed() const override;

            bool NeedToPlay() const override;

            void setNeedToPlay(bool needToPlay) override;

            const std::string &getPath() const override;

        private:
            std::string _path;
            ::Music _music;
            bool _needToPlay {false};
    };
} // namespace Raylib
