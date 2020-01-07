/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpouzol <mpouzol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 13:19:55 by mpouzol           #+#    #+#             */
/*   Updated: 2020/01/07 19:08:53 by mpouzol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_search_pwd(char *str, int *i)
{
	if (*i == 0 || str[*i - 1] == ' ')
		if (str[*i] == 'p' &&
		str[*i + 1] == 'w' && str[*i + 2] == 'd')
		{
			*i += 3;
			printf("rentre\n");
			while (str[*i] == ' ')
				*i += 1;
			if (str[*i] == '\n' || str[*i] == '|' || str[*i] == ';')
			{
				ft_putstr(getcwd(NULL, 0));
				ft_putstr("\n");
			}
			printf("str = %s", &str[*i]);
	}
}
