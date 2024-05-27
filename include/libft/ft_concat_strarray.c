/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_concat_strarray.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 19:27:46 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/11/09 14:08:37 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_copy_and_join(
		char **fullstring, const char *stringtoadd, int joinchar)
{
	char	*buffer;
	int		stringlen;
	int		count;

	count = 0;
	buffer = NULL;
	if (stringtoadd == NULL)
		return ;
	stringlen = ft_strlen(stringtoadd);
	buffer = malloc(sizeof(char) * (stringlen + 2));
	while (count < stringlen)
	{
		buffer[count] = stringtoadd[count];
		count++;
	}
	buffer[count] = (unsigned char)joinchar;
	buffer[count + 1] = 0;
	(*fullstring) = ft_strjoin_get((*fullstring), buffer);
	free(buffer);
}

char	*ft_concat_strarray(char **strarray, int joinchar)
{
	char	*fullstring;
	int		strcount;
	int		count;
	char	*buffer;

	fullstring = NULL;
	count = 0;
	if (strarray == NULL || *strarray == NULL)
		return (NULL);
	strcount = ft_strarraylen(strarray);
	while (count < strcount)
	{
		if (count < strcount - 1 && joinchar != 0)
			ft_copy_and_join(&fullstring, strarray[count], joinchar);
		else
		{
			buffer = ft_strdup(strarray[count]);
			fullstring = ft_strjoin_get(fullstring, buffer);
			free(buffer);
		}
		count++;
	}
	return (fullstring);
}
