/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_substr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmayne-p <cmayne-p@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 17:08:23 by cmayne-p          #+#    #+#             */
/*   Updated: 2024/12/22 13:20:48 by cmayne-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"
#include "../libft.h"

int	test_ft_substr(char const *s, unsigned int start, size_t len, char *expected)
{
	char	*my;

	my = ft_substr(s, start, len);
	if ((my == NULL && expected != NULL) || (my != NULL && expected == NULL)
		|| (my && strcmp(my, expected) != 0))
	{
		printf("FAIL: ft_substr(%s, %u, %zu) => %s (expected: %s)\n", s, start, len, my, expected);
		free(my);
		return (1);
	}
	free(my);
	return (0);
}

void	do_test_ft_substr(void)
{
	int	err_count;

	err_count = 0;
	err_count += test_ft_substr("Hello world!", 6, 5, "world");
	err_count += test_ft_substr("Hello", 10, 5, "");
	err_count += test_ft_substr("Hello", 2, 10, "llo");
	err_count += test_ft_substr("", 0, 5, "");
	err_count += test_ft_substr("Hello", 2, 0, "");
	err_count += test_ft_substr(NULL, 0, 10, NULL);
	if (!err_count)
		printf("ft_substr: Passed all tests!\n");
}
