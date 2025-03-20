/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igngonza <igngonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 13:15:03 by igngonza          #+#    #+#             */
/*   Updated: 2025/03/20 15:45:52 by igngonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipex pipex;

	(void)envp;
	init_pipex(&pipex, argc, argv);
	check_args(&pipex, argc, argv);
	printf("Number of commands: %d\n", pipex.cmd_count);
	printf("Is here_doc being used: %d\n", pipex.here_doc);
	printf("Input file descriptor: %d\n", pipex.in_fd);
	printf("Output file descriptor: %d\n", pipex.out_fd);
	printf("Is input file invalid: %d\n", pipex.is_invalid_infile);
	// parse_cmds(&pipex, argv);
	// parse_args(&pipex, argv, envp);

	// while (pipex.cmd_count > 0)
	//	exec(&pipex);

	// cleanup(&pipex);

	return (0);
}