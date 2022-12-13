/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbesson <fbesson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 14:22:50 by fbesson           #+#    #+#             */
/*   Updated: 2022/12/13 16:27:43 by fbesson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_conversions(const char c, va_list *args)
{
	unsigned long		ptr;

	if (c == 'c')
		return (ft_putchar(va_arg(*args, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(*args, char *)));
	else if (c == 'p')
	{
		ptr = (unsigned long)va_arg(*args, void *);
		if (!ptr)
			return (write(1, "(nil)", 5));
		return (ft_putstr("0x") \
			+ ft_putnbr(ptr, 16, 0));
	}
	else if (c == 'd' || c == 'i')
		return (ft_putdecimal(args));
	else if (c == 'u')
		return (ft_putnbr(va_arg(*args, unsigned int), 10, 0));
	else if (c == 'x' || c == 'X')
		return (ft_putnbr(va_arg(*args, unsigned int), 16, c == 'X'));
	else if (c == '%')
		return (ft_putchar('%'));
	return (ft_putchar(c));
}

int	ft_printf(const char *format, ...)
{
	size_t		i;
	size_t		len_output;
	va_list		args;

	i = -1;
	len_output = 0;
	va_start(args, format);
	while (format[++i])
	{
		if (format[i] == '%')
			len_output += ft_conversions(format[++i], &args);
		else
			len_output += ft_putchar(format[i]);
	}
	va_end(args);
	return (len_output);
}
