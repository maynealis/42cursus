/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_seq.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmayne-p <cmayne-p@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 18:14:16 by cmayne-p          #+#    #+#             */
/*   Updated: 2025/02/08 19:13:46 by cmayne-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf_bonus.h"

t_seq	init_seq(void)
{
	t_seq	seq;

	seq.moves = 0;
	seq.rb = 0;
	seq.ra = 0;
	seq.rr = 0;
	seq.pb = 0;
	seq.pa = 0;
	seq.rra = 0;
	seq.rrb = 0;
	seq.rrr = 0;
	seq.sa = 0;
	seq.sb = 0;
	seq.number = -1; 
	seq.next_moves = 21475829;
	return (seq);
}

t_seq	opt_seq(t_seq seq)
{
	if (seq.rb > 0 && seq.ra > 0)
	{
		while (seq.ra > 0 && seq.rb > 0)
		{
			seq.rr ++;
			seq.ra--;
			seq.rb--;
		}
	}
	if (seq.rrb > 0 && seq.rra > 0) //TODO if is not necessary
	{
		while (seq.rra > 0 && seq.rrb > 0)
		{
			seq.rrr++;
			seq.rra--;
			seq.rrb--;
		}
	}
	return (seq);
}

void	aply_seq(t_stack **stack_a, t_stack **stack_b, t_seq best_move)
{
	//int	i;
	while (best_move.rrr-- > 0)
	{
		reverse_rotate(stack_a);
		reverse_rotate(stack_b);
		ft_printf("rrr\n");
	}
	while (best_move.rr-- > 0)
	{
		rotate(stack_a);
		rotate(stack_b);
		ft_printf("rr\n");
	}
	while (best_move.ra-- > 0)
		rotate_print(stack_a, 'a');
	while (best_move.rb-- > 0)
		rotate_print(stack_b, 'b');
	while (best_move.rra-- > 0)
		reverse_rotate_print(stack_a, 'a');
	while (best_move.rrb-- > 0)
		reverse_rotate_print(stack_b, 'b');
	if (best_move.sa)
		swap_print(stack_a, 'a');
	if (best_move.sb)
		swap_print(stack_b, 'b');
	if (best_move.pa)
		push_print(stack_b, stack_a, 'a');
	if (best_move.pb)
		push_print(stack_a, stack_b, 'b');
	
/*
	if (best_move.rb > 0 && best_move.ra > 0)
	{
		i = 0;
		while (i < best_move.rb && i < best_move.ra)
		{
			ft_printf("rr\n");
			rotate(stack_a);
			rotate(stack_b);
			i++;
		}
		while (i < best_move.rb)
		{
			ft_printf("rb\n");
			rotate(stack_b);
			i++;
		}
		while (i < best_move.ra)
		{
			ft_printf("ra\n");
			rotate(stack_a);
			i++;
		}
	}
	else if (best_move.rrb > 0 && best_move.rra > 0)
	{
		i = 0;
		while (i < best_move.rrb && i < best_move.rra)
		{
			ft_printf("rrr\n");
			reverse_rotate(stack_a);
			reverse_rotate(stack_b);
			i++;
		}
		while (i < best_move.rrb)
		{
			ft_printf("rrb\n");
			reverse_rotate(stack_b);
			i++;
		}
		while (i < best_move.rra)
		{
			ft_printf("ra\n");
			reverse_rotate(stack_a);
			i++;
		}
	}
	else
	{
		if (best_move.rb > 0)
		{
			i = 0;
			while (i < best_move.rb)
			{
				ft_printf("rb\n");
				rotate(stack_b);
				i++;
			}
		}
		if (best_move.ra > 0)
		{
			i = 0;
			while (i < best_move.ra)
			{
				ft_printf("ra\n");
				rotate(stack_a);
				i++;
			}
		}
		if (best_move.rra > 0)
		{
			i = 0;
			while (i < best_move.rra)
			{
				ft_printf("rra\n");
				reverse_rotate(stack_a);
				i++;
			}
		}
		if (best_move.rrb > 0)
		{
			i = 0;
			while (i < best_move.rrb)
			{
				ft_printf("rrb\n");
				reverse_rotate(stack_b);
				i++;
			}
		}
	}
	ft_printf("pb\n");
	push(stack_a, stack_b);
	*/
}
