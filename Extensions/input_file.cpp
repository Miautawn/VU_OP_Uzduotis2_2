#include "input_file.hpp"


// pagalbinė funkcija, kuri validuoja gautus pažymius
void add_read_grade(string grade_temp, Student &student, bool exam)
{
  if(is_digit(grade_temp)) {
    int grade = std::stoi(grade_temp);
    if(grade >= 0 && grade <= 10) {
      if(exam) {
        student.grades.pop_back();
        student.exam_score = grade;
      } else student.grades.push_back(grade);
    } else if (exam) student.exam_score = 0;
  } else if (exam) student.exam_score = 0;
}

void read_students_from_file(vector<Student> &students, string file_name)
{
    ifstream input(file_name);
    if(input) {

      cout<<"Skaitoma..."<<endl;
      string line;
      getline(input, line);   //praleidžia pirmą eilutę
      while(getline(input, line)) {
         Student new_student;

        //vardu skaitymas
        std::istringstream temp(line);
        temp >> new_student.name >> new_student.last_name;

        //pazymiu skaitymas
        string grade_temp;
        while(temp >> grade_temp) add_read_grade(grade_temp, new_student, false);
        //egzamino rezultato skaitymas
        add_read_grade(grade_temp, new_student, true);

        //galutinių balų skaičiavimas
        int grade_num = new_student.grades.size();
        calculate_final(grade_num, new_student, true); //vidurkiu paremtas galutinis balas
        calculate_final(grade_num, new_student, false); //mediana paremtas galutinis balas
  
        students.push_back(new_student);
      } 
    }else throw std::runtime_error("Could not open file");
    input.close();
}