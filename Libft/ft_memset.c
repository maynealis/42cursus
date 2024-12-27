/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmayne-p <cmayne-p@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 11:54:08 by cmayne-p          #+#    #+#             */
/*   Updated: 2024/12/27 14:02:20 by cmayne-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
*	@brief Fills a block of memory with a constant byte.
*	
*	This functions fills the first n bytes of the memory area pointed to by s
*	with the constant byte c.
*
*	@param s The pointer to the memory area to be filled. 
*	@param c The value to fill the memory with. It is passed as an `int` but
*			 only the less significant byte is used, as it is converted to 
*			 an `unsigned char`.
*	@param n The number of bytes to fill in the memory block.
*	
*	@return A pointer to the memory area s.
*/
void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		ptr[i] = (unsigned char)c;
		i++;
	}
	return (s);
}
