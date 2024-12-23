/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_itoa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmayne-p <cmayne-p@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 20:02:35 by cmayne-p          #+#    #+#             */
/*   Updated: 2024/12/23 20:08:30 by cmayne-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "tests.h"

int	test_ft_itoa(int n, char *expected)
{
	char	*my_result;

	my_result = ft_itoa(n);
	if ((my_result && !expected) || (!my_result && expected)
		|| (my_result && strcmp(my_result, expected) != 0))
	{
		printf("FAIL: ft_itoa(%d) => %s (expected: %s)\n", n, my_result, expected);
		return (1);
	}
	return (0);
}

void	do_test_ft_itoa(void)
{
	int	err;

	err = 0;
	err += test_ft_itoa(0, "0");
	err += test_ft_itoa(-0, "0");
	err += test_ft_itoa(8956, "8956");
	err += test_ft_itoa(-9024150, "-9024150");
	err += test_ft_itoa(2147483647, "2147483647");
	err += test_ft_itoa(-2147483648, "-2147483648");
	if (!err)
		printf("ft_itoa: Passed all tests!\n");
}
