/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strncmp.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmayne-p <cmayne-p@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 14:51:50 by cmayne-p          #+#    #+#             */
/*   Updated: 2024/12/26 15:10:23 by cmayne-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"
#include "../libft.h"

int	test_ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (ft_strncmp(s1, s2, n) != strncmp(s1, s2, n))
	{
		printf("FAIL: ft_strncmp\n");
		return (1);
	}
	return (0);
}

void	do_test_ft_strncmp(void)
{
	int		err;
	char	s1[] = "Hello world!";
	char	s2[] = "Hello world!";
	char	s3[] = "Hello there";
	char	s4[] = "";
	char	s5[] = "";
	char	s6[] = "Hello";
	char	s7[] = "lorem ipsum dolor sit amet";
	char	s8[] = "ipsumm";

	err = 0;
	err += test_ft_strncmp(s1, s2, 13);
	err += test_ft_strncmp(s1, s3, 5);
	err += test_ft_strncmp(s1, s3, 10);
	err += test_ft_strncmp(s1, s4, 13);
	err += test_ft_strncmp(s4, s5, 13);
	err += test_ft_strncmp(s4, s5, 1);
	err += test_ft_strncmp(s1, s6, 10);
	err += test_ft_strncmp(s7, s8, 30);
	if (!err)
		printf("ft_strncmp: Passed all tests!\n");
}
