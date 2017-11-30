/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_tabsize.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 19:53:17 by mfonteni          #+#    #+#             */
/*   Updated: 2017/11/30 12:38:27 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	ft_gridsize(char **grid, int limit)
{
	int line;
	int row;

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
