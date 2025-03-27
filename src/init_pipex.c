/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pipex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igngonza <igngonza@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 13:16:03 by igngonza          #+#    #+#             */
/*   Updated: 2025/03/27 10:34:58 by igngonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int open_file(char *argv, int i)
{
  int file;

  file = 0;
  if (i == 0)
    file = open(argv, O_WRONLY | O_CREAT | O_APPEND, 0777);
  else if (i == 1)
    file = open(argv, O_WRONLY | O_CREAT | O_TRUNC, 0777);
  else if (i == 2)
    file = open(argv, O_RDONLY, 0777);
  if (file == -1)
    error();
  return (file);
}

void usage(void)
{
  ft_putstr_fd("\033[31mError: Bad argument\n\e[0m", 2);
  ft_putstr_fd("Ex: ./pipex <file1> <cmd1> <cmd2> <...> <file2>\n", 1);
  ft_putstr_fd("    ./pipex \"here_doc\" <LIMITER> <cmd> <cmd1> <...> <file>\n", 1);
  exit(EXIT_SUCCESS);
}

void init_pipex(t_pipex *pipex, int argc, char **argv)
{
  pipex->is_invalid_infile = 0;
  pipex->cmd_paths = NULL;
  pipex->cmd_args = NULL;
  is_here_doc_active(pipex, argc, argv);
  cmd_counter(pipex, argc);
  if (pipex->here_doc)
  {
    pipex->out_fd = open_file(argv[argc - 1], 0);
    handle_here_doc(argv[2], argc);
  }
  else
  {
    pipex->out_fd = open_file(argv[argc - 1], 1);
    pipex->in_fd = open_file(argv[1], 2);
    dup2(pipex->in_fd, STDIN_FILENO);
  }
}
