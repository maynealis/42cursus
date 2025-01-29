/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmayne-p <cmayne-p@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 11:16:53 by cmayne-p          #+#    #+#             */
/*   Updated: 2025/01/29 15:01:44 by cmayne-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h" //for the structure

t_stack	*ft_stacknew(int number)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (new == NULL)
		return (NULL);
	new->number = number;
	new->next = NULL;
	return (new);
}

t_stack	*ft_stacklast(t_stack *stack)
{
	if (stack == NULL)
		return (NULL);
	while (stack->next != NULL)
		stack = stack->next;
	return (stack);
}

void	ft_stackadd_back(t_stack **stack, t_stack *new)
{
	t_stack	*last;

	if (stack == NULL)
		return ;
	if (*stack == NULL)
	{
		*stack = new;
		return ;
	}
	last = ft_stacklast(*stack);
	last->next = new;
}

void	ft_stackadd_front(t_stack **stack, t_stack *new)
{
	if (stack == NULL)
		return ;
	new->next = *stack;
	*stack = new;
}

void	free_stack(t_stack **stack)
{
	t_stack	*current;

	if (stack == NULL)
		return ;
	while (*stack != NULL)
	{
		current = *stack;
		*stack = (*stack)->next;
		current->next = NULL;
		free(current);
	}
}
