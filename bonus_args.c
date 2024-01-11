/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:09:20 by lmicheli          #+#    #+#             */
/*   Updated: 2024/01/11 17:26:05 by lmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**get_bonus_args(t_pipex *data)
{
	char	**args;
	(void)data;

	args = malloc(sizeof(char *) * 3);
	if (!args)
		return (NULL);
	//args[0] = ft_strjoin("/bin/", data->limiter_cmd[0]);
	//args[1] = ft_strjoin("/bin/", data->limiter_cmd2[0]);
	args[2] = NULL;
	return (args);
}
