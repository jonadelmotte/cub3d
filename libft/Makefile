
NAME = libft.a

FILES = ft_bzero ft_calloc ft_strjoin ft_strlen ft_strncmp get_next_line

SRC_DIR = src/
OBJ_DIR = obj/

CC = cc
FLAGS = -Wall -Werror -Wextra

INCLUDE =  include/libft.h

SRC = $(addprefix $(SRC_DIR), $(addsuffix) .c, $(FILES))
OBJ = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(FILES)))

OBJF = .cache_exits

GREEN = \033[0;92m
YELLOW = \033[33m
RESET = \033[0;39m

$(OBJF):
	@mkdir -p $(OBJ_DIR)

vpath %.c $(SRC_DIR)

all: $(NAME)

$(NAME): $(OBJ)
	@ar rcs $@ $^
	@echo -e "$(GREEN)libft Compiled!$(RESET)"

$(OBJ_DIR)%.o: %.c $(INCLUDE) Makefile | $(OBJF)
	@$(CC) $(FLAGS) -c -g3 $< -o $@

clean:
	@rm -f $(OBJ)
	@rm -rf $(OBJ_DIR)
	@echo -e "$(YELLOW)libft: make clean$(RESET)"

fclean:
	@rm -f $(OBJ)
	@rm -rf $(OBJ_DIR)
	@rm -f $(NAME)
	@echo -e "$(YELLOW)libft: make fclean$(RESET)"

re: fclean all

.PHONY: all clean fclean re