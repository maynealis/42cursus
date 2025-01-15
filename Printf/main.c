/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmayne-p <cmayne-p@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 19:53:59 by cmayne-p          #+#    #+#             */
/*   Updated: 2025/01/13 18:42:23 by cmayne-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int main(void) 
{
    printf("TESTING MANDATORY PRINTF\n");
    // Testing decimal
    printf("Decimal with d: %d\n", -2147483647);
    printf("Decimal with i: %i\n", -2147483647);

    // Testing u
    printf("Decimal withou sign: %u\n", 2147483647);
    printf("Decimal withou sign: %u\n", -1);

    printf("----------------------------\n");

    // Testing the '-' flag (left-justify)
    printf("Left--justified: '%-10d'\n", 42);
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
    printf("Alternate form for dec: '%#f'\n", 42.5);
    printf("Alternate form for hex: '%#x'\n", 42);
    printf("Alternate form for HEX: '%#X'\n", 42);

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

