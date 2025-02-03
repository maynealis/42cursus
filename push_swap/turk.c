/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmayne-p <cmayne-p@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 12:30:29 by cmayne-p          #+#    #+#             */
/*   Updated: 2025/02/03 18:02:24 by cmayne-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	best_move_rb(t_stack *a, t_stack *b)
{
	int	size_a;
	int	size_b;
	int	i;
	int	pos;
	int	moves;

	size_a = ft_stacksize(*a);
	size_b = ft_stacksize(*b);
	i = 0;
	pos = 0;
	moves = number_moves_rb(a->number, b);
	while (a && i < size_a && i < size_b)
	{
		if (number_moves_rb(a->number, b) < moves)
		{
			pos = i;
			moves = number_moves_rb(a->number, b);
		}
		i++;
		a = a->next;
	}
	//TODO while a a->previous
	return (pos);
}

int	number_moves_rb(int n, t_stack *b)
{
	int	last;
	int	first;
	int	moves;
	int	size_b;

	size_b = ft_stacksize(b);
	moves = 0;
	while (moves < size_b)
	{
		last = ft_stacklast(b)->number;
		first = b->number;
		if (last < first)
		{
			if (n > last)
				return (moves + 1); //pb
		}
		else if (last > first)
		{
			if (n < first)
				return (moves + 1); //pb
		}
		moves++;
		rotate(&b);
	}
}

int	number_moves_rrb(int n, t_stack *b)
{
	int	last;
	int	first;
	int	moves;
	int	size_b;

	size_b = ft_stacksize(b);
	moves = 0;
	while (moves < size_b)
	{
		last = ft_stacklast(b)->number;
		first = b->number;
		if (last < first)
		{
			if (n > last)
				return (moves + 1); //pb
		}
		else if (last > first)
		{
			if (n < first)
				return (moves + 1); //pb
		}
		moves++;
		reverse_rotate(&b);
	}
}
