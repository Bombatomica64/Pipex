/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 17:33:09 by lmicheli          #+#    #+#             */
/*   Updated: 2024/01/10 15:15:46 by lmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av)
{
	t_pipex	*data;
	int		fd[2];

	if (ac < 5)
		return (ft_printf("Error: too few arguments\n"));
	if (ft_strncmp(av[1], "here_doc", 8) == 0)
		do_bonus(ac, av);
	data = malloc(sizeof(t_pipex));
	basic_check(av[1], av[ac - 1]);
	data->files = open_files(av[1], av[ac - 1]);
	data->fd = fd;
	get_file_names(data, av[1], av[ac - 1]);
	data->cmds = get_commands(av, ac);
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