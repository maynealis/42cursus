/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmayne-p <cmayne-p@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 21:29:05 by cmayne-p          #+#    #+#             */
/*   Updated: 2024/12/20 21:47:17 by cmayne-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	char	*ptr;
	size_t	size;
	size_t	i;

	ptr = (char *)nptr;
	size = ft_strlen(ptr);
	i = 0;
	while (i < size)
	{
		if (ft_isspace(i))
			i++;
	}
}

#include <stdio.h>
#include <stdlib.h>
int	main(int argc, char**argv)
{
	(void) argc;
	printf("Atoi de %s es %d\n",argv[1], atoi(argv[1]));
	return (1);
}
