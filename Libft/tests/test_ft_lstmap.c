/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_lstmap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmayne-p <cmayne-p@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 14:41:24 by cmayne-p          #+#    #+#             */
/*   Updated: 2025/01/04 15:10:52 by cmayne-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Función de mapeo: duplica un string
void *duplicate_content(void *content)
{
    char *str = (char *)content;
    char *dup = strdup(str);
    if (!dup)
        return (NULL);
    return (dup);
}

// Función para liberar memoria
void delete_content(void *content)
{
    free(content);
}

// Imprimir contenido de una lista
void print_list(t_list *lst)
{
    while (lst)
    {
        printf("Content: %s\n", (char *)lst->content);
        lst = lst->next;
    }
}

void	do_test_ft_lstmap(void)
{
	t_list	*lst = NULL;
	t_list	*mapped_lst = NULL;

	ft_lstadd_back(&lst, ft_lstnew(strdup("First")));
	ft_lstadd_back(&lst, ft_lstnew(strdup("Second")));
	ft_lstadd_back(&lst, ft_lstnew(strdup("Third")));

	printf("Original list: \n");
	print_list(lst);

	mapped_lst = ft_lstmap(lst, duplicate_content, delete_content);

	printf("\nMapped list:\n");
	print_list(mapped_lst);

	ft_lstclear(&lst, delete_content);
	ft_lstclear(&mapped_lst, delete_content);
}
