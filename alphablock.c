/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alphablock.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 14:42:23 by mfonteni          #+#    #+#             */
/*   Updated: 2017/12/06 14:42:26 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	alphablock(char **grid, char letter)
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
			if (grid[line][row] == '#')
			{
				grid[line][row] = letter;
				counthash++;
			}
			row++;
		}
		row = 0;
		line++;
	}
	return (1);
}
