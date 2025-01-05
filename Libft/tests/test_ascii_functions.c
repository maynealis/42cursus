/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ascii_functions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmayne-p <cmayne-p@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 19:25:43 by cmayne-p          #+#    #+#             */
/*   Updated: 2025/01/05 11:22:30 by cmayne-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"
#include "../libft.h"

int	show_error(char *name_ft, int input, int lib_val, int ori_val)
{
	printf("There is an error in `%s`.\n", name_ft);
	printf("The result of %c on your library is %d\n", input, lib_val);
	printf("and the correct result of %c on the standard library is %d\n", input, ori_val);
	printf("--------------------------------------------------------\n");
 	return (1);
} 

void	do_test_ascii_functions(void)
{
	int	err_isalpha = 0;
	int	err_isdigit = 0;
	int	err_isalnum = 0;
	int	err_isascii = 0;
	int	err_isprint = 0;
	int	err_toupper = 0;
	int	err_tolower = 0;
	int i = -2;
	while (++i < 258)
	{
		if ((ft_isalpha(i) && !isalpha(i)) || (!ft_isalpha(i) && isalpha(i)))
			err_isalpha += show_error("ft_isalpha", i, ft_isalpha(i), isalpha(i));
		if ((ft_isdigit(i) && !isdigit(i)) || (!ft_isdigit(i) && isdigit(i)))
			err_isdigit += show_error("ft_isdigit", i, ft_isdigit(i), isdigit(i));
		if ((ft_isalnum(i) && !isalnum(i)) || (!ft_isalnum(i) && isalnum(i)))
			err_isalnum += show_error("ft_isalnum", i, ft_isalnum(i), isalnum(i));
		if ((ft_isascii(i) && !isascii(i)) || (!ft_isascii(i) && isascii(i)))
			err_isascii += show_error("ft_isascii", i, ft_isascii(i), isascii(i));
		if ((ft_isprint(i) && !isprint(i)) || (!ft_isprint(i) && isprint(i)))
			err_isprint += show_error("ft_isprint", i, ft_isprint(i), isprint(i));
		if (ft_toupper(i) != toupper(i))
			err_toupper += show_error("ft_toupper", i, ft_toupper(i), toupper(i));
		if (ft_tolower(i) != tolower(i))
			err_tolower += show_error("ft_tolower", i, ft_tolower(i), tolower(i));
	}
	if (!err_isalpha)
		printf("ft_isalpha: Passed all tests!\n");
	if (!err_isdigit)
		printf("ft_isdigit: Passed all tests!\n");
	if (!err_isalnum)
		printf("ft_isalnum: Passed all tests!\n");
	if (!err_isascii)
		printf("ft_isascii: Passed all tests!\n");
	if (!err_isprint)
		printf("ft_isprint: Passed all tests!\n");
	if (!err_toupper)
		printf("ft_toupper: Passed all tests!\n");
	if (!err_tolower)
		printf("ft_tolower: Passed all tests!\n");
}
