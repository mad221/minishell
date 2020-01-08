/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpouzol <mpouzol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 12:51:44 by mpouzol           #+#    #+#             */
/*   Updated: 2020/01/08 12:27:06 by mpouzol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "get_next_line.h"

pid_t create_process(void)
{
	pid_t pid;

	pid = fork();
	while (pid == -1)
		pid = fork();
	return (pid);
}

void child_process()
{
	printf(" j'ai fini dady\n");
}

void father_process(int child_pid)
{

	if (wait(NULL))
		printf("process child = %d terminate\n", child_pid);
}
