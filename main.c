
#define MAX_MEMORY_SIZE 3000

volatile unsigned int *UART0DR = (unsigned int *)0x101f1000;
volatile unsigned int *UART0FR = (unsigned int *)0x101f1018;

struct braingdf {
    int current_pos;
    int code_size;
    char *current_char;
    char *program;
    int lista_breakpoints[MAX_MEMORY_SIZE];
}

void uart_putchar_2(char c) {
    while (*UART0FR & (1 << 5)); // espera até que TXFF == 0
    *UART0DR = c;
}

int uart_getchar_2() {
    while (*UART0FR & (1 << 4)); // espera até que RXFE == 0
    return *UART0DR & 0xFF;      // retorna o caractere recebido
}

void uart_puts_2(const char *s) {
    while (*s) uart_putchar_2(*s++);
}

// void print_mem(char *string, int *init, int *end);
// void print_string(char *c);

// **********************************
// COLOCAR MEMORIA NO STRUCT
// **********************************
static char memory[MAX_MEMORY_SIZE] = {0};

int pos_memoria = 0;
void main() {
    // const char *program = "++++++++++++++++++++++++++++++++++."; // #
                              
    const char *program = ",[.,>++++++++++++++++++++++++++++++++++.----------------------------------<]";
    // const char *program = ",."; // Hello World!

    for (int i = 0; program[i] != '\0'; i++) {
        switch (program[i]) {
            case '>': ++pos_memoria; break;
            case '<': --pos_memoria; break;
            case '+': ++memory[pos_memoria]; break;
            case '-': --memory[pos_memoria]; break;
            case '.': uart_putchar_2(memory[pos_memoria]); break;
            case ',': memory[pos_memoria] = uart_getchar_2(); break;
            case '[':
                if (!memory[pos_memoria]) {
                    int loop = 1;
                    while (loop > 0) {
                        i++;
                        if (program[i] == '[') loop++;
                        else if (program[i] == ']') loop--;
                    }
                }
                break;
            case ']':
                if (memory[pos_memoria]) {
                    int loop = 1;
                    while (loop > 0) {
                        i--;
                        if (program[i] == ']') loop++;
                        else if (program[i] == '[') loop--;
                    }
                    i--;
                }
                break;
        }
    }

    while (1);
}

// void print_mem(char *memory, int *init, int *end) {
//     if(init < 0 || end > MAX_MEMORY_SIZE || init >= end) {
//         print_string("Mensagem de erro: intervalo inválido.\n");
//         return;
//     }

//     for (int i = *init; i < *end; i++) {
//         if (i == *init) {
//             print_string("| ");
//         } 
//          print_string(&memory[i]);
//          print_string(" |");
//     } 
// }

// void print_string(char *c){
//     for (int i = 0; c[i] != '\0'; i++) {
//         uart_putchar_2(c[i]);
//         i++;
//     }
// }
