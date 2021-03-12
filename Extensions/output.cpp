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
    for(int i = 0; i<students.size(); i++) {
        try {
        printf("%-14.14s ", students.at(i).last_name.c_str());
        printf("%-14.14s ", students.at(i).name.c_str());
        if(students.at(i).is_mean) printf("%.2f \n", students.at(i).final_score_mean);
        else printf("%17s %.2f \n", "", students.at(i).final_score_median);
        } catch(...) { printf("%s \n", "ERROR"); }     
    }
}

//išvedimas į failą
void output_to_file(vector<Student> students, string file_name, bool log) {
    //rikiavimas
    sort(students.begin(), students.end(), student_compare);

    if(log) cout<<"Rašoma į failą "<<"'"<<file_name<<"'"<<" ..."<<endl;
    std::ostringstream buffer;
    buffer<<"Pavardė        Vardas         Galutinis (vid) / Galutinis(med)\n";
    buffer<<string(60, '-')<<"\n"<<endl;

    for(int i = 0; i<students.size(); i++) {
        try {
            buffer<<left<<setw(14)<<setprecision(3)
            <<students.at(i).last_name<<" "<<setw(14)
            <<students.at(i).name<<" "<<setw(15)
            <<students.at(i).final_score_mean<<"   "
            <<students.at(i).final_score_median<<endl; 
        } catch(...) { buffer << "ERROR" << endl; };
    } 
    
    ofstream output(file_name);
    output << buffer.str();
    output.close();
}

// pagrindinė išvedimo funkcija
void output_students(vector<Student> students, bool to_file, string file_name, bool log) {
    if(students.size() != 0) {
        if(to_file) output_to_file(students, file_name, log);
        else output_to_console(students);
    }
}

