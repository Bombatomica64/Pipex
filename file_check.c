/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 18:03:47 by lmicheli          #+#    #+#             */
/*   Updated: 2024/01/08 12:04:40 by lmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	file_exist(char *file)
{
	if (access(file, F_OK) == 0)
		return (1);
	return (0);
}

int	file_readable(char *file)
{
	if (access(file, R_OK) == 0)
		return (1);
	return (0);
}

int	file_writable(char *file)
{
	if (access(file, W_OK) == 0)
		return (1);
	return (0);
}

void	basic_check(char *file1, char *file2)
{
	if (!file_exist(file1))
	{
		perror("infile doesn't exist");
		exit(EXIT_FAILURE);
	}
	if (!file_exist(file2))
	{
		perror("outfile doesn't exist");
		exit(EXIT_FAILURE);
	}
	if (!file_readable(file1))
	{
		perror("infile isn't readable");
		exit(EXIT_FAILURE);
	}
	if (!file_writable(file2))
	{
		perror("outfile isn't writable");
		exit(EXIT_FAILURE);
	}
}
