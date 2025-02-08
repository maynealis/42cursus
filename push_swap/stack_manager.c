/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmayne-p <cmayne-p@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 11:52:50 by cmayne-p          #+#    #+#             */
/*   Updated: 2025/02/08 13:28:46 by cmayne-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_stacksize(t_stack *stack)
{
	t_stack	*first;
	int		size;

	if (!stack)
		return (0);
	first = stack;
	size = 1;
	while (stack)
	{
		stack = stack->next;
		if (stack == first)
			break ;
		size++;
	}
	return (size);
}

t_stack	*ft_stacknew(int number)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (new == NULL)
		return (NULL);
	new->num = number;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

void	ft_stackadd_back(t_stack **stack, t_stack *new)
{
	t_stack	*first;
	t_stack	*last;

	if (!stack || !new)
		return ;
	if (!*stack)
	{
		*stack = new;
		new->next = new;
		new->prev = new;
		return ;
	}
	first = *stack;
	last = first->prev;
	last->next = new;
	first->prev = new;
	new->next = first;
	new->prev = last;
}

void	ft_stackadd_front(t_stack **stack, t_stack *new)
{
	t_stack	*first;
	t_stack	*last;

	if (!stack || !new)
		return ;
	if (!*stack)
	{
		*stack = new;
		new->next = new;
		new->prev = new;
		return ;
	}
	first = *stack;
	last = first->prev;
	new->next = first;
	new->prev = last;
	first->prev = new;
	last->next = new;
	*stack = new;
}

t_stack	*ft_stackremove_front(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*last;

	if (!stack || !*stack)
		return (NULL);
	first = *stack;
	second = first->next;
	last = first->prev;
	first->next = NULL;
	first->prev = NULL;
	if (second == first)
	{
		*stack = NULL;
		return (first);
	}
	second->prev = last;
	last->next = second;
	*stack = second;
	return (first);
}

//TODO: revisar esto
void	ft_stackfree(t_stack **stack)
{
	t_stack	*next;
	int		size;
	int		i;

	if (!stack)
		return ;
	size = ft_stacksize(*stack);
	i = 0;
	while (i < size)
	{
		next = (*stack)->next;
		free(*stack);
		*stack = next;
		i++;
	}
	*stack = NULL;
}
