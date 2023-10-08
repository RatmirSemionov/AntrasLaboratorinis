#include "mylib.h"

int main() {
    Studentas Laikinas;
    vector<Studentas> Grupe;
    char Pasirinktas;
    char Pasirinkimas2;
    string inputFileName;
    string outputFileName;
    ofstream outputFile;
    char FailoGeneravimas;
    //Ar norim sugeneruot faila
    cout << "Ar norite sugeneruot studentu faila? (T - taip, N - ne): ";
    cin >> FailoGeneravimas;
    if (FailoGeneravimas == 'T') {
        int studentCount;
        string filename;
        cout << "Iveskite kiek studentu duomenis norite sugeneruoti: ";
        cin >> studentCount;
        cout << "Iveskite failo pavadinima i kuri norite sugeneruoti duomenis: ";
        cin >> filename;
        SukurtiStudentoFaila(studentCount, filename);
        cout << "Studentu duomenis sugeneruoti i faila " << filename << endl;
        return 1;
    }
    else if (FailoGeneravimas == 'N') {
    //Kaip gausim duomenis
    cout << "Kaip norite ivesti duomenis? (M - manualiai, F - is failo): ";
    cin >> Pasirinkimas2;
    if (Pasirinkimas2 != 'M' && Pasirinkimas2 != 'F') {
        cout << "Klaida. Netinkamas ivedimas, programa baigiasi." << endl;
        return 1;
    }
    //Nuskaitymas is failo
    if (Pasirinkimas2 == 'F') {
        FailoSkaitymas(Grupe);
        RezultatoFailas(outputFile);
    //Manualus ivedimas
    } else if (Pasirinkimas2 == 'M') {
        StudentuInfo(Laikinas, Grupe);
    }

    // Studentu rusiavimas
    sort(Grupe.begin(), Grupe.end(), Rusiavimas);

    std::ostream &output = (Pasirinkimas2 == 'F') ? outputFile : cout;
    //Pasirinkimas ka apskaiciuot
    cout << "Apskaciuoti Vidurki (V) arba Mediana (M)? -> ";
    cin >> Pasirinktas;
    if (Pasirinktas != 'V' && Pasirinktas != 'M') {
        cout << "Klaida. Netinkamas ivedimas, programa baigiasi" << endl;
        return 1;
    }
    output << "--------------------------------------------------" << endl;
    output << setw(17) << left << "Vardas " << setw(15) << left << " Pavarde " << setw(15) << (Pasirinktas == 'V' ? " Galutinis (Vid.) " : " Galutinis (Med.) ") << endl;
    output << "--------------------------------------------------" << endl;
    output << std::fixed << std::setprecision(2);
    for (auto &a : Grupe) {
        output << setw(18) << left << a.Vardas << setw(20) << left << a.Pavarde << setw(15) << (Pasirinktas == 'V' ? a.Vidurkis : a.Mediana) << endl;
    }
    }
}
