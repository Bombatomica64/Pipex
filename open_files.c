/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 18:23:13 by lmicheli          #+#    #+#             */
/*   Updated: 2024/01/05 15:52:45 by lmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	*open_files(char *file1, char *file2)
{
	int	*fd;

	fd = malloc(sizeof(int) * 2);
	if (!fd)
	{
		perror("malloc failed");
		exit(0);
	}
	fd[0] = open(file1, O_RDONLY);
	fd[1] = open(file2, O_WRONLY, 0644);
	return (fd);
}
