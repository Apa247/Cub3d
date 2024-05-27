/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strarr_add.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 14:33:21 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/12/07 19:47:20 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#ifndef FIRST
# define FIRST 1
#endif
#ifndef LAST
# define LAST 0
#endif

static void	ft_copy_stringarray(
		char ***destarray, char **srcarray, int start, int end)
{
	int	i;

	i = 0;
	if (start > end || start < 0 || end < 0)
		return ;
	while (start < end && srcarray[i] != NULL)
	{
		(*destarray)[start] = ft_strdup(srcarray[i]);
		start++;
		++i;
	}
}

void	ft_strarr_add(char ***strarray, const char *newstring, int pos)
{
	char	**new_strarray;
	int		strarray_size;

	new_strarray = NULL;
	if (strarray == NULL || *strarray == NULL || newstring == NULL
		|| (pos != FIRST && pos != LAST))
		return ;
	strarray_size = ft_strarraylen(*strarray);
	new_strarray = malloc(sizeof(char *) * (strarray_size + 2));
	if (new_strarray == NULL)
		return ;
	new_strarray[strarray_size + 1] = NULL;
	if (pos == FIRST)
	{
		new_strarray[0] = ft_strdup(newstring);
		ft_copy_stringarray(&new_strarray, *strarray, 1, strarray_size + 1);
	}
	else if (pos == LAST)
	{
		new_strarray[strarray_size] = ft_strdup(newstring);
		ft_copy_stringarray(&new_strarray, *strarray, 0, strarray_size);
	}
	ft_clear_strarray((*strarray));
	(*strarray) = new_strarray;
}
