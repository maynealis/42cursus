/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmayne-p <cmayne-p@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 12:12:30 by cmayne-p          #+#    #+#             */
/*   Updated: 2025/01/15 12:12:32 by cmayne-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	char	*str="Hello %s!\nand hello to you";

	// ft_putstr_fd(str, 0);
	// char *ini = ft_strchr(str, '%');
	// char *end = ft_strchr(ini, 's');
	// // printf("%ld", end - ini);
	// char c = ini[end - ini];
	// ft_putchar_fd('\n', 0);
	// ft_putchar_fd(c, 0);
	// printf("TEEEST\n");
	//ft_putnbr_fd(-1234,0);

	printf("ft_printf: %i", ft_printf(str));

	return (0);
}
