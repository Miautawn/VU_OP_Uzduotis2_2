#ifndef UTILITY_FUNCTIONS_HPP
#define UTILITY_FUNCTIONS_HPP

#include "martyno_lib.hpp"
#include <sys/stat.h>
#include <algorithm>

// UTILITY FUNKCIJOS
////////////////////

bool yes_or_no(string text); //paklausia taip arba ne klausimo
bool is_digit(string input); //patikrina ar ivestas tekstas yra skaicius
float calculate_mean(int n, vector<int> grades); //suskaičiuoja vidurkį
float calculate_median(int n, vector<int> grades); //suskaičiuoja medianą

//funkcija, kuri nuskaito tik sveikąjį skaičių ribose
int input_integer(string text, string err_text, string exit_string, int lower_bound, int upper_bound);

#endif