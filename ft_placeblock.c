/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_placeblock.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <mfonteni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 13:53:57 by mfonteni          #+#    #+#             */
/*   Updated: 2017/12/01 15:02:38 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fillit.h"

static int	ft_revlast(char *block, char **grid, int line, int row)
{
	int placeres;
	
	placeres = 0;
	if (block[-1] == 'l')
		placeres = ft_placeblock(&block[1], grid, line, row + 1);
	if (block[-1] == 'r')
		placeres = ft_placeblock(&block[1], grid, line, row - 1);
	if (block[-1] == 'u')
		placeres = ft_placeblock(&block[1], grid, line + 1, row);
	if (block[-1] == 'd')
		placeres = ft_placeblock(&block[1], grid, line - 1, row);
	return (placeres);
}

int			ft_placeblock(char *block, char **grid, int line, int row)
{
	int placeres;

	placeres = 0;
	printf("line :%d row %d block: %s\n", line, row, block); 
	if (line < 0 || row < 0)
		return (0);
	if (block[0] == '\0')
		placeres = 1;
	if (grid[line][row] != '.')
		return (0);
	if (block[0] == 'l')
		placeres = ft_placeblock(&block[1], grid, line, row - 1);
	if (block[0] == 'r')
		placeres = ft_placeblock(&block[1], grid, line, row + 1);
	if (block[0] == 'u')
		placeres = ft_placeblock(&block[1], grid, line - 1, row);
	if (block[0] == 'd')
		placeres = ft_placeblock(&block[1], grid, line + 1, row);
	if (block[0] == 'b')
		placeres = ft_revlast(&block[0], grid, line, row);
	if (placeres)
	{
		printf("placing %d:%d\n", line, row);
		grid[line][row] = '#';
		ft_print_grid(grid, 20);
	}
	printf("return %d\n", placeres);
	return (placeres);
}
