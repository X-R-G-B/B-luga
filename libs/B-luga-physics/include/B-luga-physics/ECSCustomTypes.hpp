/*
** EPITECH PROJECT, 2023
** R-Bus
** File description:
** Custom Types
*/

#pragma once

#include <cstddef>
#include <functional>
#include <optional>
#include <any>
#include <vector>
#include "B-luga/Json.hpp"
#include "B-luga/Clock.hpp"
#include "B-luga/Registry.hpp"

// all values are in percentage of the screen
namespace Types {

    struct Health {
            Health(int hp) : hp(hp)
            {
            }

            int hp;

            NLOHMANN_DEFINE_TYPE_INTRUSIVE(Health, hp);
    };

    struct CollisionRect {
            int width;
            int height;
            int offsetX;
            int offsetY;

            NLOHMANN_DEFINE_TYPE_INTRUSIVE(CollisionRect, width, height, offsetX, offsetY);
    };

    struct Position {
            int x;
            int y;

            NLOHMANN_DEFINE_TYPE_INTRUSIVE(Position, x, y);
    };

    struct Damage {
            int damage;
    };

    struct Velocity {
            int speedX;
            int speedY;

            NLOHMANN_DEFINE_TYPE_INTRUSIVE(Velocity, speedX, speedY);
    };

    struct SpriteDatas {
            SpriteDatas(
                const std::string &fileName,
                int width,
                int height,
                enum LayerType layer,
                std::size_t layerSide)
                : fileName(fileName),
                  width(width),
                  height(height),
                  layer(layer),
                  layerSide(layerSide)
            {
            }
            std::string fileName;
            int width;
            int height;
            std::size_t id;
            enum LayerType layer;
            size_t layerSide;
    };

    enum PhysicsType {
        ZIGZAG = 0,
        BOUNCING
    };

    // These structs are used to store physics data

    struct Zigzag {
            Zigzag(const Types::Position &originPosition)
                : clockId(Registry::getInstance().getClock().create(true)),
                  originPos(originPosition)
            {
            }
            std::size_t clockId;
            Types::Position originPos;
            float period     = 400.0F;
            float amplitude  = 10.0F;
            float maxScreenY = 100.0F;
            float minScreenY = 0.0F;
    };

    struct Bouncing {
            Bouncing(const Types::Position &originPosition) : originPos(originPosition)
            {
            }
            Types::Position originPos;
    };

    class Physics {
        public:
            inline static const std::map<std::string, PhysicsType> physicsTypeMap = {
                {"bouncing", BOUNCING},
                {"zigzag",   ZIGZAG  }
            };

            Physics()
            {
            }
            void addPhysic(nlohmann::json &jsonObject, const Types::Position &originPos)
            {
                Json &json     = Json::getInstance();
                std::string id = json.getDataFromJson<std::string>(jsonObject, "id");
                if (id == "zigzag") {
                    initZigzag(jsonObject, originPos);
                }
                if (id == "bouncing") {
                    initBounce(jsonObject, originPos);
                }
            }
            std::vector<PhysicsType> getPhysics() const
            {
                std::vector<PhysicsType> physics;

                for (const auto &pair : _physicsMap) {
                    physics.push_back(pair.first);
                }
                return physics;
            }
            bool hasPhysics(PhysicsType type) const
            {
                return _physicsMap.find(type) != _physicsMap.end();
            }
            bool hasPhysics() const
            {
                return !_physicsMap.empty();
            }
            void removePhysic(PhysicsType type)
            {
                if (_physicsMap.find(type) == _physicsMap.end()) {
                    Logger::error("Physics not found");
                    return;
                }
                _physicsMap.erase(type);
            }
            void removePhysics()
            {
                _physicsMap.clear();
            }
            template <typename T>
            T &getPhysicData(PhysicsType type)
            {
                return std::any_cast<T &>(_physicsMap[type]);
            }

        private:
            void initBounce(nlohmann::json & /*unused*/, const Types::Position &originPos)
            {
                Bouncing bounce(originPos);
                _physicsMap[BOUNCING] = bounce;
            }
            void initZigzag(nlohmann::json &jsonObject, const Types::Position &originPos)
            {
                Json &json = Json::getInstance();
                Zigzag zigzag(originPos);
                if (json.isDataExist(jsonObject, "amplitude")) {
                    zigzag.amplitude = json.getDataFromJson<float>(jsonObject, "amplitude");
                }
                if (json.isDataExist(jsonObject, "period")) {
                    zigzag.period = json.getDataFromJson<float>(jsonObject, "period");
                }
                if (json.isDataExist(jsonObject, "maxScreenY")) {
                    zigzag.maxScreenY = json.getDataFromJson<float>(jsonObject, "maxScreenY");
                }
                if (json.isDataExist(jsonObject, "minScreenY")) {
                    zigzag.minScreenY = json.getDataFromJson<float>(jsonObject, "minScreenY");
                }
                _physicsMap[ZIGZAG] = zigzag;
            }
            std::unordered_map<PhysicsType, std::any> _physicsMap;
    };

    struct Dead {
            Dead(std::size_t time = 0)
                : deathFunction(std::nullopt),
                  timeToWait(time),
                  clockId(static_cast<std::size_t>(-1)),
                  launched(false) {};
            Dead(std::optional<std::function<void(std::size_t id)>> func, std::size_t time = 0)
                : deathFunction(func),
                  timeToWait(time),
                  clockId(static_cast<std::size_t>(-1)),
                  launched(false) {};
            std::optional<std::function<void(std::size_t id)>> deathFunction;
            std::size_t timeToWait;
            std::size_t clockId;
            bool launched;
    };

    struct Container {
        float minX;
        float maxX;
        float minY;
        float maxY;

        NLOHMANN_DEFINE_TYPE_INTRUSIVE(Container, minX, maxX, minY, maxY);
    };

    struct NoRemoveOutside {};

} // namespace Types
