/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmayne-p <cmayne-p@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 15:42:53 by cmayne-p          #+#    #+#             */
/*   Updated: 2025/02/09 16:57:33 by cmayne-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf_bonus.h"
#include "push_swap.h"

char	add_number(t_stack **a, int n)
{
	t_stack	*new;

	new = ft_stacknew(n);
	if (new == NULL)
		//free all stack
		return (0);
	ft_stackadd_back(a, new);
	return (1);
}

#include <stdio.h> //TODO: change to my printf
void	print_stacks(t_stack *a, t_stack *b)
{
	int	size_a;
	int	size_b;
	int	i;

	size_a = ft_stacksize(a);
	size_b = ft_stacksize(b);
	printf("---- a ----\t---- b ----\n");
	i = 0;
	while (i < size_a || i < size_b)
	{
		if (i < size_a)
		{
			//print_binary(a->number, 7);
			printf("% 11i", a->num);
			a = a->next;
		}
		else
			printf("           "); //TODO
		printf("\t");
		if (i < size_b)
		{
			//print_binary(a->number, 7);
			printf("% 11i", b->num);
			b = b->next;
		}
		printf("\n");
		i++;
	}
	printf("--------------------------\n");
}

char	print_error_message_and_clean(t_stack **stack_a, t_stack **stack_b)
{
	ft_putendl_fd("Error", 2);
	ft_stackfree(stack_a);
	ft_stackfree(stack_b);
	return (1);
}




int	main(int argc, char **argv)
{
	int		i;
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (0);
	i = 1;
	while (i < argc)
	{
		if (!is_valid_argument(argv[i], stack_a))
			return (print_error_message_and_clean(&stack_a, &stack_b));
		if (!add_number(&stack_a, ft_atoi(argv[i]))) //ha fallado el anadir el numero al stack
			return (print_error_message_and_clean(&stack_a, &stack_b));
		i++;
	}

	//print_stacks(stack_a, stack_b);
	//get_max_on_top(&stack_a, 'a');
	

	//print_stacks(stack_a, stack_b);


	// ALGORITHM DONE
	push(&stack_a, &stack_b);
	push(&stack_a, &stack_b);
	push(&stack_a, &stack_b);
	ft_printf("pb\n");
	ft_printf("pb\n");
	ft_printf("pb\n");

	sort_three_desc(&stack_b, 'b');

	while (ft_stacksize(stack_a) > 3 || !is_sorted(stack_a)) //TODO is sorted?
	{
		t_seq	seq = get_best_move(stack_a, stack_b);
		seq = opt_seq(seq);
		aply_seq(&stack_a, &stack_b, seq);
		//print_stacks(stack_a, stack_b);
	}

	sort_three_asc(&stack_a, 'a');
	get_min_on_top(&stack_a, 'a');

	//get_max_on_top(&stack_b, 'b');
	//print_stacks(stack_a, stack_b);
	while (stack_b)
	{
		if ((stack_a->prev->num < stack_a->num && stack_b->num < stack_a->num && stack_b->num > stack_a->prev->num)
			|| (stack_a->prev->num > stack_a->num && (stack_b->num < stack_a->num || stack_b->num > stack_a->prev->num)))
		{
			ft_printf("pa\n");
			push(&stack_b, &stack_a);
		}
		else
		{
			ft_printf("rra\n");
			reverse_rotate(&stack_a);
		}
	}
	//print_stacks(stack_a, stack_b);
	get_min_on_top(&stack_a, 'a');
	//print_stacks(stack_a, stack_b);
	

/*	
	// WORKING RADIX SORT
	int	d = 0;
	while (d < 9)
	{
		radix(&stack_a, &stack_b, d);
		d++;
	}
*/	
	//print_stacks(stack_a, stack_b);

	ft_stackfree(&stack_a);
	ft_stackfree(&stack_b);
	return (0);
}
