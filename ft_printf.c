/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wteles-d <wteles-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:43:34 by wteles-d          #+#    #+#             */
/*   Updated: 2023/05/12 20:08:55 by wteles-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

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

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_str(char *s)
{
	int	i;
	
	i = 0;
	while (s && s[i])
	{
		ft_putchar(s[i]);
		i++;
	}
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

void	ft_found_arg(char c, va_list *al)
{
	if (c == 'c')
		ft_putchar(va_arg(*al, int));
	else if (c == 's')
		ft_print_str(va_arg(*al, char *));
	else if (c == 'p')
		;
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

int ft_printf(const char *str, ...)
{
	va_list al;
	va_start(al, str);
	
	int	i = 0;
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

int main(void)
{
	void *p = malloc(5 * sizeof(char));
	ft_printf("%d %c %s %i %u %x %X %% %p\n", 123456, 'h', "yes", 52876, 345, 2412, 2412, p);
	printf("%d %c %s %i %u %x %X %% %p\n", 123456, 'h', "yes", 52876, 345, 2412, 2412, p);
}
