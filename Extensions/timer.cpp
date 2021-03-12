#include "timer.h"

//konstruktorius
Timer::Timer() : start{ std::chrono::high_resolution_clock::now() } {}

//laiko resetinimas
void Timer::reset() { start = std::chrono::high_resolution_clock::now(); }

//prabėgusio laiko grąžinimas
double Timer::current_time() {return std::chrono::duration<double> (std::chrono::high_resolution_clock::now() - start).count();}