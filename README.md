*Este proyecto ha sido creado como parte del currículo de 42 por damagda.*

# ft_printf

## Descripción

`ft_printf` es una reimplementación de la función `printf()` de la librería estándar de C. El objetivo del proyecto es comprender el funcionamiento interno de las funciones variádicas en C (`va_list`, `va_start`, `va_arg`, `va_end`) y practicar la gestión de múltiples tipos de conversión sin usar el buffer original de `printf()`.

La librería se compila como un archivo estático (`libftprintf.a`) y puede enlazarse a cualquier proyecto C como sustituto directo de `printf()`.

### Conversiones soportadas

| Especificador | Descripción |
|---|---|
| `%c` | Imprime un solo carácter |
| `%s` | Imprime una cadena de caracteres |
| `%p` | Imprime un puntero en formato hexadecimal |
| `%d` | Imprime un entero decimal con signo |
| `%i` | Imprime un entero en base 10 |
| `%u` | Imprime un entero decimal sin signo |
| `%x` | Imprime un número hexadecimal en minúsculas |
| `%X` | Imprime un número hexadecimal en mayúsculas |
| `%%` | Imprime el símbolo `%` |

## Instrucciones

### Compilación

```bash
make
```

Esto genera el archivo `libftprintf.a` en la raíz del repositorio.

### Uso en un proyecto

Incluye el header en tu código:

```c
#include "ft_printf.h"
```

Y enlaza la librería al compilar:

```bash
cc -Wall -Wextra -Werror main.c libftprintf.a -o programa
```

### Limpieza

```bash
make clean    # elimina los archivos objeto (.o)
make fclean   # elimina también libftprintf.a
make re       # recompila desde cero
```

## Algoritmo y estructura de datos

La función `ft_printf()` recorre el string de formato carácter a carácter. Cuando encuentra un `%` seguido de un especificador válido, delega el manejo a una función estática especializada (`handle_format`), que a su vez llama a la función de escritura correspondiente según el tipo.

Se ha optado por una arquitectura modular dividida en tres archivos:

- **`ft_printf.c`**: núcleo principal con el parsing del formato y las funciones `handle_*` estáticas.
- **`1half_functions.c`**: funciones para tipos básicos (`char`, `string`, `int`).
- **`2half_functions.c`**: funciones para tipos numéricos especiales (`unsigned`, hexadecimal, puntero).

Cada función de escritura devuelve el número de caracteres escritos, que se va acumulando en un contador que `ft_printf()` retorna al final, respetando el comportamiento del `printf()` original.

No se usa ninguna estructura de datos adicional. El recorrido es lineal O(n) sobre el string de formato, y las conversiones numéricas usan recursión para simplificar la lógica de inversión de dígitos sin necesidad de buffers auxiliares.

## Recursos

- [Manual de `printf` 

### Uso de IA

Se utilizó Claude (Anthropic) como herramienta de revisión del código al finalizar el proyecto. Concretamente para:
- Verificar que todas las conversiones requeridas por el subject estaban implementadas.
- Detectar el bug en el manejo de punteros nulos (`%p` con `NULL`).

La implementación del código fue realizada de forma propia como parte del aprendizaje del proyecto.