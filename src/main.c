/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igngonza <igngonza@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 13:15:03 by igngonza          #+#    #+#             */
/*   Updated: 2025/03/27 18:38:17 by igngonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main(int argc, char **argv, char **envp)
{
  t_pipex pipex;

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
  waitpid(-1, NULL, 0);
  parent_free(&pipex);
  return (0);
}
