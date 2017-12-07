/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placenext.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 14:46:08 by mfonteni          #+#    #+#             */
/*   Updated: 2017/12/07 15:02:06 by mfonteni         ###   ########.fr       */
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

static int	chk_alph(char **grid, char letter)
{
	if (alphablock(grid, letter))
	{
		print_grid(grid);
		printf("\n");
		return (1);
	}
	else
	{
		eraseblock(grid, letter);
		return (0);
	}
}

int			placenext(char *block, char **grid, char letter)
{
	int line;
	int row;
	int limit;
	int temp_limit;

	temp_limit = -1;
	limit = chk_limit(grid);
	while (++temp_limit <= limit)
	{
		row = temp_limit;
		line = -1;
		while (++line < row)
		{
			if (chk_place(block, grid, line, row) && chk_alph(grid, letter))
				return (1);
		}
		row = -1;
		while (++row <= line)
		{
			if (chk_place(block, grid, line, row) && chk_alph(grid, letter))
				return (1);
		}
	}
	return (0);
}
