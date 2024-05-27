/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstrip.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 20:41:21 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/11/18 17:19:28 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstrip(const char *string)
{
	int		i;
	char	*cleanedstring;
	int		alphacount;

	i = 0;
	cleanedstring = NULL;
	if (string == NULL)
		return (NULL);
	alphacount = ft_countalpha(string);
	cleanedstring = malloc(sizeof(char) * (alphacount + 1));
	if (!cleanedstring)
		return (NULL);
	alphacount = 0;
	while (string[i] != '\0')
	{
		if (ft_isalpha(string[i]) != 0)
		{
			cleanedstring[alphacount] = string[i];
			++alphacount;
		}
		++i;
	}
	cleanedstring[alphacount] = '\0';
	return (cleanedstring);
}
