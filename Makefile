NAME = cub3d

FILES = main

SRC_DIR = src/
OBJ_DIR = obj/

CC = cc
FLAGS = -Wall -Wextra -Werror -lm -g

INCLUDE = include/cub3d.h

SRC = $(addprefix $(SRC_DIR), $(addsuffix .c), $(FILES))
OBJ = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(FILES)))

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

MLX_DIR		= ./minilibx-linux
MLX_FLAGS	= -L$(MLX_DIR) -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

OBJF = .cache_exits

GREEN = \033[0;92m
YELLOW = \033[33m
BLUE = \033[0;34m
PINK = \033[38;5;169m
PURPLE_1 = \033[38;5;181m
PURPLE_2 = \033[38;5;161m
RESET = \033[0;39

$(OBJF):
	@mkdir -p $(OBJ_DIR)

vpath %.c $(SRC_DIR)

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	@$(CC) $(FLAGS) $(OBJ) $(LIBFT) -g3 -o $(NAME)
	@echo -e "$(PURPLE_2)cub3d Compiled!$(RESET)"

$(OBJ_DIR)%.o: %.c $(INCLUDE) Makefile | $(OBJF)
	@$(CC) $(FLAGS) -c -g3 $< -o $@

$(LIBFT):
	@echo -e "$(PURPLE_1)Entering directory 'libft'$(RESET)"
	@make --no-print-directory -C $(LIBFT_DIR)
	@echo -e "$(PURPLE_1)Leaving directory 'libft'$(RESET)"

clean:
	@rm -f $(OBJ)
	@rm -rf $(OBJ_DIR)
	@echo -e "$(PURPLE_1)Entering directory 'libft'$(RESET)"
	@make --no-print-directory clean -C $(LIBFT_DIR)
	@echo -e "$(PURPLE_1)Leaving directory 'libft'$(RESET)"
	@echo -e "$(PINK)cub3d: make clean$(RESET)"

fclean:
	@rm -f $(OBJ)
	@rm -rf $(OBJ_DIR)
	@rm -f $(NAME)
	@echo -e "$(PURPLE_1)Entering directory 'libft'$(RESET)"
	@make --no-print-directory fclean -C $(LIBFT_DIR)
	@echo -e "$(PURPLE_1)Leaving directory 'libft'$(RESET)"
	@echo -e "$(PINK)cub3d: make fclean$(RESET)"

re: fclean all

.PHONY: all clean fclean re