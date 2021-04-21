#include "input_file.hpp"

template <class Container>
void read_students_from_file(Container &students, string file_name, bool log)
{
    ifstream input(file_name);
    if(input) {

      if(log) cout<<"Skaitoma..."<<endl;
      string line;
      getline(input, line);   //praleidžia pirmą eilutę

      Student new_student;
      while(getline(input, line)) {

        std::istringstream temp(line);
        new_student.read_student(temp);
        students.push_back(new_student);
      } 
    }else throw std::runtime_error("Could not open file"); 
    input.close();
}

template void read_students_from_file(vector<Student> &students, string file_name, bool log);
template void read_students_from_file(list<Student> &students, string file_name, bool log);
template void read_students_from_file(deque<Student> &students, string file_name, bool log);