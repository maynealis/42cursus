/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmayne-p <cmayne-p@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 13:25:46 by cmayne-p          #+#    #+#             */
/*   Updated: 2024/12/22 13:51:04 by cmayne-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	size_t	s1_size;
	size_t	s2_size;

	s1_size = ft_strlen(s1);
	s2_size = ft_strlen(s2);
	result = (char *)malloc(s1_size + s2_size + 1);
	ft_bzero(result, s1_size + s2_size + 1);
	ft_strlcat(result, s1, s1_size + 1);
	ft_strlcat(result, s2, s1_size + s2_size + 1);
	return (result);
}
