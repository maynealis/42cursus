/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmayne-p <cmayne-p@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 13:21:04 by cmayne-p          #+#    #+#             */
/*   Updated: 2025/02/08 12:16:16 by cmayne-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf_bonus.h"

void	push_print(t_stack **src, t_stack **dst, char letter)
{
	push(src, dst);
	ft_printf("p%c\n", letter);
}

void	swap_print(t_stack **stack, char letter)
{
	swap(stack);
	ft_printf("s%c\n", letter);
}

void	rotate_print(t_stack **stack, char letter)
{
	rotate(stack);
	ft_printf("r%c\n", letter);
}

void	reverse_rotate_print(t_stack **stack, char letter)
{
	reverse_rotate(stack);
	ft_printf("rr%c\n", letter);
}
