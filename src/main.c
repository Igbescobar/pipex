/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igngonza <igngonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 13:15:03 by igngonza          #+#    #+#             */
/*   Updated: 2025/03/31 17:16:23 by igngonza         ###   ########.fr       */
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
	if (argc < here_doc_checker(argv[1], &pipex))
		return (handle_msg(ERR_INPUT));
	init_files(argv, argc, &pipex);
	parse_cmds(&pipex, argv);
	parse_paths(&pipex, argv, envp);
	create_pipes(&pipex);
	pipex.idx = -1;
	while (++(pipex.idx) < pipex.cmd_count)
		create_child_process(&pipex, envp);
	close_pipes(&pipex);
	while ((last_exit_id = waitpid(-1, &status, 0)) > 0)
	{
		if (WIFEXITED(status) && pipex.pid == last_exit_id)
			last_exit_status = WEXITSTATUS(status);
	}
	parent_free(&pipex);
	return (last_exit_status);
}
