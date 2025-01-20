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
	int	result;

	i = -1;
	result = 0;
	if (flags.width > 1 && flags.minus == 0)
	{
		while (++i < flags.width - 1)
			result += write(1, " ", 1);
	}
	result += write(1, &c, 1);
	if (flags.width > 1 && flags.minus == 1)
	{
		while (++i < flags.width - 1)
			result += write(1, " ", 1);
	}
	return (result);
}

int	write_str(char *str, t_flags flags)
{
	int	result;
	int	i;
	char	*str_to_write;
	char	str_len;

	if (str == NULL)
		str_to_write = ft_strdup("(null)");
	else
		str_to_write = ft_strdup(str);
	str_len = ft_strlen(str_to_write);
	result = 0;
	i = -1;
	while (flags.minus == 0 && ++i < flags.width - str_len)
		result += write(1, " ", 1);
	result += write(1, str_to_write, str_len);
	while (flags.minus == 1 && ++i < flags.width - str_len)
		result += write(1, " ", 1);
	free(str_to_write);
	return (result);
}

char	*fill_zero_padded(char *int_str, t_flags flags, int width)
{
	char	*zero_str;
	char	*zero_padded;
	char	*str_to_write;
	char	is_neg;

	is_neg = 0;
	if (int_str[0] == '-')
		is_neg = 1;
	zero_str = (char *)malloc(width + 1); //better ft_calloc
	zero_str[width] = '\0';
	zero_str = ft_memset(zero_str, '0', width);
	zero_padded = ft_strjoin(zero_str, int_str + is_neg);
	free(zero_str);
	if (flags.plus == 1 && !is_neg)
		str_to_write = ft_strjoin("+", zero_padded);
	else if (is_neg)
	str_to_write = ft_strjoin("-", zero_padded);
	else
		str_to_write = ft_strdup(zero_padded);
	free(zero_padded);
	return (str_to_write);
}

int	write_int(int n, t_flags flags)
{
	char	*int_str;
	char	*str_to_write;
	int		len;
	int		size;

	len = 0;
	int_str = ft_itoa(n);
	size = ft_strlen(int_str);
	if (flags.zero && flags.width > size)
		str_to_write = fill_zero_padded(int_str, flags, flags.width - size);
	else if (flags.plus == 1 && n >= 0)
		str_to_write = ft_strjoin("+", int_str);
	else if (flags.space == 1 && n >= 0)
		str_to_write = ft_strjoin(" ", int_str);
	else
		str_to_write = ft_strdup(int_str);
	len += write_str(str_to_write, flags);
	free(int_str);
	free(str_to_write);
	return (len);
}

int	write_uint(unsigned int n, t_flags flags)
{
	char	*num;
	char	*str;
	int		len;
	int		size;

	num = ft_uitoa_base(n, FT_BASE_DECIMAL);
	size = ft_strlen(num);
	if (flags.zero && flags.width > size)
		str = fill_zero_padded(num, flags, flags.width - size);
	else
		str = ft_strdup(num);
	len = write_str(str, flags);
	free(num);
	free(str);
	return (len);
}

int	write_hexa(unsigned long n, char x, t_flags flags)
{
	char	*num;
	char	*str;
	char	*str_zeros;
	char	*prefix;
	int		len;

	if (x == 'x' || x == 'p')
		num = ft_ultoa_base(n, FT_BASE_HEXA_MIN);
	else
		num = ft_ultoa_base(n, FT_BASE_HEXA_MAY);
	prefix = NULL;
	if (n != 0 && flags.hash == 1 && (x == 'x' || x == 'p'))
		prefix = ft_strdup("0x");
	else if (n!= 0 && flags.hash == 1 && x == 'X')
		prefix = ft_strdup("0X");
	if (flags.zero && flags.width > (int)(ft_strlen(num) - ft_strlen(prefix)))
		str_zeros = fill_zero_padded(num, flags, flags.width - ft_strlen(num) - ft_strlen(prefix));
	else
		str_zeros = ft_strdup(num);
	str = ft_strjoin(prefix, str_zeros);
	len = write_str(str, flags);
	free(prefix);
	free(num);
	free(str);
	free(str_zeros);
	return (len);
}
