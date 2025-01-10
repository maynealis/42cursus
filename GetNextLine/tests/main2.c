/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmayne-p <cmayne-p@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 13:03:22 by cmayne-p          #+#    #+#             */
/*   Updated: 2025/01/10 15:04:55 by cmayne-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line_bonus.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>


int main(void)
{
    int fd1 = open("test_1char.txt", O_RDONLY);
    int fd2 = open("test1", O_RDONLY);
    int fd3 = open("test2", O_RDONLY);
    int fd4 = open("test_empty.txt", O_RDONLY);
	char *line;

	printf("\n-----------NORMAL---------\n");
	line = get_next_line(fd1);
	printf("line: %s", line);
	free(line);
	
	printf("\n--------EMPTY---------\n");
	line = get_next_line(fd4);
	printf("line: %s", line);
	free(line);

	printf("\n-----------2 FILES---------\n");
	line = get_next_line(fd2);
	printf("line 1: %s", line);
	free(line);

	line = get_next_line(fd3);
	printf("line 2: %s", line);
	free(line);

	line = get_next_line(fd2);
	printf("line 1: %s", line);
	free(line);

	line = get_next_line(fd3);
	printf("line 2: %s", line);
	free(line);

	line = get_next_line(fd3);
	printf("line 2: %s", line);
	free(line);

	line = get_next_line(fd2);
	printf("line 1: %s", line);
	free(line);

	line = get_next_line(fd2);
	while (line)
	{
		free(line);
		line = get_next_line(fd2);
	}

	line = get_next_line(fd3);
	while(line)
	{
		free(line);
		line = get_next_line(fd3);
	}

    close(fd1);
    close(fd2);
    close(fd3);
    close(fd4);
    return (0);
}
