/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 14:28:19 by lmicheli          #+#    #+#             */
/*   Updated: 2024/01/12 16:10:31 by lmicheli         ###   ########.fr       */
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

typedef struct s_pipex
{
	char	*file1; // input file
	char	*file2; // output file
	char	*line; // line read from input file
	char	*limiter; // limiter
	char	*path;
	char	*part_path;
	char	**paths;
	int		bonus;
	int		files[2]; // file descriptors
}		t_pipex;

int		file_exist(char *file);
int		file_readable(char *file);
int		file_writable(char *file);
int		ft_matrix_len(char **array);
int		get_new_next_line(char **line);
void	basic_check(char *file1);
void	do_commands(t_pipex *data);
void	parent(t_pipex *data);
void	child(t_pipex *data);
void	free_char_ptr_ptr(char **ptr);
void	free_char_ptr_ptr_ptr(char ***ptr);
void	free_int_ptr(int *ptr);
void	free_pipex(t_pipex *data);
void	close_all_fd(t_pipex *data);
void	get_file_names(t_pipex *data, char *file1, char *file2);
void	get_file_bonus(t_pipex *data, char *file, char *limiter);
char	**get_commands(char **av, int ac);
char	**get_args(t_pipex *data);
void	print_matrix(char **matrix);
void	print_matrix2(char ***matrix);
void	do_bonus(t_pipex *data, int ac);
void	bonus_child(int fd[2], t_pipex *data);
void	error(t_pipex *data, int error);
void	execute(char *cmd, char **mvp, t_pipex *data);
void	child_process(char *cmd, char **mvp, t_pipex *data);
void	here_doc(char *limiter, int argc, t_pipex *data);
t_pipex	*initialize(int ac, char **av, char **mvp, int nbr);

#endif