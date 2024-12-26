/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_memcmp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmayne-p <cmayne-p@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 15:41:02 by cmayne-p          #+#    #+#             */
/*   Updated: 2024/12/26 15:47:08 by cmayne-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"
#include "../libft.h"

int	test_ft_memcmp(const void *s1, const void *s2, size_t n)
{
	if (ft_memcmp(s1, s2, n) != memcmp(s1, s2, n))
	{
		printf("FAIL: ft_memcmp\n");
		return (1);
	}
	return (0);
}

void	do_test_ft_memcmp(void)
{
	int		err;
	int 	s1[] = {1, 2, 3, 4, 5};
	int 	s2[] = {1, 2, 3, 5555, 5};
	int 	s3[] = {1, 2, 3, 4, 5};
	char	s4[] = "Hello there";
	char	s5[] = "Hello world!";

	err = 0;
	err += test_ft_memcmp(s1, s2, 2);
	err += test_ft_memcmp(s1, s2, 5);
	err += test_ft_memcmp(s1, s2, 20);
	err += test_ft_memcmp(s1, s2, 200);
	err += test_ft_memcmp(s1, s3, 5);
	err += test_ft_memcmp(s4, s5, 5);
	err += test_ft_memcmp(s4, s5, 10);
	err += test_ft_memcmp(s4, s5, 180);
	if (!err)
		printf("ft_memcmp: Passed all tests!\n");
}
