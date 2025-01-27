/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmayne-p <cmayne-p@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 21:00:08 by cmayne-p          #+#    #+#             */
/*   Updated: 2025/01/27 22:10:21 by cmayne-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

#include "includes/ft_printf.h"

void	swap(t_list *a)
{
	void	*temp;

	if (a->next == NULL)
		return ;
	temp = a->content;
	a->content = a->next->content;
	a->next->content = temp;
}


int	main(void)
{
	t_list a1;
	t_list a2;
	t_list a3;
	int	n1 = 2;
	int	n2 = 1;
	int	n3 = 9;

	a1.content = &n1;
	a1.next = &a2;
	a2.content = &n2;
	a2.next = &a3;
	a3.content = &n3;
	a3.next = NULL;

	ft_printf("%i %i %i\n", *(int *)a1.content, *(int *)a2.content, *(int *)a3.content);
	swap(&a1);
	ft_printf("%i %i %i\n", *(int *)a1.content, *(int *)a2.content, *(int *)a3.content);
	return (0);
}
