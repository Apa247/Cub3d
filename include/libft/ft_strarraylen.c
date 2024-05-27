/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strarraylen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 19:16:05 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/09/15 19:18:21 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strarraylen(char **strarray)
{
	size_t	count;

	if (*strarray == NULL || !strarray)
		return (0);
	count = 0;
	while (strarray[count] != NULL)
		count++;
	return (count);
}
