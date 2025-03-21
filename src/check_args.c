/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igngonza <igngonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 13:15:45 by igngonza          #+#    #+#             */
/*   Updated: 2025/03/20 16:31:20 by igngonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	check_args(t_pipex *pipex, int argc, char **argv)
{
	int min_args;
	(void)argv;

	if (pipex->here_doc)
		min_args = 6;
	else
		min_args = 5;

	if (argc < min_args)
	{
		handle_error("Error: Too few arguments.");
		exit(1);
	}
}