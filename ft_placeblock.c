/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_placeblock.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 13:53:57 by mfonteni          #+#    #+#             */
/*   Updated: 2017/11/27 14:20:32 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fillit.h"

static int	ft_revlast(char *block, char **grid, int line, int row)
{
	if (block[-1] == 'l')
		row++;
	if (block[-1] == 'r')
		row--;
	if (block[-1] == 'u')
		line++;
	if (block[-1] == 'd')
		line--;
	if (ft_placeblock(&block[1], grid, line, row))
		return (1);
	return (0);
}

int			ft_placeblock(char *block, char **grid, int line, int row)
{
	int placeres;

	placeres = 0;
	if (!block[0])
		placeres = 1;
	if (grid[line][row] && ft_isalpha(grid[line][row]))
		return (0);
	if (grid[line][row])
	{
		if (block[0] == 'l')
			placeres = ft_placeblock(&block[1], grid, line, row - 1);
		if (block[0] == 'r')
			placeres = ft_placeblock(&block[1], grid, line, row + 1);
		if (block[0] == 'u')
			placeres = ft_placeblock(&block[1], grid, line - 1, row);
		if (block[0] == 'd')
			placeres = ft_placeblock(&block[1], grid, line + 1, row);
		if (block[0] == 'b')
			placeres = ft_revlast(&block[0], grid, line, row);
	}
	if (placeres && grid[line][row] && grid[line])
		grid[line][row] = '#';
	printf("placer: placeres:%d, line:%d, row:%d\n", placeres, line, row);
	return (placeres);
}
