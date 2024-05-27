/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcontains.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 20:23:41 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/12/14 20:37:05 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcontains(const char *fullstring, const char *string_tofind)
{
	int	i;
	int	result;

	i = 0;
	result = -1;
	if (fullstring == NULL || string_tofind == NULL)
		return (0);
	while (fullstring[i] != '\0')
	{
		if (fullstring[i] == string_tofind[0])
		{
			result
				= ft_strncmp(
					fullstring + i,
					string_tofind,
					ft_strlen(string_tofind));
			if (result == 0)
				return (1);
		}
		++i;
	}
	return (0);
}
