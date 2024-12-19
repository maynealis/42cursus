#include "libft.h"
#include <stdio.h> // For printf
#include <ctype.h> // For standard library functions

int    show_error(char *name_ft, char c, int lib_val, int ori_val)
{
    printf("There is an error in `%s`.\n", name_ft);
    printf("The result of %c on your library is %d\n", c, lib_val);
    printf("and the correct result of %c on the standard library is %d\n", c, ori_val);
    printf("--------------------------------------------------------\n");
    return (1);
}

int main(void)
{
    int i;
    int err_count;

    err_count = 0;
    i = -1;
    while (++i < 296)
    {
        if (ft_isalpha(i) != isalpha(i))
            err_count += show_error("ft_isalpha", i, ft_isalpha(i), isalpha(i));
        if (ft_isdigit(i) != isdigit(i))
            err_count += show_error("ft_isdigit", i, ft_isdigit(i), isdigit(i));
        if (ft_isalnum(i) != isalnum(i))
            err_count += show_error("ft_isalnum", i, ft_isalnum(i), isalnum(i));
        if (ft_isascii(i) != isascii(i))
            err_count += show_error("ft_isascii", i, ft_isascii(i), isascii(i));
        if (ft_isprint(i) != isprint(i))
            err_count += show_error("ft_isprint", i, ft_isprint(i), isprint(i));
    }
    if (err_count == 0)
        printf("Passed all tests!");
    return (0);
}