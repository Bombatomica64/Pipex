/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 14:28:19 by lmicheli          #+#    #+#             */
/*   Updated: 2024/01/15 16:51:49 by lmicheli         ###   ########.fr       */
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
# include <string.h>

int		file_exist(char *file);
int		file_readable(char *file);
int		file_writable(char *file);
int		ft_matrix_len(char **array);
int		get_new_next_line(char **line);
void	basic_check(char *file1);
void	do_bonus(char *limiter, int ac);
void	bonus_child(int fd[2], char *limiter, char *line);
void	error(int error);
void	free_char_ptr_ptr(char **ptr);
void	free_char_ptr_ptr_ptr(char ***ptr);
void	free_int_ptr(int *ptr);
void	print_matrix(char **matrix);
void	print_matrix2(char ***matrix);
void	execute(char *cmd, char **mvp);
void	child_process(char *cmd, char **mvp);
void	daddy_execute(char *cmd, char **mvp);
void	basic_check_ac(int ac, int bonus);
char	*find_path(char **envp, char *cmd);

#endif
