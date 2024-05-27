/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cutstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 20:07:26 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/11/03 20:36:03 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_get_limitpos(const char *str, const char *strlimit)
{
	char	*ptr;
	int		ptrpos;

	ptrpos = 0;
	ptr = (char *)str;
	while (*ptr != '\0')
	{
		if (ft_strncmp(ptr, strlimit, ft_strlen(ptr)) == 0)
			break ;
		ptrpos++;
		ptr++;
	}
	return (ptrpos);
}

char	*ft_cutstr(const char *str, const char *strlimit)
{
	char	*finalstr;
	int		len;
	int		i;

	finalstr = NULL;
	if (str == NULL || strlimit == NULL)
		return (NULL);
	i = 0;
	len = ft_get_limitpos(str, strlimit);
	finalstr = malloc(sizeof(char) *(len + 1));
	while (i < len && str[i] != '\0')
	{
		finalstr[i] = str[i];
		i++;
	}
	finalstr[i] = 0;
	return (finalstr);
}
