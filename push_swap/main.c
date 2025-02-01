/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmayne-p <cmayne-p@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 15:42:53 by cmayne-p          #+#    #+#             */
/*   Updated: 2025/01/30 15:58:44 by cmayne-p         ###   ########.fr       */
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
	printf("---- a ----\t---- b ----\n");
	while (a != NULL || b != NULL)
	{
		if (a)
		{
			printf("% 11i", a->number);
			a = a->next;
		}
		else
			printf("           "); //TODO
		printf("\t");
		if (b)
		{
			printf("% 11i", b->number);
			b = b->next;
		}
		printf("\n");
	}
	printf("--------------------------\n");
}

char	print_error_message_and_clean(t_stack **stack_a, t_stack **stack_b)
{
	ft_putendl_fd("Error", 2);
	free_stack(stack_a);
	free_stack(stack_b);
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


	// d = 0;
	// while (d < 5)
	// {
	// 	radix2(&stack_b, &stack_a, d, 31);
	// 	d++;
	// }
	// print_stacks(stack_a, stack_b);



	int	d = 0;
	while (d < 7)
	{
		//ft_printf("---------------------------------started bit %d\n", d);
		radix(&stack_a, &stack_b, d);
		

		// if (is_sorted(stack_a))
		// 	ft_printf("a is sorted in d %i -----------------------------------\n", d);
		// if (is_sorted(stack_b))
		// 	ft_printf("b is sorted in d %i -----------------------------------\n", d);

		d++;
	}
	
	//print_stacks(stack_a, stack_b);
	// d = 0;
	// while (d < 6)
	// {
	// 	radix2(&stack_b, &stack_a, d);
	// 	d++;
	// }
	//print_stacks(stack_a, stack_b);
	// while (stack_b)
	// {
	// 	ft_printf("pa\n");
	// 	ft_printf("ra\n");
	// 	push(&stack_b, &stack_a);
	// 	rotate(&stack_a);
	// }
	//print_stacks(stack_a, stack_b);
	/*
	// ALGORITHM TURK?
	if (ft_stacksize(stack_a) <= 3)
	{
		sort_stack_three(&stack_a);
		print_stacks(stack_a, stack_b);

		return (0);
	}
	else if (ft_stacksize(stack_a) <= 6)
	{
		ft_printf("pb\n");
		ft_printf("pb\n");
		ft_printf("pb\n");
		push(&stack_a, &stack_b);
		push(&stack_a, &stack_b);
		push(&stack_a, &stack_b);
		sort_stack_three(&stack_a);
		sort_stack_three(&stack_b);
		while (ft_stacksize(stack_b) > 0)
			insert_number(&stack_b, &stack_a);
		set_stack_ordered(&stack_a);
		print_stacks(stack_a, stack_b);
		
		return (0);
	}

	ft_printf("pb\n");
	ft_printf("pb\n");
	ft_printf("pb\n");
	push(&stack_a, &stack_b);
	push(&stack_a, &stack_b);
	push(&stack_a, &stack_b);
	sort_stack_three(&stack_b);

	//print_stacks(stack_a, stack_b);

	while (ft_stacksize(stack_a) > 3)
	{
		insert_number(&stack_a, &stack_b);
		//print_stacks(stack_a, stack_b);
	}
	sort_stack_three(&stack_a);
	//print_stacks(stack_a, stack_b);
	while (ft_stacksize(stack_b) > 0)
	{
		insert_number(&stack_b, &stack_a);
	//	print_stacks(stack_a, stack_b);
	}
	set_stack_ordered(&stack_a);
	//print_stacks(stack_a, stack_b);
	*/


	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
