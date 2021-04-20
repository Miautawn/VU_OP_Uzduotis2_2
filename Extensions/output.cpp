#include "output.hpp"

//išvedimas į konsolę
template <class Container>
void output_to_console(Container students) {
    
    typename Container::iterator iter = students.begin();
    cout<<"\n"<<endl;
    cout<<"Pavardė        "<<"Vardas         "<<"Galutinis (vid)"<<" / "<<"Galutinis(med)"<<endl;
    cout<<string(60, '-')<<endl;
    for(int i = 0; i<students.size(); i++) {
        try {
        printf("%-14.14s ", (*iter).get_last_name().c_str());
        printf("%-14.14s ", (*iter).get_name().c_str());
        if((*iter).get_is_mean()) printf("%.2f \n", (*iter).get_final_score_mean());
        else printf("%17s %.2f \n", "", (*iter).get_final_score_median());
        } catch(...) { printf("%s \n", "ERROR"); }     
        ++iter;
    }
}

// išvedimas į failą
template <class Container>
void output_to_file(Container students, string sort_argument, bool log, string file_name) {
    //rikiavimas pagal varda ir pavarde
    sort_students(students, sort_argument);
    typename Container::iterator iter = students.begin();

    if(log) cout<<"Rašoma į failą "<<"'"<<file_name<<"'"<<" ..."<<endl;
    std::ostringstream buffer;
    buffer<<"Pavardė        Vardas         Galutinis (vid) / Galutinis(med)\n";
    buffer<<string(60, '-')<<"\n"<<endl;

    for(int i = 0; i<students.size(); i++) {
        try {
            buffer<<left<<setw(14)<<setprecision(3)
            <<(*iter).get_last_name()<<" "<<setw(14)
            <<(*iter).get_name()<<" "<<setw(15)
            <<(*iter).get_final_score_mean()<<"   "
            <<(*iter).get_final_score_median()<<endl; 
        } catch(...) { buffer << "ERROR" << endl; };
        ++iter;
    } 
    
    ofstream output(file_name);
    output << buffer.str();
    output.close();
}


template void output_to_console(vector<Student>);
template void output_to_console(list<Student>);
template void output_to_console(deque<Student>);

template void output_to_file(vector<Student> students, string sort_argument, bool log, string file_name);
template void output_to_file(list<Student> students, string sort_argument, bool log, string file_name);
template void output_to_file(deque<Student> students, string sort_argument, bool log, string file_name);

