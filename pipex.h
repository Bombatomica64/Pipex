/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 14:28:19 by lmicheli          #+#    #+#             */
/*   Updated: 2024/01/05 16:29:53 by lmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "ft_printf/ft_printf.h"
# include "ft_printf/libft.h"
# include "ft_printf/get_next_line_bonus.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <unistd.h>

int		file_exist(char *file);
int		file_readable(char *file);
int		file_writable(char *file);
int		ft_matrix_len(char **array);
int		*open_files(char *file1, char *file2);
void	basic_check(char *file1, char *file2);
void	do_commands(char **cmds, int *fd);
void	parent(pid_t chi_pid, char **cmds, int *fd);
void	child(int *fd, char **cmds);
char	**get_commands(char **av, int ac);

#endif