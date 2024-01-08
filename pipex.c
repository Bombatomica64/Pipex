/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 17:33:09 by lmicheli          #+#    #+#             */
/*   Updated: 2024/01/08 12:20:06 by lmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av)
{
	t_pipex	*data;

	if (ac < 5)
	{
		ft_printf("Error: too few arguments\n");
		return (1);
	}
	data = malloc(sizeof(t_pipex));
	basic_check(av[1], av[ac - 1]);
	data->fd = open_files(av[1], av[ac - 1]);
	get_file_names(data, av[1], av[ac - 1]);
	data->cmds = get_commands(av, ac);
	if (!data->cmds)
	{
		perror("Error: malloc failed\n");
		free_pipex(data);
		return (-1);
	}
	if (pipe(data->fd) == -1)
	{
		perror("Error: pipe failed\n");
		free_pipex(data);
		return (-1);
	}
	do_commands(data);
}
/*
	char *args= ft_strjoin("/bin/", av[1]);
	execve(args, &av[1], NULL);
	exit(0);
*/