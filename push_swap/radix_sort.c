#include "includes/push_swap.h"
#include "includes/ft_printf_bonus.h"

#include <math.h>

// width is the number of bits to represent. I think the maximum for a int is 32?
void	print_binary(int num, int width)
{
	int	bit;
	int	i;

	i = width - 1;
	while (i >= 0)
	{
		bit = (num >> i) & 1;
		ft_printf("%i", bit);
		i--;
	}
}

char	are_more_one_in_digit(t_stack *stack, int d)
{
	while (stack)
	{
		if (((stack->number >> d) & 1) == 1)
			return (1);
		stack = stack->next;
	}
	return (0);
}

char	are_more_one_in_digit_limit(t_stack *stack, int d, int max_rows)
{
	while (stack && --max_rows >= 0)
	{
		if (((stack->number >> d) & 1) == 1)
			return (1);
		stack = stack->next;
	}
	return (0);
}

char	are_more_zero_in_digit(t_stack *stack, int d)
{
	while (stack)
	{
		if (((stack->number >> d) & 1) == 0)
			return (1);
		stack = stack->next;
	}
	return (0);
}

char	are_only_zero_left_in_bit(t_stack *stack, int d, int max_rows)
{
	while (stack && --max_rows >= 0)
	{
		if (((stack->number >> d) & 1) == 1)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	pos_next_one(t_stack *stack, int d)
{
	int	pos;

	pos = 0;
	while (stack)
	{
		if (((stack->number >> d) & 1) == 1)
			return (pos);
		pos++;
		stack = stack->next;
	}
	return (-1); // not found
}

char	check_bit(t_stack *stack, int bit, int d)
{
	char	found;

	found = 0;
	while (stack)
	{
		if (((stack->number >> d) & 1) == bit)
		{
			found = 1;
			break ;
		}
		stack = stack->next;
	}
	if (found)
	{
		while (stack)
		{
			if (((stack->number >> d) & 1) != bit)
				return (1);
			stack = stack->next;
		}
		found  = 0;
	}
	return (found); //0
}



void	radix_bucket_between(t_stack **a, t_stack **b, int pivot)
{
	int	size_a;
	int	i;

	size_a = ft_stacksize(*a);
	i = 0;
	while (i < size_a) //TODO: and also check if I have to continue..
	{
		if ((*a)->number > pivot)
		{
			ft_printf("pb\n");
			push(a, b);
		}
		else
		{
			ft_printf("ra\n");
			rotate(a);
		}
		i++;
	}
	
	// int d = 0;
	// while (d < desp)
	// {
	// 	radix2(b, a, d, desp);
	// 	d++;
	// }
}

void	radix_base4(t_stack **a, t_stack **b, int d)
{
	int	size_a;
	int	i;

	size_a = ft_stacksize(*a);
	i = 0;
	// pass 0 and 1 to b
	while (i < size_a)
	{
		if (((*a)->number / (1 << (2 * d)) % 4) == 0 || ((*a)->number / (1 << (2 * d)) % 4) == 1)
		{
			ft_printf("pb\n");
			push(a, b);
		}
		else
		{
			ft_printf("ra\n");
			rotate(a);
		}
		i++;
	}

	//order 3 and 4
	size_a = ft_stacksize(*a);
	i = 0;
	while (i < size_a)
	{
		if (((*a)->number / (1 << (2 * d)) % 4) == 3)
		{
			ft_printf("pb\n");
			push(a, b);
		}
		else
		{
			ft_printf("ra\n");
			rotate(a);
		}
		i++;
	}
	while (((*b)->number / (1 << (2 * d)) % 4) == 3)
	{
		ft_printf("pa\n");
		push(b, a);
	}
	//order 0 and 1 
	int	size_b = ft_stacksize(*b);

	i = 0;
	while (i < size_b)
	{
		if (((*a)->number / (1 << (2 * d)) % 4) == 1)
		{
			ft_printf("pa\n");
			push(b, a);
		}
		else
		{
			ft_printf("rb");
			rotate(b);
		}
		i++;
	}
	// put 00 back
	while  (*b)
	{
		ft_printf("pa\n");
		push(b, a);
	}
}

void	radix(t_stack **a, t_stack **b, int d)
{
	int	size_a;
	int	i;

	size_a = ft_stacksize(*a);
	i = 0;
	while (i < size_a)
	{
		if (((((*a)->number) >> d) & 1) == 0 && !is_sorted_rows(*a, size_a - i))
		{
			ft_printf("pb\n");
			push(a, b);
		}
		else if (((((*a)->number) >> d) & 1) == 1 && are_more_one_in_digit((*a)->next, d))
		{
			ft_printf("ra\n");
			rotate(a);
		}
		else
			ft_printf("");
		i++;
	}
	while (*b)
	{
		ft_printf("pa\n");
		push(b, a);      
	}
}

void	radix_opt(t_stack **a, t_stack **b, int d) //it has a problem
{
	int	size_a;
	int	i;

	size_a = ft_stacksize(*a);
	i = 0;
	while (i < size_a)
	{
		if (((((*a)->number) >> d) & 1) == 0 && check_bit(*a, 1, d)) // && !are_only_zero_left_in_bit(*a, d, size_a - rotations))
		{
			ft_printf("pb\n");
			push(a, b);
		}
		else if (((((*a)->number) >> d) & 1) == 1 && check_bit(*a, 0, d))
		{
			ft_printf("ra\n");
			rotate(a);
		}
		else
			ft_printf("");
		i++;
	}
	while (*b && are_more_one_in_digit((*b), d + 1))
	{
		ft_printf("pa\n");
		push(b, a);      
	}
}

void	radix_optimize(t_stack **a, t_stack **b, int d)
{
	int	size_a;
	int	i;

	size_a = ft_stacksize(*a);
	i = 0;
	while (i < size_a)
	{
		if (((((*a)->number) >> d) & 1) == 0 && !is_sorted_rows(*a, size_a - i))
		{
			ft_printf("pb\n");
			push(a, b);
		}
		else if (((((*a)->number) >> d) & 1) == 1 && are_more_one_in_digit((*a)->next, d))
		{
			ft_printf("ra\n");
			rotate(a);
		}
		else
			ft_printf("");
		i++;
	}
	while (*b && are_more_one_in_digit(*b, d - 1))
	{
		if (d > 0 && ((*b)->number >> (d - 1) & 1) == 0)
		{
			ft_printf("rb\n");
			rotate(b);      
		}
		ft_printf("pa\n");
		push(b, a);      
	}
}


void	radix2(t_stack **src, t_stack **dst, int d, int pivot)
{
	int	size_src;
	int	i;

	size_src = ft_stacksize(*src);
	i = 0;
	while (i < size_src)
	{
		if (((((*src)->number) >> d) & 1) == 0 && !is_sorted_rows(*src, size_src - i))
		{
			ft_printf("pb\n");
			push(src, dst);
		}
		else if (((((*src)->number) >> d) & 1) == 1 && are_more_one_in_digit((*src)->next, d))
		{
			ft_printf("ra\n");
			rotate(src);
		}
		else
			ft_printf("");
		i++;
	}
	while (*dst && (*dst)->number > pivot)
	{
		ft_printf("pa\n");
		push(dst, src);      
	}
	//ft_printf("current size of a %i\nand current size of b %i\n", ft_stacksize(*a), ft_stacksize(*b));
	// while (*dst)
	// {
	// 	ft_printf("pa\n");
	// 	push(dst, src);      
	// }
}

void	radix_down(t_stack **src, t_stack **dst, int d, int pivot)
{
	int	size_src;
	int	i;

	size_src = ft_stacksize(*src);
	i = 0;
	while (i < size_src)
	{
		if (((((*src)->number) >> d) & 1) == 0 && !is_sorted_rows(*src, size_src - i))
		{
			ft_printf("pb\n");
			push(src, dst);
		}
		else if (((((*src)->number) >> d) & 1) == 1 && are_more_one_in_digit((*src)->next, d))
		{
			ft_printf("ra\n");
			rotate(src);
		}
		else
			ft_printf("");
		i++;
	}
	while (*dst && (*dst)->number < pivot)
	{
		ft_printf("pa\n");
		push(dst, src);      
	}
}

void	radix_limit(t_stack **src, t_stack **dst, int d, int max, int min)
{
	int	size_src;
	int	i;
	int	count_rotate;

	count_rotate = 0;
	size_src = ft_stacksize(*src);
	i = 0;
	while (i < size_src && (*src)->number < max)
	{
		if (((((*src)->number) >> d) & 1) == 0 && !is_sorted_rows(*src, size_src - i))
		{
			ft_printf("pb\n");
			push(src, dst);
		}
		else if (((((*src)->number) >> d) & 1) == 1 && are_more_one_in_digit((*src)->next, d))
		{
			ft_printf("ra\n");
			rotate(src);
			count_rotate++;
		}
		else
			ft_printf("");
		i++;
	}
	while (count_rotate > 0)
	{
		ft_printf("rra\n");
		reverse_rotate(src);
		count_rotate--;
	}
	while (*dst && (*dst)->number > min)
	{
		ft_printf("pa\n");
		push(dst, src);      
	}
}

// int main(void)
// {
// 	ft_printf("bit menos %i\n", (1 >> 0) & 1);
// 	print_binary(100, 7);
// }
