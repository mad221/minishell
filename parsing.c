/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpouzol <mpouzol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 19:00:18 by mpouzol           #+#    #+#             */
/*   Updated: 2020/01/07 18:39:57 by mpouzol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int ft_parsing(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		ft_search_cd(str, &i);
		ft_search_echo(str, &i);
		ft_search_pwd(str, &i);
		ft_search_exit(str, &i);
		ft_search_export(str, &i);
		ft_search_unset(str, &i);
		printf("count = %d\n", i);
		i++;
	}
	return (1);
}
