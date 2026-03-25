#include "ft_printf.h"

int main(void)
{
    int i = 42;
    char c = 'A';
    char *str = "Hola 42";
    unsigned int u = 123456;
    unsigned int x = 48879;
    void *ptr = str;

    ft_printf("Caracter: %c\n", c);
    ft_printf("Cadena: %s\n", str);
    ft_printf("Entero: %d\n", i);
    ft_printf("Entero sin signo: %u\n", u);
    ft_printf("Hex min: %x\n", x);
    ft_printf("Hex MAY: %X\n", x);
    ft_printf("Puntero: %p\n", ptr);
    ft_printf("Porcentaje: %%%%\n");

    return 0;
}