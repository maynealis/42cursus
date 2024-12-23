/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_striteri.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmayne-p <cmayne-p@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 21:23:58 by cmayne-p          #+#    #+#             */
/*   Updated: 2024/12/23 21:42:49 by cmayne-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"
#include "../libft.h"

static void	ft_odd_toupper(unsigned int i, char *c)
{
	if (i % 2 == 1)
		*c = (char)ft_toupper(*c);
}

int	test_ft_striteri(char *s, char *expected)
{
	ft_striteri(s, ft_odd_toupper);
	if (strcmp(s, expected) != 0)
	{
		printf("FAIL: ft_striteri with the function custom toupper.\n");
		printf("My result is %s, and the expected is %s", s, expected);
		return (1);
	}
	return (0);
}

void	do_test_ft_striteri(void)
{
	int		err;
	char	test1[] = "abcdE";
	char	test2[] = "abcdE .a!";

	err = 0;
	err += test_ft_striteri(test1, "aBcDE");
	err += test_ft_striteri(test2, "aBcDE .A!");
	if (!err)
		printf("ft_striteri: Passed all tests!\n");
}
