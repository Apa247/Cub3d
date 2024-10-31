/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolopez- <jolopez-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 11:03:11 by jolopez-          #+#    #+#             */
/*   Updated: 2024/06/27 19:43:45 by jolopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

/*	ft_print_menu() prints the menu. */

void	ft_print_menu(void)
{
	printf(CYAN "\n");
	printf(" .d8888b.           888                .d8888b.  8888888b. \n");
	printf("d88P  Y88b          888               d88P  Y88b 888  'Y88b\n");
	printf("888    888          888                    .d88P 888    888\n");
	printf("888        888  888 88888b.   .d88b.      8888:  888    888\n");
	printf("888        888  888 888  88b d8P  Y8b      'Y88b 888    888\n");
	printf("888    888 888  888 888  888 88888888 888    888 888    888\n");
	printf("Y88b  d88P Y88b 888 888 d88P Y8b.     Y88b  d88P 888  .d88P\n");
	printf(" 'Y8888P'   'Y88888 88888P'   'Y8888   'Y8888P'  8888888P' \n");
	printf("\n\n");
	printf(GREEN "\tW" WHITE ": move forward\t");
	printf(GREEN "\tS" WHITE ": move backward\n");
	printf(GREEN "\tA" WHITE ": strafe left\t");
	printf(GREEN "\tD" WHITE ": strafe right\n");
	printf(BLUE "\t<" WHITE ": rotate left\t");
	printf(BLUE "\t>" WHITE ": rotate right\n");
	printf("\n");
}
