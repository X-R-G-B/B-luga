#pragma once

#include <fstream>
#include <functional>
#include <string>
#include <vector>
#include "B-luga-graphics/GraphicsCustomTypes.hpp"
#include "B-luga/Json.hpp"
#include "B-luga/Maths/Maths.hpp"
#include "B-luga/Registry.hpp"
#include "B-luga/SystemManagers/SystemManagersDirector.hpp"
#include "B-luga-physics/ECSCustomTypes.hpp"

namespace Systems::GraphicsSystems {

    static constexpr int maxOutParallaxLeft  = -100;
    static constexpr int maxOutParallaxRight = 100;



    class ParallaxSystems {
        public:
            static std::vector<std::function<void(std::size_t /* unused */, std::size_t /* unused */)>> getParallaxSystems()
            {
                return {
                    manageParallax,
                };
            }

            static void resetParallaxPosition(
                std::size_t id,
                Registry::components<Types::Parallax> &arrParallax,
                Registry::components<Types::Position> &arrPosition)
            {
                if (Maths::intToFloatConservingDecimals(arrPosition[id].x) <= maxOutParallaxLeft) {
                    Maths::addNormalIntToDecimalInt(arrPosition[id].x, maxOutParallaxRight * 2);
                    arrPosition[id].y = Maths::floatToIntConservingDecimals(arrParallax[id].y);
                }
            }

            static void manageParallax(std::size_t /*unused*/, std::size_t /*unused*/)
            {
                std::lock_guard<std::mutex> lock(Registry::getInstance().mutex);
                Registry::components<Types::Position> arrPosition =
                    Registry::getInstance().getComponents<Types::Position>();
                Registry::components<Types::Parallax> arrParallax =
                    Registry::getInstance().getComponents<Types::Parallax>();

                std::vector<std::size_t> ids = Registry::getInstance().getEntitiesByComponents(
                    {typeid(Types::Position), typeid(Types::Parallax), typeid(Types::Velocity)});

                for (auto &id : ids) {
                    resetParallaxPosition(id, arrParallax, arrPosition);
                }
            }
    };
}
