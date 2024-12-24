/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmayne-p <cmayne-p@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 15:36:42 by cmayne-p          #+#    #+#             */
/*   Updated: 2024/12/23 16:10:27 by cmayne-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*result;

	/*
	if (nmemb == 0 || size == 0)
		return ((void *)malloc(1));
	*/
	if (size != 0 && nmemb > FT_INT_MAX / size) //0x7fffffff
		return (NULL);
	result = malloc(nmemb * size);
	if (result == NULL)
	{
		errno = ENOMEM;
		return (NULL);
	}
	ft_bzero(result, nmemb * size);
	return (result);
}
