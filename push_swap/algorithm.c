/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmayne-p <cmayne-p@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 15:41:09 by cmayne-p          #+#    #+#             */
/*   Updated: 2025/01/30 15:58:38 by cmayne-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf_bonus.h"

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
		if (stack->next->number > stack->number)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	get_smallest_number_stack(t_stack *stack)
{
	int	num;

	num = stack->number;
	while (stack)
	{
		if (stack->number < num)
			num = stack->number;
		stack = stack->next;
	}
	return (num);
}

int	get_biggest_number_stack(t_stack *stack)
{
	int	num;

	num = stack->number;
	while (stack)
	{
		if (stack->number > num)
			num = stack->number;
		stack = stack->next;
	}
	return (num);
}

// suponiendo que el stack esta ordenado
int	get_number_of_moves(t_stack *stack, int n)
{
	int	moves;
	int	size;
//	int	lit;
//	int	big;

	moves = 0;
	size = ft_stacksize(stack);
//	lit = get_smallest_number_stack(stack);
//	big = get_biggest_number_stack(stack);
	
	if (ft_stacklast(stack)->number < n)
		return (2);
	while (moves < (size / 2 + (size % 2))) // + 1 per impars?
	{
		if (n < stack->number)
			break ;
			//return (moves + 1);
		moves++;
		stack = stack->next;
	}
	return (moves + 1); //minimum 1 push
}

void	insert_number(t_stack **a, t_stack **b)
{
	if (ft_stacklast(*b)->number < *a->number)
	{
		//pb + ra (to sort)
	}	
}

void	sort_stack_three(t_stack **stack)
{
	int	lit;
	int	big;

	lit = get_smallest_number_stack(*stack);
	big = get_biggest_number_stack(*stack);
	if (is_sorted(*stack))
		return ;
	else if ((*stack)->number == lit)
	{
		ft_printf("sa\n");
		swap(stack);
		ft_printf("ra\n");
		rotate(stack);
	}
	else if ((*stack)->number == big)
	{
		ft_printf("ra\n");
		rotate(stack);
		if (is_sorted(*stack))
			return ;
		ft_printf("sa\n");
		swap(stack);
	}
	else if ((*stack)->next->number == lit)
	{
		ft_printf("sa\n");
		swap(stack);
	}
	else
	{
		ft_printf("rra\n");
		reverse_rotate(stack);
	}
}
