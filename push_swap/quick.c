#include "push_swap.h"

typedef struct s_bucket
{
	t_stack	*stack; //pointer to the stack where it is
	int		size; //number of nums it contains
	int		pivot_big;
	int		pivot_mid;

}	t_bucket;


void	divide_in_three(t_bucket bucket)
{
	if (bucket.size <= 4) // TODO: calibrate this
	{
		// sort 4 depending on where it is
	}

	// create three buckets
	t_bucket	big;
	t_bucket	mid;
	t_bucket	low;
	int	i = 0;
	while (i < bucket.size)
	{
		if (bucket.stack->number >= bucket.pivot_big)
		// put in top a
	}

	divide_in_three(big);
	divide_in_three(mid);
	divide_in_three(low);
}

