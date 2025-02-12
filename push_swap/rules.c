/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmayne-p <cmayne-p@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 12:26:06 by cmayne-p          #+#    #+#             */
/*   Updated: 2025/02/07 12:29:28 by cmayne-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	push(t_stack **src, t_stack **dst)
{
	t_stack	*node;

	if (!src || !dst || !*src)
		return ;
	node = ft_stackremove_front(src);
	ft_stackadd_front(dst, node);
}

void	rotate(t_stack **stack)
{
	*stack = (*stack)->next;
}

void	reverse_rotate(t_stack **stack)
{
	*stack = (*stack)->prev;
}

void	swap(t_stack **stack)
{
	t_stack	*first;

	if (!stack || !*stack || ft_stacksize(*stack) < 2)
		return ;
	first = ft_stackremove_front(stack);
	rotate(stack);
	ft_stackadd_front(stack, first);
	reverse_rotate(stack);
}
