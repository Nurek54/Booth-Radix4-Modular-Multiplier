# Mnożenie Bootha Radix-4 - Symulacja Verilator + C++ / Booth Radix-4 Multiplication - Verilator + C++ Simulation

---

## 🇵🇱 Wersja polska

### Opis projektu

Projekt realizuje **algorytm mnożenia Bootha Radix-4** w dwóch wariantach:

- **Sprzętowy** - moduł Verilog (`BoothRadix4`) symulowany za pomocą Verilatora, z generowaniem przebiegów VCD
- **Programowy** - implementacja algorytmu Bootha w czystym C++

Program pozwala porównać wyniki obu metod, mierzy czas wykonania i stosuje operację modulo `(2^n − 3)` na wyniku mnożenia.

### Struktura plików

| Plik | Opis |
|------|------|
| `main.cpp` | Główny punkt wejścia - menu wyboru algorytmu, obsługa wejścia/wyjścia |
| `Booth.h` / `Booth.cpp` | Implementacja klasycznego algorytmu Bootha w C++ |
| `BinaryUtils.h` / `BinaryUtils.cpp` | Narzędzia do konwersji binarno-dziesiętnej |
| `Modulo.h` / `Modulo.cpp` | Klasa realizująca operację modulo `2^n − 3` |
| `sc_time_stamp.cpp` | Funkcja wymagana przez Verilator |
| `build_and_run.sh` | Skrypt kompilacji i uruchomienia symulacji |
| `CMakeLists.txt` | Konfiguracja CMake dla projektu |
| `waveform.vcd` / `dump_1.vcd` | Przykładowe przebiegi sygnałów (VCD) |

### Wymagania

- **MSYS2** (środowisko Windows)
- **Verilator** - symulator Verilog
- **G++** z obsługą C++17
- Pakiety systemowe: `git`, `make`, `autoconf`, `automake`, `gcc`

### Instalacja i uruchomienie

1. Zainstaluj MSYS2 ze [strony oficjalnej](https://www.msys2.org/)
2. Zainstaluj zależności:
   ```sh
   pacman -Syu
   pacman -S git make autoconf automake gcc g++
   ```
3. Skompiluj i uruchom:
   ```sh
   verilator --cc verilog/BoothRadix4.v --exe --trace --build \
     src/main.cpp src/BinaryUtils.cpp src/Booth.cpp src/Modulo.cpp \
     sc_time_stamp.cpp -o sim --timing -LDFLAGS "-mconsole"
   ./obj_dir/sim
   ```

### Użycie

Po uruchomieniu program wyświetla menu:

1. **Algorytm BoothRadix4** - symulacja sprzętowa przez Verilator (generuje plik `.vcd`)
2. **Algorytm Booth** - implementacja czysto programowa w C++
3. **Zakończ program**

Dla obu wariantów podajesz mnożnik, mnożną oraz parametr `n` dla operacji modulo.

### Jak to działa

Algorytm Bootha Radix-4 przetwarza po 2 bity mnożnika w każdym cyklu (zamiast 1 jak klasyczny Booth), co zmniejsza liczbę iteracji o połowę. Moduł Verilog implementuje maszynę stanów (IDLE → BUSY → IDLE) z rejestrem przesuwnym i akumulatorem. Symulacja generuje pliki VCD, które można wizualizować np. w GTKWave.

---

## 🇬🇧 English version

### Project description

This project implements the **Booth Radix-4 multiplication algorithm** in two variants:

- **Hardware** - a Verilog module (`BoothRadix4`) simulated with Verilator, generating VCD waveforms
- **Software** - a pure C++ implementation of the Booth algorithm

The program compares results from both methods, measures execution time, and applies a modulo `(2^n − 3)` operation to the multiplication result.

### File structure

| File | Description |
|------|-------------|
| `main.cpp` | Entry point - algorithm selection menu, I/O handling |
| `Booth.h` / `Booth.cpp` | Classic Booth algorithm implementation in C++ |
| `BinaryUtils.h` / `BinaryUtils.cpp` | Binary-decimal conversion utilities |
| `Modulo.h` / `Modulo.cpp` | Modulo `2^n − 3` operation class |
| `sc_time_stamp.cpp` | Stub function required by Verilator |
| `build_and_run.sh` | Build and run script |
| `CMakeLists.txt` | CMake project configuration |
| `waveform.vcd` / `dump_1.vcd` | Example VCD signal waveforms |

### Requirements

- **MSYS2** (Windows environment)
- **Verilator** - Verilog simulator
- **G++** with C++17 support
- System packages: `git`, `make`, `autoconf`, `automake`, `gcc`

### Installation and running

1. Install MSYS2 from the [official website](https://www.msys2.org/)
2. Install dependencies:
   ```sh
   pacman -Syu
   pacman -S git make autoconf automake gcc g++
   ```
3. Build and run:
   ```sh
   verilator --cc verilog/BoothRadix4.v --exe --trace --build \
     src/main.cpp src/BinaryUtils.cpp src/Booth.cpp src/Modulo.cpp \
     sc_time_stamp.cpp -o sim --timing -LDFLAGS "-mconsole"
   ./obj_dir/sim
   ```

### Usage

After launching, the program displays a menu:

1. **BoothRadix4 algorithm** - hardware simulation via Verilator (generates a `.vcd` file)
2. **Booth algorithm** - pure software C++ implementation
3. **Exit**

For both variants you provide the multiplier, multiplicand, and the `n` parameter for the modulo operation.

### How it works

The Booth Radix-4 algorithm processes 2 bits of the multiplier per cycle (instead of 1 as in classic Booth), cutting the number of iterations in half. The Verilog module implements a state machine (IDLE → BUSY → IDLE) with a shift register and accumulator. The simulation generates VCD files that can be visualized using tools like GTKWave.

### VCD waveform signals

| Signal | Width | Description |
|--------|-------|-------------|
| `clk` | 1 bit | Clock |
| `n_reset` | 1 bit | Active-low reset |
| `start` | 1 bit | Start multiplication |
| `mplier` | 18 bit | Multiplier input |
| `mcand` | 18 bit | Multiplicand input |
| `product` | 36 bit | Multiplication result |
| `done` | 1 bit | Operation complete flag |
| `state_reg` | 2 bit | FSM state (IDLE=01, BUSY=10) |
| `q_reg` | 5 bit | Iteration counter |
| `prod_reg` | 37 bit | Internal product/shift register |
