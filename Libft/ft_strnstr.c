/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmayne-p <cmayne-p@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 21:03:29 by cmayne-p          #+#    #+#             */
/*   Updated: 2024/12/27 11:59:41 by cmayne-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t		i;
	size_t		j;
	size_t		size_little;
	char		*big_str;

	big_str = (char *) big;
	size_little = ft_strlen(little);
	if (*little == '\0')
		return ((char *)big);
	i = 0;
	j = 0;
	while (i < len && big[i] != '\0')
	{
		if (big[i + j] == little[j])
		{
			while (j < size_little && big[i + j] == little[j] && i + j < len)
				j++;
			if (j == size_little)
				return (&big_str[i]);
		}
		i++;
	}
	return (NULL);
}
