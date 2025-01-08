/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmayne-p <cmayne-p@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 17:26:12 by cmayne-p          #+#    #+#             */
/*   Updated: 2025/01/06 13:39:37 by cmayne-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>  // read
# include <stdlib.h>  // malloc and free
# include <stddef.h> // size_t

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 8
# endif

size_t	ft_strlen(char *s);
char	*ft_strdup(char *s);
char	*ft_substr(char *s, size_t ini, size_t end);
char	*ft_strjoin(char *s1, char *s2);
char	*get_next_line(int fd);

#endif