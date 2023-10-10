#include "mylib.h"
double ElapsedTime1 = 0, ElapsedTime2 = 0, ElapsedTime3 = 0;
//Rusiavimo funkcija
bool Rusiavimas(const Studentas& a, const Studentas& b) {

    string strA = a.Vardas;
    string strB = b.Vardas;

    if(strA == strB) { // Jeigu vardai vienodi, palyginam pagal pavarde
         strA = a.Pavarde;
         strB = b.Pavarde;
    }

    size_t i = 0, j = 0;
    while (i < strA.size() && j < strB.size()) {
        if (isdigit(strA[i]) && isdigit(strB[j])) {
            int numA = 0, numB = 0;
            while (i < strA.size() && isdigit(strA[i])) {
                numA = numA * 10 + (strA[i] - '0');
                i++;
            }
            while (j < strB.size() && isdigit(strB[j])) {
                numB = numB * 10 + (strB[j] - '0');
                j++;
            }
            if (numA != numB)
                return numA < numB;
        }
        else {
            if (strA[i] != strB[j])
                return strA[i] < strB[j];
            i++;
            j++;
        }
    }
    return strA.size() < strB.size();
}
//Vidurkio Skaciavimas
void Vidurkis(Studentas& Laikinas) {
    float PazymiuVidurkis = 0.0;
    for (int j = 0; j < Laikinas.Pazymiai.size(); j++) {
        PazymiuVidurkis += Laikinas.Pazymiai[j];
    }
    if (!Laikinas.Pazymiai.empty()) {
        PazymiuVidurkis /= Laikinas.Pazymiai.size();
    }
    Laikinas.Vidurkis = 0.4 * PazymiuVidurkis + 0.6 * Laikinas.Egzaminas;
}
//Medianos Skaiciavimas
void Mediana(Studentas& Laikinas) {
    sort(Laikinas.Pazymiai.begin(), Laikinas.Pazymiai.end());
    int vidut = Laikinas.Pazymiai.size() / 2;
    if (Laikinas.Pazymiai.size() % 2 == 0) {
        Laikinas.Mediana = (Laikinas.Pazymiai[vidut - 1] + Laikinas.Pazymiai[vidut]) / 2.0;
    } else {
        Laikinas.Mediana = Laikinas.Pazymiai[vidut];
    }
}
//Duomenu nuskaitymas is failo(Pavadinimus rasyt su .txt, pvz. studentai10000.txt)
void FailoSkaitymas(vector<Studentas>& Grupe) {
    string inputFileName;
    cout << "Jusu aplankale esantis teksto failas: " << endl;
    system("dir *.txt");
    cout << "Iveskite failo pavadinima: ";
    cin >> inputFileName;
    ifstream inputFile(inputFileName);

    auto start = std::chrono::high_resolution_clock::now();
    if (!inputFile.is_open()) {
        cout << "Nepavyko atidaryti faila: " << inputFileName << endl;
        exit(1);
    }

    Studentas Laikinas;
    string line;
    getline(inputFile, line); // Ignoruojam header linija
    while (getline(inputFile, line)) {
        istringstream iss(line);
        iss >> Laikinas.Vardas >> Laikinas.Pavarde;

        string value;
        while (iss >> value) {
            if (all_of(value.begin(), value.end(), ::isdigit)) {
                int pazymys = std::stoi(value);
                Laikinas.Pazymiai.push_back(pazymys);
            }
        }

        if (!Laikinas.Pazymiai.empty()) {
            Laikinas.Egzaminas = Laikinas.Pazymiai.back();
            Laikinas.Pazymiai.pop_back();
        } else {
            continue;
        }

        // Skaiciavimas
        Vidurkis(Laikinas);
        Mediana(Laikinas);

        Grupe.push_back(Laikinas);
        Laikinas.Pazymiai.clear();
    }
    inputFile.close();
    auto finish = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed1 = finish - start;
    ElapsedTime1 = elapsed1.count();
    cout << "Failo nuskaitymo laikas: " << elapsed1.count() << " sekundziu" << endl;
}
//Failo funkcija, kuriame bus rezultatai(Failo pavadinima rasyt su .txt, pvz. rezultatai.txt)
void RezultatoFailas(ofstream& outputFile) {
    string outputFileName;
    cout << "Iveskite rezultatu failo pavadinima: ";
    cin >> outputFileName;

    outputFile.open(outputFileName);

    if (!outputFile.is_open()) {
        cout << "Nepavyko atidaryti rezultatu faila: " << outputFileName << endl;
        exit(1);
    }
}
//Egzamino pazymio ivedimo funkcija
void EgzaminoPazymis(Studentas& Laikinas) {
    char Pasirinkimas;
    cout << "Pasirinkite kaip ivesite egzamino pazymi (M - manualiai, A - automatiskai): ";
            cin >> Pasirinkimas;

            if (Pasirinkimas != 'M' && Pasirinkimas != 'A') {
                cout << "Klaida. Netinkamas ivedimas, programa baigiasi." << endl;
                exit(1);
            }

            if (Pasirinkimas == 'A') {
                Laikinas.Egzaminas = rand() % 11;
                cout << "Sugeneruotas egzamino pazymis: " << Laikinas.Egzaminas << '\n';
            } else if (Pasirinkimas == 'M') {
                cout << "Iveskite egzamino pazymi: ";
                cin >> Laikinas.Egzaminas;
                if (cin.fail() || Laikinas.Egzaminas < 0 || Laikinas.Egzaminas > 10) {
                    cout << "Klaida. Netinkamas ivedimas, programa baigiasi" << endl;
                    exit(1);
                }
            }
}

//Pazymiu generavimo funkcija
void PazymiuGeneravimas(Studentas& Laikinas) {
    char PazymiuPasirinkimas;
    int PazymiuSkaicius;
    cout << "Ar zinote, kiek pazymiu reikia sugeneruot? (T - taip, N - ne) ";
                    cin >> PazymiuPasirinkimas;

                    if (PazymiuPasirinkimas != 'T' && PazymiuPasirinkimas != 'N') {
                        cout << "Klaida. Netinkamas ivedimas, programa baigiasi." << endl;
                        exit(1);
                    }

                    if (PazymiuPasirinkimas == 'T') {
                    cout << "Iveskite generuojamu pazymiu skaiciu: ";
                    cin >> PazymiuSkaicius;
                    if (cin.fail() || PazymiuSkaicius <= 0) {
                        cout << "Klaida. Netinkamas ivedimas, programa baigiasi" << endl;
                        exit(1);
                    }
                    }
                    else if (PazymiuPasirinkimas == 'N') {
                        PazymiuSkaicius = rand() % 11 + 1;
                    }

                for (int j = 0; j < PazymiuSkaicius; j++) {
                    int RandPazymis = rand() % 11;
                    Laikinas.Pazymiai.push_back(RandPazymis);
                }
                cout << "Sugeneruoti studento pazymiai: ";
                for (int pazymys : Laikinas.Pazymiai) {
                    cout << pazymys << " ";
                }
                cout << '\n';
}
//Pazymiu ivedimo funkcija
void PazymiuIvedimas(Studentas& Laikinas) {
    cout << "Iveskite pazymiu skaiciu (arba 'q', jei norite ivesti pazymius be apribojimu): ";
    string input;
    int PazymiuSkaicius;
    cin >> input;
    try {
        PazymiuSkaicius = std::stoi(input);
        if (PazymiuSkaicius == 0) {
            throw std::domain_error("Dalyba is nulio neapibrezta.\n");
        }
    } catch (std::invalid_argument&) {
        PazymiuSkaicius = -1;
    } catch (std::exception& e) {
        std::cerr << "Gavome isimti: " << e.what() << endl;
        exit(1);
    }

    if (cin.fail() || PazymiuSkaicius < -1) {
        cout << "Klaida. Netinkamas ivedimas, programma baigiasi." << endl;
        exit(1);
    }

    if (PazymiuSkaicius == -1) {
        cout << "Iveskite pazymius. Baigti ivedineti pazymius galite suvede 'q'." << endl;
        int Numeris = 1;
        while (true) {
            cout << "Iveskite " << Numeris << " pazymi: ";
            cin >> input;
            int k;
            try {
                k = std::stoi(input);
                if (k < 1 || k > 10) {
                    cout << "Klaida. Netinkamas ivedimas, programa baigiasi." << endl;
                    exit(1);
                }
            } catch (std::invalid_argument&) {
                break;
            }

            Laikinas.Pazymiai.push_back(k);
            Numeris++;
        }

        try {
            if (Numeris == 1) {
                throw std::domain_error("Dalyba is nulio neapibrezta.\n");
            }
        } catch (std::exception& e) {
            std::cerr << "Gavome isimti: " << e.what() << endl;
            exit(1);
        }
    } else {
        for (int j = 0; j < PazymiuSkaicius; j++) {
            int k;
            cout << "Iveskite " << j + 1 << " pazymi: ";
            cin >> k;
            if (cin.fail() || k < 1 || k > 10) {
                cout << "Klaida. Netinkamas ivedimas, programa baigiasi." << endl;
                exit(1);
            }
            Laikinas.Pazymiai.push_back(k);
        }
    }
}

//Studentu skaiciu ir ivedimo budo funkcija
void StudentuInfo(Studentas& Laikinas, vector<Studentas>& Grupe) {
    int StudentuSkaicius;
    char Pasirinkimas;
    cout << "Iveskite studentu skaiciu: ";
        cin >> StudentuSkaicius;
        if (cin.fail() || StudentuSkaicius <= 0) {
            cout << "Klaida. Netinkamas ivedimas, programa baigiasi." << endl;
            exit(1);
        }

        srand(time(0));

        for (int i = 0; i < StudentuSkaicius; i++) {
            cout << "Iveskite studento varda ir pavarde: ";
            cin >> Laikinas.Vardas >> Laikinas.Pavarde;
            //Pasirinkimas kaip gausim duomenis apie pazymius(Ivedimo metodu arba generuojamu)
            cout << "Pasirinkite kaip ivesite pazymius (M - manualiai, A - automatiskai): ";
            cin >> Pasirinkimas;

            if (Pasirinkimas != 'M' && Pasirinkimas != 'A') {
                cout << "Klaida. Netinkamas ivedimas, programa baigiasi." << endl;
                exit(1);
            }

            if (Pasirinkimas == 'A') {
                PazymiuGeneravimas(Laikinas);
            } else if (Pasirinkimas == 'M') {
                PazymiuIvedimas(Laikinas);
            }
            //Pasirinkimas kaip gausim egzamino pazymi(Ivedimo metodu arba generuojamu)
            EgzaminoPazymis(Laikinas);
            //Vidurkio skaiciavimas
            Vidurkis(Laikinas);
            //Medianos skaiciavimas
            Mediana(Laikinas);
            Grupe.push_back(Laikinas);
            Laikinas.Pazymiai.clear();
        }
}

void SukurtiStudentoFaila(int studentCount, const string& filename) {
    auto start = std::chrono::high_resolution_clock::now();
    ofstream file(filename);

    if (!file.is_open()) {
        cout << "Failed to open file: " << filename << endl;
        exit(1);
    }

    Studentas Laikinas;
    srand(time(NULL));

    file << std::left << std::setw(22) << "Vardas"
                      << std::setw(22) << "Pavarde";

    for (int i = 1; i <= 10; i++)
        file << std::setw(10) << "ND" + std::to_string(i);

    file << std::setw(10) << "Egz." << "\n";

    for (int i = 0; i < studentCount; i++) {
        Laikinas.Vardas = "Vardas" + std::to_string(i+1);
        Laikinas.Pavarde = "Pavarde" + std::to_string(i+1);

        for (int j = 0; j < 10; j++)
            Laikinas.Pazymiai.push_back(rand()%11);

        Laikinas.Egzaminas = rand()%11;

        file << std::left << std::setw(22) << Laikinas.Vardas
                          << std::setw(22) << Laikinas.Pavarde;

        for (int grade : Laikinas.Pazymiai)
            file << std::setw(10) << grade;

        file << std::setw(10) << Laikinas.Egzaminas << "\n";

        Laikinas.Pazymiai.clear();
    }

    file.close();
    auto finish = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = finish - start;
    cout << "Failo kurimo laikas: " << elapsed.count() << " sekundziu" << endl;
}

void KategorizuotiStudentus(const vector<Studentas>& Grupe, vector<Studentas>& BelowFive, vector<Studentas>& AboveFive) {
    auto start = std::chrono::high_resolution_clock::now();

    for (const auto& a : Grupe) {
        if(a.Vidurkis < 5.0){
            BelowFive.push_back(a);
        } else {
            AboveFive.push_back(a);
        }
    }

    auto finish = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed2 = finish - start;
    ElapsedTime2 = elapsed2.count();
    cout << "Studentu dalinimas i kategorijas uztruko: " << elapsed2.count() << " sekundziu" << endl;
}

void KategorijuFailai(const vector<Studentas>& BelowFive, const vector<Studentas>& AboveFive) {
    string fileBelowFive, fileAboveFive;
    cout << "Iveskite rezultato failo pavadinima studentams su galutini vidurki < 5: ";
    cin >> fileBelowFive;
    cout << "Iveskite rezultato failo pavadinima studentams su galutini vidurki >= 5: ";
    cin >> fileAboveFive;

    ofstream BelowFiveFile(fileBelowFive);
    ofstream AboveFiveFile(fileAboveFive);

    auto start = std::chrono::high_resolution_clock::now();

    if (!BelowFiveFile.is_open() || !AboveFiveFile.is_open()) {
        cout << "Nepavyko atidaryti failo: " << (BelowFiveFile.is_open() ? fileAboveFive : fileBelowFive) << endl;
        exit(1);
    }

    // Output rezultatas
    BelowFiveFile << "-------------------------------------------------\n";
    BelowFiveFile << std::left << std::setw(17) << "Vardas" << std::setw(15) << "Pavarde" << std::setw(15) << "Galutinis (Vid.)" << "\n";
    BelowFiveFile << "-------------------------------------------------\n";

    // Output rezultatas
    AboveFiveFile << "-------------------------------------------------\n";
    AboveFiveFile << std::left << std::setw(17) << "Vardas" << std::setw(15) << "Pavarde" << std::setw(15) << "Galutinis (Vid.)" << "\n";
    AboveFiveFile << "-------------------------------------------------\n";

    // Duomenys rasomos studentams su vidurki < 5
    for(const auto& a : BelowFive){
        BelowFiveFile << std::fixed << std::setprecision(2) << std::left << std::setw(18) << a.Vardas
                              << std::setw(20) << a.Pavarde
                              << std::setw(15) << a.Vidurkis
                              << "\n";
    }

    // Duomenys rasomos studentams su vidurki >= 5
    for(const auto& a : AboveFive){
        AboveFiveFile << std::fixed << std::setprecision(2) << std::left << std::setw(18) << a.Vardas
                            << std::setw(20) << a.Pavarde
                            << std::setw(15) << a.Vidurkis
                            << "\n";
    }

    BelowFiveFile.close();
    AboveFiveFile.close();

    auto finish = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed3 = finish - start;
    ElapsedTime3 = elapsed3.count();
    cout << "Galutiniai matavimo rezultatai: " << endl;
    cout << "Failo nuskaitymo laikas: " << ElapsedTime1 << " sekundziu" << endl;
    cout << "Studentu dalinimas i kategorijas uztruko: " << ElapsedTime2 << " sekundziu" << endl;
    cout << "Studentu irasymas i failus uztruko: " << ElapsedTime3 << " sekundziu" << endl;
    double totalElapsed = ElapsedTime1 + ElapsedTime2 + ElapsedTime3;
    cout << "Bendras matavimo laikas: " << std::setprecision(15) << totalElapsed << " sekundziu" << endl;
}
