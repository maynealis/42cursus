/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmayne-p <cmayne-p@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 11:04:48 by cmayne-p          #+#    #+#             */
/*   Updated: 2025/01/30 10:33:07 by cmayne-p         ###   ########.fr       */
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
void	free_stack(t_stack **stack);

// Functions to parse the arguments
char	is_valid_argument(char *arg, t_stack *a);

// Rules
void	swap(t_stack **stack);
void	push(t_stack **src, t_stack **dst);
void	rotate(t_stack **stack);
void	reverse_rotate(t_stack **stack);


char	is_sorted(t_stack *stack);
char	is_reverse_sorted(t_stack *stack);

#endif
