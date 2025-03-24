/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igngonza <igngonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 11:58:42 by igngonza          #+#    #+#             */
/*   Updated: 2024/12/23 11:33:43 by igngonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	ft_print_format(char specifier, va_list ap)
{
	int	count;

	count = 0;
	if (specifier == '%')
		count = ft_print_char('%');
	else if (specifier == 'c')
		count = ft_print_char(va_arg(ap, int));
	else if (specifier == 's')
		count = ft_print_str(va_arg(ap, char *));
	else if (specifier == 'p')
		count = ft_print_ptr(va_arg(ap, unsigned long));
	else if (specifier == 'd' || specifier == 'i')
		count = ft_print_nbr(va_arg(ap, int));
	else if (specifier == 'u')
		count = ft_print_nbr_base(va_arg(ap, unsigned int), "0123456789");
	else if (specifier == 'x')
		count = ft_print_nbr_base(va_arg(ap, unsigned int), "0123456789abcdef");
	else if (specifier == 'X')
		count = ft_print_nbr_base(va_arg(ap, unsigned int), "0123456789ABCDEF");
	else
		count = write(1, &specifier, 1);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		i;
	int		count;

	va_start(ap, format);
	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
			count += ft_print_format(format[i++ + 1], ap);
		else if (format[i] == '%' && !format[i + 1])
		{
			va_end(ap);
			return (-1);
		}
		else
		{
			write(1, &format[i], 1);
			count++;
		}
		i++;
	}
	va_end(ap);
	return (count);
}
