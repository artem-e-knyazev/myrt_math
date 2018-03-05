#include <iostream>

#include "test/assert.hpp"
#include "test/tester.hpp"

#include "scenarios/vec4.hpp"

int main() {
    add_vec4_scenarios();

    return TESTER->run();
}

