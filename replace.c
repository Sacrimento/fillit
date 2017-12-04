/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 18:37:02 by mfonteni          #+#    #+#             */
/*   Updated: 2017/12/01 13:33:58 by mfonteni         ###   ########.fr       */
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

static int	revlast(char *block, char **grid, int line, int row)
{
	if (block[-1] == 'l')
		row++;
	if (block[-1] == 'r')
		row--;
	if (block[-1] == 'u')
		line++;
	if (block[-1] == 'd')
		line--;
	if (search_block(&block[1], grid, line, row))
		return (1);
	return (0);
}

int			search_block(char *block, char **grid, int line, int row)
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
			placeres = search_block(&block[1], grid, line, row - 1);
		if (block[0] == 'r')
			placeres = search_block(&block[1], grid, line, row + 1);
		if (block[0] == 'u')
			placeres = search_block(&block[1], grid, line - 1, row);
		if (block[0] == 'd')
			placeres = search_block(&block[1], grid, line + 1, row);
		if (block[0] == 'b')
			placeres = revlast(&block[0], grid, line, row);
	}
	if (placeres && grid[line][row] && grid[line] && grid[line][row] == '#')
		placeres = 1;
	return (placeres);
}

void		hash_block(char **grid, char letter)
{
	int line;
	int row;
	int counthash;

	line = 0;
	row = 0;
	counthash = 0;
	while (grid[line] && counthash < 4)
	{
		while (grid[line][row])
		{
			if (grid[line][row] == letter)
			{
				grid[line][row] = '#';
				counthash++;
			}
			row++;
		}
		row = 0;
		line++;
	}
}

static void	erase_and_mark(char **grid, int line, int row, char letter)
{
	eraseblock(grid, '#');
	grid[line][row] = ft_tolower(letter);
}

int			ft_replace(char *block, char **grid, char letter, int limit)
{
	int line;
	int row;

	line = -1;
	hash_block(grid, letter);
	while (++line <= limit)
	{
		row = -1;
		while (++row <= limit)
		{
			if (search_block(block, grid, line, row))
			{
				erase_and_mark(grid, line, row, letter);
				if (placenext(block, grid, limit, letter))
					{
						grid[line][row] = '.';
						return (1);
					}
				else
					{
						grid[line][row] = '.';
						placenext(block, grid, limit, letter);
						return (0);
					}
			}
		}
	}
}
