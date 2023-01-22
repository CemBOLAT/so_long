NAME = so_long
CFLAGS = -Wall -Wextra -Werror

SO_LONG_SRC = *.c
SO_LONG_OBJ = $(SO_LONG_SRC:.c=.o)
SO_LONG = so_long.a

LIBFT_PATH = ./libft/
LIBFT = libft.a

FT_PRINTF_PATH = ./ft_printf
FT_PRINTF = libftprintf.a

GET_NEXT_LINE = get_next_line.a
GET_NEXT_LINE_PATH = ./get_next_line

MINILIBX_PATH = ./minilibx
MINILIBX = minilibx.a

all: $(NAME)

$(NAME): $(LIBFT) $(FT_PRINTF) $(GET_NEXT_LINE) $(SO_LONG) #minilibx
	@echo "\033[32mGAME IS COMPILING...\033[0m"
	@gcc $(CFLASGS) $(LIBFT) $(FT_PRINTF) $(GET_NEXT_LINE) $(SO_LONG) -o $(NAME)
	@echo "\033[32mCOMPILATION SUCCESS...\033[0m"

$(GET_NEXT_LINE) :
	@make -C get_next_line/
	@cp ./get_next_line/get_next_line.a .
	@echo "\033[32mGET_NEXT_LINE COMPILED\033[0m"

$(LIBFT) :
	@make -C libft/
	@cp ./libft/libft.a .
	@echo "\033[32mLIBFT COMPILED\033[0m"

$(FT_PRINTF) :
	@make -C ft_printf/
	@cp ./ft_printf/libftprintf.a .
	@echo "\033[32mFT_PRINTF COMPILED\033[0m"

$(MINILIBX) :
	@make -C minilibx/
	@cp ./minilibx/minilibx.a .
	@echo "\033[32mMINILIBX COMPILED\033[0m"

$(SO_LONG) :
	@gcc $(CFLAGS) -c $(SO_LONG_SRC)
	@ar -rcs so_long.a $(SO_LONG_OBJ)
	@echo "\033[32mSO_LONG COMPILED\033[0m"

clean:
	@echo "\033[32mCLEANING...\033[0m"
	@rm -rf *.o
	@make clean -C libft/
	@make clean -C ft_printf/
	@make clean -C get_next_line/
	@echo "\033[32mCLEANED\033[0m"

fclean: clean
	@echo "\033[32mARCHIVE FILES ARE CLEANING...\033[0m"
	@rm -rf $(LIBFT) ./libft/$(LIBFT)
	@rm -rf $(FT_PRINTF) ./ft_printf/$(FT_PRINTF)
	@rm -rf $(GET_NEXT_LINE) ./get_next_line/$(GET_NEXT_LINE)
	@rm -rf $(NAME)
	@rm -rf *.a
	@echo "\033[32mARCHIVE FILES WERE CLEANED\033[0m"

re: clean fclean all

.PHONY : clean fclean all re
