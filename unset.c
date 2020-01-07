/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpouzol <mpouzol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 10:48:52 by mpouzol           #+#    #+#             */
/*   Updated: 2020/01/07 15:48:38 by mpouzol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_strcmp_spe(char *str)
{
	int i;
	int s;

	i = 0;
	while (g_envp[i])
	{
		s = 0;
		while (str[s] == g_envp[i][s])
			s++;
		if ((str[s] == '\n' && g_envp[i][s] == '=') || (str[s] == '\n' && g_envp[i][s] == '\0'))
			return (i);
		i++;
	}
	return (-1);
}


static void	ft_unset(char *str)
{
	int found;
	int i;
	int s;
	char **array;

	if ((found = ft_strcmp_spe(str)) == -1)
		return ;
	i = 0;
	s = 0;
	while (g_envp[i])
		i++;
	if (!(array = malloc(sizeof(char) * (i))))
		return ;
	i = 0;
	while (g_envp[i])
	{
		if (i == found)
			i++;
		array[s] = g_envp[i];
		i++;
		s++;
	}
	array[s] = NULL;
	g_envp = array;
}

void	ft_search_unset(char *str, int *i)
{
	while (str[*i] == ' ')
		*i += 1;
	if (ft_strcmp(&str[*i], "unset") == 0)
	{
		*i += 6;
		ft_unset(&str[*i]);
	}
}
