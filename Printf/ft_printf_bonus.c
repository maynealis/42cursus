/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmayne-p <cmayne-p@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 13:00:53 by cmayne-p          #+#    #+#             */
/*   Updated: 2025/01/22 15:45:31 by cmayne-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
//#include "ft_utils.h"
#include "libft.h"


int	write_subst(char type, va_list args, t_flags flags)
{
	void	*arg;

	if (type == 'c')
		return (write_char(va_arg(args, int), flags));
	else if (type == '%')
		return (write_char('%', flags));
	else if (type == 's')
		return (write_str(va_arg(args, char *), flags));
	else if (type == 'p')
	{
		arg = va_arg(args, void *);
		if (arg == NULL)
			return (write_str("(nil)", flags));
		else
		{
			flags.hash = 1;
			return (write_hexa((unsigned long)arg, type, flags));
		}
	}
	else if (type == 'd' || type == 'i')
		return (write_int(va_arg(args, int), flags));
	else if (type == 'u')
		return (write_uint(va_arg(args, unsigned int), flags));
	else if (type == 'x' || type == 'X')
		return (write_hexa(va_arg(args, unsigned int), type, flags));
	return (-1);
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

t_flags	init_flags(void)
{
	t_flags flags;

	flags.minus = 0;
	flags.zero = 0;
	flags.dot = 0;
	flags.hash = 0;
	flags.space = 0;
	flags.plus = 0;
	flags.width = -1;
	flags.precision = -1;
	return (flags);
}

void	reset_flags(t_flags *flags)
{
	flags->minus = 0;
	flags->zero = 0;
	flags->dot = 0;
	flags->hash = 0;
	flags->space = 0;
	flags->plus = 0;
	flags->width = -1;
	flags->precision = -1;
}

void	set_flags(char *str_flags, char type, t_flags *flags)
{
	int	i;

	if (ft_strchr(str_flags, '#') && (type == 'x' || type == 'X'))
		flags->hash = 1;
	if (ft_strchr(str_flags, '+') && (type == 'd' || type == 'i'))
		flags->plus = 1;
	if (ft_strchr(str_flags, ' ') && (type == 'd' || type == 'i') && flags->plus == 0)
		flags->space = 1;
	if (ft_strchr(str_flags, '-'))
		flags->minus = 1;
	if (ft_strchr(str_flags, '.'))
	{
		flags->dot = 1;
		flags->precision = ft_atoi(ft_strchr(str_flags, '.') + 1);
	}
	i = 0;
	while (str_flags[i] != '\0' && str_flags[i] != '.')
	{
		if (str_flags[i] == '0' && (i == 0 || !ft_isdigit(str_flags[i - 1])))
			flags->zero = 1;
		else if (ft_isdigit(str_flags[i]))
		{
			flags->width = ft_atoi(str_flags + i); //can it be bigger that int?
			break ;
		}
		i++;
	}
	// if (str_flags[i] != '\0' && str_flags[i] == '0' && flags->minus == 0 && flags->dot == 0)
	// {
	// 	flags->zero = 1;
	// 	i++;
	// }
	// if (str_flags[i] != '\0')
	// 	flags->width = ft_atoi(str_flags + i); //can it be bigger that int?
}

int	ft_printf(const char *str, ...)
{
	int		result;
	va_list	args;
	char	*str_copy;
	t_flags	flags = init_flags();

	str_copy = (char *)str;
	va_start(args, str);
	result = 0;
	while (*str_copy != '\0')
	{
		if (*str_copy == '%')
		{
			char	*conv = find_conversion(str_copy + 1);
			char	*str_flags = ft_substr(str_copy, 0, conv-str_copy + 1);
			set_flags(str_flags, *conv, &flags);
			free(str_flags);
			int	temp =  write_subst(*conv, args, flags);
			result += temp;
			conv++;
			str_copy = conv;
			reset_flags(&flags);
		}
		else
		{
			result += write(1, str_copy, 1);
			str_copy++;
		}
	}
	va_end(args);
	return (result);
}
