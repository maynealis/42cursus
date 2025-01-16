/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmayne-p <cmayne-p@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 10:33:28 by cmayne-p          #+#    #+#             */
/*   Updated: 2025/01/16 13:08:23 by cmayne-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "write_utils.h" // todooo

int	write_int(int n)
{
	char	*int_str;
	int		len;

	int_str = ft_itoa(n);
	len = write_str(int_str);
	free(int_str);
	return (len);
}
