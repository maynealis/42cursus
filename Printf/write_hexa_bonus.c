/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_hexa_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmayne-p <cmayne-p@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 15:56:37 by cmayne-p          #+#    #+#             */
/*   Updated: 2025/01/17 16:13:07 by cmayne-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	write_hexa(char *flags, unsigned long n, char x, char *prefix)
{
	char	*num;
	char	*str;
	int		len;

	if (x == 'x')
		num = ft_ultoa_base(n, FT_BASE_HEXA_MIN);
	else
		num = ft_ultoa_base(n, FT_BASE_HEXA_MAY);
	if (ft_strchr(flags, '#') && x == 'x')
		str = ft_strjoin("0x", num);
	else if (ft_strchr(flags, '#') && x == 'X')
		str = ft_strjoin("0X", num);
	else
		str = ft_strjoin(prefix, num);
	free(num);
	len = write_str(str);
	free(str);
	return (len);
}
