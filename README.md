# VU_OP_antra_uzduotis
Tai yra studentų pažymių apskaitos programa, leidžianti įvesti arba sugeneruoti studentų įvertinimus tiek už namų darbus, tiek už egzaminą ir pasirinkus skaičiavimo metodiką gauti suformatuotą ataskaitą.

```shell
Pavardė        Vardas         Galutinis (vid) / Galutinis(med)
------------------------------------------------------------
Pranas         Kaisiadorius   3.12           
Matilda        Anastasija                       8.20
```

## Changelog'as
* [v0.1]() - Šioje versijoje jau yra realizuotas skaičių atsitiktinis generavimas ir dinaminis pažymių skaičius, kuris buvo 
įgyvendintas dviem būdais: per C masyvus `main-array.cpp` ir vektorius `main-vector.cpp`.  
Taip pat šioje versijoje galima pasirinkti per ką skaičiuoti galutinius įvertinimus - **vidurkį** ar **medianą**.
* [v0.1.1]() - Ištaisyta klaida, kur studentai `main-array.cpp` faile buvo laikomi vektoriuje, o ne dinaminiame masyve.

* [v0.2]() - Šioje versijoje realizuota galimybė nuskaityti studentus ir jų duomenis iš tekstinio failo `kursiokai.txt`.  
Patys duomenys turi būti išdėstyti tokia tvarka:
```
Vardas                   Pavarde                    ND1       ND2       ND3       ND4       ND5       ND6       ND7       ND8       ND9      ND10      ND11      ND12      ND13      ND14      ND15      Egz.
Vardas1                 Pavarde1                      8         5         8         3         3         7         3        10         2         3         7         5         6         3         5         3
Vardas2                 Pavarde2                      6         6         5         5         1         8         4         3         3         8         5         4         5         5         5         7
Vardas3                 Pavarde3                      8         3         2         7         7         9         5        10         9         9        10         4         3         3         8         5
Vardas4                 Pavarde4                      7         9         8         9         6         8         8         8         3         9         5         2         5         5         5         1
```

## Naudojimosi instrukcija
1. Pasirinkti ar nuskaityti duomenis iš failo `kursiokai.txt`:  
*P.S.* Šio pasirinkimo nebus, jei `kursiokai.txt` nebus rastas paleidimo foldery.
```shell
>> Ar norėtumėte nuskaityti studentų duomenis iš failo? y/n:
```
2. Jei ne, pridėti studentą įrašant '*y*'  
```shell
>> Ar norite pridėti studentą į apskaitą? y/n: y
```
3. Įvesti vardą ir pavardę  
```shell
>> Prašoma įrašyti studento
>> vardą: Pranas
>> pavardę: Kaisiadorius
```
4. Pasirinkti ar įvesti pažymių skaičių iš anksto 
```shell
>> Ar žinote kiek studentas turi pažymių už ND, y/n: y
>> Kiek (0, 50): 5
```
5. Pasirinkti ar norite atsitiktinai sugeneruoti skaičius
```shell
>> Ar norėtumėte atsitiktinai sugeneruoti pažymius? y/n: y
```
6. Atitinkamai nuo pasirinkimų: įvesti pažymius arba pažiūrėti kas buvo sugeneruota
```shell
>> Buvo sugeneruoti tokie 5 ND pažymiai: 8 7 3 1 5 
>> Ir egzamino rezultatas: 2
```
7. Pasirinkti ar galutinį balą skaičiuoti pagal vidurkį ar medianą
```shell
>> Skaičiuoti per vidurkį - y, ar medianą - n?  y/n: y
```
8. Jei norite gauti ataskaitą, įveskite '*n*'
```shell
>> Ar norite pridėti studentą į apskaitą? y/n: n
```
9. Viskas!
```shell
Pavardė        Vardas         Galutinis (vid) / Galutinis(med)
------------------------------------------------------------
Pranas         Kaisiadorius   3.12           
```

## Instaliavimo instrukcija
Kad pasileisti šią programą reikia atlikti šiuos žingsnius:
1. Atsisiųsti `main.cpp` failą kartu su `martyno_lib.h` antraščių failu. `kursiokai.txt` neprivalomas.
2. Sukompiliuoti ir sulinkinti **.exe** failą su savo pageidaujamais įrankiais, kurie palaikytų **C++11**
3. Pasileisti **.exe** failą ir džiaugtis!
