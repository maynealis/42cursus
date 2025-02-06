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

#include "ft_printf.h"
#include "push_swap.h"

int	get_max_num(t_stack *stack)
{
	t_stack	*first;
	int		max;

	first = stack;
	max = first->num;
	while (stack)
	{
		stack = stack->next;
		if (stack == first)
			break ;
		if (stack->num > max)
			max = stack->num;
	}
	return (max);
}

int	get_min_num(t_stack *stack)
{
	t_stack	*first;
	int		min;

	first = stack;
	min = first->num;
	while (stack)
	{
		stack = stack->next;
		if (stack == first)
			break ;
		if (stack->num <min)
			min = stack->num;
	}
	return (min);
}

int	get_pos_max_num(t_stack *stack)
{
	t_stack	*first;
	int		max;
	int		pos;
	int		i;

	first = stack;
	max = first->num;
	pos = 0;
	i = 0;
	while (stack)
	{
		stack = stack->next;
		if (stack == first)
			break ;
		if (stack->num > max)
		{
			max = stack->num;
			pos = i;
		}
		i++;
	}
	return (pos);
}

int	get_pos_min_num(t_stack *stack)
{
	t_stack	*first;
	int		min;
	int		pos;
	int		i;

	first = stack;
	min = first->num;
	pos = 0;
	i = 0;
	while (stack)
	{
		stack = stack->next;
		if (stack == first)
			break ;
		if (stack->num < min)
		{
			min = stack->num;
			pos = i;
		}
		i++;
	}
	return (pos);
}

char	is_reverse_sorted(t_stack *stack)
{
	int	max;
	int	size;
	int	i;

	max = get_max_num(stack);
	size = ft_stacksize(stack);
	while (stack->num != max)
		stack = stack->next;
	i = 0;
	while (i < size - 1)
	{
		if (stack->next->num  > stack->num)
			return (0);
		stack = stack->next;
		i++;
	}
	return (1);
}

char	is_sorted(t_stack *stack)
{
	int	min;
	int	size;
	int	i;

	min = get_min_num(stack);
	size = ft_stacksize(stack);
	while (stack->num != min)
		stack = stack->next;
	i = 0;
	while (i < size - 1)
	{
		if (stack->next->num  < stack->num)
			return (0);
		stack = stack->next;
		i++;
	}
	return (1);
}

void	sort_three_desc(t_stack **stack)
{
	if (!is_reverse_sorted(*stack))
	{
		//TODO: print el mov
		ft_printf("sb\n");
		swap(stack);
	}
}

void	sort_three_asc(t_stack **stack)
{
	if (!is_sorted(*stack))
	{
		ft_printf("sa\n");
		swap(stack);
	}
}

void	get_max_on_top(t_stack **stack, char stack_letter)
{
	int	pos;
	int	size;
	int	i;

	pos = get_pos_max_num(*stack);
	size = ft_stacksize(*stack);
	if (pos <= (size / 2))
	{
		i = 0;
		while (i <= pos)
		{
			ft_printf("r%c\n", stack_letter);
			rotate(stack); 
			i++;
		}
	}
	else
	{
		i = size - 1;
		while (i > pos)
		{
			ft_printf("rrb\n");
			ft_printf("rr%c\n", stack_letter);
			i--;
		}
	}
}

void	get_min_on_top(t_stack **stack, char stack_letter)
{
	int	pos;
	int	size;
	int	i;

	pos = get_pos_min_num(*stack);
	size = ft_stacksize(*stack);
	if (pos <= (size / 2))
	{
		i = 0;
		while (i < pos + 1)
		{
			ft_printf("r%c\n", stack_letter);
			rotate(stack); 
			i++;
		}
	}
	else
	{
		i = size - 1;
		while (i > pos)
		{
			ft_printf("rr%c\n", stack_letter);
			reverse_rotate(stack); 
			i--;
		}
	}
}

int	moves_with_rotate(int n, t_stack *stack)
{
	int	size;
	int	i;
	int	moves;

	i = 0;
	size = ft_stacksize(stack);
	moves = 0;
	while (i < size)
	{
		if (stack->prev->num < stack->num && (n > stack->num || n < stack->prev->num))
		{
			//push
			//moves += 1;
			break ;
		}
		else if (stack->prev->num > stack->num && n > stack->num && n < stack->prev->num)
		{
			//push
			//moves += 1;
			break ;
		}
		else
		{
			//rotate
			rotate(&stack);
			//stack = stack->next;
			moves+=1;
		}
		i++;
	}
	return (moves);
}

int	moves_with_reverse_rotate(int n, t_stack *stack)
{
	int	size;
	int	i;
	int	moves;

	i = 0;
	size = ft_stacksize(stack);
	moves = 0;
	while (i < size)
	{
		if (stack->prev->num < stack->num && (n > stack->num || n < stack->prev->num))
		{
			//push
			//moves += 1;
			break ;
		}
		else if (stack->prev->num > stack->num && n > stack->num && n < stack->prev->num)
		{
			//push
			//moves += 1;
			break ;
		}
		else
		{
			reverse_rotate(&stack);
			//stack = stack->prev;
			moves += 1;
		}
		i++;
	}
	return (moves);
}

t_seq	init_seq(void)
{
	t_seq	seq;

	seq.moves = 0;
	seq.rb = 0;
	seq.ra = 0;
	seq.pb = 0;
	seq.pa = 0;
	seq.rra = 0;
	seq.rrb = 0;
	seq.number = -1; 
	return (seq);
}

t_seq	get_min_moves_r_r(t_stack *stack_a, t_stack *stack_b)
{
	int	i;
	int	size_a;
	int	size_b;
	int	moves_b;
	int	moves_a;
	t_seq	seq;

	seq = init_seq();
	i = 0;
	size_a = ft_stacksize(stack_a);
	size_b = ft_stacksize(stack_b);
	moves_b = moves_with_rotate(stack_a->num, stack_b);
	moves_a = i;
	seq.moves = moves_b;
	seq.number = stack_a->num;
	while (i < size_a && i < size_b)
	{
		if(moves_with_rotate(stack_a->num, stack_b) < seq.moves && i < seq.moves)
		{
			moves_b = moves_with_rotate(stack_a->num, stack_b);
			moves_a = i;
			seq.number = stack_a->num;
			if (moves_b >= moves_a)
				seq.moves = moves_b;
			else
				seq.moves = moves_a;
		}
		if (i >= size_a)
			break ;
		stack_a = stack_a->next;
		i++;
	}
	if (moves_b >= moves_a)
		seq.moves = moves_b;
	else
		seq.moves = moves_a;
	seq.rb = moves_b;
	seq.ra = moves_a;
	seq.pb = 1;
	return (seq);
}

t_seq	get_min_moves_r_rr(t_stack *stack_a, t_stack *stack_b)
{
	int	i;
	int	size_a;
	int	size_b;
	int	moves_b;
	int	moves_a;
	t_seq	seq;

	seq = init_seq();
	i = 0;
	size_a = ft_stacksize(stack_a);
	size_b = ft_stacksize(stack_b);
	moves_b = moves_with_reverse_rotate(stack_a->num, stack_b);
	moves_a = i;
	seq.moves = moves_a + moves_b;
	seq.number = stack_a->num;
	while (i < size_a && i < size_b)
	{
		if(moves_with_reverse_rotate(stack_a->num, stack_b) + i < seq.moves)
		{
			moves_b = moves_with_reverse_rotate(stack_a->num, stack_b);
			moves_a = i;
			seq.number = stack_a->num;
			seq.moves = moves_a + moves_b;
		}
		if (i >= size_a)
			break ;
		stack_a = stack_a->next;
		i++;
	}
	seq.moves = moves_b + moves_a;
	seq.rrb = moves_b;
	seq.ra = moves_a;
	seq.pb = 1;
	return (seq);
}

t_seq	get_min_moves_rr_r(t_stack *stack_a, t_stack *stack_b)
{
	int	i;
	int	size_a;
	int	size_b;
	int	moves_b;
	int	moves_a;
	t_seq	seq;

	seq = init_seq();
	i = 0;
	size_a = ft_stacksize(stack_a);
	size_b = ft_stacksize(stack_b);
	moves_b = moves_with_rotate(stack_a->num, stack_b);
	moves_a = i;
	seq.moves = moves_a + moves_b;
	seq.number = stack_a->num;
	while (i < size_a && i < size_b)
	{
		if(moves_with_rotate(stack_a->num, stack_b) + i < seq.moves)
		{
			moves_b = moves_with_rotate(stack_a->num, stack_b);
			moves_a = i;
			seq.number = stack_a->num;
			seq.moves = moves_a + moves_b;
		}
		if (i >= size_a)
			break ;
		stack_a = stack_a->prev;
		i++;
	}
	seq.moves = moves_b + moves_a;
	seq.rb = moves_b;
	seq.pb = 1;
	seq.rra = moves_a;
	return (seq);
}

t_seq	get_min_moves_rr_rr(t_stack *stack_a, t_stack *stack_b)
{
	int	i;
	int	size_a;
	int	size_b;
	int	moves_b;
	int	moves_a;
	t_seq	seq;

	seq = init_seq();
	i = 0;
	size_a = ft_stacksize(stack_a);
	size_b = ft_stacksize(stack_b);
	moves_b = moves_with_reverse_rotate(stack_a->num, stack_b);
	moves_a = i;
	seq.moves = moves_b;
	seq.number = stack_a->num;
	while (i < size_a && i < size_b)
	{
		if(moves_with_reverse_rotate(stack_a->num, stack_b) < seq.moves && i < seq.moves)
		{
			moves_b = moves_with_reverse_rotate(stack_a->num, stack_b);
			moves_a = i;
			seq.number = stack_a->num;
			if (moves_b >= moves_a)
				seq.moves = moves_b;
			else
				seq.moves = moves_a;
		}
		if (i >= size_a)
			break ;
		stack_a = stack_a->prev;
		i++;
	}
	if (moves_b >= moves_a)
		seq.moves = moves_b;
	else
		seq.moves = moves_a;
	seq.pb = 1;
	seq.rrb = moves_b;
	seq.rra = moves_a;
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

void	aply_seq(t_stack **stack_a, t_stack **stack_b, t_seq best_move)
{
	int	i;

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
}