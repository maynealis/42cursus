#include <stdio.h>

/**
 * @brief This function returns the number of digits without the sign
 * 
 * @param number 
 * @return int 
 */
int		ft_numlen(int number)
{
	int	len;

	len = 0;
	while (number != 0)
	{
		len++;
		number /= 10;
	}
	return (len);
}

void	print_binary(int number)
{
	int	width;
	int	bit;

	width = 8;
	int i = width - 1;
	while (i >= 0)
	{
		bit = (number >> i) & 1;
		printf("%i", bit);
		i--;
	}
}

int	op_and(int a, int b)
{
	return (a & b);
}


int	main(void)
{

	printf("%i\n", ft_numlen(90001));
	print_binary(8);
}