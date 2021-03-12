#include "utility_functions.hpp"

bool yes_or_no(string text)
{
  string option;
  while(option != "y" && option != "n")
  {
    cout<<text + " y/n: ";
    cin>>option;
  }
  return option == "y";
}

bool is_digit(string input)
{
  int n = input.length();
  for(int i = 0; i<n; i++) if(!std::isdigit(input[i])) return 0;
  return 1;
}

int input_integer(string text, string err_text, string exit_string, int lower_bound, int upper_bound)
{
  string input;
  cout<<text;
  while(true)
  {
    cin>>input;
    if(is_digit(input))
    {
      int number = std::stoi(input);
      if(number >= lower_bound && number <= upper_bound) return number;
    } else if (input == exit_string) return -1; 
    //jeigu neatitiko sąlygų
    cout<<err_text;
  }
}

float calculate_mean(int n, vector<int> grades)
{
  float sum = 0;
  for(int i = 0; i<n; i++) sum+=grades[i];
  return sum/n;
}

float calculate_median(int n, vector<int> grades)
{
  if(grades.size() != 0) {
    std::sort(grades.begin(), grades.end());
    //jei nelyginis skaičius namų darbų
    if(n%2 != 0) return grades[n / 2];
    //jei lyginis skaičius namų darbų
    else return ((float)(grades[n / 2] + grades[n / 2 - 1]))/2;
  } else return 0;
}


