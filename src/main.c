/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igngonza <igngonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 13:15:03 by igngonza          #+#    #+#             */
/*   Updated: 2025/03/24 16:56:48 by igngonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	print_parsed_args(t_pipex *pipex)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	printf("\n===== Parsed Arguments =====\n");
	printf("Number of commands: %d\n", pipex->cmd_count);
	while (i < pipex->cmd_count)
	{
		printf("Command %d: ", i);
		j = 0;
		while (pipex->cmd_args[i][j])
		{
			printf("\"%s\" ", pipex->cmd_args[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	printf("============================\n\n");
}

void	print_cmd_paths(t_pipex *pipex)
{
	int	i;

	i = 0;
	printf("\n===== Command Paths =====\n");
	while (pipex->cmd_paths && pipex->cmd_paths[i])
	{
		printf("Path %d: %s\n", i, pipex->cmd_paths[i]);
		i++;
	}
	printf("=========================\n\n");
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex pipex;

	init_pipex(&pipex, argc, argv);
	check_args(&pipex, argc, argv);
	parse_cmds(&pipex, argv);
	parse_paths(&pipex, argv, envp);

	// print_parsed_args(&pipex);
	// print_cmd_paths(&pipex);

	exec(&pipex);

	cleanup(&pipex);

	return (0);
}