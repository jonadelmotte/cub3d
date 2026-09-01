# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sdabbas <sdabbas@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/09/01 11:34:04 by jdelmott          #+#    #+#              #
#    Updated: 2026/09/01 16:04:02 by sdabbas          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FILES = ft_bzero ft_calloc ft_strjoin ft_strlen ft_strncmp get_next_line ft_strchr \

SRC_DIR = src/
OBJ_DIR = obj/

CC = cc
FLAGS = -Wall -Werror -Wextra -I.

SRC = $(addprefix $(SRC_DIR), $(addsuffix) .c, $(FILES))
OBJ = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(FILES)))

OBJF = .cache_exits

GREEN = \033[0;92m
YELLOW = \033[33m
PINK = \033[38;5;169m
PURPLE_2 = \033[38;5;161m
RESET = \033[0;39m

$(OBJF):
	@mkdir -p $(OBJ_DIR)

vpath %.c $(SRC_DIR)

all: $(NAME)

$(NAME): $(OBJ)
	@ar rcs $@ $^
	@echo -e "$(PURPLE_2)libft Compiled!$(RESET)"

$(OBJ_DIR)%.o: %.c $(OBJF)
	@$(CC) $(FLAGS) -c -g3 $< -o $@

clean:
	@rm -f $(OBJ)
	@rm -rf $(OBJ_DIR)
	@echo -e "$(PINK)libft: make clean$(RESET)"

fclean:
	@rm -f $(OBJ)
	@rm -rf $(OBJ_DIR)
	@rm -f $(NAME)
	@echo -e "$(PINK)libft: make fclean$(RESET)"

re: fclean all

.PHONY: all clean fclean re