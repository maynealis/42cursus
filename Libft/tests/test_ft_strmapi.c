/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strmapi.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmayne-p <cmayne-p@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 20:42:17 by cmayne-p          #+#    #+#             */
/*   Updated: 2024/12/23 21:14:31 by cmayne-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"
#include "../libft.h"

static char ft_odd_toupper(unsigned int i, char c)
{
	if (i % 2 == 1)
		return (char)ft_toupper(c);
	return (c);
}

int	test_ft_strmapi(char const *s, char *expected)
{
	char *my_result;

	my_result = ft_strmapi(s, ft_odd_toupper);
	if ((my_result && !expected) || (!my_result && expected)
		|| (my_result && strcmp(my_result, expected) != 0))
	{
		printf("FAIL: ft_strmapi with the function upper.\n");
		printf("My result: %s, and the expeted: %s\n", my_result, expected);
		free(my_result);
		return (1);
	}
	free(my_result);
	return (0);
}

void	do_test_ft_strmapi(void)
{
	int	err;

	err = 0;
	err += test_ft_strmapi("abcdE", "aBcDE");
	err += test_ft_strmapi("abcdE .a!", "aBcDE .A!");
	if (!err)
		printf("ft_strmapi: Passed all tests!\n");
}
