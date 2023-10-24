#pragma once
#include <iostream>
namespace ECS {
    class ABC {
        public:
            static void test() {
                std::cout << "ABC" << std::endl;
            }
    };
}
