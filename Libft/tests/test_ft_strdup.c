/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strdup.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmayne-p <cmayne-p@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 12:24:31 by cmayne-p          #+#    #+#             */
/*   Updated: 2024/12/27 12:32:21 by cmayne-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"
#include "../libft.h"

int	test_ft_strdup(const char *s)
{
	char	*my_result;
	char	*original;

	my_result = ft_strdup(s);
	original = strdup(s);
	if ((my_result && !original) || (!my_result && original)
		|| (my_result && original && strcmp(my_result, original) != 0))
	{
		printf("FAIL: ft_strdup(%s) => %s (expected: %s)", s, my_result, original);
		free(my_result);
		free(original);
		return (1);
	}
	free(my_result);
	free(original);
	return (0);
}

void	do_test_ft_strdup(void)
{
	int	err;

	err = 0;
	err += test_ft_strdup("Hello world!");
	err += test_ft_strdup("");
	err += test_ft_strdup("Hello   adufad #@ adsfi7879854world!");
	if (!err)
		printf("ft_strdup: Passed all tests!\n");
}
