/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmayne-p <cmayne-p@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 13:03:22 by cmayne-p          #+#    #+#             */
/*   Updated: 2025/01/10 13:04:43 by cmayne-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>


int main(void)
{
    int fd = open("test.txt", O_RDONLY); // Archivo de prueba
    char *line;

    if (fd < 0)
        return (1); // Error al abrir el archivo

    while ((line = get_next_line(fd)) != NULL)
    {
        free(line); // Libera cada línea para evitar fugas
    }

    close(fd); // Cierra el archivo
    return (0);
}
