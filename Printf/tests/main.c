/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmayne-p <cmayne-p@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 14:26:17 by cmayne-p          #+#    #+#             */
/*   Updated: 2025/01/22 16:04:10 by cmayne-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_bonus.h"
#include <stdio.h>
#include <limits.h>
#include <libft.h>

#ifndef BONUS
# define BONUS 0
#endif

int	main(void)
{	
	int	my_result;
	int	or_result;

	// Without arguments
	printf("###############################################################\n");
	printf("###################### WITHOUT ARGUMENTS ######################\n");
	printf("###############################################################\n");
	my_result = ft_printf("	Simple print\n");
	or_result = printf("	Simple print\n");
	printf("\nresult: %d - %d\n", my_result, or_result);
	printf("###############################################################\n");

	// With single character substitution
	printf("######################### CHARACTER  ##########################\n");
	printf("###############################################################\n");
	my_result = ft_printf("char: %c", 'c');
	printf("\n");
	or_result = printf("char: %c", 'c');
	printf("\nresult: %d - %d\n", my_result, or_result);
	printf("---------------------------------------------------------------\n");
	my_result = ft_printf("%c", '\n');
	or_result = printf("%c", '\n');
	printf("\nresult: %d - %d\n", my_result, or_result);
	printf("###############################################################\n");

	// With multiple character substitution
	printf("#################### MULTIPLE CHARACTER #######################\n");
	printf("###############################################################\n");
	my_result = ft_printf("char1: %c, char2: %c, char3: %c\n", '\t', '%', 63);
	or_result = printf("char1: %c, char2: %c, char3: %c\n", '\t', '%', 63);
	printf("\nresult: %d - %d\n", my_result, or_result);
	printf("###############################################################\n");

	// With single string substitution
	printf("#################### STRING SUBSTITUTION ######################\n");
	printf("###############################################################\n");
	my_result = ft_printf("%ssome random text\n", "at the beginning-");
	or_result = printf("%ssome random text\n", "at the beginning-");
	printf("\nresult: %d - %d\n", my_result, or_result);
	printf("---------------------------------------------------------------\n");
	my_result = ft_printf("I know %s nothing\n", "-middle-");
	or_result = printf("I know %s nothing\n", "-middle-");
	printf("\nresult: %d - %d\n", my_result, or_result);
	printf("---------------------------------------------------------------\n");
	my_result = ft_printf("At the %s", "-end\n");
	or_result = printf("At the %s", "-end\n");
	printf("\nresult: %d - %d\n", my_result, or_result);
	printf("---------------------------------------------------------------\n");

	// With multiple string substitution
	char	*str1 = "Hello";
	char	*str2 = NULL;
	char	c1 = 'p';
	my_result = ft_printf("string1: %s, null+string1: %s%s, char: %c\n", str1, str2, str1, c1);
	or_result = ft_printf("string1: %s, null+string1: %s%s, char: %c\n", str1, str2, str1, c1);
	printf("\nresult: %d - %d\n", my_result, or_result);
	printf("###############################################################\n");

	// With percentage
	printf("####################### %% SUBSTITUTION ########################\n");
	printf("###############################################################\n");
	my_result = ft_printf("This is a percentage: %%\n");
	or_result = printf("This is a percentage: %%\n");
	printf("\nresult: %d - %d\n", my_result, or_result);
	printf("###############################################################\n");
	
	// Pointer
	printf("########################### POINTER ###########################\n");
	printf("###############################################################\n");
	int	arr[] = {1, 2, 3};
	my_result = ft_printf("pointer char: %p, null pointer: %p, pointer int: %p\n", str1, str2, arr);
	or_result = printf("pointer char: %p, null pointer: %p, pointer int: %p\n", str1, str2, arr);
	printf("\nresult: %d - %d\n", my_result, or_result);
	printf("---------------------------------------------------------------\n");
	int	*arr2d = &arr[0];
	my_result = ft_printf("pointer2d: %p\n", arr2d);
	or_result = printf("pointer2d: %p\n", arr2d);
	printf("\nresult: %d - %d\n", my_result, or_result);
	printf("---------------------------------------------------------------\n");
	int	*arr1 = 0;
	my_result = ft_printf("pointer a 0: %p	pointer a 0: %p\n", arr1, arr1);
	or_result = printf("pointer a 0: %p	pointer a 0: %p\n", arr1, arr1);
	printf("\nresult: %d - %d\n", my_result, or_result);
	printf("###############################################################\n");

	// Hexa
	printf("############################ HEXA #############################\n");
	printf("###############################################################\n");
	my_result = ft_printf("hexa: %x\n", 0);
	or_result = printf("hexa: %x\n", 0);
	printf("\nresult: %d - %d\n", my_result, or_result);
	printf("---------------------------------------------------------------\n");
	my_result = ft_printf("hexa: %x	HEXA: %X\n", 2564, 2564);
	or_result = printf("hexa: %x	HEXA: %X\n", 2564, 2564);
	printf("\nresult: %d - %d\n", my_result, or_result);
	printf("---------------------------------------------------------------\n");
	my_result = ft_printf("min: %x	max: %x\n", 1, -1);
	or_result = printf("min: %x	max: %x\n", 1, -1);
	printf("\nresult: %d - %d\n", my_result, or_result);
	printf("###############################################################\n");

	// Integers
	printf("########################### DECIMAL ###########################\n");
	printf("###############################################################\n");
	int	n1 = 0;
	int	min = 0x80000000;
	int	max = 0x7fffffff;
	my_result = ft_printf("d: %d	i: %i\n", n1, n1);
	or_result = printf("d: %d	i: %i\n", n1, n1);
	printf("\nresult: %d - %d\n", my_result, or_result);
	printf("---------------------------------------------------------------\n");
	my_result = ft_printf("min d: %d	min i: %i\n", min, min);
	or_result = printf("min d: %d	min i: %i\n", min, min);
	printf("\nresult: %d - %d\n", my_result, or_result);
	printf("---------------------------------------------------------------\n");
	my_result = ft_printf("max d: %d	max i: %i\n", max, max);
	or_result = printf("max d: %d	max i: %i\n", max, max);
	printf("\nresult: %d - %d\n", my_result, or_result);
	printf("###############################################################\n");

	// Unsigned decimal
	printf("########################## UNSIGNED ###########################\n");
	printf("###############################################################\n");
	my_result = ft_printf("%u\n", max);
	or_result = printf("%u\n", max);
	printf("\nresult: %d - %d\n", my_result, or_result);
	printf("---------------------------------------------------------------\n");
	my_result = ft_printf("%u\n", 0);
	or_result = printf("%u\n", 0);
	printf("\nresult: %d - %d\n", my_result, or_result);
	printf("---------------------------------------------------------------\n");
	my_result = ft_printf("%u\n", -1);
	or_result = printf("%u\n", -1);
	printf("\nresult: %d - %d\n", my_result, or_result);
	printf("###############################################################\n");

	// Weird combinations
	printf("##################### WEIRD COMBINATIONS ######################\n");
	printf("###############################################################\n");
	/*
	my_result = ft_printf("this is a number %d and also %i and %u\n", "hello", "hello", "hello");
	or_result = printf("this is a number %d and also %i and %u\n", "hello", "hello", "hello");
	printf("\nresult: %d - %d\n", my_result, or_result);
	printf("---------------------------------------------------------------\n");
	*/
	my_result = ft_printf("this is a number %d and also %i and %u\n", c1, c1, c1);
	or_result = printf("this is a number %d and also %i and %u\n", c1, c1, c1);
	printf("\nresult: %d - %d\n", my_result, or_result);
	printf("---------------------------------------------------------------\n");
	my_result = ft_printf("\001\002\007\v\010\f\r\n");
	or_result = printf("\001\002\007\v\010\f\r\n");
	printf("\nresult: %d - %d\n", my_result, or_result);
	printf("###############################################################\n");

	
	// BONUS
	printf("\n");
	printf("###############################################################\n");
	printf("############################ BONUS ############################\n");
	printf("###############################################################\n");
	printf("\n");
	printf("####################### FLAGS WITH CHAR #######################\n");
	printf("###############################################################\n");
	my_result = ft_printf("'%-c'\n", 'b');
	or_result = printf("'%-c'\n", 'b');
	printf("\nresult: %d - %d\n", my_result, or_result);
	printf("---------------------------------------------------------------\n");
	my_result = ft_printf("character with width 4: '%4c'\n", 'b');
	or_result = printf("character with width 4: '%4c'\n", 'b');
	printf("\nresult: %d - %d\n", my_result, or_result);
	printf("---------------------------------------------------------------\n");
	my_result = ft_printf("character with width 18 and -: '%-18c'\n", 'b');
	or_result = printf("character with width 18 and -: '%-18c'\n", 'b');
	printf("\nresult: %d - %d\n", my_result, or_result);
	printf("###############################################################\n");


	printf("######################## FLAGS WITH STR #######################\n");
	printf("###############################################################\n");
	my_result = ft_printf("str with width lower than length: '%4s'\n", "hello");
	or_result = printf("str with width lower than length: '%4s'\n", "hello");
	printf("\nresult: %d - %d\n", my_result, or_result);
	printf("---------------------------------------------------------------\n");
	my_result = ft_printf("str with width bigger than length: '%18s'\n", "hello");
	or_result = printf("str with width bigger than length: '%18s'\n", "hello");
	printf("\nresult: %d - %d\n", my_result, or_result);
	printf("---------------------------------------------------------------\n");
	my_result = ft_printf("str with width bigger than length and -: '%-18s'\n", "hello");
	or_result = printf("str with width bigger than length and -: '%-18s'\n", "hello");
	printf("\nresult: %d - %d\n", my_result, or_result);
	printf("###############################################################\n");

	printf("######################## FLAGS WITH # #########################\n");
	printf("###############################################################\n");
	my_result = ft_printf("%#x	%#X	'%-#12x'\n", 0, 24561, 0xffffffff);
	or_result = printf("%#x	%#X	'%-#12x'\n", 0, 24561, 0xffffffff);
	printf("\nresult: %d - %d\n", my_result, or_result);
	printf("---------------------------------------------------------------\n");

	printf("################### FLAGS WITH ' ' and '+' ####################\n");
	printf("###############################################################\n");
	my_result = ft_printf("space: '% i'	'% d'	'% i'	'% d'\n", 0, 7, 234, -123);
	or_result = printf("space: '% i'	'% d'	'% i'	'% d'\n", 0, 7, 234, -123);
	printf("\nresult: %d - %d\n", my_result, or_result);
	printf("---------------------------------------------------------------\n");
	my_result = ft_printf("plus: '%+i'	'%+d'	'%+10i'	'%+d'\n", 0, 7, 234, -123);
	or_result = printf("plus: '%+i'	'%+d'	'%+10i'	'%+d'\n", 0, 7, 234, -123);
	printf("\nresult: %d - %d\n", my_result, or_result);
	printf("---------------------------------------------------------------\n");
	my_result = ft_printf("random: '% 10i'	'%010i'\n", -130, 0xffffffff);
	or_result = printf("random: '% 10i'	'%010i'\n", -130, 0xffffffff);
	printf("\nresult: %d - %d\n", my_result, or_result);
	printf("---------------------------------------------------------------\n");
	my_result = ft_printf("'%0d'	'%0d'	'%02d'	'%04d'\n", 1, 30, 30, 30);
	or_result = printf("'%0d'	'%0d'	'%02d'	'%04d'\n", 1, 30, 30, 30);
	printf("\nresult: %d - %d\n", my_result, or_result);
	printf("---------------------------------------------------------------\n");
	my_result = ft_printf("'%010u'	'%#010x'\n", 301, 0x4f);
	or_result = printf("'%010u'	'%#010x'\n", 301, 0x4f);
	printf("\nresult: %d - %d\n", my_result, or_result);
	printf("---------------------------------------------------------------\n");
	my_result = ft_printf("'%p'	'%#010x'\n", str1, 0x4f);
	or_result = printf("'%p'	'%#010x'\n", str1, 0x4f);
	printf("\nresult: %d - %d\n", my_result, or_result);
	printf("---------------------------------------------------------------\n");



	// Testing zone printf
	printf("###############################################################\n");
	printf("################### COMBINATIONS IN PRINTF ####################\n");
	printf("###############################################################\n");
	ft_isalpha('c'); //TODO BREAKPOINT
	ft_printf("'%#012.4x'\n", 0x4f);
	my_result = ft_printf("zero works with d,i,u,x,%%:	'%04d' '%04i' '%04u' '%#012.4x' '%04%'\n", 42, 0, -42, 0x4f);
	or_result = printf("zero works with d,i,u,x,%%:	'%04d' '%04i' '%04u' '%#012.4x' '%04%'\n", 42, 0, -42, 0x4f);
	printf("\nresult: %d - %d\n", my_result, or_result);
	printf("---------------------------------------------------------------\n");
	my_result = ft_printf("- works with all:	'%-3c' '%-10s' '%-14p' '%-4d' '%-4i' '%-4u' '%-4x' '%-4%'\n", 'c', str1, str1, 42, 0, -42, 0x4f);
	or_result = printf("- works with all:	'%-3c' '%-10s' '%-14p' '%-4d' '%-4i' '%-4u' '%-4x' '%-4%'\n", 'c', str1, str1, 42, 0, -42, 0x4f);
	printf("\nresult: %d - %d\n", my_result, or_result);
	printf("---------------------------------------------------------------\n");
	my_result = ft_printf("precision works with:	'%.13s' '%+.3d' '%.3i' '%.4u' '%#.4x' '%.4%'\n", str1, 42, -42, -42, 0x4f);
	or_result = printf("precision works with:	'%.13s' '%+.3d' '%.3i' '%.4u' '%#.4x' '%.4%'\n", str1, 42, -42, -42, 0x4f);
	printf("\nresult: %d - %d\n", my_result, or_result);
	printf("---------------------------------------------------------------\n");
	my_result = ft_printf("# works with all:	'%#4x' '%#4%'\n", 0x4f);
	or_result = printf("# works with all:	'%#4x' '%#4%'\n", 0x4f);
	printf("\nresult: %d - %d\n", my_result, or_result);
	printf("---------------------------------------------------------------\n");
	my_result = ft_printf("' ' works with all:	'% 1d' '% 4i' '% 4%'\n", 42, 0);
	or_result = printf("' ' works with all:	'% 1d' '% 4i' '% 4%'\n", 42, 0);
	printf("\nresult: %d - %d\n", my_result, or_result);
	printf("---------------------------------------------------------------\n");
	my_result = ft_printf("+ works with all:	'%+3d' '%+3i' '%+4%'\n", 42, -42);
	or_result = printf("+ works with all:	'%+3d' '%+3i' '%+4%'\n", 42, -42);
	printf("\nresult: %d - %d\n", my_result, or_result);
	printf("---------------------------------------------------------------\n");
	printf("'%-8.s'\n", "hello");
	char	*str_null = NULL;
	printf("'%8s'\n", str_null);
	printf("%0+8.4d\n", 23);

	ft_printf("%#x\n%#X\n", -1, -1);
	
	return (0);
}
