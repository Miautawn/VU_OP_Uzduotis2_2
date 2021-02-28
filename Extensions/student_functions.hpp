#ifndef STUDENT_FUNCTIONS_HPP 
#define STUDENT_FUNCTIONS_HPP

#include "martyno_lib.hpp"
#include "structures.hpp"
#include "random_generator.h"
#include "utility_functions.hpp"

// Šios funkcijos yra skirtos dirbti su studentų duomenimis ir yra labai specifinės
///////////////////////////////////////////////////////////////////////////////////

void generate_grades(int &n, Student &new_student); //sugeneruoja pažymius
void calculate_final(int grade_num, Student &new_student, bool is_mean); //suskaičiuoja galutinį balą


#endif