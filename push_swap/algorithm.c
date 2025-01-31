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

int	get_pos_smallest_number_stack(t_stack *stack)
{
	int	pos;
	int	small_number;

	small_number = get_smallest_number_stack(stack);
	pos = 0;
	while (stack->number != small_number)
	{
		pos++;
		stack = stack->next;
	}
	return (pos);
}

void	set_stack_ordered(t_stack **stack)
{
	int	pos_min;
	int	i;

	pos_min = get_pos_smallest_number_stack(*stack);
	if (pos_min < ft_stacksize(*stack) / 2)
	{
		i = 0;
		while (i < pos_min)
		{
			rotate(stack);
			ft_printf("ra\n"); //TODO just a?
			i++;
		}
	}
	else
	{
		i = ft_stacksize(*stack);
		while (i > pos_min)
		{
			reverse_rotate(stack);
			ft_printf("rra\n"); //TODO just a?
			i--;
		}
	}
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

int	get_number_moves(t_stack *stack, int n)
{
	int moves;
	int	stack_size;
	int	f;
	int	s;

	stack_size = ft_stacksize(stack);
	moves = 1;
	while (moves < stack_size)
	{
		f = stack->number;
		s = stack->next->number;
		if ((s > f && n > f && n < s) || (s < f && (n > f || n < s)))
			break ;
		stack = stack->next;
		moves++;
	}
	if (moves == stack_size) //last position is the same as first position //TODO: hacer un if al principio?
		moves = 0;
	return (moves + 1); //push
}

int	which_pos_move(t_stack *a, t_stack *b)
{
	int moves;
	int	tmp_moves;
	int	size_b;
	int	i;
	int	pos;

	size_b = ft_stacksize(b);
	i = 1;
	moves = get_number_moves(b, a->number);
	pos = 0;
	while (i < size_b && a->next)
	{
		a = a->next;
		tmp_moves = get_number_moves(b, a->number);
		if (tmp_moves < moves)
		{
			pos = i;
			moves = tmp_moves;
		}
		i++;
	}
	return (pos);
}

/*
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
*/

int	get_number(t_stack *stack, int pos)
{
	int	i;

	i = 0;
	while (i < pos)
	{
		stack = stack->next;
		i++;
	}
	return (stack->number);
}

void	insert_number(t_stack **a, t_stack **b)
{
	int	pos;
	int	i;
	int	moves;
	int	n;

	pos = which_pos_move(*a, *b);
	n = get_number(*a, pos);
	moves = get_number_moves(*b, n);
	i = 0;
	while (i != pos && i != (moves - 1))
	{
		//rr
		rotate(a);
		rotate(b);
		ft_printf("rr\n");
		i++;
	}
	while (i != pos && i >= (moves - 1))
	{
		//ra
		rotate(a);
		ft_printf("ra\n");
		i++;
	}
	while (i >= pos && i < (moves - 1))
	{
		//rb
		rotate(b);
		ft_printf("rb\n");
		i++;
	}
	//push
	push(a, b);
	ft_printf("pb\n");
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
