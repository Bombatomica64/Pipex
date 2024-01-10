/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:09:38 by lmicheli          #+#    #+#             */
/*   Updated: 2024/01/10 16:29:31 by lmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	parent_bonus(t_bonus *data)
{
	waitpid(data->chi_pid, NULL, 0);
	close(data->fd[1]);
	if (dup2(data->file_fd, STDOUT_FILENO) == -1
		|| dup2(data->fd[0], STDIN_FILENO) == -1)
	{
		perror("Error: dup2 failed in parent\n");
		free_bonus(data);
		exit(1);
	}
	if (execve(data->limiter_cmd_args[1], data->limiter_cmd2, NULL) == -1)
	{
		perror("Error: execve failed in parent\n");
		free_bonus(data);
		exit(1);
	}
}

void	child_bonus(t_bonus *data)
{
	int	flag;

	flag = 0;
	close(data->fd[0]);
	ft_printf("limiter: %s\n", data->limiter);
	print_matrix(data->limiter_cmd);
	ft_printf("limiter_cmd_args: %s\n", data->limiter_cmd_args[0]);
	if (dup2(data->fd[1], STDOUT_FILENO) == -1)
	{
		perror("Error: dup2 failed in child\n");
		free_bonus(data);
		exit(1);
	}
	data->line = get_next_line(STDIN_FILENO);
	while (flag == 0)
	{
		write(data->file_fd, data->line, ft_strlen(data->line));
		free(data->line);
		if (ft_strncmp(data->line, data->limiter,
				ft_strlen(data->limiter)) == 0)
		{
			flag = 1;
			ft_printf("limiter found\n");
		}
		data->line = get_next_line(STDIN_FILENO);
	}
	if (execve(data->limiter_cmd_args[0],
			data->limiter_cmd, NULL) == -1)
	{
		perror("Error: execve failed in child\n");
		free_bonus(data);
		exit(1);
	}
	free_bonus(data);
	exit(0);
}

t_bonus	*initialize_bonus(int ac, char **av)
{
	t_bonus		*data;

	data = malloc(sizeof(t_bonus));
	if (!data)
	{
		perror("Error: malloc failed\n");
		exit(1);
	}
	bonus_check(ac, av);
	data->file = av[5];
	data->limiter_cmd = ft_split(av[3], ' ');
	data->limiter_cmd2 = ft_split(av[4], ' ');
	data->limiter = ft_strjoin(av[2], "\n");
	data->limiter_cmd_args = get_bonus_args(data);
	data->file_fd = open(data->file, O_WRONLY, 0644);
	if (data->file_fd < 0)
	{
		perror("Error: open failed\n");
		free_bonus(data);
		exit(1);
	}
	return (data);
}

void	execute_bonus(t_bonus *data)
{
	if (pipe(data->fd) < 0)
	{
		perror("Error: pipe failed\n");
		free_bonus(data);
		exit(1);
	}
	data->chi_pid = fork();
	if (data->chi_pid < 0)
	{
		perror("Error: fork failed\n");
		free_bonus(data);
		exit(1);
	}
	if (data->chi_pid == 0)
		child_bonus(data);
	else
		parent_bonus(data);
	exit(0);
}

void	do_bonus(int ac, char **av)
{
	t_bonus		*data;

	data = initialize_bonus(ac, av);
	execute_bonus(data);
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