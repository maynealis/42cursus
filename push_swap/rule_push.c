#include "stack.h"
#include "ft_printf_bonus.h"

void	push(t_stack **src, t_stack **dst)
{
	t_stack	*node;

	if (!src || !dst || !*src)
		return ;
	node = ft_stackremove_front(src);
	ft_stackadd_front(dst, node);
}

void	push_print(t_stack **src, t_stack **dst, char letter)
{
	push(src, dst);
	ft_printf("p%c\n", letter);
}
