#include "stack.h"
#include "ft_printf_bonus.h"

void	rotate(t_stack **stack)
{
	*stack = (*stack)->next;
}

void	rotate_print(t_stack **stack, char letter)
{
	rotate(stack);
	ft_printf("r%c\n", letter);
}

void	rotate_both_print(t_stack **stack_a, t_stack **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	ft_printf("rr\n");
}