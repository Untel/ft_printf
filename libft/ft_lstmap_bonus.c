/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adda-sil <adda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 17:02:01 by adda-sil          #+#    #+#             */
/*   Updated: 2019/10/20 20:17:57 by adda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *first;
	t_list *node;

	if (!(first = ft_lstnew(f ? f(lst->content) : lst->content)))
		return (NULL);
	ft_lstdelone(lst, del);
	node = first;
	while ((lst = lst->next))
	{
		if (!(node->next = ft_lstnew(f ? f(lst->content) : lst->content)))
			return (NULL);
		ft_lstdelone(lst, del);
		node = node->next;
	}
	node->next = NULL;
	return (first);
}
