/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_grid.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouvero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 11:24:28 by abouvero          #+#    #+#             */
/*   Updated: 2017/11/30 15:20:34 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_print_grid(char **tab, int limit)
{
	int line;
	int row;

	line = -1;
	row = 0;
	while (++line <= limit && line < TAB_MAX)
	{
		while (row <= limit && row < TAB_MAX)
			ft_putchar(tab[line][row++]);
		ft_putchar('\n');
		row = 0;
	}
}
