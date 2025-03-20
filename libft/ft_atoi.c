/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igngonza <igngonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 11:07:22 by igngonza          #+#    #+#             */
/*   Updated: 2025/01/22 16:29:35 by igngonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

long	ft_atoi(const char *str)
{
	long	i;
	int		sign;
	long	result;
	long	counter;

	i = 0;
	sign = 1;
	result = 0;
	counter = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' || str[i] == '\v'
		|| str[i] == '\r' || str[i] == '\f')
		i++;
	while ((str[i] == '-' || str[i] == 43) && (counter < 1))
	{
		if (str[i] == '-')
			sign *= -1;
		counter = 1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	return (result * sign);
}

/*int	main(void)
{
	char	n[40] = "+1234";
	int		i1;
	int		i2;

	i1 = atoi(n);
	i2 = ft_atoi(n);
	printf("%d\n%d\n", i1, i2);
	return (0);
}*/
