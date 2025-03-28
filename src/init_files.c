/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igngonza <igngonza@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 13:16:03 by igngonza          #+#    #+#             */
/*   Updated: 2025/03/28 15:30:12 by igngonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void get_infile(char **argv, t_pipex *pipex)
{
  if (pipex->here_doc)
    handle_here_doc(argv[2], pipex);
  else
  {
    pipex->in_fd = open(argv[1], O_RDONLY);
    if (pipex->in_fd < 0)
    {
      perror(argv[1]);
      pipex->in_fd = STDIN_FILENO;
    }
  }
}

void get_outfile(char *argv, t_pipex *pipex)
{
  if (pipex->here_doc)
    pipex->out_fd = open(argv, O_WRONLY | O_CREAT | O_APPEND, 0000644);
  else
    pipex->out_fd = open(argv, O_CREAT | O_RDWR | O_TRUNC, 0000644);
  if (pipex->out_fd < 0)
    handle_error(ERR_OUTFILE);
}

void init_files(char **argv, int argc, t_pipex *pipex)
{
  get_infile(argv, pipex);
  get_outfile(argv[argc - 1], pipex);
  pipex->cmd_count = argc - 3 - pipex->here_doc;
  pipex->pipe_count = 2 * (pipex->cmd_count - 1);
  pipex->pipes = (int *)malloc(sizeof(int) * (pipex->pipe_count));
  if (!pipex->pipes)
    handle_error(ERR_PIPE);
}
