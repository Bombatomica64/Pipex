/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 17:33:09 by lmicheli          #+#    #+#             */
/*   Updated: 2024/01/15 17:11:32 by lmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	basic_check_ac(int ac, int bonus)
{
	if (ac < 5)
	{
		perror("\033[36m Error: too few arguments");
		exit(EXIT_FAILURE);
	}
	if (ac > 5 && bonus == 0)
	{
		perror("\033[36m Error: too many arguments");
		exit(EXIT_FAILURE);
	}
	if (ac < 6 && bonus == 1)
	{
		perror("\033[36mError: too few arguments\n");
		exit(EXIT_FAILURE);
	}
}

int	main(int ac, char **av, char **mvp)
{
	int			i;
	int			filein;
	int			fileout;

	basic_check_ac(ac, 1);
	if (ft_strncmp(av[1], "here_doc", 8) == 0)
	{
		i = 3;
		fileout = open(av[ac - 1], O_WRONLY | O_CREAT | O_APPEND, 0777);
		do_bonus(av[2], ac);
	}
	else
	{
		i = 2;
		filein = open(av[1], O_RDONLY, 0777);
		fileout = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
		if (dup2(filein, STDIN_FILENO) == -1)
			error(2);
	}
	while (i < ac - 2)
		child_process(av[i++], mvp);
	if (dup2(fileout, STDOUT_FILENO) == -1)
		error(2);
	daddy_execute(av[ac - 2], mvp);
	return (EXIT_SUCCESS);
}

/*
	char *args= ft_strjoin("/bin/", av[1]);
	execve(args, &av[1], NULL);
	exit(0);
*/
