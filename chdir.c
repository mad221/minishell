/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chdir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpouzol <mpouzol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 18:51:35 by mpouzol           #+#    #+#             */
/*   Updated: 2019/12/12 10:39:36 by mpouzol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int		ft_cd(char *hope_path)
{
	int i;
	char *new_path;

	i = 0;
	while (hope_path[i] && hope_path[i] != ' ')
		i++;
	if ((i == 1 && hope_path[0] == '\n') || !(new_path = malloc(sizeof(char) * i + 1)))
		return (0);
	i = -1;
	while (hope_path[++i] && hope_path[i] != ' ' && hope_path[i] != '\n')
		new_path[i] = hope_path[i];
	new_path[i] = '\0';
	if (chdir(new_path) < 0)
		ft_putstr("Error\nPath Not Found\n");
	free(new_path);
	return(1);
}

void			ft_search_cd(char *str, int i)
{
	if ((str[i] == ' ' && ( str[i + 1] == 'c' && str[i + 2] == 'd'))
		|| (str[0] == 'c' && str[i + 1] == 'd'))
		{
			i += 2;
			if (str[i] == ' ')
			{	while (str[i] == ' ')
					i++;
				ft_cd(&str[i]);
			}
		}
}
