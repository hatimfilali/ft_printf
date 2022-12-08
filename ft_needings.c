/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_needings.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilali <hfilali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 21:23:08 by hfilali           #+#    #+#             */
/*   Updated: 2022/11/24 03:39:00 by hfilali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *str)
{
	int	i;
	int	cnt;

	if (!str)
		return (write(1, "(null)", 6));
	i = 0;
	cnt = 0;
	while (str[i])
	{
		cnt += ft_putchar(str[i]);
		i++;
	}
	return (cnt);
}

int	ft_putnbr_base(unsigned long nb, char *base)
{
	int	cnt;

	cnt = 0;
	if (nb >= 16)
		cnt += ft_putnbr_base(nb / 16, base);
	cnt += ft_putchar(base[nb % 16]);
	return (cnt);
}

int	ft_putnbr(long n)
{
	int	count;

	count = 0;
	if (n < 0)
	{
		n *= -1;
		count += write(1, "-", 1);
	}
	if (n > 9)
		count += ft_putnbr(n / 10);
	count += ft_putchar((n % 10) + 48);
	return (count);
}
