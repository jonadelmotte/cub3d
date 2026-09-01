NAME = cub3d

FILES = pipi

SRC_DIR = src/
OBJ_DIR = obj/

CC = cc
FLAGS = -Wall -Wextra -Werror -lm -g

INCLUDE = include/cub3d.h

SRC = $(addprefix $(SRC_DIR), $(addprefix .c), $(FILES))
OBJ = $(addprefix $(OBJ_DIR), $((addsuffix .o, $(FILES)))

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

MLX_DIR		= ./minilibx-linux
MLX_FLAGS	= -L$(MLX_DIR) -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

OBJF = .cache_exits

GREEN = \033[0;92m
YELLOW = \33[33m
RESET = \033[0;39

$(OBJF):
	@mkdir -p $(OBJ_DIR)

vpath %.c $(SRC_DIR) $(SRC_DIR)/parsing

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	@$(CC) $(FLAGS) -o $(NAME)
	@echo -e "$(GREEN)cub3d Compiled!$(RESET)"

$(OBJ_DIR)%.o: %.c $(INCLUDE) Makefile | $(OBJF)
	@$(CC) $(FLAGS) $< -o $@

$(LIBFT):
	@make -C $(LIBFT_DIR)

clean:
	@rm -f $(OBJ)
	@rm -rf $(OBJ_DIR)
	@make clean -C $(LIBFT_DIR)
	@echo -e "$(YELLOW)cub3d: make clean$(RESET)"

fclean:
	@rm -f $(OBJ)
	@rm -rf $(OBJ_DIR)
	@rm -f $(NAME)
	@make fclean -C $(LIBFT_DIR)
	@echo -e "$(YELLOW)cub3d: make fclean$(RESET)"