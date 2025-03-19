/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igngonza <igngonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 13:15:45 by igngonza          #+#    #+#             */
/*   Updated: 2025/03/19 13:15:48 by igngonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	check_args(t_pipex *pipex, int argc, char **argv)
{
	if (argc < 5)
	{
		write(2, "Error: Too few arguments.\n", 25);
		exit(1);
	}
	else if (argc > 6)
	{
		write(2, "Error: Too many arguments.\n", 26);
		exit(1);
	}

	// Check if input file exists and is readable
	pipex->in_fd = open(argv[1], O_RDONLY);
	if (pipex->in_fd == -1)
	{
		perror("Error opening input file");
		exit(1);
	}

	// Check if output file can be opened for writing (it may be created if not existing)
	pipex->out_fd = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (pipex->out_fd == -1)
	{
		perror("Error opening output file");
		close(pipex->in_fd);
		exit(1);
	}