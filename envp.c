/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpouzol <mpouzol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 17:34:49 by mpouzol           #+#    #+#             */
/*   Updated: 2019/12/07 17:50:37 by mpouzol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_strdup(char *src)
{
	char	*new;
	int		i;
	int		size;

	size = 0;
	while (src[size])
		++size;
	if (!(new = malloc(sizeof(char) * (size + 1))))
		return (NULL);
	i = 0;
	while (src[i])
	{
		new[i] = src[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

int		init_envp(char **envp)
{
	int		i;

	if (!(g_envp = (char **)malloc(sizeof(char *) * (ft_strstrlen(envp) + 1))))
		return (0);
	i = -1;
	while (envp[++i])
	{
		if (!(g_envp[i] = ft_strdup(envp[i])))
			return (0);
	}
	return (1);
}

char	*strjoin_one(char const *s1, char c)
{
	char	*new_str;
	size_t	i;
	size_t	s1_len;

	if (!s1 || !c)
		return (NULL);
	s1_len = ft_strlen(s1);
	new_str = (char *)malloc(s1_len + 1);
	if (!new_str)
		return (NULL);
	i = -1;
	while (++i < s1_len)
		*(new_str + i) = *(s1 + i);
	*(new_str + i) = c;
	return (new_str);
}

int		if_first(char *s1, char *s2)
{
	int	i;

	i = -1;
	while (s2[++i])
		if (s1[i] != s2[i])
			return (0);
	return (1);
}

int		find_env(char *var)
{
	int		i;
	char	*tmp;

	i = -1;
	while (g_envp[++i])
	{
		tmp = strjoin_one(var, '=');
		if (if_first(g_envp[i], tmp))
		{
			free(tmp);
			return (i);
		}
		free(tmp);
	}
	return (i);
}
