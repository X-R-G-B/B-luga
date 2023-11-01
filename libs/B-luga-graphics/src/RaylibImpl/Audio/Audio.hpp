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
            Sound(const std::string& fileName, float volume)
                : _path(fileName),
                  _sound(LoadSound(_path.c_str()))
            {
                SetSoundVolume(_sound, volume);
            }

            bool isReady() const override
            {
                return IsSoundReady(_sound);
            }

            void unload() override
            {
                UnloadSound(_sound);
            }

            void play() const override
            {
                PlaySound(_sound);
            }

            void stop() const override
            {
                StopSound(_sound);
            }

            void pause() const override
            {
                PauseSound(_sound);
            }

            void resume() const override
            {
                ResumeSound(_sound);
            }

            bool isPlaying() const override
            {
                return IsSoundPlaying(_sound);
            }

            void setVolume(float volume) const override
            {
                SetSoundVolume(_sound, volume);
            }

            void setPitch(float pitch) const override
            {
                SetSoundPitch(_sound, pitch);
            }

            void setPan(float pan) const override
            {
                SetSoundPitch(_sound, pan);
            }

            bool NeedToPlay() const override
            {
                return _needToPlay;
            }

            void setNeedToPlay(bool needToPlay) override
            {
                _needToPlay = needToPlay;
            }

            const std::string &getPath() const override
            {
                return _path;
            }

        private:
            std::string _path;
            ::Sound _sound;
            bool _needToPlay {false};
    };

    class MusicImpl : public Music {
        public:
            Music(const std::string& fileName, float volume)
                : _path(fileName),
                  _music(LoadMusicStream(_path.c_str()))
            {
                SetMusicVolume(_music, volume);
            }

            void unload() override
            {
                UnloadMusicStream(_music);
            }

            bool isReady() const override
            {
                return IsMusicReady(_music);
            }

            void play() const override
            {
                PlayMusicStream(_music);
            }

            bool isPlaying() const override
            {
                return IsMusicStreamPlaying(_music);
            }

            void update() const override
            {
                UpdateMusicStream(_music);
            }

            void stop() const override
            {
                StopMusicStream(_music);
            }

            void pause() const override
            {
                PauseMusicStream(_music);
            }

            void resume() const override
            {
                ResumeMusicStream(_music);
            }

            void setVolume(float volume) const override
            {
                SetMusicVolume(_music, volume);
            }

            void setPitch(float pitch) const override
            {
                SetMusicPitch(_music, pitch);
            }

            void setPan(float pan) const override
            {
                SetMusicPitch(_music, pan);
            }

            float getTimeLength() const override
            {
                return GetMusicTimeLength(_music);
            }

            float getTimePlayed() const override
            {
                return GetMusicTimePlayed(_music);
            }

            bool NeedToPlay() const override
            {
                return _needToPlay;
            }

            void setNeedToPlay(bool needToPlay) override
            {
                _needToPlay = needToPlay;
            }

            const std::string &getPath() const override
            {
                return _path;
            }

        private:
            std::string _path;
            ::Music _music;
            bool _needToPlay {false};
    };
} // namespace Raylib
