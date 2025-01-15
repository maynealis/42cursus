/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmayne-p <cmayne-p@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 18:42:53 by cmayne-p          #+#    #+#             */
/*   Updated: 2025/01/15 16:13:08 by cmayne-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

#define CONVERSIONS "cspdiuxX%"

int	ft_printf(const char *str, ...)
{
	va_list args;

	va_start(args, str);

	char	*str_copy = ft_strdup(str); //malloc
	
	char	*subst;
	subst = ft_strchr(str, '%');
	while (subst)
	{
		if (subst == NULL)
		{
			ft_putstr_fd(str, 0);
			return (ft_strlen(str)); //va_end cal ???
		}
		char	*to_write = ft_substr(str, 0, subst); //malloc
		ft_putstr_fd(to_write, 0);
		free(to_write);

		subst = ft_strchr(subst++, '%');
	}
	va_end(args);
	return (1);
}
