NAME = so_long

SO_LONG_SRC = *.c

SO_LONG_OBJ = $(SO_LONG_SRC:.c=.o)

SO_LONG = so_long.a

LIBFT_PATH = ./libft/

LIBFT = libft.a

CFLASGS = -Wall -Wextra -Werror

FT_PRINTF_PATH = ./ft_printf

FT_PRINTF = libftprintf.a

MINILIBX_PATH = ./minilibx

MINILIBX = minilibx.a

all: $(NAME)

$(NAME): $(LIBFT) $(FT_PRINTF) $(SO_LONG) #minilibx
	gcc $(CFLASGS) $(LIBFT) $(FT_PRINTF) $(SO_LONG) -o $(NAME)

$(LIBFT) :
	make -C libft/
	cp ./libft/libft.a .

$(FT_PRINTF) :
	make -C ft_printf/
	cp ./ft_printf/libftprintf.a .

$(MINILIBX) :
	make -C minilibx/
	cp ./minilibx/minilibx.a .

$(SO_LONG) :
	gcc $(CFLAGS) -c $(SO_LONG_SRC)
	ar -rcs so_long.a $(SO_LONG_OBJ)

clean:
	rm -rf *.o
	make clean -C libft/
	make clean -C ft_printf/

fclean: clean
	rm -rf $(LIBFT) ./libft/$(LIBFT)
	rm -rf $(FT_PRINTF) ./libft/$(FT_PRINTF)
	rm -rf $(NAME)
	rm -rf *.a

re: clean fclean all

.PHONY : clean fclean all re
