/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_placenext.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 11:41:24 by mfonteni          #+#    #+#             */
/*   Updated: 2017/11/24 19:00:18 by mfonteni         ###   ########.fr       */
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

int	*nextpos(char **grid, int max)
{
	int line;
	int row;
	int phase2;

	line = 0;
	row = 0;
	phase2 = 0;
	while (grid[line] && line <= max)
	{
		while ((line <= max || row <= max) && line >= 0)
		{
			while (ft_isalpha(grid[line][row]) && row <= (max - line))
				++row;
			if (grid[line][row] && !ft_isalpha(grid[line][row]))
				return (fill_posarray(line, row));
			line--;
			if (line == max && row == max)
			row = (phase2 ? max - line + 1 : 0);
		}
		line = max;
	}
	return (NULL);
}

//int	ft_placenext(char **grid, char *block)
//{
	/*
	 * this function will genereate an array and swap the values and test all 
	 * combinations with the grid, if in a combination placing a specific block
	 * make the combination badder than the last saved combi it drops all
	 * the nexts possibilites whith this block in this order
	 */
	
//}

