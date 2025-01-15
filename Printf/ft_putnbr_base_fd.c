/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmayne-p <cmayne-p@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 10:53:17 by cmayne-p          #+#    #+#             */
/*   Updated: 2025/01/15 11:53:53 by cmayne-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void	ft_putnbr_base_fd(int n, char *base, int fd)
{
	size_t	len_base;
	unsigned int num;

	num = (unsigned int)n;
	len_base = ft_strlen(base);
	if (num < len_base)
		ft_putchar_fd(base[num], fd);
	else
	{
		ft_putnbr_base_fd(num / len_base, base, fd);
		ft_putchar_fd(base[num % len_base], fd);
	}
}
