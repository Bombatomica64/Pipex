/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_cmds.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 15:21:18 by lmicheli          #+#    #+#             */
/*   Updated: 2024/01/05 18:26:53 by lmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	do_commands(t_pipex *data)
{
	data->split_cmds = ft_gigasplit(data);
	data->cmd_args = get_args(data);
	data->chi_pid = fork();
	if (data->chi_pid == -1)
	{
		perror("fork failed");
		exit(EXIT_FAILURE);
	}
	if (data->chi_pid == 0)
		child(data);
	else
		parent(data);
}

void	parent(t_pipex *data)
{
	(void)data->fd;
	ft_printf("everything fine\n");
}

void	child(t_pipex *data)
{
	if (dup2(fd[0], STDIN_FILENO) == -1 || dup2(fd[1], STDOUT_FILENO) == -1)
	{
		perror("dup2 failed");
		exit(EXIT_FAILURE);
	}
	close_all_fd(data);
	if (execve(arg, command, NULL) == -1)
	{
		perror("execve failed");
		exit(EXIT_FAILURE);
	}
}
