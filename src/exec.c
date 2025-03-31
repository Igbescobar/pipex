/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igngonza <igngonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 15:48:20 by igngonza          #+#    #+#             */
/*   Updated: 2025/03/31 17:18:30 by igngonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	sub_dup2(int zero, int first)
{
	dup2(zero, 0);
	dup2(first, 1);
}

void	create_child_process(t_pipex *pipex, char **envp)
{
	char	*cmd;
	char	**cmd_args;
	int		saved_stdout;

	pipex->pid = fork();
	if (pipex->pid == -1)
		handle_error("Fork failed");
	if (pipex->pid == 0)
	{
		saved_stdout = dup(STDOUT_FILENO);
		if (pipex->idx == 0)
			sub_dup2(pipex->in_fd, pipex->pipes[1]);
		else if (pipex->idx == pipex->cmd_count - 1)
		{
			if (pipex->out_fd != -1)
				sub_dup2(pipex->pipes[2 * pipex->idx - 2], pipex->out_fd);
			else
			{
				close(pipex->pipes[2 * pipex->idx - 2]);
				exit(1);
			}
		}
		else
			sub_dup2(pipex->pipes[2 * pipex->idx - 2], pipex->pipes[2
				* pipex->idx + 1]);
		close_pipes(pipex);
		cmd = pipex->cmd_paths[pipex->idx];
		cmd_args = pipex->cmd_args[pipex->idx];
		if (!cmd)
		{
			dup2(saved_stdout, STDOUT_FILENO);
			close(saved_stdout);
			ft_printf("%s: command not found\n",
				pipex->cmd_args[pipex->idx][0]);
			exit(127);
		}
		execve(cmd, cmd_args, envp);
	}
}
