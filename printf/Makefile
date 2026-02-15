# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbrooks- <cbrooks-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/23 22:14:10 by cbrooks-          #+#    #+#              #
#    Updated: 2026/01/05 14:33:28 by cbrooks-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a

FILES	=	\
	ft_printf.c ft_printf_helpers.c

OBJ		=	$(FILES:.c=.o)

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror
RM		=	rm -f

$(NAME):	$(OBJ)
	ar rcs $(NAME) $(OBJ)

all:		$(NAME)

clean:
	$(RM) $(OBJ)

fclean:		clean
	$(RM) $(NAME)

re:			fclean $(NAME)

norm:		$(FILES)
	norminette $(FILES)

.PHONY:		all clean fclean re