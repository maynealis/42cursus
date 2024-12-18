/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmayne-p <cmayne-p@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 10:54:04 by cmayne-p          #+#    #+#             */
/*   Updated: 2024/12/16 10:54:08 by cmayne-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h> //for malloc
#include <string.h> // for strdup
#include <stdio.h> // for printf

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strdup(char *src)
{
	char	*dst;
	int		size;
	int		i;

	size = ft_strlen(src);
	dst = (char *)malloc(size * sizeof(char) + 1);
	if (dst == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		dst[i] = src[i];
		i++;
	}
	return (dst);
}

int	main(int argc, char **argv)
{
	char	*my_result;
	char	*result;

	(void)argc;
	my_result = ft_strdup(argv[1]);
	result = strdup(argv[1]);

	printf("My result: %s\n", my_result);
	printf("Strdup: %s\n", result);
	free(my_result);
	return (0);
}
