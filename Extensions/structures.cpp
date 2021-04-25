#include "structures.hpp"

//getter'iai
string Student::get_name() const {return name;}
string Student::get_last_name() const {return last_name;}
bool Student::get_is_mean() const {return is_mean;}
int Student::get_exam_score() const {return exam_score;}
float Student::get_final_score_mean() const {return final_score_mean;}
float Student::get_final_score_median() const {return final_score_median;}
int Student::get_grade(int i) const { return i == -1 ? (*grades).size() : (*grades)[i]; }

//setter'iai
void Student::set_name(string name) {this->name = name;}
void Student::set_last_name(string last_name) {this->last_name = last_name;}
void Student::add_grade(int grade) {(*grades).push_back(grade);}
void Student::remove_grade() {(*grades).pop_back();}
void Student::set_exam_score(int exam_score) {this->exam_score = exam_score;}

// konstruktoriai ir operatoriai
////////////////////////////////

Student::Student() : exam_score{0}, grades{new vector<int>}, is_mean{true} {} //konstruktroius
Student::~Student() { delete grades; } //destruktorius;
Student::Student(const Student& other) //copy konstruktorius
      : name{other.name}, last_name{other.last_name},
        is_mean{other.is_mean}, exam_score{other.exam_score},
        mean{other.mean}, median{other.median},
        final_score_mean{other.final_score_mean}, 
        final_score_median{other.final_score_median},
        grades{ new vector<int>( *(other.grades) ) } {}


Student& Student::operator=(const Student& other) { //copy operatorius
  if(this == &other) return *this;

  vector<int> *other_grades = new vector<int>(*(other.grades));
  delete grades;
  grades = other_grades;
  name = other.name;
  last_name = other.last_name;
  exam_score = other.exam_score;
  is_mean = other.is_mean;
  mean = other.mean;
  median = other.median;
  final_score_mean = other.final_score_mean;
  final_score_median = other.final_score_median;

  return *this;
}

Student::Student(Student&& other) //move konstruktorius
      : name{std::move(other.name)}, last_name{std::move(other.last_name)},
        is_mean{std::move(other.is_mean)}, exam_score{std::move(other.exam_score)},
        mean{std::move(other.mean)}, median{std::move(other.median)},
        final_score_mean{std::move(other.final_score_mean)},
        final_score_median{std::move(other.final_score_median)},
        grades{std::move(other.grades)}
        {
          other.grades = NULL;
          other.exam_score = 0;
          other.mean = 0;
          other.median = 0;
          other.final_score_mean = 0;
          other.final_score_median = 0;
        }

Student& Student::operator=(Student&& other) { //move operatorius
  if(this == &other) return *this;
  delete grades;
  grades = std::move(other.grades);
  name = std::move(other.name);
  last_name = std::move(other.last_name);
  exam_score = std::move(other.exam_score);
  is_mean = std::move(other.is_mean);
  mean = std::move(other.mean);
  median = std::move(other.median);
  final_score_mean = std::move(other.final_score_mean);
  final_score_median = std::move(other.final_score_median);

  other.grades = NULL;
  other.exam_score = 0;
  other.mean = 0;
  other.median = 0;
  other.final_score_mean = 0;
  other.final_score_median = 0;

  return *this;
}

bool Student::operator < (const Student &another_student) { // palyginimo operatorius
  return this->final_score_mean < another_student.final_score_mean;
}

////////////////////////////////
// konstruktoriai ir operatoriai


//member funkcijos
/////////////////

// pagalbinė funkcija, kuri validuoja gautus pažymius
void Student::validate_grade(string grade_temp, bool exam) {
  if(is_digit(grade_temp)) {
    int grade = std::stoi(grade_temp);
    if(grade >= 0 && grade <= 10) {
      if(exam) {
        (*grades).pop_back();
        exam_score = grade;
      } else (*grades).push_back(grade);
    }
  }
}

// studento užpildymas iš streamo
void Student::read_student(std::istringstream &source)
{
  (*grades).clear();
  source >> name >> last_name;

  //pazymiu skaitymas
  string grade_temp;
  while(source >> grade_temp) validate_grade(grade_temp, false);

  //egzamino rezultato skaitymas
  validate_grade(grade_temp, true);

  calculate_final(true); //vidurkiu paremtas galutinis balas
  calculate_final(false); //mediana paremtas galutinis balas
}

//generuojamų pažymių funkcija
void Student::generate_grades(int &n, bool log) {
    RandomInt generator;
    //jeigu vartotojas nepasakė kiek turi būti pažymių
    if(n == -1) n = generator.rnd(0, 15); 

    (*grades).reserve(n);
    for(int i=0; i<n; i++) (*grades).push_back(generator.rnd(0,10));
    exam_score = generator.rnd(0,10);

    if(log) {
      cout<<"\nBuvo sugeneruoti tokie "<<n<<" ND pažymiai: ";
      for(int grade: (*grades)) cout<<grade<<" ";

      cout<<"\nIr egzamino rezultatas: "<<exam_score<<endl;
    } 
}

//funkcija skirta suskaičiuoti galutinius balus
void Student::calculate_final(bool is_mean) {
  this->is_mean = is_mean;
  //jeigu yra nd pažymių
  if((*grades).size() != 0) {

    //skaičiuoti per vidurkį
    if(is_mean) { 
      mean = calculate_mean((*grades).size(), (*grades));
      final_score_mean = 0.4 * mean + 0.6 * exam_score;
    }
    //skaičiuoti per medianą 
    if(!is_mean) {  
      median = calculate_median((*grades).size(), (*grades));
      final_score_median = 0.4 * median + 0.6 * exam_score;
    } 
  }
  //jeigu pažymių iš ND nebuvo 
  else {
    mean, median = 0, 0;
    final_score_mean = 0.6 * exam_score;
    final_score_median =  0.6 * exam_score;
  }
}


//pažymių išvalymas
void Student::clear_grades() {
  if(!grades) return;
  (*grades).clear();
}

void Student::print_grades() {
  if(!grades) return;
  for(auto i : (*grades)) {
    cout<<i<<" ";
  }
  cout<<endl;
}


