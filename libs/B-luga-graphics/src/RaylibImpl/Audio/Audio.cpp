/*
** EPITECH PROJECT, 2023
** R-Bus
** File description:
** Audio
*/

#include <string>
extern "C"
{
#include "raylib.h"
}
#include "B-luga-graphics/Raylib/Audio/Audio.hpp"
#include "Audio.hpp"

namespace Raylib {
    // Sounds
            SoundImpl::SoundImpl(const std::string& fileName, float volume)
                : _path(fileName),
                  _sound(LoadSound(_path.c_str()))
            {
                SetSoundVolume(_sound, volume);
            }

            bool SoundImpl::isReady() const
            {
                return IsSoundReady(_sound);
            }

            void SoundImpl::unload()
            {
                UnloadSound(_sound);
            }

            void SoundImpl::play() const
            {
                PlaySound(_sound);
            }

            void SoundImpl::stop() const
            {
                StopSound(_sound);
            }

            void SoundImpl::pause() const
            {
                PauseSound(_sound);
            }

            void SoundImpl::resume() const
            {
                ResumeSound(_sound);
            }

            bool SoundImpl::isPlaying() const
            {
                return IsSoundPlaying(_sound);
            }

            void SoundImpl::setVolume(float volume) const
            {
                SetSoundVolume(_sound, volume);
            }

            void SoundImpl::setPitch(float pitch) const
            {
                SetSoundPitch(_sound, pitch);
            }

            void SoundImpl::setPan(float pan) const
            {
                SetSoundPitch(_sound, pan);
            }

            bool SoundImpl::NeedToPlay() const
            {
                return _needToPlay;
            }

            void SoundImpl::setNeedToPlay(bool needToPlay)
            {
                _needToPlay = needToPlay;
            }

            const std::string &SoundImpl::getPath() const
            {
                return _path;
            }

            MusicImpl::MusicImpl(const std::string& fileName, float volume)
                : _path(fileName),
                  _music(LoadMusicStream(_path.c_str()))
            {
                SetMusicVolume(_music, volume);
            }

            void MusicImpl::unload()
            {
                UnloadMusicStream(_music);
            }

            bool MusicImpl::isReady() const
            {
                return IsMusicReady(_music);
            }

            void MusicImpl::play() const
            {
                PlayMusicStream(_music);
            }

            bool MusicImpl::isPlaying() const
            {
                return IsMusicStreamPlaying(_music);
            }

            void MusicImpl::update() const
            {
                UpdateMusicStream(_music);
            }

            void MusicImpl::stop() const
            {
                StopMusicStream(_music);
            }

            void MusicImpl::pause() const
            {
                PauseMusicStream(_music);
            }

            void MusicImpl::resume() const
            {
                ResumeMusicStream(_music);
            }

            void MusicImpl::setVolume(float volume) const
            {
                SetMusicVolume(_music, volume);
            }

            void MusicImpl::setPitch(float pitch) const
            {
                SetMusicPitch(_music, pitch);
            }

            void MusicImpl::setPan(float pan) const
            {
                SetMusicPitch(_music, pan);
            }

            float MusicImpl::getTimeLength() const
            {
                return GetMusicTimeLength(_music);
            }

            float MusicImpl::getTimePlayed() const
            {
                return GetMusicTimePlayed(_music);
            }

            bool MusicImpl::NeedToPlay() const
            {
                return _needToPlay;
            }

            void MusicImpl::setNeedToPlay(bool needToPlay)
            {
                _needToPlay = needToPlay;
            }

            const std::string &MusicImpl::getPath() const
            {
                return _path;
            }

            SoundImpl::~SoundImpl()
            {
                if (isReady()) {
                    unload();
                }
            }

            MusicImpl::~MusicImpl()
            {
                if (isReady()) {
                    unload();
                }
            }
} // namespace Raylib
