/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igngonza <igngonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 11:27:00 by igngonza          #+#    #+#             */
/*   Updated: 2024/03/20 13:00:53 by igngonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void	*ft_calloc(size_t count, size_t size)
{
	void	*result;

	result = (void *)malloc(count * size);
	if (result != NULL)
		ft_memset(result, 0, count * size);
	return (result);
}

/*int	main(void)
{
	void *pointer = calloc(10, 4);
	// void *pointer2 = ft_calloc(10, 4);
	printf("%p\n", pointer);
	return (0);
}*/