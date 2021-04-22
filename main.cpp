#include "main.hpp"

int main() {
  
  //benchmarkas
  if(yes_or_no("Ar norėtumėte atlikti programos 'benchmark'ą'?")) {

    //gaunamas konteinerio pasirinkimas
    int container_code = input_integer(
      "\nSu kuriuo konteineriu atlikti testą?"
      "\n1) Vektor"
      "\n2) List"
      "\n3) Deque"
      "\n4) Atšaukti"
      "\nĮveskite pasirinkimą: ",
      "Klaida, bandykite vėl: ", 1, 4);
      if(container_code != 4) {
        string split_mode = "";
        int split_index = input_integer(
        "\nSu kuriuo metodu atlikti rušiavimą?"
        "\n1) Kopijavimu metodu"
        "\n2) Trynimo metodu"
        "\nĮveskite pasirinkimą: ",
        "Klaida, bandykite vėl: ", 1, 2);
        split_mode = (split_index == 1) ? "COPY" : "REMOVE";

        switch(container_code) {
        case 1 : student_benchmark(vector<Student> (), "VECTOR", split_mode); break;
        case 2 : student_benchmark(list<Student> (), "LIST", split_mode); break;
        case 3 : student_benchmark(deque<Student> (), "DEQUE", split_mode); break;}
        exit(0);
      }else cout<<"Atšaukiamas benchmark'as...\n"<<endl;
  }

Student a;
a.set_name("ala");
a.set_last_name("cringe");
a.set_exam_score(12);
a.add_grade(12);
a.add_grade(13);

int cr;
int br = cr;
cout<<br<<endl;

Student b = a;

b.set_name("vaikas");
cout<<b.get_name()<<endl;
cout<<b.get_last_name()<<endl;

a.remove_grade();
a.print_grades();
b.print_grades();

Student c;
c = b;
cout<<c.get_name()<<endl;
}


//   vector <Student> students;
//   students.reserve(10);
//   bool manual_input = false;
 
//   // //nuskaitymas iš failo
//   if(yes_or_no("Ar norėtumėte nuskaityti studentų duomenis iš failo?")) {

//      string file_name = "";
//      cout<<"\nIveskite failo pavadinimą: ";
//      cin>>file_name;

//     try {
//       read_students_from_file(students, file_name);
//     } catch(...) {
//       processException();
//       cout<<"\nJungiamas rankinis rėžimas...\n"<<endl; 
//       manual_input = true;
//     }
//   } else {
//       cout<<"\nJungiamas rankinis įvedinmas...\n"<<endl; 
//       manual_input = true;
//   }

  
//   while(manual_input) {
//     if(!yes_or_no("Ar norite pridėti studentą į apskaitą?")) break;
//     cout<<"\n*************************";
//     Student new_student;
//     read_credentials(new_student);

//     int grade_num = -1;
//     if(yes_or_no("Ar žinote kiek studentas turi pažymių už ND,"))
//     grade_num = input_integer("Kiek (0, 50): ","Įveskite ne neigiamą skaičių: ", 0, 50);

//     if(yes_or_no("Ar norėtumėte atsitiktinai sugeneruoti pažymius?"))
//     new_student.generate_grades(grade_num);
//     else input_grades(grade_num, new_student);

//     if(yes_or_no("\nSkaičiuoti per vidurkį - y, ar medianą - n? "))
//     new_student.calculate_final(true);
//     else new_student.calculate_final(false);

//     students.push_back(new_student);
//     cout<<"*************************"<<endl;
//   }

//   //pateikiama ataskaita
//   if(!manual_input) output_to_file(students, "NAMES", true);
//   else output_to_console(students);
  
// }