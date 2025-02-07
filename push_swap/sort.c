/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmayne-p <cmayne-p@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 12:48:33 by cmayne-p          #+#    #+#             */
/*   Updated: 2025/02/07 13:36:01 by cmayne-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three_desc(t_stack **stack, char stack_letter)
{
	if (!is_reverse_sorted(*stack))
	{
		ft_printf("s%c\n", stack_letter);
		swap(stack);
	}
}

void	sort_three_asc(t_stack **stack, char stack_letter)
{
	if (!is_sorted(*stack))
	{
		ft_printf("s%c\n", stack_letter);
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
	if (pos == 0)
		return ;
	if (pos <= (size / 2))
	{
		i = 0;
		while (i++ < pos)
		{
			rotate_print(stack, stack_letter);
			//ft_printf("r%c\n", stack_letter);
			//rotate(stack); 
			//i++;
		}
	}
	else
	{
		i = size;
		while (i-- > pos)
		{
			reverse_rotate_print(stack, stack_letter);
			//ft_printf("rr%c\n", stack_letter);
			//reverse_rotate(stack);
			//i--;
		}
	}
}

void	get_min_on_top(t_stack **stack, char stack_letter)
{
	int	pos;
	int	size;
	int	i;

	pos = get_pos_max_num(*stack);
	size = ft_stacksize(*stack);
	if (pos == 0)
		return ;
	if (pos <= (size / 2))
	{
		i = 0;
		while (i++ < pos)
		{
			rotate_print(stack, stack_letter);
			//ft_printf("r%c\n", stack_letter);
			//rotate(stack); 
			//i++;
		}
	}
	else
	{
		i = size;
		while (i-- > pos)
		{
			reverse_rotate_print(stack, stack_letter);
			//ft_printf("rr%c\n", stack_letter);
			//reverse_rotate(stack);
			//i--;
		}
	}
}
