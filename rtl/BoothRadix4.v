`timescale 1ns / 100 ps
module BoothRadix4 #(parameter N = 18)  // parametryzowalna szerokość danych N
(
    output reg [2*N-1:0] product,   // wyjście - wynik mnożenia
    output reg           done,      // wyjście - sygnalizacja zakończenia operacji
    input wire [N-1:0]   mplier,    // wejście - mnożnik
    input wire [N-1:0]   mcand,     // wejście - mnożna
    input wire           n_reset,   // wejście - reset
    input wire           start,     // wejście - sygnał startu
    input wire           clk        // wejście - zegar
);

//---------------- stany dla FSM --------------------------------------
parameter IDLE = 2'b01, BUSY = 2'b10;  // Definicja stanów FSM: IDLE i BUSY
reg [1:0] state_reg, state_next;  // Rejestry do przechowywania aktualnego i następnego stanu FSM

//---------------- wewnętrzne zmienne ----------------------------------
reg [$clog2(N>>1):0] q_reg, q_next;  // Licznik do N/2, obecna i następna wartość
// Rejestr produktu ma 2N+2 bity: akumulator jest o 2 bity szerszy niż mnożna, bo przy mnożnej
// -2^(N-1) operacja -2*Mcand daje +2^N, które nie mieści się w N+1 bitach ze znakiem.
reg [2*N+1:0] prod_reg, prod_next;  // obecna i następna wartość
reg result_reg;  // Rejestr do przechowywania najmniej znaczącego bitu dla kodowania Bootha
reg [N-1:0] mcand_reg, mcand_next;  // Rejestry do przechowywania mnożnej, obecna i następna wartość
reg q_add, q_reset;  // Flagi kontrolne do licznika: dodawanie i reset

// Aktualizacja stanów
always @ (posedge clk) begin : FSM_Synch
    if (n_reset == 1'b0) begin  // Jeśli reset jest aktywny
        state_reg <= IDLE;  // Przejdź do stanu IDLE
        q_reg <= {($clog2(N>>1)+1){1'b0}};  // Zresetuj licznik
        prod_reg <= {(2*N+2){1'b0}};  // Zresetuj rejestr produktu
        result_reg <= 1'b0;  // Zresetuj rejestr wyniku
        mcand_reg <= {N{1'b0}};  // Zresetuj rejestr mnożnej
    end else begin  // Jeśli reset nie jest aktywny
        q_reg <= q_next;  // Zaktualizuj licznik
        state_reg <= state_next;  // Zaktualizuj stan FSM
        prod_reg <= {prod_next[2*N+1], prod_next[2*N+1:1]};  // Zaktualizuj rejestr produktu z przesunięciem
        result_reg <= prod_next[0];  // Zaktualizuj rejestr wyniku
        mcand_reg <= mcand_next;  // Zaktualizuj rejestr mnożnej
    end
end

// Licznik z kontrolnymi flagami
always @ (q_reset, q_add, q_reg) begin : Counter
    case ({q_reset, q_add})  // Sprawdź kombinację flag resetu i dodawania
        2'b00: q_next = q_reg;  // Jeśli brak resetu i dodawania, zachowaj aktualną wartość licznika
        2'b01: q_next = q_reg + 1;  // Jeśli dodawanie, zwiększ licznik o 1
        default: q_next = {($clog2(N>>1)+1){1'b0}};  // W przeciwnym razie zresetuj licznik
    endcase
end

// Obliczanie następnego stanu i wyjść
always @ (*) begin : FSM_Comb
    q_add = 1'b0;  // Inicjalizacja flagi dodawania
    q_reset = 1'b0;  // Inicjalizacja flagi resetu
    done = 1'b0;  // Inicjalizacja flagi zakończenia
    state_next = state_reg;  // Inicjalizacja następnego stanu
    prod_next = prod_reg;  // Inicjalizacja następnego rejestru produktu
    mcand_next = mcand_reg;  // Inicjalizacja następnego rejestru mnożnej

    /* verilator lint_off CASEINCOMPLETE */
    case (state_reg)
        IDLE: begin  // Stan IDLE
            if (start == 1'b1) begin  // Jeśli sygnał start jest aktywny
                mcand_next = mcand;  // Załaduj mnożną
                prod_next = {{(N+1){1'b0}}, mplier, 1'b0};  // Załaduj mnożnik do rejestru produktu z dodatkowym bitem
                state_next = BUSY;  // Przejdź do stanu BUSY
            end else begin
                mcand_next = mcand_reg;  // Zachowaj aktualną wartość mnożnej
            end
        end

        BUSY: begin  // Stan BUSY
            q_add = 1'b1;  // Uruchomienie dodawania
            if ((q_reg == (N >> 1)) && (start != 1'b1)) begin  // Po N/2 cyklach zegara i braku sygnału startu
                done = 1'b1;  // Ustawienie flagi zakończenia
                q_add = 1'b0;  // Zatrzymanie dodawania
                q_reset = 1'b1;  // Zresetowanie licznika
                state_next = IDLE;  // Przejście do stanu IDLE
            end

            // Dekodowanie Bootha i operacje, kodowanie pochodzi z prod_next[2:0] po aktualizacji sekwencyjnej
            case ({prod_reg[1:0], result_reg})
                3'b001: prod_next = {({prod_reg[2*N+1], prod_reg[2*N+1:N+1]} + {{2{mcand_reg[N-1]}}, mcand_reg}), prod_reg[N:1]};  // Dodaj Mcand
                3'b010: prod_next = {({prod_reg[2*N+1], prod_reg[2*N+1:N+1]} + {{2{mcand_reg[N-1]}}, mcand_reg}), prod_reg[N:1]};  // Dodaj Mcand
                3'b011: prod_next = {({prod_reg[2*N+1], prod_reg[2*N+1:N+1]} + {mcand_reg[N-1], mcand_reg, 1'b0}), prod_reg[N:1]};  // Dodaj 2*Mcand
                3'b100: prod_next = {({prod_reg[2*N+1], prod_reg[2*N+1:N+1]} - {mcand_reg[N-1], mcand_reg, 1'b0}), prod_reg[N:1]};  // Odejmij 2*Mcand
                3'b101: prod_next = {({prod_reg[2*N+1], prod_reg[2*N+1:N+1]} - {{2{mcand_reg[N-1]}}, mcand_reg}), prod_reg[N:1]};  // Odejmij Mcand
                3'b110: prod_next = {({prod_reg[2*N+1], prod_reg[2*N+1:N+1]} - {{2{mcand_reg[N-1]}}, mcand_reg}), prod_reg[N:1]};  // Odejmij Mcand
                default: prod_next = {prod_reg[2*N+1], prod_reg[2*N+1:1]};  // Przesunięcie w prawo o 1
            endcase
        end
    endcase
    /* verilator lint_on CASEINCOMPLETE */
end

// Synchronizacja wyjścia z sygnałem done dla enable
always @ (posedge clk) begin : Synch_Output
    if (done) begin  // Jeśli operacja jest zakończona
        product <= prod_reg[2*N:1];  // Przypisz wynik do wyjścia product
    end
end

endmodule
