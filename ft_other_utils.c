/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_other_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wteles-d <wteles-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 17:50:51 by wteles-d          #+#    #+#             */
/*   Updated: 2023/05/15 17:57:36 by wteles-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "libftprintf.h"

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
