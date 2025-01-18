/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmayne-p <cmayne-p@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 11:00:11 by cmayne-p          #+#    #+#             */
/*   Updated: 2025/01/17 13:56:42 by cmayne-p         ###   ########.fr       */
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
}	t_flags;

int	ft_printf(char const *str, ...);

#endif
