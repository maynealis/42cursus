/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmayne-p <cmayne-p@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 15:54:43 by cmayne-p          #+#    #+#             */
/*   Updated: 2024/12/23 11:46:37 by cmayne-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dst_size;

	if (!dst && !src)
		return (0);
	if (!dst)
		return (ft_strlen(src));
	if (!src)
		return (ft_strlen(dst));
	dst_size = ft_strlen(dst);
	if (size < dst_size)
		return (size);
	i = 0;
	while (i < size - dst_size - 1)
	{
		dst[dst_size + i] = src[i];
		i++;
	}
	dst[dst_size + i] = '\0';
	return (dst_size + ft_strlen(src));
}
