/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igngonza <igngonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 11:56:12 by igngonza          #+#    #+#             */
/*   Updated: 2024/12/23 11:28:25 by igngonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>

int	ft_printf(char const *s, ...);
int	ft_print_char(char c);
int	ft_print_str(char *s);
int	ft_print_nbr(int nb);
int	ft_print_nbr_base(unsigned long nb, char *base);
int	ft_print_ptr(unsigned long ptr);

#endif