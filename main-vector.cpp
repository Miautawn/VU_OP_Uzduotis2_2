#include "martyno_lib.h"

//Pagrindinė struktūra
struct Student
{
  string name;
  string last_name;
  vector<int> grades;
  bool is_mean;
  double mean_or_median;
  int exam_score;
  double final_score;
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

///////////////////
//UTILITY FUNKCIJOS



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
    //jeigu vartotojas nepasakė kiek turi būti pažymių
    if(n == -1) n = rand()%10;
    new_student.grades.reserve(n);
    for(int i=0; i<n; i++) new_student.grades.push_back(rand()%11);

    cout<<"\nBuvo sugeneruoti tokie "<<n<<" ND pažymiai: ";
    for(int grade: new_student.grades) cout<<grade<<" ";
    new_student.exam_score = rand()%11;
    cout<<"\nIr egzamino rezultatas: "<<new_student.exam_score<<endl;
}

//Ši funkcija nuskaito pažymius iš vartotojo
void input_grades(int &n, Student &new_student)
{
    //jei vartotojas nepasakė kiek turi būti pažymių, jis ves, kol jam pabos
    if(n == -1)
    {
      n = 0;
      cout<<"\nVeskite pažymius (0, 10), kai pabos, parašykite -1"<<endl;
      while(true)
      {
        cout<<"Įveskite "<< n+1 <<" Pažymį: ";
        int grade = input_integer("", "Bandykite vėl (-1 jeigu norite užbaigti): ", "-1", 0, 10);
        if(grade == -1) break; // -1 baigs ciklą
        else new_student.grades.push_back(grade);
        n++;
      }
    }
    //jei vartotojas pasakė kiek turi būti pažymių
    else
    {
      for(int i = 0; i<n; i++)
      {
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
void calculate_final(int grade_num, Student &new_student)
{
  //jeigu yra nd pažymių
  if(grade_num != 0)
  {
    //skaičiuoti per vidurkį
    if(yes_or_no("\nAr norėtumėte skaičiuoti per vidurkį?\n(jei ne, tai per medianą) "))
    {
      int sum = 0;
      new_student.is_mean = true;
      for(int i = 0; i<grade_num; i++) sum+=new_student.grades[i];
      new_student.mean_or_median = (double)sum/grade_num;

    }else //skaičiuoti per medianą
    {
      new_student.is_mean = false;
      std::sort(new_student.grades.begin(), new_student.grades.end());

      //jei nelyginis skaičius namų darbų
      if(grade_num%2 != 0) new_student.mean_or_median = new_student.grades[grade_num / 2];
      //jei lyginis skaičius namų darbų
      else new_student.mean_or_median = ((double)(new_student.grades[grade_num / 2] + 
      new_student.grades[grade_num / 2 - 1]))/2;
    } 
  } else new_student.mean_or_median = 0; //jeigu pažymių iš ND nebuvo

  new_student.final_score = 0.4 * new_student.mean_or_median + 0.6 * new_student.exam_score;
}

int main() {
  srand(time(NULL));

  vector <Student> students;
  students.reserve(10);

  while(true)
  {
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

    calculate_final(grade_num, new_student);
    students.push_back(new_student);
    cout<<"*************************"<<endl;
  }

  //pateikiama ataskaita
  if(students.size() != 0)
  {
    cout<<"\n"<<endl;
    cout<<"Pavardė        "<<"Vardas         "<<"Galutinis (vid)"<<" / "<<"Galutinis(med)"<<endl;
    cout<<string(60, '-')<<endl;
    for(auto student : students)
    {
      cout<<std::left<<setw(15)<<student.name;
      cout<<std::left<<setw(15)<<student.last_name;
      if(student.is_mean) cout<<setw(15)<<std::fixed<<std::setprecision(2)<<student.final_score<<endl;
      else cout<<setw(18)<<""<<setw(15)<<std::fixed<<std::setprecision(2)<<student.final_score<<endl;
    }
  }

}
