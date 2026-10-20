# Generuje model C++ z rtl/BoothRadix4.v do generated/VBoothRadix4 (cmake -P, wywolywane przez cel regenerate_model).
# Wymaga VERILATOR_BIN i SOURCE_DIR.
set(OUT "${SOURCE_DIR}/generated/VBoothRadix4")
file(REMOVE_RECURSE "${OUT}")
execute_process(
        COMMAND "${VERILATOR_BIN}" --cc --trace -Wall -Wno-fatal --prefix VBoothRadix4
        --Mdir generated/VBoothRadix4 rtl/BoothRadix4.v
        WORKING_DIRECTORY "${SOURCE_DIR}"  # sciezki wzgledne, zeby w kodzie nie bylo sciezki z jednego komputera
        RESULT_VARIABLE rc)
if (NOT rc EQUAL 0)
    message(FATAL_ERROR "Verilator zakonczyl sie bledem ${rc}")
endif ()
# Zostaja tylko zrodla C++; pliki .mk, .d i .dat sluza do budowania przez make
file(GLOB extra "${OUT}/*.mk" "${OUT}/*.d" "${OUT}/*.dat")
if (extra)
    file(REMOVE ${extra})
endif ()
# Skrot bez znakow CR, zeby nie zalezal od koncow linii (Windows / Linux)
file(READ "${SOURCE_DIR}/rtl/BoothRadix4.v" rtl)
string(REPLACE "\r" "" rtl "${rtl}")
string(SHA256 hash "${rtl}")
file(WRITE "${SOURCE_DIR}/generated/rtl.sha256" "${hash}\n")
message(STATUS "Model wygenerowany w ${OUT}")
