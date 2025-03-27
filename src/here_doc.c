/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igngonza <igngonza@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 15:44:47 by igngonza          #+#    #+#             */
/*   Updated: 2025/03/27 19:06:38 by igngonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int here_doc_checker(char *arg, t_pipex *pipex)
{
  if (!ft_strncmp("here_doc", arg, 9))
  {
    pipex->here_doc = 1;
    return (6);
  }
  else
  {
    pipex->here_doc = 0;
    return (5);
  }
}

void handle_here_doc(char *limiter, t_pipex *pipex)
{
  int file;
  char *buf;

  file = open(".heredoc_tmp", O_CREAT | O_WRONLY | O_TRUNC, 0644);
  if (file < 0)
    handle_error(ERR_HEREDOC);
  while (1)
  {
    write(1, "heredoc> ", 9);
    buf = get_next_line(STDIN_FILENO);
    if (!buf)
      break;
    if (!ft_strncmp(limiter, buf, ft_strlen(limiter)) && buf[ft_strlen(limiter)] == '\n')
    {
      free(buf);
      break;
    }
    write(file, buf, ft_strlen(buf));
    free(buf);
  }
  close(file);
  pipex->in_fd = open(".heredoc_tmp", O_RDONLY);
  if (pipex->in_fd < 0)
  {
    unlink(".heredoc_tmp");
    handle_error(ERR_HEREDOC);
  }
}
