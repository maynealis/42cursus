# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmayne-p <cmayne-p@student.42barcelon      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/22 11:58:31 by cmayne-p          #+#    #+#              #
#    Updated: 2025/01/12 20:28:18 by cmayne-p         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra -g

LIBFT = ../libft.a

INCLUDES = tests.h ../libft.h
SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)

EXEC = tests

all: $(EXEC)

$(LIBFT):
	$(MAKE) -C ../
	$(MAKE) bonus -C ../

$(EXEC): $(OBJS) | $(LIBFT)
	$(CC) $(CFLAGS) -o $(EXEC) $(OBJS) -L. $(LIBFT)

%.o: %.c $(INCLUDES)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -f $(EXEC)

re: fclean all
	

