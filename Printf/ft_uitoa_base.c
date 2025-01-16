/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmayne-p <cmayne-p@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 11:20:33 by cmayne-p          #+#    #+#             */
/*   Updated: 2025/01/16 14:21:53 by cmayne-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_numlen(unsigned long n, char *base)
{
	size_t	len_base;
	int		len;

	if (n == 0)
		return (1);
	len_base = ft_strlen(base);
	len = 0;
	while (n != 0)
	{
		n /= len_base;
		len++;
	}
	return (len);
}

char	*ft_uitoa_base(unsigned int n, char *base)
{
	char	*result;
	size_t	len_base;
	int		len_n;

	len_base = ft_strlen(base);
	len_n = ft_numlen(n, base);
	result = (char *)malloc((len_n + 1) * sizeof(char));
	//TODO: protect malloc
	result[len_n] = '\0';
	while (n > 0)
	{
		result[--len_n] = base[n % len_base];
		n /= len_base;
	}
	return (result);
}

char	*ft_ultoa_base(unsigned long n, char *base)
{
	char	*result;
	size_t	len_base;
	int		len_n;

	len_base = ft_strlen(base);
	len_n = ft_numlen(n, base);
	result = (char *)malloc((len_n + 1) * sizeof(char));
//	TODO: protect mallloc	
	result[len_n] = '\0';
	while (n > 0)
	{
		result[--len_n] = base[n % len_base];
		n /= len_base;
	}
	return (result);
}
