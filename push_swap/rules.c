/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmayne-p <cmayne-p@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 21:00:08 by cmayne-p          #+#    #+#             */
/*   Updated: 2025/01/28 15:40:34 by cmayne-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include "includes/ft_printf.h"

void	swap(t_list *stack)
{
	void	*temp;

	if (stack->next == NULL)
		return ;
	temp = stack->content;
	stack->content = stack->next->content;
	stack->next->content = temp;
}

void	push(t_list **first, t_list **second)
{
	t_list *node;

	if (first == NULL || *first == NULL)
		return ;
	node = *first;
	*first = (*first)->next;
	node->next = NULL;
	ft_lstadd_front(second, node);
}

void	rotate(t_list **stack)
{
	t_list	*temp;
	t_list	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ; //minimum of two elements
	temp = *stack;
	*stack = (*stack)->next;
	last = ft_lstlast(*stack);
	temp->next = NULL;
	last->next = temp;
}

void	reverse_rotate(t_list **stack)
{
	t_list	*last;
	t_list	*second_to_last;

	if (!stack || !*stack || !(*stack)->next)
		return ; //minimum of two elements
	second_to_last = *stack;
	while (second_to_last->next->next)
		second_to_last = second_to_last->next;
	last = second_to_last->next;
	second_to_last->next = NULL;
	last->next = *stack;
	*stack = last;
}

void	print_stacks(t_list *a, t_list *b)
{
	t_list	*tmp_a;
	t_list	*tmp_b;

	tmp_a = a;
	tmp_b = b;
	while (tmp_a != NULL || tmp_b != NULL)
	{
		if (tmp_a)
		{
			ft_printf("% 11i", *(int *)tmp_a->content);
			tmp_a = tmp_a->next;
		}
		else
			ft_printf("           "); //TODO
		ft_printf("\t");
		if (tmp_b)
		{
			ft_printf("% 11i", *(int *)tmp_b->content);
			tmp_b = tmp_b->next;	
		}
		ft_printf("\n");
	}
}

t_list	*init_stack(int argc, char **argv)
{
	int		i;
	t_list	*stack_a;
	t_list	*new_node;
	int		*value;

	stack_a = NULL;
	value = NULL;
	i = argc - 1;
	while (i > 0)
	{
		value = (int *)malloc(sizeof(int));
		*value = ft_atoi(argv[i]);//TODO protect malloc
		new_node = ft_lstnew(value); //TODO proteger malloc
		ft_lstadd_front(&stack_a, new_node);
		//ft_lstadd_back(&stack_a, new_node);
		i--;
	}
	return (stack_a);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_b = NULL;
	stack_a = init_stack(argc, argv);
	print_stacks(stack_a, stack_b);

	ft_printf("SWAP\n");
	swap(stack_a);
	print_stacks(stack_a, stack_b);

	ft_printf("PUSH\n");
	push(&stack_a, &stack_b);
	print_stacks(stack_a, stack_b);

	ft_printf("ROTATE\n");
	rotate(&stack_a);
	print_stacks(stack_a, stack_b);
	
	ft_printf("REVERSE ROTATE\n");
	reverse_rotate(&stack_a);
	print_stacks(stack_a, stack_b);
	return (0);
}

