/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_substr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmayne-p <cmayne-p@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 17:08:23 by cmayne-p          #+#    #+#             */
/*   Updated: 2024/12/21 19:10:42 by cmayne-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "" // header para tests
#include <string.h> // strcmp
#include <stdio.h> // printf

void	test_ft_substr(char const *s, unsigned int start, size_t len, char *expected)
{
	char	*my;

	my = ft_substr(s, start, len);
	if (my == NULL && expected != NULL || my != NULL && expected == NULL ||
		(my && strcmp(my, expected) != 0))
	{
		printf("FAIL: ft_substr(%s, %u, %zu) => %s (expected: %s)\n", s, start, len, my, expected);
	}
	free(my);
}

void	do_test_ft_substr()
{
	test_ft_substr("Hello world!", 6, 5, "world");
	test_ft_substr("Hello", 10, 5, "");
	test_ft_substr("Hello", 2, 10, "llo");
	test_ft_substr("", 0, 5, "");
	test_ft_substr(NULL)// TODO
}
