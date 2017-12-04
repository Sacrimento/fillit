/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gridsize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 15:23:25 by mfonteni          #+#    #+#             */
/*   Updated: 2017/12/04 14:49:10 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	ft_gridsize(char **grid)
{
	int line;
	int row;
	int limit;

	limit = ft_get_limit(grid);
	while (limit)
	{
		line = limit;
		row = 0;
		while (row <= limit)
		{
			if (grid[line][row] && ft_isalpha(grid[line][row]))
				return (limit);
			row++;
		}
		while (line >= 0)
		{
			if (grid[line][row] && ft_isalpha(grid[line][row]))
				return (limit);
			line--;
		}
		limit--;
	}
	return (0);
}
