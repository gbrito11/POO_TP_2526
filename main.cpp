#include <ctime>
#include <iostream>
#include "Jardim/Jardim.h"
#include "Sim.h"

int main() {
    std::srand(std::time(nullptr));
    Sim sim;
    sim.run();

}