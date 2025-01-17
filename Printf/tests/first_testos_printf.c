/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_testos_printf.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmayne-p <cmayne-p@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 19:53:59 by cmayne-p          #+#    #+#             */
/*   Updated: 2025/01/17 15:51:34 by cmayne-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int main(void) 
{
	int	result;
	
	/*
    printf("TESTING MANDATORY PRINTF\n");
    // Testing decimal
    printf("Decimal with d: %d\n", -2.1);
    printf("Decimal with i: %i\n", 'c');
    printf("Decimal with i: %i\n", "hell");

    // Testing u
    printf("Decimal withou sign: %u\n", 2147483647);
    printf("Decimal withou sign: %u\n", -1);

	// Testing hexadecimal
	printf("Hexadecimal: %X\n", 123);
	printf("Hexadecimal: %X\n", 0b1111011);
	printf("Hexadecimal: %X\n", 0x7b);
	printf("Hexadecimal: %X\n", -1);

	// Testing no substitutio
	printf("Nothing to substitute\n", 42, "Hello");


	// Testing string NULL
	char	*null_str = NULL;
	printf("String NULL:\n");
	result = printf( "%s", null_str);
	printf("\n");
	printf("result: %i\n", result);

	// Testing pointer
	char	str_random[]="something";
	printf("pointer: %p\n", null_str);
    printf("pointer: %p\n", str_random);
	printf("\n----------------------------\n");
	*/

    // Testing the '-' flag (left-justify)
    printf("Left--justified(-0): '%-010d'\n", 42);
    printf("Left--justified(0-): '%0-10d'\n", 42);
    printf("Left--justified(0-): '%0-.10d'\n", 42);
	printf("Right-justified: '%10d'\n", 42);

    // Testing the '0' flag (zero-padding)
    printf("Zero-padded: '%03d'\n", 4321);

    // Testing the '.' flag (precision with integers and floats)
    printf("Precision with integer: '%.5d'\n", 42);
    printf("Precision with float: '%.2f'\n", 42.12345);

    // Testing field width
    printf("Field width 10: '%10d'\n", 42);
    printf("Field width and precision: '%10.5d'\n", 42);

    // Testing '#' flag (alternate form for octal, hex, etc.)
	int	*ptr;
    printf("# with c: '%#c'\n", 'c');
    printf("# with s: '%#s'\n", "c");
    printf("# with p: '%#p'\n", ptr);
    printf("not # with p: '%p'\n", ptr);
    printf("# with d: '%#d'\n", 42);
    printf("# with i: '%#i'\n", 42);
    printf("# with u: '%#u'\n", 42);
    printf("# with x: '%#010x'\n", 42);
    printf("# with X: '%#X'\n", 42);
    printf("# with %%: '%#%'\n");

    // Testing '+' flag (explicitly show sign)
    printf("Show positive sign: '%+d'\n", 42);
    printf("Show negative sign: '%+d'\n", -42);

    // Testing space flag (prepend a space for positive numbers)
    printf("Space flag: '% d'\n", 42);
    printf("Space flag with negative: '% d'\n", -42);

    // Combining flags
    printf("Combining flags (# and 0): '%#010x'\n", 42);
    printf("Combining flags (+ and 10): '%+10d'\n", 42);
    printf("Combining flags (space and 10): '% 10d'\n", 42);
    printf("Combining flags (- and 10): '%-10d'\n", 42);
    printf("Combining flags (- and precision): '%-.5d'\n", 42);

    return 0;
}

