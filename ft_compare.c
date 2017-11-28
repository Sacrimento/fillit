/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_compare.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 15:35:39 by mfonteni          #+#    #+#             */
/*   Updated: 2017/11/28 18:20:13 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int getsize(char **grid)
{
	int line;
	int row;
	int check;
	int size;

	size = 0;
	while (grid[line] != 0 && check < 2)
	{
		check = 0;
		row = 0;
		line = size;
		while (row <= line)
			check = (ft_isalpha(grid[line][row++]) ? 1 : check);
		row = line;
		while (line >= 0)
			check = (ft_isalpha(grid[line--][row]) ? 1 : check);
		if (check == 1)
			size++;
		check = (check == 0 ? 2 : 1);
	}
	return (size);
}

int	ft_compare(char **grid, char **newgrid)
{
	return (getsize(grid));
}
