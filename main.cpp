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

//Rusiavimo funkcija
bool Rusiavimas(const Studentas& a, const Studentas& b) {
    size_t i = 0, j = 0;
    while (i < a.Vardas.size() && j < b.Vardas.size()) {
        if (isdigit(a.Vardas[i]) && isdigit(b.Vardas[j])) {
            int numA = 0, numB = 0;
            while (i < a.Vardas.size() && isdigit(a.Vardas[i])) {
                numA = numA * 10 + (a.Vardas[i] - '0');
                i++;
            }
            while (j < b.Vardas.size() && isdigit(b.Vardas[j])) {
                numB = numB * 10 + (b.Vardas[j] - '0');
                j++;
            }
            if (numA != numB)
                return numA < numB;
        }
        else {
            if (a.Vardas[i] != b.Vardas[j])
                return a.Vardas[i] < b.Vardas[j];
            i++;
            j++;
        }
    }
    return a.Vardas.size() < b.Vardas.size();
}

int main() {
    Studentas Laikinas;
    vector<Studentas> Grupe;
    int StudentuSkaicius, PazymiuSkaicius;
    char Pasirinktas;
    char Pasirinkimas;
    char Pasirinkimas2;
    char PazymiuPasirinkimas;
    string inputFileName;
    string outputFileName;
    ofstream outputFile;

    cout << "Kaip norite ivesti duomenis? (M - manualiai, F - is failo): ";
    cin >> Pasirinkimas2;

    if (Pasirinkimas2 == 'F') {
        cout << "Iveskite failo pavadinima: ";
        cin >> inputFileName;
        ifstream inputFile(inputFileName);

        if (!inputFile.is_open()) {
            cout << "Nepavyko atidaryti faila: " << inputFileName << endl;
            return 1;
        }

        string line;
        getline(inputFile, line); // Perskaityt header linija ir pasalint ji
        while (getline(inputFile, line)) {
            istringstream iss(line);
            iss >> Laikinas.Vardas >> Laikinas.Pavarde;

            int pazymys;
            while (iss >> pazymys) {
                Laikinas.Pazymiai.push_back(pazymys);
            }
            Laikinas.Egzaminas = Laikinas.Pazymiai.back();
            Laikinas.Pazymiai.pop_back();

            // Skaiciavimas
            float PazymiuVidurkis = 0.0;
            for (int j = 0; j < Laikinas.Pazymiai.size(); j++) {
                PazymiuVidurkis += Laikinas.Pazymiai[j];
            }
            if (!Laikinas.Pazymiai.empty()) {
                PazymiuVidurkis /= Laikinas.Pazymiai.size();
            }
            //Galutinio Vidurkio skaiciavimas
            Laikinas.Vidurkis = 0.4 * PazymiuVidurkis + 0.6 * Laikinas.Egzaminas;
            //Medianos skaiciavimas
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
        inputFile.close();

        cout << "Iveskite rezultatu failo pavadinima: ";
        cin >> outputFileName;
        outputFile.open(outputFileName);

        if (!outputFile.is_open()) {
            cout << "Nepavyko atidaryti rezultatu faila: " << outputFileName << endl;
            return 1;
        }

    } else if (Pasirinkimas2 == 'M') {
        cout << "Iveskite studentu skaiciu: ";
        cin >> StudentuSkaicius;

        srand(time(0));

        for (int i = 0; i < StudentuSkaicius; i++) {
            cout << "Iveskite studento varda ir pavarde: ";
            cin >> Laikinas.Vardas >> Laikinas.Pavarde;
            //Pasirinkimas kaip gausim duomenis apie pazymius(Ivedimo metodu arba generuojamu)
            cout << "Pasirinkite kaip ivesite pazymius (M - manualiai, A - automatiskai): ";
            cin >> Pasirinkimas;

            if (Pasirinkimas == 'A') {
                    cout << "Ar zinote, kiek pazymiu reikia sugeneruot? (T - taip, N - ne) ";
                    cin >> PazymiuPasirinkimas;
                    if (PazymiuPasirinkimas == 'T') {
                    cout << "Iveskite generuojamu pazymiu skaiciu: ";
                    cin >> PazymiuSkaicius;
                    }
                    else if (PazymiuPasirinkimas == 'N') {
                        PazymiuSkaicius = rand() % 11;
                    }

                for (int j = 0; j < PazymiuSkaicius; j++) {
                    int RandPazymis = rand() % 11;
                    Laikinas.Pazymiai.push_back(RandPazymis);
                }
            } else if (Pasirinkimas == 'M') {
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
            }
            //Pasirinkimas kaip gausim egzamino pazymi(Ivedimo metodu arba generuojamu)
            cout << "Pasirinkite kaip ivesite egzamino pazymi (M - manualiai, A - automatiskai): ";
            cin >> Pasirinkimas;

            if (Pasirinkimas == 'A') {
                Laikinas.Egzaminas = rand() % 11;
            } else if (Pasirinkimas == 'M') {
                cout << "Iveskite egzamino pazymi: ";
                cin >> Laikinas.Egzaminas;
            }
            float PazymiuVidurkis = 0.0;
            for (int j = 0; j < Laikinas.Pazymiai.size(); j++) {
                PazymiuVidurkis += Laikinas.Pazymiai[j];
            }
            if (!Laikinas.Pazymiai.empty()) {
                PazymiuVidurkis /= Laikinas.Pazymiai.size();
            }
            //Galutinio Vidurkio skaiciavimas
            Laikinas.Vidurkis = 0.4 * PazymiuVidurkis + 0.6 * Laikinas.Egzaminas;
            //Medianos skaiciavimas
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
    }

    // Studentu rusiavimas
    std::sort(Grupe.begin(), Grupe.end(), Rusiavimas);

    std::ostream &output = (Pasirinkimas2 == 'F') ? outputFile : cout;

    cout << "Apskaciuoti Vidurki (V) arba Mediana (M)? -> ";
    cin >> Pasirinktas;
    output << "--------------------------------------------------" << endl;
    output << setw(17) << left << "Vardas " << setw(15) << left << " Pavarde " << setw(15) << (Pasirinktas == 'V' ? " Galutinis (Vid.) " : " Galutinis (Med.) ") << endl;
    output << "--------------------------------------------------" << endl;
    output << std::fixed << std::setprecision(2);
    for (auto &a : Grupe) {
        output << setw(18) << left << a.Vardas << setw(20) << left << a.Pavarde << setw(15) << (Pasirinktas == 'V' ? a.Vidurkis : a.Mediana) << endl;
    }
}
