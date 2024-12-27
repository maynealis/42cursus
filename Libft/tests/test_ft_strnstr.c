/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strnstr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmayne-p <cmayne-p@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 11:19:27 by cmayne-p          #+#    #+#             */
/*   Updated: 2024/12/27 11:55:30 by cmayne-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"
#include "../libft.h"

int	test_ft_strnstr(const char *big, const char *little, size_t len, char *expected)
{
	char	*my_result;

	my_result = ft_strnstr(big, little, len);
	if	((my_result && !expected) || (!my_result && expected)
		|| (my_result && strcmp(my_result, expected) != 0))
	{
		printf("FAIL: ft_strnstr(%s, %s, %zu) => %s (expected: %s)", big, little, len, my_result, expected);
		return (1);
	}
	return (0);		
}

void	do_test_ft_strnstr(void)
{
	int			err;
	const char	*largestring = "Foo Bar Bar";
	const char	*smallstring = "Bar";
	
	err = 0;
	err += test_ft_strnstr(largestring, smallstring, 12, "Bar Bar");
	err += test_ft_strnstr(largestring, smallstring, 8, "Bar Bar");
	err += test_ft_strnstr(largestring, smallstring, 5, NULL);
	err += test_ft_strnstr(largestring, smallstring, 4, NULL);
	err += test_ft_strnstr(largestring, "", 1, "Foo Bar Bar");
	if (!err)
		printf("ft_strnstr: Passed all tests!\n");
}
