/*
** EPITECH PROJECT, 2023
** R-Bus
** File description:
** GraphicSystems
*/

#pragma once

#include "B-luga-graphics/Raylib/UnloadRaylib.hpp"
#include "B-luga-graphics/AudioSystems.hpp"
#include "B-luga-graphics/GraphicsCustomTypes.hpp"
#include "B-luga-graphics/ParallaxSystems.hpp"
#include "B-luga/Maths/Maths.hpp"
#include "B-luga/Registry.hpp"
#include "B-luga-graphics/SpriteSystems.hpp"
#include "B-luga-graphics/TextSystems.hpp"
#include "B-luga/SceneManager.hpp"
#include "B-luga/IPlugin.hpp"

namespace Systems::GraphicsSystems {


    static constexpr int screenWidth  = 1920;
    static constexpr int screenHeight = 1080;


    class GraphicsPlugin : public IPlugin
    {
        public:
            static void startLoopRaylib(std::size_t /*unused*/)
            {
                Raylib::Drawing::beginDrawing();
                Raylib::Drawing::clearBackground(Raylib::DarkGray);
            }

            static void beforeLoopRaylib(std::size_t /*unused*/)
            {
                Raylib::Window::initWindow(screenWidth, screenHeight, "R-Bus");
                Raylib::Window::setWindowState(Raylib::ConfigFlags::WINDOW_RESIZABLE);
                Raylib::Frame::setTargetFPS(Raylib::Window::getMonitorRefreshRate(Raylib::Window::getCurrentMonitor()));
                Raylib::Audio::initAudioDevice();
            }

            static void endLoopRaylib(std::size_t /*unused*/)
            {
                Raylib::Drawing::endDrawing();
            }

            static void afterLoopRaylib(std::size_t /*unused*/)
            {
                Raylib::Audio::closeAudioDevice();
                Raylib::Window::closeWindow();
                Raylib::TextureManager::getInstance().unloadTextures();
            }

            static void checkRaylibStop(std::size_t /*unused*/, std::size_t /*unused*/)
            {
                if (Raylib::Window::windowShouldClose()) {
                    Scene::SceneManager::getInstance().stop();
                }
            }
            void initPlugin() override
            {
                std::lock_guard<std::mutex> lock(Registry::getInstance().mutex);
                Registry::getInstance().addEventCallback(Events::REMOVE_ENTITY, UnloadRaylib::unloadRaylibComponents);
                Registry::getInstance().addEventCallback(Events::CLEAR, UnloadRaylib::unloadRaylibComponents);
                Registry::getInstance().addEventCallback(Events::START_LOOP, startLoopRaylib);
                Registry::getInstance().addEventCallback(Events::END_LOOP, endLoopRaylib);
                Registry::getInstance().addEventCallback(Events::BEFORE_LOOP, beforeLoopRaylib);
                Registry::getInstance().addEventCallback(Events::AFTER_LOOP, afterLoopRaylib);
            }
            std::vector<std::function<void(std::size_t, std::size_t)>> getSystems() override
            {
                std::vector<std::function<void(std::size_t, std::size_t)>> graphicsSystems = {
                    checkRaylibStop
                };
                std::vector<std::function<void(std::size_t, std::size_t)>> audioSystems  = AudioSystems::getAudioSystems();
                std::vector<std::function<void(std::size_t, std::size_t)>> spriteSystems = SpriteSystems::getSpriteSystems();
                std::vector<std::function<void(std::size_t, std::size_t)>> textSystems   = TextSystems::getTextSystems();
                std::vector<std::function<void(std::size_t, std::size_t)>> parallaxSystems =
                    ParallaxSystems::getParallaxSystems();

                graphicsSystems.insert(graphicsSystems.end(), audioSystems.begin(), audioSystems.end());
                //graphicsSystems.insert(graphicsSystems.end(), spriteSystems.begin(), spriteSystems.end());
                graphicsSystems.insert(graphicsSystems.end(), textSystems.begin(), textSystems.end());
                //graphicsSystems.insert(graphicsSystems.end(), parallaxSystems.begin(), parallaxSystems.end());
                return graphicsSystems;
            }
    };
} // namespace Systems
