/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_cmds.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 15:21:18 by lmicheli          #+#    #+#             */
/*   Updated: 2024/01/15 16:46:49 by lmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	find_path_index(char **envp)
{
	int	i;

	i = 0;
	while (ft_strnstr(envp[i], "PATH", 4) == 0)
		i++;
	return (i);
}

char	*find_path(char **envp, char *cmd)
{
	int		j;
	char	*path;
	char	**paths;
	char	*part_path;

	j = find_path_index(envp);
	paths = ft_split(envp[j] + 5, ':');
	j = 0;
	while (paths[j])
	{
		part_path = ft_strjoin(paths[j], "/");
		path = ft_strjoin(part_path, cmd);
		free(part_path);
		if (access(path, F_OK) == 0)
		{
			free_char_ptr_ptr(paths);
			return (path);
		}
		free(path);
		j++;
	}
	free_char_ptr_ptr(paths);
	free(paths);
	return (0);
}

void	child_process(char *cmd, char **mvp)
{
	pid_t	chi_pid;
	int		fd[2];

	if (pipe(fd) == -1)
		error(1);
	chi_pid = fork();
	if (chi_pid == -1)
		error(4);
	if (chi_pid == 0)
	{
		close(fd[0]);
		if (dup2(fd[1], STDOUT_FILENO) == -1)
			error(2);
		execute(cmd, mvp);
	}
	else
	{
		close(fd[1]);
		if (dup2(fd[0], STDIN_FILENO) == -1)
			error(2);
		wait(NULL);
	}
}

void	execute(char *av, char **mvp)
{
	int		i;
	char	*path;
	char	**cmd;

	i = 0;
	cmd = ft_split(av, ' ');
	path = find_path(mvp, cmd[0]);
	if (path == 0)
	{
		perror("Error: command not found\n");
		free_char_ptr_ptr(cmd);
		exit(EXIT_FAILURE);
	}
	if (execve(path, cmd, NULL) == -1)
		perror("\033[36mError: execve failed");
	free_char_ptr_ptr(cmd);
	free(path);
}

void	daddy_execute(char *av, char **mvp)
{
	int		i;
	char	*path;
	char	**cmd;

	i = 0;
	cmd = ft_split(av, ' ');
	path = find_path(mvp, cmd[0]);
	if (path == 0)
	{
		perror("Error: command not found\n");
		free_char_ptr_ptr(cmd);
		exit(EXIT_FAILURE);
	}
	if (execve(path, cmd, NULL) == -1)
		perror("\033[36mError: execve failed");
	free_char_ptr_ptr(cmd);
	free(path);
}
/* void	do_commands(t_pipex *data)
{
	if (pipe(data->fd) == -1)
	{
		perror("pipe failed\n");
		free_pipex(data);
		exit(EXIT_FAILURE);
	}
	free_char_ptr_ptr(data->cmds);
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
	i = 1;
	close(data->fd[1]);
	if (dup2(data->files[1], STDOUT_FILENO) == -1
		|| dup2(data->fd[0], STDIN_FILENO) == -1)
	{
		perror("dup2 failed in parent");
		free_pipex(data);
		exit(EXIT_FAILURE);
	}
	if (execve(data->cmd_args[1], data->split_cmds[1], NULL) == -1)
	{
		perror("execve failed in parent");
		free_pipex(data);
		exit(EXIT_FAILURE);
	}
	free_pipex(data);
	exit(0);
}

void	child(t_pipex *data)
{
	int		i;

	i = data->current_cmd;
	close(data->fd[0]);
	if (data->cmd_args == NULL)
	{
		perror("cmd_args is NULL\n");
		exit(EXIT_FAILURE);
	}
	if (dup2(data->files[0], STDIN_FILENO) == -1
		|| dup2(data->fd[1], STDOUT_FILENO) == -1)
	{
		perror("dup2 failed in child");
		free_pipex(data);
		exit(EXIT_FAILURE);
	}
	if (execve(data->cmd_args[0], data->split_cmds[i], NULL) == -1)
	{
		perror("execve failed in child");
		free_pipex(data);
		exit(EXIT_FAILURE);
	}
	data->current_cmd++;
	free_pipex(data);
	exit(0);
} */
