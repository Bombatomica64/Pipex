/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 18:42:18 by lmicheli          #+#    #+#             */
/*   Updated: 2024/01/11 18:44:14 by lmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	close_all_fd(t_pipex *data)
{
	int		i;

	i = 0;
	while (i < 2)
	{
		close(data->files[i]);
		i++;
	}
}

void	error(t_pipex *data, int error)
{
	if (error == 1)
		perror("Error: pipe failed\n");
	else if (error == 2)
		perror("Error: dup2 failed\n");
	else if (error == 3)
		perror("Error: execve failed\n");
	else if (error == 4)
		perror("Error: fork failed\n");
	else if (error == 5)
		perror("Error: open failed\n");
	else if (error == 6)
		perror("Error: malloc failed\n");
	else if (error == 7)
		perror("Error: close failed\n");
	else
		perror("Error: unknown error\n");
	free_pipex(data);
	exit(EXIT_FAILURE);
}
