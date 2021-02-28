#include "main.hpp"

int main() {
  srand(time(NULL));

  vector <Student> students;
  students.reserve(10);
  
  string file_name = "kursiokai.txt";
  bool manual_input = true;

  //nuskaitymas iš failo
  if(file_exists(file_name)) {
    if(yes_or_no("Ar norėtumėte nuskaityti studentų duomenis iš failo?")) 
    read_students_from_file(students, file_name, manual_input);
    else cout<<"Jungiamas rankinis įvedinmas...\n"<<endl; 
  }
  
  while(manual_input) {
    if(!yes_or_no("Ar norite pridėti studentą į apskaitą?")) break;
    cout<<"\n*************************";
    Student new_student;
    read_credentials(new_student);

    int grade_num = -1;
    if(yes_or_no("Ar žinote kiek studentas turi pažymių už ND,"))
    grade_num = input_integer("Kiek (0, 50): ","Įveskite ne neigiamą skaičių: ", "0", 0, 50);

    if(yes_or_no("Ar norėtumėte atsitiktinai sugeneruoti pažymius?"))
    generate_grades(grade_num, new_student);
    else input_grades(grade_num, new_student);

    if(yes_or_no("\nSkaičiuoti per vidurkį - y, ar medianą - n? "))
    calculate_final(grade_num, new_student, true);
    else calculate_final(grade_num, new_student, false);

    students.push_back(new_student);
    cout<<"*************************"<<endl;
  }

  //pateikiama ataskaita
  if(!manual_input) output_students(students, true);
  else output_students(students, false);
}