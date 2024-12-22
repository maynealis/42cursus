/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strjoin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmayne-p <cmayne-p@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 13:36:48 by cmayne-p          #+#    #+#             */
/*   Updated: 2024/12/22 13:54:07 by cmayne-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"
#include "../libft.h"

int	test_ft_strjoin(char const *s1, char const *s2, char *expected)
{
	char	*my_result;

	my_result = ft_strjoin(s1, s2);
	if (strcmp(my_result, expected) != 0)
	{
		printf("FAIL: ft_strjoin(%s, %s) => %s (expected: %s)\n", s1, s2, my_result, expected);
		free(my_result);
		return (1);
	}
	free(my_result);
	return (0);
}

void	do_test_ft_strjoin(void)
{
	int	err_count;

	err_count = 0;
	err_count += test_ft_strjoin("Hello ", "world!", "Hello world!");
	err_count += test_ft_strjoin("", "", "");
	err_count += test_ft_strjoin("", "some", "some");
	err_count += test_ft_strjoin("  ", "", "  ");
	if (!err_count)
		printf("ft_strjoin: Passed all tests!\n");
}
