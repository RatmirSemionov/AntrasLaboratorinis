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
    vector<int> Pazymiai;
    int Egzaminas;
    float Vidurkis;
    double Mediana;
};

int main() {
    Studentas Laikinas;
    vector<Studentas> Grupe;
    int StudentuSkaicius, PazymiuSkaicius;
    char Pasirinktas;

    cout << "Iveskite studentu skaiciu: ";
    cin >> StudentuSkaicius;

    for (int i = 0; i < StudentuSkaicius; i++) {
        cout << "Iveskite studento varda ir pavarde: ";
        cin >> Laikinas.Vardas >> Laikinas.Pavarde;

        cout << "Iveskite pazymiu skaiciu (arba -1, jei norite ivesti pazymius be apribojimu): ";
        cin >> PazymiuSkaicius;

        if (PazymiuSkaicius == -1) {
            cout << "Iveskite pazymius. Baigti ivedineti pazymius galite suvede '-1'." << endl;
            int Numeris = 1;
            while (true) {
                int k;
                cout << "Iveskite " << Numeris << " pazymi: ";
                cin >> k;
                if (k == -1) {
                    break;
                }
                Laikinas.Pazymiai.push_back(k);
                Numeris++;
            }
        } else {
            for (int j = 0; j < PazymiuSkaicius; j++) {
                int k;
                cout << "Iveskite " << j + 1 << " pazymi: ";
                cin >> k;
                Laikinas.Pazymiai.push_back(k);
            }
        }

        cout << "Iveskite egzamino pazymi: ";
        cin >> Laikinas.Egzaminas;

        // Galutinio Vidurkio skaiciavimas
        float PazymiuVidurkis = 0.0;
        for (int j = 0; j < Laikinas.Pazymiai.size(); j++) {
            PazymiuVidurkis += Laikinas.Pazymiai[j];
        }
        if (!Laikinas.Pazymiai.empty()) {
            PazymiuVidurkis /= Laikinas.Pazymiai.size();
        }
        Laikinas.Vidurkis = 0.4 * PazymiuVidurkis + 0.6 * Laikinas.Egzaminas;

        // Medianos skaiciavimas
        sort(Laikinas.Pazymiai.begin(), Laikinas.Pazymiai.end());
        int vidut = Laikinas.Pazymiai.size() / 2;
        if (Laikinas.Pazymiai.size() % 2 == 0) {
            Laikinas.Mediana = (Laikinas.Pazymiai[vidut - 1] + Laikinas.Pazymiai[vidut]) / 2.0;
        } else {
            Laikinas.Mediana = Laikinas.Pazymiai[vidut];
        }
        Grupe.push_back(Laikinas);
        Laikinas.Pazymiai.clear();
    }

    cout << "Apskaciuoti Vidurki (V) arba Mediana (M)? -> ";
    cin >> Pasirinktas;
    cout << "--------------------------------------------------" << endl;
    cout << setw(10) << "Vardas " << setw(18) << " Pavarde " << setw(23) << (Pasirinktas == 'V' ? " Galutinis (Vid.) " : " Galutinis (Med.) ") << endl;
    cout << "--------------------------------------------------" << endl;
    cout << std::fixed << std::setprecision(2);
    for (auto &a : Grupe) {
        cout << setw(10) << a.Vardas << setw(18) << a.Pavarde << setw(16) << (Pasirinktas == 'V' ? a.Vidurkis : a.Mediana) << endl;
    }
}
