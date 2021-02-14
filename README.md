# VU_OP_antra_uzduotis
Tai yra studentų pažymių apskaitos programa, leidžianti įvesti arba sugeneruoti studentų įvertinimus tiek už namų darbus, tiek už egzaminą ir pasirinkus skaičiavimo metodiką gauti suformatuotą ataskaitą.

```shell
Pavardė        Vardas         Galutinis (vid) / Galutinis(med)
------------------------------------------------------------
Pranas         Kaisiadorius   3.12           
Matilda        Anastasija                       8.20
```

## Changelog'as
* [v0.1](https://github.com/Miautawn/VU_OP_Uzduotis2/releases/tag/v0.1) - Šioje versijoje jau yra realizuotas skaičių atsitiktinis generavimas ir dinaminis pažymių skaičius, kuris buvo 
įgyvendintas dviem būdais: per C masyvus `main-array.cpp` ir vektorius `main-vector.cpp`.  
Taip pat šioje versijoje galima pasirinkti per ką skaičiuoti galutinius įvertinimus - **vidurkį** ar **medianą**.

## Naudojimosi instrukcija
1. Pridėti studentą įrašant '*y*'  
```shell
>> Ar norite pridėti studentą į apskaitą? y/n: y
```
2. Įvesti vardą ir pavardę  
```shell
>> Prašoma įrašyti studento
>> vardą: Pranas
>> pavardę: Kaisiadorius
```
3. Pasirinkti ar įvesti pažymių skaičių iš anksto 
```shell
>> Ar žinote kiek studentas turi pažymių už ND, y/n: y
>> Kiek (0, 50): 5
```
4. Pasirinkti ar norite atsitiktinai sugeneruoti skaičius
```shell
>> Ar norėtumėte atsitiktinai sugeneruoti pažymius? y/n: y
```
5. Atitinkamai nuo pasirinkimų: įvesti pažymius arba pažiūrėti kas buvo sugeneruota
```shell
>> Buvo sugeneruoti tokie 5 ND pažymiai: 8 7 3 1 5 
>> Ir egzamino rezultatas: 2
```
6. Pasirinkti ar galutinį balą skaičiuoti pagal vidurkį ar medianą
```shell
>> Skaičiuoti per vidurkį - y, ar medianą - n?  y/n: y
```
7. Jei norite gauti ataskaitą, įveskite '*n*'
```shell
>> Ar norite pridėti studentą į apskaitą? y/n: n
```
8. Viskas!
```shell
Pavardė        Vardas         Galutinis (vid) / Galutinis(med)
------------------------------------------------------------
Pranas         Kaisiadorius   3.12           
```

## Instaliavimo instrukcija
Kad pasileisti šią programą reikia atlikti šiuos žingsnius:
1. Atsisiųsti `main-array.cpp` arba `main-vector.cpp` failą kartu su `martyno_lib.h` antraščių failu.
2. Sukompiliuoti ir sulinkinti **.exe** failą su savo pageidaujamais įrankiais, kurie palaikytų **C++11**
3. Pasileisti **.exe** failą ir džiaugtis!
