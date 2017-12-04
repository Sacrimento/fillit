/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_grid.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouvero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 11:24:28 by abouvero          #+#    #+#             */
/*   Updated: 2017/12/04 13:40:21 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	print_grid(char **grid)
{
	int line;
	int row;

	line = -1;
	while (grid[++line] != 0)
	{
		row = -1;
		while (grid[line][++row])
			ft_putchar(grid[line][row]);
		ft_putchar('\n');
	}
}
