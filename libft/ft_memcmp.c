/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igngonza <igngonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 11:26:06 by igngonza          #+#    #+#             */
/*   Updated: 2024/03/19 12:18:24 by igngonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*first;
	const unsigned char	*second;

	i = 0;
	first = (unsigned char *)s1;
	second = (unsigned char *)s2;
	while (i < n)
	{
		if (first[i] != second[i])
			return (first[i] - second[i]);
		i++;
	}
	return (0);
}

/*int	main(void)
{
	char	*arr;
	char	*arr2;

	arr = "t\200";
	arr2 = "t\0";
	printf("%d\n", ft_memcmp(arr, arr2, 2));
	printf("%d\n", memcmp(arr, arr2, 2));
	return (0);
}*/
