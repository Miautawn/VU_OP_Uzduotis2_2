#ifndef STRUCTURES_HPP
#define STRUCTURES_HPP

#include "martyno_lib.hpp"
#include "random_generator.h"
#include "utility_functions.hpp"

class Student
{
  // privatūs atributai
  private:
    string name;
    string last_name;
    vector<int> grades;
    int exam_score;
    bool is_mean;
    float mean;
    float median;
    float final_score_mean;
    float final_score_median;

    void validate_grade(string grade_temp, bool exam);
  
  // vieši atributai ir funkcijos
  public:
    Student() : exam_score{0} {} //default konstruktorius
    Student(std::istream& source); // konstruktorius skirtas skaityti iš failo

    //getter'iai
    string get_name() const;
    string get_last_name() const;
    bool get_is_mean() const;
    int get_exam_score() const;
    float get_final_score_mean() const;
    float get_final_score_median() const;
    int get_grade(int i = -1) const;

    //setter'iai
    void set_name(string name);
    void set_last_name(string last_name);
    void add_grade(int grade);
    void remove_grade();
    void set_exam_score(int exam_score);

    //member funkcijos
    void clear_grades();
    void read_student(std::istringstream &source);
    void generate_grades(int &n, bool log = true);
    void calculate_final(bool is_mean);
    bool operator < (const Student &another_student);
};

#endif