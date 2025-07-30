// uart.c

volatile unsigned int *UART0DR = (unsigned int *)0x101f1000;
volatile unsigned int *UART0FR = (unsigned int *)0x101f1018;

void uart_putchar(char c) {
    while (*UART0FR & (1 << 5)); // espera até que TXFF == 0
    *UART0DR = c;
}

int uart_getchar() {
    while (*UART0FR & (1 << 4)); // espera até que RXFE == 0
    return *UART0DR & 0xFF;      // retorna o caractere recebido
}

void uart_puts(const char *s) {
    while (*s) uart_putchar(*s++);
}

void main() {
    uart_puts("Digite algo:\n");
    while (1) {
        char c = uart_getchar();
        uart_putchar(c);  // ecoa
    }
}
