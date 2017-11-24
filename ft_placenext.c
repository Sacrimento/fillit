/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_placenext.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 11:41:24 by mfonteni          #+#    #+#             */
/*   Updated: 2017/11/24 16:17:36 by mfonteni         ###   ########.fr       */
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

static int	*nextpos(char **grid)
{
	int line;
	int row;
	int max;
	int rowmax;

	line = 0;
	row = 0;
	max = 0;
	rowmax = 0;
	while (grid[line])
	{
		while (grid[line][row] && line)
		{
			while (ft_isalpha(grid[line][row]) && row <= rowmax)
				row++;
			if (!ft_isalpha(grid[line][row]))
				return (fill_posarray(line, row));
			line--;
			rowmax++;
			row = 0;
		}
		max++;
		line = count;
	}
	return (NULL);
}

int	ft_placenext(char **grid, char *block)
{
	/*
	 * this function will genereate an array and swap the values and test all 
	 * combinations with the grid, if in a combination placing a specific block
	 * make the combination badder than the last saved combi it drops all
	 * the nexts possibilites whith this block in this order
	 */
	
}
