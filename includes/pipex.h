/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igngonza <igngonza@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 13:16:21 by igngonza          #+#    #+#             */
/*   Updated: 2025/03/27 10:21:29 by igngonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
#define PIPEX_H

#include "ft_printf.h"
#include "libft.h"
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

typedef struct s_pipex
{
  int in_fd;
  int out_fd;
  int here_doc;
  int is_invalid_infile;
  char **cmd_paths;
  char ***cmd_args;
  int cmd_count;
} t_pipex;

void init_pipex(t_pipex *pipex, int argc, char **argv);
void check_args(t_pipex *pipex, int argc, char **argv);
void parse_cmds(t_pipex *pipex, char **argv);
void parse_paths(t_pipex *pipex, char **argv, char **envp);
void handle_here_doc(char *limiter, int argc);
void exec(t_pipex *pipex);
void cleanup(t_pipex *pipex);
void usage(void);

void is_here_doc_active(t_pipex *pipex, int argc, char **argv);
void cmd_counter(t_pipex *pipex, int argc);
int open_file(char *argv, int i);
int get_next_line(char **line);
void error(void);

void handle_error(const char *message);

#endif