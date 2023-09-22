#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

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
};

int main() {
  Studentas Laikinas;
  vector <Studentas> Grupe;
  int StudentuSkaicius, PazymiuSkaicius;
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
    Grupe.push_back(Laikinas);
  }
  cout << "--------------------------------------------------" << endl;
  cout << setw(10) << "Vardas " << setw(18) << " Pavarde " << setw(23) << " Galutinis (Vid.) " << endl;
  cout << "--------------------------------------------------" << endl;
  cout << std::fixed << std::setprecision(2);
  for (auto &a: Grupe) {
    cout << setw(10) << a.Vardas << setw(18) << a.Pavarde << setw(16) << a.Vidurkis << endl;
  }
}
