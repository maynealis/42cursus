/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmayne-p <cmayne-p@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 12:03:37 by cmayne-p          #+#    #+#             */
/*   Updated: 2024/12/26 13:15:52 by cmayne-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*c_dest;
	unsigned char	*c_src;

	c_dest = (unsigned char *)dest;
	c_src = (unsigned char *)src;
	if (dest > src && dest < src + n)
	{
		i = n;
		while (i > 0)
		{
			i--;
			c_dest[i] = c_src[i];
		}
	}
	else // dest > src + n
	{
		i = 0;
		while (i < n)
		{
			c_dest[i] = c_src[i];
			i++;
		}
	}
	return (dest);
}
*/
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;
	unsigned char	*c_dest;
	unsigned char	*c_src;

	if (dest == NULL || src == NULL)
		return (dest);
	c_dest = (unsigned char *)dest;
	c_src = (unsigned char *)src;
	if (src < dest && dest < src + n)
	{
		i = n;
		while (i > 0)
		{
			i--;
			c_dest[i] = c_src[i]; // cal el casteo...
		}
	}
	else
	{
		i = 0;
		while (i < n)
		{
			c_dest[i] = c_src[i];
			i++;
		}
	}
	return (dest);
}
