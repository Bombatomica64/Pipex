/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 18:23:13 by lmicheli          #+#    #+#             */
/*   Updated: 2024/01/08 12:21:11 by lmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	*open_files(char *file1, char *file2)
{
	int	*fd;

	fd = malloc(sizeof(int) * 2);
	if (!fd)
	{
		perror("malloc failed");
		exit(0);
	}
	fd[0] = open(file1, O_RDONLY);
	fd[1] = open(file2, O_WRONLY, 0644);
	return (fd);
}

char	**get_args(t_pipex *data)
{
	char	**args;
	char	*tmp;
	int		i;

	i = 0;
	args = malloc(sizeof(char *) * (ft_matrix_len(data->cmds) + 1));
	while (data->cmds[i])
	{
		tmp = ft_strjoin("/bin/", data->cmds[i]);
		args[i] = tmp;
		i++;
	}
	args[i] = NULL;
	return (args);
}

void	get_file_names(t_pipex *data, char *file1, char *file2)
{
	data->file1 = file1;
	data->file2 = file2;
}