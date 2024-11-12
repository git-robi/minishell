# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rgiambon <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/28 10:47:59 by rgiambon          #+#    #+#              #
#    Updated: 2024/10/28 10:50:28 by rgiambon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = src/main.c  src/mini_loop.c  src/lexer/lexer.c src/lexer/list_utils_lexer.c src/lexer/quotes.c src/utils/strarr_utils.c  src/utils/str_utils.c src/utils/free_memory.c src/parser/parser.c src/parser/list_utils_parser.c src/parser/parser_utils.c 
OBJS = $(SRCS:.c=.o)
HEADER = includes/strarr_utils.h includes/str_utils.h includes/mini.h includes/parser.h includes/lexer.h includes/utils.c

all: $(NAME)

$(NAME): $(OBJS) 
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L libft -lft
	chmod +x $(NAME)

%.o: %.c Makefile $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.SILENT: 

.PHONY: all clean fclean re
