/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpouzol <mpouzol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 15:30:01 by mpouzol           #+#    #+#             */
/*   Updated: 2020/01/07 19:34:41 by mpouzol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_search_exit(char *str, int *i)
{
	if ((str[*i] ==  ' ' && str[*i + 1] == 'e' && str[*i + 2] == 'x'
	&& str[*i + 3] == 'i') || (*i == 0 && str[*i] == 'e' &&
	str[*i + 1] == 'x' && str[*i + 2] == 'i'))
	{
		while (str[*i] == ' ')
			*i += 1;
		if (ft_strcmp(&str[*i], "exit") == 0)
		{
			ft_putstr("exit\n");
			exit(EXIT_SUCCESS);
		}
	}
}


