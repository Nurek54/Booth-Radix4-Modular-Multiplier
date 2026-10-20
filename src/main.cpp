// Mnozenie Bootha: modul Verilog BoothRadix4 (symulacja Verilatora) i algorytm Bootha w C++,
// wynik redukowany modulo 2^n - 3.
//
// Uzycie:
//   booth_sim                          menu
//   booth_sim <mnoznik> <mnozna> <n>   jedno mnozenie obiema metodami, przebiegi w waveform.vcd
//   booth_sim test [liczba]            test automatyczny (domyslnie 100000 losowych par)
#include "modulo/Modulo.h"
#include "sw/Booth.h"
#include "util/BinaryUtils.h"
#ifdef BOOTH_HAS_VERILATOR
#include "hw/BoothRadix4Sim.h"
#endif

#include <chrono>
#include <cstdint>
#include <cstdlib>
#include <iostream>
#include <iterator>
#include <limits>
#include <random>
#include <string>

using namespace std;

constexpr int WIDTH = 18;
constexpr int64_t MIN_VALUE = -(int64_t(1) << (WIDTH - 1));  // -131072
constexpr int64_t MAX_VALUE = (int64_t(1) << (WIDTH - 1)) - 1;  // 131071

static void printModulo(const string& label, int64_t product, const Modulo& mod) {
    int folds = 0;
    int64_t r = mod.reduce(product, &folds);
    cout << "Wynik po modulo (" << label << "): " << r << "  (2^n - 3 = " << mod.modulus()
         << ", krokow redukcji 3H + L: " << folds;
    if (r != mod.applyModulo(product)) cout << ", BLAD: operator % daje " << mod.applyModulo(product);
    cout << ")\n";
}

#ifdef BOOTH_HAS_VERILATOR
static void runBoothRadix4(int64_t mplier, int64_t mcand, const Modulo& mod, const string& vcd) {
    hw::HwResult r;
    double ns;
    {
        hw::BoothRadix4Sim sim(vcd);
        auto t0 = chrono::steady_clock::now();
        r = sim.multiply(mplier, mcand);
        ns = chrono::duration<double, nano>(chrono::steady_clock::now() - t0).count();
    }
    cout << "\nWynik (BoothRadix4, Verilog): " << r.product << "\n";
    cout << "Cykle zegara: " << r.cycles << " (zaladowanie, " << WIDTH / 2 << " krokow radix-4, zapis wyniku)\n";
    cout << "Czas symulacji: " << ns / 1000 << " us, przebiegi: " << vcd << "\n";
    printModulo("BoothRadix4", r.product, mod);
}
#endif

static void runBooth(int64_t mplier, int64_t mcand, const Modulo& mod) {
    Booth booth(mcand, mplier, WIDTH);
    auto t0 = chrono::steady_clock::now();
    int64_t result = booth.multiply();
    double ns = chrono::duration<double, nano>(chrono::steady_clock::now() - t0).count();
    cout << "\nWynik (Booth, C++): " << result << "\n";
    cout << "Iteracje: " << booth.iterations() << " (radix-2), czas: " << ns / 1000 << " us\n";
    printModulo("Booth", result, mod);
}

static void printInputs(int64_t mplier, int64_t mcand) {
    cout << "\nMnoznik binarnie: " << BinaryUtils::toBinaryString(mplier, WIDTH) << "\n";
    cout << "Mnozna binarnie:  " << BinaryUtils::toBinaryString(mcand, WIDTH) << "\n";
}

static void printExact(int64_t mplier, int64_t mcand, const Modulo& mod) {
    cout << "\nDokladnie: " << mplier << " * " << mcand << " = " << mplier * mcand << ", modulo "
         << mod.modulus() << " = " << mod.applyModulo(mplier * mcand) << "\n";
}

// Test: wartosci brzegowe i losowe pary; sprawdza oba mnozenia i obie redukcje modulo
static int selfTest(int count) {
    const int64_t edge[] = {0, 1, -1, 2, -2, 3, -3, MIN_VALUE, MAX_VALUE, MIN_VALUE + 1, MAX_VALUE - 1, 12345, -777};
    mt19937_64 rng(2024);
    uniform_int_distribution<int64_t> value(MIN_VALUE, MAX_VALUE);
    uniform_int_distribution<int> bits(2, 40);
#ifdef BOOTH_HAS_VERILATOR
    hw::BoothRadix4Sim sim;
    long hwBad = 0;
    double hwNs = 0;
    int cycles = 0;
#endif
    long swBad = 0, modBad = 0, total = 0;
    double swNs = 0;
    auto check = [&](int64_t a, int64_t b) {
        const int64_t exact = a * b;
        ++total;
#ifdef BOOTH_HAS_VERILATOR
        auto t0 = chrono::steady_clock::now();
        hw::HwResult r = sim.multiply(a, b);
        hwNs += chrono::duration<double, nano>(chrono::steady_clock::now() - t0).count();
        cycles = r.cycles;
        if (r.product != exact) {
            if (hwBad < 5) cout << "  BoothRadix4: " << a << " * " << b << " = " << r.product << ", oczekiwano " << exact << "\n";
            ++hwBad;
        }
#endif
        auto t1 = chrono::steady_clock::now();
        int64_t s = Booth(b, a, WIDTH).multiply();
        swNs += chrono::duration<double, nano>(chrono::steady_clock::now() - t1).count();
        if (s != exact) {
            if (swBad < 5) cout << "  Booth: " << a << " * " << b << " = " << s << ", oczekiwano " << exact << "\n";
            ++swBad;
        }
        Modulo mod(bits(rng));
        int64_t ref = ((exact % mod.modulus()) + mod.modulus()) % mod.modulus();
        if (mod.reduce(exact) != ref || mod.applyModulo(exact) != ref) ++modBad;
    };
    for (int64_t a : edge)
        for (int64_t b : edge) check(a, b);
    for (int i = 0; i < count; i++) check(value(rng), value(rng));

    cout << "Test: " << total << " par (" << size(edge) * size(edge) << " brzegowych i " << count
         << " losowych), argumenty " << WIDTH << "-bitowe ze znakiem\n";
#ifdef BOOTH_HAS_VERILATOR
    cout << "  BoothRadix4 (Verilog): " << total - hwBad << " / " << total << " poprawnych, " << cycles
         << " cykli zegara na mnozenie, " << hwNs / total << " ns symulacji\n";
#else
    cout << "  BoothRadix4 (Verilog): pominiety, program zbudowany bez Verilatora\n";
#endif
    cout << "  Booth (C++):           " << total - swBad << " / " << total << " poprawnych, " << WIDTH
         << " iteracji na mnozenie, " << swNs / total << " ns\n";
    cout << "  Modulo 2^n - 3:        " << total - modBad << " / " << total << " poprawnych (losowe n od 2 do 40)\n";
#ifdef BOOTH_HAS_VERILATOR
    long bad = hwBad + swBad + modBad;
#else
    long bad = swBad + modBad;
#endif
    cout << (bad ? "WYNIK: BLEDY\n" : "WYNIK: OK\n");
    return bad ? 1 : 0;
}

// Wczytuje liczbe calkowita z zakresu [lo, hi], ponawia przy blednych danych
static bool readValue(const string& prompt, int64_t lo, int64_t hi, int64_t& out) {
    while (true) {
        cout << prompt;
        if (cin >> out && out >= lo && out <= hi) return true;
        if (cin.eof()) return false;
        cout << "Podaj liczbe calkowita z zakresu " << lo << " .. " << hi << "\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

static bool parseInt(const char* s, int64_t& out) {
    char* end;
    out = strtoll(s, &end, 10);
    return *s && !*end;
}

int main(int argc, char** argv) {
    if (argc >= 2 && string(argv[1]) == "test") return selfTest(argc >= 3 ? atoi(argv[2]) : 100000);

    if (argc == 4) {
        int64_t a, b, n;
        if (!parseInt(argv[1], a) || !parseInt(argv[2], b) || !parseInt(argv[3], n) || a < MIN_VALUE ||
            a > MAX_VALUE || b < MIN_VALUE || b > MAX_VALUE || n < 2 || n > 40) {
            cerr << "Uzycie: booth_sim <mnoznik> <mnozna> <n>, argumenty od " << MIN_VALUE << " do " << MAX_VALUE
                 << ", n od 2 do 40\n";
            return 2;
        }
        Modulo mod{int(n)};
        printInputs(a, b);
#ifdef BOOTH_HAS_VERILATOR
        runBoothRadix4(a, b, mod, "waveform.vcd");
#endif
        runBooth(a, b, mod);
        printExact(a, b, mod);
        return 0;
    }

    int runNumber = 0;
    while (true) {
        cout << "\nWybierz opcje:\n"
             << "1. Algorytm BoothRadix4 (Verilog, Verilator)\n"
             << "2. Algorytm Booth (C++)\n"
             << "3. Oba algorytmy i porownanie\n"
             << "4. Test automatyczny\n"
             << "5. Zakoncz program\n";
        int64_t choice;
        if (!readValue("> ", 1, 5, choice) || choice == 5) break;
        if (choice == 4) {
            selfTest(100000);
            continue;
        }
#ifndef BOOTH_HAS_VERILATOR
        if (choice == 1) {
            cout << "Program zbudowany bez Verilatora: symulacja modulu Verilog jest niedostepna (README, Uruchomienie).\n";
            continue;
        }
#endif
        int64_t mplier, mcand, n;
        if (!readValue("\nPodaj mnoznik (" + to_string(MIN_VALUE) + " .. " + to_string(MAX_VALUE) + "): ", MIN_VALUE,
                       MAX_VALUE, mplier) ||
            !readValue("Podaj mnozna: ", MIN_VALUE, MAX_VALUE, mcand) ||
            !readValue("Podaj n dla modulo (2^n - 3), od 2 do 40: ", 2, 40, n))
            break;
        Modulo mod{int(n)};
        printInputs(mplier, mcand);
#ifdef BOOTH_HAS_VERILATOR
        if (choice == 1 || choice == 3) runBoothRadix4(mplier, mcand, mod, "dump_" + to_string(++runNumber) + ".vcd");
#endif
        if (choice == 2 || choice == 3) runBooth(mplier, mcand, mod);
        if (choice == 3) printExact(mplier, mcand, mod);
    }
    return 0;
}
