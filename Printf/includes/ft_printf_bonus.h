/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmayne-p <cmayne-p@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 11:00:11 by cmayne-p          #+#    #+#             */
/*   Updated: 2025/01/22 13:02:06 by cmayne-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <stdarg.h> // to use: va_start, va_arg, va_copy, va_end
# include <stddef.h> // to use: size_t
//# include <stdbool.h> // to use bool?

// TODO: con mascaras de bits?
typedef struct s_flags
{
	char	minus;
	char	zero;
	char	dot;
	char	hash;
	char	space;
	char	plus;
	int		width; //?	
	int		precision;
}	t_flags;

int		ft_printf(char const *str, ...);

int		write_char(char c, t_flags flags);
int		write_str(char *str, t_flags flags);
int		write_int(int n, t_flags flags);
int		write_uint(unsigned int n, t_flags flags);
int		write_hexa(unsigned long n, char x, t_flags flags);

# define FT_BASE_HEXA_MIN "0123456789abcdef"
# define FT_BASE_HEXA_MAY "0123456789ABCDEF"
# define FT_BASE_DECIMAL "0123456789"

char	*ft_uitoa_base(unsigned int n, char *base);
char	*ft_ultoa_base(unsigned long n, char *base);

#endif
