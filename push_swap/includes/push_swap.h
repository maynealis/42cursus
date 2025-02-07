/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmayne-p <cmayne-p@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 11:04:48 by cmayne-p          #+#    #+#             */
/*   Updated: 2025/02/07 14:55:59 by cmayne-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h> // for malloc

// double linked list
typedef struct s_stack
{
	int				num;
	//int			normal_n;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

typedef struct s_seq
{
	int	moves;
	int	rb;
	int	ra;
	int	pb;
	int	rra;
	int	rrb;
	int	pa;
	int	number;
}	t_seq;


// Auxiliar function to manage the t_stack
int		ft_stacksize(t_stack *stack);
t_stack	*ft_stacknew(int number);
void	ft_stackadd_back(t_stack **stack, t_stack *new);
void	ft_stackadd_front(t_stack **stack, t_stack *new);
t_stack	*ft_stackremove_front(t_stack **stack);
void	ft_stackfree(t_stack **stack);

// Functions to parse the arguments
char	is_valid_argument(char *arg, t_stack *a);

// Rules
void	push(t_stack **src, t_stack **dst);
void	rotate(t_stack **stack);
void	reverse_rotate(t_stack **stack);
void	swap(t_stack **stack);
void	push_print(t_stack **src, t_stack **dst, char letter);
void	rotate_print(t_stack **stack, char letter);
void	reverse_rotate_print(t_stack **stack, char letter);
void	swap_print(t_stack **stack, char letter);



// Algorithm basics
void	sort_three_desc(t_stack **stack);
void	sort_three_asc(t_stack **stack);

void	get_max_on_top(t_stack **stack, char stack_letter);
void	get_min_on_top(t_stack **stack, char stack_letter);


// Algorithm turk
t_seq	get_best_move(t_stack *stack_a, t_stack *stack_b);
void	aply_seq(t_stack **stack_a, t_stack **stack_b, t_seq best_move);


#endif

/* ##################### OLD #####################
// Struct t_stack
// typedef struct s_stack
// {
// 	int				number;
// 	struct s_stack	*next;
// }	t_stack;

// Auxiliar function to manage the t_stack
// t_stack	*ft_stacknew(int number);
// t_stack	*ft_stacklast(t_stack *stack);
// void	ft_stackadd_back(t_stack **stack, t_stack *new);
// void	ft_stackadd_front(t_stack **stack, t_stack *new);
// int		ft_stacksize(t_stack *stack);
// void	free_stack(t_stack **stack);

// Functions to parse the arguments
char	is_valid_argument(char *arg, t_stack *a);

// To print for me
void	print_stacks(t_stack *a, t_stack *b);
void	print_binary(int num, int width);


// Rules
// void	swap(t_stack **stack);
// void	push(t_stack **src, t_stack **dst);
// void	rotate(t_stack **stack);
// void	reverse_rotate(t_stack **stack);

// Algorithm
// char	is_sorted(t_stack *stack);
// char	is_reverse_sorted(t_stack *stack);
// void	sort_stack_three(t_stack **stack);
// //int		get_number_of_moves(t_stack *stack, int n);
// int		get_number_moves(t_stack *stack, int n);
// int		which_pos_move(t_stack *a, t_stack *b);
// int		get_number(t_stack *stack, int pos);
// void	insert_number(t_stack **a, t_stack **b);
// void	set_stack_ordered(t_stack **stack);

// // Radix
// void	radix(t_stack **a, t_stack **b, int d);
// void	radix_opt(t_stack **a, t_stack **b, int d);
// void	radix_base3(t_stack **a, t_stack **b, int d);
*/


