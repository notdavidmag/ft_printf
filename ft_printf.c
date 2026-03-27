
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damagda <<marvin@42.fr>>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 19:07:21 by damagda           #+#    #+#             */
/*   Updated: 2026/03/25 19:07:22 by damagda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
 
static int	handle_char(va_list *args)
{
	return (ft_putchar(va_arg(*args, int)));
}
 
static int	handle_string(va_list *args)
{
	char	*str;
 
	str = va_arg(*args, char *);
	if (!str)
		str = "(null)";
	return (ft_putstr(str));
}
 
static int	handle_pointer(va_list *args)
{
	unsigned long	ptr;
	int				count;
 
	ptr = (unsigned long)va_arg(*args, void *);
	count = ft_putstr("0x");
	count += ft_putptr(ptr);
	return (count);
}
 
static int	handle_number(char c, va_list *args)
{
	if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(*args, int)));
	if (c == 'u')
		return (ft_putunsigned(va_arg(*args, unsigned int)));
	if (c == 'x' || c == 'X')
		return (ft_putexa(va_arg(*args, unsigned int), c));
	return (0);
}
 
static int	handle_format(char c, va_list *args)
{
	if (c == 'c')
		return (handle_char(args));
	if (c == 's')
		return (handle_string(args));
	if (c == 'p')
		return (handle_pointer(args));
	if (c == '%')
		return (ft_putchar('%'));
	return (handle_number(c, args));
}
 
int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		count;
 
	if (!format)
		return (-1);
	va_start(args, format);
	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			i++;
			count += handle_format(format[i], &args);
		}
		else
			count += ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (count);
}