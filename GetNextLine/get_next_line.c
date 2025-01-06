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

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*result;
	size_t	i;
	size_t	s1_size;
	size_t	s2_size;

	s1_size = 0;
	s2_size = 0;
	if (s1 != NULL)
		s1_size = ft_strlen(s1);
	if (s2 != NULL) // en teoria en mi caso esto no pasara nunca creo?
		s2_size = ft_strlen(s2);
	result = (char *)malloc((s1_size + s2_size + 1) * sizeof(char));
	i = -1;
	while (++i < s1_size)
		result[i] = s1[i];
	i = -1;
	while (++i < s2_size)
		result[s1_size + i] = s2[i];
	result[s1_size + s2_size] = '\0';
	free(s1); 
	return (result);
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
