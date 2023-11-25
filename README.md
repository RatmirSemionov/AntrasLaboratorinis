# AntrasLaboratorinis

V0.1 -
Buvo sukurta studentu struktura, kuri turi studentu varda, pavarde,
namu darbu pažymius, egzamino pažymi. 
Realizuotas manualus duomenų ivedimas,
po kurio suskaičiuojamas studentu pažymiu galutinis balas arba mediana.
Pridėtas
pasirinkimas ar vartotojas žino kiek namu darbu turi studentas, taip pat realizuotas
atsitiktinis pažymiu generavimas.

V.pradinė -
Pridėta galimybė nuskaityti duomenis iš failo. Failo atvėju, rezultatu išvedimas
yra siunčiamas į kita faila.
Pridėta galimybė surušiuot studentus pagal vardus arba
pavardes. 
Programa yra padalinta į source failus ir į header failus, taip pat naudojamas
išimčių valdymas.

V0.2 -
Realizuotas studentu failu generavimas, kur galima pasirinkt kiek studentu duomenu
generuot, pasirinkt kiek namu darbu jie turi.
Tikslas buvo sukurt 5 failus sudarytus
iš: 1000, 10000, 100000, 1000000, 10000000 įrašų. 
Studentai iš failų yra dalinami
į dvi kategorijas: Studentai su galutinį balą < 5.0 yra vargščiukai, o studentai
su galutinį balą >= 5.0 yra galvočiai.
Realizuotos matavimo laikai, sumatuotas failo
kūrimas, duomenų nuskaitymas iš failų, studentų dalinimas į kategorijas, sūrušiuotų
studentų išvedimas į du naujus failus.
Studentai taip pat gali but rušiuojami pagal
pasirinkta parametra: Varda, Pavarde arba Vidurki.

V0.3 -
Buvo atliekamas projekto testavimas pakeičiant konteineri iš vector į list.
Laiko matavimai atliekami taip pat, pateiktos sistemos parametrai ir testavimo
vidurkiu rezultatai su 
prieš tai sugeneruotais failais vector ir list atveju.
Rankiniu ivedimui buvo pridėtas atminties adresas, kad galima būtų matyt kur
duomenis yra saugomi.

V1.0 -
Buvo analizuotas studentu dalinimas į kategorijas, bandant pritaikyt skirtingas
kategorijas, siekiant pamatyti, kuri strategija veikia greičiau ir kiek atminties
užima. 
Sudarant dvi strategijas, pasirenkama grečiausia iš jų ir yra patobulinta
naudojant algoritmus. 
Vector ir List atveju pateiktos lentelės su studentu dalinimo
į kategorijas pagal strategijas testu vidurkiai, taip pat atminties matavimai nuotraukomis.
Yra paruoštas cmake failas, įdiegimo ir paleidimo proceso instrukciją.

V1.1 -
Vietoj strukturos kodui buvo panaudota klasę, buvo padaryti pakeitimai visame kode kad jis
veiktu su class. Buvo atliktas palyginimas tarp strukturos ir klases, naudojant 100000 ir
1000000 failus, taip pat greičiausia dalinimo strategija. Be to, dar buvo atlikti
testavimai naudojant flagus O1,O2,O3 tam, kad pamatyt kaip jie optimizuoja koda.


Naudojimosi instrukcija:

1. Norint sugeneruoti studentu faila, reikia pasirinkt T - taip, ivesti
kiek studentu duomenu jus norite sugeneruot, po to ivesti kiek namu darbu
turi studentai. Parasyt failo pavadinima i kuri norite sugeneruoti duomenis.
Jei norite padalint studentus i dvi kategorijas, pasirinkt T - taip, jei ne,
bus sukurtas failas be dalinimo. Jei pasirinkote padalint studentus, reikes vel
ivest failo pavadinima i kuri buvo sugeneruotos duomenis. Po to bus pasirinkimas
surusiuot studentus pagal parametrus - Varda, Pavarde, Vidurki, arba nerusiuot.
Po pasirinkusio rusiavimo metodo reikės pasirinkt viena iš triju strategiju pagal
kuri studentai bus padalinami į dvi kategorijas. Padalinimui reikės ivest failu
pavadinimus į kurias bus idėtos padalintos studentai.

2. Norint padaryt laiko matavimus su jau sukurta studentu faila, pasirinkt J - jau
turim faila. Pasirinkt ar norite rušiuot studentus pagal pasirinkta parametra(Varda,
Pavarde arba Vidurki). Po to reikės pasirinkt studentu dalinimo strategija pagal kuri
bus dalinami studentai į dvi kategorijas ir ivest failo pavadinimus į kurias bus idėtos
rezultatai. Gausite to failo laiko matavimus.

3. Norint ivest studentu duomenis rankiniu būdų arba iš failo, pasirinkt N - ne.
Jeigu pasirinksite varianta M - manualiai, galesite ivest kiek studentu duomenis jus
norite irašyt rankiniu būdų, po to galesite ivest studentu varda ir pavarde. Pažymiu
ivedimui irgi yra pasirinkimas, ar jus norit patys surašyt pažymius ar sugeneruot pažymius
atsitiktinai. Jei pasirinkt manuali ivedimą, galesite ivest pažymiu skaičiu, arba
parašyt q norint ivesti pažymius be apribojimu ir baigt pažymiu ivedima vėl parašant q.
Jei pasirinksite automatiška pažymiu ivedimą, bus pasirinkimas ar jus žinote kiek
pažymiu sugeneruot arba ne. Taip pat ir su egzamino pažymi, reikės pasirinkt ar norite
patys ivest pažymi arba sugeneruot. Galiausiai bus pasirinkimas, ar jus norite
apskaičiuot studentu pažymiu vidurki arba mediana. Rezultatas bus rodomas pagal
pasirinkta apskaičiavima, taip pat bus rodomas atminties adresas.


Sistemos parametrai: Intel(R) Celeron(R) CPU 5205U @ 1.90GHz, RAM: 8.00GB, SSD: 225GB.

Testavimo vidurkiai su vector:
| Testavimas                    |      1000      |     10000     |     100000    |     1000000    |     10000000    |
|-------------------------------|:--------------:|:-------------:|:-------------:|:--------------:|:---------------:|
| Failo Nuskaitymas             |  0.00474288 s. | 0.07705792 s. |  0.8252412 s. |   7.056874 s.  |   74.33216 s.   |
| Sort() veiksmas               | 0.000142492 s. |  0.0195622 s. |  0.3513392 s. |   4.145426 s.  |   53.74884 s.   |
| Padalijimas į dvi kategorijas |  0.00250514 s. | 0.00430474 s. | 0.06608228 s. |  0.6064022 s.  |   7.690488 s.   |
| Rašymas į vargščiukų failą    |  0.00150928 s. |  0.0168969 s. |  0.152845 s.  |   1.611866 s.  |   20.86688 s.   |
| Rašymas į galvočių failą      |      0 s.      |  0.0112793 s. |  0.1410478 s. |   1.439764 s.  |   18.45458 s.   |
| Bendras Matavimas             |  0.0087573 s.  | 0.10953886 s. | 1.18521492 s. | 10.71491118 s. | 121.34410962 s. |

Testavimo vidurkiai su list:
| Testavimas                    |      1000     |     10000     |     100000    |     1000000    |     10000000    |
|-------------------------------|:-------------:|:-------------:|:-------------:|:--------------:|:---------------:|
| Failo Nuskaitymas             | 0.01488534 s. |  0.1997474 s. |   1.82044 s.  |   14.68788 s.  |   162.1624 s.   |
| Sort() veiksmas               | 0.00067264 s. | 0.01067096 s. |  0.1998048 s. |   2.393176 s.  |    30.1942 s.   |
| Padalijimas į dvi kategorijas | 0.00131578 s. |  0.017916 s.  |  0.214513 s.  |   1.857508 s.  |   23.35872 s.   |
| Rašymas į vargščiukų failą    |  0.0013564 s. |  0.0168339 s. |  0.1614352 s. |   1.86077 s.   |   29.62158 s.   |
| Rašymas į galvočių failą      | 0.00060234 s. | 0.01614728 s. |  0.1765102 s. |   1.70107 s.   |   15.65226 s.   |
| Bendras Matavimas             | 0.01815986 s. | 0.25064478 s. | 2.37290326 s. | 20.50723126 s. | 230.79486618 s. |

Studentu dalinimo i kategorijas testavimo vidurkiai pagal strategijas:
| Testavimas su Vector |      1000     |     10000     |     100000    |    1000000   |   10000000   |
|:--------------------:|:-------------:|:-------------:|:-------------:|:------------:|:------------:|
| 1 Strategija         | 0.00250514 s. | 0.00430474 s. | 0.06608228 s. | 0.6064022 s. |  7.690488 s. |
| 2 Strategija         | 0.00177476 s. | 0.03419008 s. | 0.62716634 s. |  6.618906 s. |  70.21366 s. |
| 3 Strategija         | 0.00202814 s. |  0.0021994 s. | 0.03989024 s. | 0.4955056 s. |  4.697758 s. |

| Testavimas su List |      1000     |     10000     |    100000    |   1000000   |   10000000  |
|:------------------:|:-------------:|:-------------:|:------------:|:-----------:|:-----------:|
| 1 Strategija       | 0.00131578 s. |  0.017916 s.  |  0.214513 s. | 1.857508 s. | 23.35872 s. |
| 2 Strategija       |  0.0023217 s. | 0.02404208 s. |  0.425756 s. |  4.59005 s. | 49.89908 s. |
| 3 Strategija       | 0.00220356 s. | 0.01183548 s. | 0.1963102 s. | 1.821548 s. |  18.0035 s. |



V1.1:
Struct ir Class vektoriaus atveju testavimo rezultatai naudojant greičiausia dalijimo strategija:
|         Vector(Struct)        |     100000    |    1000000    |         Vector(Class)         |     100000    |    1000000   |
|:-----------------------------:|:-------------:|:-------------:|:-----------------------------:|:-------------:|:------------:|
|       Failo Nuskaitymas       | 1.07586886 s. |  7.5074866 s. |       Failo Nuskaitymas       |  1.734298 s.  |  15.05332 s. |
|        Sort() veiksmas        |  0.4211282 s. |  4.860546 s.  |        Sort() veiksmas        |  0.4335954 s. |  4.842296 s. |
| Padalijimas į dvi kategorijas |  0.0383447 s. |  0.4194998 s. | Padalijimas į dvi kategorijas | 0.03993036 s. | 0.4644954 s. |
|   Rašymas į vargščiukų failą  |  0.1644058 s. |  1.713978 s.  |   Rašymas į vargščiukų failą  |  0.1677366 s. |  1.848376 s. |
|    Rašymas į galvočių failą   |  0.1898104 s. |  1.7326022 s. |    Rašymas į galvočių failą   |  0.180565 s.  | 1.6300066 s. |
|       Bendras Matavimas       | 1.34658872 s. | 11.3739598 s. |       Bendras Matavimas       |  2.1229318 s. | 18.777604 s. |


Struct vektoriaus atveju testavimo su flagais rezultatai:
|         Vector(Struct)        |   100000 O1   |   100000 O2   |   100000 O3   |  1000000 O1  |   1000000 O2  |   1000000 O3  |
|:-----------------------------:|:-------------:|:-------------:|:-------------:|:------------:|:-------------:|:-------------:|
|       Failo Nuskaitymas       |  0.5864872 s. |  0.489574 s.  |  0.5502432 s. |  4.770758 s. |   4.86836 s.  |   4.76179 s.  |
|        Sort() veiksmas        | 0.03821272 s. | 0.04754054 s. | 0.04019078 s. |  0.553845 s. |  0.5296582 s. |  0.5478884 s. |
| Padalijimas į dvi kategorijas | 0.00309958 s. | 0.01654182 s. | 0.01009942 s. | 0.1715242 s. |  0.1648226 s. |  0.1734082 s. |
|   Rašymas į vargščiukų failą  |  0.1477234 s. |  0.1235406 s. |  0.1655452 s. |  1.675816 s. |  1.673498 s.  |  1.625244 s.  |
|    Rašymas į galvočių failą   |  0.1347786 s. |  0.122209 s.  |  0.1418554 s. |  1.483072 s. |  1.519442 s.  |  1.612124 s.  |
|       Bendras Matavimas       |  0.8724888 s. |  0.7520647 s. |  0.8687435 s. | 8.1003724 s. | 8.42513456 s. | 8.17276554 s. |


Class vektoriaus atveju testavimo su flagais rezultatai:
|         Vector(Class)         |   100000 O1   |   100000 O2  |   100000 O3  |   1000000 O1  |   1000000 O2  |   1000000 O3  |
|:-----------------------------:|:-------------:|:------------:|:------------:|:-------------:|:-------------:|:-------------:|
|       Failo Nuskaitymas       |  0.8976846 s. | 0.9803412 s. | 0.9535538 s. |   8.57903 s.  |   8.11724 s.  |  7.907724 s.  |
|        Sort() veiksmas        |  0.1676326 s. |  0.145493 s. | 0.1531744 s. |  2.155316 s.  |  1.842976 s.  |  2.447388 s.  |
| Padalijimas į dvi kategorijas |  0.0086956 s. | 0.0174011 s. | 0.0153462 s. |  0.2031724 s. |  0.1749414 s. |  0.2175004 s. |
|   Rašymas į vargščiukų failą  |  0.154668 s.  | 0.1381002 s. |  0.154413 s. |  1.6706524 s. |   2.00579 s.  |  1.858334 s.  |
|    Rašymas į galvočių failą   |  0.1401796 s. | 0.1439824 s. | 0.1701494 s. |   1.7042 s.   |   1.90836 s.  |   1.73408 s.  |
|       Bendras Matavimas       | 1.20022848 s. | 1.2608231 s. | 1.2946622 s. | 12.3972582 s. | 12.4063556 s. | 11.7184282 s. |
