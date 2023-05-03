/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <prodrigo@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 22:45:37 by prodrigo          #+#    #+#             */
/*   Updated: 2023/05/02 23:38:31 by prodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*list;
	t_list	*node;
	void	*content;

	list = NULL;
	if (lst && f && del)
	{
		while (lst)
		{
			content = f(lst->content);
			node = ft_lstnew(content);
			if (!node)
			{
				free(content);
				ft_lstclear(&list, del);
				return (NULL);
			}
			ft_lstadd_back(&list, node);
			lst = lst->next;
		}
	}
	return (list);
}
