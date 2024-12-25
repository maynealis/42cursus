/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_bzero.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmayne-p <cmayne-p@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 21:05:51 by cmayne-p          #+#    #+#             */
/*   Updated: 2024/12/25 21:38:48 by cmayne-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"
#include "../libft.h"

int	test_ft_bzero(void *ft_s, size_t n, void *or_s)
{
	ft_bzero(ft_s, n);
	bzero(or_s, n);
	if (memcmp(ft_s, or_s, n) != 0)
	{
		printf("ft_bzero FAILED\n");
		return (1);
	}
	return (0);
}

void	do_test_ft_bzero(void)
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
	err += test_ft_bzero(buffer1, 12, buffer2);
	err += test_ft_bzero(buffer3, 5, buffer4);
	err += test_ft_bzero(buffer5, 5, buffer6);
	err += test_ft_bzero(buffer7, 12, buffer8);
	err += test_ft_bzero(arr1, 3, arr2);
	if (!err)
		printf("ft_bzero: Passed all tests!\n");
}
