/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmayne-p <cmayne-p@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 21:29:05 by cmayne-p          #+#    #+#             */
/*   Updated: 2024/12/21 15:21:12 by cmayne-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	size_t	size;
	size_t	i;
	char	sign;
	int		result;

	result = 0;
	size = ft_strlen(nptr);
	i = 0;
	while (ft_isspace(nptr[i]))
		i++;
	sign = 1;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		sign += -2 * (nptr[i] == '-');
		i++;
	}
	while (ft_isdigit(nptr[i]) && i < size)
	{
		result = result * 10 + (nptr[i] - '0');
		i++;
	}
	return (result * sign);
}
