NAME = so_long
CFLAGS = -Wall -Wextra -Werror
LFLAGS	=	-Lft_printf -Llibft -Lminilibx -framework OpenGL -framework AppKit

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

$(NAME): $(LIBFT) $(FT_PRINTF) $(GET_NEXT_LINE) $(SO_LONG) $(MINILIBX) #minilibx
	@echo "\033[32mSOURCE IS COMPILING...\033[0m"
	@gcc $(CFLASGS) $(LFLAGS) $(LIBFT) $(FT_PRINTF) $(GET_NEXT_LINE) $(SO_LONG) $(MINILIBX) -o $(NAME)
	@rm -rf *.a
	@echo "\033[32mCOMPILATION SUCCESS...\033[0m"

bonus : $(LIBFT) $(FT_PRINTF) $(GET_NEXT_LINE) $(MINILIBX)
	@echo "\033[32mBONUS IS COMPILING...\033[0m"
	@make -C bonus
	@cp bonus/so_long_bonus.a .
	@gcc $(CFLASGS) $(LFLAGS) $(LIBFT) $(FT_PRINTF) $(GET_NEXT_LINE) so_long_bonus.a $(MINILIBX) -o so_long_bonus
	@rm -rf *.a
	@echo "\033[32mBONUS COMPILED\033[0m"

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
	@make -C src/
	@cp ./src/so_long.a .
	@echo "\033[32mSO_LONG COMPILED\033[0m"

clean:
	@echo "\033[32mCLEANING...\033[0m"
	@rm -rf *.o
	@make clean -C libft/
	@make clean -C ft_printf/
	@make clean -C get_next_line/
	@make clean -C minilibx/
	@make clean -C src/
	@make clean -C bonus/
	@echo "\033[32mCLEANED\033[0m"

fclean: clean
	@echo "\033[32mARCHIVE FILES ARE CLEANING...\033[0m"
	@rm -rf $(NAME)
	@rm -rf $(LIBFT_PATH)/$(LIBFT)
	@rm -rf $(GET_NEXT_LINE_PATH)/$(GET_NEXT_LINE)
	@rm -rf $(FT_PRINTF_PATH)/$(FT_PRINTF)
	@rm -rf $(MINILIBX_PATH)/$(MINILIBX)
	@rm -rf src/so_long.a
	@rm -rf bonus/so_long_bonus.a
	@rm -rf so_long_bonus
	@rm -rf *.a
	@echo "\033[32mARCHIVE FILES WERE CLEANED\033[0m"

re: clean fclean all

.PHONY : clean fclean all re bonus
