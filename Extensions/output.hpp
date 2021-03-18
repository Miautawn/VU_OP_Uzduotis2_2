#ifndef OUTPUT_HPP
#define OUTPUT_HPP

#include "martyno_lib.hpp"
#include "structures.hpp"
#include "utility_functions.hpp"
#include <algorithm>

// Čia funkcijos yra skirtos išvesti rezultatus
///////////////////////////////////////////////

//universali išvedimo funkcija
template <class Container>
void output_students(Container students, bool to_file, string file_name = "output.txt", bool log = true);

#endif