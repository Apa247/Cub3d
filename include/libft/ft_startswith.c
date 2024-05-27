/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_startswith.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 13:47:45 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/12/15 18:43:00 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_startswith(const char *string, const char *prefix)
{
	int	prefixlen;
	int	result;

	result = -1;
	if (string == NULL || prefix == NULL)
		return (0);
	prefixlen = ft_strlen(prefix);
	result = ft_strncmp(prefix, string, prefixlen);
	if (result == 0)
		return (1);
	return (0);
}
