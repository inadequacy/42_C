# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbrooks- <	cbrooks-@student.42berlin.de    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/05 15:28:12 by cbrooks-          #+#    #+#              #
#    Updated: 2026/01/08 13:13:55 by cbrooks-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	getnextline.a

FILES	=	\
	get_next_line.c get_next_line_utils.c

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