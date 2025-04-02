/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igngonza <igngonza@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 13:15:03 by igngonza          #+#    #+#             */
/*   Updated: 2025/04/02 21:35:12 by igngonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;
	int		status;
	int		last_exit_status;
	int		last_exit_id;

	last_exit_status = 0;
	if (argc < check_and_set_heredoc(argv[1], &pipex))
		return (handle_msg(ERR_INPUT));
	init_files(argv, argc, &pipex);
	parse_cmds(&pipex, argv);
	parse_paths(&pipex, argv, envp);
	create_pipes(&pipex);
	pipex.idx = -1;
	while (++(pipex.idx) < pipex.cmd_count)
		create_child_process(&pipex, envp);
	close_pipes(&pipex);
	last_exit_id = waitpid(-1, &status, 0);
	while (last_exit_id > 0)
	{
		if (WIFEXITED(status) && pipex.pid == last_exit_id)
			last_exit_status = WEXITSTATUS(status);
		last_exit_id = waitpid(-1, &status, 0);
	}
	parent_free(&pipex);
	return (last_exit_status);
}
