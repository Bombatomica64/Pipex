/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 18:30:33 by lmicheli          #+#    #+#             */
/*   Updated: 2024/01/11 16:33:14 by lmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_char_ptr(char *ptr)
{
	if (ptr)
		free(ptr);
}

void	free_char_ptr_ptr(char **ptr)
{
	int	i;

	i = 0;
	if (ptr)
	{
		while (ptr[i])
		{
			free(ptr[i]);
			i++;
		}
		free(ptr);
	}
}

void	free_char_ptr_ptr_ptr(char ***ptr)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (ptr)
	{
		while (ptr[i])
		{
			j = 0;
			while (ptr[i][j])
			{
				free(ptr[i][j]);
				j++;
			}
			free(ptr[i]);
			i++;
		}
		free(ptr);
	}
}

void	free_int_ptr(int *ptr)
{
	if (ptr)
		free(ptr);
}

void	free_pipex(t_pipex *pipex)
{
	if (pipex)
	{
		if (pipex->bonus == 2)
		{
			free_int_ptr(pipex->fd);
			free_char_ptr_ptr_ptr(pipex->split_cmds);
			free_char_ptr_ptr(pipex->cmd_args);
			free(pipex);
		}
		else
		{
			free_char_ptr_ptr(pipex->cmd_args);
			free_int_ptr(pipex->fd);
			free_int_ptr(pipex->files);
			free(pipex);
		}
	}
}
