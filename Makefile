# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tpaaso <tpaaso@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/11 13:52:52 by tpaaso            #+#    #+#              #
#    Updated: 2023/01/02 12:46:19 by tpaaso           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRCS = libft/libft.a src/main.c src/key.c src/fdf.c src/validate.c

CCFL = gcc -g -Wall -Wextra -Werror -L /usr/local/lib -lmlx -I /minilibx/ -framework OpenGL -framework AppKit

LIBFT = libft/

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIBFT)
	@$(CCFL) -o $(NAME) $(OBJ) $(SRCS)

clean:
	@/bin/rm -f $(OBJ)5
	@make -C $(LIBFT) clean

fclean: clean
	@/bin/rm -f $(NAME)
	@make -C $(LIBFT) fclean

re: fclean all

proper: all clean

.PHONY = all $(NAME) clean fclean re
