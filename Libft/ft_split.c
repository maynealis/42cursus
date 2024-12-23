/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmayne-p <cmayne-p@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 12:05:30 by cmayne-p          #+#    #+#             */
/*   Updated: 2024/12/23 13:39:13 by cmayne-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_words(char const *s, char c)
{
	size_t	size;
	size_t	i;
	size_t	words;

	size = ft_strlen(s);
	words = 0;
	if (s[0] != c && s[0] != '\0')
		words++;
	i = 1;
	while (i < size)
	{
		if (s[i] != c && s[i - 1] == c)
			words++;
		i++;
	}
	return (words);
}

char	**ft_split(char const *s, char c)
{
	size_t	words;
	size_t	n;
	char	**result;

	if (s == NULL)
		return (NULL);	
	words = ft_count_words(s, c);
	result = (char **)malloc((words + 1) * sizeof(char *));
	if (result == NULL)
		return (NULL);
	n = 0;
	while (n < words)
	{
		result[n] = (char *)malloc(sizeof(char) * ft_strlen(xxx))
		n++;
	}
	return (NULL);
}

int	main()
{
	ft_split("   Hello world ", 32);
	return (1);
}
