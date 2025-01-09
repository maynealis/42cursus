/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmayne-p <cmayne-p@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 17:48:37 by cmayne-p          #+#    #+#             */
/*   Updated: 2025/01/05 19:25:50 by cmayne-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line.h"

#include <unistd.h> //read
#include <fcntl.h> //open
#include <stdio.h> //printf

int	main(void)
{
	char	*line;
	int		fd;

	// invalid fd
	line = get_next_line(8);
	printf("Test with invalid fd: '%s'", line);
	while (line)
	{
		printf("Test with invalid fd: '%s'", line);
		line = get_next_line(8);
	}
	printf("\n--------------------------------\n");

	// file empty
	fd = open("test_empty.txt", O_RDONLY);
	line = get_next_line(fd);
	printf("Test with empty file: '%s'", line);
	while (line)
	{
		printf("Test with empty file: '%s'", line);
		line = get_next_line(fd);
	}
	printf("\n--------------------------------\n");
	close(fd);

	// file with 1 char
	fd = open("test_1char.txt", O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		printf("Test with 1char file: '%s'", line);
		line = get_next_line(fd);
	}
	printf("\n--------------------------------\n");
	close(fd);

	// file with 1 line only ended in \n
	fd = open("test_1line_endiline.txt", O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		printf("Test with 1 line and endline: '%s'", line);
		line = get_next_line(fd);
	}
	printf("\n--------------------------------\n");
	close(fd);

	// file with 1 line only with no \n
	fd = open("test_1line_noendline.txt", O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		printf("Test with 1 line and no endline: '%s'", line);
		line = get_next_line(fd);
	}
	printf("\n--------------------------------\n");
	close(fd);

	// file with multiple lines
	fd = open("test_multiplelines.txt", O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		printf("Test with multi lines: '%s'", line);
		line = get_next_line(fd);
	}
	printf("\n--------------------------------\n");
	close(fd);

	// file with looooong single line
	fd = open("test_1longline.txt", O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		printf("Test with 1 long line: '%s'", line);
		line = get_next_line(fd);
	}
	printf("\n--------------------------------\n");
	close(fd);

	// file with looooong lines
	fd = open("test_longlines.txt", O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		printf("Test with multi long lines: '%s'", line);
		line = get_next_line(fd);
	}
	printf("\n--------------------------------\n");
	close(fd);

	return (0);
}
