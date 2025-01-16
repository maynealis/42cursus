/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_hexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmayne-p <cmayne-p@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 13:03:17 by cmayne-p          #+#    #+#             */
/*   Updated: 2025/01/16 13:13:59 by cmayne-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	write_hexa_min(unsigned long n)
{
	char	*num;
	char	*prefix;
	char	*str;
	int		len;

	num = ft_ultoa_base(n, "1234567890abcdef");
	prefix = ft_strdup("0x");
	str = ft_strjoin(prefix, num);
	free(prefix);
	free(num);
	len = write_str(str);
	free(str);
	return (len);
}

int	write_hexa_may(unsigned long n)
{
	char	*num;
	char	*prefix;
	char	*str;
	int		len;

	num = ft_ultoa_base(n, "1234567890ABCDEF");
	prefix = ft_strdup("0X");
	str = ft_strjoin(prefix, num);
	free(prefix);
	free(num);
	len = write_str(str);
	free(str);
	return (len);
}
