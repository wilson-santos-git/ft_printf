/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wteles-d <wteles-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:43:34 by wteles-d          #+#    #+#             */
/*   Updated: 2023/05/15 17:57:28 by wteles-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "libftprintf.h"

void	ft_found_arg(char c, va_list *al)
{
	if (c == 'c')
		ft_putchar(va_arg(*al, int));
	else if (c == 's')
		ft_print_str(va_arg(*al, char *));
	else if (c == 'p')
	{
		ft_print_str("0x");
		ft_convert_ptr(va_arg(*al, unsigned int long), "0123456789abcdef");
	}
	else if (c == 'd' || c == 'i')
		ft_putnbr(va_arg(*al, int));
	else if (c == 'u')
		ft_unsigned_putnbr(va_arg(*al, unsigned int));
	else if (c == 'x')
		ft_putnbr_base(va_arg(*al, int), "0123456789abcdef");
	else if (c == 'X')
		ft_putnbr_base(va_arg(*al, int), "0123456789ABCDEF");
	else if (c == '%')
		ft_putchar('%');
}

int	ft_printf(const char *str, ...)
{
	va_list	al;
	int		i;

	va_start(al, str);
	i = 0;
	while (str && str[i])
	{
		if (str[i] == '%')
		{
			ft_found_arg(str[i + 1], &al);
			i++;
		}
		else
			write(1, &str[i], 1);
		i++;
	}
	va_end(al);
	return (i);
}
