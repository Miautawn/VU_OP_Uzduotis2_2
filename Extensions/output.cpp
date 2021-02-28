#include "output.hpp"

//funkcija, kuri palygina du studentus pagal pavardę ar vardą
bool student_compare(Student l_student, Student r_student)
{
  return (l_student.last_name == r_student.last_name) ? 
        l_student.name < r_student.name : 
        l_student.last_name < r_student.last_name;
}

//išvedimas į konsolę
void output_to_console(vector<Student> students) {
    cout<<"\n"<<endl;
    cout<<"Pavardė        "<<"Vardas         "<<"Galutinis (vid)"<<" / "<<"Galutinis(med)"<<endl;
    cout<<string(60, '-')<<endl;
    for(auto student : students) {
        printf("%-14.14s ", student.last_name.c_str());
        printf("%-14.14s ", student.name.c_str());
        if(student.is_mean) printf("%.2f \n", student.final_score_mean);
        else printf("%17s %.2f \n", "", student.final_score_median);
    }
}

//išvedimas į failą
void output_to_file(vector<Student> students) {
    //rikiavimas
    sort(students.begin(), students.end(), student_compare);

    cout<<"Rašoma į failą 'output.txt'..."<<endl;
    std::ostringstream buffer;
    buffer<<"Pavardė        Vardas         Galutinis (vid) / Galutinis(med)\n";
    buffer<<string(60, '-')<<"\n"<<endl;

    for(auto student : students) 
    buffer<<left<<setw(14)<<setprecision(3)
        <<student.last_name<<" "<<setw(14)
        <<student.name<<" "<<setw(15)
        <<student.final_score_mean<<"   "
        <<student.final_score_median<<endl;

    ofstream output ("output.txt");
    output << buffer.str();
    output.close();
}

// pagrindinė išvedimo funkcija
void output_students(vector<Student> students, bool to_file) {
    if(students.size() != 0) {
        if(to_file) output_to_file(students);
        else output_to_console(students);
    }
}

