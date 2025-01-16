/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmayne-p <cmayne-p@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 11:50:36 by cmayne-p          #+#    #+#             */
/*   Updated: 2025/01/16 11:57:35 by cmayne-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"
#include "../libft.h"

int	main(void)
{
	printf("-----PART 1 -----\n");
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
	printf("-----PART 2 -----\n");
	do_test_ft_substr();
	do_test_ft_strjoin();
	do_test_ft_strtrim();
	do_test_ft_split();
	do_test_ft_itoa();
	do_test_ft_strmapi();
	do_test_ft_striteri();
	tests_fd();
	printf("----- BONUS -----\n");
	do_test_ft_lstmap();

	char **arr = ft_split("Hello  world", ' ');
	printf("arr[0]: %s\n", arr[0]);
	printf("arr[1]: %s\n", arr[1]);
	return (0);
}
