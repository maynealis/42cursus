/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_hexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmayne-p <cmayne-p@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 11:54:22 by cmayne-p          #+#    #+#             */
/*   Updated: 2025/01/15 12:00:08 by cmayne-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	write_x(int n)
{
	ft_putnbr_base_fd(n, FT_BASE_HEXA, 0);
}

void	write_x_mayus(int n)
{
	ft_putnbr_base_fd(n, "0123456789ABCDEF", 0);
}
