/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_placeblock.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 13:53:57 by mfonteni          #+#    #+#             */
/*   Updated: 2017/11/24 19:00:23 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fillit.h"

static int	ft_revlast(char *block, char **grid, int cline, int crow)
{
	if (block[-1] == 'l')
		cline++;
	if (block[-1] == 'r')
		cline--;
	if (block[-1] == 'u')
		grid++;
	if (block[-1] == 'd')
		grid--;
	if (ft_placeblock(&block[1], grid, cline, crow))
		return (1);
	return (0);
}

int			ft_placeblock(char *block, char **grid, int cline, int crow)
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
			placeres = ft_placeblock(&block[1], grid, cline - 1, crow);
		if (block[0] == 'r')
			placeres = ft_placeblock(&block[1], grid, cline + 1, crow);
		if (block[0] == 'u')
			placeres = ft_placeblock(&block[1], grid - 1, cline, crow);
		if (block[0] == 'd')
			placeres = ft_placeblock(&block[1], grid + 1, cline, crow);
		if (block[0] == 'b')
			placeres = ft_revlast(&block[0], grid, cline, crow);
	}
	if (placeres)
		grid[crow][cline] = '#';
	return (placeres);
}
