/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igngonza <igngonza@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 16:10:02 by igngonza          #+#    #+#             */
/*   Updated: 2025/03/27 19:04:32 by igngonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void parent_free(t_pipex *pipex)
{
  int i;
  int j;

  i = 0;
  close(pipex->in_fd);
  close(pipex->out_fd);
  if (pipex->here_doc)
    unlink(".heredoc_tmp");
  while (pipex->cmd_paths[i])
  {
    free(pipex->cmd_paths[i]);
    i++;
  }
  free(pipex->cmd_paths);
  i = 0;
  while (pipex->cmd_args[i])
  {
    j = 0;
    while (pipex->cmd_args[i][j])
    {
      free(pipex->cmd_args[i][j]);
      j++;
    }
    free(pipex->cmd_args[i]);
    i++;
  }
  free(pipex->cmd_args);
  free(pipex->pipes);
}

void child_free(t_pipex *pipex)
{
  int i;

  i = 0;
  while (pipex->cmd_args[i])
  {
    free(pipex->cmd_args[i]);
    i++;
  }
  free(pipex->cmd_args);
  free(pipex->cmd_paths);
}

void pipe_free(t_pipex *pipex)
{
  close(pipex->in_fd);
  close(pipex->out_fd);
  if (pipex->here_doc)
    unlink(".heredoc_tmp");
  free(pipex->pipes);
  handle_msg(ERR_ENVP);
  exit(1);
}
