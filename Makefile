# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joaomart <joaomart@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/23 09:55:49 by joaomart          #+#    #+#              #
#    Updated: 2025/02/26 17:45:39 by joaomart         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_S = server
NAME_C = client
CC = cc
FLAGS = -Wall -Wextra -Werror

# Libft e ft_printf #
LIBFT_DIR = libs/libft
FT_PRINTF_DIR = libs/ft_printf
LIBFT = $(LIBFT_DIR)/libft.a
FT_PRINTF = $(FT_PRINTF_DIR)/libftprintf.a

# minitalk #
MINITALK_DIR = srcs
SERVER = $(MINITALK_DIR)/server.c
CLIENT = $(MINITALK_DIR)/client.c
SERVER_OBJ = $(SERVER:.c=.o)
CLIENT_OBJ = $(CLIENT:.c=.o)

all: $(NAME_S) $(NAME_C)

$(NAME_S): $(SERVER_OBJ) $(LIBFT) $(FT_PRINTF)
	@echo "$(BLUE)🔨 Building $(NAME_S)...$(RESET)"
	@$(CC) $(FLAGS) $(SERVER_OBJ) $(LIBFT) $(FT_PRINTF) -o $(NAME_S)
	@echo "$(BOLD_GREEN)✅ $(NAME_S) built successfully!$(RESET)"

$(NAME_C): $(CLIENT_OBJ) $(LIBFT) $(FT_PRINTF)
	@echo "$(BLUE)🔨 Building $(NAME_C)...$(RESET)"
	@$(CC) $(FLAGS) $(CLIENT_OBJ) $(LIBFT) $(FT_PRINTF) -o $(NAME_C)
	@echo "$(BOLD_GREEN)✅ $(NAME_C) built successfully!$(RESET)"

%.o: %.c
	@echo "$(YELLOW)🛠️ Compiling $<...$(RESET)"
	@$(CC) $(FLAGS) -c $< -o $@

$(LIBFT):
	@echo "$(BLUE)📚 Compiling libft...$(RESET)"
	@$(MAKE) -C $(LIBFT_DIR) --no-print-directory
	@echo "$(BOLD_GREEN)✅ libft.a built successfully!$(RESET)"

$(FT_PRINTF):
	@echo "$(BLUE)🖨️  Compiling ft_printf...$(RESET)"
	@$(MAKE) -C $(FT_PRINTF_DIR) --no-print-directory
	@echo "$(BOLD_GREEN)✅ libftprintf.a built successfully!$(RESET)"

clean:
	@echo "$(BLUE)🧹 Cleaning object files...$(RESET)"
	@rm -f $(SERVER_OBJ) $(CLIENT_OBJ)
	@$(MAKE) -C $(LIBFT_DIR) clean --no-print-directory
	@$(MAKE) -C $(FT_PRINTF_DIR) clean --no-print-directory
	@echo "$(BOLD_GREEN)✅ Object files cleaned.$(RESET)"

fclean: clean
	@echo "$(BLUE)🗑️  Removing $(NAME_S) & $(NAME_C)...$(RESET)"
	@rm -f $(NAME_S) $(NAME_C)
	@$(MAKE) -C $(LIBFT_DIR) fclean --no-print-directory
	@$(MAKE) -C $(FT_PRINTF_DIR) fclean --no-print-directory
	@echo "$(BOLD_GREEN)✅ Full clean completed.$(RESET)"

re: fclean all

.PHONY: all clean fclean re

# Cores #
GREEN = \033[0;32m
YELLOW = \033[0;33m
BLUE = \033[0;34m
BOLD_GREEN = \033[1;32m
BOLD_YELLOW = \033[1;33m
BOLD_BLUE = \033[1;34m
RESET = \033[0m
