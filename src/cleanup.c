/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igngonza <igngonza@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 16:10:02 by igngonza          #+#    #+#             */
/*   Updated: 2025/03/26 13:23:14 by igngonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void cleanup(t_pipex *pipex)
{
	int i;

	if (pipex->cmd_paths)
	{
		i = 0;
		while (pipex->cmd_paths[i])
			free(pipex->cmd_paths[i++]);
		free(pipex->cmd_paths);
	}

	if (pipex->cmd_args)
	{
		i = 0;
		while (pipex->cmd_args[i])
		{
			int j = 0;
			while (pipex->cmd_args[i][j])
				free(pipex->cmd_args[i][j++]);
			free(pipex->cmd_args[i++]);
		}
		free(pipex->cmd_args);
	}

	if (pipex->in_fd != -1)
		close(pipex->in_fd);
	if (pipex->out_fd != -1)
		close(pipex->out_fd);
}
