/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpouzol <mpouzol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 17:39:28 by bshi              #+#    #+#             */
/*   Updated: 2020/01/07 10:53:25 by mpouzol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include <dirent.h>
# include <stdio.h>

char    **g_envp;

void	ft_putchar(char c);
void	ft_putstr(char *s);
int		ft_strlen(const char *s);
int		ft_strstrlen(char **s);
char	*ft_place(char *s);
void	child_process(void);
void	father_process(int child_pid);
pid_t	create_process(void);
void 	ft_read_stdin(void);
void	ft_show_prompt(void);
int		find_env(char *var);
int		ft_parsing(char *str);
void	ft_search_cd(char *str, int i);
int		ft_strcmp(char *str1, char *str2);
void	ft_search_echo(char *str, int *i);
void	ft_search_pwd(char *str, int *i);
void	ft_search_exit(char *str, int *i);
void	ft_search_export(char *str, int *i);
void	ft_search_unset(char *str, int i);

#endif
