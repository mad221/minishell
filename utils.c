/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpouzol <mpouzol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 17:38:30 by bshi              #+#    #+#             */
/*   Updated: 2020/01/08 14:17:05 by mpouzol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    ft_putchar(char c)
{
    write(1, &c, 1);
}

void    ft_putstr(char *s)
{
    int i;

    i = 0;
    while(s[i] != '\0')
    {
        ft_putchar(s[i]);
        i++;
    }
}

int     ft_strlen(const char *s)
{
    int i;

    i = 0;
    while(s[i])
        i++;
    return (i);
}

int     ft_strstrlen(char **s)
{
    int i;
    int count;

    i = -1;
    count = 0;
    while (s[++i])
        count++;
    return (count);
}

int ft_strcmp(char *str1, char *str2)
{
    int i;

    i = 0;
    if (str2 != NULL && str1 != NULL)
    {
        while (str2[i] && str1[i])
        {
            if (str1[i] != str2[i])
            return (-1);
            i++;
        }
        if (str1[i] != '\n' && str1[i] != ' ')
            return (-1);
        return (0);
    }
    return (-1);
}
