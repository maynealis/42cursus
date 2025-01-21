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

#include "parse_flags.c" // TODO

int	write_char(char c, t_flags flags)
{
	int		result;
	char	*str_to_write;

	str_to_write = parse_padded_char(c, flags);
	result = write(1, str_to_write, ft_strlen(str_to_write));
	free(str_to_write);
	return (result);
}

int	write_str(char *str, t_flags flags)
{
	int		result;
	char	*str_to_parse;
	char	*str_precision;
	char	*str_to_write;
	
	if (str == NULL)
		str_to_parse = ft_strdup("(null)");
	else
		str_to_parse = ft_strdup(str);
	if (str_to_parse == NULL)
		return (-1);
	str_precision = parse_precision_str(str_to_parse, flags);
	str_to_write = parse_width(str_precision, flags);
	result = write(1, str_to_write, ft_strlen(str_to_write));
	free(str_precision);
	free(str_to_write);
	free(str_to_parse);
	return (result);
}

char	*parse_int(char *num, char is_neg, t_flags flags)
{
	char	*num_precision;
	char	*num_sign;
	char	*num_zero;
	char	*num_padded;

	num_precision = parse_precision_num(num + is_neg, flags);
	num_zero = parse_zero(num_precision, is_neg, flags);
	num_sign = parse_sign(num_zero, is_neg, flags);
	num_padded = parse_width(num_sign, flags);
	free(num_precision);
	free(num_sign);
	free(num_zero);
	return (num_padded);
}

int	write_int(int n, t_flags flags)
{
	int		result;
	char	*num;
	char	is_neg;
	char	*num_to_write;

	is_neg = 0;
	if (n < 0)
		is_neg = 1;
	num = ft_itoa(n);
	if (num == NULL)
		return (-1);
	num_to_write = parse_int(num, is_neg, flags);
	result = write(1, num_to_write, ft_strlen(num_to_write));
	free(num);
	free(num_to_write);
	return (result);
}

int	write_uint(unsigned int n, t_flags flags)
{
	int		result;
	char	*num;
	char	*num_precision;
	char	*num_padded;

	num = ft_uitoa_base(n, FT_BASE_DECIMAL);
	num_precision = parse_precision_num(num, flags);
	if (flags.zero)
		num_padded = parse_zero(num_precision, 0, flags);
	else
		num_padded = parse_width(num_precision, flags);
	result = write(1, num_padded, ft_strlen(num_padded));
	free(num);
	free(num_precision);
	free(num_padded);
	return (result);
}

char	*parse_hexa(char *num, unsigned long n, t_flags flags)
{
	char	*parse1;
	char	*parse2;

	if (flags.zero && flags.dot)
	{
		parse1 = parse_hash(num, n, flags);
		// if (flags.hash)
		// 	parse2 = parse_zero(parse1, 2, flags);
		// else
		parse2 = parse_zero(parse1, 0, flags);
	}
	else if (flags.zero && !flags.dot)
	{
		if (flags.hash)
			parse1 = parse_zero(num, 2, flags);
		else
			parse1 = parse_zero(num, 0, flags);
		parse2 = parse_hash(parse1, n, flags);
	}
	else
	{
		parse1 = parse_hash(num, n, flags);
		parse2 = parse_width(parse1, flags);
	}
	free(parse1);
	return (parse2);
}

int	write_hexa(unsigned long n, char type, t_flags flags)
{
	int		result;
	char	*num;
	char	*num_precision;
	char	*num_parsed;
	// char	*num_hash;
	// char	*num_padded;
	// char	*num_zero;

	if (type == 'x' || type == 'p')
		num = ft_ultoa_base(n, FT_BASE_HEXA_MIN);
	else
		num = ft_ultoa_base(n, FT_BASE_HEXA_MAY);
	num_precision = parse_precision_num(num, flags);
	num_parsed = parse_hexa(num_precision, n, flags);


	// if (flags.hash)
	// 	num_zero = parse_zero_hexa(num_precision, 2, n, flags);
	// else
	// 	num_zero = parse_zero_hexa(num_precision, 0, n, flags);
	// num_hash = parse_hash(num_zero, n, flags);
	// if (flags.zero)
	// 	num_padded = parse_zero(num_hash, 0, flags);
	// else
	// if (!flags.zero)
	// 	num_padded = parse_width(num_hash, flags);
	// else
	// 	num_padded = ft_strdup(num_hash);
	result = write(1, num_parsed, ft_strlen(num_parsed));
	free(num);
	free(num_precision);
	// free(num_hash);
	free(num_parsed);
	// free(num_zero);
	return (result);
}
