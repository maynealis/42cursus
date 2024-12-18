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
#include <stdio.h>

int	*ft_range(int min, int max)
{
	int	i;
	int	size;
	int	*arr;

	if (min >= max)
		return (NULL);
	size = max - min;
	arr = (int *)malloc(size * sizeof(int));
	i = 0;
	while ((min + i) < max)
	{
		arr[i] = min + i;
		i++;
	}
	return (arr);
}

int main()
{
    int min = 15;
    int max = 10;
    int *range;
    int size;
    int i;

    // Llamar a ft_range
    range = ft_range(min, max);

    // Verificar si se devolvió NULL
    if (range == NULL)
    {
        printf("ft_range devolvió NULL (min >= max o error de memoria).\n");
        return 1;
    }

    // Calcular el tamaño del rango
    size = max - min;

    // Imprimir los valores del rango
    printf("Rango generado (min=%d, max=%d): ", min, max);
    for (i = 0; i < size; i++)
    {
        printf("%d ", range[i]);
    }
    printf("\n");

    // Liberar la memoria asignada
    free(range);

    return 0;
}