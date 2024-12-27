/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_atoi.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmayne-p <cmayne-p@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 12:02:17 by cmayne-p          #+#    #+#             */
/*   Updated: 2024/12/27 12:09:51 by cmayne-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"
#include "../libft.h"

int	test_ft_atoi(const char *nptr)
{
	int	my_result;
	int	original;

	my_result = ft_atoi(nptr);
	original = atoi(nptr);
	if (my_result != original)
	{
		printf("FAIL: ft_atoi(%s) => %d (expected: %d)\n", nptr, my_result, original);
		return (1);
	}
	return (0);
}

void	do_test_ft_atoi(void)
{
	int	err;

	err = 0;
	err += test_ft_atoi("0");
	err += test_ft_atoi("    -87a");
	err += test_ft_atoi("2147483648");
	err += test_ft_atoi("-2147483648");
	err += test_ft_atoi("-=147483648");
	err += test_ft_atoi("   8*  dh");
	err += test_ft_atoi("  - asdfa 89");
	if (!err)
		printf("ft_atoi: Passed all tests!\n");
}
