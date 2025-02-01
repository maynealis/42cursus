#include "includes/push_swap.h"
#include "includes/ft_printf_bonus.h"

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

void	radix_bucket(t_stack **a, t_stack **b)
{
	//int i;
	while (*a && are_more_one_in_digit(*a, 6))
	{
		if ((((*a)->number >> 6) & 1) == 1)
		{
			ft_printf("pb\n");
			push(a, b);
		}
		else
		{
			ft_printf("ra\n");
			rotate(a);
		}
	}
	
	int d = 0;
	while (d < 6)
	{
		radix2(b, a, d);
		d++;
	}

	// i = 0;
	// while (i < 7)
	// {
	// 	radix(a, b, i);
	// 	i++;
	// }
	// i = 0;
	// while (i < 6)
	// {
	// 	radix(b, a, i);
	// 	i++;
	// }
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

void	radix_bucket2(t_stack **a, t_stack **b)
{
	while (*a && are_more_one_in_digit(*a, 5))
	{
		if ((((*a)->number >> 6) & 1) == 0 && (((*a)->number >> 5) & 1) == 1)
		{
			ft_printf("pb\n");
			push(a, b);
		}
		else
		{
			ft_printf("ra\n");
			rotate(a);
		}
	}
	
	int d = 0;
	while (d < 5)
	{
		radix2(b, a, d);
		d++;
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
	//ft_printf("current size of a %i\nand current size of b %i\n", ft_stacksize(*a), ft_stacksize(*b));
	while (*b)
	{
		ft_printf("pa\n");
		push(b, a);      
	}
}

void	radix2(t_stack **src, t_stack **dst, int d)
{
	int	size_src;
	int	i;
	int	count;

	count = 0;
	size_src = ft_stacksize(*src);
	i = 0;
	while (i < size_src)
	{
		if (((((*src)->number) >> d) & 1) == 0 && !is_sorted_rows(*src, size_src - i))
		{
			ft_printf("pb\n");
			push(src, dst);
			count++;
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
	while (*dst && count-- >= 0)
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

// int main(void)
// {
// 	ft_printf("bit menos %i\n", (1 >> 0) & 1);
// 	print_binary(100, 7);
// }