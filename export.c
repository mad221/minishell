/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpouzol <mpouzol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 18:47:56 by mpouzol           #+#    #+#             */
/*   Updated: 2020/01/08 14:23:57 by mpouzol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void    ft_swap_g_envp(int i)
{
	char *swap;

	swap = g_envp[i];
	g_envp[i] = g_envp[i + 1];
	g_envp[i + 1] = swap;
}

static char 	**ft_changer_order(char **str)
{
	int i;
	int len;
	int s;

	i = 0;
	len = 0;
	while (str[len])
		len++;
	s = len;
	while (s > 0)
	{
		i = 0;
		while (i < len - 1)
		{
			if (g_envp[i][0] > g_envp[i + 1][0])
				ft_swap_g_envp(i);
			i++;
		}
		s--;
	}
	return (g_envp);
}

static void	ft_print_export(void)
{
	int i;

	i = 0;
	ft_changer_order(g_envp);
	while (g_envp[i])
	{
		ft_putstr("declare -x ");
		ft_putstr(g_envp[i]);
		ft_putstr("\n");
		i++;
	}
}

int 	ft_isnumalpha(char c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9') ||
	(c >= 'a' && c <= 'z'))
		return (1);
	return (0);
}


char	**ft_export_word(char *str)
{
	int len;
	char **array;
	int exist;

	exist = 0;
	len = 0;
	while (g_envp[len])
		len++;
	if (!(array = malloc(sizeof(char *) * len + 2)))
		return (0);
	len = 0;
	while (g_envp[len])
	{
		array[len] = g_envp[len];
		if (str != NULL)
			if (ft_strcmp(g_envp[len], str) == 0)
				exist = 1;
			len++;
	}
	array[len] = (exist == 0) ? str : NULL;

	array[len + 1] = NULL;
	return (array);
}

int		ft_add_to_envp(char *str)
{
	int i;
	int len;
	int s;
	char *word;

	len = 0;
	s = 0;
	i = 0;
	while ((str[len] && ft_isnumalpha(str[len]) == 1) || str[len] == '=')
		len++;
	if (!(word = malloc(sizeof(char) * len + 3)))
		return (0);
	while (i < len)
	{
		if (i != 0 && str[i - 1] == '=')
		{
			word[s] = '\"';
			word[len+1] = '\"';
			s++;
		}
		word[s] = str[i];
		i++;
		s++;
	}
	word[s+1] = '\0';
	g_envp = ft_export_word(word);
	return (1);
}

void	ft_search_export(char *str, int *i)
{
	if ((*i  == 0 && str[*i] == 'e' && str[*i + 1] == 'x'
	&& str[*i + 2] == 'p' && str[*i + 3] == 'o') ||
	(str[*i] == ' ' && str[*i + 1] == 'e' && str[*i + 2] == 'x' && str[*i + 3] == 'p'))
	{
		while ( str[*i] == ' ')
			*i += 1;
		if (ft_strcmp(&str[*i], "export") == 0)
		{
			*i += 6;
			while (str[*i] == ' ')
				*i += 1;
			if (str[*i] != '|' && str[*i] != '\n' && str[*i] != ';')
				ft_add_to_envp(&str[*i]);
			else
				ft_print_export();
		}
		*i += 4;
	}
}
