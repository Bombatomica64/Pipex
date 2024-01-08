/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_cmds.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 15:21:18 by lmicheli          #+#    #+#             */
/*   Updated: 2024/01/08 12:12:53 by lmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	do_commands(t_pipex *data)
{
	data->split_cmds = ft_gigasplit(data);
	data->cmd_args = get_args(data);
	data->current_cmd = 0;
	free_pipex(data);
	ft_printf("seso");
	exit(0);
	data->chi_pid = fork();
	if (data->chi_pid == -1)
	{
		perror("fork failed");
		free_pipex(data);
		exit(EXIT_FAILURE);
	}
	if (data->chi_pid == 0)
		child(data);
	else
		parent(data);
}

void	parent(t_pipex *data)
{
	waitpid(data->chi_pid, NULL, 0);
}

void	child(t_pipex *data)
{
	int		i;

	i = data->current_cmd;
	if (dup2(data->fd[0], STDIN_FILENO) == -1
		|| dup2(data->fd[1], STDOUT_FILENO) == -1)
	{
		perror("dup2 failed");
		free_pipex(data);
		exit(EXIT_FAILURE);
	}
	close_all_fd(data);
	if (execve(data->cmd_args[0], &data->cmds[0], NULL) == -1)
	{
		perror("execve failed");
		free_pipex(data);
		exit(EXIT_FAILURE);
	}
	data->current_cmd++;
}
