/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:09:20 by lmicheli          #+#    #+#             */
/*   Updated: 2024/01/09 18:44:16 by lmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	bonus_check(int ac, char **av)
{
	if (ac != 6)
	{
		perror("Error:wrong number of arguments\n");
		exit(1);
	}
	if (ft_strncmp(av[1], "here_doc", 8) != 0)
	{
		perror("Error: wrong first argument\n");
		exit(1);
	}
	if (!file_exist(av[5]) || !file_writable(av[5]))
	{
		perror("Error: outfile doesn't exist or isn't writable\n");
		exit(1);
	}
}

char	**get_bonus_args(t_bonus *data)
{
	char	**args;

	args = malloc(sizeof(char *) * 3);
	if (!args)
		return (NULL);
	args[0] = ft_strjoin("/bin/", data->limiter_cmd[0]);
	args[1] = ft_strjoin("/bin/", data->limiter_cmd2[0]);
	args[2] = NULL;
	return (args);
}
