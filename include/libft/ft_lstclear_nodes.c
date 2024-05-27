/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_nodes.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 20:09:21 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/09/23 20:21:12 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear_nodes(t_list **lst)
{
	t_list	*node;

	if (*lst)
	{
		while (*lst != NULL)
		{
			node = (*lst)->next;
			free(*lst);
			*lst = node;
		}
		(*lst) = NULL;
	}
}
