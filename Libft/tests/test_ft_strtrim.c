/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strtrim.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmayne-p <cmayne-p@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 10:38:40 by cmayne-p          #+#    #+#             */
/*   Updated: 2024/12/23 11:27:11 by cmayne-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"
#include "../libft.h"

int	test_ft_strtrim(char const *s1, char const *set, char *expected)
{
	char *my_result;

	my_result = ft_strtrim(s1, set);
	if ((my_result && !expected) || (!my_result && expected) 
		|| (my_result && strcmp(my_result, expected) != 0))
	{
		printf("FAIL: ft_strtrim(`%s`, `%s`) => `%s` (expected: `%s`)\n", s1, set, my_result, expected);
		if (my_result)
			free(my_result);
		return (1);
	}
	if (my_result)
		free(my_result);
	return (0);
}

void	do_test_ft_strtrim(void)
{
	int	err;

	err = 0;
	err += test_ft_strtrim("   Hello, world!    ", " ", "Hello, world!");
	err += test_ft_strtrim(" ++ * Hello + world!  *  ", "+* ", "Hello + world!");
	err += test_ft_strtrim("Hello, world!", " ", "Hello, world!");
	err += test_ft_strtrim("+++++Hello, world!", "+", "Hello, world!");
	err += test_ft_strtrim("Hello, world!+++", "+", "Hello, world!");
	err += test_ft_strtrim("++++", "+", "");
	err += test_ft_strtrim("+++++", "+", "");
	err += test_ft_strtrim("something", " ", "something");
	err += test_ft_strtrim(" ", " ", "");
	err += test_ft_strtrim("", "+", "");
	err += test_ft_strtrim(NULL, " ", NULL);
	err += test_ft_strtrim(" ", NULL, NULL);
	err += test_ft_strtrim(NULL, NULL, NULL);
	if (!err)
		printf("ft_strtrim: Passed all tests!\n");
}
