/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_cmds.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 15:21:18 by lmicheli          #+#    #+#             */
/*   Updated: 2024/01/12 18:42:33 by lmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*find_path(t_pipex *data, char **envp, char *cmd)
{
	int		i;

	i = 0;
	while (ft_strnstr(envp[i], "PATH", 4) == 0)
		i++;
	data->paths = ft_split(envp[i] + 5, ':');
	i = 0;
	while (data->paths[i])
	{
		data->part_path = ft_strjoin(data->paths[i], "/");
		data->path = ft_strjoin(data->part_path, cmd);
		free(data->part_path);
		if (access(data->path, F_OK) == 0)
			return (data->path);
		free(data->path);
		i++;
	}
	i = -1;
	while (data->paths[++i])
		free(data->paths[i]);
	free(data->paths);
	return (0);
}

void	child_process(char *cmd, char **mvp, t_pipex *data)
{
	pid_t	chi_pid;
	int		fd[2];

	if (pipe(fd) == -1)
		error(data, 1);
	chi_pid = fork();
	if (chi_pid == -1)
		error(data, 4);
	if (chi_pid == 0)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		execute(cmd, mvp, data);
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		wait(NULL);
	}
}

void	execute(char *av, char **mvp, t_pipex *data)
{
	int		i;
	char	*path;
	char	**cmd;

	i = 0;
	cmd = ft_split(av, ' ');
	path = find_path(data, mvp, cmd[0]);
	if (path == 0)
	{
		perror("Error: command not found\n");
		free_char_ptr_ptr(cmd);
		free_pipex(data);
		exit(EXIT_FAILURE);
	}
	if (execve(path, cmd, NULL) == -1)
		error(data, 3);
	free_char_ptr_ptr(cmd);
	free(path);
}

void	daddy_execute(char *av, char **mvp, t_pipex *data)
{
	int		i;
	char	*path;
	char	**cmd;

	i = 0;
	cmd = ft_split(av, ' ');
	path = find_path(data, mvp, cmd[0]);
	if (path == 0)
	{
		perror("Error: command not found\n");
		free_char_ptr_ptr(cmd);
		free_pipex(data);
		exit(EXIT_FAILURE);
	}
	free(data);
	if (execve(path, cmd, NULL) == -1)
		error(data, 3);
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
