# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tpaaso <tpaaso@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/02 13:02:45 by tpaaso            #+#    #+#              #
#    Updated: 2020/11/02 13:03:10 by tpaaso           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRCS = libft/libft.a srcs/main.c srcs/draw.c srcs/key.c srcs/fdf.c

OBJ = $(SRC:.c=.o)

CCFL = gcc -g -Wall -Wextra -Werror -I /usr/local/include/ -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit

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
