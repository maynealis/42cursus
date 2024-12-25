#include "tests.h"
#include "../libft.h"

void	tests_fd(void)
{
	ft_putstr_fd("Hello world!", 1);
	ft_putendl_fd("Hello again!", 1);
	ft_putnbr_fd(-900077, 1);
}