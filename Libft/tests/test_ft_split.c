/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmayne-p <cmayne-p@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 17:53:24 by cmayne-p          #+#    #+#             */
/*   Updated: 2024/12/23 19:57:07 by cmayne-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "tests.h"

//TODO: frees bien hechos

int	test_ft_split(char const *s, char c, char **expected)
{
	char	**my_result;
	size_t	i;

	my_result = ft_split(s, c);
	if ((my_result && !expected) || (!my_result && expected))
		printf("FAIL: ft_split(%s, `%c`)\n", s, c);
	i = 0;
	while (my_result[i] != NULL)
	{
		if (strcmp(my_result[i], expected[i]) != 0)
		{
			printf("FAIL: ft_split(%s, `%c`)\n", s, c);
			printf("For i = %zu, my word is `%s` and the expected is `%s`\n", i, my_result[i], expected[i]);
			return (1);
		}
		i++;
	}
	return (0);
}

void	do_test_ft_split(void)
{
	int		err;
	char	*exp1[] = {"Hello", "world", NULL};
	char	*exp2[] = {"Hello there", NULL};
	char	*exp3[] = {"some", NULL};
	char	*exp4[] = {"", NULL};

	err = 0;
	err += test_ft_split("  Hello    world  ", ' ', exp1);
	err += test_ft_split("Hello there", '\0', exp2);
	err += test_ft_split("some", ' ', exp3);
	err += test_ft_split("", ' ', exp4);
	if (!err)
		printf("ft_split: Passed all tests!\n");
}
