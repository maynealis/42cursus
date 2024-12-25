/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_put_fd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmayne-p <cmayne-p@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 19:23:20 by cmayne-p          #+#    #+#             */
/*   Updated: 2024/12/25 19:23:30 by cmayne-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"
#include "../libft.h"

void	tests_fd(void)
{
	ft_putstr_fd("Hello world!", 1);
	ft_putendl_fd("Hello again!", 1);
	ft_putnbr_fd(-900077, 1);
}
