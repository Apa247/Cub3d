/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countalpha.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 17:19:41 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/11/18 17:19:53 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_countalpha(const char *string)
{
	int		alphacount;
	int		count;

	alphacount = 0;
	count = 0;
	if (string == NULL)
		return (0);
	while (string[count] != '\0')
	{
		if (ft_isalpha(string[count]) != 0)
			alphacount++;
		count++;
	}
	return (alphacount);
}
