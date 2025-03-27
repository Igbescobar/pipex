/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igngonza <igngonza@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 15:48:20 by igngonza          #+#    #+#             */
/*   Updated: 2025/03/27 18:49:05 by igngonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void sub_dup2(int zero, int first)
{
  dup2(zero, 0);
  dup2(first, 1);
}

void create_child_process(t_pipex pipex, char **envp)
{
  char *cmd;
  char **cmd_args;

  pipex.pid = fork();
  if (pipex.pid == -1)
    handle_error("Fork failed");
  if (pipex.pid == 0)
  {
    if (pipex.idx == 0)
      sub_dup2(pipex.in_fd, pipex.pipes[1]);
    else if (pipex.idx == pipex.cmd_count - 1)
      sub_dup2(pipex.pipes[2 * pipex.idx - 2], pipex.out_fd);
    else
      sub_dup2(pipex.pipes[2 * pipex.idx - 2], pipex.pipes[2 * pipex.idx + 1]);
    close_pipes(&pipex);
    cmd = pipex.cmd_paths[pipex.idx];
    cmd_args = pipex.cmd_args[pipex.idx];
    if (!cmd)
    {
      handle_pipe_msg(cmd_args[0]);
      child_free(&pipex);
      exit(1);
    }
    execve(cmd, cmd_args, envp);
  }
}
