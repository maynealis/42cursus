/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmayne-p <cmayne-p@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 11:50:36 by cmayne-p          #+#    #+#             */
/*   Updated: 2025/01/04 13:43:41 by cmayne-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

int	main(void)
{
	do_test_ascii_functions();
	do_test_ft_strlen();
	do_test_ft_memset();
	do_test_ft_bzero();
	do_test_ft_memcpy();
	do_test_ft_memmove();
	do_test_ft_strchr();
	do_test_ft_strrchr();
	do_test_ft_strncmp();
	do_test_ft_memchr();
	do_test_ft_memcmp();
	do_test_ft_strnstr();
	do_test_ft_atoi();
	do_test_ft_calloc();
	do_test_ft_strdup();
	do_test_ft_substr();
//	do_test_ft_strjoin();
	do_test_ft_strtrim();
	do_test_ft_split();
	do_test_ft_itoa();
	do_test_ft_strmapi();
	do_test_ft_striteri();
	tests_fd();
	printf("\n0b1: %d\n", 0x80000000);
	return (0);
}
