/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 14:28:19 by lmicheli          #+#    #+#             */
/*   Updated: 2024/01/09 18:28:21 by lmicheli         ###   ########.fr       */
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

typedef struct s_pipex
{
	char	*file1; // input file
	char	*file2; // output file
	char	**cmds;
	char	***split_cmds;
	char	**cmd_args;
	int		current_cmd;
	int		*fd;
	int		*files;
	int		fd_nbr;
	pid_t	chi_pid;
}		t_pipex;

typedef struct s_bonus
{
	int		file_fd;
	int		fd[2];
	pid_t	chi_pid;
	char	*file;
	char	*limiter;
	char	**limiter_cmd;
	char	**limiter_cmd2;
	char	**limiter_cmd_args;
}		t_bonus;

int		file_exist(char *file);
int		file_readable(char *file);
int		file_writable(char *file);
int		ft_matrix_len(char **array);
int		*open_files(char *file1, char *file2);
void	basic_check(char *file1, char *file2);
void	do_commands(t_pipex *data);
void	parent(t_pipex *data);
void	child(t_pipex *data);
void	free_bonus(t_bonus *data);
void	free_char_ptr(char *ptr);
void	free_char_ptr_ptr(char **ptr);
void	free_char_ptr_ptr_ptr(char ***ptr);
void	free_int_ptr(int *ptr);
void	free_pipex(t_pipex *data);
void	close_all_fd(t_pipex *data);
void	get_file_names(t_pipex *data, char *file1, char *file2);
char	**get_commands(char **av, int ac);
char	**get_args(t_pipex *data);
char	**get_bonus_args(t_bonus *data);
char	***ft_gigasplit(t_pipex *data);
void	print_matrix(char **matrix);
void	print_matrix2(char ***matrix);
void	bonus_check(int ac, char **av);
void	do_bonus(int ac, char **av);
void	parent_bonus(t_bonus *data);
void	child_bonus(t_bonus *data);

#endif