/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 18:37:02 by mfonteni          #+#    #+#             */
/*   Updated: 2017/11/30 18:38:55 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
/* ============================================================================
 * This function moves the block to the next available place, he tries untill
 * he finds a place or untill he tried evereything possible
 * TODO: 
 * - create an alternate placenext who have to check the point where we 
 * placed the block the first time
 * - We need to convert the block we are searching in # because the function 
 * uses too many arguments
 * - Parser needs to parse trough the point the most close to the left
*/

static int ft_search_block(char *block, char **grid, int line, int row)
{
	int placeres;

	placeres = 0;
	if (line < 0 || row < 0)
		return (0);
	if (!block[0])
		placeres = 1;
	if (!grid[line][row] || ft_isalpha(grid[line][row]))
		return (0);
	if (grid[line][row])
	{
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
	}
	if (placeres && grid[line][row] && grid[line] && grid[line][row] == '#')
		placeres = 1;
	return (placeres);
}

int	ft_replace(list history, char *block, char **grid, char letter)
{
		
}
