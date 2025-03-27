/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igngonza <igngonza@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 13:15:45 by igngonza          #+#    #+#             */
/*   Updated: 2025/03/27 18:21:54 by igngonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void create_pipes(t_pipex *pipex)
{
  int i;

  i = 0;
  while (i < pipex->cmd_count - 1)
  {
    if (pipe(pipex->pipes + 2 * i) < 0)
      parent_free(pipex);
    i++;
  }
}

void close_pipes(t_pipex *pipex)
{
  int i;

  i = 0;
  while (i < (pipex->pipe_count))
  {
    close(pipex->pipes[i]);
    i++;
  }
}