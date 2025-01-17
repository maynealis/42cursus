/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmayne-p <cmayne-p@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 18:42:53 by cmayne-p          #+#    #+#             */
/*   Updated: 2025/01/17 15:38:09 by cmayne-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_utils.h"

int	write_subst(char type, va_list args)
{
	void	*arg;

	if (type == 'c')
		return (write_char(va_arg(args, int)));
	else if (type == '%')
		return (write_char('%'));
	else if (type == 's')
		return (write_str(va_arg(args, char *)));
	else if (type == 'p')
	{
		arg = va_arg(args, void *);
		if (arg == NULL)
			return (write_str("(nil)"));
		return (write_hexa((unsigned long)arg, 'x', "0x"));
	}
	else if (type == 'd' || type == 'i')
		return (write_int(va_arg(args, int)));
	else if (type == 'u')
		return (write_uint(va_arg(args, unsigned int)));
	else if (type == 'x' || type == 'X')
		return (write_hexa(va_arg(args, unsigned long), type, NULL));
	return (-1); //error?
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
			i++;
			result += write_subst(str[i], args);
		}
		else
			result += write_char(str[i]);
		i++;
	}
	va_end(args);
	return (result);
}
