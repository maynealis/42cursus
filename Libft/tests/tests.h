/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmayne-p <cmayne-p@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 12:16:58 by cmayne-p          #+#    #+#             */
/*   Updated: 2024/12/27 12:31:10 by cmayne-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_H
# define TESTS_H

# include <stdio.h> //printf
# include <string.h> //strcmp
# include <ctype.h> //isalpha isdigit isascii isprint toupper tolower
# include <stddef.h> //size_t
# include <stdlib.h> //atoi

void	do_test_ascii_functions(void);
void	do_test_ft_strlen(void);
void	do_test_ft_memset(void);
void	do_test_ft_bzero(void);
void	do_test_ft_memcpy(void);
void	do_test_ft_memmove(void);
void	do_test_ft_strchr(void);
void	do_test_ft_strrchr(void);
void	do_test_ft_strncmp(void);
void	do_test_ft_memchr(void);
void	do_test_ft_memcmp(void);
void	do_test_ft_strnstr(void);
void	do_test_ft_atoi(void);
void	do_test_ft_calloc(void);
void	do_test_ft_strdup(void);
void	do_test_ft_substr(void);
void	do_test_ft_strjoin(void);
void	do_test_ft_strtrim(void);
void	do_test_ft_split(void);
void	do_test_ft_itoa(void);
void	do_test_ft_strmapi(void);
void	do_test_ft_striteri(void);
void	tests_fd(void);

#endif /* TESTS_H*/
