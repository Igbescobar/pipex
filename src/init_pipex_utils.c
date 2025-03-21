/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pipex_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igngonza <igngonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 13:22:28 by igngonza          #+#    #+#             */
/*   Updated: 2025/03/20 16:05:22 by igngonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "pipex.h"

void	is_here_doc_active(t_pipex *pipex, int argc, char **argv)
{
	if (argc > 1 && ft_strncmp(argv[1], "here_doc", 8) == 0)
		pipex->here_doc = 1;
	else
		pipex->here_doc = 0;
}

void	cmd_counter(t_pipex *pipex, int argc)
{
	if (pipex->here_doc)
		pipex->cmd_count = argc - 4;
	else
		pipex->cmd_count = argc - 3;
}