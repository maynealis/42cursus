# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmayne-p <cmayne-p@student.42barcelon      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/18 12:49:10 by cmayne-p          #+#    #+#              #
#    Updated: 2024/12/18 13:33:50 by cmayne-p         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra -Iincludes

NAME = ft_display_file

INCLUDES = $(wildcard includes/*.h)
SRCS = src/ft_putstr.c src/ft_display_file.c src/ft_read_file.c
OBJS = $(SRCS:.c=.o)

%.o : %.c $(INCLUDES)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

all : $(NAME)

clean : 
	rm -rf $(OBJS)

fclean : clean 
	rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re
