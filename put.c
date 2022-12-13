/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbesson <fbesson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 14:47:37 by fbesson           #+#    #+#             */
/*   Updated: 2022/12/13 16:21:32 by fbesson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_putchar(int c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (write(1, "(null)", 6));
	while (str[i] != '\0')
		i++;
	return (write(1, str, i));
}

int	ft_putnbr(unsigned long nb, unsigned int base, int X)
{
	static size_t	len;

	len = 0;
	if (nb >= base)
		ft_putnbr((nb / base), base, X);
	len += ft_putchar(HEX_BASE[nb % base + X * 16]);
	return (len);
}

int	ft_putdecimal(va_list *args)
{
	long		nb;

	nb = va_arg(*args, int);
	if (nb < 0)
		return (ft_putchar('-') + ft_putnbr(nb * -1, 10, 0));
	return (ft_putnbr(nb, 10, 0));
}
