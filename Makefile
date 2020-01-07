# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpouzol <mpouzol@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/04 17:42:28 by bshi              #+#    #+#              #
#    Updated: 2019/12/11 18:51:52 by mpouzol          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			=	main.c utils.c place_user.c process.c get_next_line.c read_stdin.c envp.c parsing.c export.c chdir.c pwd.c echo.c exit.c

OBJS			= $(SRCS:.c=.o)

RM				= rm -f

CFLAGS			= -Wall -Wextra -Werror

NAME			= minishell

all:			$(NAME)

$(NAME):		$(OBJS)
				gcc $(CFLAGS) -I . -o $(NAME) $(OBJS)

clean:
				@$(RM) $(OBJS)

fclean:			clean
				@$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re
