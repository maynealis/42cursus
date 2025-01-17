/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_conversions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmayne-p <cmayne-p@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 13:18:08 by cmayne-p          #+#    #+#             */
/*   Updated: 2025/01/17 12:28:53 by cmayne-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_utils.h"

int	write_char(char c)
{
	ft_putchar_fd(c, 1);
	return (1);
}

int	write_str(char *str)
{
	if (str == NULL)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	ft_putstr_fd(str, 1);
	return (ft_strlen(str));
}

int	write_int(int n)
{
	char	*int_str;
	int		len;

	int_str = ft_itoa(n);
	len = write_str(int_str);
	free(int_str);
	return (len);
}

int	write_uint(unsigned int n)
{
	char	*num;
	int		len;

	num = ft_uitoa_base(n, FT_BASE_DECIMAL);
	len = write_str(num);
	free(num);
	return (len);
}

int	write_hexa(unsigned long n, char x, char *prefix)
{
	char	*num;
	char	*str;
	int		len;

	if (n == 0)
		return (write_char('0'));
	if (x == 'x')
		num = ft_ultoa_base(n, FT_BASE_HEXA_MIN);
	else
		num = ft_ultoa_base(n, FT_BASE_HEXA_MAY);
	str = ft_strjoin(prefix, num);
	free(num);
	len = write_str(str);
	free(str);
	return (len);
}
