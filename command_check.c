/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 12:51:57 by lmicheli          #+#    #+#             */
/*   Updated: 2024/01/11 15:35:10 by lmicheli         ###   ########.fr       */
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
	cmds[ac - 3] = NULL;
	return (cmds);
}

char	***ft_gigasplit(t_pipex *data)
{
	char	***split_cmds;
	int		i;

	i = 0;
	split_cmds = malloc(sizeof(char **) * (ft_matrix_len(data->cmds) + 1));
	if (!split_cmds)
		return (NULL);
	while (data->cmds[i])
	{
		split_cmds[i] = ft_split(data->cmds[i], ' ');
		i++;
	}
	split_cmds[i] = NULL;
	return (split_cmds);
}
