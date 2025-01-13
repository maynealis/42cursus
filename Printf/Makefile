# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmayne-p <cmayne-p@student.42barcelon      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/12 19:09:37 by cmayne-p          #+#    #+#              #
#    Updated: 2025/01/13 18:26:17 by cmayne-p         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Werror -Wextra -g #TODO: quitar el flag para debugar

LIBFT = libft/libft.a

INCLUDES = 

all: $(NAME)

%.o: %.c Makefile
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(LIBFT)
	$(CC) $(CFLAGS) -o test.out
