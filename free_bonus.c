/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 18:03:48 by lmicheli          #+#    #+#             */
/*   Updated: 2024/01/09 18:39:52 by lmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_bonus(t_bonus *data)
{
	if (data)
	{
		//free_int_ptr(data->fd);
		// free_char_ptr_ptr(data->limiter_cmd);
		// free_char_ptr_ptr(data->limiter_cmd2);
		// free_char_ptr_ptr(data->limiter_cmd_args);
		free(data);
	}
}
