#ifndef STRUCTURES_HPP
#define STRUCTURES_HPP

// Čia yra pagrindinė duomenų struktūra
///////////////////////////////////////

struct Student
{
  string name;
  string last_name;

  vector<int> grades;
  int exam_score;
  
  bool is_mean;
  float mean;
  float median;
  
  float final_score_mean;
  float final_score_median;

  bool operator < (const Student &another_student) {
    return this->final_score_mean < another_student.final_score_mean;}
};

#endif