/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_memcpy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmayne-p <cmayne-p@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 11:51:24 by cmayne-p          #+#    #+#             */
/*   Updated: 2025/01/05 11:57:25 by cmayne-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"
#include "../libft.h"

int	test_ft_memcpy(void *ft_dest, const void *src, size_t n, void *or_dest)
{
	ft_memcpy(ft_dest, src, n);
	memcpy(or_dest, src, n);
	if (memcmp(ft_dest, or_dest, n) != 0)
	{
		printf("ft_memcpy FAILED\n");
		return (1);
	}
	return (0);
}

void	do_test_ft_memcpy(void)
{
	int			err;
	const char	src1[] = "Hello world!";
	const char	src2[] = "";
	char		dest1[20];
	char		dest2[20];
	char		*null = NULL;
	
	err = 0;
	err += test_ft_memcpy(dest1, src1, 5, dest2);
	err += test_ft_memcpy(dest1, src1, 12, dest2);
	err += test_ft_memcpy(dest1, src1, 0, dest2);
	err += test_ft_memcpy(dest1, src2, 1, dest2);
	err += test_ft_memcpy(dest1, src2, 0, dest2);
	err += test_ft_memcpy(null, null, 0, null);
	if (!err)
		printf("ft_memcpy: Passed all tests!\n");
}
