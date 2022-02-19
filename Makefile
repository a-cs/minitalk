# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acarneir <acarneir@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/18 21:51:24 by acarneir          #+#    #+#              #
#    Updated: 2022/02/18 23:54:06 by acarneir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk

CLIENT = client
SERVER = server

CC = gcc
FLAGS = -Wall -Wextra -Werror

INCLUDE_DIR = ./include
INCLUDE = -I $(INCLUDE_DIR)

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

SRC_DIR = ./src
SRCS_CLIENT = $(addprefix $(SRC_DIR)/,$(CLIENT).c)
SRCS_SERVER = $(addprefix $(SRC_DIR)/,$(SERVER).c)

OBJ_DIR = ./objs
OBJS_CLIENT = $(addprefix $(OBJ_DIR)/,$(CLIENT).o)
OBJS_SERVER = $(addprefix $(OBJ_DIR)/,$(SERVER).o)


$(NAME): all

all: $(LIBFT) $(CLIENT) $(SERVER)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(CLIENT): $(OBJS_CLIENT)
	$(CC) $(FLAGS) -o $(CLIENT)  $(OBJS_CLIENT) $(LIBFT)

$(SERVER): $(OBJS_SERVER)
	$(CC) $(FLAGS) -o $(SERVER) $(OBJS_SERVER) $(LIBFT)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(FLAGS) $(INCLUDE) -c $< -o $@

clean:
		make clean -C ./libft
		rm -rf $(OBJ_DIR)

fclean: clean
		make fclean -C ./libft
		rm -rf $(CLIENT) $(SERVER)

re: fclean all