/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmayne-p <cmayne-p@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 15:42:53 by cmayne-p          #+#    #+#             */
/*   Updated: 2025/01/28 17:13:39 by cmayne-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf_bonus.h"

char	is_valid_integer(char *arg)
{
	size_t	len;
	size_t	i;

	if (!ft_isdigit(arg[0]) && arg[0] != '-' && arg[0] != '+')
		return (0);
	i = 1;
	len = ft_strlen(arg);
	while (i < len)
	{
		if (!ft_isdigit(arg[i]))
			return (0);
		i++;
	}
	if (ft_isdigit(arg[0]) && len >= 10)
	{
		if (len > 10 || ft_strncmp(arg, "2147483647", len) > 0)
			return (0);
	}
	else if (arg[0] == '-' && len >= 11)
	{
		if (len > 11 || ft_strncmp(arg, "-2147483648", len) > 0)
			return (0);	
	}
	return (1);
}

char	is_valid_argument(char *arg)
{
	char	is_valid;

	is_valid = is_valid_integer(arg);
	return (is_valid);
}
/*
char	check_arguments(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (ft_atoi(argv[i]) == 0) // TODO: also check for real 0
		i++;
	}
}
*/
int	main(int argc, char **argv)
{
	if (argc < 2)
		return (0);
	ft_printf("%i\n", is_valid_argument(argv[1]));
	
	return (0);
}
