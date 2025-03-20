/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igngonza <igngonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 13:16:21 by igngonza          #+#    #+#             */
/*   Updated: 2025/03/20 15:26:26 by igngonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <unistd.h>

typedef struct s_pipex
{
	int		in_fd;
	int		out_fd;
	int		here_doc;
	int		is_invalid_infile;
	char	**cmd_paths;
	char	***cmd_args;
	int		cmd_count;
}			t_pipex;

void		init_pipex(t_pipex *pipex, int argc, char **argv);
void		check_args(t_pipex *pipex, int argc, char **argv);
void		parse_cmds(t_pipex *pipex, char **argv);
void		parse_args(t_pipex *pipex, char **argv, char **envp);
void		exec(t_pipex *pipex);
void		cleanup(t_pipex *pipex);

void		is_here_doc_active(t_pipex *pipex, int argc, char **argv);
void		cmd_counter(t_pipex *pipex, int argc);

#endif