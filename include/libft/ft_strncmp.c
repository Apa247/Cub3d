/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 19:32:52 by jolopez-          #+#    #+#             */
/*   Updated: 2023/12/11 20:46:20 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

int	cmp_char(char c1, char c2)
{
	if ((unsigned char)c1 != (unsigned char)c2)
		return ((unsigned char)c1 - (unsigned char)c2);
	return (0);
}

/*	Devuelve 0 si las cadenas son iguales hasta el caracter n, si no devuelve
	la diferencia o -1 si alguna de las cadenas está vacía.	*/

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;

	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (1);
	if (*s1 == '\0' || *s2 == '\0')
		return (-1);
	while (s1[i] && s2[i] && i < n)
	{
		if (cmp_char(s1[i], s2[i]))
			return (cmp_char(s1[i], s2[i]));
		i++;
	}
	if (i < n)
		return (cmp_char(s1[i], s2[i]));
	return (0);
}
