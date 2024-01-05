/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_cmds.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 15:21:18 by lmicheli          #+#    #+#             */
/*   Updated: 2024/01/05 17:16:10 by lmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	do_commands(char **cmds, int *fd)
{
	pid_t	chi_pid;

	chi_pid = fork();
	if (chi_pid == -1)
	{
		perror("fork failed");
		exit(EXIT_FAILURE);
	}
	if (chi_pid == 0)
		child(fd, cmds);
	else
		parent(chi_pid, cmds, fd);
}

void	parent(pid_t chi_pid, char **cmds, int *fd)
{
	(void)cmds;
	(void)fd;
	(void)chi_pid;
	ft_printf("everything fine\n");
}

void	child(int *fd, char **cmds)
{
	char	*arg;
	char	**command;

	if (dup2(fd[0], STDIN_FILENO) == -1 || dup2(fd[1], STDOUT_FILENO) == -1)
	{
		perror("dup2 failed");
		exit(EXIT_FAILURE);
	}
	command = ft_split(cmds[0], ' ');
	arg = ft_strjoin("/bin/", command[0]);
	close(fd[0]);
	close(fd[1]);
	if (execve(arg, command, NULL) == -1)
	{
		perror("execve failed");
		exit(EXIT_FAILURE);
	}
}
