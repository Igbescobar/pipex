/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igngonza <igngonza@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 15:44:47 by igngonza          #+#    #+#             */
/*   Updated: 2025/04/03 11:47:05 by igngonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	check_and_set_heredoc(char *arg, t_pipex *pipex)
{
	if (!ft_strncmp("here_doc", arg, 9))
	{
		pipex->here_doc = 1;
		return (6);
	}
	pipex->here_doc = 0;
	return (5);
}

int	create_heredoc_file(void)
{
	int	fd;

	fd = open(".heredoc_tmp", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd < 0)
		handle_error(ERR_HEREDOC);
	return (fd);
}

void	process_heredoc_input(char *limiter, int fd)
{
	char	*buf;
	size_t	lim_len;

	lim_len = ft_strlen(limiter);
	while (1)
	{
		write(1, "heredoc> ", 9);
		buf = get_next_line(STDIN_FILENO);
		if (!buf)
			break ;
		if (!ft_strncmp(limiter, buf, lim_len) && buf[lim_len] == '\n')
		{
			free(buf);
			break ;
		}
		write(fd, buf, ft_strlen(buf));
		free(buf);
	}
}

void	finalize_heredoc(t_pipex *pipex)
{
	pipex->in_fd = open(".heredoc_tmp", O_RDONLY);
	if (pipex->in_fd < 0)
	{
		unlink(".heredoc_tmp");
		handle_error(ERR_HEREDOC);
	}
}

void	handle_heredoc(char *limiter, t_pipex *pipex)
{
	int	fd;

	fd = create_heredoc_file();
	process_heredoc_input(limiter, fd);
	close(fd);
	finalize_heredoc(pipex);
}
