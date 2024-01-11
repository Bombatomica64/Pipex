/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 17:33:09 by lmicheli          #+#    #+#             */
/*   Updated: 2024/01/11 18:23:44 by lmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **mvp)
{
	t_pipex	*data;

	if (ac < 5)
	{
		perror("\033[36m Error: too few arguments\n");
		return (EXIT_FAILURE);
	}
	if (ft_strncmp(av[1], "here_doc", 8) == 0)
	{
		data = initialize(ac, av, mvp, 3);
		do_bonus(data, ac);
	}
	else
	{
		data = initialize(ac, av, mvp, 2);
		dup2(data->files[0], STDIN_FILENO);
	}
	while (data->bonus < ac -2)
		child_process(av[data->bonus++], mvp, data);
	dup2(data->file2, STDOUT_FILENO);
	execute(av[ac - 2], mvp);
}

/*
	char *args= ft_strjoin("/bin/", av[1]);
	execve(args, &av[1], NULL);
	exit(0);
*/