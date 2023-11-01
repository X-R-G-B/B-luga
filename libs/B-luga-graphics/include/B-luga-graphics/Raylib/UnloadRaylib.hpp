/*
** EPITECH PROJECT, 2023
** R-Bus
** File description:
** unloadRaylib
*/

#pragma once

#include <cstddef>
#include "B-luga-graphics/Raylib/Raylib.hpp"
#include "B-luga/Registry.hpp"

// NOLINTNEXTLINE(readability-convert-member-functions-to-static,-warnings-as-errors)
class UnloadRaylib {
    public:
        static void unloadRaylibComponents(std::size_t id);
};
