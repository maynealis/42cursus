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
//Edgecase: What happens if n is bigger than size src?
/**
 * @brief Copies n bytes from memory area src to memory area dest.
 * 
 * The memory areas may overlap.
 * --------------------------------------------------------
 * EXEMPLES
 * dst [H][e][l][ ][ ][ ]
 * src          [w][o][r][l][d][\0]
 * res [w][o][r][l][d][r][l][d]]\0
 * 
 * dst          [l][o][w][o][r][l][d][\0]
 * src [H][e][l][l][o]
 * res          [H][e][l][l][o][l][d][\0]
 * ---------------------------------------------------------
 * 
 * If n is 0, the function does nothing and simply returns `dest`.
 * 
 * @param dest The pointer to the destination memory are.
 * @param src The pointer to the source memory area.
 * @param n The number of bytes to copy.
 * @return The pointer to the memory area dest.
 * 
 * @note Edge cases:
 * - **n > size of src**: If `n`is bigger than the size of the allocated memory
 * 	for source, the behaviour of the function is unpredicted.
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
	if (dest <= src)
	{
		i = 0;
		while (i < n)
		{
			c_dest[i] = c_src[i];
			i++;
		}
	}
	else
	{
		i = n;
		while (i > 0)
		{
			i--;
			c_dest[i] = c_src[i];
		}
	}
	return (dest);
}
