#ifndef INPUT_CONSOLE_HPP
#define INPUT_CONSOLE_HPP

#include "martyno_lib.hpp"
#include "structures.hpp"
#include "utility_functions.hpp"

// Čia funkcijos yra skirtos nuskaityti studentus iš consolės
/////////////////////////////////////////////////////////////

void read_credentials(Student &new_student); //nuskaito studento vardą/pavardę
void input_grades(int &n, Student &new_student); //nuskaito pažymius iš vartotojo

#endif