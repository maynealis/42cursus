/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_memchr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmayne-p <cmayne-p@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 15:31:22 by cmayne-p          #+#    #+#             */
/*   Updated: 2024/12/26 15:40:33 by cmayne-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"
#include "../libft.h"

int	test_ft_memchr(const void *s, int c, size_t n)
{
	if (ft_memchr(s, c, n) != memchr(s, c, n))
	{
		printf("FAIL: ft_memchr\n");
		return (1);
	}
	return (0);
}

void	do_test_ft_memchr(void)
{
	int		err;
	char	s1[] = "Hello world!";
	char	s2[] = "";
	char	s3[] = "♪ ♫ ♬ ♩ ♪ ♬ ♫ ♪";
	int		s4[] = {1, 4, 42};

	err = 0;
	err += test_ft_memchr(s1, ' ', 12);
	err += test_ft_memchr(s1, ' ', 4);
	err += test_ft_memchr(s1, 45828, 4);
	err += test_ft_memchr(s1, 'u', 12);
	err += test_ft_memchr(s2, ' ', 12);
	err += test_ft_memchr(s3, ' ', 12);
	err += test_ft_memchr(s3, 569899, 12);
	err += test_ft_memchr(s3, 185, 12);
	err += test_ft_memchr(s4, 42, 3);
	err += test_ft_memchr(s4, 4290, 3);
	if (!err)
		printf("ft_memchr: Passed all tests!\n");
}
