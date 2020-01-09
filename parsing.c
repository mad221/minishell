/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpouzol <mpouzol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 19:00:18 by mpouzol           #+#    #+#             */
/*   Updated: 2020/01/08 19:45:51 by mpouzol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int ft_parsing(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		printf("check 1\n");
		ft_search_cd(str, &i);
		printf("check 2\n");
		ft_search_echo(str, &i);
		printf("check 3\n");
		ft_search_pwd(str, &i);
		printf("check 4\n");
		ft_search_exit(str, &i);
		printf("check 5\n");
		ft_search_export(str, &i);
		printf("check 6\n");
		ft_search_unset(str, &i);
		printf("check 7\n");
		printf("count = %d\n", i);
		i++;
	}
	return (1);
}
