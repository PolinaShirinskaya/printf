/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adian <adian@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 11:32:21 by adian             #+#    #+#             */
/*   Updated: 2022/01/12 11:55:08 by adian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

int	ft_print_nbr(int n);
int	ft_print_unsigned(unsigned int n);
int	ft_print_x(char c, unsigned int n);
int	ft_print_char(char c);
int	ft_print_str(char *str);
int	ft_print_ptr(unsigned long p);
int	ft_printf(const char *first, ...);
#endif
