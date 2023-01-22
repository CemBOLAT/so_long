NAME = get_next_line.a

SRC = *.c
OBJ = $(SRC:.c=.o)
CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) :
	@gcc $(CFLAGS) -c $(SRC)
	@ar -rcs $(NAME) $(OBJ)
re : fclean all

clean :
	@rm -rf $(OBJ)

fclean : clean
	@rm -rf $(NAME)

.PHONY : all bonus clean fclean re