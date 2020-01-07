/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpouzol <mpouzol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 11:18:15 by mpouzol           #+#    #+#             */
/*   Updated: 2020/01/07 10:36:00 by mpouzol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int ft_echon(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ')
		i++;
	while(str[i] && str[i] != '|' && str[i] != '\n')
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

static int	ft_echo(char *str)
{
	int i;

	i = 0;
	if (str[i] == '-' && str[i + 1] == 'n')
		return (ft_echon(&str[i + 2]));
	while(str[i] && str[i] != '|')
	{
		write(1, &str[i], 1);
		i++;
	}
	if (str[i - 1] != '\n')
		write(1, "\n", 1);
	return (i);
}

static int	ft_strcmp_spe(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s2[i] != '=')
	{
		if (s1[i] != s2[i] || s1[i] == '\n')
			return (1);
		i++;
	}
	if (s1[i] == '\n')
		return (0);
	return (1);
}

static void ft_putvar(char *str)
{
	int i;

	i = 0;
	ft_putchar('=');
	while (str[i] != '\"')
	{
		ft_putchar(str[i]);
		i++;
	}
}

static void	ft_echo_var(char *str, int start)
{
	int i;

	i = 0;
	while (g_envp[i])
	{
		if (ft_strcmp_spe(&str[start], g_envp[i]) == 0)
		{
			ft_putvar(&g_envp[i][start - 1]);
			break;
		}
		i++;
	}
	ft_putchar('\n');
}

void ft_search_echo(char *str, int *i)
{
	if (str[*i] == 'e')
		if (ft_strcmp(&str[*i], "echo") == 0)
		{
			*i += 4;
			while (str[*i] == ' ')
				*i += 1;
			if (str[*i] == '$')
				ft_echo_var(str, *i + 1);
			else
				*i += ft_echo(&str[*i]);
		}
}
