/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 17:33:09 by lmicheli          #+#    #+#             */
/*   Updated: 2024/01/09 17:10:30 by lmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av)
{
	t_pipex	*data;
	int		fd[2];

	if (ac < 5)
	{
		ft_printf("Error: too few arguments\n");
		return (1);
	}
	if (av[1] == "here_doc")
		do_bonus(ac, av);
	data = malloc(sizeof(t_pipex));
	basic_check(av[1], av[ac - 1]);
	data->files = open_files(av[1], av[ac - 1]);
	data->fd = fd;
	get_file_names(data, av[1], av[ac - 1]);
	data->cmds = get_commands(av, ac);
	print_matrix(data->cmds);
	data->split_cmds = ft_gigasplit(data);
	data->cmd_args = get_args(data);
	data->current_cmd = 0;
	if (!data->cmds)
	{
		perror("Error: malloc failed\n");
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