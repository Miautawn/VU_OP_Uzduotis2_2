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
* [v0.1.1](https://github.com/Miautawn/VU_OP_Uzduotis2/releases/tag/0.1.1) - Ištaisyta klaida, kur studentai `main-array.cpp` faile buvo laikomi vektoriuje, o ne dinaminiame masyve.
* [v0.1.2](https://github.com/Miautawn/VU_OP_Uzduotis2/releases/tag/v0.1.2) - Ištaisyta klaida, kur `main-array.cpp` faile nebuvo išvalomi dinaminiai masyvai.

* [v0.2](https://github.com/Miautawn/VU_OP_Uzduotis2/releases/tag/v0.2) - Šioje versijoje realizuota galimybė nuskaityti studentus ir jų duomenis iš tekstinio failo `kursiokai.txt`, kurio duomenys turi būti išdėstyti tokia tvarka:

  **SVARBU!!!** [v0.3](https://github.com/Miautawn/VU_OP_Uzduotis2/releases/tag/v0.3) versijoje ši funkcija buvo pakeista taip, kad vartotojas gali pats įvesti duomenų failo pavadinimą.

```
Vardas                   Pavarde                    ND1       ND2       ND3       ND4       ND5       ND6       ND7       ND8       ND9      ND10      ND11      ND12      ND13      ND14      ND15      Egz.
Vardas1                 Pavarde1                      8         5         8         3         3         7         3        10         2         3         7         5         6         3         5         3
Vardas2                 Pavarde2                      6         6         5         5         1         8         4         3         3         8         5         4         5         5         5         7
Vardas3                 Pavarde3                      8         3         2         7         7         9         5        10         9         9        10         4         3         3         8         5
Vardas4                 Pavarde4                      7         9         8         9         6         8         8         8         3         9         5         2         5         5         5         1
```

* [v0.3](https://github.com/Miautawn/VU_OP_Uzduotis2/releases/tag/v0.3) - Didelė programos kodo dalis buvo reorganizota ir išskirstyta po failus `Extensions` folderyje. Taip pat buvo implementuota išimčių tvarkymas, kuris turėtų užtikrinti stabilesnį programos veikimą.
* [v0.4](https://github.com/Miautawn/VU_OP_Uzduotis2/releases/tag/v0.4) - Šioje versijoje buvo realizuota "benchmark" funkcija, kuri išmatuos programos veikimo laiką per keletą testų su skirtingais įrašų kiekiais.
* [v0.4.1](https://github.com/Miautawn/VU_OP_Uzduotis2/releases/tag/v0.4.1) - Šioje versijoje buvo pamodifikuota "benchmark" implementacija taip, kad studentų grupių failai būtų generuojami į `Benchmark` folderį.



## Naudojimosi instrukcija
1. Pasirinkti ar norima atlikti "benchmark'ą":
```shell
>> Ar norėtumėte atlikti programos 'benchmark'ą'? y/n:
```
2. Pasirinkti ar nuskaityti duomenis iš failo, ir įvesti failo pavadinimą jei taip:  
```shell
>> Ar norėtumėte nuskaityti studentų duomenis iš failo? y/n: y
>> Iveskite failo pavadinimą: file-name.txt
```
3. Jei ne, pridėti studentą įrašant '*y*'  
```shell
>> Ar norite pridėti studentą į apskaitą? y/n: y
```
4. Įvesti vardą ir pavardę  
```shell
>> Prašoma įrašyti studento
>> vardą: Pranas
>> pavardę: Kaisiadorius
```
5. Pasirinkti ar įvesti pažymių skaičių iš anksto 
```shell
>> Ar žinote kiek studentas turi pažymių už ND, y/n: y
>> Kiek (0, 50): 5
```
6. Pasirinkti ar norite atsitiktinai sugeneruoti skaičius
```shell
>> Ar norėtumėte atsitiktinai sugeneruoti pažymius? y/n: y
```
7. Atitinkamai nuo pasirinkimų: įvesti pažymius arba pažiūrėti kas buvo sugeneruota
```shell
>> Buvo sugeneruoti tokie 5 ND pažymiai: 8 7 3 1 5 
>> Ir egzamino rezultatas: 2
```
8. Pasirinkti ar galutinį balą skaičiuoti pagal vidurkį ar medianą
```shell
>> Skaičiuoti per vidurkį - y, ar medianą - n?  y/n: y
```
9. Jei norite gauti ataskaitą, įveskite '*n*'
```shell
>> Ar norite pridėti studentą į apskaitą? y/n: n
```
10. Viskas!
```shell
Pavardė        Vardas         Galutinis (vid) / Galutinis(med)
------------------------------------------------------------
Pranas         Kaisiadorius   3.12           
```

## Instaliavimo instrukcija
Kad pasileisti šią programą reikia atlikti šiuos žingsnius:
1. Atsisiųsti visą projekto folderį, tačiau `kursiokai.txt` neprivalomas.
2. Galima subuild'inti programos paleidžiamąjį failą rankiniu būdu su jūsų pageidaujamais įrankiais,  
tačiau patariama naudoti `makefile` komandas:
```shell

>> make build         // subuild'ins viską per vieną kartą
>> make build_all     // sulink'ins visus object failus su main.cpp
>> make compile_all   // sukompiliuos visus headerių failus
>> make clean         // išvalys visus object failus
```
*P.S ši programa buvo padaryta su **C++11** standartu*  

3. Pasileisti paleidžiamąjį failą!
