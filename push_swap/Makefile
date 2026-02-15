# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbrooks- <	cbrooks-@student.42berlin.de    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/19 13:24:02 by cbrooks-          #+#    #+#              #
#    Updated: 2025/11/19 13:24:02 by cbrooks-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap

LIBFT	=	./libft/libft.a

CFLAGS	=	-Wall -Wextra -Werror

FILES	=	helper.c push_swap.c \
			sort_utils.c validate.c \
			validate_utils.c

OBJ			=	$(FILES:.c=.o)
RM			=	rm -f

all:		$(NAME)

$(NAME):	$(OBJ) $(LIBFT)
	@gcc $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)
	@echo "$(NAME) created"

$(LIBFT):
	@$(MAKE) -C ./libft

%.o:		%.c
	@gcc $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJ)
	@echo "OBJ deleted"

fclean:		clean
	@$(RM) $(NAME)
	@echo "$(NAME) deleted"

re:			fclean all

normi:		$(FILES)
	norminette $(FILES)

test:		main.c $(NAME)
	@gcc $(FLAG) main.c $(NAME) && ./a.out

git:
	git add .
	git commit -m "$m"
	git push origin main

.PHONY:		all clean fclean re