/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraatika <nraatika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 16:11:30 by nraatika          #+#    #+#             */
/*   Updated: 2025/04/24 12:37:11 by nraatika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*ret;
	t_list	*temp;

	if (lst == NULL || f == NULL || del == NULL)
		return (NULL);
	ret = ft_lstnew(f(lst->content));
	if (ret == NULL)
		return (NULL);
	if (lst->next == NULL)
		return (ret);
	while (lst->next != NULL)
	{
		lst = lst->next;
		temp = ft_lstnew(f(lst->content));
		if (temp == NULL)
		{
			ft_lstclear(&ret, del);
			return (NULL);
		}
		ft_lstadd_back(&ret, temp);
	}
	return (ret);
}
