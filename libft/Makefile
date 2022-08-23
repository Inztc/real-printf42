# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: btiewcha <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/24 01:31:30 by btiewcha          #+#    #+#              #
#    Updated: 2022/08/24 01:31:32 by btiewcha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_PART = ./ft_itoa.c ./ft_putchar_fd.c ./ft_putstr_fd.c ./ft_strdup.c ./ft_strlen.c ./ft_memcpy.c
SRC_BONUS = 
NAME = libft.a
FLAGS = -Wall -Werror -Wextra
CC = gcc -c
HDRS = libft.h
OBJ_PART = $(SRC_PART:.c=.o)
OBJ_BONUS = $(OBJ_PART) $(SRC_BONUS:.c=.o)

%.o:%.c
	@gcc -Wall -Wextra -Werror -o $@ -c $<

$(NAME): $(OBJ_PART) $(HDRS)
	@$(CC) $(SRC_PART) $(FLAGS)
	@ar r $(NAME) $(OBJ_PART)
	@echo "Libft Compiled."

bonus: $(OBJ_BONUS) $(HDRS)
	@$(CC) $(SRC_PART) $(SRC_BONUS) $(FLAGS)
	@ar r $(NAME) $(OBJ_BONUS)
	@echo "Libft Compiled."

all: $(NAME)

clean:
	@/bin/rm -f $(OBJ_BONUS)
	@echo "Libft files deleted"

fclean: clean
	@/bin/rm -f $(NAME)
	@echo "Libft deleted."

re: fclean all

.PHONY: all clean fclean re bonus
