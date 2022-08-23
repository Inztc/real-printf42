# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: btiewcha <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/24 01:30:43 by btiewcha          #+#    #+#              #
#    Updated: 2022/08/24 01:30:47 by btiewcha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a
LIBFT	= libft
INCLUDES = includes
CC	= gcc
CFLGAS	= -Wall -Wextra -Werror
OBJDIR	= obj

SOURCES	= ft_printf.c utils_general.c utils_hex.c utils_pointer.c utils_unsigned.c

SRCDIR	= srcs
SRCS	= ${addprefix $(SRCDIR)/, $(SOURCES)}
OBJS	= ${addprefix $(OBJDIR)/, $(SOURCES:.c=.o)}

all:	${NAME}

$(NAME): $(OBJS)
	make -C $(LIBFT)
	cp libft/libft.a ./$(NAME)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	mkdir -p obj
	${CC} ${CFLAGS} -I ${INCLUDES} -c $< -o $@

clean:
	rm -f $(OBJS)
	rm -rf $(OBJDIR)
	make clean -C $(LIBFT)
	

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT)

re :	fclean all

.PHONY: all clean fclean re
