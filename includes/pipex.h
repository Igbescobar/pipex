/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igngonza <igngonza@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 13:16:21 by igngonza          #+#    #+#             */
/*   Updated: 2025/03/27 18:49:10 by igngonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
#define PIPEX_H

#include "ft_printf.h"
#include "libft.h"
#include "get_next_line.h"
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

#define ERR_INFILE "Infile"
#define ERR_OUTFILE "Outfile"
#define ERR_INPUT "Invalid number of arguments.\n"
#define ERR_PIPE "Pipe"
#define ERR_ENVP "Environment"
#define ERR_CMD "Command not found: "
#define ERR_HEREDOC "here_doc"

typedef struct s_pipex
{
  int in_fd;
  int out_fd;
  int here_doc;
  int is_invalid_infile;
  char **cmd_paths;
  char ***cmd_args;
  int cmd_count;
  int pipe_count;
  int *pipes;
  int idx;
  pid_t pid;
} t_pipex;

void init_files(char **argv, int argc, t_pipex *pipex);
void get_infile(char **argv, t_pipex *pipex);
void get_outfile(char *argv, t_pipex *pipex);
void create_pipes(t_pipex *pipex);
void close_pipes(t_pipex *pipex);

int here_doc_checker(char *arg, t_pipex *pipex);
void handle_here_doc(char *limiter, t_pipex *pipex);

void parse_cmds(t_pipex *pipex, char **argv);
void parse_paths(t_pipex *pipex, char **argv, char **envp);
void create_child_process(t_pipex pipex, char **envp);

void child_free(t_pipex *pipex);
void parent_free(t_pipex *pipex);

void handle_error(const char *message);
int handle_msg(char *err);
void handle_pipe_msg(char *arg);

#endif