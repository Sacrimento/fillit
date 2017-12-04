/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placenext.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <mfonteni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 11:41:24 by mfonteni          #+#    #+#             */
/*   Updated: 2017/12/04 14:46:06 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	chk_place(char *block, char **grid, int line, int row)
{
	if (grid[line][row] && !ft_isalpha(grid[line][row])
			&& placeblock(block, grid, line, row))
		return (1);
	return (0);
}

static int	chk_dec(int decal, char **grid, char letter)
{
	if (decal < 1)
	{
		alphablock(grid, letter);
		return (1);
	}
	else
	{
		alphablock(grid, letter);
		eraseblock(grid, letter);
		return (0);
	}
}

int			placenext(char *blk, char **grid, char let, int decal)
{
	int line;
	int row;
	int limit;
	int tmp_lim;

	tmp_lim = -1;
	limit = check_limit(grid);
	while (++tmp_lim <= limit)
	{
		row = tmp_lim;
		line = -1;
		while (++line < row)
		{
			if (chk_place(blk, grid, line, row) && chk_dec(decal--, grid, let))
				return (1);
		}
		row = -1;
		while (++row <= line)
		{
			if (chk_place(blk, grid, line, row) && chk_dec(decal--, grid, let))
				return (1);
		}
	}
	return (0);
}
