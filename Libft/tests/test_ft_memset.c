/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_memset.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmayne-p <cmayne-p@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 20:25:07 by cmayne-p          #+#    #+#             */
/*   Updated: 2024/12/27 15:14:09 by cmayne-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"
#include "../libft.h"

int	test_ft_memset(void *ft_s, int c, size_t n, void *or_s)
{
	ft_memset(ft_s, c, n);
	memset(or_s, c, n);
	if (memcmp(ft_s, or_s, n) != 0)
	{
		printf("ft_memset FAILED\n");
		return (1);
	}
	return (0);
}

void	do_test_ft_memset(void)
{
	int		err;
	char	buffer1[10];
	char	buffer2[10];
	char	buffer3[10] = "12345";
	char	buffer4[10] = "12345";
	char	buffer5[] = "qwertyuiop";
	char	buffer6[] = "qwertyuiop";
	char	buffer7[] = "";
	char	buffer8[] = "";
	int		arr1[] = {1, 2, 3};
	int		arr2[] = {1, 2, 3};

	err = 0;
	err += test_ft_memset(buffer1, '7', 7, buffer2);
	err += test_ft_memset(buffer1, 5848464, 7, buffer2);
	err += test_ft_memset(buffer3, '7', 10, buffer4);
	err += test_ft_memset(buffer5, '\0', 3, buffer6);
	err += test_ft_memset(buffer7, '-', 10, buffer8);
	err += test_ft_memset(arr1, 42, 42, arr2);
	err += test_ft_memset(buffer1, '4', 0, buffer2);
	if (!err)
		printf("ft_memset: Passed all tests!\n");
}
