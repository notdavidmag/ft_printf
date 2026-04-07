/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damagda <<marvin@42.fr>>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 20:00:15 by damagda           #+#    #+#             */
/*   Updated: 2026/04/07 18:48:03 by damagda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

#define TEST(desc, fmt, ...) do { \
	int r1, r2; \
	printf("\n[TEST] %s\n", desc); \
	printf("  printf   : "); \
	r2 = printf(fmt, ##__VA_ARGS__); \
	printf("  (ret=%d)\n", r2); \
	printf("  ft_printf: "); \
	r1 = ft_printf(fmt, ##__VA_ARGS__); \
	ft_printf("  (ret=%d)\n", r1); \
	if (r1 == r2) \
		printf("  [OK] retornos iguales (%d)\n", r1); \
	else \
		printf("  [FAIL] printf=%d ft_printf=%d\n", r2, r1); \
} while (0)

int	main(void)
{
	char			c = 'A';
	char			*str = "Hola 42";
	char			*null_str = NULL;
	int				i_pos = 42;
	int				i_neg = -42;
	int				i_zero = 0;
	int				i_min = INT_MIN;
	int				i_max = INT_MAX;
	unsigned int	u_one = 1;
	unsigned int	u_max = UINT_MAX;
	unsigned int	u_zero = 0;
	unsigned int	x_val = 0xBEEF;
	unsigned int	x_zero = 0;
	unsigned int	x_max = UINT_MAX;
	void			*ptr = str;
	void			*null_ptr = NULL;

	printf("\n==============================\n");
	printf("   PRUEBAS EXHAUSTIVAS FT_PRINTF\n");
	printf("==============================\n");

	printf("\n--- %%c ---");
	TEST("char normal",         "%c", c);
	TEST("char minuscula",      "%c", 'z');
	TEST("char numero",         "%c", '0');
	TEST("char espacio",        "%c", ' ');
	TEST("char con texto",      "X=%c!", c);

	printf("\n--- %%s ---");
	TEST("string normal",       "%s", str);
	TEST("string nulo",         "%s", null_str);
	TEST("string vacio",        "%s", "");
	TEST("string largo",        "%s", "abcdefghijklmnopqrstuvwxyz");
	TEST("string con texto",    "Di: %s!", str);

	printf("\n--- %%d y %%i ---");
	TEST("d positivo",          "%d", i_pos);
	TEST("d negativo",          "%d", i_neg);
	TEST("d cero",              "%d", i_zero);
	TEST("d INT_MIN",           "%d", i_min);
	TEST("d INT_MAX",           "%d", i_max);
	TEST("i positivo",          "%i", i_pos);
	TEST("i negativo",          "%i", i_neg);
	TEST("i cero",              "%i", i_zero);
	TEST("i INT_MIN",           "%i", i_min);
	TEST("i INT_MAX",           "%i", i_max);
	TEST("d -1",                "%d", -1);
	TEST("d 1",                 "%d", 1);

	printf("\n--- %%u ---");
	TEST("u cero",              "%u", u_zero);
	TEST("u uno",               "%u", u_one);
	TEST("u UINT_MAX",          "%u", u_max);
	TEST("u valor medio",       "%u", 2147483648u);

	printf("\n--- %%x y %%X ---");
	TEST("x cero",              "%x", x_zero);
	TEST("x valor",             "%x", x_val);
	TEST("x UINT_MAX",          "%x", x_max);
	TEST("X cero",              "%X", x_zero);
	TEST("X valor",             "%X", x_val);
	TEST("X UINT_MAX",          "%X", x_max);
	TEST("x 10 (a)",            "%x", 10u);
	TEST("x 15 (f)",            "%x", 15u);
	TEST("x 16 (10)",           "%x", 16u);
	TEST("x 255 (ff)",          "%x", 255u);

	printf("\n--- %%p ---");
	TEST("p puntero valido",    "%p", ptr);
	TEST("p puntero nulo",      "%p", null_ptr);
	TEST("p otro puntero",      "%p", (void *)&i_pos);

	printf("\n--- %%%% ---");
	TEST("porcentaje solo",     "%%");
	TEST("porcentaje con texto","100%%");
	TEST("dos porcentajes",     "%%%%");

	printf("\n--- MEZCLAS ---");
	TEST("mix basico",
		"%c %s %d %i %u %x %X %%",
		c, str, i_neg, i_pos, u_max, x_val, x_val);
	TEST("multiples d",         "%d %d %d", i_min, i_zero, i_max);
	TEST("multiples s",         "%s %s", str, "mundo");
	TEST("consecutivos %%",     "50%% off %s por %d euros", str, i_pos);
	TEST("todo junto",
		"c=%c s=%s d=%d i=%i u=%u x=%x X=%X %%",
		'B', "test", -1, 42, u_max, 0xDEADu, 0xCAFEu);

	printf("\n--- EDGE CASES ---");
	TEST("solo char",           "%c", 'A');
	TEST("solo porcentaje",     "%%");
	TEST("d despues de string", "%s=%d", "val", 99);
	TEST("hex de 1",            "%x", 1u);
	TEST("hex de 0xF",          "%x", 0xFu);
	TEST("hex de 0x10",         "%x", 0x10u);

	printf("\n==============================\n");
	printf("   FIN DE PRUEBAS\n");
	printf("==============================\n\n");

	return (0);
}
	*/