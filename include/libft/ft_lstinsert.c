/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstinsert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 19:40:10 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/10/14 20:51:05 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstinsert(t_list **list, void *content, t_location location)
{
	t_list	*newnode;

	newnode = NULL;
	if (content)
	{
		newnode = ft_lstnew(content);
		if (location == FRONT)
			ft_lstadd_front(list, newnode);
		else if (location == BACK)
			ft_lstadd_back(list, newnode);
	}
}