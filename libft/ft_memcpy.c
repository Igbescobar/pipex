/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igngonza <igngonza@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 21:00:26 by igngonza          #+#    #+#             */
/*   Updated: 2024/04/03 21:00:30 by igngonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned int	i;
	char			*d;
	const char		*s;

	i = 0;
	d = (char *)dest;
	s = (const char *)src;
	while (i < n && (dest || src))
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}

/*int	main(void)
{
	char	arr[10];
	char	*arr2;

	arr2 = "hello there";
	ft_memcpy(((void *)0), ((void *)0), 3);
	printf("%s\n", arr);
	// memcpy((NULL), (NULL), 3);
	// printf("%s\n", arr);
	return (0);
}*/
