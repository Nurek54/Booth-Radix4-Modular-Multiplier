cmake_minimum_required(VERSION 3.16)
project(Booth_Radix4_Modular_Multiplier LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(booth_sim
        src/main.cpp
        src/hw/BoothRadix4Sim.cpp
        src/sw/Booth.cpp
        src/modulo/Modulo.cpp
        src/util/BinaryUtils.cpp)
target_include_directories(booth_sim PRIVATE src)
target_compile_definitions(booth_sim PRIVATE BOOTH_HAS_VERILATOR)

# Verilator jest potrzebny tylko do zamiany rtl/BoothRadix4.v na C++. Bez niego projekt uzywa modelu
# wygenerowanego wczesniej (generated/) i runtime'u Verilatora (third_party/), wiec buduje sie zwyklym
# kompilatorem C++, np. MinGW dolaczonym do CLion.
option(BOOTH_VERILATE "Generuj model z rtl/ przy kazdym budowaniu, jesli Verilator jest zainstalowany" ON)

find_program(VERILATOR_BIN NAMES verilator_bin verilator_bin.exe
        HINTS $ENV{VERILATOR_ROOT}/bin C:/msys64/ucrt64/bin C:/msys64/mingw64/bin)
if (VERILATOR_BIN)
    get_filename_component(VERILATOR_BIN_DIR "${VERILATOR_BIN}" DIRECTORY)
    find_package(verilator QUIET HINTS $ENV{VERILATOR_ROOT} "${VERILATOR_BIN_DIR}/../share/verilator")
    # cmake --build <katalog> --target regenerate_model: odswieza generated/ po zmianie pliku Verilog
    add_custom_target(regenerate_model
            COMMAND ${CMAKE_COMMAND} -DVERILATOR_BIN=${VERILATOR_BIN} -DSOURCE_DIR=${CMAKE_SOURCE_DIR}
            -P ${CMAKE_SOURCE_DIR}/tools/regenerate_model.cmake)
endif ()

if (verilator_FOUND AND BOOTH_VERILATE)
    message(STATUS "Verilator ${verilator_VERSION}: model generowany z rtl/BoothRadix4.v")
    verilate(booth_sim
            SOURCES rtl/BoothRadix4.v
            PREFIX VBoothRadix4
            TRACE
            VERILATOR_ARGS -Wall -Wno-fatal)
else ()
    message(STATUS "Model z generated/VBoothRadix4 i runtime Verilatora 5.020 z third_party/")
    file(READ rtl/BoothRadix4.v rtl)
    string(REPLACE "\r" "" rtl "${rtl}")
    string(SHA256 rtl_hash "${rtl}")
    file(STRINGS generated/rtl.sha256 generated_hash LIMIT_COUNT 1)
    if (NOT rtl_hash STREQUAL generated_hash)
        message(WARNING "rtl/BoothRadix4.v zmienil sie od wygenerowania modelu w generated/. "
                "Symulacja uzywa starej wersji; po instalacji Verilatora uruchom cel regenerate_model.")
    endif ()
    file(GLOB model_sources CONFIGURE_DEPENDS generated/VBoothRadix4/*.cpp)
    set(VL third_party/verilator/include)
    add_library(verilated_model STATIC ${model_sources}
            ${VL}/verilated.cpp ${VL}/verilated_threads.cpp ${VL}/verilated_vcd_c.cpp)
    target_include_directories(verilated_model PUBLIC generated/VBoothRadix4 ${VL})
    target_compile_definitions(verilated_model PUBLIC VM_TRACE=1 VM_TRACE_VCD=1)
    if (CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
        target_compile_options(verilated_model PRIVATE -w)  # kod wygenerowany i runtime: bez ostrzezen
    endif ()
    find_package(Threads REQUIRED)
    target_link_libraries(verilated_model PUBLIC Threads::Threads)
    target_link_libraries(booth_sim PRIVATE verilated_model)
endif ()

# MinGW: libstdc++ i libgcc wbudowane w exe, a libwinpthread-1.dll kopiowany z kompilatora
# obok exe, zeby Windows nie wzial starszej wersji z innego MinGW w PATH.
if (MINGW)
    get_filename_component(MINGW_BIN "${CMAKE_CXX_COMPILER}" DIRECTORY)
    target_link_options(booth_sim PRIVATE -static-libgcc -static-libstdc++)
    if (EXISTS "${MINGW_BIN}/libwinpthread-1.dll")
        add_custom_command(TARGET booth_sim POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy_if_different
                "${MINGW_BIN}/libwinpthread-1.dll" $<TARGET_FILE_DIR:booth_sim>)
    endif ()
endif ()

enable_testing()
add_test(NAME self_test COMMAND booth_sim test 20000)
