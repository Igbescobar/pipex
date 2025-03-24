/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pipex_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igngonza <igngonza@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 13:22:28 by igngonza          #+#    #+#             */
/*   Updated: 2025/03/24 11:18:53 by igngonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

#include "pipex.h"

void	handle_here_doc(t_pipex *pipex, char *delimiter)
{
	char *line;
	int temp_fd;

	temp_fd = open(".here_doc_tmp", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (temp_fd < 0)
		handle_error("Error: Failed to create temporary file for here_doc");

	while (1)
	{
		ft_printf("here_doc> ");
		line = get_next_line(STDIN_FILENO);
		if (!line)
			break ;
		if (ft_strncmp(line, delimiter, ft_strlen(delimiter)) == 0
			&& line[ft_strlen(delimiter)] == '\n')
		{
			free(line);
			break ;
		}
		write(temp_fd, line, ft_strlen(line));
		free(line);
	}
	close(temp_fd);

	pipex->in_fd = open(".here_doc_tmp", O_RDONLY);
	if (pipex->in_fd < 0)
		handle_error("Error: Failed to open temporary file for here_doc");
}