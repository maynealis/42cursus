/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmayne-p <cmayne-p@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 18:42:53 by cmayne-p          #+#    #+#             */
/*   Updated: 2025/01/16 14:51:56 by cmayne-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include "ft_utils.h"

//#define CONVERSIONS "cspdiuxX%"

// int	write_subst_old(char type, void *sub)
// {
// 	if (type == 'c')
// 		return (write_char(*((char *)sub)));
// 	else if (type == '%')
// 		return (write_char('%'));
// 	else if (type == 's')
// 		return (write_str((char *)sub));
// 	else if (type == 'p')
// 		return (write_hexa((unsigned long)sub, 'x'));
// 	else if (type == 'd' || type == 'i')
// 		return (write_int(*((int *)sub)));
// 	else if (type == 'u')
// 		return (write_uint(*((unsigned int *)sub)));
// 	else if (type == 'x' || type == 'X')
// 		return (write_hexa(*((unsigned int *)sub), type));
// 	return (-1); //error??
// }

int	write_subst(char type, va_list args)
{
	if (type == 'c')
		return (write_char(va_arg(args, int))); // TODO: why then char is actually an int?
	else if (type == '%')
		return (write_char('%'));
	else if (type == 's')
		return (write_str(va_arg(args, char *)));
	else if (type == 'p')
		return (write_hexa(va_arg(args, unsigned long), 'x'));
	else if (type == 'd' || type == 'i')
		return (write_int(va_arg(args, int)));
	else if (type == 'u')
		return (write_uint(va_arg(args, unsigned int)));
	else if (type == 'x' || type == 'X')
		return (write_hexa(va_arg(args, unsigned long), type));
	return (-1); //error??
}

int	ft_printf(const char *str, ...)
{
	int		result;
	va_list	args;
	size_t	i;

	va_start(args, str);
	result = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			i++; //conversion
			result += write_subst(str[i], args);
		}
		else
			result += write_char(str[i]);
		i++;
	}
	va_end(args);
	return (result);
}
