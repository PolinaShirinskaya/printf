/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_snd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adian <adian@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 11:33:04 by adian             #+#    #+#             */
/*   Updated: 2022/01/12 11:55:09 by adian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(char c)
{
	return (write(1, &c, 1));
}

int	ft_print_str(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (write(1, "(null)", 6));
	while (*s)
		i += write(1, &*s++, 1);
	return (i);
}

int	ft_print_nbr(int n)
{
	long	ret;

	if (n == -2147483648)
		return (write(1, "-2147483648", 11));
	ret = 0;
	if (n < 0)
	{
		ret += ft_print_char('-');
		n = n * -1;
	}
	if (n >= 10)
	{
		ret += ft_print_nbr(n / 10);
		ret += ft_print_nbr(n % 10);
	}
	else
		ret += ft_print_char(n + '0');
	return (ret);
}

int	ft_print_unsigned(unsigned int n)
{
	unsigned long	ret;

	ret = 0;
	if (n >= 10)
	{
		ret += ft_print_unsigned(n / 10);
		ret += ft_print_unsigned(n % 10);
	}
	else
		ret += ft_print_char(n + '0');
	return (ret);
}
