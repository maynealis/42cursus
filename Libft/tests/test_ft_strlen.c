/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strlen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmayne-p <cmayne-p@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 19:49:51 by cmayne-p          #+#    #+#             */
/*   Updated: 2024/12/25 20:23:16 by cmayne-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"
#include "../libft.h"

int	test_ft_strlen(const char *s)
{
	size_t	my_result;
	size_t	expected;

	my_result = ft_strlen(s);
	expected = strlen(s);
	if (my_result != expected)
	{
		printf("FAIL: ft_strlen(%s) => %zu (expected %zu)\n", s, my_result, expected);
		return (1);
	}
	return (0);
}

void	do_test_ft_strlen(void)
{
	int	err;

	err = 0;
	err += test_ft_strlen("Hello world!");
	err += test_ft_strlen("");
	err += test_ft_strlen("                 ");
	err += test_ft_strlen("♫♪.ılılıll|̲̅̅●̲̅̅|̲̅̅=̲̅̅|̲̅̅●̲̅̅|llılılı.♫♪");
	err += test_ft_strlen("what is gonna happen now \0 do you read me?");
	err += test_ft_strlen("and with this \\0? haha");
	if (!err)
		printf("ft_strlen: Passed all tests!\n");
}
