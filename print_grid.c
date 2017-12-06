/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_grid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 14:46:33 by mfonteni          #+#    #+#             */
/*   Updated: 2017/12/06 14:46:34 by mfonteni         ###   ########.fr       */
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
