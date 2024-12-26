/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmayne-p <cmayne-p@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 16:58:31 by cmayne-p          #+#    #+#             */
/*   Updated: 2024/12/26 13:57:07 by cmayne-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	size_t	size;
	char	*str;

	str = (char *)s;
	size = ft_strlen(s);
	i = size;
	while (i >= 0)
	{
		if (s[i] == (unsigned char)c)
			return ((char *)&str[i]);
		if (i == 0)
			break ;
		i--;
	}
	return (NULL);
}
