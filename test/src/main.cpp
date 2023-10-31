#include "B-luga/Clock.hpp"
#include "B-luga/Logger.hpp"
#include "B-luga/Registry.hpp"
#include "B-luga/PluginHandler.hpp"
#include "B-luga/SceneManager.hpp"
#include "B-luga/Json.hpp"

int main() {
    Clock clock;
    clock.create();
    Logger::debug("bite");
}
