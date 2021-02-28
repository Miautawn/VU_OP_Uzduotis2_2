#include "student_functions.hpp"

void generate_grades(int &n, Student &new_student)
{
    RandomInt generator;
    //jeigu vartotojas nepasakė kiek turi būti pažymių
    if(n == -1) n = generator.rnd(0, 15); 

    new_student.grades.reserve(n);
    for(int i=0; i<n; i++) new_student.grades.push_back(generator.rnd(0,10));

    cout<<"\nBuvo sugeneruoti tokie "<<n<<" ND pažymiai: ";
    for(int grade: new_student.grades) cout<<grade<<" ";
    new_student.exam_score = generator.rnd(0,10);
    cout<<"\nIr egzamino rezultatas: "<<new_student.exam_score<<endl;
}

void calculate_final(int grade_num, Student &new_student, bool is_mean)
{
  new_student.is_mean = is_mean;
  //jeigu yra nd pažymių
  if(grade_num != 0) {

    //skaičiuoti per vidurkį
    if(is_mean) { 
      new_student.mean = calculate_mean(grade_num, new_student.grades);
      new_student.final_score_mean = 0.4 * new_student.mean + 0.6 * new_student.exam_score;
    }
    //skaičiuoti per medianą 
    if(!is_mean) {  
      new_student.median = calculate_median(grade_num, new_student.grades);
      new_student.final_score_median = 0.4 * new_student.median + 0.6 * new_student.exam_score;
    } 
  }
  //jeigu pažymių iš ND nebuvo 
  else {
    new_student.mean, new_student.median = 0, 0;
    new_student.final_score_mean = 0.6 * new_student.exam_score;
    new_student.final_score_median =  0.6 * new_student.exam_score;
  }
}