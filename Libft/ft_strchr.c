/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmayne-p <cmayne-p@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 16:54:36 by cmayne-p          #+#    #+#             */
/*   Updated: 2024/12/20 17:16:52 by cmayne-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//El casteo a unsigned char es para coger el bit menos significativo?
char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	size_t	size;
	char	*str;
	
	str = (char *)s;
	size = ft_strlen(s);
	i = 0;
	while (i <= size)
	{
		if (s[i] == (unsigned char)c)
			return (&str[i]);
		i++;
	}
	return (NULL);
}
