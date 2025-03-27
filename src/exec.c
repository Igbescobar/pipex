/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igngonza <igngonza@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 15:48:20 by igngonza          #+#    #+#             */
/*   Updated: 2025/03/26 18:44:57 by igngonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void create_pipe(int pipe_fd[2])
{
  if (pipe(pipe_fd) == -1)
    handle_error("Error: Pipe creation failed");
}

static pid_t create_child_process(void)
{
  pid_t pid;

  pid = fork();
  if (pid == -1)
    handle_error("Error: Fork failed");
  return (pid);
}

static void setup_child_process(t_pipex *pipex, int pipe_fd[2], int cmd_index)
{
  if (pipex->in_fd != -1)
    dup2(pipex->in_fd, STDIN_FILENO);
  if (cmd_index < pipex->cmd_count - 1)
    dup2(pipe_fd[1], STDOUT_FILENO);
  else
    dup2(pipex->out_fd, STDOUT_FILENO);
  close(pipe_fd[0]);
  close(pipe_fd[1]);
  if (access(pipex->cmd_paths[cmd_index], X_OK) == -1)
    handle_error("Error: Command not found or not executable");
  execve(pipex->cmd_paths[cmd_index], pipex->cmd_args[cmd_index], NULL);
  handle_error("Error: Command execution failed");
}

static void setup_parent_process(t_pipex *pipex, int pipe_fd[2])
{
  waitpid(-1, NULL, 0);
  if (pipex->in_fd != -1)
    close(pipex->in_fd);
  pipex->in_fd = pipe_fd[0];
  close(pipe_fd[1]);
}

void exec(t_pipex *pipex)
{
  int pipe_fd[2];
  pid_t pid;
  pid_t last_pid;
  int cmd_index;
  int status;

  cmd_index = 0;
  while (cmd_index < pipex->cmd_count)
  {
    create_pipe(pipe_fd);
    pid = create_child_process();
    if (pid == 0)
    {
      setup_child_process(pipex, pipe_fd, cmd_index);
    }
    else
    {
      if (cmd_index == pipex->cmd_count - 1)
        last_pid = pid; // Track the last child process
      setup_parent_process(pipex, pipe_fd);
    }
    cmd_index++;
  }

  // Wait for all child processes
  while ((pid = wait(&status)) > 0)
  {
    if (pid == last_pid) // Check if this is the last process
    {
      if (WIFEXITED(status))
        status = WEXITSTATUS(status); // Save the last command's exit status
      else
        status = EXIT_FAILURE;
    }
  }

  if (pipex->in_fd != -1)
    close(pipex->in_fd);

  exit(status); // Exit with the last command's exit status
}
