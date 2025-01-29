/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmayne-p <cmayne-p@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 21:00:08 by cmayne-p          #+#    #+#             */
/*   Updated: 2025/01/29 14:59:31 by cmayne-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **stack)
{
	t_stack	*temp;

	if (stack == NULL || (*stack)->next == NULL)
		return ;
	temp = (*stack)->next;
	(*stack)->next = temp->next;
	temp->next = *stack;
	*stack = temp;
}

void	push(t_stack **src, t_stack **dst)
{
	t_stack	*first;

	if (src == NULL || *src == NULL || dst == NULL)
		return ;
	first = *src;
	*src = (*src)->next;
	first->next = NULL;
	ft_stackadd_front(dst, first);
}

void	rotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return ;
	first = *stack;
	*stack = (*stack)->next;
	last = ft_stacklast(*stack);
	first->next = NULL;
	last->next = first;
}

void	reverse_rotate(t_stack **stack)
{
	t_stack	*last;
	t_stack	*second_to_last;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return ;
	second_to_last = *stack;
	while (second_to_last->next->next)
		second_to_last = second_to_last->next;
	last = second_to_last->next;
	second_to_last->next = NULL;
	last->next = *stack;
	*stack = last;
}
