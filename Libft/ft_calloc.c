/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmayne-p <cmayne-p@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 15:36:42 by cmayne-p          #+#    #+#             */
/*   Updated: 2024/12/21 16:15:05 by cmayne-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*result;

	if (nmemb == 0 || size == 0)
		return ((void *)malloc(1));
	if (nmemb > INT_MAX / size)
		return ((void *)0);
	result = malloc(nmemb * size);
	ft_bzero(result, nmemb * size);
	return (result);
}
