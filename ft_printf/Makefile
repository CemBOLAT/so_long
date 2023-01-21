# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbolat <cbolat@student.42kocaeli.com.tr    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/25 21:34:11 by cbolat            #+#    #+#              #
#    Updated: 2022/10/26 15:11:24 by cbolat           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

FLAGS = -Wall -Wextra -Werror

SRC = ft_*.c;

OBJ = ft_*.o

all: ${NAME}

${NAME}:
	@gcc ${FLAGS} -c ${SRC}
	@ar -rcs ${NAME} ${OBJ}

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re