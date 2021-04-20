#ifndef STUDENT_FUNCTIONS_HPP 
#define STUDENT_FUNCTIONS_HPP

#include "martyno_lib.hpp"
#include "structures.hpp"
#include "random_generator.h"
#include "utility_functions.hpp"
#include "output.hpp"
#include "input_file.hpp"
#include "timer.h"

// Šios funkcijos yra skirtos dirbti su studentų duomenimis ir yra labai specifinės
///////////////////////////////////////////////////////////////////////////////////

//ši funkcija atlkits programos benchmarką
template <class Container>
void student_benchmark(Container bench_students, string container_code, string split_mode);

//ši funkcija išrikiuoja studentus pagal tam tikrą parametrą
template <class Container>
void sort_students(Container &students, string sort_argument = "GRADES");

#endif