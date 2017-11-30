/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_placenext.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <mfonteni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 11:41:24 by mfonteni          #+#    #+#             */
/*   Updated: 2017/11/30 17:50:25 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	test_limit(char **grid, int limit)
{
	int line;
	int row;

	line = limit;
	row = 0;
	while (grid[line][row] && row < limit)
	{
		if (grid[line][row] && ft_isalpha(grid[line][row]))
			return (0);
		row++;
	}
	while (line >= 0 && grid[line][row])
	{
		if (grid[line][row] && ft_isalpha(grid[line][row]))
			return (0);
		line--;
	}
	return (1);
}

static int	chk_place(char *block, char **grid, int line, int row)
{
	if (grid[line][row] && !ft_isalpha(grid[line][row])
			&& ft_placeblock(block, grid, line, row))
		return (1);
	return (0);
}

static int	chk_lim(char **grid, char letter, int limit)
{
	ft_alphablock(grid, letter);
	if (test_limit(grid, limit + 1))
		return (1);
	ft_eraseblock(grid, letter);
	return (0);
}

int			ft_placenext(char *blk, char **grid, int lim, char l)
{
	int line;
	int row;
	int tmp_lim;

	tmp_lim = -1;
	while (++tmp_lim <= lim)
	{
		row = tmp_lim;
		line = -1;
		while (++line < row)
		{
			if (chk_place(blk, grid, line, row) && chk_lim(grid, l, lim))
				return (1);
		}
		row = -1;
		while (++row <= line)
		{
			if (chk_place(blk, grid, line, row) && chk_lim(grid, l, lim))
				return (1);
		}
	}
	return (0);
}
