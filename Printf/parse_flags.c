
#include "libft.h"
#include "ft_printf_bonus.h"

char	*parse_precision_num(char *num, t_flags flags) //num without sign onlye for d i u x X
{
	char	*zeros;
	size_t	len_num;
	char	*str;

	zeros = NULL;
	len_num = ft_strlen(num);
	if (flags.precision > (int)len_num)
	{
		zeros = ft_calloc(flags.precision - len_num + 1, 1);
		if (zeros)
			zeros = ft_memset(zeros, '0', flags.precision - len_num);
	}
	str = ft_strjoin(zeros, num);
	free(zeros);
	return (str);
}

char	*parse_precision_str(char *str, t_flags flags)
{
	char	*str_result;

	if (flags.precision < (int)ft_strlen(str))
	{
		str_result = ft_substr(str, 0, flags.precision);
		return (str_result);
	}
	else
		str_result = ft_strdup(str);
	return (str_result);
}

char	*parse_sign(char *num, char is_neg, t_flags flags) //num without sign
{
	char	*str;

	if (!is_neg && flags.plus)
		str = ft_strjoin("+", num);
	else if (!is_neg && flags.space)
		str = ft_strjoin(" ", num);
	else if (is_neg)
		str = ft_strjoin("-", num);
	else
		str = ft_strdup(num);
	return (str);
}

char	*parse_hash(char *num, unsigned long n, t_flags flags)
{
	char	*prefix;
	char	*str;

	prefix = NULL;
	if (flags.hash && n != 0)
		prefix = ft_strdup("0x");
	else if (flags.hash && n != 0)
		prefix = ft_strdup("0X");
	str = ft_strjoin(prefix, num);
	free(prefix);
	return (str);
}

char	*parse_zero(char *str, char is_neg, t_flags flags)
{
	char	*padded;
	int		str_len;
	char	*str_result;
	int		len;

	padded = NULL;
	str_len = ft_strlen(str);
	if (flags.zero && flags.width > str_len)
	{
		len = flags.width - str_len - is_neg;
		padded = (char *)ft_calloc(len + 1, sizeof(char));
		if (padded && !flags.dot)
			padded = ft_memset(padded, '0', len);
		if (padded && flags.dot)
			padded = ft_memset(padded, ' ', len);
	}
	str_result = ft_strjoin(padded, str);
	free(padded);
	return (str_result);
}

// char	*parse_zero_hexa(char *str, char is_neg, unsigned long n, t_flags flags)
// {
// 	char	*padded;
// 	int		str_len;
// 	char	*str_hash;
// 	char	*str_result;
// 	int		len;

// 	padded = NULL;
// 	str_len = ft_strlen(str);
// 	str_hash = ft_strdup(str);
// 	if (flags.zero && flags.width > str_len)
// 	{
// 		len = flags.width - str_len - is_neg;
// 		padded = (char *)ft_calloc(len + 1, sizeof(char));
// 		if (padded && !flags.dot)
// 			padded = ft_memset(padded, '0', len);
// 		if (padded && flags.dot)
// 		{
// 			if (flags.hash)
// 			{
// 				free(str_hash);
// 				str_hash = parse_hash(str, n, flags);
// 			}
// 			padded = ft_memset(padded, ' ', len);
// 		}
// 	}
// 	str_result = ft_strjoin(padded, str_hash);
// 	free(padded);
// 	free(str_hash);
// 	return (str_result);
// }

char	*parse_width(char *str, t_flags flags)
{
	char	*padded;
	int		str_len;
	char	*str_result;

	padded = NULL;
	str_len = ft_strlen(str);
	if (flags.width > str_len)
	{
		padded = ft_calloc(flags.width - str_len + 1, 1);
		if (padded)
			padded = ft_memset(padded, ' ', flags.width - str_len);
	}
	if (flags.minus)
		str_result = ft_strjoin(str, padded);
	else
		str_result = ft_strjoin(padded, str);
	free(padded);
	return (str_result);
}

char	*parse_padded_char(char c, t_flags flags)
{
	char	*padded;
	char	*str_result;
	char	*c_ptr;

	c_ptr = (char *)ft_calloc(2, sizeof(char));
	c_ptr[0] = c;
	padded = NULL;
	if (flags.width > 1 && (flags.minus || (!flags.minus && !flags.zero)))
	{
		padded = ft_calloc(flags.width, 1);
		if (padded)
			padded = ft_memset(padded, ' ', flags.width - 1);
	}
	else if (flags.zero && flags.width > 1)
	{
		padded = ft_calloc(flags.width, 1);
		if (padded)
			padded = ft_memset(padded, '0', flags.width - 1);
	}
	if ((flags.zero && c != '%') || flags.minus)
		str_result = ft_strjoin(c_ptr, padded);
	else
		str_result = ft_strjoin(padded, c_ptr);
	free(padded);
	free(c_ptr);
	return (str_result);
}