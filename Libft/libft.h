/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmayne-p <cmayne-p@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 16:36:55 by cmayne-p          #+#    #+#             */
/*   Updated: 2024/12/21 16:43:38 by cmayne-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h> // size_t
# include <stdlib.h> // malloc
# include <limits.h> //SIZE_MAX
# include <errno.h> 

int		ft_isupper(int c);
int		ft_islower(int c);
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isspace(int c);
int		ft_isalnum(int c); //for test
int		ft_isascii(int c); //for test
int		ft_isprint(int c); //for test
size_t	ft_strlen(const char *s);
void	*ft_memset(void *s, int c, size_t n); //for test
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n); //for test
void	*ft_memmove(void *dest, const void *src, size_t n); //for test
size_t	ft_strlcpy(char *dst, const char *src, size_t size); //for test
size_t	ft_strlcat(char *dst, const char *src, size_t size); //for test
int		ft_toupper(int c); //for test
int		ft_tolower(int c); //for test
char	*ft_strchr(const char *s, int c); //for test
char	*ft_strrchr(const char *s, int c); //for test
int		ft_strncmp(const char *s1, const char *s2, size_t n); //for test
void	*ft_memchr(const void *s, int c, size_t n); // for test
int		ft_memcmp(const void *s1, const void *s2, size_t n); //for test
char	*ft_strnstr(const char *big, const char *little, size_t len); //for test
int		ft_atoi(const char *nptr); //for test
void	*ft_calloc(size_t nmemb, size_t size); // for test
char	*ft_strdup(const char *s); // for test

#endif
