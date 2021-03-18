#include "output.hpp"

//funkcija, kuri palygina du studentus pagal pavardę ar vardą
bool student_compare(Student l_student, Student r_student)
{
  return (l_student.last_name == r_student.last_name) ? 
        l_student.name < r_student.name : 
        l_student.last_name < r_student.last_name;
}

//išvedimas į konsolę
template <class Container>
void output_to_console(Container students) {
    
    typename Container::iterator iter = students.begin();
    cout<<"\n"<<endl;
    cout<<"Pavardė        "<<"Vardas         "<<"Galutinis (vid)"<<" / "<<"Galutinis(med)"<<endl;
    cout<<string(60, '-')<<endl;
    for(int i = 0; i<students.size(); i++) {
        try {
        printf("%-14.14s ", (*iter).last_name.c_str());
        printf("%-14.14s ", (*iter).name.c_str());
        if((*iter).is_mean) printf("%.2f \n", (*iter).final_score_mean);
        else printf("%17s %.2f \n", "", (*iter).final_score_median);
        } catch(...) { printf("%s \n", "ERROR"); }     
        ++iter;
    }
}

//išvedimas į failą
template <class Container>
void output_to_file(Container students, string file_name, bool log) {
    //rikiavimas
    sort_container(students);
    typename Container::iterator iter = students.begin();

    if(log) cout<<"Rašoma į failą "<<"'"<<file_name<<"'"<<" ..."<<endl;
    std::ostringstream buffer;
    buffer<<"Pavardė        Vardas         Galutinis (vid) / Galutinis(med)\n";
    buffer<<string(60, '-')<<"\n"<<endl;

    for(int i = 0; i<students.size(); i++) {
        try {
            buffer<<left<<setw(14)<<setprecision(3)
            <<(*iter).last_name<<" "<<setw(14)
            <<(*iter).name<<" "<<setw(15)
            <<(*iter).final_score_mean<<"   "
            <<(*iter).final_score_median<<endl; 
        } catch(...) { buffer << "ERROR" << endl; };
        ++iter;
    } 
    
    ofstream output(file_name);
    output << buffer.str();
    output.close();
}

// pagrindinė išvedimo funkcija
template <class Container>
void output_students(Container students, bool to_file, string file_name, bool log) {
    if(students.size() != 0) {
        if(to_file) output_to_file(students, file_name, log);
        else output_to_console(students);
    }
}



template void output_students(vector<Student> students, bool to_file, string file_name, bool log);
template void output_students(list<Student> students, bool to_file, string file_name, bool log);
template void output_students(deque<Student> students, bool to_file, string file_name, bool log);

