/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmayne-p <cmayne-p@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 11:00:11 by cmayne-p          #+#    #+#             */
/*   Updated: 2025/01/15 13:07:53 by cmayne-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h> // to use: va_start, va_arg, va_copy, va_end
//# include <unistd.h> // to use: write
//# include <stdlib.h> // to use malloc and free
# include <limits.h> // to use: INT_MIN

# define FT_BASE_HEXA "0123456789abcdef"

int	ft_printf(char const *, ...);

#endif
