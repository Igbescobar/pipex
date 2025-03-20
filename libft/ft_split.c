/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igngonza <igngonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 15:54:56 by igngonza          #+#    #+#             */
/*   Updated: 2024/04/09 18:59:36 by igngonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

static size_t	ft_find_total_tokens(const char *s, char c)
{
	size_t	ret;

	ret = 0;
	while (*s)
	{
		if (*s != c)
		{
			++ret;
			while (*s && *s != c)
				++s;
		}
		else
			++s;
	}
	return (ret);
}

static char	**ft_memory_allocation(const char *s, char c)
{
	char	**ret;

	ret = malloc(sizeof(char *) * (ft_find_total_tokens(s, c) + 1));
	if (!ret)
	{
		free(ret);
		ret = NULL;
	}
	return (ret);
}

static char	**ft_free_memory(char **ret)
{
	int	j;

	j = 0;
	while (ret[j])
	{
		free(ret[j]);
		j++;
	}
	free(ret);
	return (NULL);
}

char	**ft_split(const char *s, char c)
{
	char	**ret;
	size_t	i;
	size_t	len;

	i = 0;
	ret = ft_memory_allocation(s, c);
	while (*s && ret)
	{
		if (*s != c)
		{
			len = 0;
			while (*s && *s != c && ++len)
				++s;
			ret[i] = ft_substr(s - len, 0, len);
			if (!ret[i])
				ret = ft_free_memory(ret);
			i++;
		}
		else
			++s;
	}
	if (ret != NULL)
		ret[i] = NULL;
	return (ret);
}
/*int	main(void)
{
	char	**str_array;

	str_array = ft_split("hello!", ' ');
	for (int i = 0; str_array[i] != NULL; i++)
		printf("%s\n", str_array[i]);
	return (0);
}*/
