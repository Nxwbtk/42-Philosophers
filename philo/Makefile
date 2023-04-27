# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bsirikam <bsirikam@student.42bangkok.com>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/05 04:36:19 by bsirikam          #+#    #+#              #
#    Updated: 2023/04/27 21:49:09 by bsirikam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = gcc
UNAME = $(shell uname -s)

CFLAGS = -Wall -Wextra -Werror

ifneq ($(UNAME), Darwin)
	CFLAGS += -O2
endif

SRC = main.c ft_split.c ft_atoi.c ft_select_size.c ft_strdup.c \
ft_create_philo.c ft_create_thread.c ft_free_lst.c ft_kunjaeban.c ft_checkdie.c \
ft_init_time.c ft_activity.c ft_is_one.c ft_time.c ft_util1.c
HEADER = philo.h

OBJ_C = $(SRC:.c=.o)
OBJ_DIR = obj
OBJ = $(addprefix $(OBJ_DIR)/,$(OBJ_C))

$(OBJ_DIR)/%.o: %.c $(HEADER)
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) -pthread -o $(NAME) $(OBJ)

%.o: %.c $(HEADER)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re all
