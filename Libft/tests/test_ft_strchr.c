/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strchr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmayne-p <cmayne-p@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 13:17:34 by cmayne-p          #+#    #+#             */
/*   Updated: 2024/12/26 13:26:08 by cmayne-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"
#include "../libft.h"

int	test_ft_strchr(const char *s, int c)
{
	if (ft_strchr(s, c) != strchr(s, c))
	{
		printf("FAIL: ft_strchr.\n");
		return (1);
	}
	return (0);
}

void	do_test_ft_strchr(void)
{
	int		err;
	char	src1[] = "Hello world!";
	char	src2[] = "";

	err = 0;
	err += test_ft_strchr(src1, 'c');
	err += test_ft_strchr(src1, 'o');
	err += test_ft_strchr(src1, '\0');
	err += test_ft_strchr(src1, 123456);
	err += test_ft_strchr(src2, 'u');
	if (!err)
		printf("ft_strchr: Passed all tests!\n");
}
