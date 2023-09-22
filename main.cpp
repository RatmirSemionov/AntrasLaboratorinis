#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>

using std::cout;
using std::string;
using std::cin;
using std::endl;
using std::vector;
using std::setw;

struct Studentas {
string Vardas, Pavarde;
vector <int> Pazymiai;
int Egzaminas;
float Vidurkis;
double Mediana;
};

int main() {
  Studentas Laikinas;
  vector <Studentas> Grupe;
  int StudentuSkaicius, PazymiuSkaicius;
  char Pasirinktas;
  cout << "Iveskite studentu skaiciu: ";
  cin >> StudentuSkaicius;

  for (int i = 0; i < StudentuSkaicius; i++) {
    cout << "Iveskite studento varda ir pavarde: ";
    cin >> Laikinas.Vardas >> Laikinas.Pavarde;
    cout << "Iveskite pazymiu skaiciu: ";
    cin >> PazymiuSkaicius;
    float PazymiuVidurkis = 0.0;

    for (int j = 0; j < PazymiuSkaicius; j++) {
      int k;
      cout << "Iveskite " << j + 1 << " pazymi: ";
      cin >> k;
      Laikinas.Pazymiai.push_back(k);
      PazymiuVidurkis += k;
    }
    PazymiuVidurkis /= PazymiuSkaicius;

    cout << "Iveskite egzamino pazymi: ";
    cin >> Laikinas.Egzaminas;
    //Galutinio Vidurkio skaiciavimas
    Laikinas.Vidurkis = 0.4*PazymiuVidurkis + 0.6*Laikinas.Egzaminas;
    //Medianos skaiciavimas
    sort(Laikinas.Pazymiai.begin(), Laikinas.Pazymiai.end());
    int vidut = PazymiuSkaicius / 2;
    if (PazymiuSkaicius % 2 == 0) Laikinas.Mediana = (Laikinas.Pazymiai[vidut - 1] +
      Laikinas.Pazymiai[vidut]) / 2.0;
    else Laikinas.Mediana = Laikinas.Pazymiai[vidut];
    Grupe.push_back(Laikinas);
    Laikinas.Pazymiai.clear();
  }
  cout << "Apskaiciuoti Vidurki (V) arba Mediana (M)? --> ";
  cin >> Pasirinktas;
  cout << "--------------------------------------------------" << endl;
  cout << setw(10) << "Vardas " << setw(18) << " Pavarde " << setw(23) << (Pasirinktas == 'V' ? 
    " Galutinis (Vid.) " : " Galutinis (Med.) ") << endl;
  cout << "--------------------------------------------------" << endl;
  cout << std::fixed << std::setprecision(2);
  for (auto &a: Grupe) {
    cout << setw(10) << a.Vardas << setw(18) << a.Pavarde << setw(16) << (Pasirinktas == 'V' ? 
      a.Vidurkis : a.Mediana) << endl;
  }
}
