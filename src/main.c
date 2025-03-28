/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igngonza <igngonza@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 13:15:03 by igngonza          #+#    #+#             */
/*   Updated: 2025/03/28 15:21:06 by igngonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main(int argc, char **argv, char **envp)
{
  t_pipex pipex;
  int status;
  int last_exit_status;
  int pid;

  last_exit_status = 0;
  if (argc < here_doc_checker(argv[1], &pipex))
    return (handle_msg(ERR_INPUT));
  init_files(argv, argc, &pipex);
  parse_cmds(&pipex, argv);
  parse_paths(&pipex, argv, envp);
  create_pipes(&pipex);
  pipex.idx = -1;
  while (++(pipex.idx) < pipex.cmd_count)
    create_child_process(pipex, envp);
  close_pipes(&pipex);
  while ((pid = waitpid(-1, &status, 0)) > 0)
  {
    if ((status & 0x7F) == 0)
      last_exit_status = (status >> 8) & 0xFF;
  }
  parent_free(&pipex);
  return (last_exit_status);
}
