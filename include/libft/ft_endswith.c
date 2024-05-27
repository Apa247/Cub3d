/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_endswith.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 17:51:04 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/11/18 18:10:07 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_endswith(const char *string, const char *suffix)
{
	size_t	suffixlen;
	char	*pointer;

	if (string == NULL || suffix == NULL)
		return (0);
	pointer = (char *)string;
	suffixlen = ft_strlen(suffix);
	while (*pointer != '\0')
	{
		if (ft_strlen(pointer) == suffixlen)
		{
			if (ft_strncmp(pointer, suffix, suffixlen) == 0)
				return (1);
		}
		pointer++;
	}
	return (0);
}
