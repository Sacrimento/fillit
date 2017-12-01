/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_placenext.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <mfonteni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 11:41:24 by mfonteni          #+#    #+#             */
/*   Updated: 2017/12/01 15:13:07 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	chk_place(char *block, char **grid, int line, int row)
{
	if (grid[line][row] && !ft_isalpha(grid[line][row])
			&& ft_placeblock(block, grid, line, row))
		return (1);
	return (0);
}

int			ft_placenext(char *blk, char **grid, char l)
{
	int line;
	int row;
	int limit;
	int tmp_lim;

	tmp_lim = -1;
	limit = ft_get_limit(grid);
	while (++tmp_lim <= limit)
	{
		row = tmp_lim;
		line = -1;
		while (++line < row)
		{
			if (chk_place(blk, grid, line, row) && ft_alphablock(grid, l))
				return (1);
		}
		row = -1;
		while (++row <= line)
		{
			if (chk_place(blk, grid, line, row) && ft_alphablock(grid, l))
				return (1);
		}
	}
	return (0);
}
