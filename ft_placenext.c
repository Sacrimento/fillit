/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_placenext.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 11:41:24 by mfonteni          #+#    #+#             */
/*   Updated: 2017/11/27 13:02:26 by mfonteni         ###   ########.fr       */
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

int	*nextpos(char **grid, int limit)
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
	while (line >= 0)
	{
		if (grid[line][row] && !ft_isalpha(grid[line][row]))
			return (fill_posarray(line, row));
		line--;
	}
	return (NULL);
}
