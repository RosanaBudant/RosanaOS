#include <stddef.h>
#include <stdint.h>

// Dimensões do modo texto VGA
static const size_t VGA_WIDTH = 80;
static const size_t VGA_HEIGHT = 25;

// Ponteiro para a memória VGA (modo texto)
static uint16_t* const VGA_MEMORY = (uint16_t*)0xB8000;

// Cores disponíveis no VGA
enum vga_color {
    VGA_COLOR_BLACK = 0,
    VGA_COLOR_BLUE = 1,
    VGA_COLOR_GREEN = 2,
    VGA_COLOR_CYAN = 3,
    VGA_COLOR_RED = 4,
    VGA_COLOR_MAGENTA = 5,
    VGA_COLOR_BROWN = 6,
    VGA_COLOR_LIGHT_GREY = 7,
    VGA_COLOR_DARK_GREY = 8,
    VGA_COLOR_LIGHT_BLUE = 9,
    VGA_COLOR_LIGHT_GREEN = 10,
    VGA_COLOR_LIGHT_CYAN = 11,
    VGA_COLOR_LIGHT_RED = 12,
    VGA_COLOR_LIGHT_MAGENTA = 13,
    VGA_COLOR_LIGHT_BROWN = 14,
    VGA_COLOR_WHITE = 15,
};

// Posição atual do cursor
static size_t cursor_row = 0;
static size_t cursor_col = 0;

// Cor padrão: texto branco em fundo preto
static uint8_t default_color = (VGA_COLOR_WHITE << 4) | VGA_COLOR_BLACK;

// Função para criar uma entrada VGA (caractere + cor)
static inline uint16_t vga_entry(unsigned char ch, uint8_t color) {
    return (uint16_t)ch | ((uint16_t)color << 8);
}

// Limpa a tela
void clear() {
    for (size_t i = 0; i < VGA_WIDTH * VGA_HEIGHT; i++) {
        VGA_MEMORY[i] = vga_entry(' ', default_color);
    }
    cursor_row = 0;
    cursor_col = 0;
}

// Define a cor padrão
void set_color(uint8_t color) {
    default_color = color;
}

// Move o cursor para uma posição específica
void set_cursor(size_t row, size_t col) {
    if (row < VGA_HEIGHT && col < VGA_WIDTH) {
        cursor_row = row;
        cursor_col = col;
    }
}

// Função principal de escrita
void print(const char* str) {
    for (size_t i = 0; str[i] != '\0'; i++) {
        char ch = str[i];
        
        if (ch == '\n') {
            // Nova linha
            cursor_row++;
            cursor_col = 0;
        } else if (ch == '\t') {
            // Tabulação (4 espaços)
            do {
                VGA_MEMORY[cursor_row * VGA_WIDTH + cursor_col] = vga_entry(' ', default_color);
                cursor_col++;
            } while (cursor_col % 4 != 0 && cursor_col < VGA_WIDTH);
        } else {
            // Caractere normal
            VGA_MEMORY[cursor_row * VGA_WIDTH + cursor_col] = vga_entry(ch, default_color);
            cursor_col++;
        }
        
        // Quebra de linha automática
        if (cursor_col >= VGA_WIDTH) {
            cursor_col = 0;
            cursor_row++;
        }
        
        // Scroll se necessário (por enquanto, volta ao início)
        if (cursor_row >= VGA_HEIGHT) {
            // Opção 1: Limpa a tela
            clear();
            // Opção 2: Scroll (implementaremos depois)
        }
    }
}

// Escreve com cor específica
void print_color(const char* str, uint8_t color) {
    uint8_t old_color = default_color;
    default_color = color;
    print(str);
    default_color = old_color;
}
