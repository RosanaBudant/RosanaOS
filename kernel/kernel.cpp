#include <stdint.h>
#include <stddef.h>

// Declarações das funções (prototypes)
extern "C" void kernel_main();

// Funções da VGA
void clear();
void print(const char* str);
void print_color(const char* str, uint8_t color);
void set_color(uint8_t color);
void set_cursor(size_t row, size_t col);

// Cores úteis
enum colors {
    BLACK = 0,
    BLUE = 1,
    GREEN = 2,
    CYAN = 3,
    RED = 4,
    MAGENTA = 5,
    BROWN = 6,
    LIGHT_GREY = 7,
    DARK_GREY = 8,
    LIGHT_BLUE = 9,
    LIGHT_GREEN = 10,
    LIGHT_CYAN = 11,
    LIGHT_RED = 12,
    LIGHT_MAGENTA = 13,
    LIGHT_BROWN = 14,
    WHITE = 15,
};

extern "C" void kernel_main() {
    // Limpa a tela
    clear();
    
    // Escreve o título com cor
    set_color((WHITE << 4) | BLACK);
    print("========================================\n");
    print("        RosanaOS v0.1 - Fase 2        \n");
    print("========================================\n\n");
    
    // Teste de cores
    print("Cores disponiveis:\n");
    print_color(" Preto   ", (BLACK << 4) | WHITE);
    print_color(" Vermelho", (RED << 4) | BLACK);
    print("\n");
    print_color(" Verde   ", (GREEN << 4) | BLACK);
    print_color(" Azul    ", (BLUE << 4) | BLACK);
    print("\n");
    print_color(" Amarelo ", (BROWN << 4) | BLACK);
    print_color(" Magenta ", (MAGENTA << 4) | BLACK);
    print("\n\n");
    
    print("Teste de posicionamento:\n");
    print("Linha 1\n");
    print("Linha 2\n");
    print("Linha 3\n");
    set_cursor(15, 10);
    print_color("Texto centralizado!", (GREEN << 4) | BLACK);
    
    print("\nSistema operacional carregado com sucesso!\n");
    print("Aguardando proxima fase...\n");
    
    // Loop infinito
    while (true) {}
}
