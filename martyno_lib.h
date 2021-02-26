#ifndef MARTYNO_LIB_H
#define MARTYNO_LIB_H

//bibliotekų įtraukimas
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip> 
#include <random>
#include <fstream>
#include <sys/stat.h>
#include <chrono>

//dėl lengvesnės sintaksės
using std::cout;
using std::cin;
using std::endl;
using std::setw;
using std::string;
using std::vector;
using std::ifstream;
using std::ofstream;
using std::left;
using std::right;
using std::setprecision;


//Klasė skirta generuoti sveikuosius skaičius
class RandomInt{
    public:
        RandomInt() : mt{rd()} {}
        int rnd(int low, int high)
        {
            std::uniform_int_distribution<int> dist(low, high);
            return dist(mt);
        }
    private:
        std::random_device rd;
        std::mt19937 mt;
};

#endif