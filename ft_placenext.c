/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_placenext.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <mfonteni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 11:41:24 by mfonteni          #+#    #+#             */
/*   Updated: 2017/11/29 13:43:44 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	*fill_posarray(int line, int row)
{
	int *array;

	array = ft_memalloc(2);
	array[0] = line;
	array[1] = row;
	return (array);
}

static int	*nextpos(char **grid, int limit)
{
	int line;
	int row;
	int *res;

	line = limit;
	row = 0;
	if (limit == 0)
		return (!ft_isalpha(grid[0][0]) ? fill_posarray(0, 0) : NULL);
	if ((res = (nextpos(grid, limit - 1))))
		return (res);
	while (row < limit)
	{
		if (grid[line][row] && !ft_isalpha(grid[line][row]))
			return (fill_posarray(line, row));
		row++;
	}
	row = limit;
	line = 0;
	while (line <= limit)
	{
		if (grid[line][row] && !ft_isalpha(grid[line][row]))
			return (fill_posarray(line, row));
		line++;
	}
	return (NULL);
}

static int	test_limit(char **grid, int limit)
{
	int line;
	int row;

	line = limit;
	row = 0;
	while (row < limit)
	{
		if (grid[line][row] && ft_isalpha(grid[line][row]))
			return (0);
		row++;
	}
	while (line >= 0)
	{
		if (grid[line][row] && ft_isalpha(grid[line][row]))
			return (0);
		line--;
	}
	return (1);
}

int			ft_placenext(char *block, char **grid, int limit, char letter)
{
	int *coord;

	if ((coord = nextpos(grid, limit))
			&& ft_placeblock(block, grid, coord[0], coord[1])
			&& ft_alphablock(grid, letter) && test_limit(grid, limit))
				return (1);
	else
		ft_eraseblock(grid, letter);
	return (0);
}
