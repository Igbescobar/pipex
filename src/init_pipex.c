/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pipex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igngonza <igngonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 13:16:03 by igngonza          #+#    #+#             */
/*   Updated: 2025/03/20 16:31:33 by igngonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	open_input_file(t_pipex *pipex, char *filename)
{
	pipex->in_fd = open(filename, O_RDONLY);
	if (pipex->in_fd == -1)
	{
		handle_error("Error opening input file");
		pipex->is_invalid_infile = 1;
	}
}

static void	open_output_file(t_pipex *pipex, char *filename, int here_doc)
{
	int	flags;

	flags = O_WRONLY | O_CREAT;
	if (here_doc)
		flags |= O_APPEND;
	else
		flags |= O_TRUNC;
	pipex->out_fd = open(filename, flags, 0777);
	if (pipex->out_fd == -1)
	{
		handle_error("Error opening output file");
		exit(1);
	}
}

void	init_pipex(t_pipex *pipex, int argc, char **argv)
{
	pipex->is_invalid_infile = 0;
	pipex->cmd_paths = NULL;
	pipex->cmd_args = NULL;
	is_here_doc_active(pipex, argc, argv);
	cmd_counter(pipex, argc);
	if (!pipex->here_doc)
		open_input_file(pipex, argv[1]);
	else
		pipex->in_fd = STDIN_FILENO;
	open_output_file(pipex, argv[argc - 1], pipex->here_doc);
}
