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
            SoundImpl::SoundImpl(const std::string& fileName, float volume)
                : _path(fileName),
                  _sound(LoadSound(_path.c_str()))
            {
                SetSoundVolume(_sound, volume);
            }

            bool SoundImpl::isReady() const override
            {
                return IsSoundReady(_sound);
            }

            void SoundImpl::unload() override
            {
                UnloadSound(_sound);
            }

            void SoundImpl::play() const override
            {
                PlaySound(_sound);
            }

            void SoundImpl::stop() const override
            {
                StopSound(_sound);
            }

            void SoundImpl::pause() const override
            {
                PauseSound(_sound);
            }

            void SoundImpl::resume() const override
            {
                ResumeSound(_sound);
            }

            bool SoundImpl::isPlaying() const override
            {
                return IsSoundPlaying(_sound);
            }

            void SoundImpl::setVolume(float volume) const override
            {
                SetSoundVolume(_sound, volume);
            }

            void SoundImpl::setPitch(float pitch) const override
            {
                SetSoundPitch(_sound, pitch);
            }

            void SoundImpl::setPan(float pan) const override
            {
                SetSoundPitch(_sound, pan);
            }

            bool SoundImpl::NeedToPlay() const override
            {
                return _needToPlay;
            }

            void SoundImpl::setNeedToPlay(bool needToPlay) override
            {
                _needToPlay = needToPlay;
            }

            const std::string &SoundImpl::getPath() const override
            {
                return _path;
            }

            MusicImpl::MusicImpl(const std::string& fileName, float volume)
                : _path(fileName),
                  _music(LoadMusicStream(_path.c_str()))
            {
                SetMusicVolume(_music, volume);
            }

            void MusicImpl::unload() override
            {
                UnloadMusicStream(_music);
            }

            bool MusicImpl::isReady() const override
            {
                return IsMusicReady(_music);
            }

            void MusicImpl::play() const override
            {
                PlayMusicStream(_music);
            }

            bool MusicImpl::isPlaying() const override
            {
                return IsMusicStreamPlaying(_music);
            }

            void MusicImpl::update() const override
            {
                UpdateMusicStream(_music);
            }

            void MusicImpl::stop() const override
            {
                StopMusicStream(_music);
            }

            void MusicImpl::pause() const override
            {
                PauseMusicStream(_music);
            }

            void MusicImpl::resume() const override
            {
                ResumeMusicStream(_music);
            }

            void MusicImpl::setVolume(float volume) const override
            {
                SetMusicVolume(_music, volume);
            }

            void MusicImpl::setPitch(float pitch) const override
            {
                SetMusicPitch(_music, pitch);
            }

            void MusicImpl::setPan(float pan) const override
            {
                SetMusicPitch(_music, pan);
            }

            float MusicImpl::getTimeLength() const override
            {
                return GetMusicTimeLength(_music);
            }

            float MusicImpl::getTimePlayed() const override
            {
                return GetMusicTimePlayed(_music);
            }

            bool MusicImpl::NeedToPlay() const override
            {
                return _needToPlay;
            }

            void MusicImpl::setNeedToPlay(bool needToPlay) override
            {
                _needToPlay = needToPlay;
            }

            const std::string &MusicImpl::getPath() const override
            {
                return _path;
            }
} // namespace Raylib
