/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 12:51:57 by lmicheli          #+#    #+#             */
/*   Updated: 2024/01/05 13:21:11 by lmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**get_commands(char **av, int ac)
{
	char	**cmds;
	int		i;

	cmds = malloc(sizeof(char *) * (ac - 2));
	if (!cmds)
		return (NULL);
	i = ac - 3;
	while (i < ac - 1)
	{
		cmds[i - 2] = ft_strdup(av[i]);
		i++;
	}
	cmds[ac - 2] = NULL;
	return (cmds);
}
