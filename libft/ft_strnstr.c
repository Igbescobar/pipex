/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igngonza <igngonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 10:41:15 by igngonza          #+#    #+#             */
/*   Updated: 2024/04/16 18:04:11 by igngonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

char	*ft_strnstr(const char *s, const char *need, size_t len)
{
	long unsigned int	i;
	long unsigned int	j;

	i = 0;
	if (need[i] == '\0')
		return ((char *)s);
	while (s[i] && i < len)
	{
		j = 0;
		while (s[i + j] == need[j] && i + j < len)
		{
			j++;
			if (need[j] == '\0')
				return ((char *)&s[i]);
		}
		i++;
	}
	return (NULL);
}

/*int	main(void)
{
	char	arr[] = "hellotherehola";
	char	arr1[] = "hello";

	printf("%p\n", (void *)ft_strnstr(arr, arr1, 2));
	printf("%p\n", (void *)strnstr(arr, arr1, 2));
	return (0);
}*/
