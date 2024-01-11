/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 13:02:03 by lmicheli          #+#    #+#             */
/*   Updated: 2024/01/11 18:20:07 by lmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	get_new_next_line(int fd, t_pipex *data)
{
	int		ret;

	data->line = get_next_line(fd);
	ret = ft_strlen(data->line);
	if (ret == -1)
	{
		perror("Error: get_next_line failed\n");
		free_pipex(data);
		exit(1);
	}
	return (ret);
}
