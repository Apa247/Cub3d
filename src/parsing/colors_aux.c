/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_aux.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 17:53:13 by jolopez-          #+#    #+#             */
/*   Updated: 2024/07/02 01:53:39 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

/*	Reads the 3 numbers of a RGB color.	*/
char	*ft_read_number(const char *str, int *i)
{
	int		j;
	char	*number;

	j = 0;
	number = "";
	number = malloc(sizeof(char) * (3 + 1));
	while (ft_is_space(str[*i]))
		(*i)++;
	while (str[*i] != ',' && !ft_is_space(str[*i]) && j < 3)
	{
		number[j] = str[*i];
		j++;
		(*i)++;
	}
	number[j] = '\0';
	return (number);
}

/*	Checks if next character (no spaces) is a comma.	*/
void	ft_check_comma(t_data *data, const char *str, int *i)
{
	while (ft_is_space(str[*i]))
		(*i)++;
	if (str[*i] != ',')
		ft_exit(data, "Error: RGB format not valid!!\n");
	(*i)++;
	return ;
}

/*	Checks the end of a string checking if there are something but spaces
	before the string finishs.	*/
void	ft_check_end(t_data *data, const char *str, int *i)
{
	while (ft_is_space(str[*i]))
		(*i)++;
	if (str[*i] != '\0')
		ft_exit(data, "Error: RGB format not valid!!\n");
	return ;
}
