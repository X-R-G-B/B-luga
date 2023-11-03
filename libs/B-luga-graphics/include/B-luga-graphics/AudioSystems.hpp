/*
** EPITECH PROJECT, 2023
** R-Bus
** File description:
** AudioSystems
*/

#pragma once

#include <functional>
#include <mutex>
#include <vector>
#include "B-luga-graphics/GraphicsCustomTypes.hpp"
#include "B-luga/Registry.hpp"
#include "B-luga/SystemManagers/SystemManagersDirector.hpp"
#include "B-luga/IPlugin.hpp"

namespace Systems {
    namespace GraphicsSystems {

        class AudioSystems {
            public:
                static void soundEffectPlayer(std::size_t /*unused*/, std::size_t /*unused*/)
                {
                    std::lock_guard<std::mutex> lock(Registry::getInstance().mutex);
                    Registry::components<Raylib::SoundShared> arrSoundEffect =
                        Registry::getInstance().getComponents<Raylib::SoundShared>();

                    for (auto &soundEffect : arrSoundEffect) {
                        if (soundEffect->NeedToPlay() && !soundEffect->isPlaying()) {
                            soundEffect->play();
                            soundEffect->setNeedToPlay(false);
                        }
                    }
                }
                static void musicPlayer(std::size_t /*unused*/, std::size_t /*unused*/)
                {
                    std::lock_guard<std::mutex> lock(Registry::getInstance().mutex);
                    Registry::components<Raylib::MusicShared> arrMusics =
                        Registry::getInstance().getComponents<Raylib::MusicShared>();

                    for (auto &music : arrMusics) {
                        if (music->NeedToPlay()) {
                            music->play();
                            music->setNeedToPlay(false);
                        }
                        if (music->isPlaying()) {
                            music->update();
                        }
                    }
                }
                static std::vector<std::function<void(std::size_t, std::size_t)>> getAudioSystems()
                {
                    return { soundEffectPlayer, musicPlayer };
                }
        };
    } // namespace GraphicsSystems
} // namespace Systems
