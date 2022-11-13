/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adian <adian@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 11:31:10 by adian             #+#    #+#             */
/*   Updated: 2022/01/12 11:55:08 by adian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static long	ft_type(const char *c, va_list arg)
{
	if (*c)
	{
		if (*c == 'c')
			return (ft_print_char(va_arg(arg, int)));
		if (*c == 's')
			return (ft_print_str(va_arg(arg, char *)));
		if (*c == 'd' || *c == 'i')
			return (ft_print_nbr(va_arg(arg, int)));
		if (*c == 'u')
			return (ft_print_unsigned(va_arg(arg, unsigned int)));
		if (*c == '%')
			return (ft_print_char('%'));
		if (*c == 'x' || *c == 'X')
			return (ft_print_x(*c, va_arg(arg, unsigned int)));
		if (*c == 'p')
			return (ft_print_ptr(va_arg(arg, unsigned long)));
	}
	return (0);
}

int	ft_printf(const char *first, ...)
{
	va_list	args;
	long	count;

	count = 0;
	if (!first)
		return (0);
	va_start(args, first);
	while (*first)
	{
		if (*first != '%')
		{
			count += write(1, &(*first), 1);
			first++;
		}
		if (*first && *first == '%')
		{
			count += ft_type(++first, args);
			first++;
		}
	}
	va_end(args);
	return (count);
}
