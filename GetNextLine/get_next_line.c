/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmayne-p <cmayne-p@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 17:25:46 by cmayne-p          #+#    #+#             */
/*   Updated: 2025/01/06 16:07:22 by cmayne-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

//TODO protegir returns de NULL i fer els free
char	*get_line(char **s)
{
	size_t	end_line;
	size_t	size;
	char	*result;
	char	*temp;

	end_line = 0;
	while (end_line < size && (*s)[end_line] != '\n') //this can be an auxiliar function
		end_line++;
	if (end_line == size)
		return (NULL); //not found
	else
	{
		result = ft_substr(*s, 0, end_line);
		temp = ft_strdup(*s);
		free(*s);
		*s = ft_substr(temp, end_line + 1, size);
		return (result);
	}
}

char	*read_append(int fd)
{
	int		bytes_read;
	char	*buffer;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (buffer == NULL)
		return (NULL);
	bytes_read = read(fd, buffer, BUFFER_SIZE); //TODO check for error, or 0?
	buffer[bytes_read] = '\0';
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*left = NULL;
	char		*current;
	char		*line;

	printf("left: %s\n", left);

	if (left != NULL)
	{
		line = get_line(&left);
		if (line)
			return (line);
	}
	
	// current = ft_strjoin(left, read_append(fd));
	// line = get_line(&current);
	line = NULL;
	while (line == NULL)
	{
		current = ft_strjoin(left, read_append(fd));
		line = get_line(&current);
		left = ft_strdup(current);
	}
	return (line);
		
		// line = get_line(&current);
		// left = current;
		// if (line)
		// 	return (line);
	
	
}

#include <fcntl.h>
int	main(void)
{
	int		fd = open("test1.txt", O_RDONLY);
	
	// char	*next_line = get_next_line(fd);
	printf("Next line is: %s", get_next_line(fd));
	printf("Next line is: %s", get_next_line(fd));
	printf("Next line is: %s", get_next_line(fd));
	printf("Next line is: %s", get_next_line(fd));
	
	close(fd);
	return (0);
}

/*
char	*search_endline(char *current)
{
	int	i;

	i = 0;
	while (current[i] != '\0')
	{
		if (current[i] == '\n')
			return ((char *)&current[i]);
		i++;
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	int		bytes_read; // es size_t o un int?
	char	*last;// = NULL;
	char	*current;
	char	*next; //ahora apunta pero deberia hacer un malloc?
	char	*line;
	static char	*remaining;

	//check if remaining has a \n -> split and return & set new remaining

	current = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	
	bytes_read = read(fd, current, BUFFER_SIZE);
	current[bytes_read] = '\0';

	next = search_endline(current);
	if (next == NULL)
		line = ft_strjoin(line, current);
	else
		//truncate
}
*/
