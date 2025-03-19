/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pipex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igngonza <igngonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 13:16:03 by igngonza          #+#    #+#             */
/*   Updated: 2025/03/19 13:16:05 by igngonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	init_pipex(t_pipex *pipex, int argc, char **argv)
{
	is_here_doc_active(pipex, argc, argv);
	cmd_counter(pipex, argc);
	pipex->in_fd = open(argv[1], O_RDONLY);
	if (pipex->in_fd == -1)
	{
		perror("Error opening input file");
		pipex->is_invalid_infile = 1;
	}
	pipex->out_fd = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (pipex->out_fd == -1)
	{
		perror("Error opening output file");
		exit(1);
	}
	pipex->cmd_paths = NULL;
	pipex->cmd_args = NULL;
}