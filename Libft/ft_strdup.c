/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmayne-p <cmayne-p@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 16:15:22 by cmayne-p          #+#    #+#             */
/*   Updated: 2024/12/27 12:32:11 by cmayne-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Allocates sufficient memory for a copy of the string `s1`, does the
 * copy and returns a pointer to it.
 * 
 * @param s The original string to be copied.
 * @return A pointer to the copied string. If insuficient memory is available, 
 * NULL is returned and errno is set to ENOMEM.
 * 
 * @warning The memory allocated by `ft_strdup` should be freed by the user 
 * once it is no longer needed. To free the allocated memory, use the `free()` 
 * function.
 */
char	*ft_strdup(const char *s)
{
	size_t	size;
	size_t	i;
	char	*result;

	size = ft_strlen(s);
	result = (char *)malloc(size * sizeof(char) + 1);
	if (result == NULL)
	{
		errno = ENOMEM;
		return ((char *)0);
	}
	i = 0;
	while (i < size + 1)
	{
		result[i] = s[i];
		i++;
	}
	return (result);
}
