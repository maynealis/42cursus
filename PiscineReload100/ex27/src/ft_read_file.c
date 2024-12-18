/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmayne-p <cmayne-p@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 13:15:06 by cmayne-p          #+#    #+#             */
/*   Updated: 2024/12/18 15:25:02 by cmayne-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h> // For read and close, write
#include <fcntl.h> // For open

#define BUFFER_SIZE 1024

void	ft_putstr(char *str);

void	ft_print_content(char *file_name)
{
	char	buffer[BUFFER_SIZE];
	int		bytes_read;
	int		total_bytes;
	int		file_id;

	file_id = open(file_name, O_RDONLY);
	if (file_id == -1)
		return (ft_putstr("Cannot read file.\n"));
	bytes_read = read(file_id, buffer, BUFFER_SIZE);
	if (bytes_read < 0)
		return (ft_putstr("Cannot read file.\n"));
	total_bytes = 0;
	while (bytes_read > 0)
	{
		write(1, &buffer, bytes_read);
		total_bytes += bytes_read;
		bytes_read = read(file_id, buffer, BUFFER_SIZE);
	}
	close(file_id);
}
