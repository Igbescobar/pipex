/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igngonza <igngonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 11:56:49 by igngonza          #+#    #+#             */
/*   Updated: 2024/12/23 11:34:11 by igngonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(char c)
{
	return (write(1, &c, 1));
}

int	ft_print_str(char *str)
{
	int	i;

	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	i = 0;
	while (str[i])
	{
		write(1, str + i, 1);
		i++;
	}
	return (i);
}

int	ft_print_ptr(unsigned long ptr)
{
	int	n;

	if (!ptr)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	n = 0;
	n += ft_print_str("0x");
	n += ft_print_nbr_base(ptr, "0123456789abcdef");
	return (n);
}

int	ft_print_nbr(int n)
{
	unsigned int	aux_int;
	int				number_chars_printed;

	aux_int = 0;
	number_chars_printed = 0;
	if (n < 0)
	{
		ft_print_char('-');
		aux_int = -1 * n;
		++number_chars_printed;
	}
	else
		aux_int = n;
	if (aux_int > 9)
		number_chars_printed += ft_print_nbr(aux_int / 10);
	ft_print_char(aux_int % 10 + '0');
	++number_chars_printed;
	return (number_chars_printed);
}

int	ft_print_nbr_base(unsigned long n, char *base)
{
	int	number_chars_printed;
	int	len;

	number_chars_printed = 0;
	len = 0;
	while (base[len])
		++len;
	if (n >= (unsigned long)len)
		number_chars_printed += ft_print_nbr_base(n / len, base);
	ft_print_char(base[n % len]);
	++number_chars_printed;
	return (number_chars_printed);
}
