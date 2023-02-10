# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgraefen <mgraefen@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/24 11:58:47 by mgraefen          #+#    #+#              #
#    Updated: 2023/02/06 17:16:40 by mgraefen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= 	push_swap
NAME2		=	checker
CC 			= 	cc
CFLAGS 		=   -Wall -Wextra -Werror #-fsanitize=address -g
SRC_DIR		= 	src
SRC_DIR2	= 	src/bonus
OBJ_DIR 	= 	obj
OBJ_DIR2 	= 	obj/bonus
DIR_DUP 	=	mkdir -p $(@D)

SRC 		= push_swap.c \
				utils.c \
				utils_2.c \
				load_stack.c \
				rotation.c \
				solve.c \
				movement.c \
				free_utils.c \
				swapping.c

SRC2		= checker_bonus.c \
				check_input_bonus.c \
				utils_bonus.c \
				utils_2_bonus.c \
				load_stack_bonus.c \
				rotation_bonus.c \
				movement_bonus.c \
				free_utils_bonus.c \
				swapping_bonus.c

SRC 		:= $(SRC:%=$(SRC_DIR)/%)
SRC2		:= $(SRC2:%=$(SRC_DIR2)/%)
OBJ 		= $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
OBJ2 		= $(SRC2:$(SRC_DIR2)/%.c=$(OBJ_DIR2)/%.o)
LIBFT 		= ./libft/libft.a

all: $(NAME)

bonus: $(NAME2)

%.o: %.c
	gcc $(CFLAGS) -c $^ -o $@

$(NAME): $(LIBFT) $(OBJ)
	@$(CC) $(OBJ) $(LIBFT) -o $(NAME)

$(NAME2): $(LIBFT) $(OBJ2)
	@$(CC) $(OBJ2) $(LIBFT) -o $(NAME2)
	
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(DIR_DUP)
	$(CC) $(CFLAGS) -c -o $@ $<

$(OBJ_DIR2)/%.o: $(SRC_DIR2)/%.c
	$(DIR_DUP)
	$(CC) $(CFLAGS) -c -o $@ $<

$(LIBFT):
	@git submodule init Libft
	@git submodule update Libft
	@cd libft && make && make clean

clean:
	@rm -rf $(OBJ) $(OBJ_DIR) $(OBJ2) $(OBJ_DIR2)

fclean: clean
	@rm -rf $(NAME) $(NAME2)

libclean:
	@rm -rf ./libft
re: fclean all

.PHONY: all bonus clean fclean re
