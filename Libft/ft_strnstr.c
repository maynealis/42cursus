/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmayne-p <cmayne-p@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 21:03:29 by cmayne-p          #+#    #+#             */
/*   Updated: 2024/12/20 21:22:50 by cmayne-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t		i;
	size_t		size_little;
	char		*big_str;
	const char	*empty_str;

	empty_str = "";
	big_str = (char *) big;
	size_little = ft_strlen(little);
	if (little == empty_str)
		return ((char *)big);
	i = 0;
	while (i < len && big[i] != '\0')
	{
		if (ft_strncmp(big, little, size_little) == 0)
			return (&big_str[i]);
		i++;
	}
	return (NULL);
}
