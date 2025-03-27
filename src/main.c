/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igngonza <igngonza@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 13:15:03 by igngonza          #+#    #+#             */
/*   Updated: 2025/03/27 11:55:33 by igngonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main(int argc, char **argv, char **envp)
{
  t_pipex pipex;

  init_pipex(&pipex, argc, argv);
  check_args(&pipex, argc, argv);
  parse_cmds(&pipex, argv);
  parse_paths(&pipex, argv, envp);

  exec(&pipex);

  cleanup(&pipex);

  return (0);
}