/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igngonza <igngonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 13:15:03 by igngonza          #+#    #+#             */
/*   Updated: 2025/03/19 13:22:39 by igngonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipex pipex;

	init_pipex(&pipex, argc, argv);
	check_args(&pipex, argc, argv);
	parse_cmds(&pipex, argv);
	parse_args(&pipex, argv, envp);

	while (pipex.cmd_count > 0)
		exec(&pipex);

	cleanup(&pipex);

	return (0);
}