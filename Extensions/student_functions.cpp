#include "student_functions.hpp"

//funkcija, kuri palygina du studentus pagal pavardę ar vardą
bool student_compare_names(Student l_student, Student r_student)
{
  return (l_student.get_last_name() == r_student.get_last_name()) ? 
        l_student.get_name() < r_student.get_name() : 
        l_student.get_last_name() < r_student.get_last_name();
}

template <class Container>
void sort_students(Container &students, string sort_argument) {
  if(sort_argument == "GRADES") {
    std::sort(students.begin(), students.end());
  } else if(sort_argument == "NAMES") {
    std::sort(students.begin(), students.end(), student_compare_names);
  }
}

template <>
void sort_students(list<Student> &students, string sort_argument) {
  students.sort();
}


void student_benchmark_generate_file(int n, string file_name)
{
  vector<Student> generated_students;
  Student bench_student;
  std::ostringstream buffer;
  buffer<<"VARDAS          PAVARDĖ"<<endl;

  for(int i = 0; i<n; i++) {

    //duomenų generavimas
    bench_student.clear_grades();
    bench_student.set_name("Vardas" + std::to_string(i+1));
    bench_student.set_last_name("Pavarde" +  std::to_string(i+1));
    int grade_num = -1;
    bench_student.generate_grades(grade_num, false);

    //studento buferizavimas
    buffer<<left<<setw(15)
          <<bench_student.get_name()<<" "<<setw(30)
          <<bench_student.get_last_name();

    for(int j = 0; j<bench_student.get_grade(); j++) 
    buffer<<left<<setw(5)<<bench_student.get_grade(j)<<setw(5);

    buffer<<bench_student.get_exam_score()<<endl;
  }

  //išvedimas mūsų benchmark failo
  ofstream output(file_name);
  output << buffer.str();
  output.close();  
}


template <class Container>
void student_benchmark(Container bench_students, string container_code,  string split_mode)
{
  int stages[5] = {1000, 10000, 100000, 1000000, 10000000};
  double full_time;
  Timer m_timer;
  string local_file;
  
  for(int stage_index = 0; stage_index < 5; stage_index++) {

    cout<<"\n***************************";
    cout<<"\nPradedamas tikrinimas su "<<stages[stage_index]<<" studentų..."<<endl;
    m_timer.reset();
    full_time = 0;
    local_file = "bench_temp" + std::to_string(stages[stage_index]) + ".txt";

    //failo kūrimas
    if(!files_exists(local_file)) {
      student_benchmark_generate_file(stages[stage_index], local_file);
      cout<<stages[stage_index]<<" studentų generavimas ir failo kūrimas užtruko: "
      <<m_timer.split_time(full_time)<<endl;
    }
    
    //failo nuskaitymas
    read_students_from_file(bench_students, 
    "bench_temp" + std::to_string(stages[stage_index]) + ".txt", false);
    cout<<stages[stage_index]<<" studentų nuskaitymas užtruko: "
    <<m_timer.split_time(full_time)<<endl;
    
    //studentų rūšiavimas į dvi grupes:
    ///////////////////////////////////

    //1) surušiavimas didėjimo tvarka
    sort_students(bench_students);
    cout<<stages[stage_index]<<" studentų surūšiavimas didėjimo tvarka užtruko: "
    <<m_timer.split_time(full_time)<<endl;

    //2) pirmo >= 5 radimas
    typename Container::iterator first_good_student = 
    std::lower_bound(bench_students.begin(), bench_students.end(), 5,
      [](const Student &l_student, const int value) {
        return l_student.get_final_score_mean() < value;
      });
    

    //3) kietaku ir varguoliu į skirtingus konteinerius paskirstymas
    Container temp_kietuoliai;
    Container temp_varguoliai;
    Container *kietuoliai = &temp_kietuoliai;
    Container *varguoliai = &temp_varguoliai;
    if(split_mode == "COPY") {
      temp_kietuoliai = {first_good_student, bench_students.end()};
      temp_varguoliai = {bench_students.begin(), first_good_student};
    } else {
      temp_kietuoliai = {first_good_student, bench_students.end()};
      bench_students.erase(first_good_student, bench_students.end());
      varguoliai = &bench_students;
    }

    cout<<stages[stage_index]<<" Įrašų 'kietakų' ir 'varguolių' rūšiavimas užtruko: "
    <<m_timer.split_time(full_time)<<endl;

    ///////////////////////////////////
    //studentų rūšiavimas į dvi grupes:
    

    //kietakų išvedimas į failą
    local_file = "Benchmark/bench_kietuoliai" + std::to_string(stages[stage_index]) + ".txt";
    output_to_file(*kietuoliai, "GRADES", false, local_file);
    cout<<stages[stage_index]<<" Įrašų 'kietuolių' išvedimas į failą užtruko: "
    <<m_timer.split_time(full_time)<<endl;

    //nabagėlių išvedimas į failą
    local_file = "Benchmark/bench_varguoliai" + std::to_string(stages[stage_index]) + ".txt";
    output_to_file(*varguoliai, "GRADES", false, local_file);
    cout<<stages[stage_index]<<" Įrašų 'varguolių' išvedimas į failą užtruko: "
    <<m_timer.split_time(full_time)<<endl;

    //galutinio laiko išrašymas
    cout<<stages[stage_index]<<" VISAS TESTAS UŽTRUKO: "<<full_time<<endl;

    if(stage_index != 4) {
      if(!yes_or_no("Ar norite testi?")) break;
      else bench_students.clear(); 
    }
  }
}

template void sort_students(vector<Student> &students, string sort_argument);
template void sort_students(deque<Student> &students, string sort_argument);

template void student_benchmark(vector<Student> bench_students, string container_code, string split_mode);
template void student_benchmark(list<Student> bench_students, string container_code, string split_mode);
template void student_benchmark(deque<Student> bench_students, string container_code, string split_mode);
