/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_calloc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmayne-p <cmayne-p@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 12:13:08 by cmayne-p          #+#    #+#             */
/*   Updated: 2024/12/27 12:22:34 by cmayne-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"
#include "../libft.h"

int	test_ft_calloc(size_t nmemb, size_t size)
{
	void	*my_result;
	void	*original;

	my_result = ft_calloc(nmemb, size);
	original = calloc(nmemb, size);
	if ((my_result && !original) || (!my_result && original)
		|| (my_result && original && memcmp(my_result, original, nmemb * size) != 0))
	{
		printf("FAIL: ft_calloc with nmemb=%zu and size %zu", nmemb, size);
		free(my_result);
		free(original);
		return (1);
	}
	free(my_result);
	free(original);
	return (0);
}

void	do_test_ft_calloc(void)
{
	int	err;

	err = 0;
	err += test_ft_calloc(4, 168);
	err += test_ft_calloc(0, 168);
	err += test_ft_calloc(4, 0);
	err += test_ft_calloc(0, 0);
	if (!err)
		printf("ft_calloc: Passed all tests!\n");
}
