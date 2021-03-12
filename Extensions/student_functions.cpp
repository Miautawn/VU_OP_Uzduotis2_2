#include "student_functions.hpp"

void generate_grades(int &n, Student &new_student, bool log)
{
    RandomInt generator;
    //jeigu vartotojas nepasakė kiek turi būti pažymių
    if(n == -1) n = generator.rnd(0, 15); 

    new_student.grades.reserve(n);
    for(int i=0; i<n; i++) new_student.grades.push_back(generator.rnd(0,10));

    if(log) {
      cout<<"\nBuvo sugeneruoti tokie "<<n<<" ND pažymiai: ";
      for(int grade: new_student.grades) cout<<grade<<" ";
    }
    new_student.exam_score = generator.rnd(0,10);
    if(log) cout<<"\nIr egzamino rezultatas: "<<new_student.exam_score<<endl;
}

void calculate_final(int grade_num, Student &new_student, bool is_mean)
{
  new_student.is_mean = is_mean;
  //jeigu yra nd pažymių
  if(grade_num != 0) {

    //skaičiuoti per vidurkį
    if(is_mean) { 
      new_student.mean = calculate_mean(grade_num, new_student.grades);
      new_student.final_score_mean = 0.4 * new_student.mean + 0.6 * new_student.exam_score;
    }
    //skaičiuoti per medianą 
    if(!is_mean) {  
      new_student.median = calculate_median(grade_num, new_student.grades);
      new_student.final_score_median = 0.4 * new_student.median + 0.6 * new_student.exam_score;
    } 
  }
  //jeigu pažymių iš ND nebuvo 
  else {
    new_student.mean, new_student.median = 0, 0;
    new_student.final_score_mean = 0.6 * new_student.exam_score;
    new_student.final_score_median =  0.6 * new_student.exam_score;
  }
}

void student_benchmark_generate_file(int n)
{
  vector<Student> generated_students;
  Student bench_student;
  std::ostringstream buffer;
  buffer<<"VARDAS          PAVARDĖ"<<endl;

  for(int i = 0; i<n; i++) {

    //duomenų generavimas
    bench_student.grades.clear();
    bench_student.name = "Vardas" + std::to_string(i+1);
    bench_student.last_name = "Pavarde" +  std::to_string(i+1);
    int grade_num = -1;
    generate_grades(grade_num, bench_student, false);

    //studento buferizavimas
    buffer<<left<<setw(15)
          <<bench_student.name<<" "<<setw(30)
          <<bench_student.last_name;

    for(int j = 0; j<bench_student.grades.size(); j++) 
    buffer<<left<<setw(5)<<bench_student.grades[j]<<setw(5);

    buffer<<bench_student.exam_score<<endl;
  }

  //išvedimas mūsų benchmark failo
  ofstream output("bench_temp.txt");
  output << buffer.str();
  output.close();  
}

void student_benchmark()
{
  int stages[5] = {1000, 10000, 100000, 1000000, 10000000};
  vector<Student> bench_students;
  Timer m_timer;
  for(int stage_index = 0; stage_index < 5; stage_index++) {

    cout<<"\n***************************";
    cout<<"\nPradedamas tikrinimas su "<<stages[stage_index]<<" studentų..."<<endl;
    m_timer.reset();
    bench_students.reserve(stages[stage_index]);

    //failo kūrimas
    student_benchmark_generate_file(stages[stage_index]);
    cout<<stages[stage_index]<<" studentų generavimas ir failo kūrimas užtruko: "
    <<m_timer.current_time()<<endl;
    m_timer.reset();

    //failo nuskaitymas
    read_students_from_file(bench_students, "bench_temp.txt", false);
    cout<<stages[stage_index]<<" studentų skaitymas iš failo užtruko: "
    <<m_timer.current_time()<<endl;
    m_timer.reset();
    
    //studentų rūšiavimas į dvi grupes:

    //1) surušiavimas didėjimo tvarka
    std::sort(bench_students.begin(), bench_students.end(), 
    [](const Student &l_student, const Student &r_student) {
      return l_student.final_score_mean < r_student.final_score_mean;
    });
    //2) pirmo >= 5 radimas
    vector<Student>::iterator first_good_student = 
    std::lower_bound(bench_students.begin(), bench_students.end(), 5,
    [](const Student &l_student, const int value) {
      return l_student.final_score_mean < value;
    });
    cout<<stages[stage_index]<<" studentų skirstymas užtruko: "
    <<m_timer.current_time()<<endl;
    m_timer.reset();

    //kietakų išvedimas į failą
    output_students( {first_good_student, bench_students.end()}, true, "bench_kietuoliai.txt", false);
    cout<<stages[stage_index]<<" Įrašų 'kietuolių' išvedimas į failą užtruko: "
    <<m_timer.current_time()<<endl;
    m_timer.reset();

    //nabagėlių išvedimas į failą
    output_students( {bench_students.begin(), first_good_student}, true, "bench_varguoliai.txt", false);
    cout<<stages[stage_index]<<" Įrašų 'varguolių' išvedimas į failą užtruko: "
    <<m_timer.current_time()<<endl;
    m_timer.reset();

    if(stage_index != 4) {
      if(!yes_or_no("Ar norite testi?")) break;
      else bench_students.clear(); 
    }
  }
}
