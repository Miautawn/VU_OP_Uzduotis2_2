#ifndef OUTPUT_HPP
#define OUTPUT_HPP

#include "martyno_lib.hpp"
#include "structures.hpp"
#include "student_functions.hpp"

// Čia funkcijos yra skirtos išvesti rezultatus
///////////////////////////////////////////////

//universali išvedimo funkcija
template <class Container>
void output_to_console(Container students);

template <class Container>
void output_to_file(Container students, string sort_argument = "GRADES", bool log = true, string file_name = "output.txt");

#endif