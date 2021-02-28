#ifndef RANDOM_GENERATOR_H
#define RANDOM_GENERATOR_H

#include <random>

// Čia yra klasė skirta generuoti atsitiktinius skaičius
////////////////////////////////////////////////////////

class RandomInt{
    private:
        std::random_device rd;
        std::mt19937 mt;
    public:
        RandomInt();
        int rnd(int low, int high);
};

#endif
