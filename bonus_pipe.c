/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:09:38 by lmicheli          #+#    #+#             */
/*   Updated: 2024/01/12 12:27:07 by lmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	do_bonus(t_pipex *data, int ac)
{
	pid_t	chi_pid;
	int		fd[3];

	if (ac < 6)
	{
		perror("Error: too few arguments\n");
		free_pipex(data);
		exit(EXIT_FAILURE);
	}
	if (pipe(fd) == -1)
		error(data, 1);
	chi_pid = fork();
	if (chi_pid == -1)
		error(data, 4);
	if (chi_pid == 0)
	{
		bonus_child(fd, data);
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		wait(NULL);
	}
}

void	bonus_child(int fd[2], t_pipex *data)
{
	close(fd[0]);
	while (get_new_next_line(&data->line))
	{
		if (ft_strncmp(data->line, data->limiter,
				ft_strlen(data->limiter)) == 0)
		{
			//free_pipex(data);
			exit(EXIT_SUCCESS);
		}
		write(fd[1], data->line, ft_strlen(data->line));
//		free(data->line);
	}
}

void	here_doc(char *limiter, int argc, t_pipex *data)
{
	pid_t	reader;
	int		fd[2];
	char	*line;

	if (argc < 6)
		error(data, 8);
	if (pipe(fd) == -1)
		error(data, 1);
	reader = fork();
	if (reader == 0)
	{
		close(fd[0]);
		while (get_new_next_line(&line))
		{
			if (ft_strncmp(line, limiter, ft_strlen(limiter)) == 0)
			{
				write(2, "sesso\n", 6);
				exit(EXIT_SUCCESS);
			}
			write(fd[1], line, ft_strlen(line));
		}
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		wait(NULL);
	}
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