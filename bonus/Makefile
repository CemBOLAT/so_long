NAME = so_long_bonus.a

FLAGS = -Wall -Wextra -Werror

SRC = map_control.c \
	  map_control2.c \
	  map_control3.c \
	  path_control.c \
	  exit.c \
	  key_comb.c \
	  shell_print.c \
	  minilibx_create.c \
	  so_long.c \
	  shell_print.c \
	  key_check_exit.c \

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@ar -rcs $(NAME) $(OBJ)

%.o: %.c
	@gcc $(FLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
