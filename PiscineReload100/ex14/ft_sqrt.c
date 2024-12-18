/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmayne-p <cmayne-p@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 19:14:03 by cmayne-p          #+#    #+#             */
/*   Updated: 2024/12/17 19:33:43 by cmayne-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	result;

	if (nb < 0)
		return (0);
	result = 2;
	while (result <= nb / result)
	{
		if (result * result == nb)
			return (result);
		result++;
	}
	return (0);
}
