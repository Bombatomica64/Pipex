/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 18:42:18 by lmicheli          #+#    #+#             */
/*   Updated: 2024/01/12 11:37:51 by lmicheli         ###   ########.fr       */
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
		perror("\033[36mError: pipe failed\n");
	else if (error == 2)
		perror("\033[36mError: dup2 failed\n");
	else if (error == 3)
		perror("\033[36mError: execve failed\n");
	else if (error == 4)
		perror("\033[36mError: fork failed\n");
	else if (error == 5)
		perror("\033[36mError: open failed\n");
	else if (error == 6)
		perror("\033[36mError: malloc failed\n");
	else if (error == 7)
		perror("\033[36mError: close failed\n");
	else if (error == 8)
		perror("\033[36mError: Wrong number of arguments\n");
	else
		perror("\033[36mError: unknown error\n");
	free_pipex(data);
	exit(EXIT_FAILURE);
}
