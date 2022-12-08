/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilali <hfilali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 21:23:27 by hfilali           #+#    #+#             */
/*   Updated: 2022/11/24 23:59:21 by hfilali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_help_print(va_list q, char c, int *i)
{
	int	cnt;

	cnt = 0;
	if (c == 'c')
		cnt += ft_putchar(va_arg(q, int));
	else if (c == 's')
		cnt += ft_putstr(va_arg(q, char *));
	else if (c == 'X')
		cnt += ft_putnbr_base(va_arg(q, unsigned int), "0123456789ABCDEF");
	else if (c == 'x')
		cnt += ft_putnbr_base(va_arg(q, unsigned int), "0123456789abcdef");
	else if (c == 'p')
		cnt += ft_putstr("0x") + ft_putnbr_base(va_arg(q, unsigned long),
				"0123456789abcdef");
	else if (c == 'u')
		cnt += ft_putnbr(va_arg(q, unsigned int));
	else if (c == 'd' || c == 'i')
		cnt += ft_putnbr(va_arg(q, int));
	else if (c == '%')
		cnt += ft_putchar('%');
	else
		(*i)--;
	return (cnt);
}

int	ft_printf(const char *x, ...)
{
	va_list	z;
	int		nb;
	int		y;

	va_start(z, x);
	y = -1;
	nb = 0;
	while (x[++y])
	{
		if (x[y] == '%')
		{
			y++;
			if (!x[y])
				return (nb);
			nb += ft_help_print(z, x[y], &y);
		}
		else
			nb += ft_putchar(x[y]);
	}
	va_end(z);
	return (nb);
}
