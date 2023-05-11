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
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

# c files in srcs
SRCS_DIR = /srcs
SRCS_FILES = push_swap
C_FILES = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(SRCS_FILES)))
# obj files: /objs will be created to store the obj files
OBJS_DIR = /objs
OBJ_FILES = $(C_FILES:.c=.o)

LIBFT = libft.a
LIBFT_DIR = /libft

# Bonus Variables
BONUS_NAME = checker

BONUS_DIR = /bonus
BONUS_FILES = push_swap
BONUS_C_FILES = $(addprefix $(BONUS_DIR), $(addsuffix .c, $(BONUS_FILES)))

BONUS_OBJ_FILES = $(BONUS_C_FILES:.c=.o)

# making directory (More info at notes below)
MKDIR = mkdir -p

# Other utilities:
# object file creation
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

libft:
	make -C $(LIBFT_DIR)

all:
	$(MKDIR) $(OBJS_DIR)
	make libft $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(LIBFT_DIR)/$(LIBFT) $(OBJS) -o $(NAME)

bonus:
	$(MKDIR) $(OBJS_DIR)
	make libft $(BONUS_NAME)

$(BONUS_NAME): $(BONUS_OBJS)
	$(CC) $(CFLAGS) $(LIBFT_DIR)/$(LIBFT) $(BONUS_OBJS) -o $(BONUS_NAME)

# cleaning, re, phony
clean:
	$(RM) $(OBJS_DIR)
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