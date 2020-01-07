/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpouzol <mpouzol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 16:22:19 by bshi              #+#    #+#             */
/*   Updated: 2019/12/07 16:17:07 by mpouzol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*char    *cut_cwd(char *cwd)
{

}*/

void    display_prompt()
{
    char *cwd;
//    char *cutted;

    cwd = getcwd(NULL, 0);
//    cutted = cut_cwd(cwd);
    ft_putstr("\033[32m➠ \033[0m");
//    ft_putstr(cutted);
}

int     main(int ac, char **av, char **envp)
{
    (void)ac;
    (void)av;
    g_envp = envp;
    int i;

    i = 0;
    //display_prompt();
    //while(envp[i])
       // printf("%s\n ici ",envp[i++]);

    pid_t pid = create_process();

    if (pid == -1)
        return (0);
    if (pid == 0)
        child_process();
    else
        father_process(pid);
    return (0);
}
