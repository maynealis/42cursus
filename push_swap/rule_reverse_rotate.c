#include "stack.h"
#include "ft_printf_bonus.h"

void	reverse_rotate(t_stack **stack)
{
	*stack = (*stack)->prev;
}

void	reverse_rotate_print(t_stack **stack, char letter)
{
	reverse_rotate(stack);
	ft_printf("rr%c\n", letter);
}

void	reverse_rotate_both_print(t_stack **stack_a, t_stack **stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	ft_printf("rrr\n");
}