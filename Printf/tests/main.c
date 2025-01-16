/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmayne-p <cmayne-p@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 14:26:17 by cmayne-p          #+#    #+#             */
/*   Updated: 2025/01/16 14:33:53 by cmayne-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{	
	int	my_result;
	int	or_result;

	// Without arguments
	ft_printf("################### `TAB Simple print` ###################\n");
	my_result = ft_printf("	Simple print\n");
	or_result = printf("	Simple print\n");
	ft_printf("\nresult: %d - %d\n", my_result, or_result);
	ft_printf("##########################################################\n");

	// With single character substitution
	ft_printf("######################## char: `c` ########################\n");
	my_result = ft_printf("char: %c", 'c');
	or_result = printf("char: %c", 'c');
	ft_printf("\nresult: %d - %d\n", my_result, or_result);
	ft_printf("-----------------------------------------------------------\n");
	ft_printf("###################### char: `\\n` ########################\n");
	my_result = ft_printf("%c", '\n');
	or_result = printf("%c", '\n');
	ft_printf("\nresult: %d - %d\n", my_result, or_result);
	ft_printf("##########################################################\n");

	// With multiple character substitution

	// With single string substitution

	// With multiple string substitution
	ft_printf("Print with substitution at the end %s", "---this is the substitution\n");
	ft_printf("Print with %s at the middle %s\n", "---this is the substitution---");
	ft_printf("Multiple subs: %s, and here goes: %c", "---first---", 'c');
	ft_printf("A integer: %d\n another one: %i\n", 42, 90765);
	ft_printf("hexa: %x\n", 32);
	return (0);
}
