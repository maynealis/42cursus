/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmayne-p <cmayne-p@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 14:26:17 by cmayne-p          #+#    #+#             */
/*   Updated: 2025/01/17 11:17:18 by cmayne-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

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
	printf("###############################################################\n");
	return (0);
}
