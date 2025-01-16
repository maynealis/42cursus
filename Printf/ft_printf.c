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

#define CONVERSIONS "cspdiuxX%"

int	write_subst(char type, void *sub)
{
	if (type == 'c' || type == '%')
		return (write_char(*((char *)sub)));
	else if (type == 's')
		return (write_str((char *)sub));
	else if (type == 'p')
		return (write_hexa((unsigned long)sub, 'x'));
	else if (type == 'd' || type == 'i')
		return (write_int(*((int *)sub)));
	else if (type == 'u')
		return (write_uint(*((unsigned int *)sub)));
	else if (type == 'x' || type == 'X')
		return (write_hexa(*((unsigned int *)sub), type));
	return (-1); //error??
}

int	ft_printf(const char *str, ...)
{
	int		result;
	va_list args;

	va_start(args, str);

	char	*subst;
	subst = ft_strchr(str, '%');

	// Nothing to substitute
	if (subst == NULL)
	{
		ft_putstr_fd((char *)str, 1);
		va_end(args);
		return (ft_strlen(str));
	}
	result = 0;
	int	ini = 0;
	while (subst)
	{
		int		len = (int)(subst - (str + ini));
		char	*to_write = ft_substr(str, ini, len)); //malloc
		result += write_str(to_write);
		free(to_write);

		result += write_subst(*(subst++), va_arg(args, void *));
		
		ini = (int)subst + 1;
		subst = ft_strchr(++subst, '%');
	}
	if (subst != NULL)
	{
		result += write_str(subst);
	}
	va_end(args);
	return (1);
}
