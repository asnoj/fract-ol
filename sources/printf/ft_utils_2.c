/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcrochet <jcrochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 06:39:28 by jcrochet          #+#    #+#             */
/*   Updated: 2025/11/12 03:24:57 by jcrochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

int	ft_puthex_upper(unsigned int n)
{
	char	*hex;
	int		count;
	char	c;

	hex = "0123456789ABCDEF";
	count = 0;
	if (n >= 16)
		count += ft_puthex_upper(n / 16);
	c = hex[n % 16];
	count += write(1, &c, 1);
	return (count);
}

int	ft_putptr(unsigned long int n, int i)
{
	int		count;
	char	*hex;
	char	c;

	hex = "0123456789abcdef";
	count = 0;
	if (!n)
		return (ft_putstr("(nil)"));
	if (i != 1)
	{
		count += ft_putstr("0x");
		i = 1;
	}
	if (n >= 16)
		count += ft_putptr(n / 16, 1);
	c = hex[n % 16];
	count += write(1, &c, 1);
	return (count);
}

int	ft_putdouble(double n, int precision)
{
	long	int_part;
	double	fract_part;
	int		count;
	int		i;

	count = 0;
	if (n < 0)
	{
		count += write(1, "-", 1);
		n = -n;
	}
	int_part = (long)n;
	fract_part = n - int_part;
	count += ft_putnbr(int_part);
	count += write(1, ".", 1);
	if (precision == 0)
		precision = 6;
	i = -1;
	while (++i < precision)
	{
		fract_part *= 10;
		count += ft_putchar((int)fract_part + '0');
		fract_part -= (int)fract_part;
	}
	return (count);
}
