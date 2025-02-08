#include "includes/push_swap.h"
#include "includes/ft_printf_bonus.h"

#include <math.h>

// width is the num of bits to represent. I think the maximum for a int is 32?
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
		if (((stack->num >> d) & 1) == 1)
			return (1);
		stack = stack->next;
	}
	return (0);
}

char	are_more_one_in_digit_limit(t_stack *stack, int d, int max_rows)
{
	while (stack && --max_rows >= 0)
	{
		if (((stack->num >> d) & 1) == 1)
			return (1);
		stack = stack->next;
	}
	return (0);
}

char	are_more_zero_in_digit(t_stack *stack, int d)
{
	while (stack)
	{
		if (((stack->num >> d) & 1) == 0)
			return (1);
		stack = stack->next;
	}
	return (0);
}

char	are_only_zero_left_in_bit(t_stack *stack, int d, int max_rows)
{
	while (stack && --max_rows >= 0)
	{
		if (((stack->num >> d) & 1) == 1)
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
		if (((stack->num >> d) & 1) == 1)
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
		if (((stack->num >> d) & 1) == bit)
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
			if (((stack->num >> d) & 1) != bit)
				return (1);
			stack = stack->next;
		}
		found  = 0;
	}
	return (found); //0
}

int	ft_numlen(unsigned long n, char *base)
{
	size_t	len_base;
	int		len;

	if (n == 0)
		return (1);
	len_base = ft_strlen(base);
	len = 0;
	while (n != 0)
	{
		n /= len_base;
		len++;
	}
	return (len);
}

char	*ft_itoa_base(int n, char *base)
{
	char	*result;
	size_t	len_base;
	int		len_n;

	len_base = ft_strlen(base);
	len_n = ft_numlen(n, base);
	result = (char *)malloc((len_n + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);
	result[len_n] = '\0';
	if (n == 0)
		result[0] = base[0];
	while (n > 0)
	{
		result[--len_n] = base[n % len_base];
		n /= len_base;
	}
	return (result);
}
/*
void	radix_base3(t_stack **a, t_stack **b, int d)
{
	char	*n;
	int	size_a;
	int	i;

	size_a = ft_stacksize(*a);
	i = 0;
	while (i < size_a)
	{
		n = ft_itoa_base((*a)->num, "012");
		if (n[d] == '0')
		{
			ft_printf("pb\n");
			push(a, b);
			ft_printf("rb\n");
			rotate(b);
		}
		else if (n[d] == '1')
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
	while (ft_itoa_base((*b)->num, "012")[d] == '1')
	{
		ft_printf("pa\n");
		push(b, a);
	}
	while (*b)
	{
		ft_printf("rrb\n");
		reverse_rotate(b);
		ft_printf("pa\n");
		push(b, a);
	}
}
*/
void	radix(t_stack **a, t_stack **b, int d)
{
	int	size_a;
	int	i;

	size_a = ft_stacksize(*a);
	i = 0;
	while (i < size_a)
	{
		if (((((*a)->num) >> d) & 1) == 0)// && !is_sorted_rows(*a, size_a - i))
		{
			ft_printf("pb\n");
			push(a, b);
		}
		else if (((((*a)->num) >> d) & 1) == 1 && are_more_one_in_digit((*a)->next, d))
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
/*
void	radix_opt(t_stack **a, t_stack **b, int d) //it has a problem
{
	int	size_a;
	int	i;

	size_a = ft_stacksize(*a);
	i = 0;
	while (i < size_a)
	{
		if (((((*a)->num) >> d) & 1) == 0 && check_bit(*a, 1, d)) // && !are_only_zero_left_in_bit(*a, d, size_a - rotations))
		{
			ft_printf("pb\n");
			push(a, b);
		}
		else if (((((*a)->num) >> d) & 1) == 1 && check_bit(*a, 0, d))
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
*/
