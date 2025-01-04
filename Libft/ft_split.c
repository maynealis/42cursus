/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmayne-p <cmayne-p@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 12:05:30 by cmayne-p          #+#    #+#             */
/*   Updated: 2025/01/04 14:16:17 by cmayne-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_free(char **arr, size_t n)
{
	while (n > 0)
		free(arr[--n]);
	free(arr);
	return (NULL);
}

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

static size_t	ft_end_next_word(char const *s, char c, size_t *start)
{
	size_t	end;

	while (s[*start] == c)
		(*start)++;
	end = *start;
	while (s[end] != c && s[end] != '\0')
		end++;
	/*
	if (s[*start] != c && (*start == 0 || s[*start - 1] == c))
	{
		while (s[end] != c)
			end++;
	}
	*/
	return (end);
}

char	**ft_split(char const *s, char c)
{
	size_t	words;
	size_t	i;
	size_t	j;
	size_t	n;
	char	**result;

	if (s == NULL)
		return (NULL);
	words = ft_count_words(s, c);
	result = (char **)malloc((words + 1) * sizeof(char *));
	if (result == NULL)
		return (NULL);
	n = 0;
	j = 0;
	while (n < words)
	{
		i = j;
		j = ft_end_next_word(s, c, &i);
		result[n] = ft_substr(s, i, j - i);
		if (result[n] == NULL)
			return (ft_free(result, n));
		n++;
	}
	result[n] = (void *)0;
	return (result);
}
