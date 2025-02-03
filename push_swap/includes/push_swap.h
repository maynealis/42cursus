/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmayne-p <cmayne-p@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 11:04:48 by cmayne-p          #+#    #+#             */
/*   Updated: 2025/01/30 14:55:55 by cmayne-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h> // for malloc

// Struct t_stack
typedef struct s_stack
{
	int				number;
	struct s_stack	*next;
}	t_stack;

// Auxiliar function to manage the t_stack
t_stack	*ft_stacknew(int number);
t_stack	*ft_stacklast(t_stack *stack);
void	ft_stackadd_back(t_stack **stack, t_stack *new);
void	ft_stackadd_front(t_stack **stack, t_stack *new);
int		ft_stacksize(t_stack *stack);
void	free_stack(t_stack **stack);

// Functions to parse the arguments
char	is_valid_argument(char *arg, t_stack *a);

// To print for me
void	print_stacks(t_stack *a, t_stack *b);
void	print_binary(int num, int width);


// Rules
void	swap(t_stack **stack);
void	push(t_stack **src, t_stack **dst);
void	rotate(t_stack **stack);
void	reverse_rotate(t_stack **stack);

// Algorithm
char	is_sorted(t_stack *stack);
char	is_reverse_sorted(t_stack *stack);
void	sort_stack_three(t_stack **stack);
//int		get_number_of_moves(t_stack *stack, int n);
int		get_number_moves(t_stack *stack, int n);
int		which_pos_move(t_stack *a, t_stack *b);
int		get_number(t_stack *stack, int pos);
void	insert_number(t_stack **a, t_stack **b);
void	set_stack_ordered(t_stack **stack);

// Radix
void	radix(t_stack **a, t_stack **b, int d);
void	radix_opt(t_stack **a, t_stack **b, int d);

void	radix_base4(t_stack **a, t_stack **b, int d);
void radix_base4_gpt(t_stack **a, t_stack **b, int d);


void	radix_optimize(t_stack **a, t_stack **b, int d);
void	radix_gpt(t_stack **a, t_stack **b, int max_bits);

void	radix_bucket(t_stack **a, t_stack **b);
void	radix2(t_stack **a, t_stack **b, int d, int pivot);
void	radix_down(t_stack **src, t_stack **dst, int d, int pivot);
void	radix_limit(t_stack **src, t_stack **dst, int d, int max, int min);
void	radix_bucket2(t_stack **a, t_stack **b);
void	radix_bucket_between(t_stack **a, t_stack **b, int pivot);


char	is_sorted_rows(t_stack *stack, int rows_to_check);



#endif
