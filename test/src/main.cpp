#include "B-luga/Clock.hpp"
#include "B-luga/Logger.hpp"

int main() {
    Clock clock;
    clock.create();
    Logger::debug("bite");
}
