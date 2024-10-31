/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcopy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 20:09:21 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/09/23 20:21:12 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstcopy(t_list *list, t_list *limit)
{
	t_list	*node;
	t_list	*newlist;

	if (list == NULL)
		return (NULL);
	node = list;
	newlist = NULL;
	while (node != limit)
	{
		ft_lstinsert(&newlist, node->content, BACK);
		node = node->next;
	}
	return (NULL);
}
