/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convertion_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wteles-d <wteles-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 17:49:19 by wteles-d          #+#    #+#             */
/*   Updated: 2023/05/18 19:44:34 by wteles-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include "libftprintf.h"

size_t	ft_putnbr(int n)
{
	char			c;
	long			nbr;
	size_t			counter;

	counter = 0;
	nbr = (long)n;
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr *= -1;
		counter++;
	}
	if (nbr > 9)
		counter += ft_putnbr(nbr / 10);
	c = nbr % 10 + '0';
	counter += ft_putchar(c);
	return (counter);
}

int	check_base_size_and_errors(char *s1)
{
	int	j;
	int	k;

	j = 0;
	k = 0;
	while (s1 && s1[j])
	{
		if (s1[j] == '+' || s1[j] == '-')
			return (1);
		k = j + 1;
		while (s1[k])
		{
			if (s1[j] == s1[k])
				return (1);
			k++;
		}
		j++;
	}
	if (j <= 1)
		return (1);
	return (j);
}

size_t	ft_putnbr_base(int nbr, char *base)
{
	long			longn;
	int				baselen;
	size_t			counter;

	counter = 0;
	longn = (long)nbr;
	baselen = check_base_size_and_errors(base);
	if (baselen <= 1)
		return (counter);
	if (longn == -2147483648)
	{
		counter += ft_putchar('-');
		longn = 2147483648;
	}
	if (longn < 0)
	{
		longn = longn * (-1);
		counter += ft_putchar('-');
	}
	if (longn > baselen)
		counter += ft_putnbr_base(longn / baselen, base);
	counter += ft_putchar(base[longn % baselen]);
	return (counter);
}

size_t	ft_convert_ptr(unsigned int long p, char *base)
{
	size_t				counter;
	unsigned int long	baselen;
	unsigned int long	converted;

	counter = 0;
	converted = p;
	baselen = check_base_size_and_errors(base);
	if (baselen <= 1)
		return (counter);
	if (converted > baselen)
		counter += ft_convert_ptr(converted / baselen, base);
	counter += ft_putchar(base[converted % baselen]);
	return (counter);
}

size_t	ft_unsigned_putnbr(int n)
{
	char			c;
	unsigned int	nbr;
	size_t			counter;
	
	counter = 0;
	nbr = (unsigned int)n;
	if (nbr > 9)
		counter += ft_unsigned_putnbr(nbr / 10);
	c = nbr % 10 + '0';
	counter += ft_putchar(c);
	return (counter);
}
