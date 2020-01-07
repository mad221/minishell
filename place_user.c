/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_user.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpouzol <mpouzol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 17:11:20 by mpouzol           #+#    #+#             */
/*   Updated: 2019/12/07 17:56:03 by mpouzol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include  "minishell.h"

char		*ft_place(char *str)
{
	int i;

	i = ft_strlen(str);
	while (str[i]  != '/')
		i--;
	return (&str[i + 1]);
}

static int	ft_path_usr(char *str)
{
	int i;
	int s;
	int value;

	s = 0;
	i = 0;
	value = find_env("HOME");
	while (g_envp[value][i] != '/')
		i++;
	while (g_envp[value][i + s])
	{
		if (str[s] != g_envp[value][i + s])
			return (0);
		s++;
	}
	return (1);
}

void	ft_show_prompt(void)
{
	if ((ft_path_usr(getcwd(NULL, 0))) == 0)
		write(1, "/ ", 2);
	else
		write(1, "~ ", 2);
	ft_putstr(ft_place(getcwd(NULL, 0)));
	write(1, " ", 1);
}
