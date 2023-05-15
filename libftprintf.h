/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wteles-d <wteles-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 17:44:57 by wteles-d          #+#    #+#             */
/*   Updated: 2023/05/15 17:57:13 by wteles-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

void	ft_putnbr(int n);
void	ft_unsigned_putnbr(int n);
void	ft_putchar(char c);
void	ft_print_str(char *s);
int		check_base_size_and_errors(char *s1);
void	ft_putnbr_base(int nbr, char *base);
void	ft_convert_ptr(unsigned int long p, char *base);
void	ft_found_arg(char c, va_list *al);
int		ft_printf(const char *str, ...);

#endif