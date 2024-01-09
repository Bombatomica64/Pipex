/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:09:38 by lmicheli          #+#    #+#             */
/*   Updated: 2024/01/09 17:30:35 by lmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	do_bonus(int ac, char **av)
{
	t_bonus	*data;

	bonus_check(ac, av);
	data = malloc(sizeof(t_bonus));
	data->file = av[5];
	data->limiter_cmd = ft_split(av[3], ' ');
	data->limiter_cmd2 = ft_split(av[4], ' ');
	data->limiter_cmd_args = get_bonus_args(data);
}
