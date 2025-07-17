/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nraatika <nraatika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 15:51:57 by nraatika          #+#    #+#             */
/*   Updated: 2025/04/21 13:14:29 by nraatika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;
	t_list	*nxt;

	tmp = *lst;
	while (tmp->next != NULL)
	{
		nxt = tmp->next;
		ft_lstdelone(tmp, del);
		tmp = nxt;
	}
	ft_lstdelone(tmp, del);
	*lst = NULL;
	return ;
}
