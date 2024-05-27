/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 15:23:16 by jolopez-          #+#    #+#             */
/*   Updated: 2023/10/14 21:06:51 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*point;
	t_list	*next_p;

	if (!lst || !del || (*lst) == NULL)
		return ;
	point = (*lst);
	next_p = point->next;
	while (point != NULL)
	{
		next_p = point->next;
		(*del)(point->content);
		free(point);
		point = next_p;
	}
	(*lst) = NULL;
}
