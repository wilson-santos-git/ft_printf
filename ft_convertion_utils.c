/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convertion_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wteles-d <wteles-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 17:49:19 by wteles-d          #+#    #+#             */
/*   Updated: 2023/05/15 17:58:20 by wteles-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "libftprintf.h"

void	ft_putnbr(int n)
{
	long	nbr;
	char	c;

	nbr = (long)n;
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr *= -1;
	}
	if (nbr > 9)
		ft_putnbr(nbr / 10);
	c = nbr % 10 + '0';
	write(1, &c, 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int				baselen;
	long			longn;

	longn = (long)nbr;
	baselen = check_base_size_and_errors(base);
	if (baselen <= 1)
		return ;
	if (longn == -2147483648)
	{
		ft_putchar('-');
		longn = 2147483648;
	}
	if (longn < 0)
	{
		longn = longn * (-1);
		ft_putchar('-');
	}
	if (longn > baselen)
		ft_putnbr_base(longn / baselen, base);
	ft_putchar(base[longn % baselen]);
}

void	ft_convert_ptr(unsigned int long p, char *base)
{
	unsigned int long	baselen;
	unsigned int long	converted;

	converted = p;
	baselen = check_base_size_and_errors(base);
	if (baselen <= 1)
		return ;
	if (converted > baselen)
		ft_convert_ptr(converted / baselen, base);
	ft_putchar(base[converted % baselen]);
}

void	ft_unsigned_putnbr(int n)
{
	unsigned int	nbr;
	char			c;

	nbr = (unsigned int)n;
	if (nbr > 9)
		ft_putnbr(nbr / 10);
	c = nbr % 10 + '0';
	write(1, &c, 1);
}
