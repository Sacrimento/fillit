/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_placeblock.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 13:53:57 by mfonteni          #+#    #+#             */
/*   Updated: 2017/11/22 11:54:32 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fillit.h"

static void ft_revlast(char *block, char **grid, int cline, int crow, char c)
{
	if (block[-2] == 'l')
		cline++;
	if (block[-2] == 'r')
		cline--;
	if (block[-2] == 'u')
		grid++;
	if (block[-2] == 'd')
		grid--;
	ft_placeblock(&block[0], grid, cline, crow, c);
}

/* Tests if the current placement is ok for this block */

int	ft_placeblock(char *block, char **grid, int cline, int crow, char c)
{
	int placeres;

	placeres = 0;
	if (!block[0])
		placeres = 1;
	if (ft_isalpha(grid[crow][cline]))
		return (0);
	if (grid[crow][cline])
	{
		if (block[0] == 'l')
			placeres =	ft_placeblock(&block[1], grid, cline - 1, crow, c);
		if (block[0] == 'r')
			placeres = ft_placeblock(&block[1], grid, cline + 1, crow, c);
		if (block[0] == 'u')
			placeres = ft_placeblock(&block[1], grid - 1, cline, crow, c);
		if (block[0] == 'd')
			placeres = ft_placeblock(&block[1], grid + 1, cline, crow, c);
		if (block[0] == 'b')
			ft_revlast(&block[1], grid, cline, crow, c);
	}
		if (placeres)
			grid[crow][cline] = c;
		printf("%d recursion: %c\n", placeres, block[0]);
		return (placeres);
}
