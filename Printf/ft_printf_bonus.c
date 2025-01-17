/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmayne-p <cmayne-p@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 13:00:53 by cmayne-p          #+#    #+#             */
/*   Updated: 2025/01/17 14:32:19 by cmayne-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
#include "ft_utils.h"
#include "libft.h"


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
	return (0);
}

char	*find_conversion(char *str)
{
	char	conversions[] = "cspdiuxX%";
	char	*conversion;
	char	*temp;
	int		i;

	conversion = NULL;
	i = 0;
	while (i < 9)
	{
		temp = ft_strchr(str, conversions[i]);
		if (temp == NULL)
			i++;
		else
		{
			if (conversion == NULL || (conversion != NULL && temp < conversion))
				conversion = temp;
			i++;
		}
	}
	return (conversion);
}

int	ft_printf(const char *str, ...)
{
	int		result;
	va_list	args;
	char	*str_copy;

	str_copy = (char *)str;
	va_start(args, str);
	result = 0;
	while (*str_copy != '\0')
	{
		if (*str_copy == '%')
		{
			char	*conv = find_conversion(str_copy + 1);
			result += write_subst(*conv, args); //TODO
			//int	len = conv - str_copy;
			conv++;
			str_copy = conv;
		}
		else
		{
			result += write_char(*str_copy);
			str_copy++;
		}
	}
	va_end(args);
	return (result);
}
