/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_conversions_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmayne-p <cmayne-p@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 13:18:08 by cmayne-p          #+#    #+#             */
/*   Updated: 2025/01/17 16:07:13 by cmayne-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf_bonus.h"

#include <stdio.h>
int	write_char(char c, t_flags flags)
{
	int	i;
	i = 0;
	if (flags.width > 1 && flags.minus == 0)
	{
		while (i < flags.width - 1)
		{
			ft_putchar_fd(' ', 1);
			i++;
		}
	}
	ft_putchar_fd(c, 1);
	if (flags.width > 1 && flags.minus == 1)
	{
		while (i < flags.width - 1)
		{
			ft_putchar_fd(' ', 1);
			i++;
		}
	}
	return (1 + i);
}

int	write_str(char *str, t_flags flags)
{
	if (flags.minus == 2)
		return (-1); //TODO QUITAAAAAR
	if (str == NULL)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	ft_putstr_fd(str, 1);
	return (ft_strlen(str));
}

int	write_int(int n, t_flags flags)
{
	char	*int_str;
	int		len;

	int_str = ft_itoa(n);
	len = write_str(int_str, flags);
	free(int_str);
	return (len);
}

int	write_uint(unsigned int n, t_flags flags)
{
	char	*num;
	int		len;

	num = ft_uitoa_base(n, FT_BASE_DECIMAL);
	len = write_str(num, flags);
	free(num);
	return (len);
}

int	write_hexa(unsigned long n, char x, char *prefix, t_flags flags)
{
	char	*num;
	char	*str;
	int		len;

	if (x == 'x')
		num = ft_ultoa_base(n, FT_BASE_HEXA_MIN);
	else
		num = ft_ultoa_base(n, FT_BASE_HEXA_MAY);
	str = ft_strjoin(prefix, num);
	free(num);
	len = write_str(str, flags);
	free(str);
	return (len);
}
