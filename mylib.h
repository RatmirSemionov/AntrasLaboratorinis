#ifndef MYLIB_H_INCLUDED
#define MYLIB_H_INCLUDED

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <sstream>
#include <cctype>
#include <ios>

using std::cout;
using std::string;
using std::cin;
using std::endl;
using std::vector;
using std::setw;
using std::ifstream;
using std::istringstream;
using std::ofstream;
using std::left;

struct Studentas {
    string Vardas, Pavarde;
    vector<int> Pazymiai;
    int Egzaminas;
    float Vidurkis;
    double Mediana;
};

bool Rusiavimas(const Studentas& a, const Studentas& b);
void Vidurkis(Studentas& Laikinas);
void Mediana(Studentas& Laikinas);
void FailoSkaitymas(vector<Studentas>& Grupe);
void RezultatoFailas(ofstream& outputFile);
void EgzaminoPazymis(Studentas& Laikinas);
void PazymiuGeneravimas(Studentas& Laikinas);
void PazymiuIvedimas(Studentas& Laikinas);
void StudentuInfo(Studentas& Laikinas, vector<Studentas>& Grupe);
#endif // MYLIB_H_INCLUDED