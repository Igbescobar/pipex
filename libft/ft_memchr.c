/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igngonza <igngonza@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 15:36:08 by igngonza          #+#    #+#             */
/*   Updated: 2024/04/01 20:28:10 by igngonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*source;

	source = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (source[i] == (unsigned char)c)
			return (&source[i]);
		i++;
	}
	return (NULL);
}

/*int	main(void)
{
	char	*src;

	src = "/|\x12\xff\x09\0\x42\042\0\42|\\";
	printf("%p\n", ft_memchr(src, '\0', 12));
	printf("%p", memchr(src, '\0', 12));
	return (0);
}*/
