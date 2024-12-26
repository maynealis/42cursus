/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strrchr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmayne-p <cmayne-p@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 13:27:38 by cmayne-p          #+#    #+#             */
/*   Updated: 2024/12/26 13:32:54 by cmayne-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"
#include "../libft.h"

int	test_ft_strrchr(const char *s, int c)
{
	if (ft_strrchr(s, c) != strrchr(s, c))
	{
		printf("FAIL: ft_strrchr.\n");
		return (1);
	}
	return (0);
}

void	do_test_ft_strrchr(void)
{
	int	err;
	char	src1[] = "Hello world!";
	char	src2[] = "";

	err = 0;
	err += test_ft_strrchr(src1, 'o');
	err += test_ft_strrchr(src1, '\0');
	err += test_ft_strrchr(src1, 'e');
	err += test_ft_strrchr(src1, 'u');
	err += test_ft_strrchr(src2, '\0');
	err += test_ft_strrchr(src2, 'e');
	err += test_ft_strrchr(src1, 123456);
	err += test_ft_strrchr(src2, -1237845);
	if (!err)
		printf("ft_strrchr: Passed all tests!\n");
}
