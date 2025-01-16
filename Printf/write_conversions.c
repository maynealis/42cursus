/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_conversions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmayne-p <cmayne-p@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 13:18:08 by cmayne-p          #+#    #+#             */
/*   Updated: 2025/01/16 14:24:58 by cmayne-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_utils.h"

#define FT_BASE_HEXA_MIN "0123456789abcdef"
#define FT_BASE_HEXA_MAY "0123456789ABCDEF"

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

	num = ft_uitoa_base(n, "0123456789");
	len = write_str(num);
	free(num);
	return (len);
}

int	write_hexa(unsigned long n, char x)
{
	char	*num;
	char	*prefix;
	char	*str;
	int		len;

	if (x == 'x')
	{
		num = ft_ultoa_base(n, FT_BASE_HEXA_MIN);
		prefix = ft_strdup("0x");
	}
	else
	{
		num = ft_ultoa_base(n, FT_BASE_HEXA_MAY);
		prefix = ft_strdup("0X");
	}
	str = ft_strjoin(prefix, num);
	free(prefix);
	free(num);
	len = write_str(str);
	free(str);
	return (len);
}
