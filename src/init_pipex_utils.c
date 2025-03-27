/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pipex_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igngonza <igngonza@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 13:22:28 by igngonza          #+#    #+#             */
/*   Updated: 2025/03/27 12:21:34 by igngonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void error(void)
{
  perror("\033[31mError");
  exit(EXIT_FAILURE);
}

void is_here_doc_active(t_pipex *pipex, int argc, char **argv)
{
  if (argc > 1 && ft_strncmp(argv[1], "here_doc", 8) == 0)
    pipex->here_doc = 1;
  else
    pipex->here_doc = 0;
}

void cmd_counter(t_pipex *pipex, int argc)
{
  if (pipex->here_doc)
    pipex->cmd_count = argc - 4;
  else
    pipex->cmd_count = argc - 3;
}

int get_next_line(char **line)
{
  char *buffer;
  int i;
  int r;
  char c;

  i = 0;
  r = 0;
  buffer = (char *)malloc(10000);
  if (!buffer)
    return (-1);
  r = read(0, &c, 1);
  while (r && c != '\n' && c != '\0')
  {
    if (c != '\n' && c != '\0')
      buffer[i] = c;
    i++;
    r = read(0, &c, 1);
  }
  buffer[i] = '\n';
  buffer[++i] = '\0';
  *line = buffer;
  if (r > 0)
    return (1);
  return (r);
}

void handle_here_doc(char *limiter, int argc)
{
  pid_t reader;
  int fd[2];
  char *line;

  if (argc < 6)
    usage();
  if (pipe(fd) == -1)
    error();
  reader = fork();
  if (reader == 0)
  {
    close(fd[0]);
    while (get_next_line(&line))
    {
      if (ft_strncmp(line, limiter, ft_strlen(limiter)) == 0 && line[ft_strlen(limiter)] == '\n')
      {
        free(line);
        break;
      }
      write(fd[1], line, ft_strlen(line));
      write(fd[1], "\n", 1);
      free(line);
    }
    close(fd[1]);
    exit(EXIT_SUCCESS);
  }
  else
  {
    close(fd[1]);
    dup2(fd[0], STDIN_FILENO);
    close(fd[0]);
    wait(NULL);
  }
}
