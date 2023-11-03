/*
** EPITECH PROJECT, 2023
** R-Bus
** File description:
** Audio
*/

#pragma once

#include <string>
#include <memory>

namespace Raylib {
    // Audio device management functions
    class Audio {
        public:
            static void initAudioDevice();
            static void closeAudioDevice();
            static bool isAudioDeviceReady();
            static void setMasterVolume(float volume);
    };

    // Sounds
    class Sound {
        public:
            static std::shared_ptr<Sound> fromFile(const std::string &fileName, float volume);

            virtual ~Sound() = default;

            [[nodiscard]] virtual bool isReady() const = 0;

            virtual void unload() = 0;

            virtual void play() const = 0;

            virtual void stop() const = 0;

            virtual void pause() const = 0;

            virtual void resume() const = 0;

            [[nodiscard]] virtual bool isPlaying() const = 0;

            virtual void setVolume(float volume) const = 0;

            virtual void setPitch(float pitch) const = 0;

            virtual void setPan(float pan) const = 0;

            [[nodiscard]] virtual bool NeedToPlay() const = 0;

            virtual void setNeedToPlay(bool needToPlay) = 0;

            [[nodiscard]] virtual const std::string &getPath() const = 0;
    };

    class Music {
        public:
            static std::shared_ptr<Music> fromFile(const std::string &fileName, float volume);

            virtual ~Music() = default;

            virtual void unload() = 0;

            virtual bool isReady() const = 0;

            virtual void play() const = 0;

            virtual bool isPlaying() const = 0;

            virtual void update() const = 0;

            virtual void stop() const = 0;

            virtual void pause() const = 0;

            virtual void resume() const = 0;

            virtual void setVolume(float volume) const = 0;

            virtual void setPitch(float pitch) const = 0;

            virtual void setPan(float pan) const = 0;

            virtual float getTimeLength() const = 0;

            virtual float getTimePlayed() const = 0;

            virtual bool NeedToPlay() const = 0;

            virtual void setNeedToPlay(bool needToPlay) = 0;

            virtual const std::string &getPath() const = 0;
    };
} // namespace Raylib
