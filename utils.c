/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 12:49:08 by lmicheli          #+#    #+#             */
/*   Updated: 2024/01/09 12:53:46 by lmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define NULL ((void *)0)
#include "pipex.h"

void	print_matrix(char **matrix)
{
	int		i;

	i = 0;
	if (matrix == NULL)
	{
		ft_printf("La matrice è NULL\n");
		return ;
	}
	while (matrix[i] != NULL)
	{
		ft_printf("Riga %d: %s\n", i, matrix[i]);
		i++;
	}
}
void	print_matrix2(char ***matrix)
{
	int		i;
	int		j;

	i = 0;
	if (matrix == NULL)
	{
		ft_printf("La matrice è NULL\n");
		return ;
	}
	while (matrix[i] != NULL)
	{
		j = 0;
		while (matrix[i][j] != NULL)
		{
			ft_printf("Riga %d, Colonna %d: %s\n", i, j, matrix[i][j]);
			j++;
		}
		i++;
	}
}