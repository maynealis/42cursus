/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_memmove.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmayne-p <cmayne-p@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 12:17:36 by cmayne-p          #+#    #+#             */
/*   Updated: 2024/12/26 12:52:35 by cmayne-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"
#include "../libft.h"

int	test_ft_memmove(void *ft_dest, const void *src, size_t n, void *or_dest)
{
	ft_memmove(ft_dest, src, n);
	memmove(or_dest, src, n);
	if (memcmp(ft_dest, or_dest, n) != 0)
	{
		printf("ft_memmove FAILED\n");
		return (1);
	}
	return (0);
}

void	do_test_ft_memmove(void)
{
	int			err;
	const char	src1[] = "Hello world!";
	const char	src2[] = "";
	char		dest1[20];
	char		dest2[20];
	char		buffer1[20] = "Hello world!";
	char		buffer2[20] = "Hello world!";
	char		*dest3 = buffer1 + 2;
	char		*dest4 = buffer2 + 2;
	char		*dest5 = buffer1 - 2;
	char		*dest6 = buffer2 - 2;

	err = 0;
	err += test_ft_memmove(dest1, src1, 5, dest2);
	err += test_ft_memmove(dest1, src1, 12, dest2);
	err += test_ft_memmove(dest1, src1, 0, dest2);
	err += test_ft_memmove(dest1, src2, 1, dest2);
	err += test_ft_memmove(dest1, src2, 0, dest2);
	err += test_ft_memmove(dest3, buffer1, 12, dest4);
	err += test_ft_memmove(dest5, buffer1, 12, dest6);
	if (!err)
		printf("ft_memmove: Passed all tests!\n");
}
