#ifndef INPUT_FILE_HPP
#define INPUT_FILE_HPP

#include "martyno_lib.hpp"
#include "structures.hpp"
#include "student_functions.hpp"

// Čia funkcijos yra skirtos nuskaityti studentus iš failo
//////////////////////////////////////////////////////////

//nuskaito studentus iš failo "kursiokai.txt"
void read_students_from_file(vector<Student> &students, string file_name, bool log = true);

#endif