/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_cmds.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 15:21:18 by lmicheli          #+#    #+#             */
/*   Updated: 2024/01/08 18:43:01 by lmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	do_commands(t_pipex *data)
{
	data->split_cmds = ft_gigasplit(data);
	data->cmd_args = get_args(data);
	data->current_cmd = 0;
	if (pipe(data->fd) == -1)
	{
		perror("pipe failed\n");
		free_pipex(data);
		exit(EXIT_FAILURE);
	}
	ft_printf("cmd_args[0] = %s\n", data->cmd_args[0]);
	ft_printf("cmd_args[1] = %s\n", data->cmd_args[1]);
	if (dup2(data->fd[1], STDOUT_FILENO) == -1)
	{
		perror("dup2 failed");
		free_pipex(data);
		exit(EXIT_FAILURE);
	}
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
	close_all_fd(data);
}

void	parent(t_pipex *data)
{
	int		i;

	waitpid(data->chi_pid, NULL, 0);
	//close(data->fd[1]);
	i = 1;
	if (dup2(data->files[1], STDOUT_FILENO) == -1 || dup2(data->fd[0], STDIN_FILENO) == -1)
	{
		perror("dup2 failed");
		free_pipex(data);
		exit(EXIT_FAILURE);
	}
	if (execve(data->cmd_args[1], data->split_cmds[1], NULL) == -1)
	{
		perror("execve failed");
		free_pipex(data);
		exit(EXIT_FAILURE);
	}
	exit(0);
}

void	child(t_pipex *data)
{
	int		i;

	i = data->current_cmd;
	//close(data->fd[0]);
	if (dup2(data->files[0],STDIN_FILENO) == -1 || dup2(data->fd[1], STDOUT_FILENO) == -1)
	{
		perror("dup2 failed");
		free_pipex(data);
		exit(EXIT_FAILURE);
	}
	if (execve(data->cmd_args[0], data->split_cmds[i], NULL) == -1)
	{
		perror("execve failed");
		free_pipex(data);
		exit(EXIT_FAILURE);
	}
	data->current_cmd++;
}
