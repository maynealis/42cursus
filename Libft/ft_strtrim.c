/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmayne-p <cmayne-p@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 13:56:22 by cmayne-p          #+#    #+#             */
/*   Updated: 2024/12/23 11:28:59 by cmayne-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	ini;
	size_t	end;
	size_t	size;
	char	*result;

	if (!s1 || !set)
		return (NULL);
	size = ft_strlen(s1);
	ini = 0;
	end = 0;
	while (ini < size && ft_strchr(set, s1[ini]) != NULL)
		ini++;
	while (end < size - 1 - ini && ft_strchr(set, s1[size - 1 - end]) != NULL)
		end++;
	result = ft_substr(s1, ini, size - ini - end);
	if (result == NULL)
		return (NULL);
	return (result);
}
