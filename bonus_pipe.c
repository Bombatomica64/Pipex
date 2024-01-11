/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:09:38 by lmicheli          #+#    #+#             */
/*   Updated: 2024/01/11 18:41:44 by lmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	do_bonus(t_pipex *data, int ac)
{
	int		ret;
	int		fd[2];

	if (ac < 6)
	{
		perror("Error: too few arguments\n");
		free_pipex(data);
		exit(EXIT_FAILURE);
	}
	if (pipe(fd) == -1)
		error(data, 1);
}
/* 	if (data->chi_pid == 0)
	{
		close(data->fd[0]);
		if (dup2(data->file_fd, 1) == -1
			|| dup2(data->fd[1], 0) == -1)
		{
			perror("Error: dup2 failed in child\n");
			free_bonus(data);
			exit(1);
		}
		if (execve(data->limiter_cmd[0], data->limiter_cmd_args, NULL) == -1)
		{
			perror("Error: execve failed in child\n");
			free_bonus(data);
			exit(1);
		}
	}
	else
	{
		waitpid(data->chi_pid, NULL, 0);
		close(data->fd[1]);
		if (dup2(data->file_fd, 1) == -1
			|| dup2(data->fd[0], 0) == -1)
		{
			perror("Error: dup2 failed in parent\n");
			free_bonus(data);
			exit(1);
		}
		if (execve(data->limiter_cmd2[0], data->limiter_cmd_args, NULL) == -1)
		{
			perror("Error: execve failed in parent\n");
			free_bonus(data);
			exit(1);
		}
	}
}
 */