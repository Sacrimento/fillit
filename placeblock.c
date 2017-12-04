/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placeblock.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <mfonteni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 13:53:57 by mfonteni          #+#    #+#             */
/*   Updated: 2017/11/28 12:14:13 by abouvero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fillit.h"

static int	revlast(char *block, char **grid, int line, int row)
{
	if (block[-1] == 'l')
		row++;
	if (block[-1] == 'r')
		row--;
	if (block[-1] == 'u')
		line++;
	if (block[-1] == 'd')
		line--;
	if (placeblock(&block[1], grid, line, row))
		return (1);
	return (0);
}

int			placeblock(char *block, char **grid, int line, int row)
{
	int placeres;

	placeres = 0;
	if (line < 0 || row < 0)
		return (0);
	if (!block[0])
		placeres = 1;
	if (!grid[line][row] || ft_isalpha(grid[line][row]))
		return (0);
	if (grid[line][row])
	{
		if (block[0] == 'l')
			placeres = placeblock(&block[1], grid, line, row - 1);
		if (block[0] == 'r')
			placeres = placeblock(&block[1], grid, line, row + 1);
		if (block[0] == 'u')
			placeres = placeblock(&block[1], grid, line - 1, row);
		if (block[0] == 'd')
			placeres = placeblock(&block[1], grid, line + 1, row);
		if (block[0] == 'b')
			placeres = revlast(&block[0], grid, line, row);
	}
	if (placeres && grid[line][row] && grid[line])
		grid[line][row] = '#';
	return (placeres);
}
