/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_placeblock.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 13:53:57 by mfonteni          #+#    #+#             */
/*   Updated: 2017/11/19 16:38:29 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fillit.h"

static void ft_revlast(char *block, char **grid, int cline, int crow, char c)
{
	
}

/* Tests if the current placement is ok for this block */

int	ft_placeblock(char *block, char **grid, int cline, int crow, char c)
{
	int placeres;

	placeres = 0;
	if (block[0] == '\0')
		return (1);
	if (ft_isalpha(grid[crow][cline]))
		return (0);
	else if (grid[crow][cline])
	{
		if (block[0] == 'l')
			placeres =	ft_placeblock(block++, grid, cline - 1, crow, c);
		if (block[0] == 'r')
			placeres = ft_placeblock(block++, grid, cline + 1, crow, c);
		if (block[0] == 'u')
			placeres = ft_placeblock(block++, grid - 1, cline, crow, c);
		if (block[0] == 'd')
			placeres = ft_placeblock(block++, grid + 1, cline, crow, c);
		if (block[0] == 'b')
		{
			ft_revlast(block, grid, cline, crow, c);
		}
	}
		grid[crow][cline] = c;
		return (1);
}