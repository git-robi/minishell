# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rgiambon <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/28 10:47:59 by rgiambon          #+#    #+#              #
#    Updated: 2024/11/14 10:04:13 by rgiambon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
CC = cc
CFLAGS = -Wall -Wextra -Werror #-g -fsanitize=address
SRCS = src/main.c src/mini_loop.c  src/lexer/lexer.c src/lexer/store_tokens.c src/lexer/list_utils_lexer.c src/lexer/quotes.c src/utils/strarr_utils.c  src/utils/str_utils.c src/utils/free_memory.c src/parser/parser.c src/parser/list_utils_parser.c src/parser/parser_utils.c 
OBJS = $(SRCS:.c=.o)
HEADER = includes/strarr_utils.h includes/str_utils.h includes/mini.h includes/parser.h includes/lexer.h includes/utils.c

LIBFT_DIR = libs/libft
LIBFT = $(LIBFT_DIR)/libft.a

# READLINE_DIR = libs/readline
READLINE_DIR = libs/readline_linux_1
READLINE_LIBS = $(READLINE_DIR)/lib/libreadline.a $(READLINE_DIR)/lib/libhistory.a
READLINE_INCLUDE = $(READLINE_DIR)/include

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L $(LIBFT_DIR) -lft $(READLINE_LIBS) -lncurses
	chmod +x $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

%.o: %.c Makefile $(HEADER)
	$(CC) $(CFLAGS) -I $(READLINE_INCLUDE) -c $< -o $@

clean:
	rm -f $(OBJS)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.SILENT: 

.PHONY: all clean fclean re
