
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2half_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damagda <<marvin@42.fr>>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 19:37:58 by damagda           #+#    #+#             */
/*   Updated: 2026/03/25 19:37:59 by damagda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunsigned(unsigned int n)
{
	int	count;

	count = 0;
	if (n >= 10)
		count += ft_putunsigned(n / 10);
	count += ft_putchar((n % 10) + '0');
	return (count);
}

int	ft_putexa(unsigned int n, char c)
{
	int	count;

	count = 0;
	if (n >= 16)
		count += ft_putexa(n / 16, c);
	if ((n % 16) < 10)
		count += ft_putchar((n % 16) + '0');
	else
	{
		if (c == 'x')
			count += ft_putchar((n % 16) - 10 + 'a');
		else
			count += ft_putchar((n % 16) - 10 + 'A');
	}
	return (count);
}

int	ft_putptr(unsigned long n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (ft_putstr("0"));
	if (n >= 16)
		count += ft_putptr(n / 16);
	if ((n % 16) < 10)
		count += ft_putchar((n % 16) + '0');
	else
		count += ft_putchar((n % 16) - 10 + 'a');
	return (count);
}

int	handle_number(char c, va_list *args)
{
	if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(*args, int)));
	if (c == 'u')
		return (ft_putunsigned(va_arg(*args, unsigned int)));
	if (c == 'x' || c == 'X')
		return (ft_putexa(va_arg(*args, unsigned int), c));
	return (0);
}
