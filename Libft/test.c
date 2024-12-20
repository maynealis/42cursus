#include "libft.h"
#include <stdio.h> // For printf
#include <ctype.h> // isalpha, isalnum, isdigit, isascii, isprint
#include <string.h> // strlen, memset, bzero, memcpy, memmove

int    show_error(char *name_ft, int input, int lib_val, int ori_val)
{
    printf("There is an error in `%s`.\n", name_ft);
    printf("The result of %c on your library is %d\n", input, lib_val);
    printf("and the correct result of %c on the standard library is %d\n", input, ori_val);
    printf("--------------------------------------------------------\n");
    return (1);
}

int test_strlcpy()
{
    char    src[] = "Hello world!";
    char    ft_dest[13];
    char    or_dest[13];
    size_t  ft_res;
    size_t  or_res;
    size_t  size;
    size_t     i;

    size = 8;
    ft_res = ft_strlcpy(ft_dest, src, size);
    or_res = strlcpy(or_dest, src, size);
    if (ft_res == or_res)
    {
        i = -1;
        while (++i < (ft_res < size ? ft_res : size))
        {
            if (ft_dest[i] != or_dest[i])
            {
                printf("There is an error with ft_strlcpy.\n");
                printf("Your version of strlcpy function copy %zu bytes of %s into %s and returns %zu\n", size, src, ft_dest, ft_res);
                printf("The original strlcpy function copy %zu bytes of %s into %s and returns %zu\n", size, src, or_dest, or_res);
                printf("--------------------------------------------------------\n");
                return (1);
            }
        }
    }
    else
    {
        printf("There is an error with ft_strlcpy.\n");
        printf("Your version of strlcpy function copy %zu bytes of %s into %s and returns %zu\n", size, src, ft_dest, ft_res);
        printf("The original strlcpy function copy %zu bytes of %s into %s and returns %zu\n", size, src, or_dest, or_res);
        printf("--------------------------------------------------------\n");  
        return (1);
    }
    printf("ft_strlcpy OK.\n");
    return (0);
}

int main(void)
{
	int err_count;
	
	err_count = 0;
	
	// First functions
	int	i = -1;
    while (++i < 257)
    {
        if ((ft_isalpha(i) && !isalpha(i)) || (!ft_isalpha(i) && isalpha(i)))
            err_count += show_error("ft_isalpha", i, ft_isalpha(i), isalpha(i));
        if ((ft_isdigit(i) && !isdigit(i)) || (!ft_isdigit(i) && isdigit(i)))
            err_count += show_error("ft_isdigit", i, ft_isdigit(i), isdigit(i));
        if ((ft_isalnum(i) && !isalnum(i)) || (!ft_isalnum(i) && isalnum(i)))
		{
			printf("ascii es %d\n", i);
			printf("isalnum es %d\n", isalnum(i));
            err_count += show_error("ft_isalnum", i, ft_isalnum(i), isalnum(i));
        }
		if ((ft_isascii(i) && !isascii(i)) || (!ft_isascii(i) && isascii(i)))
            err_count += show_error("ft_isascii", i, ft_isascii(i), isascii(i));
        if ((ft_isprint(i) && !isprint(i)) || (!ft_isprint(i) && isprint(i)))
            err_count += show_error("ft_isprint", i, ft_isprint(i), isprint(i));
    }
	// Strlen tests
	char	s1[] = "hello world!";
	char	s2[] = "";
	char	s3[] = "              ";

	if (ft_strlen(s1) != strlen(s1) || ft_strlen(s2) != strlen(s2) || ft_strlen(s3) != strlen(s3))
	{
		printf("There is an error with `ft_strlen\n`");
    	printf("--------------------------------------------------------\n");
		err_count++;
	}
	
	// Memset tests
	char	buffer1[10];
	char	buffer2[10];
	char	buffer3[10] = "12345";
	char	buffer4[10] = "12345";
	char	buffer5[10] = "qwertyuio";
	char	buffer6[10] = "qwertyuio";

	ft_memset(buffer1, '7', 7);
	memset(buffer2, '7', 7);
	i = -1;
	while (++i < 7)
	{
		if (buffer1[i] != buffer2[i])
		{
			printf("There is an error with ft_memset.\nFailed test 1.\n");
			printf("Your ft_memset returns %s while the original returns %s\n", buffer1, buffer2);			
    		printf("--------------------------------------------------------\n");
			err_count++;
		}		
	}
	ft_memset(buffer3, '7', 2);
	memset(buffer4, '7', 2);
	i = -1;
	while (++i < 2)
	{
		if (buffer3[i] != buffer4[i])
		{
			printf("There is an error with ft_memset.\nFailed test 2.\n");
			printf("Your ft_memset returns %s while the original returns %s\n", buffer3, buffer4);			
    		printf("--------------------------------------------------------\n");
			err_count++;
		}		
	}
	ft_memset(buffer5, '\0', 9);
	memset(buffer6, '\0', 9);
	i = -1;
	while (++i < 10)
	{
		if (buffer5[i] != buffer6[i])
		{
			printf("There is an error with ft_memset.\nFailed test 3.\n");
			printf("Your ft_memset returns %s while the original returns %s\n", buffer5, buffer6);			
    		printf("--------------------------------------------------------\n");
			err_count++;
		}		
	}

	// Bzero tests
	ft_bzero(buffer1, 2);
	bzero(buffer2, 2);
	i = -1;
	while (++i < 7)
	{
		if (buffer1[i] != buffer2[i])
		{
			printf("There is an error with ft_memset.\nFailed test 1.\n");
			printf("Your ft_memset returns %s while the original returns %s\n", buffer1, buffer2);			
    		printf("--------------------------------------------------------\n");
			err_count++;
		}		
	}
	ft_bzero(buffer3, 10);
	bzero(buffer4, 10);
	i = -1;
	while (++i < 2)
	{
		if (buffer3[i] != buffer4[i])
		{
			printf("There is an error with ft_memset.\nFailed test 2.\n");
			printf("Your ft_memset returns %s while the original returns %s\n", buffer3, buffer4);			
    		printf("--------------------------------------------------------\n");
			err_count++;
		}		
	}
	ft_bzero(buffer5,  9);
	bzero(buffer6,  9);
	i = -1;
	while (++i < 10)
	{
		if (buffer5[i] != buffer6[i])
		{
			printf("There is an error with ft_memset.\nFailed test 3.\n");
			printf("Your ft_memset returns %s while the original returns %s\n", buffer5, buffer6);			
    		printf("--------------------------------------------------------\n");
			err_count++;
		}
	}

	// Memecpy tests
	const char source[] = "Hello world!";
	char	dest1[7];
	char	dest2[7];
	char	dest3[12];
	char	dest4[12];
	char	dest5[1];
	char	dest6[1];

	ft_memcpy(dest1, source, 5);
	memcpy(dest2, source, 5);
	i = -1;
	while (++i < 5)
	{
		if (dest1[i] != dest2[i])
		{
			printf("There is an error with ft_memcpy.\nFailed test 1.\n");
			printf("Your ft_memcpy returns %s while the original returns %s\n", dest1, dest2);			
    		printf("--------------------------------------------------------\n");
			err_count++;
		}
	}
	ft_memcpy(dest3, source, 12);
	memcpy(dest4, source, 12);
	i = -1;
	while (++i < 12)
	{
		if (dest3[i] != dest4[i])
		{
			printf("There is an error with ft_memcpy.\nFailed test 2.\n");
			printf("Your ft_memcpy returns %s while the original returns %s\n", dest3, dest4);			
    		printf("--------------------------------------------------------\n");
			err_count++;
		}
	}
	ft_memcpy(dest5, source, 1);
	memcpy(dest6, source, 1);
	i = -1;
	while (++i < 2)
	{
		if (dest5[i] != dest6[i])
		{
			printf("There is an error with ft_memcpy.\nFailed test 3.\n");
			printf("Your ft_memcpy returns %s while the original returns %s\n", dest5, dest6);			
    		printf("--------------------------------------------------------\n");
			err_count++;
		}
	}

	// Memmove tests
	//const char source[] = "Hello world!";
	char	dst1[7];
	char	dst2[7];
	char	dst3[12];
	char	dst4[12];
	char	dst5[1];
	char	dst6[1];

	ft_memmove(dst1, source, 5);
	memmove(dst2, source, 5);
	i = -1;
	while (++i < 5)
	{
		if (dst1[i] != dst2[i])
		{
			printf("There is an error with ft_memmove.\nFailed test 1.\n");
			printf("Your ft_memmove returns %s while the original returns %s\n", dst1, dst2);			
    		printf("--------------------------------------------------------\n");
			err_count++;
		}
	}

	ft_memmove(dst3, source, 12);
	memmove(dst4, source, 12);
	i = -1;
	while (++i < 12)
	{
		if (dst3[i] != dst4[i])
		{
			printf("There is an error with ft_memmove.\nFailed test 2.\n");
			printf("Your ft_memmove returns %s while the original returns %s\n", dst3, dst4);			
    		printf("--------------------------------------------------------\n");
			err_count++;
		}
	}
	ft_memmove(dst5, source, 1);
	memmove(dst6, source, 1);
	i = -1;
	while (++i < 2)
	{
		if (dst5[i] != dst6[i])
		{
			printf("There is an error with ft_memmove.\nFailed test 3.\n");
			printf("Your ft_memmove returns %s while the original returns %s\n", dst5, dst6);			
    		printf("--------------------------------------------------------\n");
			err_count++;
		}
	}

    err_count += test_strlcpy();

    if (err_count == 0)
        printf("Passed all tests!");
    return (0);
}
