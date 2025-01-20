# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmayne-p <cmayne-p@student.42barcelon      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/12 19:09:37 by cmayne-p          #+#    #+#              #
#    Updated: 2025/01/17 14:05:43 by cmayne-p         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

INCLUDES_DIR = includes
LIBFT_DIR = libft

CC = cc
CFLAGS = -Wall -Werror -Wextra -I$(INCLUDES_DIR) #TODO: quitar el flag para debugar

LIBFT = $(LIBFT_DIR)/libft.a

INCLUDES = $(INCLUDES_DIR)/ft_printf.h $(INCLUDES_DIR)/ft_utils.h $(INCLUDES_DIR)/libft.h $(INCLUDES_DIR)/ft_printf_bonus.h

SRCS = ft_printf.c write_conversions.c utils.c

OBJS = $(SRCS:.c=.o)

OBJS_LIBFT = $(wildcard $(LIBFT_DIR)/*.o)

# OBJS_LIBFT = $(LIBFT_DIR)/ft_itoa.o \
# 			$(LIBFT_DIR)/ft_putchar_fd.o \
# 			$(LIBFT_DIR)/ft_putstr_fd.o \
# 			$(LIBFT_DIR)/ft_strjoin.o \
# 			$(LIBFT_DIR)/ft_strlen.o \
# 			$(LIBFT_DIR)/ft_bzero.o \
# 			$(LIBFT_DIR)/ft_strdup.o \
# 			$(LIBFT_DIR)/ft_strlcat.o \
# 			$(LIBFT_DIR)/ft_memset.o \
# 			$(LIBFT_DIR)/ft_isdigit.o

all: $(NAME)

$(OBJS_LIBFT):
	make -C $(LIBFT_DIR)

%.o: %.c $(INCLUDES) $(LIBFT)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(LIBFT) $(OBJS) Makefile $(OBJS_LIBFT)
	ar rcs $(NAME) $(OBJS) $(OBJS_LIBFT)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

clean:
	rm -rf $(OBJS)

fclean: clean bonus_clean
	rm -f $(NAME)
	$(MAKE) fclean -C $(LIBFT_DIR)

re: fclean all

# --------------- BONUS --------------------
SRCS_BONUS = ft_printf_bonus.c write_conversions_bonus.c utils.c

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

bonus: $(OBJS_BONUS) $(LIBFT) $(OBJS_LIBFT)
	ar rcs $(NAME) $(OBJS_BONUS) $(OBJS_LIBFT)

bonus_clean:
	rm -rf $(OBJS_BONUS)
# --------------------------------------------


norm:
	norminette $(SRCS) $(LIBFT_DIR) $(INCLUDES)

.PHONY: all clean fclean re norm bonus bonus_clean
