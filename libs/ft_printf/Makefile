# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joaomart <joaomart@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/06 12:00:03 by joaomart          #+#    #+#              #
#    Updated: 2025/01/21 14:33:09 by joaomart         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

SRCS_DIR = ./srcs
SRCS = $(addprefix $(SRCS_DIR)/, ft_printf.c ft_print_format.c ft_putchar.c \
	ft_putstr.c ft_putnbr.c ft_putunbr.c ft_puthexa.c ft_putptr.c)

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@ar rc $(NAME) $(OBJS)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: clean all

.PHONY: all clean fclean re
