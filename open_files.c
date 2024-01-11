/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 18:23:13 by lmicheli          #+#    #+#             */
/*   Updated: 2024/01/11 18:10:36 by lmicheli         ###   ########.fr       */
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
	fd[0] = open(file1, O_RDONLY, 0777);
	fd[1] = open(file2, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	return (fd);
}

/* char	**get_args(t_pipex *data)
{
	char	**args;
	char	*tmp;
	int		i;

	i = 0;
	args = malloc(sizeof(char *) * (ft_matrix_len(data->cmds) + 1));
	while (data->cmds[i])
	{
		tmp = ft_strjoin("/bin/", data->split_cmds[i][0]);
		args[i] = tmp;
		i++;
	}
	args[i] = NULL;
	return (args);
}
 */
void	get_file_names(t_pipex *data, char *file1, char *file2)
{
	data->file1 = file1;
	data->file2 = file2;
	data->files = open_files(file1, file2);
}

void	get_file_bonus(t_pipex *data, char *file)
{
	data->file1 = file;
	data->file2 = NULL;
	data->files = malloc(sizeof(int) * 2);
	data->files[0] = open(file, O_WRONLY | O_CREAT | O_APPEND, 0777);
}

t_pipex	*initialize(int ac, char **av, char **mvp, int nbr)
{
	t_pipex	*data;

	(void)mvp;
	if (nbr == 2)
		basic_check(av[1]);
	data = malloc(sizeof(t_pipex));
	data->bonus = nbr;
	if (!data)
		error(data);
	if (nbr == 2)
		get_file_names(data, av[1], av[ac - 1]);
	else
		get_file_bonus(data, av[ac - 1]);
	return (data);
}
