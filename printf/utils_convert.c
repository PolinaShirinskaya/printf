/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_convert.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adian <adian@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 11:33:32 by adian             #+#    #+#             */
/*   Updated: 2022/01/12 11:55:09 by adian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_convert_hex(unsigned int n, const char *base)
{
	char			*heap;
	int				len;
	unsigned long	c_dig;

	len = 0;
	c_dig = n;
	while (c_dig)
	{
		c_dig /= 16;
		len++;
	}
	heap = (char *)malloc((len + 1) * sizeof(char));
	if (!heap)
		return (0);
	heap[len] = 0;
	while (len--)
	{
		heap[len] = base[n % 16];
		n /= 16;
	}
	len = ft_print_str(heap);
	free(heap);
	return (len);
}

static int	ft_convert_p(unsigned long n, const char *base)
{
	char			*heap;
	int				len;
	unsigned long	c_dig;

	len = 0;
	c_dig = n;
	while (c_dig)
	{
		c_dig /= 16;
		len++;
	}
	heap = (char *)malloc((len + 1) * sizeof(char));
	if (!heap)
		return (0);
	heap[len] = 0;
	while (len--)
	{
		heap[len] = base[n % 16];
		n /= 16;
	}
	len = ft_print_str(heap);
	free(heap);
	return (len);
}

int	ft_print_x(char c, unsigned int n)
{
	if (n == 0)
		return (ft_print_char(48));
	if (c == 'X')
		return (ft_convert_hex(n, "0123456789ABCDEF"));
	return (ft_convert_hex(n, "0123456789abcdef"));
}

int	ft_print_ptr(unsigned long p)
{
	write(1, "0x", 2);
	if (p == 0)
		return (2 + ft_print_char(48));
	return (2 + ft_convert_p(p, "0123456789abcdef"));
}
