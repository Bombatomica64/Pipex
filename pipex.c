/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 17:33:09 by lmicheli          #+#    #+#             */
/*   Updated: 2024/01/05 16:51:47 by lmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av)
{
	int		*fd;
	char	**cmds;

	if (ac < 5)
	{
		ft_printf("Error: too few arguments\n");
		return (1);
	}
	basic_check(av[1], av[ac - 1]);
	fd = open_files(av[1], av[ac - 1]);
	cmds = get_commands(av, ac);
	if (!cmds)
	{
		perror("Error: malloc failed\n");
		free(fd);
		return (-1);
	}
	if (pipe(fd) == -1)
	{
		perror("Error: pipe failed\n");
		free(fd);
		return (-1);
	}
	do_commands(cmds, fd);
}
/*
	char *args= ft_strjoin("/bin/", av[1]);
	execve(args, &av[1], NULL);
	exit(0);
*/