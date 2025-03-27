/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igngonza <igngonza@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 16:30:36 by igngonza          #+#    #+#             */
/*   Updated: 2025/03/27 18:48:32 by igngonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void handle_error(const char *message)
{
  errno = 1;
  perror(message);
  exit(EXIT_FAILURE);
}

void handle_pipe_msg(char *arg)
{
  write(2, ERR_CMD, ft_strlen(ERR_CMD));
  write(2, arg, ft_strlen(arg));
  write(2, "\n", 1);
}

int handle_msg(char *err)
{
  write(2, err, ft_strlen(err));
  return (1);
}