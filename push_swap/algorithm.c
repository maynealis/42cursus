/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmayne-p <cmayne-p@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 15:41:09 by cmayne-p          #+#    #+#             */
/*   Updated: 2025/01/30 10:32:39 by cmayne-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	is_sorted(t_stack *stack)
{
	//if (!stack) // there is nothing
	//	return (-1);
	while (stack->next)
	{
		if (stack->next->number < stack->number)
			return (0);
		stack = stack->next;
	}
	return (1);
}

char	is_reverse_sorted(t_stack *stack)
{
	while (stack->next)
	{
		if (stack->next-number > stack->number)
			return (0);
		stack = stack->next;
	}
	return (1);
}
