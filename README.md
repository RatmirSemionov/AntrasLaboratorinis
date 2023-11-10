# PirmasLaboratorinis

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
