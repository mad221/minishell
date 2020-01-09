/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_stdin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpouzol <mpouzol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 14:31:08 by mpouzol           #+#    #+#             */
/*   Updated: 2020/01/09 10:33:04 by mpouzol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "get_next_line.h"


char		*ft_add_to_string(char *str, char c)
{
	char *string;
	int i;
	int len;

	i = 0;
	if (str == NULL)
		len = 0;
	else
		len = ft_strlen(str);
		if (!(string = malloc(sizeof(str) * len + 2)))
			return (0);
	while (i < len)
	{
		string[i] = str[i];
		i++;
	}
	string[i] = c;
	string[i + 1] = '\0';
	return (string);
}

void	ft_read_stdin(void)
{
	int fd;
	char *str;
	int end;
	char c;

	end = 0;
	str = NULL;
	if ((fd = open("/dev/fd/0", O_RDONLY) < 0))
		return ;
	while (end >= 0)
	{
		ft_show_prompt();
		while ((end = read(fd, &c, 1)) >= 0)
		{
			str = ft_add_to_string(str, c);
			if (end == 1 && c == '\n')
			{
				ft_parsing(str);
				free(str);
				ft_show_prompt();
			}
		}
	}
	close(fd);
}

int ft_search( char *str1, char **str2)
{
	int i;
	int s;

	i = -1;
	while (str2[++i])
	{
		s = 0;
		while (str1[s] == str2[i][s])
		{
			s++;
			if (s == 4)
				return (i);
		}
	}
	return (i);
}
