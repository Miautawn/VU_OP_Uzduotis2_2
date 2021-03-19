#include "input_console.hpp"

void read_credentials(Student &new_student)
{
    cout<<"\nPrašoma įrašyti studento \n";
    cout<<"vardą: ";
    cin>>new_student.name;
    cout<<"pavardę: ";
    cin>>new_student.last_name;
}


void input_grades(int &n, Student &new_student)
{
    //jei vartotojas nepasakė kiek turi būti pažymių, jis ves, kol jam pabos
    if(n == -1) {
      n = 0;
      cout<<"\nVeskite pažymius (0, 10), kai pabos, parašykite -1"<<endl;
      while(true) {
        cout<<"Įveskite "<< n+1 <<" Pažymį: ";
        int grade = input_integer("", "Bandykite vėl (-1 jeigu norite užbaigti): ", 0, 10, "-1");
        if(grade == -1) break; // -1 baigs ciklą
        else new_student.grades.push_back(grade);
        n++;
      }
    }
    //jei vartotojas pasakė kiek turi būti pažymių
    else {
      for(int i = 0; i<n; i++) {
        cout<<"Įveskite "<< i+1 <<" Pažymį: ";
        int grade = input_integer("", "Bandykite vėl: ", 0, 10, "0");
        new_student.grades.push_back(grade);
      }
    }

    //egzamino rezultato įvedimas
    int exam_grade = input_integer("\nĮveskite egzamino rezultatą (0, 10): " , "Bandykite vėl: ", 0, 10, "0");
    new_student.exam_score = exam_grade;
}