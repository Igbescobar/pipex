/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igngonza <igngonza@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 16:37:53 by igngonza          #+#    #+#             */
/*   Updated: 2024/04/03 21:02:51 by igngonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*result;

	if (!s || start > ft_strlen(s))
		return (ft_strdup(""));
	if (ft_strlen(s + start) < len)
		len = ft_strlen(s + start);
	result = malloc((len + 1) * sizeof(char));
	if (!result)
		return (0);
	else
	{
		ft_memcpy(result, s + start, len);
		result[len] = '\0';
	}
	return (result);
}

/*int	main(void)
{
	char	*arr;

	arr = "hello there";
	printf("%s\n", ft_substr("", 1, 1));
	return (0);
}*/
