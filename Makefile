# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rsoo <rsoo@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/11 10:54:28 by rsoo              #+#    #+#              #
#    Updated: 2023/05/11 10:54:28 by rsoo             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Mandatory Variables
NAME = push_swap
CC = gcc 
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g3
RM = rm -rf
INCLUDES = includes/push_swap.h

# c files in srcs
SRCS_DIR = srcs/
SRCS_FILES = doubly_linked_list_utils input_check operation_push \
				operation_rot_revrot operation_swap push_swap \
				sort_big sort_small sort_medium utils_1 utils_2
C_FILES = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(SRCS_FILES)))
# obj files: /objs will be created to store the obj files
OBJ = $(C_FILES:.c=.o)

LIBFT_DIR = libft
LIBFT = libft.a

# Bonus Variables
BONUS_NAME = checker
BONUS_DIR = bonus_srcs/
BONUS_FILES = checker checker_utils_1 checker_utils_2
BONUS_MAN_SRCS = doubly_linked_list_utils input_check operation_push \
				operation_rot_revrot operation_swap sort_big sort_small \
				sort_medium utils_1 utils_2
BONUS_C_FILES = $(addprefix $(BONUS_DIR), $(addsuffix .c, $(BONUS_FILES)))
BONUS_MAN_FILES = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(BONUS_MAN_SRCS)))
BONUS_C_OBJ = $(BONUS_C_FILES:.c=.o)
BONUS_MAN_OBJ = $(BONUS_MAN_FILES:.c=.o)

# Other utilities:
# object file creation
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LIBFT_DIR)/$(LIBFT)

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(BONUS_C_OBJ) $(BONUS_MAN_OBJ)
	make -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $(BONUS_C_OBJ) $(BONUS_MAN_OBJ) -o $(BONUS_NAME) $(LIBFT_DIR)/$(LIBFT)

# cleaning, re, phony
clean:
	$(RM) $(OBJ) $(BONUS_C_OBJ) $(BONUS_MAN_OBJ)
	make clean -C $(LIBFT_DIR)

fclean: clean
	$(RM) $(NAME) $(BONUS_NAME)
	make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all bonus libft clean fclean re


# Notes:
# 1. mkdir -p
# The -p option stands for "parents" and it enables the command to 
# create intermediate directories as needed. When you use mkdir -p, it 
# will create the specified directory and any parent directories that 
# don't exist.

# 2. make -C 
# make -C is a specific syntax used with the make utility to specify 
# the directory where the makefile resides before executing the build 
# process.