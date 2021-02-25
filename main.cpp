#include "martyno_lib.h"

//Pagrindinė struktūra
struct Student
{
  string name;
  string last_name;

  vector<int> grades;
  int exam_score;
  
  bool is_mean;
  float mean;
  float median;
  
  float final_score_mean;
  float final_score_median;
};


//UTILITY FUNKCIJOS
///////////////////

//ši funkcija paklausia taip arba ne klausimo
bool yes_or_no(string text)
{
  string option;
  while(option != "y" && option != "n")
  {
    cout<<text + " y/n: ";
    cin>>option;
  }
  return option == "y";
}

//funkcija, kuri patikrina ar ivestas tekstas yra skaicius
bool is_digit(string input)
{
  int n = input.length();
  for(int i = 0; i<n; i++) if(!std::isdigit(input[i])) return 0;
  return 1;
}

//funkcija, kuri nuskaito tik sveikąjį skaičių ribose
int input_integer(string text, string err_text, string exit_string, int lower_bound, int upper_bound)
{
  string input;
  cout<<text;
  while(true)
  {
    cin>>input;
    if(is_digit(input))
    {
      int number = std::stoi(input);
      if(number >= lower_bound && number <= upper_bound) return number;
    } else if (input == exit_string) return -1; 
    //jeigu neatitiko sąlygų
    cout<<err_text;
  }
}

float calculate_mean(int n, vector<int> grades)
{
  float sum = 0;
  for(int i = 0; i<n; i++) sum+=grades[i];
  return sum/n;
}

float calculate_median(int n, vector<int> grades)
{
  std::sort(grades.begin(), grades.end());

  //jei nelyginis skaičius namų darbų
  if(n%2 != 0) return grades[n / 2];
  //jei lyginis skaičius namų darbų
  else return ((float)(grades[n / 2] + grades[n / 2 - 1]))/2;
}

bool file_exists(string name)
{
  struct stat buffer;
  return (stat(name.c_str(), &buffer) == 0);
}

///////////////////
//UTILITY FUNKCIJOS

bool student_compare(Student l_student, Student r_student)
{
  if(l_student.name < r_student.name) return true;
  else if(l_student.name == r_student.name && l_student.last_name < r_student.last_name) return true;
  
  return false;
}

//ši funkcija nuskaito studento vardą/pavardę
void get_credentials(Student &new_student)
{
  cout<<"\nPrašoma įrašyti studento \n";
  cout<<"vardą: ";
  cin>>new_student.name;
  cout<<"pavardę: ";
  cin>>new_student.last_name;
}

//Ši funkcija sugeneruoja pažymius
void generate_grades(int &n, Student &new_student)
{
    RandomInt generator;
    //jeigu vartotojas nepasakė kiek turi būti pažymių
    if(n == -1) n = generator.rnd(0, 15); 

    new_student.grades.reserve(n);
    for(int i=0; i<n; i++) new_student.grades.push_back(generator.rnd(0,10));

    cout<<"\nBuvo sugeneruoti tokie "<<n<<" ND pažymiai: ";
    for(int grade: new_student.grades) cout<<grade<<" ";
    new_student.exam_score = generator.rnd(0,10);
    cout<<"\nIr egzamino rezultatas: "<<new_student.exam_score<<endl;
}

//Ši funkcija nuskaito pažymius iš vartotojo
void input_grades(int &n, Student &new_student)
{
    //jei vartotojas nepasakė kiek turi būti pažymių, jis ves, kol jam pabos
    if(n == -1) {
      n = 0;
      cout<<"\nVeskite pažymius (0, 10), kai pabos, parašykite -1"<<endl;
      while(true) {
        cout<<"Įveskite "<< n+1 <<" Pažymį: ";
        int grade = input_integer("", "Bandykite vėl (-1 jeigu norite užbaigti): ", "-1", 0, 10);
        if(grade == -1) break; // -1 baigs ciklą
        else new_student.grades.push_back(grade);
        n++;
      }
    }
    //jei vartotojas pasakė kiek turi būti pažymių
    else {
      for(int i = 0; i<n; i++) {
        cout<<"Įveskite "<< i+1 <<" Pažymį: ";
        int grade = input_integer("", "Bandykite vėl: ", "0", 0, 10);
        new_student.grades.push_back(grade);
      }
    }

    //egzamino rezultato įvedimas
    int exam_grade = input_integer("\nĮveskite egzamino rezultatą (0, 10): " , "Bandykite vėl: ", "0", 0, 10);
    new_student.exam_score = exam_grade;
}

//Ši funkcija suskaičiuoja galutinį balą
void calculate_final(int grade_num, Student &new_student, bool mean)
{
  new_student.is_mean = mean;
  //jeigu yra nd pažymių
  if(grade_num != 0) {

    //skaičiuoti per vidurkį
    if(mean) { 
      new_student.mean = calculate_mean(grade_num, new_student.grades);
      new_student.final_score_mean = 0.4 * new_student.mean + 0.6 * new_student.exam_score;
    }
    //skaičiuoti per medianą 
    if(!mean) {  
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

//ši funkcija nuskaito studentus iš failo
void read_students_from_file(vector<Student> &students, string file_name, bool &manual_input)
{
    ifstream input(file_name);
    if(input.is_open()) {
      manual_input = false;
      string line;
      
      getline(input, line);   //praleidžia pirmą eilutę
      while(getline(input, line)) {
         Student new_student;

        //vardu skaitymas
        std::istringstream temp(line);
        temp >> new_student.name >> new_student.last_name;

        //pazymiu skaitymas
        string grade_temp;
        while(temp >> grade_temp) {
          if(is_digit(grade_temp)) {
            int grade = std::stoi(grade_temp);
            if(grade >= 0 && grade <= 10) new_student.grades.push_back(grade);
          }
        }
        //egzamino rezultato skaitymas
        if(is_digit(grade_temp)) {
          int grade = std::stoi(grade_temp);
          if(grade >= 0 && grade <= 10) {
            new_student.exam_score = grade;
            new_student.grades.pop_back();
          } else new_student.exam_score = 0;
        } else new_student.exam_score = 0;

        //galutinių balų skaičiavimas
        int grade_num = new_student.grades.size();
        calculate_final(grade_num, new_student, true); //vidurkiu paremtas galutinis balas
        calculate_final(grade_num, new_student, false); //mediana paremtas galutinis balas
  
        students.push_back(new_student);
      }
    }else {
      cout<<"Įvyko klaida nuskaitant failą,\nJungiamas rankinis įvedimas..."<<endl;
      manual_input = true;
    }
}


int main() {
  srand(time(NULL));

  vector <Student> students;
  students.reserve(10);
  
  string file_name = "kursiokai.txt";
  bool manual_input = true;
  if(file_exists(file_name)) {
    if(yes_or_no("Ar norėtumėte nuskaityti studentų duomenis iš failo?")) {
    read_students_from_file(students, file_name, manual_input);

    //studentai rikiuojami pagal vardus ar pavardes
    std::sort(students.begin(), students.end(), student_compare);

    } else cout<<"Jungiamas rankinis įvedinmas...\n"<<endl; 
  }
  
  while(manual_input) {
    if(!yes_or_no("Ar norite pridėti studentą į apskaitą?")) break;
    cout<<"\n*************************";
    Student new_student;
    get_credentials(new_student);

    int grade_num = -1;
    if(yes_or_no("Ar žinote kiek studentas turi pažymių už ND,"))
    grade_num = input_integer("Kiek (0, 50): ","Įveskite ne neigiamą skaičių: ", "0", 0, 50);

    if(yes_or_no("Ar norėtumėte atsitiktinai sugeneruoti pažymius?"))
    generate_grades(grade_num, new_student);
    else input_grades(grade_num, new_student);

    if(yes_or_no("\nSkaičiuoti per vidurkį - y, ar medianą - n? "))
    calculate_final(grade_num, new_student, true);
    else calculate_final(grade_num, new_student, false);

    students.push_back(new_student);
    cout<<"*************************"<<endl;
  }

  //pateikiama ataskaita
  if(students.size() != 0) {
    cout<<"\n"<<endl;
    cout<<"Pavardė        "<<"Vardas         "<<"Galutinis (vid)"<<" / "<<"Galutinis(med)"<<endl;
    cout<<string(60, '-')<<endl;
    for(auto student : students) {
      printf("%-14.14s ", student.name.c_str());
      printf("%-14.14s ", student.last_name.c_str());
      if(!manual_input) printf("%-15.2f   %.2f \n", student.final_score_mean, student.final_score_median);
      else if(student.is_mean) printf("%.2f \n", student.final_score_mean);
      else printf("%17s %.2f \n", "", student.final_score_median);
    }
  }
}