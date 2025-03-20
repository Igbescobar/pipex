/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igngonza <igngonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 18:25:32 by igngonza          #+#    #+#             */
/*   Updated: 2024/03/18 19:16:05 by igngonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;

	i = 0;
	if (size > 0)
	{
		while (src[i] != '\0' && i < size - 1)
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	while (src[i] != '\0')
		i++;
	return (i);
}
/*int	main(void)
{
	char	arr[4];
	char	arr_two[] = "i like pineapple";
	int		w;

	// w = ft_strlcpy(arr, arr_two, 5);
		w = strlcpy(arr, arr_two, 5);
	printf("%s, %d", arr, w);
	return (0);
}*/
