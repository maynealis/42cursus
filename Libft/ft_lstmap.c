/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmayne-p <cmayne-p@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 16:59:51 by cmayne-p          #+#    #+#             */
/*   Updated: 2025/01/04 15:24:40 by cmayne-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_node;
	t_list	*new_list;
//	t_list	*new_list_last;
	void	*new_content;

	if (lst == NULL)
		return (NULL);
	new_list = NULL;
//	new_list_last = NULL;
	new_content = f(lst->content);
	if (new_content == NULL)
	{
		ft_lstclear(&new_list, del);
		return (NULL);
	}
	new_node = ft_lstnew(new_content);
	if (new_node == NULL)
	{
		del(new_content);
		ft_lstclear(&new_list, del);
		return (NULL);
	}
//	if (new_list == NULL)
//		new_list = new_node;
//	else
//		new_list_last->next = new_node;
//	new_list_last = new_node;
	ft_lstadd_back(&new_list, new_node);
	lst = lst->next;
	return (new_list);
}
/*
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_list_last;
	t_list	*new_node;
	void	*buf;

	new_list = NULL;
	while (lst)
	{
		buf = f(lst->content);
		new_node = ft_lstnew(buf);
		if (new_node == NULL)
		{
			del(buf);
			ft_lstclear(&new_list, del);
			return (new_list);
		}
		if (new_list == NULL)
			new_list = new_node;
		else
			new_list_last->next = new_node;
		new_list_last = new_node;
		lst = lst->next;
	}
	return (new_list);
}
*/
