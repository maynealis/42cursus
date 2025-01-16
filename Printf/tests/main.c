/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmayne-p <cmayne-p@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 14:26:17 by cmayne-p          #+#    #+#             */
/*   Updated: 2025/01/16 14:33:53 by cmayne-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(void)
{
//	ft_printf("Simple print\n");
	ft_printf("Print with substitution at the end %s", "---this is the substitution\n");
//	ft_printf("Print with %s at the middle %s", "---this is the substitution---");
	return (0);
}
