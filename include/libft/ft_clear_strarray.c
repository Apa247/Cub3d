/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear_strarray.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 19:19:59 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/11/09 16:08:40 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_clear_strarray(char **strarray)
{
	int	count;

	count = 0;
	if (*strarray == NULL || !strarray)
		return ;
	while (strarray[count])
	{
		if (strarray[count])
			free(strarray[count]);
		++count;
	}
	free(strarray);
}
