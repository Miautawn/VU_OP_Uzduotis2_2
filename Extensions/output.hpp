#ifndef OUTPUT_HPP
#define OUTPUT_HPP

#include "martyno_lib.hpp"
#include "structures.hpp"
#include <algorithm>

// Čia funkcijos yra skirtos išvesti rezultatus
///////////////////////////////////////////////

//universali išvedimo funkcija
void output_students(vector<Student> students, bool to_file, string file_name = "output.txt", bool log = true);

#endif