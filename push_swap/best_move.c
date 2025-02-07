/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmayne-p <cmayne-p@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 14:54:01 by cmayne-p          #+#    #+#             */
/*   Updated: 2025/02/07 18:13:42 by cmayne-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_seq	get_min_moves_r_r(t_stack *stack_a, t_stack *stack_b)
{
	int		i;
	t_seq	seq;

	seq = init_seq();
	i = 0;
	seq.rb = moves_with_r(stack_a->num, stack_b);
	seq.moves = seq.rb;
	while (i < ft_stacksize(stack_a) && i < ft_stacksize(stack_b))
	{
		if (moves_with_r(stack_a->num, stack_b) < seq.moves && i < seq.moves)
		{
			seq.rb = moves_with_r(stack_a->num, stack_b);
			seq.ra = i;
			if (seq.rb >= seq.ra)
				seq.moves = seq.rb;
			else
				seq.moves = seq.ra;
		}
		if (i >= ft_stacksize(stack_a))
			break ;
		stack_a = stack_a->next;
		i++;
	}
	seq.pb = 1;
	return (seq);
}

t_seq	get_min_moves_r_rr(t_stack *stack_a, t_stack *stack_b)
{
	int		i;
	t_seq	seq;

	seq = init_seq();
	i = 0;
	seq.rrb = moves_with_rr(stack_a->num, stack_b);
	seq.moves = seq.rrb;
	while (i < ft_stacksize(stack_a) && i < ft_stacksize(stack_b))
	{
		if (moves_with_rr(stack_a->num, stack_b) < seq.moves && i < seq.moves)
		{
			seq.rrb = moves_with_rr(stack_a->num, stack_b);
			seq.ra = i;
			seq.moves = seq.rrb + seq.ra;
		}
		if (i >= ft_stacksize(stack_a))
			break ;
		stack_a = stack_a->next;
		i++;
	}
	seq.pb = 1;
	return (seq);
}

t_seq	get_min_moves_rr_r(t_stack *stack_a, t_stack *stack_b)
{
	int		i;
	t_seq	seq;

	seq = init_seq();
	i = 0;
	seq.rb = moves_with_r(stack_a->num, stack_b);
	seq.moves = seq.rb;
	while (i < ft_stacksize(stack_a) && i < ft_stacksize(stack_b))
	{
		if (moves_with_r(stack_a->num, stack_b) < seq.moves && i < seq.moves)
		{
			seq.rb = moves_with_r(stack_a->num, stack_b);
			seq.rra = i;
			seq.moves = seq.rb + seq.rra;
		}
		if (i >= ft_stacksize(stack_a))
			break ;
		stack_a = stack_a->prev;
		i++;
	}
	seq.pb = 1;
	return (seq);
}

t_seq	get_min_moves_rr_rr(t_stack *stack_a, t_stack *stack_b)
{
	int		i;
	t_seq	seq;

	seq = init_seq();
	i = 0;
	seq.rrb = moves_with_rr(stack_a->num, stack_b);
	seq.moves = seq.rrb;
	while (i < ft_stacksize(stack_a) && i < ft_stacksize(stack_b))
	{
		if (moves_with_rr(stack_a->num, stack_b) < seq.moves && i < seq.moves)
		{
			seq.rrb = moves_with_rr(stack_a->num, stack_b);
			seq.rra = i;
			if (seq.rrb >= seq.rra)
				seq.moves = seq.rrb;
			else
				seq.moves = seq.rra;
		}
		if (i >= ft_stacksize(stack_a))
			break ;
		stack_a = stack_a->prev;
		i++;
	}
	seq.pb = 1;
	return (seq);
}

t_seq	get_best_move(t_stack *stack_a, t_stack *stack_b)
{
	t_seq	best_seq;

	best_seq = get_min_moves_r_r(stack_a, stack_b);
	if (get_min_moves_r_rr(stack_a, stack_b).moves < best_seq.moves)
		best_seq = get_min_moves_r_rr(stack_a, stack_b);
	else if (get_min_moves_rr_r(stack_a, stack_b).moves < best_seq.moves)
		best_seq = get_min_moves_rr_r(stack_a, stack_b);
	else if (get_min_moves_rr_rr(stack_a, stack_b).moves < best_seq.moves)
		best_seq = get_min_moves_rr_rr(stack_a, stack_b);
	return (best_seq);
}
